/**	\file partyscreen.c
		\brief Party screen and lower.
		\author Kawa
*/
#include "openpoke.h"

extern const unsigned short partyboxesPal[48];
extern unsigned short partyboxesTiles[1024];
extern const unsigned short partyballsPal[16];
extern const unsigned short partyballsTiles[640];

extern const unsigned long XPRequirements[808];
extern const char Abilities[][14];
extern const char * const AbilityDescriptions[];

extern const unsigned short helditemPal[16];
extern const unsigned short helditemTiles[16];

const unsigned short PartyPal[64]=
{
	0x426C,0x3A10,0x5EF7,0x7FFF,0x2297,0x17DE,0x219A,0x165E,
	0x7DF1,0x652C,0x4DDD,0x52DF,0x7F14,0x4EAD,0x2D8C,0x2108,
	0x426C,0x39CE,0x5EF7,0x7FFF,0x266F,0x2733,0x27D2,0x4DDD,
	0x7A5E,0x2E97,0x179E,0x57DE,0x375A,0x153C,0x2D8C,0x2108,
	0x426C,0x3DEF,0x5AF7,0x7FFF,0x65CE,0x7AB4,0x2E16,0x471D,
	0x16B8,0x17DE,0x299E,0x65F2,0x6698,0x4CB7,0x2D8C,0x2108,
};

extern const unsigned short selectmoveTiles[512];

/** \brief Edit of MakeHPBar to work with the party screen. */
void MakePartyHPBar(u32 value, u32 max, u32 start, u32 target)
{
	if(value > max) value = max;
	u32 percent = value * 48 / max;
	u32 fullparts = percent / 8;
	u32 subparts = percent % 8;
	u32 i;

	DmaCopy(partyboxesTiles + 0x200 + 128 + 16 + (start*16), target, 64);
	DmaCopy(partyboxesTiles + 0x200 + 128 + 16 + 32 + (start*16), target + 256, 32);

	for(i=0; i<6; i++)
		DmaCopy(partyboxesTiles + 0x200 + (start*16), target + 64 + (i*32), 32);

	if(fullparts)
		for(i=0; i<fullparts; i++)
			DmaCopy(partyboxesTiles + 0x200 + 128 + (start*16), target + 64 + (i*32), 32);

	if(subparts)
		DmaCopy(partyboxesTiles + 0x200 + (subparts*16) + (start*16), target + 64 + (fullparts*32), 32);
}

/** \brief Handles the flip animation on the status screen. */
void FlipCards(int what)
{
	int flipanim = 0;
	if(what == 0)
	{
		for(flipanim = 8; flipanim > -256 + STATUS_CARDFLIPSPEED; flipanim -= STATUS_CARDFLIPSPEED)
		{
			REG_BG2HOFS = flipanim;
			DoVBlank();
		}
		for(flipanim = -256 + STATUS_CARDFLIPSPEED; flipanim < 16; flipanim += STATUS_CARDFLIPSPEED)
		{
			REG_BG1HOFS = flipanim;
			DoVBlank();
		}
		REG_BG1HOFS = 8;
		REG_BG2HOFS = -256;
	} else
	{
		for(flipanim = 8; flipanim > -256 + STATUS_CARDFLIPSPEED; flipanim -= STATUS_CARDFLIPSPEED)
		{
			REG_BG1HOFS = flipanim;
			DoVBlank();
		}
		for(flipanim = -256 + STATUS_CARDFLIPSPEED; flipanim < 16; flipanim += STATUS_CARDFLIPSPEED)
		{
			REG_BG2HOFS = flipanim;
			DoVBlank();
		}
		REG_BG1HOFS = -256;
		REG_BG2HOFS = 8;
	}
}

void StatusSetLine(int x, int w, int y, unsigned short start, unsigned char pal)
{
	u16 *BG0 = ((u16*)0x6007000);
	int b= 0;
	u16 tpal = pal<<12;
	for(b=x; b<x+w; b++)
	{
		BG0[(y*32)+b] = start + tpal;
		BG0[(y*32)+b+32] = start + 32 + tpal;
		start++;
	}
}

extern const unsigned short ball4Pal[16], ball4Tiles[192];
extern const unsigned short ball2Pal[16], ball2Tiles[192];
extern const unsigned short ball3Pal[16], ball3Tiles[192];
extern const unsigned short ball1Pal[16], ball1Tiles[192];
extern const unsigned short ball5Pal[16], ball5Tiles[192];
extern const unsigned short ball6Pal[16], ball6Tiles[192];
extern const unsigned short ball7Pal[16], ball7Tiles[192];
extern const unsigned short ball8Pal[16], ball8Tiles[192];
extern const unsigned short ball9Pal[16], ball9Tiles[192];
extern const unsigned short ball10Pal[16], ball10Tiles[192];
extern const unsigned short ball11Pal[16], ball11Tiles[192];
extern const unsigned short ball12Pal[16], ball12Tiles[192];
const unsigned short * pokeballs[] =
{
	0,0,
	ball1Pal, ball1Tiles,
	ball2Pal, ball2Tiles,
	0,0,
	ball4Pal, ball4Tiles,
	ball5Pal, ball5Tiles,
	ball6Pal, ball6Tiles,
	ball7Pal, ball7Tiles,
	ball8Pal, ball8Tiles,
	ball9Pal, ball9Tiles,
	ball10Pal, ball10Tiles,
	ball11Pal, ball11Tiles,
	ball12Pal, ball12Tiles,
};

