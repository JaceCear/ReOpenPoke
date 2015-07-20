//======================================================================
//
//	OpenPoké battle system
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "../openpoke.h"
#include "btlmessages.h"

extern void LoadTimeAdjustedColors(u16 *dst, u16 *src, int nclrs);

extern const unsigned short battlegrassPal[16];
extern const unsigned short battlegrassTiles[1808];
extern const unsigned short battlegrassMap[2048];

// "PP: currVal/maxVal"
extern const char strBattle_PP_Note[];

int btlWindowShifts[3];

void scene_BuildBattleScreen()
{
	REG_BG0CNT = BG_4BPP | BG_SIZE2 | BG_PRIO(0) | 24 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT;
	REG_BG3CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(3) | 26 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BLDCNT = 0;
	DmaClear(0, MEM_VRAM, 0xFFFF);
	//DmaClear(0, MEM_VRAM, 0xF000);

	ClearOamBak();

	REG_DISPCNT |=  DCNT_WIN0;
	REG_WIN0H = 240;
	REG_WIN0V = 112;
	REG_WININ = WIN_BG3 | WIN_BG2 | WIN_BG1 | WIN_BG0 | WIN_OBJ | WIN_BLD;
	REG_WINOUT = 0;

	vwf_init(0, BG_CBB(0) | BG_SBB(24), fontWesternTiles, fontWesternWidths);
	vwDestination = (u32*)VWDEST_BATTLE;
	vwClear(1);

	CpuFastArrayCopy(battleinterfaceTiles,MEM_VRAM);
	CpuFastCopy(battleinterfacePal, MEM_PAL_BG + 0x1C0, 16);
	CpuFastCopy(framePal, MEM_PAL_BG + 0x1E0, 16);
	CpuFastCopy(frameTiles + (0x90 * MyPlayer.Options.frame),MEM_VRAM+0x240,0x120);

	u16* meh = (u16*)(MEM_VRAM + 0xC000);
	int i;
	for(i=0; i < 640*3; i++)
		meh[i] = battleinterfaceMap[i] + 0xE000;
	//	meh[i] = grassMap[i] + 0x1000;

	//scene_DrawFrame(0,30,14,6);
	scene_SetLine(1,28,15,96,14);
	scene_SetLine(1,28,17,160,14);

	//scene_DrawFrame(0,15,34,6);
	scene_SetLine(1,13,35,224,14);
	scene_SetLine(1,13,37,288,14);
	//scene_DrawFrame(15,15,34,6);
	vwClearLine(1,9);
	vwClearLine(1,13);
	vwWriteG(16,4,strBattleFight);
	//vwf_set_color(TEXT_INK, 3);
	vwWriteG(24,4,strBattleBag);
	//vwNormalLUT();
	vwWriteG(16,6,strBattlePokemon);
	vwWriteG(24,6,strBattleRun);
	scene_SetLine(17,6,35,240,15);
	scene_SetLine(24,5,35,248,15);
	scene_SetLine(17,6,37,304,15);
	if(!ThisBattle.trainer) scene_SetLine(24,5,37,312,15);

	//scene_DrawFrame(0,20,54,6);
	scene_SetLine(2,8,55,352,15);
	scene_SetLine(11,8,55,416,15);
	scene_SetLine(2,8,57,480,15);
	scene_SetLine(11,8,57,544,15);
	//scene_DrawFrame(20,10,54,6);
	scene_SetLine(21,8,55,368,15);
	scene_SetLine(21,8,57,376,15);

	vwWriteG(31,4,strArrow);

	//ThisBattle.background
	AGBPrintf("Supposed to copy battle background from 0x%x.\n",battlebacks[ThisBattle.background*4]);
	DmaCopy(battlebacks[ThisBattle.background*4], MEM_VRAM + 0x8000, 0x1000);
	DmaCopy(battlebacks[(ThisBattle.background*4)+1], MEM_VRAM + 0xD000, 0x1000);
	if(currentLevel->tileseta->flags && 1)
		DmaCopy(battlebacks[(ThisBattle.background*4)+2], MEM_PAL_BG, 32);
	else
		LoadTimeAdjustedColors((u16*)MEM_PAL_BG, (u16*)battlebacks[(ThisBattle.background*4)+2], 16);
	ThisBattle.environment = battlebacks[(ThisBattle.background*4)+3];
	//DmaArrayCopy(battlegrassTiles, MEM_VRAM + 0x8000);
	//DmaArrayCopy(battlegrassMap, MEM_VRAM + 0xD000);
	//LoadTimeAdjustedColors((u16*)MEM_PAL_BG, (u16*)battlegrassPal, 16);

	REG_BG3HOFS = 0;
	REG_BG3VOFS = 0;

	OamBak[0].Shape = 0;
	OamBak[0].Size = 3;
	OamBak[1].Shape = 0;
	OamBak[1].Size = 3;

//	DmaArrayCopy(playerwindowPal, MEM_PAL_OBJ + 0x10a0);
//	DmaArrayCopy(hpbarPal, MEM_PAL_OBJ + 0x10c0);

	DmaArrayCopy(btlstatusTiles, MEM_VRAM_OBJ + 0x3580);
	DmaArrayCopy(btlstatusPal, MEM_PAL_OBJ + 0xE0);
}

