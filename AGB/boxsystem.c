/**	\file boxsystem.c
		\brief Box management system
		\author Kawa
*/
#include "openpoke.h"

/*
	MENUS
	-----
	[X], SUMMARY, [Y], MARK, RELEASE, CANCEL

	Boxed monsters: Y = WITHDRAW
	Party monsters: Y = STORE

	Idle monsters: X = MOVE
	Held monsters: X = PLACE
	Collission: X = SWITCH

	Box caption: JUMP, WALLPAPER, NAME, CANCEL

	On B or Close...
	if Holding "You're holding a Pokémon!"
	if not Holding "Continue box operations?" (default to NO)
	if in Party Tab, close it

	WALLPAPERS
	Scene 1 - Forest, City, Desert, Savanna
	Scene 2 - Crag, Volcano, Snow, Cave
	Scene 3 - Beach, Seafloor, River, Sky
	Etcetera - Stars, Pokémon Center, Tiles, Simple
*/

//Whole bunch of MultipleChoice things...
//const CHOICELIST Choice_Box1 = { 6, 1, (u32*)Choices_Box1 };
//const CHOICELIST Choice_Box2 = { 6, 1, (u32*)Choices_Box2 };
//const CHOICELIST Choice_Box3 = { 6, 1, (u32*)Choices_Box3 };
//const CHOICELIST Choice_Box4 = { 6, 1, (u32*)Choices_Box4 };
//const CHOICELIST Choice_Box5 = { 6, 1, (u32*)Choices_Box5 };
//const CHOICELIST Choice_Box6 = { 6, 1, (u32*)Choices_Box6 };
//const CHOICELIST Choice_Box = { 4, 1, (u32*)Choices_Box };
//const CHOICELIST Choice_Wallpaper = { 3, 0, (u32*)Choices_Wallpaper };
//const CHOICELIST Choice_Wallpapers[] =
//{
//	{ 4, 0, (u32*)Choices_Wallpaper1 },
//	{ 4, 0, (u32*)Choices_Wallpaper2 },
//	{ 3, 0, (u32*)Choices_Wallpaper3 },
//};

//Assets
extern const unsigned short boxuiPal[16];
extern const unsigned short boxuiTiles[1728];
extern const unsigned short boxuiMap[2048];

extern const unsigned short boxhandPal[16];
extern const unsigned short boxhandTiles[1024];

extern const unsigned short boxselwinPal[16];
extern const unsigned short boxselwinTiles[1280];

extern const unsigned short boxbgPal[16];
extern const unsigned short boxbgTiles[896];
extern const unsigned short boxbgMap[640];
extern const unsigned short boxbg01Pal[16];
extern const unsigned short boxbg01Tiles[864];
extern const unsigned short boxbg02Pal[16];
extern const unsigned short boxbg02Tiles[864];
extern const unsigned short boxbg03Pal[16];
extern const unsigned short boxbg03Tiles[864];
extern const unsigned short boxbg04Pal[16];
extern const unsigned short boxbg04Tiles[864];
extern const unsigned short boxbg05Pal[16];
extern const unsigned short boxbg05Tiles[864];
extern const unsigned short boxbg06Pal[16];
extern const unsigned short boxbg06Tiles[864];
extern const unsigned short boxbg07Pal[16];
extern const unsigned short boxbg07Tiles[864];
extern const unsigned short boxbg08Pal[16];
extern const unsigned short boxbg08Tiles[864];
extern const unsigned short boxbg09Pal[16];
extern const unsigned short boxbg09Tiles[864];
extern const unsigned short boxbg10Pal[16];
extern const unsigned short boxbg10Tiles[864];
extern const unsigned short boxbg15Pal[16];
extern const unsigned short boxbg15Tiles[864];

const unsigned short * boxbgs[] =
{
	boxbg01Pal, boxbg01Tiles,
	boxbg02Pal, boxbg02Tiles,
	boxbg03Pal, boxbg03Tiles,
	boxbg04Pal, boxbg04Tiles,
	boxbg05Pal, boxbg05Tiles,
	boxbg06Pal, boxbg06Tiles,
	boxbg07Pal, boxbg07Tiles,
	boxbg08Pal, boxbg08Tiles,
	boxbg09Pal, boxbg09Tiles,
	boxbg10Pal, boxbg10Tiles,
	boxbg15Pal, boxbg15Tiles,
};

extern const u8 MonIconColors[254];
extern const unsigned short * PartyPics[];
extern const unsigned short PartyPal[64];

extern void ShowStatus(aPokemon * toshow);
extern void spindaDrawSpots(void *dst, u32 pv);

//Metrics
#define HAND_GRID 0			//Element IDs,
#define HAND_CAPTION 1	//or "what do
#define HAND_PARTYTAB 2	//we point at
#define HAND_CLOSE 3		//right about
#define HAND_PARTY 4		//now?"

#define BOX_NAMELENGTH 10	//Max length of a single box name

#define BOX_PARTYMON_FIRST_X 88			//Screen position of the first monster in your party
#define BOX_PARTYMON_FIRST_Y 48
#define BOX_PARTYMON_OTHERS_X 136		//Starting screen position of the other monsters in your party
#define BOX_PARTYMON_OTHERS_Y 0
#define BOX_PARTYMON_INCREMENT 24		//Step value for BOX_PARTYMON_OTHERS_Y
#define BOX_FIRST_X 84							//Screen position of the first monster on the grid
#define BOX_FIRST_Y 28
#define BOX_INCREMENT_X 24					//Step values for the grid
#define BOX_INCREMENT_Y 24
#define BOX_HAND_HEIGHT 16					//How high from the grid the hand should be
#define BOX_GRABBEDMON_INCREMENT 4	//How far from the hand the held monster should be
#define BOX_SIDEMON_X 8							//Screen position of the 64x64 monster image
#define BOX_SIDEMON_Y 16
#define BOX_HAND_CAPTION_X 146			//Cursor positions for the other elements
#define BOX_HAND_CAPTION_Y 252
#define BOX_HAND_PARTYTAB_X 104
#define BOX_HAND_PARTYTAB_Y 248
#define BOX_HAND_PARTYTAB_Y2 254
#define BOX_HAND_CLOSE_X 192
#define BOX_HAND_CANCEL_Y 116