extern void PokeDex_LoadType(u8 type, u8 slot);

/** \brief Writes the required status text and other graphics. */
void StatusText(aPokemon * currPkmn, u32 page, u32 oldpage)
{
	char buff[256];
	int i;
	int isEgg = GetMonsterStats(currPkmn, pEgg);

	int lvl = GetMonsterStats(currPkmn, pLevel);
	int species = GetMonsterStats(currPkmn, pSpecies);

	CpuFastClear(0, vwDestination,0x4000);
	CpuFastClear(0, MEM_VRAM + 0x7000,2000);
	vwWhiteTransparentLUT();
	vwWrite(12,0,strStatusHeaders[(page==10 ? oldpage : (page==4) ? 0 : page)]);
	if(!isEgg)
	{
		sprintf(buff,"\x80\x1C%d", lvl);
		vwWrite(4,18, buff);
		vwWrite(40,18, PokeNames[species]);
		StatusSetLine(0,12,0,1,15);
		StatusSetLine(0,12,2,64,15);
	}
	OamBak[10].VPos = 160;
	OamBak[11].VPos = 160;
	OamBak[11].VPos = 160;
	OamBak[12].VPos = 160;
	OamBak[13].VPos = 160;

	vwBlackTransparentLUT();
	if(page==0)
	{
		sprintf(buff,"%d", GetDexNumber(species));
		vwWrite(112,6, buff);
		if(currPkmn->Personal.Font == 1) vw_SetJapanese();
		vwWrite(112,21, currPkmn->Personal.Nickname);
		vwWrite(112,39, currPkmn->Personal.OTName);
		if(currPkmn->Personal.Font == 1) vw_SetBig();
		sprintf(buff,"%d", (u16)GetMonsterStats(currPkmn, pOTID));
		vwWrite(112,54, buff);
		int hi = GetMonsterStats(currPkmn, pHeldItem);
		if(hi)
			vwWrite(0,40, items[hi].name);
		else
			vwWrite(0,40, "None");
		sprintf(buff, strStatusNature, natures[GetMonsterStats(currPkmn, pPersonal) % 25]);
		vwWrite(4,81, buff);

		int otid = GetMonsterStats(currPkmn, pOTID);
		int loc = GetMonsterStats(currPkmn, pLocationMet);
		int lvlmet = GetMonsterStats(currPkmn, pLevelMet);
		if(otid != MyPlayer.trainerid || loc == 0xFE) //would also check location bounds
			sprintf(buff,strStatusMetInATrade);
		else if(loc == 0xFF)
			sprintf(buff,strStatusFatedAt, lvlmet);
		else if(lvlmet == 0)
			sprintf(buff,strStatusHatchedAt, MapNames[loc]);
		else
			sprintf(buff,strStatusMetAt, MapNames[loc], lvlmet);
		//sprintf(buff, "From %s.", locs[loc]);
		vwWrite(4,95, buff);

		//Characteristic
		extern CSTRING Characteristics[];
		int highestStat = 0, highestStatVal = 0;
		for(i = 0; i < 6; i++)
		{
			if(GetMonsterStats(currPkmn, i + pDVHP) > highestStatVal)
			{
				highestStat = i;
				highestStatVal = GetMonsterStats(currPkmn, i + pDVHP);
			}
		}
		vwWrite(4, 109, Characteristics[(highestStat * 5) +  (highestStatVal % 5)]);

		OamBak[10].HPos = 221;
		OamBak[10].VPos = 21;
		OamBak[10].CharNo = 132;
		OamBak[10].Size=1;
		OamBak[10].Pltt = 5;
		OamBak[11].HPos = 206;
		OamBak[11].VPos = 21;
		OamBak[11].CharNo = 136;
		OamBak[11].Size = 1;
		OamBak[11].Pltt = 6;
		PokeDex_LoadType(BaseStats[species].Type1, 1);
		if(BaseStats[species].Type1 != BaseStats[species].Type2)
			PokeDex_LoadType(BaseStats[species].Type2, 2);
		else
			PokeDex_LoadType(tpNormal, 2);

		StatusSetLine(21,4,2,14,15);
		StatusSetLine(21,8,4,78,15);
		StatusSetLine(21,8,6,142,15);
		StatusSetLine(21,8,8,206,15);
		StatusSetLine(21,8,9,238,15);
		StatusSetLine(21,8,11,160,15);
		StatusSetLine(1,30,14,320,15);
		StatusSetLine(1,30,16,384,15);
		StatusSetLine(1,30,18,448,15);
	} else if(page==1)
	{
		sprintf(buff,"%3d/%3d", currPkmn->Status.CurrentHP, currPkmn->Status.TotalHP);
		vwWrite(128,5,buff);
		sprintf(buff,"%d", currPkmn->Status.Attack);
		vwWrite(144,19,buff);
		sprintf(buff,"%d", currPkmn->Status.Defense);
		vwWrite(144,33,buff);
		sprintf(buff,"%d", currPkmn->Status.Speed);
		vwWrite(144,47,buff);
		sprintf(buff,"%d", currPkmn->Status.SpAttack);
		vwWrite(144,61,buff);
		sprintf(buff,"%d", currPkmn->Status.SpDefense);
		vwWrite(144,75,buff);
		sprintf(buff,strStatusExpToNext, XPRequirements[(BaseStats[species].LevelSlope * 101) + lvl + 1] - GetMonsterStats(currPkmn,pExperience));
		vwWrite(0,42,buff);

		//Abilities were switched.
		if(currPkmn->Personal.Personal % 2)	i = BaseStats[species].Ability2;
		else															i = BaseStats[species].Ability1;
		if(i==0)													i = BaseStats[species].Ability1;

		vwWrite(0,88, Abilities[i]);
		vw_SetSmall();
		vwWrite(0,101, AbilityDescriptions[i]);
		vw_SetBig();
		StatusSetLine(24,6,3,48,15);
		StatusSetLine(26,3,5,114,15);
		StatusSetLine(26,3,7,178,15);
		StatusSetLine(26,3,9,242,15);
		StatusSetLine(26,3,11,306,15);
		StatusSetLine(9,18,13,160,15);
		StatusSetLine(9,18,16,352,15);
		StatusSetLine(1,18,18,416,15);
	} else if(page==2)
	{
		for(i=0; i<4; i++)
		{
			sprintf(buff,"-");
			int atk = GetMonsterStats(currPkmn, pMove1 + i);
			if(atk)
				sprintf(buff,"%s", moveNames[atk]);
			vwWrite(128,5+(i*27), buff);
		}
		vw_SetSmall();
		for(i=0; i<4; i++)
		{
			if(GetMonsterStats(currPkmn, pMove1 + i))
			{
				sprintf(buff,"%d/%d", GetMonsterStats(currPkmn, pPP1 + i), GetPPForMove(currPkmn, i)); //moves[myA->Attack[i]].pp);
				vwWrite(128,17+(i*27), buff);
			} else break;
		}
		vw_SetBig();
		for(i=0; i<4; i++)
		{
			int atk = GetMonsterStats(currPkmn, pMove1 + i);
			if(moves[atk].type)
			{
				PokeDex_LoadType(moves[atk].type, i+1);
				OamBak[10+i].HPos = 216;
				OamBak[10+i].VPos = 24 + (i*28);
				OamBak[10+i].CharNo = 132 + (i*4);
				OamBak[10+i].Size=1;
				OamBak[10+i].Pltt = 5 + i;
			}
		}
		StatusSetLine(16,16,2,16,15);
		StatusSetLine(16,16,4,80,15);
		StatusSetLine(16,16,6,144,15);
		StatusSetLine(16,16,8,208,15);
		StatusSetLine(16,16,10,272,15);
		StatusSetLine(16,16,12,336,15);
		StatusSetLine(16,16,14,400,15);
	} else if(page == 4)
	{
		//TODO	Egg status
		int t = GetMonsterStats(currPkmn, pTameness);
		if(t <= 5)
			i = 3;
		else if(t <= 10)
			i = 2;
		else if(t <= 40)
			i = 1;
		else
			i = 0;
		vwWrite(0,17,strStatusHatchTimes[i]);
		StatusSetLine(16,16,4,64,15);
		StatusSetLine(16,16,6,128,15);
		StatusSetLine(16,16,8,192,15);
	}
}

