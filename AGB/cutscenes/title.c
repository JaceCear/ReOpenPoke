#include "../openpoke.h"

const unsigned short TitleFades[64]=
{
	0x001C,0x001A,0x0019,0x0017,0x0015,0x0013,0x0011,0x000F,
	0x000D,0x000B,0x0009,0x0007,0x0005,0x0003,0x0002,0x0000,
	0x0000,0x0001,0x0003,0x0005,0x0007,0x0009,0x000B,0x000D,
	0x000F,0x0011,0x0013,0x0015,0x0017,0x0018,0x001A,0x001C,
	0x65A5,0x69C6,0x69E8,0x6A0A,0x6E4C,0x6E6E,0x728F,0x72B1,
	0x72F3,0x7715,0x7736,0x7B58,0x7B9A,0x7FBC,0x7FDE,0x7FFF,
	0x7FFF,0x7FDE,0x7FBC,0x7B9A,0x7B78,0x7737,0x7715,0x76F3,
	0x72D1,0x728F,0x6E6E,0x6E4C,0x6A2A,0x69E8,0x69C7,0x65A5,
};

#define MAXTITLEPARTICLES 32

void TitleScreen(int skip)
{
	int i, f = 0;
	int t = 0, buildstep = 0,buildt = 0;

	int particleX[MAXTITLEPARTICLES];
	int particleY[MAXTITLEPARTICLES];
	int particleS[MAXTITLEPARTICLES];
	int particleT[MAXTITLEPARTICLES];

	ClearOamBak();
	REG_BG3CNT |= 1 << BG_CBB_SHIFT;

	DmaArrayCopy(titlebackPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(titlebackTiles, MEM_VRAM + 0x4000);
	DmaArrayCopy(titlebackMap, MEM_VRAM + 0xf000);

	DmaArrayCopy(titlemonTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(titlemonMap, MEM_VRAM + 0xe800);

	for(i = 0; i < MAXTITLEPARTICLES; i++)
	{
		particleX[i] = rrand(32) * 8;
		particleY[i] = 170;
		particleS[i] = rrand(3) + 1;
		particleT[i] = rrand(2);
	}

	REG_BG0HOFS = 0;
	REG_BG0VOFS = -2;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = -32;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;
	REG_BG3HOFS = 0;
	REG_BG3VOFS = 0;

	DmaArrayCopy(titlelogoTiles, MEM_VRAM + 0x8000);
	DmaArrayCopy(titlelogoPal, MEM_PAL_BG + 0x0020);
	for(i=0;i<320;i++) BG0MAP[i] = titlelogoMap[i] | 0x1000;

	DmaArrayCopy(titleflavorTiles, MEM_VRAM_OBJ + 0x0000);
	DmaArrayCopy(titleflavorPal, MEM_PAL_OBJ + 0x0000);

	DmaArrayCopy(titletextsTiles, MEM_VRAM_OBJ + 0x0800);

	DmaArrayCopy(titleparticlesTiles, MEM_VRAM_OBJ + 0x0c00);
	DmaArrayCopy(titleparticlesPal, MEM_PAL_OBJ + 0x0020);

	OamBak[0].Size = 3;
	OamBak[0].Shape = 1;
	OamBak[0].HPos = 63;
	OamBak[0].VPos = 55;
	OamBak[0].CharNo = 0;
	OamBak[0].ObjMode = 1;
	OamBak[1].Size = 3;
	OamBak[1].Shape = 1;
	OamBak[1].HPos = 63+64;
	OamBak[1].VPos = 55;
	OamBak[1].CharNo = 32;
	OamBak[1].ObjMode = 1;

	for(i=0; i<7; i++)
	{
		OamBak[2+i].Size = 1;
		OamBak[2+i].Shape = 1;
		OamBak[2+i].Pltt = 0;
		OamBak[2+i].CharNo = 64 + (i<<2);
	}
	for(i=0; i<7; i++)
	{
		OamBak[2+i].HPos = 8 + (i<<5);
		OamBak[2+i].VPos = 152;
	}
	for(i=0; i<2; i++)
	{
		OamBak[6+i].VPos = 152;
		OamBak[6+i].HPos = 169 + (i<<5);
	}

	REG_DISPCNT =  DCNT_MODE0 | DCNT_BG2 | DCNT_BG3;
	REG_BLDCNT = BLD_WHITE | BLD_BG3;

	if(skip)
	{
		REG_DISPCNT =  DCNT_MODE0 | DCNT_OBJ | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ_1D;
		REG_BLDCNT = 0;
		buildstep = 3;
		REG_BG1VOFS = 0;
	}

	sndPlaySound(80,SOUND_NORESTART);

	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & A_BUTTON)
			break;
		if(Trg & START_BUTTON)
			break;
		if(buildstep == 0)
		{
			REG_BLDY = 16 - (buildt>>2);
			buildt++;
			if(buildt==64)
			{
				REG_DISPCNT |= DCNT_BG1;
				buildstep++;
				buildt=0;
			}
		}
		else if(buildstep == 1)
		{
			REG_BG1VOFS = -32 + (buildt<<1);
			buildt++;
			if(buildt == 17)
			{
				REG_BG0VOFS = -64;
				REG_DISPCNT |=  DCNT_BG0;
				REG_BLDCNT = 0;
				buildstep++;
				buildt=0;
			}
		}
		else if(buildstep == 2)
		{
			REG_BG0VOFS = 64 - buildt;
			buildt+=2;
			if(buildt >= 67)
			{
				REG_DISPCNT |=  DCNT_OBJ | DCNT_OBJ_1D;
				buildstep++;
				HelpContext = 0;
				t = 0;
				f = 0;
			}
		}

		else if(buildstep == 3)
		{
			t++;
			f++;

			if(t == 20)
				for(i=0; i<2; i++)
					OamBak[6+i].VPos = 152;
			if(t == 40)
				for(i=0; i<2; i++)
					OamBak[6+i].VPos = 160;
			if(t >= 40) t = 0;

			pal_bg_mem[15] = TitleFades[((f >> 3) % 32)];
			pal_bg_mem[31] = TitleFades[((f >> 2) % 32) + 32];

			for(i = 0; i < MAXTITLEPARTICLES; i++)
			{
				particleY[i] -= particleS[i];
				if(particleY[i] < 0)
				{
					particleX[i] = rrand(32) * 8;
					particleY[i] = 170;
					particleS[i] = rrand(3) + 1;
					particleT[i] = rrand(2);
				}
				OamBak[64+i].CharNo = 96 + (particleT[i] * 2) + (f % 2);
				OamBak[64+i].HPos = particleX[i];
				OamBak[64+i].VPos = particleY[i];
				OamBak[64+i].Pltt = 1;
				OamBak[64+i].Priority = 2;
			}
		}
	}


	FadeOut();

	REG_BLDCNT = 0;
	REG_BLDALPHA = 0;
	ResetBackgrounds();
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	ClearOamBak();
}
