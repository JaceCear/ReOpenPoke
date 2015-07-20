/**	\file main.c
		\author Kawa
*/
#include "openpoke.h"

#ifdef DEBUG
const u16 TestShop[] = { 4,3,13,20,34,85,86,0 };
DebugField MyDebug;
extern void CryTest(int species, int freq);
void TestTileset();
#endif

u32 rndseed; /**< \brief Randomizer seed */

extern void DoStartMenu();
extern void PrepareDex();
extern void intr_main(void);
extern void StartSurfing(int withHop);

void StartupDebug();

void TweenTimeAdjustedColors();

aMap gLevel;

PlayerData MyPlayer INEWRAM;
DexData MyDex;
u8 MyBattles[64]; /**< \brief Bitfield to remember which trainer battles you've won. */

int LastKnownTimeOfDay;
u32 LastTOD_R, LastTOD_G, LastTOD_B;

int LockDown;
unsigned int TotalFrames;

void (*CurrentProcess)(void); /**< \brief Current subprocess to run. */
void (*PreviousProcess)(void); /**< \brief Previous subprocess. */
void (*TweenProcess)(void);

char DialogueBoxBuffer[128] INEWRAM;

typedef void (*IntrFuncp)(void);
void IntrDummy(void);
void VBlankIntr(void);
void IntroVBlank(void);
void HBlankIntr(void);
void HBlankTest(void);

void Scream(char * error);

extern void RunTheTest();
void HandleEggTimer();

int SafariBalls;
int SafariSteps;

u32 TimeOfDayColors[4][3] =
{
	{ 256, 256, 256 }, //afternoon
	{ 256, 180, 180 }, //evening
	{ 144, 144, 192 }, //night
	{ 218, 218, 180 }, //morning
};

// --------------------------------------------------------------------
// GLOBALS
// --------------------------------------------------------------------

IntrFuncp IntrTable[13] =
{
	VBlankIntr,	// V Blank interrupt
	HBlankIntr,	// H Blank interrupt
	IntrDummy,	// V Counter interrupt
	IntrDummy,	// Timer 0 interrupt
	IntrDummy,	// Timer 1 interrupt
	IntrDummy,	// Timer 2 interrupt
	IntrDummy,	// Timer 3 interrupt
	IntrDummy,	// Serial communication interrupt
	IntrDummy,	// DMA 0 interrupt
	IntrDummy,	// DMA 1 interrupt
	IntrDummy,	// DMA 2 interrupt
	IntrDummy,	// DMA 3 interrupt
	IntrDummy,	// Key interrupt
};

u32 totalframes;
u16 SongPlaying;
OamData OamBak[128];

const unsigned short demoinput[2][32] =
{
	{
			0,0,			//initial delay
			KEY_A,0,		//press fight and show attacks
			KEY_RIGHT,0,KEY_LEFT,KEY_A, //ponder and select tackle
			0,0,	//wait away usage messages
			KEY_DOWN,KEY_RIGHT,KEY_A, //select run
			KEY_A,			//press away message
			0xFFFF			//stop playing
	},
}; /**< \brief Demo recordings. */

int demo = 0;
int demotimer = 0;
int democursor = 0;

// --------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------

#ifdef DEBUG
void CheckNoSave()
{
	extern const char *Choices[];
	u16 savedcheck;
	bytecpy(&savedcheck, SRAM, sizeof(savedcheck));
	if(savedcheck == 0xFFFF)
	{
		sayf(SYSTEM, strSaveRequired, Choices[47]);
		SoftReset();
	}
}
#endif

/** \brief Entry point. */
int main(void)
{
	// Clear everything first
	RegisterRamReset(	RESET_PALETTE | RESET_VRAM | RESET_OAM |
						RESET_SOUND | RESET_OTHER	);

	RTCTime myTime;
	u16 foo;

	REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

	AGBPrintInit();
	AGBPrint("OPENPOKé\n--------\nStartup...\n");

	//AGBPrint("* Setup waitcnt\n");
	//REG_WAITCNT = CST_ROM0_1ST_3WAIT | CST_ROM0_2ND_1WAIT | CST_PREFETCH_ENABLE;

	AGBPrint("* Clear spritebuffer\n");
	ClearOamBak();

	REG_DISPCNT =  DCNT_MODE0;
	REG_BLDY = 15;

	AGBPrint("* Setup interrupts\n");

	*(vu32 *)INTR_VECTOR_BUF = (vu32 )intr_main;
	REG_IME = 1;
	REG_IE = V_BLANK_INTR_FLAG | H_BLANK_INTR_FLAG | CASSETTE_INTR_FLAG;
	REG_DISPSTAT = STAT_V_BLANK_IF_ENABLE | STAT_H_BLANK_IF_ENABLE;

	AGBPrint("* sndInit();\n");
	sndInit();

	AGBPrint("* Screen setup\n");
	ResetBackgrounds();
	CleanUpCrap();

	AGBPrint("* Real Time Clock\n");
	RTC_TurnOn();
	RTC_GetTime(&myTime);
	AGBPrintf("RTC_GetTime returns %0d/%0d/%0d, %0d:%0d:%0d\n", myTime.year,
		myTime.month,myTime.day,myTime.hours,myTime.minutes,myTime.seconds);
	AGBPrintf("RTC_GetTime also returns that the day of the week is #%d.\n",myTime.dayofweek);

	AGBPrint("* PokéDex\n");
	PrepareDex();

	AGBPrintf("Startup finished. Please check 0x02010000 in\nMemViewer for realtime player info.\n\n");
	KeyRead();

	//Just to make sure things match the originals...
	AGBPrint("SizeOf report:\n");
	AGBPrintf("* ssPersonal: %d\n", sizeof(ssPersonal)); //<-- important, should be 32
	AGBPrintf("* ssStatus: %d\n", sizeof(ssStatus)); //<-- important, should be 20
	AGBPrintf("* ssGrowth: %d\n", sizeof(ssGrowth)); //<-- important, should be 12
	AGBPrintf("* ssAttacks: %d\n", sizeof(ssAttacks)); //<-- important, should be 12
	AGBPrintf("* ssEffort: %d\n", sizeof(ssEffort)); //<-- important, should be 12
	AGBPrintf("* ssMisc: %d\n", sizeof(ssMisc)); //<-- important, should be 12
	AGBPrintf("* aPokemon: %d\n", sizeof(aPokemon)); //<-- important, should be 100
	AGBPrintf("* aBoxedMon: %d\n", sizeof(aBoxedMon)); //<-- important, should be 80
	AGBPrintf("* MyPlayer: %d\n", sizeof(MyPlayer));
	AGBPrintf("* MyDex: %d\n", sizeof(MyDex));
	AGBPrintf("* MyBattles: %d\n", sizeof(MyBattles));
	AGBPrintf("* inventory: %d\n", sizeof(inventory));
	AGBPrintf("* ScriptFlags: %d\n", sizeof(ScriptFlags));
	AGBPrintf("* ScriptVars: %d\n", sizeof(ScriptVars));
	AGBPrintf("* TrainerBattles: %d\n", sizeof(MyBattles));
	AGBPrintf("* MyBox: %d\n", sizeof(MyBox)); //<-- should be 33600 (5*6*14*80)
	AGBPrintf("* Apartment: %d\n", sizeof(ApartmentItems));

	LoadGame();
	//AGBPrintf("Settings: 0x%X\n", foo);
	if(MyPlayer.OptionsI == 0xFFFF)
		MyPlayer.OptionsI = 0xE106;

	HelpContext = -1;
	GameTimeOffset.hours = 0;
	vwNormalLUT();
	vwToBG();
	vwf_init_dflt();
	REG_BLDY = 0;
	LoadFrame();

	//Pokedex_RegisterPkmn(pkCharmander, REG_CAUGHT);
	//Pokedex_RegisterPkmn(pkSquirtle, 0);
	//Pokedex_RegisterPkmn(pkCaterpie, 0);
	//Pokedex_RegisterPkmn(pkWeedle, 0);
	//Pokedex_RegisterPkmn(pkSandshrew, 0);
	//openPokeDex();
	//CreateMonster(&MyParty[0],pkCharmander,20);
	//WriteCompleteDocs(&MyParty[1]);
	//SetNickname(&MyParty[1], "Pocky", 1);
	//WriteCompleteDocs(&MyParty[1]);
	//ShowStatus(&MyParty[1]);

	CheckForImports();

/** \brief Debug menu at game start */
#ifdef DEBUG
	StartupDebug();
#else
	StartupIntro();
	MainMenu();
#endif

	REG_DISPCNT = 0;

	ClearOamBak();
	ClearSpriteGFX();
	LoadSpriteColors();

	AGBPrint("Preloading time-of-day color tweens...\n");
	foo = GetTimeOfDay();
	LastTOD_R = TimeOfDayColors[foo][0];
	LastTOD_G = TimeOfDayColors[foo][1];
	LastTOD_B = TimeOfDayColors[foo][2];

	AGBPrint("Setting up player actor...\n");
	Actors[0].sprite = sprDanny+MyPlayer.gender;
	Actors[0].mx = MyPlayer.currentMapX;
	Actors[0].my = MyPlayer.currentMapY;
	Actors[0].speed = WALKSPEED;
	Actors[0].slot = 0;
	Actors[0].motor = actPlayer;
	Actors[0].direction = MyPlayer.currentFacing;
	Actors[0].isPlayer = 1;

	AGBPrint("Loading map...\n");
	mapLoad(MyPlayer.currentMap); //2);

	if(GETBIT(ScriptFlags, ISSURFING))
		StartSurfing(0);

	HandleCamera();
	mhRedraw(currentMapHeader, Actors[0].mx-7, Actors[0].my-5);
	HandleCamera();
	UpdateSprites();
	FocusCam();

	CurrentProcess = PreviousProcess = TweenProcess = 0;

	ResetDispCnt();
	FadeIn();
	REG_BLDCNT = 0;
	//DoCircle();

/*
	AGBPrintf("Generating a Roamer...\n");
	Roamers[5].species = 151;
	Roamers[5].map = 11;
	Roamers[5].hp = 100;
	Roamers[5].level = 50;
*/

	EggTimer.visible = 1;

	HelpContext = 2;

	//Check for "after" map scripts
	if(currentMapHeader->scriptB)
	{
		AGBPrintf("This map has an After script.\n");
		ScriptLoop(currentMapHeader->scriptB);
	}

	//Main loop!
	while(1)
	{
		DoVBlank();
		KeyRead();

		if(TotalFrames % 60 == 0)
		{
			TimeKeeper();
			if(!(currentLevel->tileseta->flags & 1) && GetTimeOfDay() != LastKnownTimeOfDay)
			{
				//AGBPrintf("Time of day <> last known.\n");
				LastKnownTimeOfDay = GetTimeOfDay();
				TweenProcess = TweenTimeAdjustedColors;
			}
		}
		if(TweenProcess != 0)
			TweenProcess();
		if(CurrentProcess != 0)
			CurrentProcess();
		if(	Trg & START_BUTTON	&&
			CurrentProcess == 0	&&
				(Actors[0].state == ACTSTATE_IDLE ||
				 Actors[0].state == ACTSTATE_SURF))
			DoStartMenu();
		if(Trg & A_BUTTON)
		{
			if(CurrentProcess == 0)
				FindAndRunScript();
		}
		//lets actors move around
		MotorSprites();

		if(Trg & SELECT_BUTTON)
			UseRegisteredItem();
/*
		{
			for(foo=0; foo < 0x400; foo++)
			{
				if(GETBIT(ScriptFlags,foo))
				{
					AGBPrintf("%x \n", foo);
				}
			}
		}
*/

		//if(Trg & SELECT_BUTTON) SETBIT(ScriptFlags,MAPSWITCHHACK); //KAWA - Map Switch Hack

		DetectWarps();
		AnimateSprites();	//updates actor timers and states
		AnimateTiles();		//loads new tiles
		HandleCamera();		//updates cam coords according to player and calls CamUpdate
		FocusCam();			//actually sets scroll regs according to cam coords
		UpdateSprites();	//actually places sprites
		HandleEggTimer();
	}
	return 0;
}

