	/**	\file map16.c
		\brief Map scroller
		\author J Vijn
		\author Kawa
*/
#include "openpoke.h"

#define WEATHER_RUN 0
#define WEATHER_INIT 1
#define WEATHER_STOP 2
void (*NextWeatherEffect)(int) = 0;
void (*WeatherEffect)(int) = 0;
void * WeatherEffects[];

extern void LoadTimeAdjustedColors(u16 *dst, u16 *src, int nclrs);
extern void LoadLightmap(u16 *dst, u8 *src);

#if 0
#define DIR_CENTER	0
#define DIR_NORTH	1
#define DIR_SOUTH	2
#define DIR_EAST	4
#define DIR_WEST	8
#define DIR_BORDER	16
#endif

#define DIR_NORTH	0
#define DIR_EAST	1
#define DIR_SOUTH	2
#define DIR_WEST	3
#define DIR_CENTER	16
#define DIR_BORDER	17

#define CONN_MAX	16

extern const aMapHeader * const MapHeaderList[];

aMapHeader	*currentMapHeader;
aMap		*currentLevel;
aTileset	*currentTileset;
aEncounterSet *currentMonsters[4];

s32 gCameraX, gCameraY;
u8	gMapOfsX, gMapOfsY;

s32 BGScrollX, BGScrollY;

//Let's see now... 128x128=16384*2=32768 bytes. hex 16384 = 0x4000, that's just four kilobytes less than FR's buffer, and that one holds all connections too. Woah.
#define MAPBUFFERSIZE 0x4000
u16 MapBuffer[MAPBUFFERSIZE] INEWRAM;

// --- Connection additions ---

RECT gConnRects[CONN_MAX];

void mhInitConnRects(const aMapHeader *mh);

int mhGetConnDir(const aMapHeader *mh, int tx, int ty);
int mhGetConnId(const aMapHeader *mh, int tx, int ty, int dir);
MetaTile *mhGetMetaTile(const aMapHeader *mh, int tx, int ty);

void mhRedraw(const aMapHeader *mh, int tx, int ty);
void mapDrawMeta(int tx, int ty, const MetaTile *meta);

//! Initialize the connection rects for a map
/*!	\note	Although creating conn-rects isn't strictly necessary,
*	  it does make things easier (and faster).
*/
void mhInitConnRects(const aMapHeader *mh)
{
	int ii, nn;
	const aMap *map= mh->map, *cmap;
	int mapW= map->width, mapH=map->height;
	aConnection *conn;

	if(mh == 0)
	{
		AGBPrintf("mhInitConnRects: mh is null.\n");
		return;
	}
	if(mh->conns == 0)
	{
		AGBPrintf("mhInitConnRects: mh->conns is null.\n");
		return;
	}
	nn= mh->conns->numconns;

	AGB_ASSERT(nn<CONN_MAX);

	for(ii=0; ii<nn; ii++)
	{
		RECT *rc= &gConnRects[ii];
		conn= &mh->conns->conns[ii];
		cmap= (aMap*)MapHeaderList[conn->level]->map;

		switch(conn->direction)
		{
		case DIR_NORTH:
			rc->left= conn->shift;
			rc->top= -cmap->height;
			rc->right= rc->left + cmap->width;
			rc->bottom= 0;
			break;
		case DIR_WEST:
			rc->left= -cmap->width;
			rc->top= conn->shift;
			rc->right= 0;
			rc->bottom= rc->top + cmap->height;
			break;
		case DIR_EAST:
			rc->left= mapW;
			rc->top= conn->shift;
			rc->right= rc->left + cmap->width;
			rc->bottom= rc->top + cmap->height;
			break;
		case DIR_SOUTH:
			rc->left= conn->shift;
			rc->top= mapH;
			rc->right= rc->left + cmap->width;
			rc->bottom= rc->top + cmap->height;
			break;
		default:
			AGB_ASSERT(0);
		}
	}
}

