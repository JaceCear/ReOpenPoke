#include "../openpoke.h"

// Module for credits at the beginning of the game

void BlackCredits()
{
	int timmy;

	REG_DISPCNT = 0;
	REG_BG1CNT = BG_4BPP | BG_SIZE1 | BG_PRIO(1) | 29 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;

	DmaArrayCopy(blackcredsTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(blackcredsPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(blackcredsMap, MEM_VRAM + 0xE800);

	REG_BG1HOFS = 8;
	REG_BLDCNT = BLD_BLACK | BLD_BG1;
	REG_BLDY = 16;

	REG_DISPCNT =  DCNT_MODE0 | DCNT_BG1;
	for(timmy = 16; timmy > 0; timmy--)
	{
		DoVBlank();
		DoVBlank();
		DoVBlank();
		REG_BLDY = timmy;
	}

	//just turn it off to ensure full viz
	REG_BLDCNT = 0;

	//simple wait loop
	while(1)
	{
		DoVBlank();
		timmy++;
		if(timmy == 250)
			break;
	}
	for(timmy=8; timmy < 256; timmy+=2)
	{
		DoVBlank();
		REG_BG1HOFS=timmy;
	}
	timmy=0;

	while(1)
	{
		DoVBlank();
		timmy++;
		if(timmy == 250)
			break;
	}

	REG_BLDCNT = BLD_BLACK | BLD_BG1;
	for(timmy = 0; timmy < 15; timmy++)
	{
		DoVBlank();
		DoVBlank();
		DoVBlank();
		REG_BLDY = timmy;
	}

	REG_BG1HOFS = 0;
	REG_BLDCNT = 0;
	REG_DISPCNT =  DCNT_MODE0 | DCNT_OBJ | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ_1D;
	REG_BG1CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(1) | 29 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;
	DmaClear(0, MEM_VRAM, VRAM_SIZE); //clean up crap
}