#ifdef DEBUG
void StartupDebug()
{
	int counter = 1;
	pal_bg_mem[0] = 0;
	LoadFrame();
	KeyRead();
	if(Cont & KEY_START)
		TestTileset();
	if(Cont & KEY_SELECT){
		sndTest();
		SoftReset();
	}
	char Mchoice = MultipleChoice(0,0,17, 21,1);

	switch(Mchoice)
	{
	case 0:		// Quick start
		CheckNoSave();
		return;
	case 1:		// Regular start
		StartupIntro();
		MainMenu();
		return;
	case 2:		// Wild battle
		CheckNoSave();
		CreateMonster(&MyParty[0],pkDitto,10);
		CreateMonster(&HisParty[0],rrand(pkTotal),5);
		//CreateMonsterInParty(25,20);
		//CreateMonster(&MyParty[1],pkTURRET,10);
		//CreateMonster(&HisParty[0],pkSKITTY,20);
		sndPlaySound(82,SOUND_NORESTART);
		Battle(0,0,0,0);
		return;
	case 3:		// Trainer battle
		CheckNoSave();
		CreateMonsterInParty(25,20);
		CreateMonsterInParty(150,20);
		CreateMonster(&HisParty[0],pkAbra,10);
		sndPlaySound(5,SOUND_NORESTART);
		Battle(1,1,1,(void*)"Great Scott!");
		break;
	case 4:		// Battle Demo
		CheckNoSave();
		StartDemo(1);
		CreateMonster(&MyParty[0],pkPidgey,10);
		CreateMonster(&HisParty[0],pkRattata,10);
		sndPlaySound(6,SOUND_NORESTART);
		Battle(0,0,0,0);
		break;
	case 5:		// FR Import Test
		CheckNoSave();
		RunTheTest();
		ShowParty(0,0);
		break;
	case 6:		// Market
		CheckNoSave();
		MyPlayer.cash += 10000;
		GiveItems(itemPotion, 4);
		GiveItem(itemTeachyTV);
		GiveItem(itemAntidote);
		GiveItem(itemZinc);
		DoStore((u16*)TestShop);
		break;
	case 7:		// RealTimeClock (RTC)
		ShowClock();
		break;
	case 8:		// Picture view
		ShowPics();
		break;
	default:
		break;
	}
	SoftReset();
}
#endif

/** \brief Handles frame counting, sound updating and debug output all in one. */
void DoVBlank()
{
	VBlankIntrWait();
	sndMain();

	TotalFrames++;
	AGBPrintFlush1Block();
	//Halt();
}

/** \brief Fades the screen in from black to regular. */
void FadeIn(void)
{
	int ii;
	REG_BLDCNT = BLD_BLACK | BLD_BD | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(ii=16; ii>=0; ii--)
	{
		DoVBlank();
		REG_BLDY = ii;
	}
}
/** \brief Fades the screen out from regular to black. */
void FadeOut(void)
{
	int blendi;
	REG_BLDCNT = BLD_BLACK | BLD_BD | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(blendi = 0; blendi <= 16; blendi++)
	{
		DoVBlank();
		REG_BLDY = blendi;
	}
	AGBPrint("Fadeout done!");
}

/** \brief Updates the input variables, handles demo input and the Help system. */
void KeyRead(void)
{
	u16 ReadData = (REG_KEYINPUT ^ 0x03ff);
	if(demo)
	{
		if(demotimer)
		{
			demotimer--;
		} else
		{
			demotimer = 100;
			democursor++;
			AGBPrintf("Demo: %d -> %x.\n", democursor, demoinput[demo-1][democursor]);
			if(demoinput[demo-1][democursor]==0xFFFF)
			{
				AGBPrintf("Demo stopped.\n");
				demo = 0;
				ReadData = 0;
				Cont = 0;
				Trg = 0;
			} else
			{
				ReadData = demoinput[demo-1][democursor];
			}
		}
	}
	if(MyPlayer.Options.buttonmode == 1)
	{
		if(ReadData & KEY_L) ReadData |= KEY_LEFT;
		if(ReadData & KEY_R) ReadData |= KEY_RIGHT;
		ReadData &= ~(KEY_L | KEY_R);
	}
	if(MyPlayer.Options.buttonmode == 2)
	{
		if(ReadData & KEY_L) ReadData |= KEY_A;
		ReadData &= ~(KEY_L | KEY_R);
	}
	Trg  = ReadData & (ReadData ^ Cont);
	Cont = ReadData;
	rndseed += Cont;
	if((MyPlayer.Options.buttonmode == 0) && (InHelpMode == 0) && ((Trg & KEY_L) || (Trg & KEY_R)))
	{
		DoHelp();
		return;
	}
}

void VBlankIntr(void)
{
	sndSync();
	DmaArrayCopy(OamBak, MEM_OAM);
	*(u16 *)INTR_CHECK_BUF |= V_BLANK_INTR_FLAG;
}

void HBlankIntr(void)
{
	//Nothing!
}

void IntrDummy(void) { ; }

/** \brief Loads the graphics for the user-specified system frame. */
void LoadFrame()
{
	CpuFastCopy(frameTiles + (0x90 * MyPlayer.Options.frame),MEM_VRAM+0x8020,0x120);
	CpuFastCopy(framePal + (16 * MyPlayer.Options.frame),MEM_PAL_BG+0x1E0,16);
}

/** \brief Short routine to construct a dialogue box. */
void BuildSpeechBox(unsigned short * m)
{
	u16* BG = (u16*)0x600FB80;
	int i;

	//AGBPrint("BuildSpeechBox: building...\n");
	for(i=0; i < 192; i++)
		BG[i] = m[i] + 16 + 0xE000;
}

/** \brief Resets the background layers to their regular (OW) state. */
void ResetBackgrounds()
{
	REG_BG0CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(0) | 31 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT;
	REG_BG1CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(1) | 29 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;
	REG_BG2CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(2) | 28 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;
	REG_BG3CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(3) | 30 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;
	ResetDispCnt();
}

/** \brief Animates the player going up the stairs and fades out. */
void GoUpStairs(u32 part, s32 delta)
{ //25042007 - made to use pointer for no good reason besides readability.
	u32 ticker=0, delayer=0;
	u8* thisPic;
	u16* targetPic;
	OamData *Player = &OamBak[LastKnownPlayerOamIndex];

	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	if(part==0)
	{
		Player->HPos += delta * 2;
		for(ticker=0; ticker<8; ticker++)
		{
			DoVBlank();

			REG_BLDY = ticker << 1;
			thisPic = (u8*)Sprites[Actors[0].sprite].spriteStart;
			targetPic = (u16*)MEM_VRAM_OBJ + (Actors[0].slot * 0x100);

			if(ticker % 4 == 0)	thisPic += 0x100*2;
			if(ticker % 4 == 1)	thisPic += 0x100*7;
			if(ticker % 4 == 2) thisPic += 0x100*2;
			if(ticker % 4 == 3)	thisPic+= 0x100*8;

			CpuFastCopy(thisPic, targetPic, 0x100);

			Player->HPos+=delta * 2;
			if(ticker % 2 == 1)
				Player->VPos -= 2;

			for(delayer=0; delayer<6; delayer++)
				DoVBlank();
		}
	}
	else
	{
		Player->HPos -= delta * 16;
		Player->VPos += 8;
		for(ticker=0; ticker<8; ticker++)
		{
			DoVBlank();

			REG_BLDY = 15 - (ticker << 1);
			thisPic = (u8*)Sprites[Actors[0].sprite].spriteStart;
			targetPic = (u16*)MEM_VRAM_OBJ + (Actors[0].slot * 0x100);
			if(ticker % 4 == 0) thisPic+= 0x100*2;
			if(ticker % 4 == 1) thisPic+= 0x100*7;
			if(ticker % 4 == 2) thisPic+= 0x100*2;
			if(ticker % 4 == 3) thisPic+= 0x100*8;
			CpuFastCopy(thisPic,targetPic,0x100);

			Player->HPos+=delta * 2;
			if(ticker % 2 == 1)
				Player->VPos -= 2;

			for(delayer=0; delayer<6; delayer++)
				DoVBlank();
		}
		Player->HPos -= delta * 4;
	}
}

/** \brief Animates the player going down the stairs. */
void GoDownStairs(u32 part, s32 delta)
{ //25042007 - made to use pointer for no good reason besides readability.
	u32 ticker=0, delayer=0;
	u8* thisPic;
	u16* targetPic;
	OamData *Player = &OamBak[LastKnownPlayerOamIndex];

	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	if(part==0)
	{
		Player->HPos += delta * 4;

		for(ticker=0; ticker<8; ticker++)
		{
			DoVBlank();

			REG_BLDY = ticker << 1;
			thisPic = (u8*)Sprites[Actors[0].sprite].spriteStart;
			targetPic = (u16*)MEM_VRAM_OBJ + (Actors[0].slot * 0x100);

			if(ticker % 4 == 0) thisPic+= 0x100*2;
			if(ticker % 4 == 1) thisPic+= 0x100*7;
			if(ticker % 4 == 2) thisPic+= 0x100*2;
			if(ticker % 4 == 3) thisPic+= 0x100*8;

			CpuFastCopy(thisPic,targetPic,0x100);

			Player->HPos += delta * 2;

			if(ticker % 2 == 1)
				Player->VPos += 2;

			for(delayer=0; delayer<6; delayer++)
				DoVBlank();
		}
	}
	else
	{
		Player->HPos += delta * 16;
		Player->VPos -= 8;
		for(ticker=0; ticker<8; ticker++)
		{
			DoVBlank();

			REG_BLDY = 15 - (ticker << 1);
			thisPic = (u8*)Sprites[Actors[0].sprite].spriteStart;
			targetPic = (u16*)MEM_VRAM_OBJ + (Actors[0].slot * 0x100);

			if(ticker % 4 == 0) thisPic+= 0x100*2;
			if(ticker % 4 == 1) thisPic+= 0x100*7;
			if(ticker % 4 == 2) thisPic+= 0x100*2;
			if(ticker % 4 == 3) thisPic+= 0x100*8;

			CpuFastCopy(thisPic,targetPic,0x100);

			Player->HPos-=delta * 2;
			if(ticker % 2 == 1)
				Player->VPos += 2;

			for(delayer=0; delayer<6; delayer++)
				DoVBlank();
		}
		Player->HPos-=delta * 2;
	}
}

/** \brief Animates the player opening the door and entering. */
void OpenDoor()
{
	//extern const u8 palletdoor_Char[32*16/8*64/8 + 0];
	//u32 timer, framer = 0;
	//u8* thisPic;
	//u16* target;
	AGBPrint("OpenDoor: not implemented yet - fading out...\n");
	FadeOut();
}