//! Get the 'direction' enum for this tile
/*!	\note	If you don't like the way it looks, it's because the
*	  currently defined direction #defines don't allow for something
*	  nicer. Ptuh!
*/
int mhGetConnDir(const aMapHeader *mh, int tx, int ty)
{
	int mapW= mh->map->width, mapH= mh->map->height;

	if(tx<0)
		return (ty<0 || ty>=mapH ? DIR_BORDER : DIR_WEST);
	else if(tx>=mapW)
		return (ty<0 || ty>=mapH ? DIR_BORDER : DIR_EAST);

	if(ty<0)
		return DIR_NORTH;
	else if(ty>=mapH)
		return DIR_SOUTH;

	return DIR_CENTER;
}

int mhGetConnId(const aMapHeader *mh, int tx, int ty, int dir)
{
	int ii;

	if(mh->conns == NULL) return -1;
	int nConns= mh->conns->numconns;
	aConnection *conn;
	const aMap *map;

	for(ii=0; ii<nConns; ii++)
	{
		conn= &mh->conns->conns[ii];
		if(conn->direction != dir)
			continue;

		map= (aMap*)MapHeaderList[conn->level]->map;

		if(dir==DIR_NORTH || dir==DIR_SOUTH)
		{
			if( IN_RANGE(tx-conn->shift, 0, map->width) )
				return ii;
		}
		else
		{
			if( IN_RANGE(ty-conn->shift, 0, map->height) )
				return ii;
		}
	}
	return -1;
}

//! Get a metatile from a map, including borders and connections.
MetaTile *mhGetMetaTile(const aMapHeader *mh, int tx, int ty)
{
	int id, dir;
	const aMap *map= mh->map;
	aConnection *conn;

	dir= mhGetConnDir(mh, tx, ty);

	switch(dir)
	{
	case DIR_CENTER:
		if(mh == currentMapHeader)
			id = MapBuffer[ty*map->width+tx]; //KAWA
		else
			id = map->mapdata[ty*map->width+tx];
		break;
	case DIR_BORDER:
		id= ((u16*)map->border)[(tx&1)|2*(ty&1)];
		break;
	default:
		id= mhGetConnId(mh, tx, ty, dir);
		if(id>=0)	// An actual connection
		{
			conn= &mh->conns->conns[id];
			return mhGetMetaTile(MapHeaderList[conn->level],
				tx-gConnRects[id].left, ty-gConnRects[id].top);
		}
		else		// Just another border
			id= ((u16*)map->border)[(tx&1)|2*(ty&1)];
	}

	if (id < 0x280)
		return (MetaTile*)&map->tileseta->blockdata[id];
	else
		return (MetaTile*)&map->tilesetb->blockdata[id-0x280];
}

u16 mhGetMetaTileFlags(const aMapHeader *mh, int tx, int ty)
{
	return mhGetMetaTile(mh, tx, ty)->flags;
}

// === FUNCTIONS ======================================================

