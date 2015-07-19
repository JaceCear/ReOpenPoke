#include "../openpoke.h"

extern void InstallHBlank(void * handler);

extern unsigned short intro_m7skyTiles[512];
extern unsigned short intro_m7skyMap[1024];
extern unsigned short intro_m7cloudsTiles[784];
extern unsigned short intro_m7cloudsMap[512];
extern unsigned short intro_m7groundTiles[640];
extern unsigned short intro_m7groundMap[512];
extern unsigned short intro_m7groundPal[32];

#define M7_D 160
#define MAP_AFF_SIZE 0x0100
#define PHI0 0
static VECTOR cam_pos;
static u16 cam_phi = PHI0;
static FIXED g_cosf = 1<<8, g_sinf= 0;
static const int horz = 86;
static int t;

static const VECTOR cam_pos_dflt =
{
	256<<8,
	70<<8,
	128<<8,
};

static const unsigned short BlackStrip[16] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

void IntroMode7()
{
	FIXED lam, lcf, lsf, lxr, lyr;
	int vc = REG_VCOUNT;

	if(IN_RANGE(vc, 70, 84))
		REG_BG2HOFS = sin_lut[vc - 70 + (t % 512)] >> 10;
	if(IN_RANGE(vc, 73, 84))
		REG_BG2VOFS = sin_lut[vc - 73 + (t % 512)] >> 12;

	if(!IN_RANGE(vc, horz-1, 160)) return;

	if(vc == horz)
	{
		BF_SET(REG_DISPCNT, DCNT_MODE1, DCNT_MODE);
		//REG_DISPCNT &= ~DCNT_OBJ;
		REG_BG2CNT = BG_CBB(0) | BG_SBB(8) | BG_AFF_32x32 | BG_WRAP;
	}
	if(horz + 16 >= vc && vc >= horz)
	{
		REG_BLDALPHA = BLDA_BUILD(vc-horz, 16-(vc-horz));
	}
	if(vc > 120)
	{
		REG_BLDCNT = BLD_BUILD(BLD_OBJ, BLD_BG2, 0);
		REG_BLDALPHA = BLDA_BUILD(6, 10);
		((OamData*)oam_mem)[2].HPos += (vc % 3 < 2);

		signed int i;
		if(OamBak[10].HPos > 24) i = -1;
		if(OamBak[10].HPos > 40) i = -(vc % 3 < 2);
		if(OamBak[10].HPos > 64) i = 0;
		if(OamBak[10].HPos > 100) i = (vc % 3 < 2);
		if(OamBak[10].HPos > 160) i = 1;
		if(OamBak[10].HPos > 300) i = -2;
		((OamData*)oam_mem)[12].HPos += i;
		((OamData*)oam_mem)[13].HPos += i;
	}

	lam = cam_pos.y * lu_div(vc) >> 12;	// .8  *.16 / .12 = 20.12
	lcf = lam * g_cosf >> 8;						// .12 *.8  / .8 =    .12
	lsf = lam * g_sinf >> 8;						// .12 *.8  / .8 =    .12

	REG_BG2PA= lcf >> 4;
	REG_BG2PC= lsf >> 4;

	// Offsets
	// Note that the lxr shifts down first!

	// horizontal offset
	lxr =  120  * (lcf  >> 4);
	lyr = (M7_D *  lsf) >> 4;
	REG_BG2X = cam_pos.x - lxr + lyr;

	// vertical offset
	lxr =  120  * (lsf  >> 4);
	lyr = (M7_D *  lcf) >> 4;
	REG_BG2Y = cam_pos.z - lxr - lyr;
}

void SmoothWhiteFade(u16 *dst, u16 *src, int nclrs, u32 d)
{
	int ii;
	u32 r, g, b;
	for(ii=0; ii<nclrs; ii++)
	{
		r= (src[ii]     & 31);
		g= (src[ii]>> 5 & 31);
		b= (src[ii]>>10 & 31);
		r=CLAMP(r + (d>>8), 0, 31);
		g=CLAMP(g + (d>>8), 0, 31);
		b=CLAMP(b + (d>>8), 0, 31);
		dst[ii]= RGB15(r, g, b);
	}
}