void scene_BreakBattleScreen()
{
	ResetBackgrounds();
	vwf_init_dflt();
	vwToBG();
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	InstallHBlank(0);
}

void scene_SetLine(int x, int w, int y, u16 start, u8 pal)
{
	u16 *BG0 = ((u16*)0x600C000);
	int b = x;
	u16 tpal = pal<<12;
	for(; b < x+w; b++)
	{
		BG0[(y*32)+b] = start + tpal;
		BG0[(y*32)+b+32] = start + 32 + tpal;
		start++;
	}
}

void scene_DrawMoveData(aPokemon * mon, int move)
{
	char ppline[8];
	int m, p;

	vwClearLine(1,17);

	if(move >= 4)
	{
		move = 0;
	}
	else
	{
		//ssmoves * myA = GetmovesSubstruct(mon);
		m = GetMonsterStats(mon, pMove1 + move);
		if(m != 0)
		{
			p = GetMonsterStats(mon, pPP1 + move);
			vwWriteG(16,8,TypeNames[moves[m].type]);
			sprintf(ppline, strBattle_PP_Note, p, GetPPForMove(mon, move)); //moves[move].pp);
			vwWriteG(24,8,ppline);
		}
	}
}

void scene_DoTrainerDefeatSpeech()
{
	int i;
	DmaCopy(TrainerPics[(Trainers[ThisBattle.trainerindex].image * 2) + 1], MEM_PAL_OBJ + 0x60, 32);
	LZ77UnCompVram(TrainerPics[(Trainers[ThisBattle.trainerindex].image)* 2], (u16*)(MEM_VRAM_OBJ + 0x6800));
	OamBak[1].CharNo = 896;
	OamBak[1].Pltt = 3;
	OamBak[1].VPos = 8;
	OamBak[1].HPos = 151;
	for(i = 18; i >= 0; i--)
	{
		DoVBlank();
		OamBak[1].HPos = 151 + (i*4);
	}
	btlsays(ThisBattle.onWin);
}

const char * scene_GetTrainerName(int index)
{
	if(Trainers[index].flags & 1)
		return MyPlayer.rival;
	return Trainers[index].name;
}