extern const unsigned short pokestatus_Pal[16];
extern const unsigned short pokestatus_Tiles[4752];
extern const unsigned short pokestatus_Map[9216];
extern const unsigned short markingsPal[16];
extern const unsigned short markingsTiles[128];

/** \brief Displays the status for the specified monster. */
void ShowStatus(aPokemon * currPkmn)
{
	int page = 0, oldpage = 0, species = 0;
	TVwf *vwf= gp_vwf;

	REG_DISPCNT = 0;

	vwf->dstD = (u32*)0x06000000;
	vwDestination = (u32*)0x06000000;

	REG_BG0CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(0) | 14 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT;
	REG_BG1CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(2) | 12 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG2CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(1) | 10 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG3CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(2) | 9 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	REG_BG1HOFS = -256;
	REG_BG1VOFS = 0;
	REG_BG2HOFS = 8;
	REG_BG2VOFS = 0;
	REG_BG3HOFS = 8;
	REG_BG3VOFS = 0;

	DmaArrayCopy(pokestatus_Pal, MEM_PAL_BG);
	DmaArrayCopy(pokestatus_Tiles, MEM_VRAM + 0x8000);
	DmaCopy(pokestatus_Map, MEM_VRAM + 0x4800, 10240);
	ClearOamBak();

	DmaArrayCopy(markingsPal, MEM_PAL_OBJ + 0x20);
	DmaCopy(markingsTiles, MEM_VRAM_OBJ + 0x1000, 128);
	if(currPkmn->Personal.Marking & 1)
		DmaCopy(markingsTiles+64,  MEM_VRAM_OBJ + 0x1000,    32);
	if(currPkmn->Personal.Marking & 2)
		DmaCopy(markingsTiles+80,  MEM_VRAM_OBJ + 0x1000+32, 32);
	if(currPkmn->Personal.Marking & 4)
		DmaCopy(markingsTiles+96, MEM_VRAM_OBJ + 0x1000+64, 32);
	if(currPkmn->Personal.Marking & 8)
		DmaCopy(markingsTiles+112, MEM_VRAM_OBJ + 0x1000+96, 32);

	species = GetMonsterStats(currPkmn, pPokeBall);
	DmaCopy(pokeballs[(species << 1) + 1], MEM_VRAM_OBJ + 0x1400, 0x180);
	DmaCopy(pokeballs[species << 1], MEM_PAL_OBJ + 0x40, 32);
	OamBak[2].HPos = 98;
	OamBak[2].VPos = 78;
	OamBak[2].CharNo = 160;
	OamBak[2].Pltt = 2;
	OamBak[2].Shape = 0;
	OamBak[2].Size = 1;

	species = GetMonsterStats(currPkmn, pSpecies);

	
	if(GetMonsterStats(currPkmn, pEgg))
	{
		LoadPokemonPic(pkEgg, 0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
		DmaCopy(pokestatus_Map + 7168, MEM_VRAM + 0x5000, 2048);
		DmaClear(0, MEM_VRAM_OBJ + 0x1000, 0x80);
		page = 4;
		oldpage = 4;
	} else
	{
		LoadPokemonPic(species, (LPP_SHINY*IsShiny(currPkmn)),MEM_VRAM_OBJ,pal_obj_bank[0],currPkmn->Personal.Personal);
	}

	SetupPokemonSprite(0);
	OamBak[0].HPos = 28;
	OamBak[0].VPos = 32;
	OamBak[0].HFlip = 1;
	OamBak[1].HPos = 8;
	OamBak[1].VPos = 86;
	OamBak[1].CharNo = 128;
	OamBak[1].Pltt = 1;
	OamBak[1].Shape = 1;
	OamBak[1].Size = 1;

#ifdef pkUNOWN
	if(species == pkUNOWN) OamBak[0].HFlip = 0; //unown are always shown unflipped d^.^b
#endif

	CpuFastClear(0, vwDestination,0x2000);
	StatusText(currPkmn, page, oldpage);

	ResetDispCnt();
	FadeIn();

	sndPlayCry(species, 60);

	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & START_BUTTON)
			WriteCompleteDocs(currPkmn);
		if(Trg & B_BUTTON)
		{
			break;
		}
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			__asm__(".space 8\n.align 2 , 0");
			//currPkmn = clamp(currPkmn + key_tri_vert(), 0, 
			GetPartySize(MyParty[0]) ;//);
			__asm__(".space 8");
			continue;
		}
		if((Trg & L_KEY) || (Trg & R_KEY))
		{
			if(page == 4) continue;
			page = clamp(page + key_tri_horz(), 0, 3);
			if(oldpage != page)
			{
				StatusText(currPkmn, 10, oldpage);
				if(page == 0) //Info
				{
					REG_BG1CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(2) | 12 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
					REG_BG2CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(1) | 10 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
					FlipCards(1);
				}
				else if(page == 1) //Skills
				{
					FlipCards(0);
					REG_BG1CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(1) | 12 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
					REG_BG2CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(2) | 10 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
					DmaCopy(pokestatus_Map + 1024, MEM_VRAM + 0x5000, 2048);
				}
				else if(page == 2) //Moves
				{
					REG_BG1CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(2) | 12 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
					REG_BG2CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(1) | 10 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
					DmaCopy(pokestatus_Map + 5120, MEM_VRAM + 0x5000, 2048);
					FlipCards(1);
				}
				StatusText(currPkmn, page, oldpage);
				oldpage = page;
			}
		}
	}
	FadeOut();
	ClearOamBak();
	ResetBackgrounds();
	vwToBG();
	vwf_init_dflt();
	Trg = 0;
}

