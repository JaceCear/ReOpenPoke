/**	\file miscevents.c
		\brief Miscellaneous things that can happen on the map
		\author Kawa
*/
#include "openpoke.h"

/** \brief Displays a GSC-style "being called" box on the screen and blinks the caller ID in it a couple times.
		\todo Phone sound?
*/
void Phonecall(char *caller)
{
	char b[128];
	int i;
	int rings;

	CpuFastArrayCopy(uiframeTiles, MEM_VRAM+0x8140);
	CpuFastArrayCopy(uiframePal, MEM_PAL_BG+0x1A0);
	BG0MAP[0] = 0xD00A;
	BG0MAP[29] = 0xD00C;
	BG0MAP[32] = 0xD00D;
	BG0MAP[61] = 0xD00F;
	BG0MAP[64] = 0xD00D;
	BG0MAP[93] = 0xD00F;
	BG0MAP[96] = 0xD010;
	BG0MAP[125] = 0xD012;
	for(i=1; i < 29; i++)
	{
		BG0MAP[i] = 0xD00B;
		BG0MAP[32+i] = 0xD000 + 95 + i;
		BG0MAP[64+i] = 0xD000 + 127 + i;
		BG0MAP[96+i] = 0xD011;
	}

	vwClearLine(1,0);
	vwClearLine(1,1);
	sprintf(b,"¯ %s", caller);

	for(rings = 0; rings < 7; rings++)
	{
		if(rings % 2 == 0)
		{
			vwWrite(4,0,b);
		} else
		{
			vwClearLine(1,0);
			vwClearLine(1,1);
			vwWrite(4,0,"¯");
		}
		for(i = 0; i < 20; i++)
		{
			DoVBlank();
			KeyRead();
		}
	}

	for(i = 0; i < 126; i++)
		BG0MAP[i] = 0;
}



void Phone_Maple()
{
	sayf(SPEECH,"Oh hi honey! How's your "POKE"Dex\ncoming along?");
}

void Phone_Joshua()
{
	sayf(SYSTEM,"No carrier.");
}

void Phone_Olson()
{
	sayf(SYSTEM,"No carrier.");
}

void Phone_Toku()
{
	sayf(SYSTEM,"No carrier.");
}

void Phone_Mom()
{
	sayf(SPEECH,"Hi dear!");
}

void Phone_Kawa()
{
	sayf(SPEECH,"I AM GOD HERE!");
}

void Phone_Barry()
{
	sayf(SYSTEM,"No carrier.");
}

void Phone_Sato()
{
	sayf(SPEECH,"Yes, this is Satoshi Tajiri?");
}

const void * const PhoneScripts[] =
{
	0,
	Phone_Maple,
	Phone_Joshua,
	Phone_Olson,
	Phone_Toku,
	Phone_Mom,
	Phone_Kawa,
	Phone_Barry,
	Phone_Sato,
};




//------------------
// APARTMENT SYSTEM
//------------------
anInventoryItem ApartmentFurniture[MAXAPARTMENTITEMDEFS] INEWRAM;
const unsigned short apartmentSmallDeskDef[] = { 0x283 };
const unsigned short apartmentPrettyChairDef[] = { 0x284 };
const unsigned short apartmentHeavyChairDef[] = { 0x285 };
const unsigned short apartmentTableDef[] = { 0x28A, 0x28B, 0x292, 0x293 };
const unsigned short apartmentTireDef[] = { 0x288, 0x289, 0x290, 0x291 };
const unsigned short apartmentTropicalPlantDef[] = { 0x28C, 0x294 };
const unsigned short apartmentRedPlantDef[] = { 0x28D, 0x295 };
const unsigned short apartmentPrettyFlowersDef[] = { 0x298, 0x2A0 };
const unsigned short apartmentGlassOrnamentDef[] = { 0x299, 0x2A1 };
const unsigned short apartmentStoneOrnamentDef[] = { 0x29A, 0x2A2 };
const unsigned short apartmentSilverShieldDef[] = { 0x286, 0x28E };
const unsigned short apartmentGoldShieldDef[] = { 0x287, 0x28F };
const anApartmentItemDefinition ApartmentItemDefinitions[] =
{
	{ 0, 0, 0, 0, "---" },
	{ 1, 1, 0, apartmentSmallDeskDef, "Small Desk" },
	{ 1, 1, 0, apartmentPrettyChairDef, "Pretty Chair" },
	{ 1, 1, 0, apartmentHeavyChairDef, "Heavy Chair" },
	{ 2, 2, 0, apartmentTableDef, "Table" },
	{ 2, 2, 0, apartmentTireDef, "Tire" },
	{ 1, 2, 1, apartmentTropicalPlantDef, "Tropical Plant" },
	{ 1, 2, 1, apartmentRedPlantDef, "Red Plant" },
	{ 1, 2, 1, apartmentPrettyFlowersDef, "Pretty Flowers" },
	{ 1, 2, 1, apartmentGlassOrnamentDef, "Glass Ornament" },
	{ 1, 2, 1, apartmentStoneOrnamentDef, "Stone Ornament" },
	{ 1, 2, 1, apartmentSilverShieldDef, "Silver Shield" },
	{ 1, 2, 1, apartmentGoldShieldDef, "Gold Shield" },
	{ 0, 0, 0, 0, "---" },
};