void scene_StartTrainerBattle(int index)
{
	u32 i = 0;

	DmaCopy(TrainerPics[(Trainers[index].image * 2) + 1], MEM_PAL_OBJ + 0x60, 32);
	LZ77UnCompVram(TrainerPics[(Trainers[index].image) * 2], (u16*)(MEM_VRAM_OBJ + 0x7000));

	if(MyPlayer.gender == 0)
	{
		DmaArrayCopy(dannybackPal, MEM_PAL_OBJ + 0x40);
		DmaArrayCopy(dannybackTiles, MEM_VRAM_OBJ + 0x4000);
	}
	else
	{
		DmaArrayCopy(danibackPal, MEM_PAL_OBJ + 0x40);
		DmaArrayCopy(danibackTiles, MEM_VRAM_OBJ + 0x4000);
	}
#ifdef WITH_SHIRTCOLORS
		*(u16*)0x0500025C= shirtcolors[(MyPlayer.shirtColor*2) + ((MyPlayer.gender%2)*16)];
		*(u16*)0x0500025E = shirtcolors[(MyPlayer.shirtColor*2)+1+((MyPlayer.gender%2)*16)];
#endif

	OamBak[0].CharNo = 512;
	OamBak[0].Pltt = 2;
	OamBak[0].HPos = 24;
	OamBak[0].VPos = 54;
	OamBak[0].Priority = 1;

	OamBak[1].CharNo = 896;
	OamBak[1].Pltt = 3;
	OamBak[1].VPos = 8;
	OamBak[1].HPos = 151;
	OamBak[1].Priority = 1;

	//sndPlaySound(3,SOUND_NORESTART);

	battle_OpenAnimation();

	scene_BuildPlayerPartyWin();
	scene_BuildOpponentPartyWin();

// "[Trainertype] [TrainerName] wants to fight!"
	btlsays(strBattleFooWantsToFight, TrainerTypes[Trainers[index].kind], scene_GetTrainerName(index));

// "[Trainertype] sents out [Pkmn]!"
	btlsays(strBattleFooSentOutBar, TrainerTypes[Trainers[index].kind], scene_GetTrainerName(index), HisParty[0].Personal.Nickname);

	for(i = 0; i < 18; i++)
	{
		DoVBlank();
		OamBak[1].HPos = 151 + (i*4);
	}
	fighters_Initialize(1,0);
	battle_SendOut(1,0,SEND_ALL);


	btlsays(strBattleIChooseYou, MyParty[0].Personal.Nickname); //fighters_This(0));
	for(i = 0; i < 64; i++)
	{
		DoVBlank();
		OamBak[0].HPos = 24 - i*2;
		if(i < 48)
			OamBak[0].CharNo = 512 + (64 * (i/10));
	}
//	OamBak[0].CharNo = 0;
//	OamBak[0].Pltt = 0;
//	OamBak[0].HPos = 24;
	fighters_Initialize(0,0);
	battle_SendOut(0,0,SEND_ALL);

	ThisBattle.duringBattle = 1;
	ThisBattle.trainer = 1;
	ThisBattle.trainerindex = index;
	ThisBattle.runCommand = 0;
	ThisBattle.doublebattle = 0;
	ThisBattle.internalbattle = 1;
	ThisBattle.decision = 0;
}