//Tile map for the party tab
const unsigned short BoxPartyTab[] =
{
	//Top line
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x46,
	//Second
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x89,0x8A,0x8A,0x8B,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x8C,0x8D,0x8D,0x8E,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x8F,0x90,0x90,0x91,0x46,
	//Third
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x92,0x93,0x93,0x94,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x95,0x96,0x96,0x97,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x98,0x99,0x99,0x9A,0x46,
	//First and fourth
	0x45,0x80,0x81,0x81,0x82,0x3B,0x3B,0x9B,0x9C,0x9C,0x9D,0x46,
	0x45,0x83,0x84,0x84,0x85,0x3B,0x3B,0x9E,0x9F,0x9F,0xA0,0x46,
	0x45,0x86,0x87,0x87,0x88,0x3B,0x3B,0xA1,0xA2,0xA2,0xA3,0x46,
	//Fifth
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0xA4,0xA5,0xA5,0xA6,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0xA7,0xA8,0xA8,0xA9,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0xAA,0xAB,0xAB,0xAC,0x46,
	//Sixth
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0xAD,0xAE,0xAE,0xAF,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0xB0,0xB1,0xB1,0xB2,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0xB3,0xB4,0xB4,0xB5,0x46,
	//Seperator
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x3B,0x46,
	//Cancel button
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x58,0x59,0x5A,0x5B,0x5C,0x46,
	0x45,0x3B,0x3B,0x3B,0x3B,0x3B,0x5D,0x5E,0x5F,0x60,0x61,0x46,
	//Bottom and tab
	0x62,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x64,0x65,0x65,0x66,
	0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x00,0x00,0x00,
	0x27,0x28,0x29,0x2A,0x2B,0x2C,0x2D,0x2E,0x2F,0x00,0x00,0x00,
	//Clearer
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

//Our settings
char boxnames[14][BOX_NAMELENGTH];
char boxwalls[14];

//-----------------------------------------------------------------------//

/** \brief Draws the party tab at a given pulldown distance. */
void DrawPartyTab(int size)
{
	int i,j, start;
	start = (23 - (size+1)) * 12;
	for(i = 0; i < size+1; i++)
	{
		for(j = 0; j < 12; j++)
		{
			se_mat[30][i][10+j] = BoxPartyTab[start + (i * 12) + j];
		}
	}
	if(size==2)
	{
		se_mat[30][0][21] = 0x14;
		se_mat[30][1][21] = 0x30;
	}

	OamBak[2].HPos = BOX_PARTYMON_FIRST_X;
	signed int foo = BOX_PARTYMON_FIRST_Y - ((22-size)*8);
	if(foo < -32) foo = 180;
	OamBak[2].VPos = foo;
	for(i = 1; i < 7; i++)
	{
		OamBak[2+i].HPos = BOX_PARTYMON_OTHERS_X;
		foo = BOX_PARTYMON_OTHERS_Y + ((i-1) * BOX_PARTYMON_INCREMENT) - ((22-size)*8);
		if(foo < -32) foo = 180;
		OamBak[2+i].VPos = foo;
	}
}

/** \brief Another variant. */
void BoxSetLine(int x, int w, int y, unsigned short start, unsigned char pal)
{
	u16 *BG = ((u16*)0x600D800);
	int b= 0;
	u16 tpal = pal<<12;
	for(b=x; b<x+w; b++)
	{
		BG[(y*32)+b] = start + tpal;
		BG[(y*32)+b+32] = start + 32 + tpal;
		start++;
	}
}

/** \brief Sets up the sprites for monsters in the given box, draws the box's caption and loads its' wallpaper. */
void DrawBox(int bno)
{
	int i=0,x,y, species;
	//ssGrowth *myG;
	for(y = 0; y < 5; y++)
	{
		for(x = 0; x < 6; x++)
		{
			//aBoxedMon * mon = DecryptBoxedMon(&MyBox[i + (bno * 30)]);
			//myG = GetGrowthSubstruct((aPokemon*)mon);
			//species = myG->Species;
			//EncryptBoxedMon(mon);
			species = GetMonsterStats((aPokemon*)&MyBox[i + (bno * 30)], pSpecies);

			if(species == 0)
			{
				OamBak[20+i].HPos = 250;
			} else
			{
				OamBak[20+i].Pltt = 1 + MonIconColors[species];
				OamBak[20+i].CharNo = i * 16;
				OamBak[20+i].Shape = 0;
				OamBak[20+i].Size = 2;
				OamBak[20+i].HPos = BOX_FIRST_X + (x*BOX_INCREMENT_X);
				OamBak[20+i].VPos = BOX_FIRST_Y + (y*BOX_INCREMENT_Y);
				OamBak[20+i].Priority = 2;
				DmaCopy(PartyPics[species], MEM_VRAM_OBJ + (i*0x200), 512);
			}

			i++;

		}
	}
	char foo[32];
	sprintf(foo,"%s        ",boxnames[bno]);
	int pl = vwf_measure_string(foo);
	int sx = 160 - (pl / 2);
	TVwf *vwf= gp_vwf;
	u32 *oldd = vwf->dstD;
	vwf->dstD = (u32*)0x06016400;
	vwf->colors[0]= 0;
	vwf->colors[TEXT_INK]= 7;
	vwf->colors[TEXT_SHADOW]= 1;
	vwf->colors[TEXT_PAPER]= 0;
	vwWrite(0,0,foo);
	vwNormalLUT();
	vwf->dstD = oldd;
	OamBak[16].CharNo = 800;
	OamBak[16].Pltt = 0;
	OamBak[16].Shape = 1;
	OamBak[16].Size = 1;
	OamBak[16].Priority = 2;
	OamBak[16].HPos = sx;
	OamBak[16].VPos = 20;
	OamBak[17].CharNo = 804;
	OamBak[17].Pltt = 0;
	OamBak[17].Shape = 1;
	OamBak[17].Size = 1;
	OamBak[17].Priority = 2;
	OamBak[17].HPos = sx+32;
	OamBak[17].VPos = 20;
	OamBak[18].CharNo = 832;
	OamBak[18].Pltt = 0;
	OamBak[18].Shape = 1;
	OamBak[18].Size = 1;
	OamBak[18].Priority = 2;
	OamBak[18].HPos = sx;
	OamBak[18].VPos = 28;
	OamBak[19].CharNo = 836;
	OamBak[19].Pltt = 0;
	OamBak[19].Shape = 1;
	OamBak[19].Size = 1;
	OamBak[19].Priority = 2;
	OamBak[19].HPos = sx+32;
	OamBak[19].VPos = 28;

	DmaCopy(boxbgs[ (boxwalls[bno])* 2   ], pal_bg_bank[2], 32);
	DmaCopy(boxbgs[((boxwalls[bno])* 2)+1], MEM_VRAM + 0x2040, 0x700);
}

/** \brief Prepares the sprites for the party tab and loads the right tiles to fill in taken slots. */
void PreparePartyTab()
{
	int i;
	int ps = GetPartySize(&MyParty);
	for(i = 0; i < ps; i++)
	{
		int species = GetMonsterStats(&MyParty[i], pSpecies);

		OamBak[2+i].Pltt = 1 + MonIconColors[species];
		OamBak[2+i].CharNo = 512 + (i * 16);
		OamBak[2+i].Shape = 0;
		OamBak[2+i].Size = 2;
		if(species == 0) OamBak[2+i].CharNo = 720;
		OamBak[2+i].Priority = 1;
		DmaCopy(PartyPics[species], MEM_VRAM_OBJ + 0x4000 + (i * 0x200), 512);

		DmaCopy(boxuiTiles + (71*16), MEM_VRAM + 0x1000 + (0x120*i), 0x120);
	}
	for(i = ps; i < 7; i++)
	{
		DmaCopy(boxuiTiles + (80*16), MEM_VRAM + 0x1000 + (0x120*i), 0x80);
		DmaCopy(boxuiTiles + (59*16), MEM_VRAM + 0x1080 + (0x120*i), 0x20);
		DmaCopy(boxuiTiles + (84*16), MEM_VRAM + 0x10A0 + (0x120*i), 0x80);
	}
}

/** \brief Shows information about the selected monster in the sidebar. */
void ShowBoxedMon(aBoxedMon * montoshow)
{
	extern const unsigned long XPRequirements[808];
	int i = 0;
	vwClearLine(0,4);
	vwClearLine(0,8);
	vwClearLine(0,12);
	if(montoshow == 0)
	{
		DmaClear(0, MEM_VRAM_OBJ+0x5C00,0x800);
		return;
	}
	//aBoxedMon * mon = DecryptBoxedMon(montoshow);
	//ssGrowth * myG = GetGrowthSubstruct((aPokemon*)mon);
	int species = GetMonsterStats((aPokemon*)montoshow, pSpecies);
	aBaseStat *myBase = (aBaseStat*)&BaseStats[species];
	char foo[16];
	char genderchar = 0x7F, gendercolor = 1;
	if(myBase->Gender < 0xFF)
	{
		if((u8)montoshow->Personal.Personal > myBase->Gender)
		{
			genderchar = 0x8A; //Male
			gendercolor = 9;
		} else
		{
			genderchar = 0x8B; //Female
			gendercolor = 5;
		}
	}

	int lv = 0;
	int expnow = GetMonsterStats((aPokemon*)montoshow, pExperience);
	for(; i < 100; i++)
	{
		if(expnow <= XPRequirements[(myBase->LevelSlope * 101) + i])
		{
			lv =  i-1;
			break;
		}
	}
	sprintf(foo, "Lv%d \7\1%c%c", lv, gendercolor, genderchar);
	vwWhiteTransparentLUT();
	if(species)
	{
		LZ77UnCompVram(PokePicsFront[species], (unsigned short*)(MEM_VRAM_OBJ + 0x5C00));
		DmaCopy(PokePicsPalette[species], (unsigned short*)MEM_PAL_OBJ + 0x40, 32);
	#ifdef pkSPINDA
		if(species == pkSPINDA)
			spindaDrawSpots((unsigned short*)(MEM_VRAM_OBJ + 0x5C00), montoshow->Personal.Personal);
	#endif
		vwWrite(0,16,montoshow->Personal.Nickname);
		vwWrite(0,30,PokeNames[species]);
		vwWrite(0,44,foo);
	} else
	{
		DmaClear(0, MEM_VRAM_OBJ+0x5C00,0x800);
	}
	vwNormalLUT();
	//EncryptBoxedMon(mon);
}

/** \brief Constructs the basic screen layout for boxes. */
void BoxBuildScreen(int bno, int handx, int handy)
{
	int i;
	u16* BG2 = (u16*)0x600E000;

	REG_BG0CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(0) | 27 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG1CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(1) | 30 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT;
	REG_BG2CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(2) | 28 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT;
	REG_BG3CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(3) | 31 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT;

	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;

	DmaArrayCopy(boxuiPal, pal_bg_mem);
	DmaArrayCopy(boxuiTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(boxuiMap, MEM_VRAM + 0xF000);
	DmaCopy(PartyPal, pal_obj_bank[1], 96);

	for(i=0;i<640;i++) BG2[i] = boxbgMap[i] + 256 + 0x2000 ;

	DmaArrayCopy(boxhandPal, pal_obj_bank[0]);
	DmaArrayCopy(boxhandTiles, MEM_VRAM_OBJ + 0x5000);

	OamBak[0].Pltt = 0;
	OamBak[0].CharNo = 640;
	OamBak[0].Shape = 0;
	OamBak[0].Size = 2;
	OamBak[0].HPos = BOX_FIRST_X + (handx*BOX_INCREMENT_X);
	OamBak[0].VPos = BOX_FIRST_Y - BOX_HAND_HEIGHT + (handy*BOX_INCREMENT_Y);
	OamBak[0].Priority = 1;
	OamBak[1].Pltt = 0;
	OamBak[1].CharNo = 704;
	OamBak[1].Shape = 0;
	OamBak[1].Size = 2;
	OamBak[1].HPos = BOX_FIRST_X + (handx*BOX_INCREMENT_X);
	OamBak[1].VPos = BOX_FIRST_Y - BOX_HAND_HEIGHT + (handy*BOX_INCREMENT_Y) + BOX_GRABBEDMON_INCREMENT;
	OamBak[1].Priority = 1;

	DrawBox(bno);

	PreparePartyTab();
	DrawPartyTab(2);

	DmaArrayCopy(boxuiMap, MEM_VRAM + 0xF000);
	LoadFrame();

	OamBak[15].Pltt = 4;
	OamBak[15].CharNo = 736;
	OamBak[15].Shape = 0;
	OamBak[15].Size = 3;
	OamBak[15].HPos = BOX_SIDEMON_X;
	OamBak[15].VPos = BOX_SIDEMON_Y;

	BoxSetLine(1,8,11,160,15);
	BoxSetLine(1,8,13,224,15);
	BoxSetLine(1,8,15,288,15);
}

/** \brief Fades out the box. */
void BoxFade(int dir)
{
	int i;
	REG_BLDCNT = BLD_BG3|BLD_BG2|BLD_OBJ | BLD_BOT(BLD_BG0|BLD_BG1|BLD_BG2|BLD_BG3|BLD_BD) | BLD_WHITE;
	if(dir==0)
	{
		for(i = 0; i < 16; i+=2)
		{
			REG_BLDY = i;
			DoVBlank();
		}
	} else
	{
		for(i = 15; i >= 0; i-=2)
		{
			REG_BLDY = i;
			DoVBlank();
		}
	}
}

/** \brief Another variant. */
void BoxDrawFrame(int x, int w, int y, int h)
{
	int a, b;
	u16 *BG = ((u16*)0x600D800);
	for(a = x+1; a < x+w-1; a++)
	{
		BG[(y*32)+a] = 0xF002;
		BG[((y+h-1)*32)+a] = 0xF008;
		for(b=y+1; b < y+h-1; b++)
		{
			BG[(b*32)+a] = 0xF005;
		}
	}
	for(a = y+1; a < y+h-1; a++)
	{
		BG[(a*32)+x] = 0xF004;
		BG[(a*32)+x+w-1] = 0xF006;
	}
	BG[(y*32)+x] = 0xF001;
	BG[(y*32)+x+w-1] = 0xF003;
	BG[((y+h-1)*32)+x] = 0xF007;
	BG[((y+h-1)*32)+x+w-1] = 0xF009;
}

/** \brief Another variant. */
void BoxDrawThinFrame(int x, int w, int y, int h)
{
	int a, b;
	u16 *BG = ((u16*)0x600D800);
	for(a = x+1; a < x+w-1; a++)
	{
		BG[(y*32)+a] = 0xE00B;
		BG[((y+h-1)*32)+a] = 0xE011;
		for(b=y+1; b < y+h-1; b++)
		{
			BG[(b*32)+a] = 0xE00E;
		}
	}
	for(a = y+1; a < y+h-1; a++)
	{
		BG[(a*32)+x] = 0xE00D;
		BG[(a*32)+x+w-1] = 0xE00F;
	}
	BG[(y*32)+x] = 0xE00A;
	BG[(y*32)+x+w-1] = 0xE00C;
	BG[((y+h-1)*32)+x] = 0xE010;
	BG[((y+h-1)*32)+x+w-1] = 0xE012;
}

/** \brief Another variant. */
void BoxClearFrame(int x, int w, int y, int h)
{
	int a, b;
	u16 *BG = ((u16*)0x600D800);
	for(a=x; a<x+w; a++)
		for(b=y; b<y+h; b++)
			BG[(b*32)+a] = 0;
}

/** \brief Another variant. */
int BoxMultipleChoice(int left, int top, int width, int choices, int bcancel) //CHOICELIST choices)
{
	int i,j,k,l,c=0;
	extern const char * Choices[];
	AnOptionsSet * set = (AnOptionsSet*)&ChoiceSets[choices];

	BoxDrawFrame(left, width, top, (set->NumChoices*2)+2); //(choices.numchoices*2)+2);
	j = 0;
	k = 113;
	l = 1;
	for(i=0; i < set->NumChoices; i++)
	{
		vwClearLine(1, l);
		vwWriteG(18, j, (char*)Choices[set->Options[i]]);
		BoxSetLine(left+1, width-2, top+1+(i*2), k, 15);
		l +=  4;
		j +=  2;
		k += 64;
	}
	vwWriteG(16,0,strArrow);
	BoxSetLine(left+1,1,top+1,112,15);
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & A_BUTTON)
			break;
		if(Trg & B_BUTTON && bcancel)
		{
			c = set->NumChoices - 1;
			break;
		}
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			BoxSetLine(left+1,1,top+1+(c<<1),176,15);
			c = wrap(c + key_tri_vert(), 0, set->NumChoices);
			BoxSetLine(left+1, 1, top+1+(c<<1), 112, 15);
			sndCursor();
		}
	}
	Trg = 0;
	BoxClearFrame(left, width, top, (set->NumChoices*2)+2);
	return c;
}

