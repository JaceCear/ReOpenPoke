#include "../openpoke.h"

extern const unsigned short welc_kawaPal[16];
extern const unsigned short welc_kawaTiles[1232];
extern const unsigned short welc_rivalPal[16];
extern const unsigned short welc_rivalTiles[1232];
extern const unsigned short welc_dannyPal[16];
extern const unsigned short welc_dannyTiles[1232];
extern const unsigned short welc_daniPal[16];
extern const unsigned short welc_daniTiles[1232];
extern const unsigned short welc_backPal[16];
extern const unsigned short welc_backTiles[176];
extern const unsigned short welc_backMap[640];
extern const unsigned short pkballPal[16];
extern const unsigned short pkballTiles[128];

/** \brief Delays stuff */
#define Delay(frames)		\
	vavoom = frames;		\
	while(vavoom)			\
	{						\
		DoVBlank();			\
		KeyRead();			\
		DialogueBox();		\
		vavoom--;			\
	}

/** \brief Fades in at a given speed */
#define Welc_FadeIn(Speed)				\
	for(fade = 0; fade < 0x11; fade++)	\
	{									\
		for(fadetimer = 0; fadetimer < Speed; fadetimer++) DoVBlank();	\
		REG_BLDALPHA = ((0x10 - fade) << 8) + fade;					\
		REG_BG1HOFS = -(0x10 - fade);	\
	}

/** \brief Fades out at a given speed */
#define Welc_FadeOut(Speed)				\
	for(fade = 0; fade < 0x11; fade++)	\
	{									\
		for(fadetimer = 0; fadetimer < Speed; fadetimer++) DoVBlank();	\
		REG_BLDALPHA = (fade << 8) + (0x10 - fade);					\
		REG_BG1HOFS = -fade;			\
	}

#ifdef WITH_SHIRTCOLORS
extern const unsigned short shirtcolorsPal[16];
extern const unsigned short shirtcolorsTiles[448];
extern const u16 shirtcolors[32];
void SelectShirtColor();
#endif

extern void pal_blend_asm5(COLOR *pa, COLOR *pb, COLOR *pc, int nclrs, u32 alpha) CODE_IN_IWRAM;
extern const unsigned short RedStrip[16];
extern const unsigned short WhiteStrip[16];

extern CSTRING playernames[2][12];

/** \brief Loads the graphics for a character in the intro speech.
		\param who Which character to load:
		- "Oak"
		- "Blue"
		- "Red"
		- "Leaf"
*/
void LoadWelcomePerson(int who)
{
	const u16* pics[] = { welc_kawaTiles, welc_rivalTiles, welc_dannyTiles, welc_daniTiles };
	const u16* pals[] = { welc_kawaPal,   welc_rivalPal,   welc_dannyPal,   welc_daniPal };
	if(who > 3) return;
	DmaCopy(pics[who], MEM_VRAM   + 0x4000, 0x9A0);
	DmaCopy(pals[who], MEM_PAL_BG + 0xC0,   32);
}

/** \brief Sets up the tilemap for the intro speech characters */
void BuildWelcomePerson()
{
	const u16 start = 0x6b;
	u16	*BG1 = (u16*)0x600E800;
	u32	l, r, c;
	AGBPrint("BuildWelcomePerson: ...\n");
	DmaClear(0,BG1,0x2000);
	c = 512;
	for(r = 0; r < 11; r++)
	{
		for(l = 0; l < 7; l++)
		{
			BG1[(r*32)+l + start] = c + 0x6000;
			c++;
		}
	}
}

extern const aSprite Sprites[];
/** \brief Animation callback function for EnterName */
void WelcomeEnterNameAnim(int t)
{
	const u8 frames[4] = { 0,3,0,4};
	u8* thisPic;
	thisPic = (u8*)Sprites[MyPlayer.gender+1].spriteStart + (0x100 * frames[(t >> 3) % 4]);
	CpuFastCopy(thisPic, (u16*)MEM_VRAM_OBJ, 0x100);
	CpuFastArrayCopy(MyPlayer.gender == 0 ? danny_Palette : dani_Palette, MEM_PAL_OBJ + 0xA0);
	OamBak[0].Pltt = 5;
}
#ifdef CUSTOM_RIVAL_NAME
void WelcomeEnterNameAnim2(int t)
{
	const u8 frames[4] = { 0,3,0,4};
	u8* thisPic;
	thisPic = (u8*)Sprites[sprArbe].spriteStart + (0x100 * frames[(t >> 3) % 4]);
	CpuFastCopy(thisPic, (u16*)MEM_VRAM_OBJ, 0x100);
	//CpuFastArrayCopy(spritecolors, MEM_PAL_OBJ + 0xA0);
	OamBak[0].Pltt = 4;
}
#endif