anApartmentItem ApartmentItems[MAXAPARTMENTITEMS] INEWRAM;
extern u16 MapBuffer[] INEWRAM;

void RemoveApartmentItem(int item)
{
	int x,y,mappos;
	anApartmentItemDefinition * myItemDef = (anApartmentItemDefinition*)&ApartmentItemDefinitions[ApartmentItems[item].type];
	for(y = 0; y < myItemDef->ysize; y++)
	{
		for(x = 0; x < myItemDef->xsize; x++)
		{
			mappos = (y+ApartmentItems[item].ypos-myItemDef->top) * currentLevel->width + (x+ApartmentItems[item].xpos);
			MapBuffer[mappos] = currentLevel->mapdata[mappos];
		}
	}
}

void DrawApartmentItem(int item)
{
	int x,y,i=0,mappos;
	anApartmentItemDefinition * myItemDef = (anApartmentItemDefinition*)&ApartmentItemDefinitions[ApartmentItems[item].type];
	for(y = 0; y < myItemDef->ysize; y++)
	{
		for(x = 0; x < myItemDef->xsize; x++)
		{
			mappos = (y+ApartmentItems[item].ypos-myItemDef->top) * currentLevel->width + (x+ApartmentItems[item].xpos);
			if(MapBuffer[mappos] == 0x111) MapBuffer[mappos] = myItemDef->tiles[i] + 0x28;
			else if(MapBuffer[mappos] == 0xA3) MapBuffer[mappos] = myItemDef->tiles[i] + 0x50;
			else MapBuffer[mappos] = myItemDef->tiles[i];
			i++;
		}
	}
}

int CheckApartmentPlacement(int item)
{
	//TODO	Check for overlapping items.
	//Also, the area immediatly in front
	//of the doorway must be kept clear so
	//you can, at the very least, reach
	//the Apartment Editor console:
	//        ==== _
	// _______|  |_T_______
	// ######XXXXXXX#######
	// ####################
	//(drawn on 2:1 ratio, so two chars =
	//one Map16 tile.)
	//This also has the added benefit
	//that you can't place items in front
	//of the door frame, which would cause
	//tile mismatch problems of its own.
	return 1;
}

void SetupApartment()
{
	int i;
	DmaCopy(currentLevel->mapdata, MapBuffer, (currentLevel->width * currentLevel->height) * 2);
	for(i = 0; i < MAXAPARTMENTITEMS; i++)
	{
		if(ApartmentItems[i].type == 0) continue;
		if(ApartmentItems[i].type < 16) DrawApartmentItem(i);
	}
}

void DrawApartment()
{
	extern u8	gMapOfsX, gMapOfsY;
	int ix, iy;
	gMapOfsX = 0;
	gMapOfsY = 0;
	for(iy=0; iy<10; iy++)
		for(ix=0; ix<10; ix++)
			mapDrawMeta(ix, iy, mhGetMetaTile(currentMapHeader, ix, iy));
}

void ApartmentBlinkItem(int item, int blinktimer)
{
	RemoveApartmentItem(item);
	if(blinktimer % 10 < 5)	DrawApartmentItem(item);
	DrawApartment();
}

extern unsigned short mapiconsPal[64];
extern unsigned short mapiconsTiles[512];

