#include "../openpoke.h"

const unsigned short evoPal[]=
{
	0x0842,0x1083,0x18C5,0x2506,0x2D48,0x3989,0x41CB,0x4A0D,
	0x564E,0x5E90,0x6AD1,0x7313,0x7F55,0x7313,0x6AD1,0x5E90,
	0x564E,0x4A0D,0x41CB,0x3989,0x2D48,0x2506,0x18C5,0x1083,
	0x0842,0x1083,0x18C5,0x2506,0x2D48,0x3989,0x41CB,0x4A0D,
	0x564E,0x5E90,0x6AD1,0x7313,0x7F55
};

const unsigned char evoBGWave[] =
{
	0xB,0xB,0xB,0xB,0xB,0xB,0xB,0xA,0xA,0xA,0x9,0x9,0x8,
	0x8,0x7,0x7,0x6,0x6,0x6,0x5,0x5,0x4,0x4,0x4,0x4,0x4,
	0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x5,0x5,0x5,0x6,0x6,0x7,
	0x7,0x8,0x8,0x9,0x9,0xA,0xA,0xA,0xB,0xB,0xB,0xB,0xB,
};

const unsigned short BlackStrip[16] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

extern const unsigned short evo_bg1Tiles[1760];
extern const unsigned short evo_bg2Tiles[1728];
extern const unsigned short evo_bg1Map[640];
extern const unsigned short evo_bg2Map[640];
extern const unsigned short battlegrassPal[16];
extern const unsigned short battlegrassTiles[1808];
extern const unsigned short battlegrassMap[2048];
extern const unsigned short battleinterfacePal[16];
extern const unsigned short battleinterfaceTiles[304];
extern const unsigned short battleinterfaceMap[2048];