/** \brief This used to be a function... */
#define WelcomeGetGender() MultipleChoice(21,8,8, 20,0)

u32 WelcomeGetName(u32 gender)
{
	int name = 1, i;

	AGBPrint("WelcomeGetName: initializing...\n");
	vwClearLine(1, 8);
	vwClearLine(1, 9);
	vwClearLine(1, 12);
	DrawFrame(0, 9, 0, 12);
	vwWriteG(0, 4, strArrow);
	vwSetLine(1, 1, 1+(name<<1), 224, 15);

	for(i = 0; i < 4; i++)
	{
		vwWrite((2+(i<<3))<<3, 4<<3, (char*)playernames[gender][i]);
		vwSetLine(2, 6, 3+(i<<1), 226+(i<<3), 15);
	}

	vwWriteG(2, 6, strIntroNewName); //"\7\x01\x0DNEW NAME");
	vwSetLine(2, 6, 1, 290, 15);
	//vwRefresh();
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & A_BUTTON) break;
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			vwSetLine(1, 1, 1+(name<<1), 225, 15);
			name = wrap(name + key_tri_vert(), 0, 5);
			vwSetLine(1, 1, 1+(name<<1), 224, 15);
		}
	}
	ClearFrame(0, 9, 0, 12);
	AGBPrintf("WelcomeGetGender: answer is %d\n", name-1);
	return name;
}