void scene_StartWildBattle()
{
	// Which Pokémon will join the battle?
	int chosenPkmn = 0;

	if(MyPlayer.gender == 0)
	{
		DmaArrayCopy(dannybackPal, MEM_PAL_OBJ + 0x40);
		DmaArrayCopy(dannybackTiles, MEM_VRAM_OBJ + 0x4000);
	}
	else
	{
		DmaArrayCopy(danibackPal, MEM_PAL_OBJ + 0x40);
		DmaArrayCopy(danibackTiles, MEM_VRAM_OBJ + 0x4000);
	}
#ifdef WITH_SHIRTCOLORS
		*(u16*)0x0500025C= shirtcolors[(MyPlayer.shirtColor*2) + ((MyPlayer.gender%2)*16)];
		*(u16*)0x0500025E = shirtcolors[(MyPlayer.shirtColor*2)+1+((MyPlayer.gender%2)*16)];
#endif
	if(demo==1) //are we running a demo?
	{
		DmaArrayCopy(demobackPal, MEM_PAL_OBJ + 0x40);
		DmaArrayCopy(demobackTiles, MEM_VRAM_OBJ + 0x4000);
	}

	//char buffy[255];
	int i=0;

	OamBak[0].CharNo = 512;
	OamBak[0].Pltt = 2;
	OamBak[0].HPos = 24;
	OamBak[0].VPos = 54;
	OamBak[0].Priority = 1;

	//sndPlaySound(6,SOUND_NORESTART);

	fighters_Initialize(1,0);
	battle_SendOut(1,0,0);
	OamBak[1].Priority = 1;
	battle_OpenAnimation();
	battle_SendOut(1,0,SEND_SCROLLCRY);
	btlWindowShifts[1] = 0;
	scene_BuildPlayerPartyWin();

	// Displays message until A or B is pressed
	btlsays(strBattleFooAppeared, fighters_This(1));
	while(!(Trg & KEY_A || Trg & KEY_B))
	{
		KeyRead();
		DoVBlank();
	}

//KAWA - This part is for the demo game.
	if(GetPartySize(&MyParty)==0)
	{
		OamBak[0].CharNo = 832;
		btlsays(strBattleDemoNoParty);
		ThisBattle.decision = 10;
		return;
	}
// </demo>
	//Runaway hack
	if(	demo == 0	 &&
		Cont & KEY_A &&
		Cont & KEY_B)
	{
		int run = battle_Run(i,0);
		if(run > 0)
		{
			ThisBattle.decision = 3;
			return;
		}
	}

	if(demo==1)
	{
		btlsays(strBattleDemoSendOut, MyParty[0].Personal.Nickname);
	}
	else
	{
	// Check for fainted Pokémon.
	// If all of them fainted, return
		while(	MyParty[chosenPkmn].Status.CurrentHP == 0 &&
				chosenPkmn < GetPartySize())
			chosenPkmn++;
		if(chosenPkmn >= GetPartySize())
		{
			AGBPrintf("*scene_StartWildBattle: chosenPkmn has an invalid value!");
			return;
		}

		btlsays(strBattleIChooseYou, MyParty[chosenPkmn].Personal.Nickname); //fighters_This(0));
	}
	for(i = 0; i < 64; i++)
	{
		DoVBlank();
		OamBak[0].HPos = 24 - i*2;
		if(i < 48)
			OamBak[0].CharNo = 512 + (64 * (i/10));
	}
//	OamBak[0].CharNo = 0;
//	OamBak[0].Pltt = 0;
//	OamBak[0].HPos = 24;
	fighters_Initialize(0,0);
	battle_SendOut(0,chosenPkmn,SEND_ALL);

	ThisBattle.duringBattle = 1;
	ThisBattle.trainer = 0;
	ThisBattle.runCommand = 0;
	ThisBattle.doublebattle = 0;
	ThisBattle.internalbattle = 1;
	ThisBattle.decision = 0;
	ThisBattle.roamer = 0;
}

void scene_WriteInBox(u32 where, char *what)
{
	TVwf *vwf= gp_vwf;
	u32 *oldd = vwf->dstD;
	u32 *oldv = (u32*)vwf->putc_;
	//u32 oldp = vwf->dstP;
	u32 x=0,y=0;
	vwf->dstD = (u32*)0x06005c00;

	switch(where)
	{
		case 0:
			x=148;
			y=13;
			break;
		case 1:
			x=148;
			y=-3;
			break;
		case 2:
			x=200;
			y=22;
			break;
	}

	vwf->putc_ = (fn_putc)vwf_putc8x16T;
	//vwf->dstP = 8;
	vw_SetSmall();
	vwBattleLUT();
	vwWrite(x,y,what);
	vwNormalLUT();
	vw_SetBig();
	//vwf->dstP = oldp;
	vwf->putc_ = (fn_putc)oldv;
	vwf->dstD = oldd;
}

void scene_StatusWindows(void)
{
	u16 line = REG_VCOUNT;
	if(line > 160)
	{
		REG_BG0HOFS = 0; //btlWindowShifts[1];
		REG_BG0VOFS = 6;
	}
	else if(line == 56)
	{
		REG_BG0HOFS = 0; //-7 + btlWindowShifts[0];
		REG_BG0VOFS = -7;
	}
	else if(line == 111)
	{
		REG_BG0HOFS = 0;
		REG_BG0VOFS = btlWindowShifts[2];
	}
}

void scene_BuildPlayerPartyWin()
{
	DmaArrayCopy(newbtlwinsPal, MEM_PAL + 0x1a0);
	DmaCopy(newbtlwinsTiles + 0x900, MEM_VRAM + 0x6400, 0x400);

	u16* BG = (u16*)0x600C000;

	const int x=22,y=10;
	int i,j;
	BG[(y*32)+x-1] = 801 | 0xD400;
	BG[((y+1)*32)+x-1] = 817 | 0xD400;
	for(i = 0; i < 8; i++)
	{
		BG[(y*32)+x+i] = 800 | 0xD000;
		BG[((y+1)*32)+x+i] = 816 | 0xD000;
	}
	for(i = 0; i < 6; i++)
	{
		if(GetMonsterStats(&MyParty[i], pPersonal))
		{
			if(GetMonsterStats(&MyParty[i], pCurrentHP))
			{
				j = 804;
			}
			else
			{
				j = 803;
			}
		}
		else
			j = 802;
		BG[(y*32)+x+1+i] = j | 0xD000;
	}
	InstallHBlank(scene_StatusWindows);
}

