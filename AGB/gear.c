#include "openpoke.h"

extern const unsigned short gearPal[16];
extern const unsigned short gearTiles[528];
extern const unsigned short gearMap[640];
extern const unsigned short gearbuttonsTiles[960];

extern const unsigned short gearphonePal[16];
extern const unsigned short gearphoneTiles[432];
extern const unsigned short gearphoneMap[640];

extern const unsigned short worldmapPal[32];
extern const unsigned short worldmapTiles[5408];
extern const unsigned short worldmapMap[640];

unsigned char PhoneBits[4];

extern const void * const PhoneScripts[];

void PokeGear_TownMap(int i)
{
	if(i==0)
	{
		REG_BG3CNT |= BG_8BPP;
		REG_BG3HOFS = 24;
		LZ77UnCompVram(worldmapTiles, (short*)MEM_VRAM + 0x0000);
		LZ77UnCompVram(worldmapMap, (short*)MEM_VRAM + 0xF000);
		DmaArrayCopy(worldmapPal, MEM_PAL_BG + 0x0000);
	} else if(i==1)
	{
		DmaClear(0,MEM_VRAM+0xF000,0x7FF);
		REG_BG3CNT &= ~BG_8BPP;
		REG_BG3HOFS = 0;
	}
}

void PokeGear_Phone(int i)
{
	int j;
	static int k;
	static int c=0;
	static int phonelist[32];

	if(i==0)
	{
		k = 0;
		//SETBIT(PhoneBits,1);
		PhoneBits[0] = 0xFE;
		DmaArrayCopy(gearphonePal, MEM_PAL_BG + 0x0000);
		DmaArrayCopy(gearphoneTiles, MEM_VRAM + 0x0000);
		DmaArrayCopy(gearphoneMap, MEM_VRAM + 0xE000);

		vw_SetSmall();
		for(j = 0; j < 8; j++)
		{
			if(GETBIT(PhoneBits,j))
			{
				vwWrite(24,((k+3)*12)+2,phonenames[j]);
				phonelist[k] = j;
				k++;
			}
		}
		vw_SetBig();
		vwWrite(12,((c+3)*12)+2,strArrow);
		REG_BG3CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(0) | 30 << BG_SBB_SHIFT | 2 << BG_CBB_SHIFT | BG_MOSAIC;
		for(i=96; i < 640; i++)
		{
			BG3MAP[i] = (i + 128) | 0xF000;
		}
	} else if(i==1)
	{
		DmaClear(0,MEM_VRAM+0xE000,0x7FF);
		REG_BG3CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(2) | 30 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;
	} else if(i==2)
	{
		if(Trg & KEY_A)
		{
			extern void Phonecall(const char *caller);
			void (*ThisFunc)(void);
			Phonecall(phonenames[phonelist[c]]);
			ThisFunc = PhoneScripts[phonelist[c]];
			ThisFunc();
			//sayf(SYSTEM, "Calling %s.", phonenames[phonelist[c]]);
			PokeGear_Phone(0); //rebuild
		} else if(Trg & KEY_UP || Trg & KEY_DOWN)
		{
			vwWrite(12,((c+3)*12)+2,strArrowBlank);
			c = wrap(c + key_tri_vert(), 0, k);
			vwWrite(12,((c+3)*12)+2,strArrow);
		}
	}
}

const void * const PokeGearApps[] =
{
	PokeGear_TownMap,
	PokeGear_Phone,
};

void PokeGear_FadeIn()
{
	int ii;
	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(ii=16; ii>=0; ii--)
	{
		DoVBlank();
		REG_BLDY = ii;
	}
}
void PokeGear_FadeOut()
{
	int ii;
	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG2 | BLD_BG3 | BLD_OBJ;
	for(ii=0; ii<=16; ii++)
	{
		DoVBlank();
		REG_BLDY = ii;
	}
}

void PokeGear()
{
	int i, CurrentApp = 0, oldHC = HelpContext;
	void (*ThisFunc)(int);

	CleanUpCrap();

	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;
	REG_BG3HOFS = 0;
	REG_BG3VOFS = 0;

	DmaArrayCopy(gearTiles, MEM_VRAM + 0x4000);
	DmaArrayCopy(gearPal, MEM_PAL_BG + 0x0180);
	//DmaArrayCopy(gearMap, MEM_VRAM + 0xE800);
	for(i=0;i<32*20;i++) BG1MAP[i] = (gearMap[i] + 512) | 0xC000;

	HelpContext = -1;

	FadeIn();

	REG_BLDCNT = BLD_BLACK | BLD_BG0 | BLD_BG1 | BLD_BG3 | BLD_OBJ;
	REG_BLDY = 16;

	ThisFunc = PokeGearApps[CurrentApp];
	ThisFunc(0);
	PokeGear_FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & KEY_R)
		{
			PokeGear_FadeOut();
			ThisFunc(1);
			if(CurrentApp<1) CurrentApp++; else CurrentApp=0;
			ThisFunc = PokeGearApps[CurrentApp];
			ThisFunc(0);
			PokeGear_FadeIn();
		} else if(Trg & KEY_L)
		{
			PokeGear_FadeOut();
			ThisFunc(1);
			if(CurrentApp) CurrentApp--; else CurrentApp=1;
			ThisFunc = PokeGearApps[CurrentApp];
			ThisFunc(0);
			PokeGear_FadeIn();
		} else if(Trg & KEY_B)
		{
			PokeGear_FadeOut();
			ThisFunc(1);
			FadeOut();
			HelpContext = oldHC;
			return;
		} else
		{
			ThisFunc(2);
		}
	}
}