/** \brief Wrapper to show the status for the selected monster and rebuild the box screen. */
void BoxShowStatus(aPokemon * montoshow, int isfromparty, int bno)
{
	FadeOut();
	if(isfromparty)
	{
		ShowStatus(montoshow);
		ClearOamBak();
		CleanUpCrap();
		ClearSpriteGFX();
		BoxBuildScreen(bno, 0, 0);
		DrawPartyTab(22);
	} else
	{
		DmaClear(0, &HisParty, sizeof(aPokemon));
		DmaCopy(montoshow, &HisParty, sizeof(aBoxedMon));
		UpdateLiveStats(&HisParty[0]);
		HisParty[0].Status.CurrentHP = HisParty[0].Status.TotalHP;
		ShowStatus(&HisParty[0]);
		ClearOamBak();
		CleanUpCrap();
		ClearSpriteGFX();
		BoxBuildScreen(bno, 0, 0);
	}
	FadeIn();
}

/** \brief Wrapper to show the name entry screen and rebuild the box screen. */
void BoxDoName(int bno)
{
	FadeOut();
	EnterName(boxnames[bno], BOX_NAMELENGTH, "Box name?", 0);
	ClearOamBak();
	CleanUpCrap();
	ClearSpriteGFX();
	BoxBuildScreen(bno, 0, 0);
	FadeIn();
}