void IntroMovie()
{
	int i = 0, fader = 0, danpos = 0, skip = 0;
	short * danTiles;
	short * danPal;
	RTCTime myTime;
	RTC_GetTime(&myTime);
	if(myTime.seconds % 4 < 2)
	{
		danTiles = (short*)intro_dannyTiles;
		danPal = (short*)intro_dannyPal;
	} else
	{
		danTiles = (short*)intro_daniTiles;
		danPal = (short*)intro_daniPal;
	}

	REG_BG1CNT = BG_CBB(2) | BG_SBB(4) | BG_REG_32x32;
	REG_DISPCNT = DCNT_MODE1 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ | DCNT_OBJ_1D ;

	CpuFastArrayCopy(intro_m7groundPal, MEM_PAL);
	CpuFastArrayCopy(intro_m7groundTiles, MEM_VRAM);
	CpuFastArrayCopy(intro_m7groundMap, MEM_VRAM + 0x4000);

	CpuFastArrayCopy(intro_m7skyTiles, MEM_VRAM + 0xC000);
	CpuFastArrayCopy(intro_m7skyMap, MEM_VRAM + 0x6000);

	CpuFastArrayCopy(intro_m7cloudsTiles, MEM_VRAM + 0x8000);
	CpuFastArrayCopy(intro_m7cloudsMap, MEM_VRAM + 0x2000);

	CpuFastCopy(danPal, MEM_PAL_OBJ,16);
	CpuFastCopy(danTiles, MEM_VRAM_OBJ, 0x800);
	CpuFastCopy(danTiles + 0x1800, MEM_VRAM_OBJ + 0x800, 0x400);
	OamBak[0].CharNo = 0;
	OamBak[0].HPos = 250;
	OamBak[0].VPos = 80;
	OamBak[0].Shape = 0;
	OamBak[0].Size = 3;
	OamBak[0].Pltt = 0;
	OamBak[0].ObjMode = 0;
	OamBak[1].CharNo = 64;
	OamBak[1].HPos = 250;
	OamBak[1].VPos = 80;
	OamBak[1].Shape = 1;
	OamBak[1].Size = 3;
	OamBak[1].Pltt = 0;
	OamBak[1].ObjMode = 0;
	OamBak[2].CharNo = 0;
	OamBak[2].HPos = 250;
	OamBak[2].VPos = 140;
	OamBak[2].VFlip = 1;
	OamBak[2].Shape = 0;
	OamBak[2].Size = 3;
	OamBak[2].Pltt = 6;
	OamBak[2].ObjMode = 1;

	DmaArrayCopy(intro_vanPal, MEM_PAL_OBJ+0x20);
	DmaArrayCopy(intro_vanTiles, MEM_VRAM_OBJ+0xC00);
	OamBak[10].CharNo = 96;
	OamBak[10].VPos = 60;
	OamBak[10].Shape = 0;
	OamBak[10].Size = 3;
	OamBak[10].Pltt = 1;
	OamBak[11].CharNo = 160;
	OamBak[11].VPos = 60;
	OamBak[11].Shape = 0;
	OamBak[11].Size = 3;
	OamBak[11].Pltt = 1;
	OamBak[12].CharNo = 96;
	OamBak[12].VPos = 124;
	OamBak[12].Shape = 0;
	OamBak[12].Size = 3;
	OamBak[12].Pltt = 6;
	OamBak[12].VFlip = 1;
	OamBak[12].ObjMode = 1;
	OamBak[13].CharNo = 160;
	OamBak[13].VPos = 124;
	OamBak[13].Shape = 0;
	OamBak[13].Size = 3;
	OamBak[13].Pltt = 6;
	OamBak[13].VFlip = 1;
	OamBak[13].ObjMode = 1;

	DmaArrayCopy(intro_cearnPal, MEM_PAL_OBJ+0x40);
	DmaArrayCopy(intro_cearnTiles, MEM_VRAM_OBJ+0x1C00);
	OamBak[3].CharNo = 224;
	OamBak[3].VPos = 64;
	OamBak[3].Shape = 0;
	OamBak[3].Size = 2;
	OamBak[3].Pltt = 2;
	DmaArrayCopy(intro_darkPal, MEM_PAL_OBJ+0x60);
	DmaCopy(intro_darkTiles, MEM_VRAM_OBJ+0x2000, 580);
	OamBak[4].CharNo = 256;
	OamBak[4].VPos = 72;
	OamBak[4].Shape = 2;
	OamBak[4].Size = 3;
	OamBak[4].Pltt = 3;
	DmaArrayCopy(intro_sukaPal, MEM_PAL_OBJ+0x80);
	DmaArrayCopy(intro_sukaTiles, MEM_VRAM_OBJ+0x2400);
	OamBak[5].CharNo = 288;
	OamBak[5].VPos = 64;
	OamBak[5].Shape = 2;
	OamBak[5].Size = 2;
	OamBak[5].Pltt = 4;
	DmaArrayCopy(intro_kawaPal, MEM_PAL_OBJ+0xA0);
	DmaCopy(intro_kawaTiles, MEM_VRAM_OBJ+0x2800,2048);
	OamBak[6].CharNo = 320;
	OamBak[6].VPos = 16;
	OamBak[6].Shape = 0;
	OamBak[6].Size = 3;
	OamBak[6].Pltt = 5;


	OamBak[10].HPos = 250;
	OamBak[11].HPos = 250;
	OamBak[12].HPos = 250;
	OamBak[13].HPos = 250;
	OamBak[3].HPos = 250;
	OamBak[4].HPos = 250;
	OamBak[5].HPos = 250;
	OamBak[6].HPos = 250;

	pal_bg_mem[0] = 0x7BBA;
	cam_pos = cam_pos_dflt;
	InstallHBlank(IntroMode7);

	//sndPlaySound(29,SOUND_NORESTART);
	//sndCursor();
	//FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		t++;
		i++;

		CpuFastCopy(danTiles + (((t>>3) % 6) * 0x400), MEM_VRAM_OBJ, 0x800);

		if((i>>1) % 2 == 0)
		{
			DmaCopy(intro_darkTiles+512, MEM_VRAM_OBJ+0x2000, 256);
			DmaCopy(intro_kawaTiles+1024, MEM_VRAM_OBJ+0x2800,1024);
		}
		else
		{
			DmaCopy(intro_darkTiles, MEM_VRAM_OBJ+0x2000, 256);
			DmaCopy(intro_kawaTiles, MEM_VRAM_OBJ+0x2800,1024);
		}

		if((i>>1) < 120)
			danpos = 250 - (i>>1);

		if((i>>1) >= 340 && (i>>1) <= 348)
			pal_blend_asm5(danPal, BlackStrip, (u16*)MEM_PAL_OBJ, 16, (i>>1)-340);
		//This next part needs some math fixing - it starts too dark
		if((i>>1) >= 480 && (i>>1) <= 498)
			pal_blend_asm5(danPal, BlackStrip, (u16*)MEM_PAL_OBJ, 16, 17 - ((i>>1)-480));

		if((i>>1) == 320)
			DmaCopy(danTiles + 0x1A00, MEM_VRAM_OBJ + 0x800, 0x400);
		if((i>>1) == 500)
			DmaCopy(danTiles + 0x1800, MEM_VRAM_OBJ + 0x800, 0x400);

		if(((i>>1) > 240) && ((i>>1) < 680))
		{
			OamBak[10].HPos = 250 - ((i>>1)-240);
			OamBak[11].HPos = 250 - ((i>>1)-240) + 64;
			OamBak[12].HPos = 250 - ((i>>1)-240);
			OamBak[13].HPos = 250 - ((i>>1)-240) + 64;
			OamBak[3].HPos = 250 - ((i>>1)-240) + 34;
			OamBak[4].HPos = 250 - ((i>>1)-240) + 58;
			OamBak[5].HPos = 250 - ((i>>1)-240) + 74;
			OamBak[6].HPos = 250 - ((i>>1)-240) + 38;
		}
		if((i>>1) == 680)
		{
			//sndCursor();
			fader=1;
		}

		//if((i>>1) ==240) sndCursor();


		if(fader==100)
		{
			//sndCursor();
			break;
		}

		OamBak[0].HPos = danpos;
		OamBak[1].HPos = danpos;
		OamBak[2].HPos = danpos - 14;

		if(fader)
		{
			OamBak[0].HPos -= fader;
			OamBak[1].HPos -= fader;
			OamBak[2].HPos -= fader;

			SmoothWhiteFade((u16*)MEM_PAL,(u16*)MEM_PAL,512, 250+(fader>>1));
			fader++;
		}

		if((Trg & A_BUTTON) && (fader==0))
		{
			skip = 1;
			fader=1;
			DmaCopy(danTiles + 0x1800, MEM_VRAM_OBJ + 0x800, 0x400);
		}

		cam_pos.x += -1 * g_cosf;
		g_cosf= lu_cos(cam_phi) >> 4;
		g_sinf= lu_sin(cam_phi) >> 4;
		BF_SET(REG_DISPCNT, DCNT_MODE0, DCNT_MODE);
		REG_BG2CNT = BG_CBB(3) | BG_SBB(12) | BG_REG_32x32 | BG_PRIO(3);
		REG_BG1HOFS = -(t >> 4);
		REG_BG2VOFS = 0;
		REG_BLDCNT = BLD_BUILD(BLD_BG2, BLD_BD, 1);
		REG_BLDALPHA = 16;

	}

	InstallHBlank(0);
	REG_BG1HOFS = 0;
	ResetBackgrounds();
	DmaClear(0, MEM_VRAM, 0x10000);
	ClearSpriteGFX();
}