void ApartmentBuildCursor()
{
	int i;
	DmaArrayCopy(mapiconsPal, MEM_PAL_OBJ);
	DmaArrayCopy(mapiconsTiles, MEM_VRAM_OBJ);
	for(i=0; i<4; i++)
	{
		OamBak[120+i].CharNo = i;
		OamBak[120+i].Size = 0;
		OamBak[120+i].Shape = 0;
		OamBak[120+i].Pltt = 0;
		OamBak[120+i].Priority = 0;
	}
}
void ApartmentCursor(int sel)
{
	anApartmentItemDefinition * myItemDef = (anApartmentItemDefinition*)&ApartmentItemDefinitions[ApartmentItems[sel].type];
	if(sel == 0xFF)
	{
		OamBak[120].HPos = 240;
		OamBak[121].HPos = 240;
		OamBak[122].HPos = 240;
		OamBak[123].HPos = 240;
	}
	OamBak[120].HPos = (ApartmentItems[sel].xpos * 16) - 2;
	OamBak[120].VPos = ((ApartmentItems[sel].ypos-myItemDef->top) * 16) - 2;
	OamBak[121].HPos = ((ApartmentItems[sel].xpos+myItemDef->xsize) * 16) - 6;
	OamBak[121].VPos = ((ApartmentItems[sel].ypos-myItemDef->top) * 16) - 2;
	OamBak[122].HPos = (ApartmentItems[sel].xpos * 16) - 2;
	OamBak[122].VPos = ((ApartmentItems[sel].ypos+myItemDef->ysize-myItemDef->top) * 16) - 6;
	OamBak[123].HPos = ((ApartmentItems[sel].xpos+myItemDef->xsize) * 16) - 6;
	OamBak[123].VPos = ((ApartmentItems[sel].ypos+myItemDef->ysize-myItemDef->top) * 16) - 6;
}

void DrawApartmentItemList(int offset)
{
	int i,y=0;
	vwClear(0);
	for(i = 0; i < 12; i++)
	{
		if(ApartmentItems[i+offset].type)
		{
			vwWrite(12,12+(i*12),ApartmentItemDefinitions[ApartmentItems[i+offset].type].name);
		} else
		{
			if(!y) vwWrite(12,12+(i*12),"[Add…]");
			y++;
		}
	}
}

int ApartmentListItem(int index)
{
	int i,j = 0;
	for(i = 0; i < MAXAPARTMENTITEMS; i++)
	{
		if(ApartmentItems[i].type == index) j++;
		//sayf(SYSTEM,"%d\n%d",j,index);
		if(ApartmentItems[i].type == 0) return j-1;
	}
	return j-1;
}

void DrawApartmentItemChoices(int offset)
{
	int i, y = 0;
	vwClear(0);
	for(i = 0; i < 12; i++)
	{
		if(ApartmentItemDefinitions[ApartmentFurniture[offset+i+1].itemidx].xsize)
		{
			if(ApartmentListItem(ApartmentFurniture[offset+i+1].itemidx) == 0) vwRedTransparentLUT();
			vwWrite(12, 12+(i*12), ApartmentItemDefinitions[ApartmentFurniture[offset+i+1].itemidx].name);
			vwWhiteTransparentLUT();
		} else
		{
			if(!y) vwWrite(12, 12+(i*12), "[Cancel]");
			y++;
		}
	}
}

void GiveApartmentItem(int index)
{
	int i;
	for(i = 0; i < MAXAPARTMENTITEMDEFS; i++)
	{
		if(ApartmentFurniture[i].itemidx == index) //have one of these already
		{
			ApartmentFurniture[i].itemcnt++;
			break;
		}
		if(ApartmentFurniture[i].itemcnt == 0) //empty slot
		{
			ApartmentFurniture[i].itemidx = index;
			ApartmentFurniture[i].itemcnt = 1;
			break;
		}
	}
}