void mapLoad(u32 index) //this one by Kawa
{
	MyPlayer.currentMap = index;

	AGBPrintf("mapLoad: told to load map #%d.\n", index);

	if(MapHeaderList[index] == 0)
	{
		AGBPrintf("mapLoad: map header for %d is null.\n", index);
		return;
	}

	currentMapHeader = (aMapHeader*)MapHeaderList[index];
	currentLevel = (aMap*)currentMapHeader->map;
	currentMonsters[0] = (aEncounterSet*)currentMapHeader->GrassMonsters;
	currentMonsters[1] = (aEncounterSet*)currentMapHeader->WaterMonsters;
	currentMonsters[2] = (aEncounterSet*)currentMapHeader->FishingMonsters;
	currentMonsters[3] = (aEncounterSet*)currentMapHeader->TreeMonsters;

	DmaCopy(currentLevel->mapdata, MapBuffer, (currentLevel->width * currentLevel->height) * 2);

	if((u32)currentMonsters[0] < 0x08000000)
		currentMonsters[0] = 0;
	if((u32)currentMonsters[1] < 0x08000000)
		currentMonsters[1] = 0;
	if((u32)currentMonsters[2] < 0x08000000)
		currentMonsters[2] = 0;
	if((u32)currentMonsters[3] < 0x08000000)
		currentMonsters[3] = 0;

	if(currentLevel->tileseta->flags & 1)
	{
		//Inside
		//DmaCopy(currentLevel->tileseta->pic, MEM_VRAM, 0x5000);
		LZ77UnCompVram(currentLevel->tileseta->pic, (void*)MEM_VRAM);
		DmaCopy(currentLevel->tileseta->colordata, MEM_PAL, 512);
		if(currentLevel->tilesetb)
		{
			//DmaCopy(currentLevel->tilesetb->pic, MEM_VRAM+0x5000, 0x3000);
			LZ77UnCompVram(currentLevel->tilesetb->pic, (void*)MEM_VRAM+0x5000);
			DmaCopy(currentLevel->tilesetb->colordata, MEM_PAL, 512);
		}
	}
	else
	{
		//Outside
		//DmaCopy(currentLevel->tileseta->pic, MEM_VRAM, 0x5000);
		LZ77UnCompVram(currentLevel->tileseta->pic, (void*)MEM_VRAM);
		LoadTimeAdjustedColors((u16*)MEM_PAL, currentLevel->tileseta->colordata, 256);
		if(currentLevel->tilesetb)
		{
			//DmaCopy(currentLevel->tilesetb->pic, MEM_VRAM+0x5000, 0x3000);
			LZ77UnCompVram(currentLevel->tilesetb->pic, (void*)MEM_VRAM+0x5000);
			LoadTimeAdjustedColors((u16*)MEM_PAL, currentLevel->tilesetb->colordata, 256);
		}

		//No and/or here -- the local tileset's lightmap -supplements- the global's.
		//if(currentLevel->tileseta->lightmap)
		//	LoadLightmap((u16*)MEM_PAL, currentLevel->tileseta->lightmap);
		//if(currentLevel->tilesetb->lightmap)
		//	LoadLightmap((u16*)MEM_PAL, currentLevel->tilesetb->lightmap);
	}

	mhInitConnRects(currentMapHeader);

	if(!GETBIT(ScriptFlags, ISSURFING))
		sndFadeToSound(currentMapHeader->Music);

	LoadPeople(currentMapHeader);
	LoadFrame();

	NextWeatherEffect = 0;
	if(	currentMapHeader->Weather &&
		currentMapHeader->Weather < 7)
	{
		if(WeatherEffect)
		{
			//Already have a weather effect running - queue the next one.
			NextWeatherEffect = WeatherEffects[currentMapHeader->Weather];
			WeatherEffect(WEATHER_STOP);
		}
		else
		{
			//No effect right now - start the new one immediately.
			WeatherEffect = WeatherEffects[currentMapHeader->Weather];
			WeatherEffect(WEATHER_INIT);
		}
	}
	else
	{
		WeatherEffect = 0;
	}

	//Check for initializing map scripts
	CallingPeople = -1;
	if(currentMapHeader->scriptA) ScriptLoop(currentMapHeader->scriptA);
}

void mapLoadMinimal(u32 index)
{
	if(currentLevel->tileseta->flags & 1)
	{
		//DmaCopy(currentLevel->tileseta->pic, MEM_VRAM, 0x5000);
		LZ77UnCompVram(currentLevel->tileseta->pic, (void*)MEM_VRAM);
		DmaCopy(currentLevel->tileseta->colordata, MEM_PAL, 256);
		if(currentLevel->tilesetb)
		{
			//DmaCopy(currentLevel->tilesetb->pic, MEM_VRAM+0x5000, 0x3000);
			LZ77UnCompVram(currentLevel->tilesetb->pic, (void*)MEM_VRAM+0x5000);
			DmaCopy(currentLevel->tilesetb->colordata, MEM_PAL, 400);
		}
	}
	else
	{
		//DmaCopy(currentLevel->tileseta->pic, MEM_VRAM, 0x5000);
		LZ77UnCompVram(currentLevel->tileseta->pic, (void*)MEM_VRAM);
		LoadTimeAdjustedColors((u16*)MEM_PAL, currentLevel->tileseta->colordata, 256);
		if(currentLevel->tilesetb)
		{
			//DmaCopy(currentLevel->tilesetb->pic, MEM_VRAM+0x5000, 0x3000);
			LZ77UnCompVram(currentLevel->tilesetb->pic, (void*)MEM_VRAM+0x5000);
			LoadTimeAdjustedColors((u16*)MEM_PAL, currentLevel->tilesetb->colordata, 256);
		}
	}
	LoadFrame();
}