/** \brief Animates the player entering a cave. */
void EnterCave()
{
	extern const unsigned short cavewarpPal[16];
	extern const unsigned short cavewarpTiles[432];
	extern const unsigned short cavewarpMap[1024];
	int ii;
	//Should fade out to black first, then white in from all-black

	Actors[0].state = ACTSTATE_WALK;
	Actors[0].timer = 0;
	Actors[0].frameindex = 0;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(ii = 0; ii <= 16; ii++)
	{
		DoVBlank();
		UpdateSprites();
		AnimateSprites();
		REG_BLDY = ii;
	}

	DmaClear(0x00000000, MEM_PAL_BG, 256 * 4);

	REG_BLDCNT = BLD_WHITE | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	REG_BLDY = 0;
	for(ii = 0; ii <= 16; ii++)
	{
		DoVBlank();
		REG_BLDY = ii;
	}

	DmaClear(0x7FFF7FFF, MEM_PAL_BG, 256 * 4);
	DmaArrayCopy(cavewarpPal, MEM_PAL_BG);
	DmaArrayCopy(cavewarpTiles, MEM_VRAM + 0x8000);
	DmaArrayCopy(cavewarpMap, MEM_VRAM + 0xF800);

	for(ii=16; ii>=0; ii--)
	{
		DoVBlank();
		REG_BLDY = ii;
	}

	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(ii = 0; ii <= 16; ii++)
	{
		DoVBlank();
		REG_BLDY = ii;
	}

	CleanUpCrap();
	LoadSpriteColors();
}

void DropDown()
{
	OamData *Player = &OamBak[LastKnownPlayerOamIndex];
	int i;
	Player->VPos = -32;
	DoVBlank();
	FadeIn();
	for(i = -32; i <= 56; i+=8)
	{
		Player->VPos = i;
		DoVBlank();
	}
	CpuFastCopy( (u8*)Sprites[Actors[0].sprite].spriteStart + 0xD00,
	             (u16*)MEM_VRAM_OBJ + (Actors[0].slot * 0x100),
	             0x100 );
	for(i = 0; i < 100; i++)
	{
		DoVBlank();
	}
}


extern u8 gMapOfsX, gMapOfsY;

int CheckWarpCriteria(int f)
{
	if(
		((f==WARP_JUSTFADE) && (Cont)) ||
		((f==WARP_STAIRSUP) && (Cont & R_KEY)) ||
		((f==WARP_STAIRSDOWN) && (Cont & L_KEY)) ||
		((f==WARP_STAIRSUPLEFT) && (Cont & L_KEY)) ||
		((f==WARP_STAIRSDOWNRIGHT) && (Cont & R_KEY)) ||
		((f==WARP_DOORINSIDE) && (Cont & D_KEY) && (Actors[0].direction == ACTFACING_SOUTH)) ||
		((f==WARP_DOOROUTSIDE) && (Cont & U_KEY) && (Actors[0].direction == ACTFACING_NORTH)) ||
		((f==WARP_CAVEINSIDE) && (Cont & D_KEY) && (Actors[0].direction == ACTFACING_SOUTH)) ||
		((f==WARP_CAVEOUTSIDE) && (Cont & U_KEY) && (Actors[0].direction == ACTFACING_NORTH)) ||
		((f==WARP_CAVEINSIDERIGHT) && (Cont & R_KEY) && (Actors[0].direction == ACTFACING_WEST)) ||
		((f==WARP_CAVELADDERUP) && (Cont & U_KEY) && (Actors[0].direction == ACTFACING_NORTH)) ||
		((f==WARP_CAVELADDERDOWN) && (Cont & D_KEY) && (Actors[0].direction == ACTFACING_SOUTH)) ||
		((f==WARP_HOLE))
	) return 1;
	return 0;
}

void DoWarpEntryAnimation(f)
{
	switch(f)
	{
	case WARP_JUSTFADE:
	case WARP_DOORINSIDE:
	case WARP_CAVELADDERUP:
	case WARP_CAVELADDERDOWN:
	case WARP_HOLE:
		FadeOut();
		break;
	case WARP_STAIRSUP:
		GoUpStairs(0,1);
		break;
	case WARP_STAIRSDOWN:
		GoDownStairs(0,-1);
		break;
	case WARP_STAIRSUPLEFT:
		GoUpStairs(0,-1);
		break;
	case WARP_STAIRSDOWNRIGHT:
		GoDownStairs(0,1);
		break;
	case WARP_DOOROUTSIDE:
		OpenDoor();
		break;
	case WARP_CAVEINSIDE:
	case WARP_CAVEOUTSIDE:
	case WARP_CAVEINSIDERIGHT:
		EnterCave();
		break;
	}
}

void DoWarpExitAnimation(int f)
{
	switch(f)
	{
	case WARP_JUSTFADE:
	case WARP_INVALID:
	case WARP_DOORINSIDE:
	case WARP_DOOROUTSIDE:
	case WARP_CAVEINSIDE:
	case WARP_CAVEOUTSIDE:
	case WARP_CAVEINSIDERIGHT:
	case WARP_CAVELADDERUP:
	case WARP_CAVELADDERDOWN:
		FadeIn();
		break;
	case WARP_STAIRSUP:
		Actors[0].direction = ACTFACING_EAST;
		GoDownStairs(1,1);
		break;
	case WARP_STAIRSDOWN:
		Actors[0].direction = ACTFACING_EAST;
		GoUpStairs(1,1);
		break;
	case WARP_STAIRSUPLEFT:
		Actors[0].direction = ACTFACING_WEST;
		GoDownStairs(1,-1);
		break;
	case WARP_STAIRSDOWNRIGHT:
		Actors[0].direction = ACTFACING_EAST;
		GoUpStairs(1,-1);
		break;
	case WARP_HOLETARGET:
		DropDown();
		break;
	}
}

/** \brief Checks if the player stands on a warp object and teleports him to the new map if needed. */
void DetectWarps()
{
	int destWarp;
	int i, x,y;

	for(i = 0; i < currentMapHeader->events->numWarps; i++)
	{
		if ((currentMapHeader->events->warps[i].xpos == Actors[0].mx) &&
			(currentMapHeader->events->warps[i].ypos == Actors[0].my))
		{
			if((Actors[0].state == ACTSTATE_IDLE) || (Actors[0].state == ACTSTATE_WALK))
			{
				if(CheckWarpCriteria(currentMapHeader->events->warps[i].kind))
				{
					DoWarpEntryAnimation(currentMapHeader->events->warps[i].kind);

					destWarp = currentMapHeader->events->warps[i].destWarp;
					mapLoad(currentMapHeader->events->warps[i].destLevel);
					x = currentMapHeader->events->warps[destWarp].xpos;
					y = currentMapHeader->events->warps[destWarp].ypos;
					Actors[0].mx = x;
					Actors[0].my = y;
					Cont = 0;
					Trg = 0;
					TweenProcess = 0;
					Actors[0].state = ACTSTATE_IDLE;
					ClearOamBak();
					HandleCamera();
					mhRedraw(currentMapHeader, Actors[0].mx-7, Actors[0].my-5);
					HandleCamera();
					UpdateSprites();
					AnimateSprites();
					FocusCam();
					UpdateSprites();
					//Captain's Log, supplemental. It appears that calling HandleCam twice helps...

					if((currentMapHeader->ShowName == 1) && (SM_PlaceNameBox.state == 0))
					{
						if(CurrentProcess == 0) //FIX 2b
						{
							PreviousProcess = CurrentProcess;
							CurrentProcess = PlaceNameBox;
							SM_PlaceNameBox.state = 0;
							PlaceNameBox();
						}
					}
					else
					{
						if(CurrentProcess == PlaceNameBox)
						{
							REG_BG0VOFS = 0;
							CurrentProcess = PreviousProcess;
						}
					}

					DoWarpExitAnimation(currentMapHeader->events->warps[destWarp].kind);
					//Check for "after" map scripts
					if(currentMapHeader->scriptB)
					{
						AGBPrintf("This map has an After script.\n");
						ScriptLoop(currentMapHeader->scriptB);
					}
				}
			}
		}
	}
}


void HandleEggTimer()
{
	char timer[16];
	int i;
	if(EggTimer.time)
	{
		EggTimer.time--;
		if(EggTimer.visible==1)
		{
			DmaCopy(fontOamPal, MEM_PAL_OBJ + 0x1E0,16);
			DmaCopy(fontOamTiles, MEM_VRAM_OBJ + 0x6400, 0x1000);
			EggTimer.visible = 2;
		}
		if(EggTimer.visible==2)
		{
			sprintf(timer,"%2d:%02d",EggTimer.time/60,EggTimer.time%60);
			for(i = 0; i < 5; i++)
			{
				OamBak[120+i].CharNo = 864 + ((timer[i]-'0')*4);
				OamBak[120+i].HPos = 4 + (i*12);
				OamBak[120+i].VPos = 4;
				OamBak[120+i].Shape = 0;
				OamBak[120+i].Size = 1;
				OamBak[120+i].Pltt = 15;
			}
			OamBak[122].HPos+=2;
		}
		if(EggTimer.visible && EggTimer.time == 160)
		{
			DmaCopy(fontOamPal+8, MEM_PAL_OBJ + 0x1E0,16);
		}
		if(EggTimer.time == 0)
		{
			ScriptLoop(EggTimer.target);
		}
	}
}

_SM_Dialoguebox SM_Dialoguebox;
extern const unsigned short morearrowTiles[32];
extern u8 textnormalLUT[4];

const unsigned short * const boxTiles[] = { speechboxTiles, signboxTiles, speechboxTiles };
const unsigned short * const boxPals[] = { speechboxPal, signboxPal, speechboxPal };
const unsigned short * const boxMaps[] = { speechboxMap, signboxMap, speechboxMap };

void DialogueBox_ParseSpecial()
{
	SM_Dialoguebox.scursor++;
	int sp = SM_Dialoguebox.source[SM_Dialoguebox.scursor++];
	int sp2;
	switch(sp)
	{
	case TCC_SPEC_INK:
		vwf_set_color(TEXT_INK, SM_Dialoguebox.source[SM_Dialoguebox.scursor]);
		break;
	case TCC_SPEC_PAPER:
		vwf_set_color(TEXT_PAPER, SM_Dialoguebox.source[SM_Dialoguebox.scursor]);
		break;
	case TCC_SPEC_SHADOW:
		vwf_set_color(TEXT_SHADOW, SM_Dialoguebox.source[SM_Dialoguebox.scursor]);
		break;
	case TCC_SPEC_COLOR:
		vwf_set_color(TEXT_INK, SM_Dialoguebox.source[SM_Dialoguebox.scursor++]);
		vwf_set_color(TEXT_PAPER, SM_Dialoguebox.source[SM_Dialoguebox.scursor]);
		break;
	case TCC_SPEC_FONT:
		sp = SM_Dialoguebox.source[SM_Dialoguebox.scursor];
		if(sp == 0)
			vw_SetSmall(); //VWF_SET_FONT(fontSmall);
		else
			vw_SetBig(); //VWF_SET_FONT(fontWestern);
		break;
	case TCC_SPEC_WAIT:
		sp = SM_Dialoguebox.source[SM_Dialoguebox.scursor];
		SM_Dialoguebox.timer = sp;
		SM_Dialoguebox.state = 8;
		break;
	case TCC_SPEC_SONG:
		sp = SM_Dialoguebox.source[SM_Dialoguebox.scursor++];
		sp2 = sp;
		sp = SM_Dialoguebox.source[SM_Dialoguebox.scursor];
		sp2 = (sp << 8) + sp2;
		sndPlaySound(sp2,SOUND_NORESTART);
		break;
	case TCC_SPEC_SONG_PAUSE:
		sndPauseSound();
		break;
	case TCC_SPEC_SONG_RESUME:
		sndResumeSound();
		break;
	}
}