int BoxGetAmount(int bno)
{
	int i, j=0;
	for(i=0; i < 5*6; i++)
	{
		if(MyBox[i+(bno*30)].Personal.Personal) j++;
	}
	return j;
}

/** \brief Draws the graphics for the Jump command */
void BoxDoJumpWrite(int bno)
{
	DmaArrayCopy(boxselwinPal, pal_obj_bank[5]);
	DmaArrayCopy(boxselwinTiles, MEM_VRAM_OBJ + 0x6C00);
	char foo[16];
	sprintf(foo,"%2d/30",BoxGetAmount(bno));
	TVwf *vwf= gp_vwf;
	u32 *oldd = vwf->dstD;
	u32 oldp = vwf->dstP;
	vwf->dstD = (u32*)0x06016D00;
	vwf->dstP = 8;
	vwf->colors[0]= 0;
	vwf->colors[TEXT_INK]= 15;
	vwf->colors[TEXT_SHADOW]= 14;
	vwf->colors[TEXT_PAPER]= 4;
	vwWrite(0,0,boxnames[bno]);
	vwWrite(32,16,foo);
	vwNormalLUT();
	vwf->dstD = oldd;
	vwf->dstP = oldp;
}

/** \brief Handles the Jump command */
int BoxDoJump(int boxno)
{
	int bno = boxno;
	OamBak[8].CharNo = 864;
	OamBak[8].Pltt = 5;
	OamBak[8].HPos = 128;
	OamBak[8].VPos = 64;
	OamBak[8].Shape = 0;
	OamBak[8].Size = 3;
	OamBak[9].CharNo = 928;
	OamBak[9].Pltt = 5;
	OamBak[9].HPos = 120;
	OamBak[9].VPos = 64;
	OamBak[9].Shape = 2;
	OamBak[9].Size = 1;
	OamBak[10].CharNo = 932;
	OamBak[10].Pltt = 5;
	OamBak[10].HPos = 120;
	OamBak[10].VPos = 96;
	OamBak[10].Shape = 2;
	OamBak[10].Size = 1;
	OamBak[11].CharNo = 936;
	OamBak[11].Pltt = 5;
	OamBak[11].HPos = 192;
	OamBak[11].VPos = 64;
	OamBak[11].Shape = 2;
	OamBak[11].Size = 1;
	OamBak[12].CharNo = 940;
	OamBak[12].Pltt = 5;
	OamBak[12].HPos = 192;
	OamBak[12].VPos = 96;
	OamBak[12].Shape = 2;
	OamBak[12].Size = 1;

	BoxDoJumpWrite(bno);

	while(1)
	{
		DoVBlank();
		KeyRead();
		if((Trg & KEY_LEFT) || (Trg & KEY_RIGHT))
		{
			bno = wrap(bno + key_tri_horz(), 0, 14);
			BoxDoJumpWrite(bno);
		}
		if(Trg & B_BUTTON)
		{
			bno = -1;
			break;
		}
		if(Trg & A_BUTTON)
		{
			break;
		}
	}
	OamBak[8].HPos = 240;
	OamBak[9].HPos = 240;
	OamBak[10].HPos = 240;
	OamBak[11].HPos = 240;
	OamBak[12].HPos = 240;
	DmaClear(0, MEM_VRAM_OBJ + 0x6C00,0x800);
	Trg = 0;
	return bno;
}