void scene_BuildOpponentPartyWin()
{
	DmaArrayCopy(newbtlwinsPal, MEM_PAL + 0x1a0);
	DmaCopy(newbtlwinsTiles + 0x900, MEM_VRAM + 0x5c00, 0x400);

	u16* BG = (u16*)0x600C000;

	const int x=0,y=2;
	int i,j;
	BG[(y*32)+x+8] = 801 | 0xD000;
	BG[((y+1)*32)+x+8] = 817 | 0xD000;
	for(i = 0; i < 8; i++)
	{
		BG[(y*32)+x+i] = 800 | 0xD000;
		BG[((y+1)*32)+x+i] = 816 | 0xD000;
	}
	for(i = 0; i < 6; i++)
	{
		if(GetMonsterStats(&HisParty[i], pPersonal))
		{
			if(GetMonsterStats(&HisParty[i], pCurrentHP))
			{
				j = 804;
			} else
			{
				j = 803;
			}
		} else
		{
			j = 802;
		}
		BG[(y*32)+x+1+i] = j | 0xD000;
	}
	InstallHBlank(scene_StatusWindows);
}

void scene_BuildPlayerWin()
{
	DmaArrayCopy(newbtlwinsPal, MEM_PAL + 0x1a0);
	DmaArrayCopy(hpbarPal, MEM_PAL + 0x180);
	DmaCopy(newbtlwinsTiles + 0x400, MEM_VRAM + 0x6400, 0xa00);

	u16* BG = (u16*)0x600C000;

	int i,x=16,y=9;
	for(i = 0; i < 78; i++)
	{
		BG[(y*32)+x] = (800 | 0xD000) + i;
		if(y == 11 &&  x > 21 && x < 28) BG[(y*32)+x] = (800 | 0xC000) + i;
		if(y == 12 &&  x > 17 && x < 24) BG[(y*32)+x] = (800 | 0xC000) + i;
		x++;
		if(x==32)
		{
			x=16;
			y++;
		}
	}

	char genderchar = 0x7F, gendercolor = 1;
	int species = GetMonsterStats(fighters[0].mon, pSpecies);
	ssPersonal *myP = (ssPersonal*)&fighters[0].mon->Personal;

	if(BaseStats[species].Gender < 0xFF)
	{
		if((u8)myP->Personal > BaseStats[species].Gender)
		{
			genderchar = 0x8A; //Male
			gendercolor = 11;
		} else
		{
			genderchar = 0x8B; //Female
			gendercolor = 10;
		}
	}
	char foo[64];
	sprintf(foo, "%s\a\1%c%c", GetNickname(fighters[0].mon), gendercolor, genderchar);
	scene_WriteInBox(0, foo);
	sprintf(foo, "%d/%d", GetMonsterStats(fighters[0].mon, pCurrentHP), GetMonsterStats(fighters[0].mon, pTotalHP));
	scene_WriteInBox(2, foo);
	MakeHPBar(GetMonsterStats(fighters[0].mon, pCurrentHP), GetMonsterStats(fighters[0].mon, pTotalHP), MEM_VRAM + 0x68c0, 0);
	MakeEXPBar(fighters[0].mon);

	InstallHBlank(scene_StatusWindows);
}