void Welcome()
{
	int fade = 0, fadetimer = 0, gender;
	int vavoom, scale;
	char fark[10];

	HelpContext = 0;

	AGBPrint("Welcome: initializing...\n");
	AGBPrint("Welcome: setting up stage...\n");
	//set up stage
	CpuFastArrayCopy(welc_backPal,MEM_PAL_BG);
	CpuFastArrayCopy(welc_backTiles,MEM_VRAM);
	CpuFastArrayCopy(welc_backMap,MEM_VRAM_FRONT+0xE000);
	REG_BG2HOFS = 8;

	LoadFrame();
	LoadSpriteColors();

	AGBPrint("Welcome: preparing sprites...\n");
	//prepare sprites
	CpuFastArrayCopy(pkballPal,MEM_PAL_OBJ+0xc0);
	CpuFastArrayCopy(pkballTiles,MEM_VRAM_OBJ+0x800);
	OamBak[1].HPos = 110; //88;
	OamBak[1].VPos = 59;
	OamBak[1].CharNo = 72; //empty tiles
	OamBak[1].Shape = 0;
	OamBak[1].Size = 1;
	OamBak[1].Pltt = 6;

	sndPlaySound(58,SOUND_NORMAL);
	LoadWelcomePerson(0);
	FadeIn();

	REG_BLDCNT = BLD_BG1 | BLD_STD | BLD_BOT(BLD_BG2) | BLD_BOT(BLD_OBJ);
	REG_BLDALPHA = 0x1000;

	BuildWelcomePerson();

	Welc_FadeIn(4);

	sayf(SPEECH,strIntroSpeech[0]);

	OamBak[1].CharNo = 64; //pokéball appears in hand...
	Delay(40);
	OamBak[1].CharNo = 68; //...opens...
	Delay(10);
	AGBPrint("Welcome: liek p00f!\n");
	LoadPokemonPic(INTROMON,LPP_NORMAL,MEM_VRAM_OBJ,pal_obj_bank[0],0);
	SetupPokemonSprite(0);
	OamBak[0].AffineMode = 1;
	OamBak[0].AffineParamNo_L = 0;
	OamBak[0].HPos = 60;
	OamBak[0].VPos = 60;
	OamBak[0].Pltt = 1;
	DmaCopy(RedStrip, MEM_PAL_OBJ + 0x20, 32);
	for(vavoom = 32; vavoom >= 0; vavoom--)
	{
		scale = 0x100 + (vavoom << 4);
		OamBak[0].AffineParam = scale;
		OamBak[3].AffineParam = scale;
		OamBak[0].VPos = 60 + (vavoom>>2);
		pal_blend_asm5(WhiteStrip, RedStrip, (u16*)MEM_PAL_OBJ+0x10,16,vavoom);
		DoVBlank();
	}
	for(vavoom = 32; vavoom >= 0; vavoom--)
	{
		pal_blend_asm5((u16*)MEM_PAL_OBJ, WhiteStrip, (u16*)MEM_PAL_OBJ+0x10,16,vavoom);
		DoVBlank();
	}
	OamBak[1].HPos = 250;
	sndPlayCry(INTROMON,60);

	Delay(10);

	sayf(SPEECH,strIntroSpeech[1]);

	REG_BLDCNT = BLD_OBJ | BLD_BG1 | BLD_STD | BLD_BOT(BLD_BG2) | BLD_BOT(BLD_OBJ);
	//REG_BLDALPHA = 0x0010;
	sayf(SPEECH,strIntroSpeech[2]);
	Welc_FadeOut(2);

	OamBak[0].HPos = 250; //hide sprites by moving off-screen
	OamBak[1].HPos = 250;

	//Welc_SimpleTextLoop("Are you a boy or a girl?\1");
	sayf(SPEECH,strIntroSpeech[3]);
	gender = WelcomeGetGender();
	MyPlayer.gender = gender;
	ClearDialogueBox();
	LoadWelcomePerson(2+gender);
	Welc_FadeIn(2);
	sayf(SPEECH,strIntroSpeech[4]);

	vavoom = WelcomeGetName(gender);
	if(vavoom == 0)
	{
RinseRepeat:
		FadeOut();
		DmaClear(0, MEM_VRAM, VRAM_SIZE); //clean up crap
		fark[0] = 0;
		MyPlayer.gender = gender;
		EnterName((char*)fark,8,strIntroSpeech[5], (void*)WelcomeEnterNameAnim);
		AGBPrint("Welcome: rebuilding stage...\n");
		HelpContext = 0;
		ClearOamBak();
		DmaClear(0, MEM_VRAM, VRAM_SIZE); //clean up crap
		CpuFastArrayCopy(welc_backPal, MEM_PAL_BG);
		CpuFastArrayCopy(welc_backTiles, MEM_VRAM);
		CpuFastArrayCopy(welc_backMap, MEM_VRAM+0xE000);
		CpuClear(0x000A000A, MEM_VRAM+0xE800, 0x500);
		LoadFrame();
		LoadSpriteColors();
		LoadWelcomePerson(2+gender);
		BuildWelcomePerson();
		FadeIn();
		if(fark[0]==0)
		{
			sprintf(fark,"%s",playernames[gender][rrand(11)]);
			//sprintf(buffy, "So it's %s?\1",fark);
			//Welc_SimpleTextLoop(buffy);
			sayf(SPEECH,strIntroSpeech[6], fark);
			if(SimpleYesNoLoop()) goto RinseRepeat;
		}
	} else
	{
		sprintf(fark, "%s",(char*)playernames[gender][vavoom-1]);
	}
	SetNewPlayer((char*)fark, gender);

#ifdef WITH_SHIRTCOLORS
	Welc_FadeOut(2);
	SelectShirtColor();
	*(u16*)0x050000DC = shirtcolors[(MyPlayer.shirtColor*2) + ((MyPlayer.gender % 2) * 16)];
	*(u16*)0x050000CE = shirtcolors[(MyPlayer.shirtColor*2)+1+((MyPlayer.gender % 2) * 16)];
#ifndef CUSTOM_RIVAL_NAME
	Welc_FadeIn(2);
#endif
#endif

#ifdef CUSTOM_RIVAL_NAME
	LoadWelcomePerson(1);
	Welc_FadeIn(2);
	sayf(SPEECH,strIntroSpeech[7]);
	vavoom = WelcomeGetName(2);
	if(vavoom == 0)
	{
RinseRepeat2:
		FadeOut();
		DmaClear(0, MEM_VRAM, VRAM_SIZE);
		fark[0] = 0;
		EnterName((char*)fark,8,strIntroSpeech[8], WelcomeEnterNameAnim2);
		HelpContext = 0;
		ClearOamBak();
		DmaClear(0, MEM_VRAM, VRAM_SIZE);
		CpuFastArrayCopy(welc_backPal, MEM_PAL_BG);
		CpuFastArrayCopy(welc_backTiles, MEM_VRAM);
		CpuFastArrayCopy(welc_backMap, MEM_VRAM+0xE000);
		CpuClear(0x000A000A, MEM_VRAM+0xE800, 0x500);
		LoadFrame();
		LoadSpriteColors();
		LoadWelcomePerson(1);
		BuildWelcomePerson();
		FadeIn();
		if(fark[0]==0)
		{
			sprintf(fark,"%s",playernames[1][rrand(3)]);
			sayf(SPEECH,strIntroSpeech[6], fark);
			if(SimpleYesNoLoop()) goto RinseRepeat2;
		}
	} else
	{
		strcpy(fark, (char*)playernames[1][vavoom-1]);
	}
	strcpy(MyPlayer.rival, fark);
	sayf(SPEECH,strIntroSpeech[9]);
	Welc_FadeOut(2);
	LoadWelcomePerson(2+gender);
	Welc_FadeIn(2);
#endif

	sayf(SPEECH,strIntroSpeech[10]);

	FadeOut();

	REG_BG2HOFS = 0;

	return;
}