/** \brief Removes message box */
void BoxRemoveMessage()
{
	BoxClearFrame(10,20,16,4);
}

/** \brief Displays messages */
void BoxShowMessage(const char *msg, int iserror)
{
	CpuFastArrayCopy(uiframeTiles, MEM_VRAM+0x8140);
	CpuFastArrayCopy(uiframePal, MEM_PAL_BG+0x1C0);
	BoxDrawThinFrame(10, 20, 16, 4);
	vwClearLine(1,32);
	vwClearLine(1,33);
	vwWrite(0,128,msg);
	BoxSetLine(11, 18, 17, 608, 14);
	if(iserror)
	{
		int i;
		for(i=0; i < 50; i++)
		{
			DoVBlank();
		}
		BoxRemoveMessage();
	}
}

aBoxedMon * BoxGetFirstFreeSpot(int bno)
{
	int i;
	for(i = 0; i < 5*6; i++)
	{
		if(MyBox[i + (bno*30)].Personal.Personal == 0) return &MyBox[i + (bno*30)];
	}
	return 0;
}

/** \brief Main box screen handler */
void ShowBoxes()
{
	int bgscroll = 0, handelement = HAND_GRID, handx = 0, handy = 0, handanim = 0, i, holding = 0, boxno = 0;

	REG_DISPCNT = 0;
	FadeOut();

	CleanUpCrap();

	BoxBuildScreen(boxno, handx, handy);

	ResetDispCnt();
	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		//---------------------------------------------------//
		if(handelement == HAND_GRID)
		{
			if((Trg & KEY_LEFT) || (Trg & KEY_RIGHT))
			{
				handx = wrap(handx + key_tri_horz(), 0, 6);
			} else if((Trg & KEY_UP) && (handy == 0))
			{
				handelement = HAND_CAPTION;
			} else if((Trg & KEY_UP) || (Trg & KEY_DOWN))
			{
				handy = wrap(handy + key_tri_vert(), 0, 5);
			}
			if(!holding) ShowBoxedMon(&MyBox[handx + (handy*6) + (boxno*30)]);
			if(Trg & A_BUTTON)
			{
				if(!holding)
				{
					char foo[64];
					sprintf(foo,strBoxFooIsSelected,MyBox[handx + (handy*6) + (boxno*30)].Personal.Nickname);
					BoxShowMessage(foo,0);
					int c = BoxMultipleChoice(17,2,13, 7,1); //Choice_Box1);
					BoxRemoveMessage();
					if(c==0)
					{
						//aBoxedMon * mon = DecryptBoxedMon(&MyBox[handx + (handy*6) + (boxno*30)]);
						//ssGrowth * myG = GetGrowthSubstruct((aPokemon*)mon);
						//holding = myG->Species;
						holding = GetMonsterStats((aPokemon*)&MyBox[handx + (handy*6) + (boxno*30)], pSpecies);
						//EncryptBoxedMon(mon);
						DmaCopy(&MyBox[handx + (handy*6) + (boxno*30)], &InMyHand, sizeof(aBoxedMon));
						DmaClear(0, &MyBox[handx + (handy*6) + (boxno*30)], sizeof(aBoxedMon));
						DmaCopy(PartyPics[holding], MEM_VRAM_OBJ + 0x5800, 512);
						OamBak[1].Pltt = 1 + MonIconColors[holding];
						AGBPrintf("Picked up boxmon \"%s\" from box %d, %d*%d.\n", InMyHand.Personal.Nickname, boxno, handx,handy);
					} else if(c==1)
					{
						BoxShowStatus((aPokemon*)&MyBox[handx + (handy*6) + (boxno*30)],0,boxno);
					} else if(c==2)
					{
						int ps = GetPartySize(MyParty);
						AGBPrintf("ps: %d\n",ps);
						if(ps == 6)
						{
							BoxShowMessage(strBoxPartyFull,1);
						} else
						{
							DmaClear(0, &MyParty[ps], sizeof(aPokemon));
							DmaCopy(&MyBox[handx + (handy*6) + (boxno*30)], &MyParty[ps], sizeof(aBoxedMon));
							UpdateLiveStats(&MyParty[ps]);
							MyParty[ps].Status.CurrentHP = MyParty[ps].Status.TotalHP;
							DmaClear(0, &MyBox[handx + (handy*6) + (boxno*30)], sizeof(aBoxedMon));
							for(i = 3; i < 23; i++)
							{
								DoVBlank();
								DrawPartyTab(i);
								DoVBlank();
							}
							PreparePartyTab();
							DrawBox(boxno);
							for(i = 22; i > 1; i--)
							{
								DoVBlank();
								DrawPartyTab(i);
								DoVBlank();
							}
						}
					}
					DrawBox(boxno);
				} else
				{
					if(MyBox[handx+(handy*6)+(boxno*30)].Personal.Personal == 0)
					{
						char foo[64];
						sprintf(foo,strBoxFooIsSelected,InMyHand.Personal.Nickname);
						BoxShowMessage(foo,0);
						int c = BoxMultipleChoice(17,2,13, 8,1); //Choice_Box2);
						BoxRemoveMessage();
						if(c==0)
						{
							AGBPrintf("Put down held \"%s\" in box %d, %d*%d.\n", InMyHand.Personal.Nickname, boxno, handx,handy);
							DmaCopy(&InMyHand, &MyBox[handx+(handy*6)+(boxno*30)], sizeof(aBoxedMon));
							DmaClear(0, &InMyHand, sizeof(aBoxedMon));
							holding = 0;
						} else if(c==1)
						{
							BoxShowStatus((aPokemon*)&InMyHand,0,boxno);
						}
						DrawBox(boxno);
					} else
					{
						char foo[64];
						sprintf(foo,strBoxFooIsSelected,InMyHand.Personal.Nickname);
						BoxShowMessage(foo,0);
						int c = BoxMultipleChoice(17,2,13, 9,1); //Choice_Box3);
						BoxRemoveMessage();
						if(c==0)
						{
							aBoxedMon switcher;
							DmaCopy(&InMyHand, &switcher, sizeof(aBoxedMon));
							DmaCopy(&MyBox[handx+(handy*6)+(boxno*30)], &InMyHand, sizeof(aBoxedMon));
							DmaCopy(&switcher, &MyBox[handx+(handy*6)+(boxno*30)], sizeof(aBoxedMon));
							holding = GetMonsterStats(&InMyHand, pSpecies);
							DmaCopy(PartyPics[holding], MEM_VRAM_OBJ + 0x5800, 512);
							OamBak[1].Pltt = 1 + MonIconColors[holding];
							AGBPrintf("Switched held \"%s\" with boxmon \"%s\" from box %d, %d*%d.\n", &MyBox[handx+(handy*6)+(boxno*30)].Personal.Nickname, InMyHand.Personal.Nickname, boxno, handx,handy);
						} else if(c==1)
						{
							BoxShowStatus((aPokemon*)&MyBox[handx + (handy*6) + (boxno*30)],0,boxno);
						}
						DrawBox(boxno);
					}
				}
			}
			OamBak[0].HPos = BOX_FIRST_X + (handx*BOX_INCREMENT_X);
			OamBak[0].VPos = BOX_FIRST_Y - BOX_HAND_HEIGHT + (handy*BOX_INCREMENT_Y);
			OamBak[0].VFlip = 0;

		//---------------------------------------------------//

		} else if(handelement == HAND_CAPTION)
		{
			if((Trg & KEY_LEFT) || (Trg & KEY_RIGHT))
			{
				boxno = wrap(boxno + key_tri_horz(), 0, 14);
				DrawBox(boxno);
				AGBPrintf("Switched to box %d.\n", boxno);
			}
			if(Trg & KEY_DOWN)
			{
				handelement = HAND_GRID;
			} else if(Trg & KEY_UP)
			{
				handelement = HAND_PARTYTAB;
			}
			if(!holding) ShowBoxedMon(0);
			if(Trg & A_BUTTON)
			{
				BoxShowMessage(strBoxWhatToDo,0);
				int c = BoxMultipleChoice(17,6,13, 13,1); //Choice_Box);
				BoxRemoveMessage();
				if(c == 0)
				{
					BoxShowMessage(strBoxJump,0);
					int i = BoxDoJump(boxno);
					BoxRemoveMessage();
					if(i != -1)
					{
						boxno = i;
						DrawBox(i);
					}
				} else if(c == 1)
				{
					BoxShowMessage(strBoxPickTheme,0);
					int i = BoxMultipleChoice(17,8,13, 14,1); //Choice_Wallpaper);
					BoxShowMessage(strBoxPickWallpaper,0);
					int j = BoxMultipleChoice(17,6+(i==2?2:0),13, 15+i,1); ////Choice_Wallpapers[i]);
					BoxRemoveMessage();
					boxwalls[boxno] = (i * 4) + j;
					DrawBox(boxno);
				} else if(c == 2)
				{
					BoxDoName(boxno);
				}
			}
			OamBak[0].HPos = BOX_HAND_CAPTION_X;
			OamBak[0].VPos = BOX_HAND_CAPTION_Y;
			OamBak[0].VFlip = 0;

		//---------------------------------------------------//

		} else if(handelement == HAND_PARTYTAB)
		{
			if(Trg & KEY_DOWN)
			{
				handelement = HAND_CAPTION;
			} else if(Trg & KEY_UP)
			{
				handelement = HAND_GRID;
				handy = 4;
			} else if((Trg & KEY_RIGHT) || (Trg & KEY_LEFT))
			{
				handelement = HAND_CLOSE;
			}
			if(!holding) ShowBoxedMon(0);
			if(Trg & A_BUTTON)
			{
				for(i = 3; i < 23; i++)
				{
					DoVBlank();
					DrawPartyTab(i);
					DoVBlank();
				}
				handy = 0;
				handelement = HAND_PARTY;
				if(!holding) ShowBoxedMon((aBoxedMon*)&MyParty[handy]);
			}
			OamBak[0].HPos = BOX_HAND_PARTYTAB_X;
			if(holding)
			{
				OamBak[0].VPos = BOX_HAND_PARTYTAB_Y;
			} else
			{
				OamBak[0].VPos = BOX_HAND_PARTYTAB_Y2;
				OamBak[0].VFlip = 1;
			}

		//---------------------------------------------------//

		} else if(handelement == HAND_CLOSE)
		{
			if(Trg & KEY_DOWN)
			{
				handelement = HAND_CAPTION;
			} else if(Trg & KEY_UP)
			{
				handelement = HAND_GRID;
				handy = 4;
			} else if((Trg & KEY_RIGHT) || (Trg & KEY_LEFT))
			{
				handelement = HAND_PARTYTAB;
			}
			if(!holding) ShowBoxedMon(0);
			if(Trg & A_BUTTON)
			{
				Trg = B_BUTTON;
			}
			OamBak[0].HPos = BOX_HAND_CLOSE_X;
			if(holding)
			{
				OamBak[0].VPos = BOX_HAND_PARTYTAB_Y;
			} else
			{
				OamBak[0].VPos = BOX_HAND_PARTYTAB_Y2;
				OamBak[0].VFlip = 1;
			}

		//---------------------------------------------------//

		} else if(handelement == HAND_PARTY)
		{
			if((Trg & KEY_UP) || (Trg & KEY_DOWN))
			{
				handy = wrap(handy + key_tri_vert(), 0, 7);
			}
			if(!holding)
			{
				if(handy == 6)
					ShowBoxedMon(0);
				else
					ShowBoxedMon((aBoxedMon*)&MyParty[handy]);
			}
			if(Trg & B_BUTTON)
			{
				handy = 6;
				Trg = A_BUTTON;
			}
			if(Trg & A_BUTTON)
			{
				if(handy == 6)
				{
					for(i = 22; i > 1; i--)
					{
						DoVBlank();
						DrawPartyTab(i);
					}
					handy = 0;
					handx = 0;
					handelement = HAND_GRID;
					if(!holding) ShowBoxedMon(&MyBox[handx + (handy*6) + (boxno*30)]);
				} else
				{
					if(!holding)
					{
						char foo[64];
						sprintf(foo,strBoxFooIsSelected,MyParty[handy].Personal.Nickname);
						BoxShowMessage(foo,0);
						int c = BoxMultipleChoice(17,2,13, 10,1); //Choice_Box4);
						BoxRemoveMessage();
						if(c==0)
						{
							int ps = GetPartySize(MyParty);
							if(ps==1)
							{
								BoxShowMessage(strBoxThatsYourLast,1);
							} else
							{
								holding = GetMonsterStats(&MyParty[handy], pSpecies);
								DmaCopy(&MyParty[handy], &InMyHand, sizeof(aBoxedMon));
								DmaClear(0, &MyParty[handy], sizeof(aPokemon));
								DmaCopy(PartyPics[holding], MEM_VRAM_OBJ + 0x5800, 512);
								OamBak[1].Pltt = 1 + MonIconColors[holding];
								OamBak[2+handy].CharNo = 720;
								if(handy < 5)
								{
									DmaCopy(&MyParty[handy+1],&MyParty[handy],sizeof(aPokemon) * (5-handy));
									DmaClear(0,&MyParty[5],sizeof(aPokemon));
									OamBak[7].CharNo = 720;
								}
								PreparePartyTab();
							}
						} else if(c==1)
						{
							BoxShowStatus((aPokemon*)&MyParty[handy],1,boxno);
						} else if(c==2)
						{
							int ps = GetPartySize(MyParty);
							if(ps==1)
							{
								BoxShowMessage(strBoxThatsYourLast,1);
							} else
							{
								int bno = BoxDoJump(0);
								if(bno != -1)
								{
									if(BoxGetAmount(bno) < 30)
									{
										DmaCopy(&MyParty[handy],BoxGetFirstFreeSpot(bno), sizeof(aBoxedMon));
										DmaClear(0,&MyParty[handy],sizeof(aPokemon));
										OamBak[2+handy].CharNo = 720;
										if(handy < 5)
										{
											DmaCopy(&MyParty[handy+1],&MyParty[handy],sizeof(aPokemon) * (5-handy));
											DmaClear(0,&MyParty[5],sizeof(aPokemon));
											OamBak[7].CharNo = 720;
										}
										PreparePartyTab();
										DrawBox(boxno);
									} else
									{
										BoxShowMessage(strBoxIsFull,1);
									}
								}
							}
						}
					} else
					{
						if(MyParty[handy].Personal.Personal == 0)
						{
							char foo[64];
							sprintf(foo,strBoxFooIsSelected,InMyHand.Personal.Nickname);
							BoxShowMessage(foo,0);
							int c = BoxMultipleChoice(17,2,13, 11,1); //Choice_Box5);
							BoxRemoveMessage();
							if(c==0)
							{
								if(MyParty[handy].Personal.Personal == 0)
								{
									handy = GetPartySize(MyParty);
								}
								DmaClear(0,&MyParty[handy],sizeof(aPokemon));
								DmaCopy(&InMyHand, &MyParty[handy], sizeof(aBoxedMon));
								DmaClear(0, &InMyHand, sizeof(aBoxedMon));
								UpdateLiveStats(&MyParty[handy]);
								MyParty[handy].Status.CurrentHP = MyParty[handy].Status.TotalHP;
								holding = 0;
								PreparePartyTab();
							} else if(c==1)
							{
								BoxShowStatus((aPokemon*)&InMyHand,1,boxno);
							} else if(c==2)
							{
								int bno = BoxDoJump(0);
								if(bno != -1)
								{
									if(BoxGetAmount(bno) < 30)
									{
										DmaCopy(&InMyHand,BoxGetFirstFreeSpot(bno), sizeof(aBoxedMon));
										holding = 0;
										DrawBox(boxno);
									} else
									{
										BoxShowMessage(strBoxIsFull,1);
									}
								}
							}
						} else
						{
							int c = BoxMultipleChoice(17,2,13, 12,1); //Choice_Box6);
							if(c==0)
							{
								aBoxedMon switcher;
								DmaCopy(&InMyHand, &switcher, sizeof(aPokemon));
								DmaCopy(&MyParty[handy], &InMyHand, sizeof(aPokemon));
								DmaCopy(&switcher, &MyParty[handy], sizeof(aPokemon));
								holding = GetMonsterStats(&InMyHand, pSpecies);
								DmaCopy(PartyPics[holding], MEM_VRAM_OBJ + 0x5800, 512);
								OamBak[1].Pltt = 1 + MonIconColors[holding];
								PreparePartyTab();
								AGBPrintf("Switched held \"%s\" with partymon \"%s\".\n", &MyParty[handy], InMyHand.Personal.Nickname);
							} else if(c==1)
							{
								BoxShowStatus((aPokemon*)&InMyHand,0,boxno);
							} else if(c==2)
							{
								int bno = BoxDoJump(0);
								if(bno != -1)
								{
									if(BoxGetAmount(bno) < 30)
									{
										DmaCopy(&InMyHand,BoxGetFirstFreeSpot(bno), sizeof(aBoxedMon));
										holding = 0;
										DrawBox(boxno);
									} else
									{
										BoxShowMessage(strBoxIsFull,1);
									}
								}
							}
						}
					}
				}
			}
			OamBak[0].VFlip = 0;
			if(handy == 0)
			{
				OamBak[0].HPos = BOX_PARTYMON_FIRST_X;
				OamBak[0].VPos = BOX_PARTYMON_FIRST_Y - BOX_HAND_HEIGHT;
			} else if(handy == 6)
			{
				OamBak[0].HPos = BOX_PARTYMON_OTHERS_X;
				OamBak[0].VPos = BOX_HAND_CANCEL_Y;
			} else
			{
				OamBak[0].HPos = BOX_PARTYMON_OTHERS_X;
				OamBak[0].VPos = -BOX_PARTYMON_INCREMENT - (BOX_PARTYMON_INCREMENT/2) + (handy * BOX_PARTYMON_INCREMENT);
			}
		}

		//---------------------------------------------------//

		if(holding)
		{
			OamBak[0].CharNo = 688;
			OamBak[1].HPos = OamBak[0].HPos;
			OamBak[1].VPos = OamBak[0].VPos+BOX_GRABBEDMON_INCREMENT;
		} else
		{
			handanim++;
			OamBak[0].CharNo = 640 + (16 * ((handanim >> 6) % 2));
			OamBak[1].HPos = 240;
		}

		if(Trg & B_BUTTON)
		{
			if(holding)
			{
				BoxShowMessage(strBoxYourHoldingOne,1);
			} else
			{
				BoxShowMessage(strBoxContinueBoxOps,0);
				int c = BoxMultipleChoice(17,10,13, 0,1); //Choice_YesNo);
				BoxRemoveMessage();
				if(c==1) break;
			}
		}

		bgscroll++;
		REG_BG3HOFS = bgscroll >> 2;
		REG_BG3VOFS = -bgscroll >> 2;
	}

	FadeOut();
	REG_DISPCNT = 0;
	ClearOamBak();
	CleanUpCrap();
	ClearSpriteGFX();
	ResetBackgrounds();
	FadeIn();
}