void scene_BuildOpponentWin()
{
	DmaArrayCopy(newbtlwinsPal, MEM_PAL + 0x1a0);
	DmaArrayCopy(hpbarPal, MEM_PAL + 0x180);
	DmaCopy(newbtlwinsTiles, MEM_VRAM + 0x5c00, 0x800);

	u16* BG = (u16*)0x600C000;

	int i,x=0,y=0;
	for(i = 0; i < 62; i++)
	{
		BG[(y*32)+x] = (736 | 0xD000) + i;
		if(y == 2 &&  x > 5 && x < 12) BG[(y*32)+x] = (736 | 0xC000) + i;
		x++;
		if(x==16)
		{
			x=0;
			y++;
		}
	}

	char genderchar = 0x7F, gendercolor = 1;
	int species = GetMonsterStats(fighters[1].mon, pSpecies);
	ssPersonal *myP = (ssPersonal*)&fighters[1].mon->Personal;

	if(GETBIT(MyDex.caught, species))
		DmaCopy(newbtlwinsTiles + 0x960, MEM_VRAM + 0x5e20, 0x20);

	if(BaseStats[species].Gender < 0xFF)
	{
		if((u8)myP->Personal > BaseStats[species].Gender)
		{
			genderchar = 0x8A; //Male
			gendercolor = 11;
		} else
		{
			genderchar = 0x8B; //Female
			gendercolor = 10;
		}
	}
	char foo[64];
	sprintf(foo, "%s\a\1%c%c", GetNickname(fighters[1].mon), gendercolor, genderchar);
	scene_WriteInBox(1, foo);
	MakeHPBar(GetMonsterStats(fighters[1].mon, pCurrentHP), GetMonsterStats(fighters[1].mon, pTotalHP), MEM_VRAM + 0x60c0, 0);

	InstallHBlank(scene_StatusWindows);
}

int scene_CommandMenu(int index, int lastAction)
{
	char buffy[255];
	u8 actioncursors[8] = { 16,35,  23,35,  16,37,  23,37 }; //cursor positions
	int bfrInt = 0;

	sprintf(buffy, strBattleWhatToDo, fighters_This(index));
	vwClearLine(1,8);
	vwClearLine(1,12);
	vwWriteG(0,4,buffy);
	scene_SetLine(actioncursors[lastAction*2],1,actioncursors[(lastAction*2)+1],255,15);
	btlWindowShifts[2] = 160;

	while(1)
	{
		DoVBlank();
		KeyRead();

		if((Trg & KEY_LEFT) || (Trg & KEY_RIGHT))
		{
			scene_SetLine(actioncursors[lastAction*2],1,actioncursors[(lastAction*2)+1],319,15);
			bfrInt = lastAction;
			lastAction = wrap(lastAction + key_tri_horz(), 0, 4);
			if(lastAction == 3 && ThisBattle.trainer)
				lastAction = bfrInt;
			scene_SetLine(actioncursors[lastAction*2],1,actioncursors[(lastAction*2)+1],255,15);
		}
		if((Trg & KEY_UP) || (Trg & KEY_DOWN))
		{
			scene_SetLine(actioncursors[lastAction*2],1,actioncursors[(lastAction*2)+1],319,15);
			bfrInt = lastAction;
			lastAction = wrap(lastAction + (key_tri_vert()*2), 0, 4);
			if(lastAction == 3 && ThisBattle.trainer)
				lastAction = bfrInt;
			scene_SetLine(actioncursors[lastAction*2],1,actioncursors[(lastAction*2)+1],255,15);
		}
		if(Trg & A_BUTTON)
		{
			scene_SetLine(actioncursors[lastAction*2],1,actioncursors[(lastAction*2)+1],319,15);
			break;
		}
	}
	return lastAction+1;
}