// 20061207: Mostly obsolete
int mapGetMetaId(const aMap *map, int tx, int ty)
{
	if(tx<0 || tx >= map->width)
		return 0;

	if(ty<0 || ty >= map->height)
		return 0;

	return map->mapdata[ty*map->width+tx];
}

// 20061207: Mostly obsolete
MetaTile *mapGetMetaTile(const aMap *map, int tx, int ty)
{
	int id;

	if( IN_RANGE(tx, 0, map->width) && IN_RANGE(ty, 0, map->height) )
	{
		id = map->mapdata[ty*map->width+tx];
	}
	else
	{
		// check connections
		id= ((u16*)map->border)[(tx&1)|2*(ty&1)];
	}

	if (id < 0x280)
		return (MetaTile*)&map->tileseta->blockdata[id];
	else
		return (MetaTile*)&map->tilesetb->blockdata[id-0x280];
}

// 20061207: Mostly obsolete
//u16 mapGetMetaTileFlags(const aMap *map, int tx, int ty)
//{
//	return mapGetMetaTile(map, tx, ty)->flags;
//}


aCamera gCam=
{
	0, 0,
	0, 0,
	0, 0
};

// 20061222: fix for diagonals, and for connections
// 20061207: changed to use mhGetMetaTile
void camUpdate(int px, int py)
{
	int ii;
	int tpx,tpy, tcx,tcy, tmp;

	// Go to metatile size
	py -= 16;
	tpx= gCameraX>>4;
	tpy= gCameraY>>4;

	tcx= gCam.oldX>>4;
	tcy= gCam.oldY>>4;

	//tcx= gCameraX>>4; tcy= gCameraY>>4;

	if( tpx != tcx )
	{
		tmp= (tpx>tcx ? tpx+15 : tpx);
		for(ii=0; ii<16; ii++)
			mapDrawMeta(tmp+gMapOfsX,
						tpy+ii+gMapOfsY,
						mhGetMetaTile(currentMapHeader, tmp, tpy+ii)
						);
	}

	if( tpy != tcy )
	{
		if(tpy>tcy)
			tpy += 15;
		for(ii=0; ii<16; ii++)
			mapDrawMeta(tpx+ii+gMapOfsX, tpy+gMapOfsY,
				mhGetMetaTile(currentMapHeader, tpx+ii, tpy));
	}

	gCam.oldX= gCameraX;
	gCam.oldY= gCameraY;
	gCameraX= px;
	gCameraY= py;

	BGScrollX= gCam.oldX + gMapOfsX*16;
	BGScrollY= gCam.oldY + gMapOfsY*16+8;

	/*
	gCameraX= px;
	gCameraY= py;

	px += gMapOfsX*16;
	py += gMapOfsY*16+8;

	BGScrollX = px; BGScrollY = py;
	*/
}

void mhRedraw(const aMapHeader *mh, int tx, int ty)
{
	int ix, iy;

	gMapOfsX = 0;
	gMapOfsY = 0;

	for(iy=ty; iy<ty+16; iy++)
		for(ix=tx; ix<tx+16; ix++)
			mapDrawMeta(ix, iy, mhGetMetaTile(mh, ix, iy));
}