void TakeApartmentItem(int index)
{
	int i,j;
	if(index==0) return;
	for(i = 0; i < MAXAPARTMENTITEMDEFS; i++)
	{
		if(inventory[i].itemidx == index) //found item
		{
			ApartmentFurniture[i].itemcnt--;
			if(ApartmentFurniture[i].itemcnt == 0) //that the last one?
			{
				for(j = i; j < MAXAPARTMENTITEMDEFS - 2; j++)
				{
					ApartmentFurniture[j].itemidx = ApartmentFurniture[j+1].itemidx;
					ApartmentFurniture[j].itemcnt = ApartmentFurniture[j+1].itemcnt;
				}
				ApartmentFurniture[j].itemidx = 0;
				ApartmentFurniture[j].itemcnt = 0;
			}
			break;
		}
	}
}

void EditApartment()
{
	int i,x,y,state=0,sel=0,offset=0,offset2=0;
	char foo[32];

	GiveApartmentItem(1);
	GiveApartmentItem(4);
	GiveApartmentItem(5);
	GiveApartmentItem(6);
	GiveApartmentItem(5);

	currentMapHeader = (aMapHeader*)MapHeaderList[108];
	currentLevel = (aMap*)currentMapHeader->map;
	LZ77UnCompVram(currentLevel->tileseta->pic, (void*)MEM_VRAM);
	LZ77UnCompVram(currentLevel->tilesetb->pic, (void*)MEM_VRAM+0x5000);
	DmaCopy(currentLevel->tilesetb->colordata, MEM_PAL, 512);
	pal_bg_mem[0] = 0x0000;
	CpuFastArrayCopy(uiframeTiles, MEM_VRAM+0x8140);
	CpuFastArrayCopy(uiframePal, MEM_PAL_BG+0x1E0);

	x = 96;
	for(i = 0; i < 20; i+=2)
	{
		vwSetLine(20,16,i,x,15);
		x+=64;
	}

	while(1)
	{
		if(state==0) //select object
		{
			SetupApartment();
			DrawApartment();
			ApartmentBuildCursor();
			vw_SetSmall();
			vwWhiteTransparentLUT();
			DrawApartmentItemList(offset);
			y = 0;
			x = 0;
			for(i = 0; i < MAXAPARTMENTITEMS; i++)
				if(ApartmentItems[i].type) x++;
			if(x == 13) x = 12;
			vwWrite(2,12+(sel*12),">");
			ApartmentCursor(sel+offset);
			while(1)
			{
				DoVBlank();
				KeyRead();
				if(Trg & KEY_B)
				{
					state = -1;
					break;
				}
				if(Trg & KEY_A)
				{
					if(ApartmentItems[sel+offset].type)
						state = 1; //decide
					else
						state = 4; //replace
					break;
				}
				if(Trg & KEY_UP)
				{
					vwWrite(2,12+(sel*12),"  ");
					if(sel)
					{
						sel--;
					} else
					{
						if(offset) offset--;
						DrawApartmentItemList(offset);
					}
					vwWrite(2,12+(sel*12),">");
					ApartmentCursor(sel+offset);
				}
				if(Trg & KEY_DOWN && ApartmentItems[sel+offset].type)
				{
					vwWrite(2,12+(sel*12),"  ");
					sel++;
					if(sel==12)
					{
						sel=11;
						offset++;
						DrawApartmentItemList(offset);
					}
					vwWrite(2,12+(sel*12),">");
					ApartmentCursor(sel+offset);
				}
				if(offset) vwWrite(8,0,"^");
				if(offset < x - 11) vwWrite(16,0,"v");

				sprintf(foo,"%d, %d",sel,offset);
				vwWrite(128,0,foo);
				vwWrite(128,16,ApartmentItemDefinitions[ApartmentItems[sel+offset].type].name);
			}
		} else if(state == 1) //decide
		{
			y = 0;
			vwClear(0);
			vwWrite(12,12,"Move");
			vwWrite(12,24,"Replace");
			vwWrite(12,36,"Remove");
			vwWrite(12,48,"Cancel");
			vwWrite(2,12+(y*12),">");
			while(1)
			{
				DoVBlank();
				KeyRead();
				if(Trg & KEY_B)
				{
					state = 0; //select
					break;
				}
				if(Trg & KEY_A)
				{
					if(y == 0) state = 2; //move
					else if(y == 1) state = 4; //replace
					else if(y == 2) state = 3; //remove
					else if(y == 3) state = 0; //select
					break;
				}
				if(Trg & KEY_UP && y)
				{
					vwWrite(2,12+(y*12),"  ");
					y--;
					vwWrite(2,12+(y*12),">");
				}
				if(Trg & KEY_DOWN && y < 4)
				{
					vwWrite(2,12+(y*12),"  ");
					y++;
					vwWrite(2,12+(y*12),">");
				}
			}
		} else if(state == 2) //move
		{
			vwClear(0);
			i = 0;
			x = ApartmentItems[sel+offset].xpos;
			y = ApartmentItems[sel+offset].ypos;
			if(ApartmentItems[sel+offset].ypos < 2) ApartmentItems[sel+offset].ypos = 2;
			while(1)
			{
				DoVBlank();
				KeyRead();
				ClearOamBak();
				i++;
				ApartmentBlinkItem(sel+offset,i);
				if(Trg & KEY_A)
				{
					if(CheckApartmentPlacement(sel+offset))
					{
						state = 0;
						break;
					}
				}
				if(Trg & KEY_B)
				{
					ApartmentItems[sel+offset].xpos = x;
					ApartmentItems[sel+offset].ypos = y;
					state = 0;
					if(y == 0) state =3;
					break;
				}
				if(Trg & KEY_LEFT && ApartmentItems[sel].xpos > 0)
				{
					ApartmentItems[sel+offset].xpos--;
					SetupApartment();
					DrawApartment();
				}
				if(Trg & KEY_RIGHT && ApartmentItems[sel].xpos < 10-ApartmentItemDefinitions[ApartmentItems[sel].type].xsize)
				{
					ApartmentItems[sel+offset].xpos++;
					SetupApartment();
					DrawApartment();
				}
				if(Trg & KEY_UP && ApartmentItems[sel].ypos > 2)
				{
					ApartmentItems[sel+offset].ypos--;
					SetupApartment();
					DrawApartment();
				}
				if(Trg & KEY_DOWN && ApartmentItems[sel].ypos < 10-ApartmentItemDefinitions[ApartmentItems[sel].type].ysize + ApartmentItemDefinitions[ApartmentItems[sel].type].top)
				{
					ApartmentItems[sel+offset].ypos++;
					SetupApartment();
					DrawApartment();
				}
				CheckApartmentPlacement(sel+offset);
				ApartmentCursor(sel+offset);
			}
		} else if(state == 3) //remove
		{
			for(i = sel+offset; i < MAXAPARTMENTITEMS - 1; i++)
			{
				ApartmentItems[i].type = ApartmentItems[i+1].type;
				ApartmentItems[i].xpos = ApartmentItems[i+1].xpos;
				ApartmentItems[i].ypos = ApartmentItems[i+1].ypos;
			}
			ApartmentItems[i].type = 0;
			ApartmentItems[i].xpos = 0;
			ApartmentItems[i].ypos = 0;
			state = 0;
		} else if(state == 4) //replace
		{
			DrawApartmentItemChoices(offset2);
			x = 0;
			for(y = 0; y < MAXAPARTMENTITEMDEFS; y++)
				if(ApartmentItemDefinitions[ApartmentFurniture[y+1].itemidx].xsize) x++;
				else break;
			y = 0;
			vwWrite(2,12+(y*12),">");
			while(1)
			{
				DoVBlank();
				KeyRead();
				if(Trg & KEY_B)
				{
					state = 0; //select
					break;
				}
				if(Trg & KEY_A)
				{
					if(ApartmentFurniture[1+y+offset2].itemidx == 0)
					{
						state = 0; //select
						break;
					}
					if(ApartmentListItem(ApartmentFurniture[offset2+y+1].itemidx) >= ApartmentFurniture[offset2+y+1].itemcnt - 1)
					{
						//TODO	Beep here.
						//sayf(SYSTEM,"No.");
						state = 4; //replace
						break;
					}
					if(ApartmentFurniture[offset2+y+1].itemidx)
					{
						ApartmentItems[sel+offset].type = ApartmentFurniture[offset2+y+1].itemidx;
						state = 2; //move
					} else
					{
						state = 0; //select
					}
					break;
				}
				if(Trg & KEY_UP)
				{
					vwWrite(2,12+(y*12),"  ");
					if(y)
					{
						y--;
					} else
					{
						if(offset2) offset2--;
						DrawApartmentItemChoices(offset2);
					}
					vwWrite(2,12+(y*12),">");
				}
				if(Trg & KEY_DOWN && ApartmentItemDefinitions[ApartmentFurniture[1+y+offset2].itemidx].xsize)
				{
					vwWrite(2,12+(y*12),"  ");
					y++;
					if(y==12)
					{
						y=11;
						offset2++;
						DrawApartmentItemChoices(offset2);
					}
					vwWrite(2,12+(y*12),">");
				}
				if(offset2) vwWrite(8,0,"^");
				if(offset2 < x - 11) vwWrite(16,0,"v");
				sprintf(foo,"%d, %d, %d",offset2, x, x-11);
				vwWrite(128,0,foo);
				vwWrite(128,16,ApartmentItemDefinitions[ApartmentFurniture[1+y+offset2].itemidx].name);
			}
		} else if(state == -1) //shutdown
		{
			CleanUpCrap();
			vwClear(0);
			vwNormalLUT();
			vw_SetBig();
			LoadFrame();
			break;
		}
	}
}