/* Function to choose a move in a battle */
int scene_FightMenu(int fighterIndex)
{
	u8 moveCursors[8] =   {  1,55,  10,55,   1,57,  10,57 };
	int lastmove = fighters[fighterIndex].lastused;


	AGBPrintf("scene_FightMenu(%d)\n", fighterIndex);

	vwClearLine(1,16);
	vwClearLine(1,20);
	vwClearLine(1,24);
	vwClearLine(1,28);
	vw_SetSmall();

// Write attack names to the screen
	vwWriteG(0,8, moveNames[GetMonsterStats(fighters[fighterIndex].mon, pMove1)]);
	vwWriteG(0,10,moveNames[GetMonsterStats(fighters[fighterIndex].mon, pMove2)]);
	vwWriteG(0,12,moveNames[GetMonsterStats(fighters[fighterIndex].mon, pMove3)]);
	vwWriteG(0,14,moveNames[GetMonsterStats(fighters[fighterIndex].mon, pMove4)]);

// Make the font bigger
	vw_SetBig();

// Draw cursor
	scene_SetLine(moveCursors[lastmove*2],1,moveCursors[(lastmove*2)+1],255,15);

// Shows type and PP
	scene_DrawMoveData(fighters[fighterIndex].mon, lastmove);

	btlWindowShifts[2] = 320;
	while(1)
	{
		DoVBlank();
		KeyRead();

	// Move cursor sideways
		if((Trg & KEY_LEFT) || (Trg & KEY_RIGHT))
		{
			scene_SetLine(moveCursors[lastmove*2], 1, moveCursors[(lastmove*2)+1], 319, 15);
			lastmove = wrap(lastmove + key_tri_horz(), 0, 4);
			scene_SetLine(moveCursors[lastmove*2], 1, moveCursors[(lastmove*2)+1], 255, 15);
			scene_DrawMoveData(fighters[fighterIndex].mon, lastmove);
		}

	// Move cursor up- and downwards
		if((Trg & KEY_UP) || (Trg & KEY_DOWN))
		{
			scene_SetLine(moveCursors[lastmove*2],1,moveCursors[(lastmove*2)+1],319,15);
			lastmove = wrap(lastmove + (key_tri_vert()*2), 0, 4);
			scene_SetLine(moveCursors[lastmove*2],1,moveCursors[(lastmove*2)+1],255,15);
			scene_DrawMoveData(fighters[fighterIndex].mon, lastmove);
		}

		if(Trg & A_BUTTON)
		{
		// If move is != 0
			if(GetMonsterStats(fighters[0].mon, pPP1 + lastmove))
			{
				fighters[0].lastused = lastmove;
				scene_SetLine(moveCursors[lastmove*2],1,moveCursors[(lastmove*2)+1],319,15);
				return lastmove;
			}
		// Else do nothing
			else
			{
				//Beep!
			}
		}
		else if(Trg & B_BUTTON)
		{
			scene_SetLine(moveCursors[lastmove*2],1,moveCursors[(lastmove*2)+1],319,15);
			btlWindowShifts[2] = 160;
			return -1;
		}
	}
}

int scene_ItemMenu(int index)
{
	FadeOut();
	scene_BreakBattleScreen();
	int i = BattleInventory();
	if(items[i].param1 != 1)
	{
		scene_BuildBattleScreen();
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;
		scene_BuildPlayerWin();
		scene_BuildOpponentWin();
		if(fighters[0].mon->Status.CurrentHP)
			battle_SendOut(0, fighters[0].pokemonIndex, 0);
		if(fighters[1].mon->Status.CurrentHP)
			battle_SendOut(1, fighters[1].pokemonIndex, 0);
		OamBak[2].HPos = 158;
		OamBak[3].HPos = 190;
		OamBak[4].HPos = 36;
		OamBak[5].HPos = 68;
		OamBak[8].HPos = 126;
		OamBak[9].HPos = 190;
		OamBak[10].HPos= 12;
		OamBak[11].HPos= 76;
		REG_WIN0V = ((80-(40*2)) << 8) + (80+(40*2));
		FadeIn();
	}
	return i;
}

void scene_ChooseEnemyCommand(int index)
{
	int dice;

	//KAWA	IMPORTANT fix here -- instead of having the opponent use Struggle,
	//the game would hang. In the memory viewer, you could see the opponent's
	//data flicker between encryption states as the dice kept being rolled and
	//usage denied.
	if(!battle_CanShowFightMenu(index))
	{
		battle_AutoChooseMove(index);
		return;
	}

	while(1)
	{
		dice = rrand(4);
		if(!battle_IsMoveSensible(index,dice)) continue;
		if(battle_CanChooseMove(index,dice,0))
		{
			battle_RegisterMove(index, dice);
			return;
		}
	}
}

int scene_ChooseNewEnemy()
{
	int i;
	for(i=0; i < 6; i++)
	{
		if(HisParty[i].Personal.OTID == 0)
		{
			return false;
		}
		if(HisParty[i].Status.CurrentHP)
		{
			return i;
		}
	}
	return false;
}