void mapDrawMeta(s32 tx, s32 ty, const MetaTile *meta)
{
	u32 ofs= (ty&15)*64 + (tx&15)*2;
	u16 *mapTop, *mapFake;

	BG3MAP[ofs+ 0]= *(u16*)&meta->lt0;
	BG3MAP[ofs+ 1]= *(u16*)&meta->lt1;
	BG3MAP[ofs+32]= *(u16*)&meta->lt2;
	BG3MAP[ofs+33]= *(u16*)&meta->lt3;

	if(meta->flags & MAP16_ONBG1)
	{	mapTop= BG1MAP;	mapFake= BG2MAP;	}
	else
	{	mapTop= BG2MAP;	mapFake= BG1MAP;	}

	mapTop[ofs+ 0]= *(u16*)&meta->ut0;
	mapTop[ofs+ 1]= *(u16*)&meta->ut1;
	mapTop[ofs+32]= *(u16*)&meta->ut2;
	mapTop[ofs+33]= *(u16*)&meta->ut3;

	mapFake[ofs+ 0]= 0;
	mapFake[ofs+ 1]= 0;
	mapFake[ofs+32]= 0;
	mapFake[ofs+33]= 0;
}

extern const u8 WalkDistLUT[8];
extern const u8 hopOffsets[16];

void HandleCamera()
{
	s32 nx, ny;

	nx = (Actors[0].mx-7) << 4;
	ny = ((Actors[0].my-4) << 4); // + 8;
	if(Actors[0].state == ACTSTATE_WALK || Actors[0].state == ACTSTATE_SURFUP)
	{
		if(Actors[0].direction == 0)
			ny += WalkDistLUT[Actors[0].frameindex];
		if(Actors[0].direction == 1)
			nx += WalkDistLUT[Actors[0].frameindex];
		if(Actors[0].direction == 2)
			ny -= WalkDistLUT[Actors[0].frameindex];
		if(Actors[0].direction == 3)
			nx -= WalkDistLUT[Actors[0].frameindex];
	}
	if(Actors[0].state == ACTSTATE_HOP)
	{
		if(Actors[0].direction == 0)
			ny += hopOffsets[Actors[0].frameindex];
		if(Actors[0].direction == 1)
			nx += hopOffsets[Actors[0].frameindex];
		if(Actors[0].direction == 3)
			nx -= hopOffsets[Actors[0].frameindex];
	}
	camUpdate(nx, ny);
}

void FocusCam()
{
	REG_BG1HOFS= BGScrollX;
	REG_BG1VOFS= BGScrollY;

	REG_BG2HOFS= BGScrollX;	
	REG_BG2VOFS= BGScrollY;

	REG_BG3HOFS= BGScrollX;
	REG_BG3VOFS= BGScrollY;
}

void CheckMapCrossing()
{
	aMapHeader *mh= currentMapHeader;
	if(mh == NULL)
		return;

	int dir = mhGetConnDir(mh, Actors[0].mx, Actors[0].my);
	int id;
	aConnection *conn;

	//AGBPrintf("CheckMapCrossing: dir = %d, mh = %x\n", dir,mh);
	if(dir != DIR_CENTER)
	{
		id = mhGetConnId(mh, Actors[0].mx, Actors[0].my, dir);
		AGBPrintf("CheckMapCrossing: dir = %d, id = %d, mx = %d, my = %d\n", dir,id,Actors[0].mx,Actors[0].my);
		AGB_ASSERT(id>=0);

		conn = &mh->conns->conns[id];

		AGBPrintf("CheckMapCrossing: crossing to level #%d.\n", conn->level);
		//DoVBlank();

		//MoveRoamer(5);

		Actors[0].mx -= gConnRects[id].left;
		Actors[0].my -= gConnRects[id].top;

		int dx= gConnRects[id].left, dy= gConnRects[id].top;

		gCameraX -= dx*16;	gCameraY -= dy*16;
		gCam.oldX -= dx*16;	gCam.oldY -= dy*16;
		gMapOfsX += dx;		gMapOfsY += dy;

		mapLoad(conn->level);
		if(currentMapHeader->scriptB)
		{
			AGBPrintf("This map has an After script.\n");
			CallingPeople = -1;
			ScriptLoop(currentMapHeader->scriptB);
		}
		else if(currentMapHeader->ShowName == 1)
		{
			AGBPrintf("CheckMapCrossing: invoking PlaceNameBox state...\n");
			if(CurrentProcess == 0) //FIX 2a
			{
				PreviousProcess = CurrentProcess;
				CurrentProcess = PlaceNameBox;
				SM_PlaceNameBox.state = 0;
				PlaceNameBox();
				REG_BG0VOFS = 0;
				SM_PlaceNameBox.state = 4;
			}
		}
	}
}

