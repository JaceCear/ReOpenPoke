#include "../openpoke.h"

extern const unsigned long* itemicons[];

extern const unsigned short useitemPal[16];
extern const unsigned short useitemTiles[160];
extern const unsigned short useitemMap[640];

void ItemUseAnimation(int itemindex, aPokemon * target)
{
	//aPokemon * mon = DecryptMonster(target);
	//ssGrowth * myG = GetGrowthSubstruct(mon);
	//int species = myG->Species;
	int species = GetMonsterStats(target, pSpecies);
	int itempicbuf[0x120];
	int i = 0;
	//EncryptMonster(mon);
	REG_DISPCNT = 0;
	CleanUpCrap();
	ClearOamBak();
	DmaArrayCopy(useitemPal, MEM_PAL);
	DmaArrayCopy(useitemTiles, MEM_VRAM);
	DmaArrayCopy(useitemMap, MEM_VRAM + 0xE000);
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	REG_BG2HOFS = 0;
	REG_BG2VOFS = 0;
	REG_BG3HOFS = 0;
	REG_BG3VOFS = 0;
	LoadPokemonPic(species,(LPP_SHINY*IsShiny(target)),MEM_VRAM_OBJ,pal_obj_bank[0],target->Personal.Personal);
	OamBak[1].CharNo = 0;
	OamBak[1].Pltt = 0;
	OamBak[1].HPos = 88;
	OamBak[1].VPos = 40;
	OamBak[1].Size = 3;
	DmaCopy(itemicons[(itemindex*2)+1], MEM_PAL_OBJ+0x20, 32);
	LZ77UnCompWram((u8*)itemicons[itemindex*2], itempicbuf);
	DmaCopy(itempicbuf, MEM_VRAM_OBJ+0x800, 0x60);
	DmaCopy(itempicbuf + 0x18, MEM_VRAM_OBJ + 0x880, 0x60);
	DmaCopy(itempicbuf + 0x30, MEM_VRAM_OBJ + 0x900, 0x60);
	OamBak[0].CharNo = 64;
	OamBak[0].Pltt = 1;
	OamBak[0].HPos = 240;
	OamBak[0].VPos = 55;
	OamBak[0].Size = 2;
	OamBak[0].AffineMode = 1;
	OamBak[0].AffineParamNo_L = 0;
	OamBak[0].AffineParam = 0x100;
	OamBak[3].AffineParam = 0x100;
	ResetDispCnt();
	FadeIn();
	for(i = 0; i < 50; i++)
	{
		DoVBlank();
		KeyRead();
		if(Trg) goto fin;
	}
	OamBak[0].HPos = 102;
	for(i = 0; i < 20; i++)
	{
		DoVBlank();
		KeyRead();
		if(Trg) goto fin;
	}
	for(i = 0; i <= 32; i++)
	{
		DoVBlank();
		OamBak[0].AffineParam = 0x100 + (i << 4);
		OamBak[3].AffineParam = 0x100 + (i << 4);
		KeyRead();
		if(Trg) goto fin;
	}
	OamBak[0].HPos = 240;
	for(i = 0; i < 20; i++)
	{
		DoVBlank();
		KeyRead();
		if(Trg) goto fin;
	}
	sayf(SYSTEM, strItemWasUsed, items[itemindex].name, target->Personal.Nickname);

fin:
	FadeOut();
	return;
}