void DialogueBox_ParseControl()
{
	Trg = 0;
	if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == '\n')
		SM_Dialoguebox.state = 2; //scroll a line
	if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == '\f')
		SM_Dialoguebox.state = 3; //start from blank
	if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == '\r')
		SM_Dialoguebox.state = 4; //wait for a key
	if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == '\0')
		SM_Dialoguebox.state = 7;
	//	SM_Dialoguebox.state = 5; //wait and stop
	if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == '\1')
	{
		SM_Dialoguebox.OneUp = 1;
		SM_Dialoguebox.state = 7; //stop but don't clean up
	}
}

void DialogueBox_ParseCharacter()
{
	TVwf *vwf= gp_vwf;
	SM_Dialoguebox.linenow[SM_Dialoguebox.tcursor] = SM_Dialoguebox.source[SM_Dialoguebox.scursor];
	SM_Dialoguebox.tcursor++;
	//To fix the help issue, we could mirror vwf->dstX/Y here...
	vwf->putc_(SM_Dialoguebox.source[SM_Dialoguebox.scursor]);

	if(MyPlayer.Options.textspeed < 2)
	{
		SM_Dialoguebox.state = 8;
		SM_Dialoguebox.timer = (2-MyPlayer.Options.textspeed) * TEXTWRITEMULTIPLIER;
	}
}

/** \brief Subprocess. Handles the display of messages from signs and NPCs and such.
		\todo Make this not mess up when Help is displayed.
*/
void DialogueBox()
{
	u16* sourceT;
	u16* sourceP;
	TVwf *vwf= gp_vwf;
	// int sp;
	// int sp2;
	if(SM_Dialoguebox.state == 0) //init
	{
		SM_Dialoguebox.source = TextBuffer;
		SM_Dialoguebox.linenow = (char*)&DialogueBoxBuffer;
		memset((char*)&DialogueBoxBuffer, ' ', sizeof(DialogueBoxBuffer));
		SM_Dialoguebox.scursor = 0;
		SM_Dialoguebox.tcursor = 0;
		SM_Dialoguebox.linewereon = 0;
		SM_Dialoguebox.OneUp = 0;
		if(SM_Dialoguebox.style < 99)
		{
			sourceT = (u16*)boxTiles[SM_Dialoguebox.style];
			sourceP = (u16*)boxPals[SM_Dialoguebox.style];
			DmaCopy(sourceT, MEM_VRAM + 0x8200, 0x100);
			DmaCopy(sourceP, MEM_PAL_BG + 0x1C0, 0x20 );
			BuildSpeechBox((unsigned short*)boxMaps[SM_Dialoguebox.style]);
			vwSetLine(2,26,15,96,14);
			vwSetLine(2,26,17,160,14);
		}
		vwClearLine(1,0);
		vwClearLine(1,1);
		vwClearLine(1,4);
		vwClearLine(1,5);
		vwNormalLUT();
		vwf->dstX = vwf->dstY = 0;
		SM_Dialoguebox.state = 1;
		DmaArrayCopy(morearrowTiles, MEM_VRAM_OBJ + 0x7FC0);

		OamBak[127].CharNo = 1022;
		OamBak[127].Pltt = 4;
		OamBak[127].Size = 0;
		OamBak[127].Shape = 1;
		OamBak[127].HPos = 210;
		OamBak[127].VPos = 172;

		REG_BG0VOFS = 0;
	}

	if(SM_Dialoguebox.state == 1) //run a line
	{
		if(MyPlayer.Options.textspeed == 3) //zoom mode?
		{
			while(SM_Dialoguebox.state == 1)
			{
				if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == TCC_SPECIAL)
					DialogueBox_ParseSpecial();
				else if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] < ' ')
					DialogueBox_ParseControl();
				else
					DialogueBox_ParseCharacter();
				SM_Dialoguebox.scursor++;
			}
		}
		else
		{
			if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == TCC_SPECIAL)
				DialogueBox_ParseSpecial();
			else if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] < ' ')
				DialogueBox_ParseControl();
			else
				DialogueBox_ParseCharacter();
			SM_Dialoguebox.scursor++;
		}
	}

	if(SM_Dialoguebox.state == 2) //scroll a line
	{
		if(SM_Dialoguebox.linewereon==0)
		{
			SM_Dialoguebox.linewereon=1;
		}
		else
		{
			vwClearLine(1,0);
			vwClearLine(1,1);
			vwClearLine(1,4);
			vwClearLine(1,5);
			vwWriteG(0,0,SM_Dialoguebox.linenow); //cruft alert!
		}
		vwf->dstY = 16;
		vwf->dstX = 0;
		//memset((char*)&DialogueBoxBuffer, ' ', sizeof(DialogueBoxBuffer));
		sprintf(SM_Dialoguebox.linenow,"                                               ");
		SM_Dialoguebox.tcursor = 0;
		SM_Dialoguebox.state = 1;
	}

	if(SM_Dialoguebox.state == 3) //start from blank
	{
		vwClearLine(1,0);
		vwClearLine(1,1);
		vwClearLine(1,4);
		vwClearLine(1,5);
		SM_Dialoguebox.linewereon = 0;
		SM_Dialoguebox.tcursor = 0;
		SM_Dialoguebox.state = 1;
		sprintf(SM_Dialoguebox.linenow,"                                               ");
		vwf->dstX = vwf->dstY = 0;
	}

	if(SM_Dialoguebox.state == 4) //wait for a key
	{
		OamBak[127].HPos = 20 + vwf->dstX;
		OamBak[127].VPos = 124 + (SM_Dialoguebox.blinker>>3) + vwf->dstY;
		SM_Dialoguebox.blinker++;
		if(SM_Dialoguebox.blinker == 32)
			SM_Dialoguebox.blinker = 0;
		if(Trg & A_BUTTON || Trg & B_BUTTON)
		{
			Trg = 0;
			sndCursor();
			OamBak[127].VPos = 170;
			SM_Dialoguebox.state = 1;
		}
	}

	if(SM_Dialoguebox.state == 5) //wait and stop
	{
		//if(SM_Dialoguebox.style == 2)
		//{
		//	//ScriptMemory[SM_LASTRESULT] = !(u8)SimpleYesNoLoop();
		//	ScriptVar_800D = !(u8)SimpleYesNoLoop();
		//	SM_Dialoguebox.state = 6;
		//}
		//else
		//{
			if(Trg & A_BUTTON || Trg & B_BUTTON)
			{
				Trg = 0;
				sndCursor();
				SM_Dialoguebox.state = 6;
			}
		//}
	}

	if(SM_Dialoguebox.state == 6) //destroy
	{
		ClearDialogueBox();
		SM_Dialoguebox.state = 7;
		CurrentProcess = PreviousProcess;
		if(CurrentProcess == DialogueBox) CurrentProcess = 0; //just in case...
		Trg = 0;
	}

	if(SM_Dialoguebox.state == 7) //just idle
	{
		//Woooop!
	}

	if(SM_Dialoguebox.state == 8) //writing delay
	{
		if(SM_Dialoguebox.timer == 0)
			SM_Dialoguebox.state = 1;
		else
			SM_Dialoguebox.timer--;
	}
}

_SM_PlaceNameBox SM_PlaceNameBox;
/** \brief Subprocess. Handles the little box in the corner that pops up when you enter an area.
		\todo Make it faster.
*/
void PlaceNameBox()
{
	u32 i;
	if(SM_PlaceNameBox.state == 0) //init
	{
		REG_BG0VOFS = -24;
		vwClearLine(1, 0);
		vwWrite(4, 2, (char*)MapNames[currentMapHeader->NameIndex]);
		CpuFastArrayCopy(uiframeTiles, MEM_VRAM+0x8140);
		CpuFastArrayCopy(uiframePal, MEM_PAL_BG+0x1C0);

		BG0MAP[0x380] = 0xE00A;
		BG0MAP[0x38F] = 0xE00C;
		BG0MAP[0x3A0] = 0xE00D;
		BG0MAP[0x3AF] = 0xE00F;
		BG0MAP[0x3C0] = 0xE00D;
		BG0MAP[0x3CF] = 0xE00F;
		BG0MAP[0x3E0] = 0xE010;
		BG0MAP[0x3EF] = 0xE012;
		for(i=0x381; i < 0x38F; i++)
			BG0MAP[i] = 0xE00B;
		for(i=0x3E1; i < 0x3EF; i++)
			BG0MAP[i] = 0xE011;

		vwSetLine(1,14,29,96,0xE);
		SM_PlaceNameBox.timer = 0;
		SM_PlaceNameBox.state = 1;
	}
	if(SM_PlaceNameBox.state == 1) //delay
	{
		SM_PlaceNameBox.timer++;
		if(SM_PlaceNameBox.timer > PLACENAMEDELAY)
		{
			SM_PlaceNameBox.timer = 0;
			SM_PlaceNameBox.state = 2;
		}
	}
	if(SM_PlaceNameBox.state == 2) //disappear
	{
		REG_BG0VOFS = -24 + SM_PlaceNameBox.timer;
		SM_PlaceNameBox.timer++;
		if(SM_PlaceNameBox.timer == 25)
		{
			SM_PlaceNameBox.state = 3;
			CurrentProcess = PreviousProcess;
			//if(CurrentProcess == PlaceNameBox) CurrentProcess = 0; //FIX CHOICE 1
		}
	}
	if(SM_PlaceNameBox.state == 4) //appear
	{
		REG_BG0VOFS = 0 - SM_PlaceNameBox.timer;
		SM_PlaceNameBox.timer++;
		if(SM_PlaceNameBox.timer == 25)
		{
			SM_PlaceNameBox.timer = 0;
			SM_PlaceNameBox.state = 1;
		}
	}
}

//Edited, somewhat simpler version of DialogueBox to display Braille messages.
//They're in a 16x16 font and only a single line, A-Z and space. No controls.
void BrailleBox()
{
	TVwf *vwf= gp_vwf;
	if(SM_Dialoguebox.state == 0) //init
	{
		SM_Dialoguebox.source = TextBuffer;
		SM_Dialoguebox.linenow = (char*)DialogueBoxBuffer;
		sprintf(SM_Dialoguebox.linenow,"                                               ");
		SM_Dialoguebox.scursor = 0;
		SM_Dialoguebox.tcursor = 0;
		SM_Dialoguebox.linewereon = 0;
		DmaCopy(signboxTiles, MEM_VRAM + 0x8200, 0x100);
		DmaCopy(signboxPal, MEM_PAL_BG + 0x1C0, 0x20 );
		BuildSpeechBox((unsigned short*)signboxMap);
		vwSetLine(2,26,15,96,14);
		vwClearLine(1,0);
		vwClearLine(1,1);
		vwNormalLUT();
		vwf->dstX = vwf->dstY = 0;
		SM_Dialoguebox.state = 1;

		REG_BG0VOFS = 0;
	}

	if(SM_Dialoguebox.state == 1) //run a line
	{
		if(SM_Dialoguebox.source[SM_Dialoguebox.scursor] == '\0')
			SM_Dialoguebox.state = 5; //wait and stop
		else
		{
			SM_Dialoguebox.linenow[SM_Dialoguebox.tcursor] =
				SM_Dialoguebox.source[SM_Dialoguebox.scursor];
			SM_Dialoguebox.tcursor++;
			vw_DrawBraille(SM_Dialoguebox.source[SM_Dialoguebox.scursor]);

			//if(MyOptions.textspeed != 2)
			//{
			//	SM_Dialoguebox.state = 8;
			//	SM_Dialoguebox.timer = 20;
			//}
		}
		SM_Dialoguebox.scursor++;
	}
	if(SM_Dialoguebox.state == 5) //wait and stop
	{
		//if(SM_Dialoguebox.style == 2)
		//{
		//	//ScriptMemory[SM_LASTRESULT] = !(u8)SimpleYesNoLoop();
		//	ScriptVar_800D = !(u8)SimpleYesNoLoop();
		//	SM_Dialoguebox.state = 6;
		//}
		//else
		//{
			if(Trg & A_BUTTON || Trg & B_BUTTON)
			{
				Trg = 0;
				sndCursor();
				SM_Dialoguebox.state = 6;
			}
		//}
	}
	if(SM_Dialoguebox.state == 6) //destroy
	{
		ClearDialogueBox();
		SM_Dialoguebox.state = 7;
		CurrentProcess = PreviousProcess;
		Trg = 0;
	}

	if(SM_Dialoguebox.state == 7) //just idle
	{
		//Woooop!
	}
	if(SM_Dialoguebox.state == 8) //writing delay
	{
		if(SM_Dialoguebox.timer == 0)
			SM_Dialoguebox.state = 1;
		else
			SM_Dialoguebox.timer--;
	}
}