//----------------------------------------------------------------

//Everything from this line down by Kawa


int animframe;
int animtimer;

/** \brief Handles animated tilesets on the overworld with callbacks defined in the map header. */
void AnimateTiles()
{
	if(currentLevel)
	{
		animtimer++;
		if(animtimer > 9)
		{
			animtimer=0;
			animframe++;

			if(currentLevel->tileseta->animator != 0)
				currentLevel->tileseta->animator();
			if(currentLevel->tilesetb != 0)
				if(currentLevel->tilesetb->animator != 0)
					currentLevel->tilesetb->animator();

		}
	}
}



void WeatherNone(int state)
{
	if(state == WEATHER_STOP)
	{
		WeatherEffect = NextWeatherEffect;
		NextWeatherEffect = 0;
		WeatherEffect(WEATHER_INIT);
	}
}

extern int WeatherStartOamIdx;
void WeatherFog(int state)
{
	static int FogFadeState;
	static int FogFadeValue = 0;
	static int FogTimer;
	if(state == WEATHER_INIT)
	{
		REG_BLDCNT = BLD_STD | BLD_BOT(BLD_BG1) | BLD_BOT(BLD_BG2) | BLD_BOT(BLD_BG3) | BLD_BOT(BLD_OBJ);
		REG_BLDY = 0x0000;
		REG_BLDALPHA = (0x10 - ((FogFadeValue >> 2) - 0x4)) << 8 | (FogFadeValue >> 2);
		DmaArrayCopy(fogTiles,MEM_VRAM_OBJ+0x5000);
		DmaArrayCopy(fogPal,MEM_PAL_OBJ+0x1A0);
		WeatherStartOamIdx = 24;
		FogFadeState = 1;
	} else if(state == WEATHER_STOP)
	{
		FogFadeState = 2;
	} else if(state == WEATHER_RUN)
	{
		if(FogFadeState == 1)
		{
			if(FogFadeValue >= 0xC << 2)
			{
				FogFadeState = 0;
			} else
			{
				FogFadeValue++;
			}
		} else if(FogFadeState == 2)
		{
			if(FogFadeValue == 0)
			{
				FogFadeState = 0;
				WeatherStartOamIdx = 0;
				REG_BLDCNT = 0;
				REG_BLDY = 0;
				REG_BLDALPHA = 0;
				WeatherEffect = NextWeatherEffect;
				NextWeatherEffect = 0;
				WeatherEffect(WEATHER_INIT);
			} else
			{
				FogFadeValue--;
			}
		}
		int i;
		int h=0;
		int v=0;
		REG_BLDCNT = BLD_STD | BLD_BOT(BLD_BG1) | BLD_BOT(BLD_BG2) | BLD_BOT(BLD_BG3) | BLD_BOT(BLD_OBJ);
		REG_BLDY = 0x0000;
		REG_BLDALPHA = (0x10 - ((FogFadeValue >> 2) - 0x4)) << 8 | (FogFadeValue >> 2);
		for(i = 0; i < 24; i++)
		{
			OamBak[i].ObjMode = 1;
			OamBak[i].CharNo = 640;
			OamBak[i].Pltt = 13;
			OamBak[i].Size = 3;
			OamBak[i].Shape = 0;
			OamBak[i].Priority = 2;
			OamBak[i].HPos = -(FogTimer>>1) - (h * 64);
			OamBak[i].VPos = v * 64;
			h++;
			if(h==8)
			{
				h=0;
				v++;
			}
		}
		FogTimer++;
		if(FogTimer==128) FogTimer=0;
	}
}