extern const unsigned short genericbackPal[16];
extern const unsigned short genericbackTiles[160];
extern const unsigned short genericbackMap[640];
extern const u8 MonIconColors[254];
extern const unsigned short * const PartyPics[];
//extern const unsigned short PartyPal[56];

void CopyPartyBoxPal(int pos, int state)
{
	int i;
	for(i=0;i<9;i++)
	{
		BGPAL[((pos+3)*16)+i] = partyboxesPal[i+(state*16)];
	}
}

/** \brief Draws the party screen for a given purpose, with highlight */
void DrawPartyScreen(int sel, int purpose, int additional)
{
	int ps = GetPartySize(MyParty);
	int i = 0, j = 0, k = 0, l = 0, m = 0, gender = 0;
	unsigned short * tP;
	char buff[16];
	TVwf *vwf= gp_vwf;
	u32 *oldd = vwf->dstD;
	u32 *oldv = (u32*)vwf->putc_;
	u32 oldp = vwf->dstP;
	const unsigned short gendercolors[] = { 0x4A7F, 0x1D13, 0x7F28, 0x4980 };

	vwf->putc_ = (fn_putc)vwf_putc8x16T;

	if(!((additional) && (purpose == psmSelectOnly)))
	{
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;
		REG_BG1HOFS = 0;
		REG_BG1VOFS = 0;
		REG_BG2HOFS = 8;
		REG_BG2VOFS = 0;
		REG_BG3HOFS = 0;
		REG_BG3VOFS = 0;
		REG_BLDCNT = 0;
		REG_BG1CNT |= BG_PRIO(1);

		ClearOamBak();
		vwClear(0);
		CpuFastClear(0, MEM_VRAM + 0xE800,2000);
		CpuFastClear(0, MEM_VRAM + 0xF800,2000);

		DmaArrayCopy(partyboxesTiles, MEM_VRAM + 0x0400);
		DmaArrayCopy(genericbackPal, MEM_PAL_BG);
		DmaArrayCopy(genericbackTiles, MEM_VRAM + 0x5000);
		for(i=0;i<640;i++) BG2MAP[i] = genericbackMap[i]+640;
		DmaCopy(PartyPal, MEM_PAL_OBJ, 96);

		DmaArrayCopy(partyballsPal, MEM_PAL_OBJ + 0x60);
		DmaArrayCopy(partyballsTiles, MEM_VRAM_OBJ + 0x2040);

		DmaArrayCopy(helditemPal, MEM_PAL_OBJ + 0x80);
		DmaArrayCopy(helditemTiles, MEM_VRAM_OBJ + 0x2800);
	}

	//Draw leader box
	DmaCopy(partyboxesTiles + (16*18), MEM_VRAM + 0x0c60,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*19), MEM_VRAM + 0x0c80 + (32*i),32);
	DmaCopy(partyboxesTiles + (16*20), MEM_VRAM + 0x0d80,32);
	DmaCopy(partyboxesTiles + (16*21), MEM_VRAM + 0x0da0,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*13), MEM_VRAM + 0x0dc0 + (32*i),32);
	DmaCopy(partyboxesTiles + (16*22), MEM_VRAM + 0x0ec0,32);
	DmaCopy(partyboxesTiles + (16*21), MEM_VRAM + 0x0da0,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*13), MEM_VRAM + 0x0dc0 + (23*i),32);
	DmaCopy(partyboxesTiles + (16*22), MEM_VRAM + 0x0ec0,32);
	DmaCopy(partyboxesTiles + (16*21), MEM_VRAM + 0x0ee0,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*13), MEM_VRAM + 0x0f00 + (32*i),32);
	DmaCopy(partyboxesTiles + (16*22), MEM_VRAM + 0x1000,32);
	DmaCopy(partyboxesTiles + (16*21), MEM_VRAM + 0x1020,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*13), MEM_VRAM + 0x1040 + (32*i),32);
	DmaCopy(partyboxesTiles + (16*22), MEM_VRAM + 0x1140,32);
	DmaCopy(partyboxesTiles + (16*23), MEM_VRAM + 0x1160,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*24), MEM_VRAM + 0x1180 + (32*i),32);
	DmaCopy(partyboxesTiles + (16*25), MEM_VRAM + 0x1280,32);
	DmaCopy(partyboxesTiles + (16*26), MEM_VRAM + 0x12a0,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*27), MEM_VRAM + 0x12c0 + (32*i),32);
	DmaCopy(partyboxesTiles + (16*28), MEM_VRAM + 0x13c0,32);
	DmaCopy(partyboxesTiles + (16*29), MEM_VRAM + 0x13e0,32);
	for(i=0; i<8; i++)
		DmaCopy(partyboxesTiles + (16*30), MEM_VRAM + 0x1400 + (32*i),32);
	DmaCopy(partyboxesTiles + (16*31), MEM_VRAM + 0x1500,32);

	if(!((additional) && (purpose == psmSelectOnly)))
	{
		k=99; j = 0x61;
		for(l=0; l < 7; l++)
		{
			for(i=0; i<10; i++)	BG1MAP[j++] = 0x3000 + (k++);
			j+=0x16;
		}

		j = 0x2c; m = 3;
		for(l=0; l < 15; l++)
		{
			if(l % 3 == 0) m++;
			for(i=0; i<18; i++)	BG1MAP[j++] = (m*0x1000) + (k++);
			j+=0xe;
		}
	}

	//Draw empty boxes
	k = 9;
	for(j = 0; j < 5; j++)
	{
		AGBPrintf("DrawPartyScreen: j %d\n",j);
		if(j==ps-1)
			k = 0;
		DmaCopy(partyboxesTiles + (16*(k+0)), MEM_VRAM + 0x1520 + (j*0x6c0),32);
		for(i=0; i<16; i++)
			DmaCopy(partyboxesTiles + (16*(k+1)), MEM_VRAM + 0x1540 + (32*i) + (j*0x6c0),32);
		DmaCopy(partyboxesTiles + (16*(k+2)), MEM_VRAM + 0x1740 + (j*0x6c0),32);
		DmaCopy(partyboxesTiles + (16*(k+3)), MEM_VRAM + 0x1760 + (j*0x6c0),32);
		for(i=0; i<16; i++)
			DmaCopy(partyboxesTiles + (16*(k+4)), MEM_VRAM + 0x1780 + (32*i) + (j*0x6c0),32);
		DmaCopy(partyboxesTiles + (16*(k+5)), MEM_VRAM + 0x1980 + (j*0x6c0),32);
		DmaCopy(partyboxesTiles + (16*(k+6)), MEM_VRAM + 0x19a0 + (j*0x6c0),32);
		for(i=0; i<16; i++)
			DmaCopy(partyboxesTiles + (16*(k+7)), MEM_VRAM + 0x19c0 + (32*i) + (j*0x6c0),32);
		DmaCopy(partyboxesTiles + (16*(k+8)), MEM_VRAM + 0x1bc0 + (j*0x6c0),32);
	}

	vwf_set_color(TEXT_INK, 3);
	vwf_set_color(TEXT_SHADOW, 2);
	vw_SetSmall();

	int species = 0;

	for(j=0; j<6; j++)
	{
		DmaCopy(partyboxesPal, MEM_PAL_BG + 0x0060 + (j*32),32);

		if(j<ps)
		{
			species = GetMonsterStats(&MyParty[j], pSpecies);
			tP = (unsigned short *)PartyPics[species];
			gender = 0x00;
			if(BaseStats[species].Gender < 0xFF)
			{
				if((u8)MyParty[j].Personal.Personal > BaseStats[species].Gender)
				{
					gender = 0x8A;
					BGPAL[((j+3)*16)+11] = gendercolors[2];
					BGPAL[((j+3)*16)+12] = gendercolors[3];
				} else
				{
					gender = 0x8B;
					BGPAL[((j+3)*16)+11] = gendercolors[0];
					BGPAL[((j+3)*16)+12] = gendercolors[1];
				}
			}
			OamBak[j].CharNo = j * 32;
			OamBak[j].Pltt = MonIconColors[species];
			OamBak[j].Shape = 0;
			OamBak[j].Size = 2;
			OamBak[j].Priority = 1;
			OamBak[j+10].CharNo = 258;
			OamBak[j+10].Pltt = 3;
			OamBak[j+10].Shape = 0;
			OamBak[j+10].Size = 2;
			OamBak[j+10].Priority = 1;
			if(j == sel) OamBak[j+10].CharNo = 274;
			OamBak[j+20].CharNo = 320 + (GetMonsterStats(&MyParty[j], pHeldItem) == 0);
			OamBak[j+20].Shape = 0;
			OamBak[j+20].Size = 0;
			OamBak[j+20].Pltt = 4;
			OamBak[j+20].Priority = 0;

			if(GetMonsterStats(&MyParty[j], pEgg))
			{
				OamBak[j].Pltt = 1;
				tP = PartyPics[pkEgg];
			}
			else if(species == pkUnown)
			{
				int letter = GetUnownLetter(GetMonsterStats(&MyParty[j], pPersonal));
				if(letter)
					tP = PartyPics[pkUnown_B + letter - 1];
			}
			DmaCopy(tP, MEM_VRAM_OBJ + (j*0x400), 1024);
			if(j==0)
			{
				vwf->dstD = (u32*)0x06000E00;
				vwf->dstP = 10;
				if(!GetMonsterStats(&MyParty[j], pEgg))
				{
					vwWrite(0,4,MyParty[j].Personal.Nickname);
					sprintf(buff, "\xBB%d", MyParty[j].Status.Level);
					vwWrite(8,13,buff);
					if(purpose != psmTeachTM)
					{
						MakePartyHPBar(MyParty[j].Status.CurrentHP, MyParty[j].Status.TotalHP, 0, MEM_VRAM + 0x1180);
						sprintf(buff, "%3d/%3d", MyParty[j].Status.CurrentHP, MyParty[j].Status.TotalHP);
						vwWrite(14,29,buff);
					} else
					{
						vwWrite(8,29, CanLearnTM(species, additional) ? strStatusAble : strStatusNotAble);
					}
					vwf_set_color(TEXT_INK, 11);
					vwf_set_color(TEXT_SHADOW, 12);
					sprintf(buff,"%c",gender);
					vwWrite(40,13,buff);
					vwf_set_color(TEXT_INK, 3);
					vwf_set_color(TEXT_SHADOW, 2);
				}
				else
				{
					vwWrite(0,4,"Egg");
				}
				vwf->dstP = 18;
				OamBak[j].HPos = 0;
				OamBak[j].VPos = 20;
				OamBak[j+10].HPos = 0;
				OamBak[j+10].VPos = 18;
				OamBak[j+20].HPos = 16;
				OamBak[j+20].VPos = 46;
			}
			else
			{
				vwf->dstD = (u32*)0x06001560 + ((j-1)*0x1B0);
				if(!GetMonsterStats(&MyParty[j], pEgg))
				{
					vwWrite(6,4,MyParty[j].Personal.Nickname);
					sprintf(buff, "\xBB%d", MyParty[j].Status.Level);
					vwWrite(16,13,buff);
					if(purpose != psmTeachTM)
					{
						MakePartyHPBar(MyParty[j].Status.CurrentHP, MyParty[j].Status.TotalHP, 12, MEM_VRAM + 0x1880 + ((j-1)*0x6C0));
						sprintf(buff, "%3d/%3d", MyParty[j].Status.CurrentHP, MyParty[j].Status.TotalHP);
						vwWrite(86,13,buff);
					} else
					{
						vwWrite(86,13,CanLearnTM(species, additional) ? strStatusAble : strStatusNotAble);
					}
					vwf_set_color(TEXT_INK, 11);
					vwf_set_color(TEXT_SHADOW, 12);
					sprintf(buff,"%c",gender);
					vwWrite(48,13,buff);
					vwf_set_color(TEXT_INK, 3);
					vwf_set_color(TEXT_SHADOW, 2);
				}
				else
				{
					vwWrite(6,4, "Egg");
				}
				OamBak[j].HPos = 84;
				OamBak[j].VPos = 3 + ((j-1)*24);
				OamBak[j+10].HPos = 86;
				OamBak[j+10].VPos = 9 + ((j-1)*24);
				OamBak[j+20].HPos = 104;
				OamBak[j+20].VPos = 24 + ((j-1)*24);
			}
		}
	}
	vw_SetBig();
	vwNormalLUT();

	vwf->dstP = oldp;
	vwf->putc_ = (fn_putc)oldv;
	vwf->dstD = oldd;

	CopyPartyBoxPal(sel, 1);

	LoadFrame();
}