#ifdef WITH_SHIRTCOLORS
void SelectShirtColor()
{
	u8 i;
	LoadFrame();
	DmaArrayCopy(shirtcolorsTiles, MEM_VRAM_OBJ + 0x400);
	DmaArrayCopy(shirtcolorsPal, MEM_PAL_OBJ + 0x0020);
	DmaArrayCopy(shirtcolors + ((MyPlayer.gender % 2) * 16), MEM_PAL_OBJ + 0x0008);
	DrawFrame(7, 16, 4, 7);
	for(i=0; i<6; i++)
	{
		OamBak[i+2].CharNo = 36 + (i*4);
		OamBak[i+2].Pltt = 1;
		OamBak[i+2].Shape = 0;
		OamBak[i+2].Size = 1;
		OamBak[i+2].VPos = 64;
		OamBak[i+2].HPos = 72 + (i*16);
	}
	if(MyPlayer.gender)
	{
		OamBak[2].CharNo = 48;
		OamBak[5].CharNo = 36;
	}
	i = MyPlayer.shirtColor;
	OamBak[1].CharNo = 32;
	OamBak[1].Pltt = 0;
	OamBak[1].Shape = 0;
	OamBak[1].Size = 1;
	OamBak[1].VPos = 64;
	OamBak[1].HPos = 72 + (i*16);
	OamBak[0].HPos = 111;
	OamBak[0].VPos = 28;
	OamBak[0].Pltt = 5;
	OamBak[0].Size = 2;
	OamBak[0].Shape = 2;
	OamBak[0].CharNo = 0;
	OamBak[0].Priority = 0;
	CpuFastCopy(Sprites[MyPlayer.gender+1].spriteStart, (u16*)MEM_VRAM_OBJ, 0x100);
	CpuFastArrayCopy(MyPlayer.gender == 0 ? danny_Palette : dani_Palette, MEM_PAL_OBJ + 0xA0);
	*(u16*)0x050002B2 = shirtcolors[(i*2) + ((MyPlayer.gender % 2) * 16)];
	*(u16*)0x050002B4 = shirtcolors[(i*2)+1+((MyPlayer.gender % 2) * 16)];
	sayf(SYSTEM,strShirtPrompt);
	while(1)
	{
		DoVBlank();
		KeyRead();
		i=wrap(i+key_tri_horz(),0,6);
		OamBak[1].HPos = 72 + (i*16);
		*(u16*)0x050002B2 = shirtcolors[(i*2) + ((MyPlayer.gender % 2) * 16)];
		*(u16*)0x050002B4 = shirtcolors[(i*2)+1+((MyPlayer.gender % 2) * 16)];
		if(Trg & A_BUTTON) break;
	}
	MyPlayer.shirtColor = i;
	DmaClear(0, MEM_VRAM + 0xF800, 0x1000);
	ClearSpriteGFX();
}
#endif