void WeatherClouds(int state)
{
	static signed int CloudHPos;
	static unsigned int CloudVPos;
	if(state == WEATHER_INIT)
	{
		DmaArrayCopy(reflectedcloudsTiles,MEM_VRAM_OBJ+0x5000);
		LoadTimeAdjustedColors((u16*)MEM_PAL_OBJ+0xD0, (u16*)reflectedcloudsPal, 16);
	} else if(state == WEATHER_STOP)
	{
		WeatherEffect = NextWeatherEffect;
		NextWeatherEffect = 0;
		WeatherEffect(WEATHER_INIT);
	} else if(state == WEATHER_RUN)
	{
		OamBak[100].ObjMode = 1;
		OamBak[100].CharNo = 640;
		OamBak[100].Pltt = 13;
		OamBak[100].Size = 3;
		OamBak[100].Shape = 0;
		OamBak[100].Priority = 3;
		OamBak[100].HPos = -64 + (CloudHPos>>1);
		OamBak[100].VPos = CloudVPos;
		CloudHPos++;
		if(CloudHPos > 600)
		{
			CloudVPos = rrand(80)*2;
			CloudHPos = 0;
		}
	}
}

void WeatherSandstorm(int state)
{
	static signed int StormPos;
	static int StormFadeState;
	static int StormFadeValue;
	if(state == WEATHER_INIT)
	{
		DmaArrayCopy(sandstormTiles,MEM_VRAM_OBJ+0x5000);
		DmaArrayCopy(sandstormPal, MEM_PAL_OBJ+0x1A0);
		WeatherStartOamIdx = 32;
		StormFadeState = 1;
		REG_BLDCNT = BLD_STD | BLD_BOT(BLD_BG1) | BLD_BOT(BLD_BG2) | BLD_BOT(BLD_BG3) | BLD_BOT(BLD_OBJ);
		REG_BLDY = 0x0000;
		REG_BLDALPHA = (0x20 - (StormFadeValue >> 1)) << 8 | (StormFadeValue >> 1);
	} else if(state == WEATHER_STOP)
	{
		StormFadeState = 2;

	} else if(state == WEATHER_RUN)
	{
		if(StormFadeState == 1)
		{
			if(StormFadeValue >= 0x1F << 1)
			{
				StormFadeState = 0;
			} else
			{
				StormFadeValue++;
			}
		} else if(StormFadeState == 2)
		{
			if(StormFadeValue == 0)
			{
				StormFadeState = 0;
				REG_BLDCNT = 0;
				REG_BLDY = 0;
				REG_BLDALPHA = 0;
				WeatherStartOamIdx = 0;
				WeatherEffect = NextWeatherEffect;
				NextWeatherEffect = 0;
				WeatherEffect(WEATHER_INIT);
			} else
			{
				StormFadeValue--;
			}
		}
		int i;
		int h=0;
		int v=0;
		REG_BLDCNT = BLD_STD | BLD_BOT(BLD_BG1) | BLD_BOT(BLD_BG2) | BLD_BOT(BLD_BG3) | BLD_BOT(BLD_OBJ);
		REG_BLDY = 0x0000;
		REG_BLDALPHA = (0x1F - (StormFadeValue >> 1)) << 8 | (StormFadeValue >> 1);
		for(i = 0; i < 32; i++)
		{
			OamBak[i].ObjMode = 1;
			OamBak[i].CharNo = 642 + ((((i + StormPos) >> 2) % 2) * 16);
			OamBak[i].Pltt = 13;
			OamBak[i].Size = 3;
			OamBak[i].Shape = 0;
			OamBak[i].Priority = 1;
			OamBak[i].HPos = -(StormPos * 2) - (h * 64);
			OamBak[i].VPos = -StormPos - (v * 64);
			h++;
			if(h==8)
			{
				h=0;
				v++;
			}
		}
		StormPos++;
	}
}

void * WeatherEffects[] =
{
	0, //no weather at all, stop immediatly (inside)
	WeatherClouds,
	WeatherNone, //no weather, gently transition (outside)
	0, //WeatherRain
	0, //WeatherSnow
	0, //WeatherThunder
	WeatherFog,
	0, //WeatherSnow
	WeatherSandstorm,
	0, //WeatherFogDiagonal
	0, //WeatherFogThinBright
	0, //WeatherDark
	0, //WeatherBright
	0, //WeatherTorrent
	0, //WeatherUnderwater
	0, //none
};