/** \brief Displays the party and lets the player
select a monster to use depending on purpose. */
int ShowParty(int purpose, int additional)
{
// Amount of Pokémon in player's party
	int partySize = 0;

	int i = 0;
	int sel = 0, bounce=0, btimer=0;

	partySize = GetPartySize(MyParty);

	AGBPrintf("ShowParty: partySize %d\n",partySize);

	REG_DISPCNT = 0;
	DrawPartyScreen(sel, purpose, additional);
	ResetDispCnt();
	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();
		if((Trg & L_KEY) || (Trg & R_KEY))
		{
			sndCursor();
			CopyPartyBoxPal(sel, 0);
			OamBak[sel+10].CharNo = 258;
			sel = wrap(sel + key_tri_horz(), 0, partySize);
			CopyPartyBoxPal(sel, 1);
			OamBak[sel+10].CharNo = 274;
		}
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			sndCursor();
			CopyPartyBoxPal(sel, 0);
			OamBak[sel+10].CharNo = 258;
			sel = wrap(sel + key_tri_vert(), 0, partySize);
			CopyPartyBoxPal(sel, 1);
			OamBak[sel+10].CharNo = 274;
		}
		if(Trg & A_BUTTON)
		{
			sndCursor();
			if(purpose == psmSelectOnly)
			{
				return sel;
			}
			else if(purpose == psmTeachTM)
			{
				if(!CanLearnTM(GetMonsterStats(&MyParty[sel], pSpecies), additional))
				{
					extern const unsigned short TMList[];
					sayf(SYSTEM,strPartyCantLearnTM, MyParty[sel].Personal.Nickname, moveNames[TMList[additional]], moveNames[TMList[additional]]);
					sel = -1;
				}
				return sel;
			}
			else if(purpose == psmBattleSwitch)
			{
				if(MyParty[sel].Status.CurrentHP)
				{
					break;
				}
			}
			else
			{
				i = MultipleChoice(18,10,12, 18,1); //ChoicePartyScreen);
				int j;
				switch(i)
				{
				case 0:		// Summary
					FadeOut();
					ShowStatus(&MyParty[sel]);
					REG_DISPCNT = 0;
					DrawPartyScreen(sel, purpose, additional);
					ResetDispCnt();
					FadeIn();
					break;
				case 1:		// Switch
					break;
				case 2:		// Item
					j = MultipleChoice(18,12,12, 19,1); //ChoicePartyItems);
					if(j == 0) //Give
					{
						FadeOut();
						j = HoldInventory();
						REG_DISPCNT = 0;
						DrawPartyScreen(sel, purpose, additional);
						ResetDispCnt();
						FadeIn();
						if(j==0) continue;
						int item = GetMonsterStats(&MyParty[sel], pHeldItem);
						if(item)
						{
							sayf(SYSTEM,strPartySwitchedItems, items[j].name, items[item].name);
							GiveItem(item);
							TakeItem(j);
							SetMonsterStats(&MyParty[sel], pHeldItem, j);
						} else
						{
							sayf(SYSTEM,strPartyGaveItem, &MyParty[sel].Personal.Nickname, items[j].name);
							TakeItem(j);
							SetMonsterStats(&MyParty[sel], pHeldItem, j);
						}
						DrawPartyScreen(sel, purpose, additional);
					} else if(j == 1) //Take
					{
						int item = GetMonsterStats(&MyParty[sel], pHeldItem);
						if(item)
						{
							GiveItem(item);
							sayf(SYSTEM,strPartyTookItem, items[item].name, &MyParty[sel].Personal.Nickname);
							SetMonsterStats(&MyParty[sel], pHeldItem, 0);
						} else
						{
							sayf(SYSTEM,strPartyNoItem, &MyParty[sel].Personal.Nickname);
						}
						DrawPartyScreen(sel, purpose, additional);
					}
					break;
				}
			}
		}
		if(Trg & B_BUTTON)
		{
			sel = -1;
			break;
		}

		btimer++;
		if(btimer == 10)
		{
			bounce ^= 1;
			for(i=0;i<partySize;i++)
			{
				OamBak[i].CharNo = (i*32) + (bounce*16);
			}
			btimer=0;
		}
	}
	FadeOut();
	vwClear(0);
	CleanUpCrap();
	ResetBackgrounds();
	vwNormalLUT();

	return sel;
}


