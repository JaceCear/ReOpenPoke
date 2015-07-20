//======================================================================
//
//	OpenPoké credits roll
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "../openpoke.h"

extern void InstallHBlank(void * handler);

extern unsigned short intro_m7skyTiles[512];
extern unsigned short intro_m7skyMap[1024];
extern unsigned short intro_m7cloudsTiles[784];
extern unsigned short intro_m7cloudsMap[512];
extern unsigned short intro_m7groundTiles[768];
extern unsigned short intro_m7groundMap[1024];
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
	256<<8,
};

extern const unsigned int fontOamTiles[12288 / sizeof(unsigned int)];
extern const unsigned int fontOamPal[64 / sizeof(unsigned int)];

extern const unsigned short outro_dannyPal[16];
extern const unsigned short outro_daniPal[16];
extern const unsigned short outro_dannyTiles[3072];
extern const unsigned short outro_daniTiles[3072];

extern void InstallHBlank(void * handler);

const char oamfontWidths[] =
{
	6, 8, 7, 8, 8, 0, 13,6, 7, 7, 10,8, 6, 8, 5, 8,
	11,7, 10,9, 11,9, 10,11,11,11,6, 6, 10,0, 9, 9,
	0, 12,10,10,11,8, 8, 11,12,6, 7, 11,8, 16,14,13,
	10,14,10,9, 11,12,12,16,14,14,11,0, 0, 0, 8, 8,
	0, 10,8, 9, 9, 7, 7, 9, 10,5, 6, 8, 7, 12,10,10,
	8, 10,8, 8, 10,10,12,12,9, 10,9, 0, 0, 0, 7, 0,
};

#define NUMCREDITS 11
const char * const creds[] =
{
/*
	"\2MUSIC CREDITS\n"
	"pok~mon              \1go ichinose\n"
	"                    junichi masuda\n"
	"\2gyakuten saiban    \1\n"
	"\2doll judgement               \1zun\n"
	"\2zelda         \1koji kondo\n"
	"\2still alive   \1jonathan\n"
	"                   coulton\n",

	"\2MUSIC CREDITS\n"
	"new smb                 \1koji kondo\n"
	"\2rock the mike      \1\n"
	"\2duel of the fates  \1\n"
	"\2dr.wily            \1\n"
	"\2cave story         \1pixel",
*/
	"\2OPENPOK^ CORE TEAM\n"
	"\n"
	"programmers\1\n"
	" kawa\n"
	" cearn",

	"\2OPENPOK^ CORE TEAM\n"
	"\n"
	"environment and\n"
	"tool programmer\1\n"
	" kawa",

	"\2OPENPOK^ CORE TEAM\n"
	"\n"
	"research\1\n"
	" kawa\n"
	" cearn",

	"\2OPENPOK^ CORE TEAM\n"
	"\n"
	"interface design\1\n"
	" kawa\n"
	" darkdata",

	"\2DEMO GAME\n"
	"\n"
	"story               map design\1\n"
	" sukasa              darkdata",

	"\2POK^MON ORIGINAL STAFF\n"
	"\n"
	"executive producer\1\n"
	" satoshi tajiri\2\n"
	"\n"
	"artist\1\n"
	" ken sugimori\2\n"
	"\n"
	"director\1\n"
	" junichi masuda",

	"\2POK^MON ORIGINAL STAFF\n"
	"\n"
	"programmers\1\n"
	" hiroyuki nakamura\n"
	" masao taya\n"
	" satoshi nohara\n"
	" miyuki iwasawa\n"
	" daisuke goto\n",

	"\2POK^MON ORIGINAL STAFF\n"
	"\n"
	"system programmers\1\n"
	" tetsuya watanabe\n"
	" akito mori\n"
	" hisashi sogabe\n"
	" sousuke tamada\n"
	"\n"
	"My hat's off to you.",

	"\2PLAYTESTERS\1\n"
	" pozeal        gywall\n"
	" shark         xeruss\n"
	" arbewhat   tyty210\n"
	" hammy",

	"\2SPECIAL THANKS\1\n"
	" everybody in #acmlm\n"
	" andrea sartori\n"
	" mastermind_x\n"
	" bulbapedia contributors\n"
	"\n"
	" and GAME FREAK\n"
	" staff for not\n"
	" killing me ;)",

	"\2\n"
	"             THE     END", //this is just about centered
};

void WriteCredits(const char * str, int x, int y)
{
	int ch, nx=x, ny=y, s = 2, p=1; //,a;
	while( (ch= *str++) != 0 )
	{
//		if(ch=='É') ch='^';
//		if(ch=='é') ch='~';
		if(ch==2)
		{
			p=2;
		} else if(ch==1)
		{
			p=1;
		} else if(ch=='\n')
		{
			nx = x;
			ny += (p == 1) ? 14 : 12;
			if(ny > 64) nx += 56; //leave some room for the player
		} else if(ch==' ')
		{
			nx += oamfontWidths[ch-' ']-1;
		} else
		{
			OamBak[s].CharNo = 64 + ((ch-' ') * 4);
			OamBak[s].VPos = ny;
			OamBak[s].Pltt = p;
			OamBak[s].Shape = 0;
			OamBak[s].Size = 1;
			OamBak[s].ObjMode = 0;
//			for(a = 240; a >= nx; a-=32)
//			{
//				OamBak[s].HPos = a;
//				DoVBlank();
//			}
			OamBak[s].HPos = nx;
			nx+= oamfontWidths[ch-' ']-1;
			s++;
		}
	}
}