/** \brief Clears the player's state and belongings, then rolls a new ID.
		\param name Name of the new player
		\param gender Boy or girl?
*/
void SetNewPlayer(char *name, int gender)
{
	u16 settings = MyPlayer.OptionsI;
	memset((char*)&MyPlayer, 0, sizeof(MyPlayer));
	memset((char*)&inventory, 0, sizeof(inventory));
	memset((char*)&ScriptFlags, 0, sizeof(ScriptFlags));
	//memset((char*)&ScriptMemory, 0, sizeof(ScriptMemory));
	memset((char*)&ScriptVars, 0, sizeof(ScriptVars));
	memset((char*)&MyParty, 0, sizeof(MyParty));
	memset((char*)&MyBox, 0, sizeof(MyBox));
	memset((char*)&MyBattles, 0, sizeof(MyBattles));
	memset((char*)&MyDex, 0, sizeof(MyDex));
	MyPlayer.OptionsI = settings;

	int i;
	extern char boxnames[14][10];
	extern char boxwalls[14];
	for(i=0; i<14;i++)
	{
		sprintf(boxnames[i],"BOX %d",i+1);
		boxwalls[i] = i % 8;
	}

	sprintf(PlayerName,name);
	MyPlayer.gender = gender;
	srand(TotalFrames);
	MyPlayer.trainerid = rand();
	MyPlayer.cash = 2000;
	MyPlayer.currentMap = 22;
	MyPlayer.currentMapX = 1;
	MyPlayer.currentMapY = 7;
#ifdef WITH_SHIRTCOLORS
	MyPlayer.shirtColor = gender ? 0 : 2;
#endif

	GiveItem(itemTownMap);
}

/** \brief Sets up the screen for the main menu. */
void SetUpMainMenu(u32 selection)
{
	*(u16*)MEM_PAL = 0x41AE; //0x7E51;
	REG_BG0VOFS = 0;
	REG_DISPCNT =  DCNT_MODE0 | DCNT_BG0 | DCNT_WIN0;
	REG_BLDCNT = BLD_BLACK | BLD_BG0;
	REG_BLDALPHA = 0x0000;//0x0010;
	REG_BLDY = 0x0004;
	REG_WIN0H = (16<<8) + (16*8);
	REG_WIN0V = ((8 + (selection * 16)) << 8) + (8+15 + (selection * 16));
	REG_WININ = 0x0011; //WIN_BG0_ON;
	REG_WINOUT = 0x0031; //WIN_BLEND_ON | WIN_BG0_ON | WIN_BG1_ON | WIN_BG2_ON;
	REG_WIN1H = 0;
	REG_WIN1V = 0;
}

/** \brief Displays the main menu. Also does savegame checks and such. */
void MainMenu()
{
	u32 selection = 0, numchoices = 2, continueavailable = 0;
	u16 savedcheck, check; //25042007 - was set to u32 by Cearn, broke checks
	PlayerData saveddata;
	char foo[32];

	REG_DISPCNT = 0;

	//Konami Code
	int konamiCode[] = { KEY_UP, KEY_UP, KEY_DOWN, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_LEFT, KEY_RIGHT, B_BUTTON, A_BUTTON, 0xFF };
	int konamiCursor = 0;

	LoadFrame();

	//AGBPrint("MainMenu: checking for RTC...\n");
	extern int haveRTC;
	if(!haveRTC)
	{
		*(u16*)MEM_PAL = 0x00AE;
		ResetDispCnt();
		FadeIn();
		sayf(SYSTEM,strMainClockDry);
		FadeOut();
	}

	bytecpy(&savedcheck, SRAM, sizeof(check));
	AGBPrintf("MainMenu: savedcheck is %x.\n", savedcheck);
	bytecpy(&saveddata, SRAM + sizeof(check), sizeof(saveddata));
	check = GetChecksum(&saveddata, sizeof(saveddata));
	AGBPrintf("MainMenu: expected checksum is %x.\n", check);
	if(savedcheck == 0xFFFF)
	{
		//AGBPrint("MainMenu: no savegame\n");
	} else if((savedcheck) && (savedcheck != check))
	{
		*(u16*)0x05000000 = 0x00AE;
		ResetDispCnt();
		FadeIn();
		sayf(SYSTEM,strMainSaveLost);
		FadeOut();
	}
	if((savedcheck) && (savedcheck == check))
		continueavailable = 1;

	if(continueavailable)
		numchoices++;

Draw:
	CleanUpCrap();
	LoadFrame();
	DrawFrame(1,16,0,2+(numchoices*2));
	vwClear(1);

	if(!continueavailable)
	{
		//AGBPrint("MainMenu: new game / options...\n");
		vwWrite(4,0,strMainMenuNewGame); vwSetLine(2,14,1,96,15);
		vwWrite(4,16,strMainMenuOptions);	vwSetLine(2,14,3,160,15);
	}
	else
	{
		//AGBPrint("MainMenu: continue / new game / options...\n");

		vwWrite(4,0,strMainMenuContinue); vwSetLine(2,14,1,96,15);
		vwWrite(4,16,strMainMenuNewGame); vwSetLine(2,14,3,160,15);
		vwWrite(4,32,strMainMenuOptions); vwSetLine(2,14,5,224,15);

		DrawFrame(1,16,11,9);
		vwWrite(4,48,strMainMenuPlayer);
		vwWrite(64,48,MyPlayer.name);
		vwWrite(4,62,strMainMenuPokedex);
		sprintf(foo,"%d",MyDex.caughtrate);
		vwWrite(64,62,foo);
		vwWrite(4,76,strMainMenuBadges);
		sprintf(foo,"%d",0);
		vwWrite(64,76,foo);
		vwWrite(4,90,strMainMenuTime);
		sprintf(foo,"%d:%d", MyPlayer.Hours, MyPlayer.Minutes);
		vwWrite(64,90,foo);
		vwSetLine(2,14,12,288,15);
		vwSetLine(2,14,14,352,15);
		vwSetLine(2,14,16,416,15);
		vwSetLine(2,14,17,448,15);
	}


	SetUpMainMenu(selection);

	while(1)
	{
		DoVBlank();
		KeyRead();
		//Handle Konami Code
		if(Trg)
		{
			if(Trg == konamiCode[konamiCursor])
			{
				konamiCursor++;
				if(konamiCode[konamiCursor] == 0xFF) //finished
				{
					sndPlayFanfare(131);
					//Gifts here:
					GiveItem(itemMasterBall);
				}
			} else
			{
				konamiCursor=0;
			}
		}

		selection = wrap(selection + key_tri_vert(), 0, numchoices);

		if(Trg)
		{
			SetUpMainMenu(selection);
			sndCursor();
		}
		if(Trg & A_BUTTON)
		{
			ClearFrame(0,30,0,20);
			REG_DISPCNT = 0;
			REG_BLDY = 16;

			if((selection == 0) && (!continueavailable)) //NEW GAME / options
			{
				OpeningLetter();
				Welcome();
				return;
			}
			else if((selection == 0) && (continueavailable)) //CONTINUE / new game / options
			{
				return;
			}
			else if((selection == 1) && (!continueavailable)) //new game / OPTIONS
			{
				Options();
				goto Draw;
			}
			else if((selection == 1) && (continueavailable)) //continue / NEW GAME / options
			{
				OpeningLetter();
				Welcome();
				return;
			}
			else if(selection == 2) //continue / new game / OPTIONS
			{
				Options();
				goto Draw;
			}
		}
	}
}






// Spinner animation that appears, when
// the players saves the game
extern const unsigned short spinnerPal[16];
extern const unsigned short spinnerTiles[512];
void Spinner()
{
	static int spinframe = 0;
	DmaArrayCopy(spinnerPal, MEM_PAL_OBJ + 0x1E0);
	DmaArrayCopy(spinnerTiles, MEM_VRAM_OBJ + 0x7c00);
	OamBak[127].CharNo = 992 + ((spinframe>>2) * 4);
	OamBak[127].Pltt = 15;
	OamBak[127].Size = 1;
	OamBak[127].Shape = 0;
	OamBak[127].HPos = 200;
	OamBak[127].VPos = 128;
	spinframe++;
	if(spinframe == 32) spinframe=0;
}
void RemoveSpinner()
{
	OamBak[127].VPos = 170;
}

/** \brief Copies words from one place to another.
		\param length Number of words, not bytes!
*/
void memcopy(void *in_dst, const void *in_src, unsigned int length)
{
	int *src = (int *)in_src;
	int *dst = (int *)in_dst;

	//AGBPrintf("memcopy: from %x to %x\n", &in_src, &in_dst);

	for(; length > 0; length--)
		*dst++ = *src++;
}

/** \brief Copies bytes from one place to another. Only good for SRAM. */
void bytecpy(void *in_dst, const void *in_src, unsigned int length)
{
	unsigned char *src = (unsigned char *)in_src;
	unsigned char *dst = (unsigned char *)in_dst;

	for(; length > 0; length--)
		*dst++ = *src++;
}

/** \brief Clears bytes. Only good for SRAM. */
void byteclr(void *in_dst, unsigned int length)
{
	unsigned char *dst = (unsigned char *)in_dst;

	for(; length > 0; length--)
		*dst++ = 0xFF;
}

/** \brief Compares bytes from one place to another. Only good for SRAM. */
int byteverify(void *in_dst, const void *in_src, unsigned int length)
{
	unsigned char *src = (unsigned char *)in_src;
	unsigned char *dst = (unsigned char *)in_dst;
	u16 tix = 0;

	Spinner();
	DoVBlank();

	for(; length > 0; length--)
	{
		tix++;
		if(tix == 750)
		{
			tix = 0;
			Spinner();
			DoVBlank();
		}
		if(*dst++ != *src++) return 1;
	}
	return 0;
}

/** \brief Bytecopies stuff, verifies it and gives an error if it's not saved right.
		\param wut A short description of the thing being saved like "Inventory".
*/
int SaveSomething(u32 in_dst, const void *in_src, unsigned int length, const char *wut)
{
	bytecpy(SRAM + in_dst, in_src, length);
	//AGBPrintf("Verifying %s...\n", wut);
	if(byteverify(SRAM + in_dst, in_src, length))
	{
		ColorAdjust((u16*)MEM_PAL_BG, (u16*)MEM_PAL_BG, 100,256,128,128);
		sayf(SYSTEM,strSaveError, wut);
		return 1;
	}
	return 0;
}