/** \brief Edit of ShowStatus to pick a move to forget. */
int SelectLearnMove(aPokemon *target, int mid)
{
	TVwf *vwf= gp_vwf;
	char buff[50];

	int selectedMove = 0;

	REG_DISPCNT = 0;

	vwf->dstD = (u32*)0x06000000;
	vwDestination = (u32*)0x06000000;

	REG_BG0CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(0) | 14 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT;
	REG_BG1CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(2) | 12 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG2CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(1) | 10 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG3CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(2) | 9 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG0HOFS = 0;
	REG_BG1HOFS = -256;
	REG_BG2HOFS = 8;
	REG_BG3HOFS = 8;
	REG_BG0VOFS = 0;
	REG_BG1VOFS = 0;
	REG_BG2VOFS = 0;
	REG_BG3VOFS = 0;

	DmaArrayCopy(pokestatus_Pal, MEM_PAL_BG);
	DmaArrayCopy(pokestatus_Tiles, MEM_VRAM + 0x8000);
	DmaCopy(pokestatus_Map, MEM_VRAM + 0x4800, 10240);
	ClearOamBak();

	DmaArrayCopy(markingsPal, MEM_PAL_OBJ + 0x20);
	DmaCopy(markingsTiles, MEM_VRAM_OBJ + 0x1000, 128);
	if(target->Personal.Marking & 1) DmaCopy(markingsTiles+64,  MEM_VRAM_OBJ + 0x1000,    16);
	if(target->Personal.Marking & 2) DmaCopy(markingsTiles+80,  MEM_VRAM_OBJ + 0x1000+32, 16);
	if(target->Personal.Marking & 4) DmaCopy(markingsTiles+96,  MEM_VRAM_OBJ + 0x1000+64, 16);
	if(target->Personal.Marking & 8) DmaCopy(markingsTiles+112, MEM_VRAM_OBJ + 0x1000+96, 16);

	int species = GetMonsterStats(target, pPokeBall);
	DmaCopy(pokeballs[(species << 1) + 1], MEM_VRAM_OBJ + 0x1400, 0x180);
	DmaCopy(pokeballs[species << 1], MEM_PAL_OBJ + 0x40, 32);
	OamBak[2].HPos = 98;
	OamBak[2].VPos = 78;
	OamBak[2].CharNo = 160;
	OamBak[2].Pltt = 2;
	OamBak[2].Shape = 0;
	OamBak[2].Size = 1;

	species = GetMonsterStats(target, pSpecies);
	LoadPokemonPic(species,(LPP_SHINY*IsShiny(target)),MEM_VRAM_OBJ,pal_obj_bank[0],target->Personal.Personal);
	SetupPokemonSprite(0);
	OamBak[0].HPos = 28;
	OamBak[0].VPos = 32;
	OamBak[0].HFlip = 1;
	OamBak[1].HPos = 8;
	OamBak[1].VPos = 86;
	OamBak[1].CharNo = 128;
	OamBak[1].Pltt = 1;
	OamBak[1].Shape = 1;
	OamBak[1].Size = 1;

	CpuFastClear(0, vwDestination,0x2000);
	StatusText(target, 2, 2);
	if(mid > -1)
	{
		vwWrite(0,8+(3*27),moveNames[mid]);
		vw_SetSmall();
		sprintf(buff,"%d/%d",moves[mid].pp, moves[mid].pp);
		vwWrite(0,20+(3*27),buff);
		vw_SetBig();
		StatusSetLine(16,16,16,352,15);
		StatusSetLine(16,16,18,416,15);
	} else
	{
		vwWrite(0,8+(3*27),"Cancel");
		StatusSetLine(16,16,16,352,15);
	}

	DmaCopy(pokestatus_Map + 5120, MEM_VRAM + 0x5000, 4000);
	OamBak[8].CharNo = 256;
	OamBak[8].Shape = 1;
	OamBak[8].Size = 3;
	OamBak[8].HPos = 117;
	OamBak[8].VPos = 18;
	OamBak[8].HFlip = 0;
	OamBak[9].CharNo = 256;
	OamBak[9].Shape = 1;
	OamBak[9].Size = 3;
	OamBak[9].HPos = 117+64;
	OamBak[9].VPos = 18;
	OamBak[9].HFlip = 1;

	DmaArrayCopy(selectmoveTiles, MEM_VRAM_OBJ + 0x2000);

	ResetDispCnt();
	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & B_BUTTON)
		{
			selectedMove = 4;
			break;
		}
		if((Trg & KEY_UP) || (Trg & KEY_DOWN))
		{
			selectedMove = clamp(selectedMove + key_tri_vert(), 0, 5);
			OamBak[8].VPos = 18 + (selectedMove * 27);
			OamBak[9].VPos = 18 + (selectedMove * 27);
		}
		if(Trg & A_BUTTON)
		{
			break;
		}
	}
	FadeOut();
	CleanUpCrap();
	ClearOamBak();
	ResetBackgrounds();
	vwToBG();
	vwf_init_dflt();
	Trg = 0;
	return selectedMove;
}