int EvolutionCutscene(aPokemon * mon, int newSpecies)
{
	int wPalCursor = 0, wWaveCursor = 0, i;
	int oldSpecies = GetMonsterStats(mon, pSpecies);

	CleanUpCrap();
	ClearOamBak();
	REG_BG1CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(1) | 28 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;
	REG_BG2CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(1) | 29 << BG_SBB_SHIFT | 1 << BG_CBB_SHIFT | BG_MOSAIC;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;
	DmaArrayCopy(battlegrassTiles, MEM_VRAM + 0x4000);
	DmaArrayCopy(battlegrassMap, MEM_VRAM + 0xE000);
	DmaArrayCopy(battlegrassPal, MEM_PAL_BG);

	CpuFastArrayCopy(battleinterfaceTiles,MEM_VRAM+0x8000);
	CpuFastCopy(battleinterfacePal,MEM_PAL_BG+0x1C0,16);
	u16* meh = (u16*)(MEM_VRAM + 0xF800);
	for(i=0;i<640;i++)
		meh[i] = battleinterfaceMap[i] | 0xE000;
	vwSetLine(1,28,15,96,14);
	vwSetLine(1,28,17,160,14);

	FadeIn();

	LoadPokemonPic(oldSpecies,(LPP_SHINY*IsShiny(mon)),MEM_VRAM_OBJ,pal_obj_bank[0],mon->Personal.Personal);
	LoadPokemonPic(newSpecies,(LPP_SHINY*IsShiny(mon)),MEM_VRAM_OBJ+0x800,pal_obj_bank[1],mon->Personal.Personal);
	OamBak[1].CharNo = 0;
	OamBak[1].Pltt = 0;
	OamBak[1].HPos = 88;
	OamBak[1].VPos = 32;
	OamBak[1].Size = 3;

	btlsays("What? %s is evolving!\1", mon->Personal.Nickname);
	sndWaitForCry(oldSpecies, 60);
	sndPlaySound(1, 0);

	for(i=0; i < 32; i++)
	{
		pal_blend_asm5(battlegrassPal, BlackStrip, (u16*)MEM_PAL,16,i);
		DoVBlank();
	}
	DmaArrayCopy(BlackStrip, MEM_PAL);

	DmaArrayCopy(evo_bg1Tiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(evo_bg1Map, MEM_VRAM + 0xE000);
	DmaArrayCopy(evo_bg2Tiles, MEM_VRAM + 0x4000);
	DmaArrayCopy(evo_bg2Map, MEM_VRAM + 0xE800);
	REG_BLDCNT = BLD_BUILD(BLD_BG1, BLD_BG2, 1);
	REG_BLDALPHA = BLDA_BUILD(8, 8);
	i = 16;
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(i > 1)
		{
			DmaCopy(evoPal, MEM_PAL_BG + i, 16);
			pal_blend_asm5(MEM_PAL_OBJ, WhiteStrip, (u16*)MEM_PAL_OBJ+32,16,36-(i<<1));
			OamBak[1].Pltt = 2;
			i--;
		} else
		{
			DmaCopy(evoPal+(wPalCursor>>1), MEM_PAL_BG + 2, 28);
			wPalCursor++;
			if(wPalCursor == 48) wPalCursor = 0;
		}
		REG_BG1HOFS = evoBGWave[wWaveCursor % 52];
		REG_BG1VOFS = -(evoBGWave[wWaveCursor % 52]/2)+12;
		REG_BG2HOFS = evoBGWave[(wWaveCursor+26) % 52];
		REG_BG2VOFS = -(evoBGWave[(wWaveCursor+26) % 52]/2)+12;
		wWaveCursor++;

		if(wWaveCursor == 400) break;
		if(Trg == B_BUTTON)
		{
			for(i = 0; i < 16; i++)
			{
				DoVBlank();
				pal_blend_asm5(WhiteStrip, BlackStrip, (u16*)MEM_PAL_BG,16,i<<1);
				pal_blend_asm5(WhiteStrip, MEM_PAL_OBJ, (u16*)MEM_PAL_OBJ+32,16,i<<1);
			}
			REG_BG2HOFS = 0;
			REG_BG2VOFS = 0;
			REG_DISPCNT &= ~DCNT_BG1;
			DmaArrayCopy(battlegrassTiles, MEM_VRAM + 0x4000);
			DmaArrayCopy(battlegrassMap, MEM_VRAM + 0xE000);
			for(i = 0; i < 16; i++)
			{
				DoVBlank();
				pal_blend_asm5(BlackStrip, battlegrassPal, (u16*)MEM_PAL_BG,16,i<<1);
			}
			btlsays("Huh? %s\nstopped evolving!", PokeNames[oldSpecies]);
			FadeOut();
			ResetBackgrounds();
			CleanUpCrap();
			return 0;
		}
	}
	DmaCopy(MEM_PAL_BG, MEM_PAL_BG + 16, 16);
	for(i = 0; i < 16; i++)
	{
		DoVBlank();
		pal_blend_asm5(MEM_PAL_BG + 32, WhiteStrip, (u16*)MEM_PAL_BG,16,i<<1);
	}
	OamBak[1].CharNo = 64;
	for(i = 0; i < 16; i++)
	{
		DoVBlank();
		pal_blend_asm5(WhiteStrip, BlackStrip, (u16*)MEM_PAL_BG,16,i<<1);
		pal_blend_asm5(WhiteStrip, MEM_PAL_OBJ+32, (u16*)MEM_PAL_OBJ+32,16,i<<1);
	}
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;
	REG_DISPCNT &= ~DCNT_BG1;
	DmaArrayCopy(battlegrassTiles, MEM_VRAM + 0x4000);
	DmaArrayCopy(battlegrassMap, MEM_VRAM + 0xE000);
	for(i = 0; i < 16; i++)
	{
		DoVBlank();
		pal_blend_asm5(BlackStrip, battlegrassPal, (u16*)MEM_PAL_BG,16,i<<1);
	}
	btlsays("Congratulations! Your %s\nevolved into %s!\r\1", PokeNames[oldSpecies], PokeNames[newSpecies]);
	FadeOut();
	ResetBackgrounds();
	CleanUpCrap();
	return newSpecies;
}