/** \brief Calculates the bytewise checksum for a piece of saved data. */
int GetChecksum(void *in_src, int length)
{
	unsigned char *src = (unsigned char *)in_src;
	u16 check = 0;
	for(; length > 0; length--)	check += *src++;
	return check;
}

/** \brief Loads the saved game from SRAM to work RAM. */
void LoadGame()
{
	//AGBPrint("LoadGame: loading...\n");

	bytecpy(&MyPlayer,
					SRAM + sizeof(u16), sizeof(MyPlayer));
	bytecpy(&MyDex,
					SRAM + sizeof(u16)+sizeof(MyPlayer),
					sizeof(MyDex));
	bytecpy(&MyParty,
					SRAM + sizeof(u16)+sizeof(MyPlayer)+
					sizeof(MyDex),
					sizeof(MyParty));
	bytecpy(&inventory,
					SRAM + sizeof(u16)+sizeof(MyPlayer)+
					sizeof(MyDex)+sizeof(MyParty),
					sizeof(inventory));
	bytecpy(&ScriptFlags,
					SRAM + sizeof(u16)+sizeof(MyPlayer)+
					sizeof(MyDex)+sizeof(MyParty)+sizeof(inventory),
					sizeof(ScriptFlags));
	bytecpy(&ScriptVars,
					SRAM + sizeof(u16)+sizeof(MyPlayer)+
					sizeof(MyDex)+sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags),
					sizeof(ScriptVars));
	bytecpy(&MyBattles,
					SRAM + sizeof(u16)+sizeof(MyPlayer)+
					sizeof(MyDex)+sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags)+
					sizeof(ScriptVars),
					sizeof(MyBattles));
	bytecpy(&MyBox,
					SRAM + sizeof(u16)+sizeof(MyPlayer)+
					sizeof(MyDex)+sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags)+
					sizeof(ScriptVars)+sizeof(MyBattles),
					sizeof(MyBox));
	bytecpy(&ApartmentItems,
					SRAM + sizeof(u16)+sizeof(MyPlayer)+
					sizeof(MyDex)+sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags)+
					sizeof(ScriptVars)+sizeof(MyBattles)+sizeof(MyBox),
					sizeof(ApartmentItems));
//	if((MyPlayer.gender = 0xFFFF) && (MyPlayer.trainerid == 0xFFFF) && (MyPlayer.secretid == 0xFFFF))
//	{
//		sayf(SYSTEM, "SRAM was inited to 0xFF. Clearing data...");
//		DmaClear(0, &MyPlayer, sizeof(MyPlayer));
//		DmaClear(0, &MyDex, sizeof(MyDex));
//		DmaClear(0, &MyParty, sizeof(MyParty));
//		DmaClear(0, &inventory, sizeof(inventory));
//		DmaClear(0, &ScriptFlags, sizeof(ScriptFlags));
//		DmaClear(0, &ScriptMemory, sizeof(ScriptMemory));
//		DmaClear(0, &MyBox, sizeof(MyBox));
//	}
}

/** \brief Saves the current game, including verification. */
void SaveGame()
{
	u16 check;
	bytecpy(&check, SRAM, sizeof(check));

	//stats window
	sayf(SYSTEM,strWantToSave);
	if(SimpleYesNoLoop())
	{
		ClearDialogueBox();
		return;
	}

	if(check == 0xFFFF)
	{
		//AGBPrint("SaveGame: no savegame yet.\n");
	}
	else
	{
		//AGBPrintf("SaveGame: checksum found: %x\n", check);
		sayf(SYSTEM, strStillWantToSave);
		if(SimpleYesNoLoop())
		{
			ClearDialogueBox();
			return;
		}
	}
	sayf(SYSTEM,strSaving);
	check = GetChecksum(&MyPlayer, sizeof(MyPlayer));
	//AGBPrintf("SaveGame: checksum for playerdata is %x.\n", check);
	bytecpy(SRAM, &check, sizeof(check));

	if(SaveSomething(sizeof(check),
										&MyPlayer,sizeof(MyPlayer),"Player data")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer),
										&MyDex,sizeof(MyDex),"Pokédex data")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer)+sizeof(MyDex),
										&MyParty,sizeof(MyParty),"Party data")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer)+sizeof(MyDex)+
										sizeof(MyParty),
										&inventory,sizeof(inventory),"Inventory")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer)+sizeof(MyDex)+
										sizeof(MyParty)+sizeof(inventory),
										&ScriptFlags,sizeof(ScriptFlags),"Script flags")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer)+sizeof(MyDex)+
										sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags),
										&ScriptVars,sizeof(ScriptVars),"Script variables")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer)+sizeof(MyDex)+
										sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags)+sizeof(ScriptVars),
										&MyBattles,sizeof(MyBattles),"Trainer defeats")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer)+sizeof(MyDex)+
										sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags)+sizeof(ScriptVars)+
										sizeof(MyBattles),
										&MyBox,sizeof(MyBox),"Box data")) return;
	if(SaveSomething(sizeof(check)+sizeof(MyPlayer)+sizeof(MyDex)+
										sizeof(MyParty)+sizeof(inventory)+sizeof(ScriptFlags)+sizeof(ScriptVars)+
										sizeof(MyBattles)+sizeof(MyBox),
										&ApartmentItems,sizeof(ApartmentItems),"Apartment data")) return;
	sayf(SYSTEM,strSaved);
}

//int GetTimeOfDayHack = 0;

/** \brief Returns the time of day. */
int GetTimeOfDay()
{
	//return GetTimeOfDayHack;

	RTCTime myTime;
	RTC_GetTime(&myTime);

	if((myTime.hours > 6) && (myTime.hours < 17))
		return 0; //afternoon
	if((myTime.hours > 16) && (myTime.hours < 21))
		return 1; //evening
	if((myTime.hours > 20) || (myTime.hours < 3))
		return 2; //night
	if((myTime.hours > 2) && (myTime.hours < 7))
		return 3; //morning

	return 0;
}

/** \brief Copies colors from one place to another, but with the individual RGB intensities changed.
		\author J Vijn
*/
void ColorAdjust(u16 *dst, u16 *src, int nclrs, u32 mr, u32 mg, u32 mb)
{
	int ii;
	u32 r, g, b;
	for(ii=0; ii<nclrs; ii++)
	{
		r= (src[ii]     & 31)*mr>>8;
		g= (src[ii]>> 5 & 31)*mg>>8;
		b= (src[ii]>>10 & 31)*mb>>8;
		dst[ii]= RGB15(r, g, b);
	}
}

/** \brief Copies colors from one place to another, using ColorAdjust and GetTimeOfDay to get day/night effects. */
void LoadTimeAdjustedColors(u16 *dst, u16 *src, int nclrs)
{
	int i = GetTimeOfDay();
//	u32 r = 256, g = 256, b = 256;
//	switch(GetTimeOfDay())
//	{
//		case 0: r = 256; g = 256; b = 256; break; //afternoon
//		case 1: r = 256; g = 180; b = 180; break; //evening
//		case 2: r = 144; g = 144; b = 192; break; //night
//		case 3: r = 218; g = 218; b = 180; break; //morning
//	}
	ColorAdjust(dst, src, nclrs, TimeOfDayColors[i][0],TimeOfDayColors[i][1],TimeOfDayColors[i][2]);
}

void TweenTimeAdjustedColors()
{
	u16 *src = currentLevel->tileseta->colordata;
	if(currentLevel->tilesetb)
		src = currentLevel->tilesetb->colordata;
	int NewTOD = GetTimeOfDay();

	//AGBPrintf("%d %d %d --> %d %d %d\n", LastTOD_R, LastTOD_G, LastTOD_B, TimeOfDayColors[NewTOD][0], TimeOfDayColors[NewTOD][1], TimeOfDayColors[NewTOD][2]);

	if(LastTOD_R < TimeOfDayColors[NewTOD][0])
		LastTOD_R++;
	else if(LastTOD_R > TimeOfDayColors[NewTOD][0])
		LastTOD_R--;

	if(LastTOD_G < TimeOfDayColors[NewTOD][1])
		LastTOD_G++;
	else if(LastTOD_G > TimeOfDayColors[NewTOD][1])
		LastTOD_G--;

	if(LastTOD_B < TimeOfDayColors[NewTOD][2])
		LastTOD_B++;
	else if(LastTOD_B > TimeOfDayColors[NewTOD][2])
		LastTOD_B--;

	ColorAdjust(MEM_PAL_BG, src, 256-32, LastTOD_R, LastTOD_G, LastTOD_B);

	if(LastTOD_R == TimeOfDayColors[NewTOD][0] &&
		 LastTOD_G == TimeOfDayColors[NewTOD][1] &&
		 LastTOD_B == TimeOfDayColors[NewTOD][2] )
	{
		//AGBPrintf("Done tweening.\n");
		//LastKnownTimeOfDay == NewTOD;
		TweenProcess = 0;
	}
}

void LoadLightmap(u16 *dst, u8 *src)
{
	const unsigned short LightColor = 0x3B1F;
	if(GetTimeOfDay() % 2 == 1) return;
	int i,s,e,j;
	AGBPrintf("LoadLightmap: %d strip(s)\n",src[0]);
	for(i = 0; i < src[0]; i++)
	{
		s = src[1+(i*2)];
		e = src[2+(i*2)];
		AGBPrintf("LoadLightmap: strip %d, %d to %d\n",i,s,e);
		for(j = s; j <= e; j++)
			dst[j] = LightColor;
	}
}

/** \brief Displays a list of choices and returns the chosen item's index. */
// Params:
	// left:	x-Coordiante
	// top:		y-Coordinate
	// width:	width of the MC-Box
	// choices:	index of predefined values
	// bcancel:	can the B_BUTTON be pressed to cancel?
int MultipleChoice(int left, int top, int width, int choices, int bcancel) //CHOICELIST choices)
{
	int i,j,k,l,c=0;
	char expanso[128];
	extern const char * Choices[];
	AnOptionsSet * set = (AnOptionsSet*)&ChoiceSets[choices];

	//AGBPrint("MultipleChoice: initializing...\n");
	DrawFrame(left, width, top, (set->NumChoices*2)+2); //(choices.numchoices*2)+2);
	j = 9;
	k = 386;
	l = 18;

	for(i=0; i < set->NumChoices; i++) //choices.numchoices; i++)
	{
		vwClearLine(1, l);
		SetText(expanso, (char*)Choices[set->Options[i]]); //(char*)choices.choices[i]);
		vwWriteG(2, j, expanso);

		vwSetLine(left+2, width-3, top+1+(i*2), k, 15);
		l +=  4;
		j +=  2;
		k += 64;
	}

	vwWriteG(0,9,strArrow);
	vwSetLine(left+1,1,top+1,384,15);
	//AGBPrintf("MultipleChoice: loop starts with %d items.\n",choices.numchoices);

	while(1)
	{
		DoVBlank();

		KeyRead();
		sndCursor();
		if(Trg & A_BUTTON)
		{
			break;
		}
		if(Trg & B_BUTTON && bcancel) //choices.bcancel)
		{
			c = set->NumChoices; //choices.numchoices - 1;
			break;
		}
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			vwSetLine(left+1,1,top+1+(c<<1),448,15);
			c = wrap(c + key_tri_vert(), 0, set->NumChoices); //choices.numchoices);
			//AGBPrintf("MultipleChoice: cursor on %d, \"%s\".\n", c,
			//	(char*)choices.choices[c]);
			vwSetLine(left+1, 1, top+1+(c<<1), 384, 15);
		}
	}
	Trg = 0;
	//AGBPrintf("MultipleChoice: answer is %d, \"%s\" - destroying...\n",c,
	//	(char*)choices.choices[c]);
	ClearFrame(left, width, top, (set->NumChoices*2)+2); //(choices.numchoices*2)+2);
	return c;
}