void WipeCredits()
{
	int i; //,j;
//	for(j=0;j<16;j++)
//	{
//		for(i=1;i<128;i++)
//		{
//			if(OamBak[i].HPos > -240)
//			{
//				OamBak[i].HPos -= j*2;
//			}
//		}
//		DoVBlank();
//	}
	for(i=2;i<128;i++)
	{
		OamBak[i].HPos = -240;
		OamBak[i].VPos = 180;
	}
}

void CreditsMode7()
{
	FIXED lam, lcf, lsf, lxr, lyr;
	int vc = REG_VCOUNT;

	if(IN_RANGE(vc, 70, 84))
		REG_BG2HOFS = sin_lut[vc - 70 + (t % 512)] >> 10;
	if(IN_RANGE(vc, 73, 84))
		REG_BG2VOFS = sin_lut[vc - 73 + (t % 512)] >> 12;

	if(vc == 162)
	{
		BF_SET(REG_DISPCNT, DCNT_MODE0, DCNT_MODE);
		REG_BG2CNT = BG_CBB(3) | BG_SBB(12) | BG_REG_32x32 | BG_PRIO(3);
		REG_BG1HOFS = -(t >> 4);
		REG_BG2VOFS = 0;
	}

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
		((OamData*)oam_mem)[1].HPos -= (vc % 4 < 3);
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

void Credits()
{
	int i=0,j=0,c=0;
	short * danTiles;
	short * danPal;

	if(MyPlayer.gender == 0)
	{
		danTiles = (short*)outro_dannyTiles;
		danPal = (short*)intro_dannyPal;
	} else
	{
		danTiles = (short*)outro_daniTiles;
		danPal = (short*)intro_daniPal;
	}

	REG_BG1CNT = BG_CBB(2) | BG_SBB(4) | BG_REG_32x32;
	REG_DISPCNT = DCNT_MODE1 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ | DCNT_OBJ_1D ;

	LoadTimeAdjustedColors((u16*)MEM_PAL_BG, intro_m7groundPal, 32);
	CpuFastArrayCopy(intro_m7groundTiles, MEM_VRAM);
	CpuFastArrayCopy(intro_m7groundMap, MEM_VRAM + 0x4000);

	CpuFastArrayCopy(intro_m7skyTiles, MEM_VRAM + 0xC000);
	CpuFastArrayCopy(intro_m7skyMap, MEM_VRAM + 0x6000);

	CpuFastArrayCopy(intro_m7cloudsTiles, MEM_VRAM + 0x8000);
	CpuFastArrayCopy(intro_m7cloudsMap, MEM_VRAM + 0x2000);

	DmaArrayCopy(fontOamPal, MEM_PAL_OBJ + 0x20);
	DmaArrayCopy(fontOamTiles, MEM_VRAM_OBJ + 0x800);

	DmaCopy(danPal, MEM_PAL_OBJ,32);
	DmaCopy(danTiles, MEM_VRAM_OBJ, 0x400);

#ifdef WITH_SHIRTCOLORS
	extern const u16 shirtcolors[32];
	*(u16*)0x05000218 = shirtcolors[(MyPlayer.shirtColor*2) + ((MyPlayer.gender % 2) * 16)];
	*(u16*)0x05000216 = shirtcolors[(MyPlayer.shirtColor*2)+1+((MyPlayer.gender % 2) * 16)];
#endif

	OamBak[0].CharNo = 0;
	OamBak[0].HPos = 32;
	OamBak[0].VPos = 80;
	OamBak[0].Shape = 2;
	OamBak[0].Size = 3;
	OamBak[0].Pltt = 0;
	OamBak[0].ObjMode = 0;
	OamBak[1].CharNo = 0;
	OamBak[1].HPos = 48;
	OamBak[1].VPos = 142;
	OamBak[1].VFlip = 1;
	OamBak[1].Shape = 2;
	OamBak[1].Size = 3;
	OamBak[1].Pltt = 6;
	OamBak[1].ObjMode = 1;

	pal_bg_mem[0] = 0x7BBA;
	cam_pos = cam_pos_dflt;
	InstallHBlank(CreditsMode7);

	sndPlaySound(78, SOUND_NORMAL);

	while(1)
	{
		DoVBlank();
		KeyRead();
		i++;
		j++;
		t++;

		DmaCopy(danTiles + (((i>>3) % 6) * 0x200), MEM_VRAM_OBJ, 0x400);

		if(j == 250)
		{
			WriteCredits((const char*)creds[c++],16,8);
		}

		if(j == 750 && c < NUMCREDITS)
		{
			WipeCredits();
			//OamBak[0].HPos = 32;
			//f = 32;
			j = 0;
		}

		cam_pos.x += 1 * (g_cosf / 4);
		g_cosf= lu_cos(cam_phi) >> 4;
		g_sinf= lu_sin(cam_phi) >> 4;
		BF_SET(REG_DISPCNT, DCNT_MODE0, DCNT_MODE);
		REG_BG2CNT = BG_CBB(3) | BG_SBB(12) | BG_REG_32x32 | BG_PRIO(3);
		REG_BG1HOFS = -(t >> 4);
		REG_BG2VOFS = 0;
		REG_BLDCNT = BLD_BUILD(BLD_BG2, BLD_BD, 1);
		REG_BLDALPHA = 16;

	}
}