int scene_Switch(int index, int lax, int cancancel)
{
	int i;
	AGBPrintf("scene_Switch(%d,%d,%d)\n",index,lax,cancancel);
	FadeOut();
	scene_BreakBattleScreen();
	i = ShowParty(1,0);
	scene_BuildBattleScreen();
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	scene_BuildPlayerWin();
	scene_BuildOpponentWin();
	if(fighters[0].mon->Status.CurrentHP)
		battle_SendOut(0, fighters[0].pokemonIndex, 0);
	if(fighters[1].mon->Status.CurrentHP)
		battle_SendOut(1, fighters[1].pokemonIndex, 0);
	OamBak[2].HPos = 158;
	OamBak[3].HPos = 190;
	OamBak[4].HPos = 36;
	OamBak[5].HPos = 68;
	OamBak[8].HPos = 126;
	OamBak[9].HPos = 190;
	OamBak[10].HPos= 12;
	OamBak[11].HPos= 76;
	REG_WIN0V = ((80-(40*2)) << 8) + (80+(40*2));
	FadeIn();
	AGBPrintf("scene_Switch: returning %d\n",i);
	return i;
}

int scene_Fainted(int index)
{
	int i, np;
	fighters_Cry(index, 40);
	if(index == 1)
	{
		for(i = 0; i < 60; i++)
		{
			DoVBlank();
			np = (i*2) + fighters[index].spriteVOffset + 8;
			OamBak[1].VPos = np;
			if(np > 24) DmaClear(0, MEM_VRAM_OBJ + 0xF00, 0x100);
			if(np > 28) DmaClear(0, MEM_VRAM_OBJ + 0xE00, 0x100);
			if(np > 32) DmaClear(0, MEM_VRAM_OBJ + 0xD00, 0x100);
			if(np > 40) DmaClear(0, MEM_VRAM_OBJ + 0xC00, 0x100);
			if(np > 48) DmaClear(0, MEM_VRAM_OBJ + 0xB00, 0x100);
			if(np > 56) DmaClear(0, MEM_VRAM_OBJ + 0xA00, 0x100);
			if(np > 64) DmaClear(0, MEM_VRAM_OBJ + 0x900, 0x100);
			if(np > 72) DmaClear(0, MEM_VRAM_OBJ + 0x800, 0x100);

			OamBak[4].HPos = 36	 - (i * 4);
			OamBak[5].HPos = 68 - (i * 4);
			OamBak[10].HPos = 12 - (i * 4);
			OamBak[11].HPos = 76 - (i * 4);
		}
	}

	if(battle_AllFainted(HisParty))
	{
		if(ThisBattle.trainer)
		{
			//sndPlaySound((ThisBattle.gymleader ? 8 : 10),SOUND_NORESTART);
			sndPlaySound(8,SOUND_NORESTART);
		}
		else
		{
			sndPlaySound(9,SOUND_NORESTART);
		}
	}
	return false;
}

void scene_WithdrawMonster(int side)
{
	int i;

	//Sprites:
	// 0 / 1 - monster
	// 2 / 4 - HP left
	// 3 / 5 - HP right
	// 6 / 7 - Status
	// 8 /10 - Window left
	// 9 /11 - Window right
	if(side == 0)
	{
		OamBak[0].Pltt = 8;
		pal_blend_asm5((u16*)MEM_PAL_OBJ, RedStrip, (u16*)MEM_PAL_OBJ+0x80,16,32);
		DmaCopy(MEM_PAL, MEM_PAL + 0x20, 32);
		for(i=0; i <= 32; i++)
		{
			pal_blend_asm5((u16*)MEM_PAL_OBJ, RedStrip, (u16*)MEM_PAL_OBJ+0x80,16,i);
			pal_blend_asm5((u16*)MEM_PAL+0x10, WhiteStrip, (u16*)MEM_PAL,16,i);
			DoVBlank();
		}
		OamBak[0].HPos = 250;
		for(i=32; i >= 0; i-=2)
		{
			pal_blend_asm5((u16*)MEM_PAL+0x10, WhiteStrip, (u16*)MEM_PAL,16,i);
			DoVBlank();
		}

		for(i = 0; i < 64; i++)
		{
			OamBak[2].HPos = 158 + (i*2);
			OamBak[3].HPos = 190 + (i*2);

			OamBak[6].HPos = 140 + (i*2);

			OamBak[8].HPos = 126 + (i*2);
			OamBak[9].HPos = 190 + (i*2);

			DoVBlank();
		}
	}
	else
	{
	}
}