/** \brief Sets up the demo playback engine for the specified demo. */
void StartDemo(int i)
{
	demo = i;
	demotimer = 100;
	democursor = 0;
	AGBPrintf("Demo started.\n");
}

int phase;

u16 CircleWipeOffsets[VID_HEIGHT+1];

/** \brief Calculates the window coordinates for a circle with the given radius and center position.
		\author J Vijn
*/
void CalculateCircle(u16 winh[], int x0, int y0, int rr)
{
    int x=0, y= rr, d= 1-rr;
    u32 tmp;


    // clear the whole array first.
  	//memset(winh, 0, (VID_HEIGHT+1)*2);

    while(y >= x)
    {
        // Side octs
        tmp  = clamp(x0+y, 0, VID_WIDTH+1);
        tmp += clamp(x0-y, 0, VID_WIDTH+1)<<8;

        if(IN_RANGE(y0-x, 0, VID_HEIGHT))       // o4, o7
            winh[y0-x]= tmp;
        if(IN_RANGE(y0+x, 0, VID_HEIGHT))       // o0, o3
            winh[y0+x]= tmp;

        // Change in y: top/bottom octs
        if(d >= 0)
        {
            tmp  = clamp(x0+x, 0, VID_WIDTH);
            tmp += clamp(x0-x, 0, VID_WIDTH)<<8;

            if(IN_RANGE(y0-y, 0, VID_HEIGHT))   // o5, o6
                winh[y0-y]= tmp;
            if(IN_RANGE(y0+y, 0, VID_HEIGHT))   // o1, o2
                winh[y0+y]= tmp;

            d -= 2*(--y);
        }
        d += 2*(x++)+3;
    }
    winh[VID_HEIGHT]= winh[0];
}

void CircleInt(void)
{
	u16 line = REG_VCOUNT;
	if(line < 160) REG_WIN0H = CircleWipeOffsets[line];
}

/** \brief Does a circular wipe in. */
void DoCircle(void)
{
	IntrTable[1] = CircleInt;
	REG_DISPCNT |=  DCNT_WIN0;
	REG_WIN0H = 0;
	REG_WIN0V = 160;
	REG_WININ = WIN_BG3 | WIN_BG2 | WIN_BG1 | WIN_BG0 | WIN_OBJ | WIN_BLD;
	REG_WINOUT = 0;
	for(phase=0; phase < 160; phase+=2)
	{
		CalculateCircle(CircleWipeOffsets,120,80,phase);
		DoVBlank();
	}
	IntrTable[1] = HBlankIntr;
}

extern s32 BGScrollX;
void ZipperInt(void)
{
	u16 line = REG_VCOUNT;
	if(line % 2 == 1)
	{
		REG_WIN0H = 240 - phase;
		REG_BG1HOFS = BGScrollX + 240 - phase;
		REG_BG2HOFS = BGScrollX + 240 - phase;
		REG_BG3HOFS = BGScrollX + 240 - phase;
	} else
	{
		REG_WIN0H = phase << 8;
		REG_BG1HOFS = (BGScrollX - phase) << 8;
		REG_BG2HOFS = (BGScrollX - phase) << 8;
		REG_BG3HOFS = (BGScrollX - phase) << 8;
	}
}

void Zipper()
{
	IntrTable[1] = ZipperInt;
	REG_DISPCNT |=  DCNT_WIN0;
	REG_WIN0H = 240;
	REG_WIN0V = 160;
	REG_WININ = WIN_BG3 | WIN_BG2 | WIN_BG1 | WIN_BG0 | WIN_OBJ | WIN_BLD;
	REG_WINOUT = 0;
	for(phase=0; phase < 248; phase+=4)
	{
		DoVBlank();
	}
	IntrTable[1] = HBlankIntr;
}

void CrossWipeInt1(void)
{
	u16 line = REG_VCOUNT;
	REG_BLDY = 0;
	if(phase > line)
		REG_BLDY = CLAMP(phase-line,0,16);
	if(line >= 160)
		REG_BLDY = 16;
}

void CrossWipeInt2(void)
{
	u16 line = REG_VCOUNT;
	REG_BLDY = 16;
	if(phase > line)
		REG_BLDY = 16-CLAMP(phase-line,0,16);
	if(line >= 160)
		REG_BLDY = 0;
}

void CrossWipe1()
{
	IntrTable[1] = CrossWipeInt1;
	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(phase=0; phase < 180; phase+=4)
	{
		DoVBlank();
	}
	IntrTable[1] = HBlankIntr;
}

void CrossWipe2()
{
	IntrTable[1] = CrossWipeInt2;
	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(phase=0; phase < 180; phase+=4)
	{
		DoVBlank();
	}
	IntrTable[1] = HBlankIntr;
}

int BattlePanOffset;
void BattlePanInt(void)
{
	u16 line = REG_VCOUNT;
	if(line > 37)
		REG_BG3HOFS = 256 - BattlePanOffset;
	if(line > 85)
		REG_BG3HOFS = 256 + BattlePanOffset;
	if(line > 160)
		REG_BG3HOFS = 256 - (BattlePanOffset / 2);
}

void BattlePan(int i)
{
	if(i == 0)
	{
		IntrTable[1] = BattlePanInt;
	}
	else
	{
		IntrTable[1] = HBlankIntr;
		REG_BG3HOFS = 0;
	}
}

void InstallHBlank(void * handler)
{
	if(handler == 0) handler = HBlankIntr;
	IntrTable[1] = handler;
}

int TrainerCardScaleVal;
void TrainerCardScaleInt(void)
{
//	int iy= REG_VCOUNT;
//	if(IN_RANGE(iy, 0, 160))
//		REG_BG2VOFS = (TrainerCardScaleVal-256)*(iy-80)>>8;
//	else
//		REG_BG2VOFS = 160;

	int g_scale = TrainerCardScaleVal;
	int fold_y = 80;

	int ys= REG_VCOUNT+1;
	int lam= 0x10000/g_scale; //lu_div(g_scale);
	int dy= lam*(ys-fold_y)>>8;
	int foo;

	// Condition for visibility:
	// lam*(yscan-yfold)+yfold inside visible card limits

	if(IN_RANGE(dy+fold_y, 0, 160))
		foo= dy - (ys-fold_y);
	else
		foo= 160-ys;	// Show transparent line
	REG_BG2VOFS = foo;
	REG_BG1VOFS = foo;
	REG_BG0VOFS = foo;
}

void TrainerCardScale(int i)
{
	if(i == 0)
	{
		IntrTable[1] = TrainerCardScaleInt;
		TrainerCardScaleVal = 256;
	} else
	{
		IntrTable[1] = IntrDummy;
		REG_BG2VOFS = 0;
		REG_BG1VOFS = 0;
		REG_BG0VOFS = 0;
	}
}





int __qran_seed;
u16 __key_curr, __key_prev;

int sqran(int seed)
{
	int old= __qran_seed;
	__qran_seed= seed;
	return old;
}



extern const unsigned short fontScreamTiles[1024];
/** \brief Serious error display, Sonic 1 style */
void Scream(char * error)
{
	u16 i = 0, j = 33;
	u8 c = 255;
	REG_BLDCNT = BLD_BLACK | BLD_BG1 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	REG_BLDY = 10;
	DmaArrayCopy(fontScreamTiles, MEM_VRAM + 0x8000);
	DmaClear(0, BG0MAP, 0x600);
	while(c != 0)
	{
		c = error[i++];
		BG0MAP[j++] = 0xF000 + c - ' ';
	}
	while(1);
}





#include <stdarg.h>
/** \brief Printf-style routine, displays fmt in a box with the given style */
void sayf(int style, const char *fmt, ...)
{
	AGBPrint("sayf: ");
	AGBPrintf(fmt);
	AGBPrint("\n");

	va_list args;
	char buf[256];

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	SetText(TextBuffer,buf);
	SM_Dialoguebox.state = 0;
	SM_Dialoguebox.style = style;
	while(1)
	{
		DoVBlank();
		KeyRead();
		DialogueBox();
		if(SM_Dialoguebox.state == 7)
			break;
	}
	if(!SM_Dialoguebox.OneUp)
		Script_WAITKEYPRESS(0);
}

//This is directly decompiled from Fire Red and returns 32-bit values. Great for ID numbers ;)
void srand(unsigned int seed)
{
	rndseed = seed;
}
unsigned int rand()
{
	rndseed = (rndseed * 0x41C64E6D) + 0x6073;
	return rndseed;
}
unsigned int rrand(unsigned int range)
{
	return (rand() >> 8) % range;
	//return rand()*range>>15;
}



extern const unsigned char Sapp2Asc[256];
void CheckForImports()
{
	unsigned int ImportKey;
	unsigned int param;
	unsigned int position;
	bytecpy(&ImportKey, SRAM+0xD000, sizeof(ImportKey));
	bytecpy(&param, SRAM+0xD004, sizeof(param));
	if(ImportKey == 0x21544547) //"GET!"
	{
		if(param == 0)
		{
			sayf(SYSTEM,strImportError);
			return;
		} else if(param == 1)
		{
			sayf(SYSTEM,strImportOne);
		} else
		{
			sayf(SYSTEM,strImportMore, param);
		}
		if(!SimpleYesNoLoop())
		{
			sayf(SYSTEM,strImporting);

			int i;
			for(i = 0; i < param; i++)
			{
				//Determine where to put them
				int boxno, boxspot;
				extern char boxnames[14][10];

				for(boxno = 0; boxno < 14; boxno++)
				{
					for(boxspot = 0; boxspot < 5*6; boxspot++)
					{
						position = boxspot + (boxno * 30);
						AGBPrintf("Boxcheck: %d is PV %d.\n",boxspot, MyBox[position].Personal.Personal);
						if(MyBox[position].Personal.Personal == 0)
						{
							//found
							goto BoxPlaced;
						}
					}
				}
BoxPlaced:

				bytecpy(&MyBox[position], SRAM+0xD010 + (i * 80), sizeof(aBoxedMon));
				if(MyBox[position].Personal.Font == 0)
				{
					Transcode(MyBox[position].Personal.Nickname, MyBox[position].Personal.Nickname,10, PCS3JtoShiftPCS3J);
					Transcode(MyBox[position].Personal.OTName, MyBox[position].Personal.OTName,7, PCS3JtoShiftPCS3J);
				}
				else
				{
					Transcode(MyBox[position].Personal.Nickname, MyBox[position].Personal.Nickname,10, PCS3WtoWin1252);
					Transcode(MyBox[position].Personal.OTName, MyBox[position].Personal.OTName,7, PCS3WtoWin1252);
				}

				sayf(SYSTEM,strImported,MyBox[position].Personal.Nickname, boxnames[boxno]);
				//btlsayf(BT_XWasTransferredToSomeonesPCItWasPlacedInBoxX, HisParty[0].Personal.Nickname, boxnames[boxno]);
			}

			byteclr(SRAM + 0xD000, 16 + (param * 80));
			ShowBoxes();
		} else
		{
			if(param == 1)
				sayf(SYSTEM,strImportOneNot);
			else
				sayf(SYSTEM,strImportMoreNot);
			if(!SimpleYesNoLoop())
			{
				sayf(SYSTEM,"Clearing…\1");
				byteclr(SRAM + 0xD000, 16 + (param * 80));
			}
		}
	}
	CleanUpCrap();
	LoadFrame();
}