extern const unsigned short titlecardTiles[8514];
extern const unsigned short titlecardMap[690];
extern const unsigned short titlecardPal[256];
extern const unsigned short titlecardcornerTiles[128];
extern const unsigned short titlecardcornerPal[16];
extern const char oamfontWidths[];

const char * const EpisodeNames[] =
{
	"    FedEx Quests\n"
	"    For the Lose",
	"    Schrodinger's\n"
	"       Porygon",
	"   To Master the\n"
	"      Onixpected",
	"   Viva Las Lapras",
	"       The Amber\n"
	"     Chunksickles",
	"     Gettin' the\n"
	"       Bugs Out",
	"Machoke, Machoke\n"
	"          Man",
	"Love, Pok~mon style",
	" All Things Bright\n"
	"   And Beautifly",
	" A Mudkip Mission",
	"    An Elite Greet\n"
	"       and Meet",
	"     I Feel Skitty!",
};

void TitleCard(int episode)
{
	int i = 0,j = 0, ny = 0, nx = 0, butt = 0;
	char * epi = (char*)EpisodeNames[episode];


	REG_DISPCNT = 0;
	REG_BG1CNT |= BG_8BPP;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	ClearOamBak();
	LZ77UnCompVram(titlecardTiles,(void*)MEM_VRAM);
	LZ77UnCompVram(titlecardMap,(void*)(MEM_VRAM+0xE800));
	DmaCopy(titlecardPal, MEM_PAL, 512);
	DmaArrayCopy(fontOamPal, MEM_PAL_OBJ);
	DmaArrayCopy(fontOamTiles, MEM_VRAM_OBJ);
	DmaArrayCopy(titlecardcornerPal, MEM_PAL_OBJ+32);
	DmaArrayCopy(titlecardcornerTiles, MEM_VRAM_OBJ+0x4000);
	REG_DISPCNT = DCNT_BG1 | DCNT_OBJ | DCNT_OBJ_1D;
	FadeIn();

	OamBak[0].HPos = 240-32;
	OamBak[0].VPos = 160;
	OamBak[0].Pltt = 1;
	OamBak[0].CharNo = 512;
	OamBak[0].Shape = 1;
	OamBak[0].Size = 2;

	nx = 48;
	ny = 56;

	while(1)
	{
		if(j < 100) j++;
		if(j == 5)
		{
			j = 0;
			if(epi[i] == '\n')
			{
				i++;
				ny += 16;
				nx = 48;
			}
			if(epi[i] == ' ')
			{
				nx+=oamfontWidths[epi[i]-' ']-1;
				i++;
			}
			OamBak[1+i].CharNo =  ((epi[i]-' ')*4);
			OamBak[1+i].VPos = ny;
			OamBak[1+i].HPos = nx;
			OamBak[1+i].Shape = 0;
			OamBak[1+i].Size = 1;
			OamBak[1+i].Pltt = 0;
			nx+=oamfontWidths[epi[i]-' ']-1;
			i++;
			if(epi[i] == '\0')
			{
				j=100;
				butt++;
			}
		}
		if(butt && butt < 16)
		{
			OamBak[0].VPos = 160 - butt;
			butt++;
		}

		DoVBlank();
		KeyRead();
		if(Trg)
		{
			FadeOut();
			REG_BG1CNT &= ~BG_8BPP;
			ResetDispCnt();
			CleanUpCrap();
			break;
		}
	}
}
