//======================================================================
//
//	OpenPoké town map screen
//		(the item / whole region)
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"

extern const unsigned short worldmapPal[32];
extern const unsigned short worldmapTiles[5408];
extern const unsigned short worldmapMap[640];

extern unsigned short mapedgesPal[16];
extern unsigned short mapedgesTiles[3072];

extern unsigned short mapiconsPal[64];
extern unsigned short mapiconsTiles[512];

void TownMap()
{
	signed int i;
	int cursorX, cursorY, cursorPulse = 0, cursorDelay = 0;
	int MapHotspots[32][32][2];

	CleanUpCrap();
	ClearOamBak();

	REG_BG0CNT = BG_8BPP | BG_SIZE0 | BG_PRIO(1) | 30 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT;
	REG_BG2CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(0) | 28 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = -8;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;

	//DmaArrayCopy(worldmapTiles, MEM_VRAM + 0x0000);
	//DmaArrayCopy(worldmapMap, MEM_VRAM + 0xF000);
	LZ77UnCompVram(worldmapTiles, (short*)(MEM_VRAM + 0x0000));
	LZ77UnCompVram(worldmapMap, (short*)(MEM_VRAM + 0xF000));
	DmaArrayCopy(worldmapPal, MEM_PAL_BG + 0x0000);

	//DmaArrayCopy(mapedgesTiles, MEM_VRAM_OBJ + 0x0640);
	LZ77UnCompVram(mapedgesTiles, (short*)(MEM_VRAM_OBJ + 0x0640));
	DmaArrayCopy(mapedgesPal, MEM_PAL_OBJ + 0x100);

	DmaClear(0xFFFFFFFF, MEM_VRAM + 0x3c00, 32);
	DmaClear(0x11E011E0, MEM_VRAM + 0xe800, 1260);

	//DmaClear(0xFFFFFFFF, MEM_VRAM_OBJ + 0x0000, 32);
	DmaArrayCopy(mapiconsPal, MEM_PAL_OBJ);
	DmaArrayCopy(mapiconsTiles, MEM_VRAM_OBJ);

	OamBak[0].CharNo = 114;
	OamBak[0].Shape = 2;
	OamBak[0].Size = 3;
	OamBak[0].Pltt = 8;
	OamBak[0].HPos = 88;
	OamBak[0].VPos = 136;
	OamBak[1].CharNo = 82;
	OamBak[1].Shape = 2;
	OamBak[1].Size = 3;
	OamBak[1].Pltt = 8;
	OamBak[1].HPos = 88;
	OamBak[1].VPos = 72;
	OamBak[2].CharNo = 50;
	OamBak[2].Shape = 2;
	OamBak[2].Size = 3;
	OamBak[2].Pltt = 8;
	OamBak[2].HPos = 88;
	OamBak[2].VPos = 8;

	OamBak[3].CharNo = 210;
	OamBak[3].Shape = 2;
	OamBak[3].Size = 3;
	OamBak[3].Pltt = 8;
	OamBak[3].HPos = 120;
	OamBak[3].VPos = 136;
	OamBak[4].CharNo = 178;
	OamBak[4].Shape = 2;
	OamBak[4].Size = 3;
	OamBak[4].Pltt = 8;
	OamBak[4].HPos = 120;
	OamBak[4].VPos = 72;
	OamBak[5].CharNo = 146;
	OamBak[5].Shape = 2;
	OamBak[5].Size = 3;
	OamBak[5].Pltt = 8;
	OamBak[5].HPos = 120;
	OamBak[5].VPos = 8;

	REG_DISPCNT =  DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D;

	for(i = 0; ; i++)
	{
		if(MapLocations[i].x == 0xFF)
			break;
		MapHotspots[MapLocations[i].x][MapLocations[i].y][!(i<20)] = i;
		if(MapLocations[i].shape == 1 || MapLocations[i].shape == 3)
			MapHotspots[MapLocations[i].x][MapLocations[i].y+1][0] = i;
		if(MapLocations[i].shape == 2 || MapLocations[i].shape == 3)
			MapHotspots[MapLocations[i].x+1][MapLocations[i].y][0] = i;
		if(MapLocations[i].shape == 3)
			MapHotspots[MapLocations[i].x+1][MapLocations[i].y+1][0] = i;
	}

	FadeIn();

	REG_WININ = WIN_BG0 | WIN_OBJ;
	REG_WINOUT = WIN_BG1 | WIN_OBJ;
	REG_DISPCNT =  DCNT_MODE0 | DCNT_OBJ | DCNT_BG0 | DCNT_BG2 | DCNT_OBJ_1D | DCNT_WIN0;
	REG_WIN0V = 2;
	REG_WIN0H = 2;

	for(i = 88; i >= -8; i-=4)
	{
		REG_WIN0H = (i+32) << 8 | (120+88-i);
		REG_WIN0V = 16 << 8 | 160;
		OamBak[0].HPos = i;
		OamBak[1].HPos = i;
		OamBak[2].HPos = i;
		OamBak[3].HPos = 120 + 88-i;
		OamBak[4].HPos = 120 + 88-i;
		OamBak[5].HPos = 120 + 88-i;
		DoVBlank();
	}

	DmaClear(0,BG2MAP,0x700);

	for(i = 0; i < 15; i++)
	{
		BG2MAP[0x43 + i] = 96 + i + 0xF000;
		BG2MAP[0x63 + i] = 128 + i + 0xF000;
		BG2MAP[0x83 + i] = 160 + i + 0xF000;
		BG2MAP[0xA3 + i] = 192 + i + 0xF000;
	}

	OamBak[6].HPos = (MapLocations[currentMapHeader->NameIndex].x * 8) + -4;
	OamBak[6].VPos = (MapLocations[currentMapHeader->NameIndex].y * 8) + 4;
	OamBak[6].CharNo = 0;
	OamBak[6].Shape = 0;
	OamBak[6].Size = 1;
	OamBak[6].Pltt = 0;
	cursorX = MapLocations[currentMapHeader->NameIndex].x;
	cursorY = MapLocations[currentMapHeader->NameIndex].y;

	OamBak[7].HPos = (MapLocations[currentMapHeader->NameIndex].x * 8) + -4;
	OamBak[7].VPos = (MapLocations[currentMapHeader->NameIndex].y * 8) + 4;
	OamBak[7].CharNo = 8 + (MyPlayer.gender * 4);
	OamBak[7].Shape = 0;
	OamBak[7].Size = 1;
	OamBak[7].Pltt = 1 + MyPlayer.gender;

	for(i = 0; i < 16; i++)
	{
		if(Roamers[i].map)
		{
			OamBak[8+i].HPos = (MapLocations[Roamers[i].map].x * 8) + -4;
			OamBak[8+i].VPos = (MapLocations[Roamers[i].map].y * 8) + 4;
			OamBak[8+i].CharNo = 8;
			OamBak[8+i].Shape = 0;
			OamBak[8+i].Size = 1;
			OamBak[8+i].Pltt = 3;
		}
	}

//REG_DISPCNT =  DCNT_MODE0 | DCNT_BG0 | DCNT_WIN0;
	REG_BLDCNT = BLD_BLACK | BLD_BG0;
	REG_BLDALPHA = 0x0000;
	REG_BLDY = 0x0004;
	REG_WIN0H = 24 << 8 | 143;
	REG_WIN0V = 8 << 8 | 32;
	REG_WINOUT = WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_OBJ; //0x0011;
	REG_WININ = WIN_BLD | WIN_BG0 | WIN_BG1 | WIN_BG2 | WIN_OBJ; //0x0031;

	vwWhiteTransparentLUT();
	vwWrite(2,2,MapNames[MapHotspots[cursorX][cursorY][0]]);
	if(MapHotspots[cursorX][cursorY][1])
	{
		REG_WIN0V = 8 << 8 | 48;
		vwWrite(12,18,MapNames[MapHotspots[cursorX][cursorY][1]]);
	}

	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & KEY_B)
			break;
		if(Cont & KEY_UP && !cursorDelay && cursorY > 3)
			cursorY--;
		if(Cont & KEY_DOWN && !cursorDelay && cursorY < 17)
			cursorY++;
		if(Cont & KEY_LEFT && !cursorDelay && cursorX > 4)
			cursorX--;
		if(Cont & KEY_RIGHT && !cursorDelay && cursorX < 25)
			cursorX++;
		if(Cont && !cursorDelay)
			cursorDelay = 5;
		if(Cont)
		{
			REG_WIN0V = 0;
			vwClear(0);
			if(MapHotspots[cursorX][cursorY][0])
			{
				REG_WIN0V = 8 << 8 | 32;
				vwWrite(2,2,MapNames[MapHotspots[cursorX][cursorY][0]]);
				if(MapHotspots[cursorX][cursorY][1])
				{
					REG_WIN0V = 8 << 8 | 48;
					vwWrite(12,18,MapNames[MapHotspots[cursorX][cursorY][1]]);
				}
			}
		}
		if(cursorDelay) cursorDelay--;
		OamBak[6].CharNo = ((cursorPulse++ >> 4) % 2) * 4;
		OamBak[6].HPos = (cursorX * 8) + -4;
		OamBak[6].VPos = (cursorY * 8) + 4;
	}

	for(i=0; i<16; i++) OamBak[6+i].VPos = 180;

	REG_WININ = WIN_BG0 | WIN_OBJ;
	REG_WINOUT = WIN_BG1 | WIN_OBJ;
	REG_DISPCNT =  DCNT_MODE0 | DCNT_OBJ | DCNT_BG0 | DCNT_BG2 | DCNT_OBJ_1D | DCNT_WIN0;
	REG_WIN0V = 2;
	REG_WIN0H = 2;

	for(i = -8; i <= 88; i+=3)
	{
		REG_WIN0H = (i+32) << 8 | (120+88-i);
		REG_WIN0V = 16 << 8 | 160;
		OamBak[0].HPos = i;
		OamBak[1].HPos = i;
		OamBak[2].HPos = i;
		OamBak[3].HPos = 120 + 88-i;
		OamBak[4].HPos = 120 + 88-i;
		OamBak[5].HPos = 120 + 88-i;
		DoVBlank();
	}

	FadeOut();

	REG_DISPCNT =  DCNT_MODE0 | DCNT_OBJ | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ_1D;

	REG_BG0VOFS = 0;
	vwNormalLUT();
	ResetBackgrounds();

}