#ifdef DEBUG
extern const unsigned short * const TrainerPics[];
extern const unsigned char HeightDataBack[];
extern const unsigned char HeightDataFront[];
extern const char * const tpicnames[tpTotal]; //[tpLAST+1];

// Debug Menu - Pictures
void ShowPics()
{
	int tid = 1, otid = 0;
	int pid = 1, opid = 0;
	int keybfr = 0;
	int ldown = 0, rdown = 0, reload = 0;
	char blah[255];

	REG_DISPCNT = 0;
	//pid = pkSkitty;

	OamBak[0].CharNo = 0;
	OamBak[0].Pltt = 0;
	OamBak[0].Shape = 0;
	OamBak[0].Size = 3;
	OamBak[0].HPos = 2*8;
	OamBak[0].VPos = 2*8;

	OamBak[1].CharNo = 64;
	OamBak[1].Pltt = 1;
	OamBak[1].Shape = 0;
	OamBak[1].Size = 3;
	OamBak[1].HPos = 20*8;
	OamBak[1].VPos = 6*8;

	DrawFrame(1,10,1,10);
	DrawFrame(11,18,1,4);
	vwSetLine(12,16,2,96,15);

	DrawFrame(19,10,5,10);
	DrawFrame(1,18,11,4);
	vwSetLine(2,16,12,160,15);

	DrawFrame(1,28,15,4);
	vwSetLine(2,26,16,224,15);
	vwClearLine(1,8);
	vwClearLine(1,9);
	vwWrite(0,32,"<> Trainer, ^v PkMn, L shiny, R back");

	ResetDispCnt();
	MyPlayer.Options.buttonmode = 3; //don't take away L/R in any way

	while(1)
	{
		DoVBlank();
		KeyRead();

		keybfr = ( REG_KEYINPUT ^ 0x3FF );

		if(keybfr != 0)
		{
			tid += (keybfr << 26 >> 31);
			tid -= (keybfr << 27 >> 31);
		}

		tid = wrap(tid, 0, tpTotal); //tpLAST);
		if(tid != otid)
		{
			DmaClear(0,MEM_VRAM_OBJ + 0x0, 0x800);
			DoVBlank();
			DmaCopy(TrainerPics[(tid * 2) + 1], MEM_PAL_OBJ + 0x0, 32);
			LZ77UnCompVram(TrainerPics[tid* 2], (u16*)(MEM_VRAM_OBJ + 0x0));
			vwClearLine(1,0);
			sprintf(blah,"#%d - %s",tid,tpicnames[tid]);
			vwWrite(0,0,blah);
			otid = tid;
		}

	// Scroll through Pokemon-Sprites

	//keybfr = ( REG_KEYINPUT ^ 0x3FF );

		if(keybfr != 0)
		{
			pid += (keybfr << 25 >> 31);
			pid -= (keybfr << 24 >> 31);
		}

		pid = wrap(pid, 1, pkCount-2);
		if(pid != opid)
		{
			reload = 1;
			vwClearLine(1,4);
			sprintf(blah,"#%d - %s",pid,PokeNames[pid]);
			vwWrite(0,16,blah);
			opid = pid;
		}


	// Change Pokémon - Palette to it's Shiny Palette
		if((Cont & KEY_L) && !(ldown))
		{
			ldown = 1;
			reload = 1;
			LoadPokemonPic(pid,LPP_SHINY,MEM_VRAM_OBJ+0x800,pal_obj_bank[1],0xDEADBEEF);
		}
		else if((ldown) && !(Cont & KEY_L))
		{
			ldown = 0;
			reload = 1;
		}

	// Show back-sprite of the Pokémon
		if((Cont & KEY_R) && !(rdown))
		{
			rdown = 1;
			reload = 1;
		} else if((rdown) && !(Cont & KEY_R))
		{
			rdown = 0;
			reload = 1;
		}

		// Get out of the Picture-Debug-Menu
		if(Trg & B_BUTTON)
		{
			break;
		}

		// Play cry of currently shown Pokémon
		if(Trg & A_BUTTON)
		{
			sndPlayCry(pid, 18);
		}

		if(reload)
		{
			DmaClear(0,MEM_VRAM_OBJ + 0x800, 0x800);
			if(rdown)
			{
				OamBak[1].VPos = (6*8) + HeightDataBack[pid];
			} else
			{
				OamBak[1].VPos = (6*8) + HeightDataFront[pid];
			}
			DoVBlank();
			LoadPokemonPic(pid,(rdown*LPP_BACK) | (ldown*LPP_SHINY),MEM_VRAM_OBJ+0x800,pal_obj_bank[1],0xDEADBEEF);
			reload = 0;
		}
	}
}

extern const aTileset tileset_Indoors[];
extern const aTileset tileset_Outdoors[];
extern const aTileset tileset_Amber[];
extern const aTileset tileset_Apartment[];
extern const aTileset tileset_AshsRoom[];
extern const aTileset tileset_BikeShop[];
extern const aTileset tileset_Burgled[];
extern const aTileset tileset_Cave[];
extern const aTileset tileset_Celadon[];
extern const aTileset tileset_CeleryMansion[];
extern const aTileset tileset_Cerulean[];
extern const aTileset tileset_CeruleanGym[];
extern const aTileset tileset_ChaosOut[];
extern const aTileset tileset_DepStore[];
extern const aTileset tileset_Elite[];
extern const aTileset tileset_FanClub[];
extern const aTileset tileset_Forest[];
extern const aTileset tileset_Fuchsia[];
extern const aTileset tileset_HallOfFame[];
extern const aTileset tileset_Indigo[];
extern const aTileset tileset_Lab[];
extern const aTileset tileset_Lavender[];
extern const aTileset tileset_Mansion[];
extern const aTileset tileset_PewterGym[];
extern const aTileset tileset_PkCenter[];
extern const aTileset tileset_Restaurant[];
extern const aTileset tileset_Silph[];
extern const aTileset tileset_Store[];
const aTileset * const alphatilesets[] =
{
	tileset_Outdoors,
	tileset_Indoors,
};
const aTileset * const betatilesets[] =
{
	tileset_Amber,
	tileset_Apartment,
	tileset_AshsRoom,
	tileset_BikeShop,
	tileset_Burgled,
	tileset_Cave,
	tileset_Celadon,
	tileset_CeleryMansion,
	tileset_Cerulean,
	tileset_CeruleanGym,
	tileset_ChaosOut,
	tileset_DepStore,
	tileset_Elite,
	tileset_FanClub,
	tileset_Forest,
	tileset_Fuchsia,
	tileset_HallOfFame,
	tileset_Indigo,
	tileset_Lab,
	tileset_Lavender,
	tileset_Mansion,
	tileset_PewterGym,
	tileset_PkCenter,
	tileset_Restaurant,
	tileset_Silph,
	tileset_Store,
};
const int betamatchingalphas[] =
{
	0,
	1,
	1,
	1,
	1,
	1,
	0,
	1,
	0,
	1,
	0,
	1,
	1,
	1,
	0,
	0,
	1,
	0,
	1,
	0,
	1,
	1,
	1,
	1,
	1,
	1,
};
const char * const tilesetnames[] =
{
	"Outdoors",
	"Indoors",
	"Amber",
	"Apartment",
	"AshsRoom",
	"BikeShop",
	"Burgled",
	"Cave",
	"Celadon",
	"CeleryMansion",
	"Cerulean",
	"CeruleanGym",
	"ChaosOut",
	"DepStore",
	"Elite",
	"FanClub",
	"Forest",
	"Fuchsia",
	"HallOfFame",
	"Indigo",
	"Lab",
	"Lavender",
	"Mansion",
	"PewterGym",
	"PkCenter",
	"Restaurant",
	"Silph",
	"Store",
};
void TestTileset()
{
	int x, y, i, s = 0x280, t = 0;
	char fop[16];
	aTileset * betatileset = (aTileset *)betatilesets[t];
	aTileset * alphatileset = (aTileset *)alphatilesets[betamatchingalphas[t]];

	LZ77UnCompVram(alphatileset->pic, (void*)MEM_VRAM);
	LZ77UnCompVram(betatileset->pic, (void*)MEM_VRAM+0x5000);
	DmaCopy(betatileset->colordata, MEM_PAL, 512);
	pal_bg_mem[0] = 0;
	LoadFrame();
	DrawFrame(16,14,0,8);
	vwSetLine(17,12,1,96,15);
	vwSetLine(17,12,3,160,15);
	vwSetLine(17,12,5,224,15);
	vwClear(1);
	vwWrite(0,0,tilesetnames[betamatchingalphas[t]]);
	vwWrite(0,14,tilesetnames[t+2]);
	sprintf(fop, "0x%x  ", s);
	vwWrite(0,28,fop);

	while(1)
	{
		i = s;

		// Draw tiles to the screen
		for(y = 0; y < 10; y++)
		{
			for(x = 0; x < 8; x++)
			{
				if(i < 0x280)
					mapDrawMeta(x, y, (MetaTile*)&alphatileset->blockdata[i]);
				else
					mapDrawMeta(x, y, (MetaTile*)&betatileset->blockdata[i-0x280]);
				i++;
			}
		}

		while(1)
		{
			DoVBlank();
			KeyRead();
			if(Trg & KEY_A)
			{
				t = wrap(t + 1, 0, 24);
				alphatileset = (aTileset*)alphatilesets[betamatchingalphas[t]];
				betatileset = (aTileset*)betatilesets[t];
				LZ77UnCompVram(alphatileset->pic, (void*)MEM_VRAM);
				LZ77UnCompVram(betatileset->pic, (void*)MEM_VRAM + 0x5000);
				DmaCopy(betatileset->colordata, MEM_PAL, 512);
				pal_bg_mem[0] = 0;
				LoadFrame();
				vwClear(1);
				vwWrite(0,14,tilesetnames[t+2]);
				vwWrite(0,0,tilesetnames[betamatchingalphas[t]]);
				sprintf(fop, "0x%x  ", s);
				vwWrite(0,28,fop);
				break;
			}
			if(Trg & KEY_B)
			{
				t = wrap(t - 1, 0, 24);
				alphatileset = (aTileset*)alphatilesets[betamatchingalphas[t]];
				betatileset = (aTileset*)betatilesets[t];
				LZ77UnCompVram(alphatileset->pic, (void*)MEM_VRAM);
				LZ77UnCompVram(betatileset->pic, (void*)MEM_VRAM + 0x5000);
				DmaCopy(betatileset->colordata, MEM_PAL, 512);
				pal_bg_mem[0] = 0;
				LoadFrame();
				vwClear(1);
				vwWrite(0,14,tilesetnames[t+2]);
				vwWrite(0,0,tilesetnames[betamatchingalphas[t]]);
				sprintf(fop, "0x%x  ", s);
				vwWrite(0,28,fop);
				break;
			}
			if(Trg & KEY_UP && s)
			{
				s-=8;
				sprintf(fop, "0x%x  ", s);
				vwWrite(0,28,fop);
				break;
			}
			if(Trg & KEY_DOWN)
			{
				s+=8;
				sprintf(fop, "0x%x  ", s);
				vwWrite(0,28,fop);
				break;
			}
			if(Trg & KEY_LEFT && s)
			{
				s-=80;
				sprintf(fop, "0x%x  ", s);
				vwWrite(0,28,fop);
				break;
			}
			if(Trg & KEY_RIGHT)
			{
				s+=80;
				sprintf(fop, "0x%x  ", s);
				vwWrite(0,28,fop);
				break;
			}
		}
	}
	SoftReset();
}

#endif //DEBUG


