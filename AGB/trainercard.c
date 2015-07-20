//======================================================================
//
//	OpenPoké trainer card screen
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"

extern const unsigned short cardbgTiles[16];
extern const unsigned short cardTiles[1488];
extern const unsigned short cardPal[16];
extern const unsigned short cardMap[640];
extern const unsigned short card2Tiles[1488];
extern const unsigned short card2Pal[16];
extern const unsigned short card2Map[640];
extern const unsigned short badgesPal[16];
extern const unsigned short badgesTiles[512];

extern const unsigned short * const TrainerPics[];
extern u32 TotalFrames;

const int CardPics[] = { tpDanny, tpDani };

#ifdef WITH_SHIRTCOLORS
extern const unsigned short shirtcolors[32];
#endif

extern void TrainerCardScale(int i);
extern int TrainerCardScaleVal;

extern const unsigned short cursorTiles[64];
void TrainerCardBuildCursor()
{
	int i;
	for(i=0; i<4; i++)
	{
		OamBak[120+i].CharNo = 992;
		OamBak[120+i].Size = 0;
		OamBak[120+i].Shape = 0;
		OamBak[120+i].Pltt = 4;
		OamBak[120+i].Priority = 1;
	}
	OamBak[120].HFlip = 0;
	OamBak[120].VFlip = 0;
	OamBak[121].HFlip = 1;
	OamBak[121].VFlip = 0;
	OamBak[122].HFlip = 0;
	OamBak[122].VFlip = 1;
	OamBak[123].HFlip = 1;
	OamBak[123].VFlip = 1;
}

void TrainerCardMoveCursor(int x, int y, u32 pulse)
{
	OamBak[120].HPos = x - pulse;
	OamBak[120].VPos = y - pulse;
	OamBak[121].HPos = x + pulse;
	OamBak[121].VPos = y - pulse;
	OamBak[122].HPos = x - pulse;
	OamBak[122].VPos = y + pulse;
	OamBak[123].HPos = x + pulse;
	OamBak[123].VPos = y + pulse;
}

void TrainerCardSetTrainerTiles()
{
	int i,j,k=320;
	for(i=0; i<8;i++)
		for(j=0; j<8;j++)
			BG1MAP[213+(i*32)+j] = (1<<12) + k++;
}

void TrainerCardDrawBadge(int i)
{
	i--; //base zero plox

	BG1MAP[517 + (i*3)] = 0x2200 + (i*4);
	BG1MAP[518 + (i*3)] = 0x2201 + (i*4);
	BG1MAP[549 + (i*3)] = 0x2202 + (i*4);
	BG1MAP[550 + (i*3)] = 0x2203 + (i*4);
}

void TrainerCardDrawBadgeFlavor(int i)
{
	i--;
	DrawFrame(1,28,4,9);
	vwClearLine(1,26);
	vwClearLine(1,27);
	vwClearLine(1,30);
	vwClearLine(1,31);
	vwClearLine(1,34);
	vwClearLine(1,35);
	if(GETBIT(ScriptFlags,HAVEBADGE1+i)) vwWrite(0,105,BadgeFlavors[i]);
	vwSetLine(3,24,5,512,15);
	vwSetLine(3,24,8,576,15);
	vwSetLine(3,24,10,640,15);
}

void TrainerCardFlavors()
{
	int i = 1, j = 0;
	CpuFastArrayCopy(cursorTiles,MEM_VRAM_OBJ+0x7C00);
	TrainerCardBuildCursor();

	TrainerCardDrawBadgeFlavor(i);

	while(1)
	{
		DoVBlank();
		KeyRead();

		j++;
		TrainerCardMoveCursor((i*24)+12,132, 5 + ((j >> 2) % 4));

		if((Trg & KEY_LEFT) || (Trg & KEY_RIGHT))
		{
			i = wrap(i + key_tri_horz(), 1, 9);
			TrainerCardDrawBadgeFlavor(i);
		} else
		{
			if(Trg) break;
		}
	}

	ClearOamBak();
	Trg = 0;
}

void TrainerCardFront()
{
	char buffy[128];

	DmaArrayCopy(cardTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(cardPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(cardMap, MEM_VRAM + 0xE000);

	REG_DISPCNT |= DCNT_BG1;

	CleanUpBG0();
	vwClear(0);
	vwBlackTransparentLUT();

	sprintf(buffy,strTrainerCardIDNo, (u16)MyPlayer.trainerid);
	vwWrite(5,2,buffy);
	vwSetLine(18,8,2,96,15);

	sprintf(buffy,strTrainerCardName, MyPlayer.name);
	vwWrite(84,5,buffy);
	vwSetLine(3,16,4,106,15);
	vwSetLine(3,16,5,138,15);

	vwWrite(84,24,strTrainerCardMoney);
	vwSetLine(3,8,8,202,15);
	sprintf(buffy,"$%d", MyPlayer.cash);
	vwWrite(54-vwf_measure_string(buffy),16,buffy);
	vwSetLine(11,8,8,160,15);

	vwWrite(84,40,strTrainerCardPokedex);
	vwSetLine(3,8,10,266,15);
	sprintf(buffy,"%d", MyDex.caughtrate);
	vwWrite(56-vwf_measure_string(buffy),32,buffy);
	vwSetLine(11,8,10,224,15);

	vwWrite(84,56,strTrainerCardTime);
	vwSetLine(3,8,12,330,15);
	sprintf(buffy,"%2d:%02d", MyPlayer.Hours, MyPlayer.Minutes);
	vwWrite(5,48,buffy);
	vwSetLine(14,8,12,288,15);

	vwNormalLUT();
}

void TrainerCardBack()
{
	DmaArrayCopy(card2Tiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(card2Pal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(card2Map, MEM_VRAM + 0xE000);

	REG_DISPCNT &= ~DCNT_BG1;

	CleanUpBG0();
	vwBlackTransparentLUT();
	vwClear(0);

	vwWrite(2,3,MyPlayer.name);
	vwSetLine(18,8,2,96,15);

	vwNormalLUT();
}

void TrainerCard()
{
	char buffy[128], flip = 0;

	CleanUpCrap();
	ClearOamBak();
	REG_BG1HOFS= 8;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;

	LoadFrame();
	LoadSpriteColors();

	DmaArrayCopy(cardbgTiles, MEM_VRAM + 0x2000);
	DmaClear(0x01000100, MEM_VRAM + 0xF000, 0x500);

	LZ77UnCompVram((u8*)TrainerPics[CardPics[MyPlayer.gender]<<1], (u8*)MEM_VRAM + 0x2800);
	DmaCopy((u8*)TrainerPics[(CardPics[MyPlayer.gender]<<1)+1], MEM_PAL_BG + 32, 32);
	TrainerCardSetTrainerTiles();
	DmaArrayCopy(badgesTiles, MEM_VRAM + 0x4000);
	DmaArrayCopy(badgesPal, MEM_PAL_BG + 64);
	for(flip=0; flip < 7; flip++)
	{
		if(GETBIT(ScriptFlags,HAVEBADGE1+flip)) TrainerCardDrawBadge(flip+1);
	}
	flip = 0;

#ifdef WITH_SHIRTCOLORS
		*(u16*)0x0500003C = shirtcolors[(MyPlayer.shirtColor*2) + ((MyPlayer.gender%2)*16)];
		*(u16*)0x0500003E = shirtcolors[(MyPlayer.shirtColor*2)+1+((MyPlayer.gender%2)*16)];
#endif

	TrainerCardFront();

	FadeIn();
	TrainerCardScale(0);

	while(1)
	{
		DoVBlank();
		KeyRead();

		if((Trg & SELECT_BUTTON) && (flip == 0))
		{
			TrainerCardFlavors();
			TrainerCardFront();
		}

		if(
				((Trg & A_BUTTON) && (flip == 0)) ||
				((Trg & B_BUTTON) && (flip == 1))
			)
		{
			REG_BLDCNT = BLD_BLACK | BLD_BG2 | BLD_BG1 | BLD_BG0;
			for(TrainerCardScaleVal = 256; TrainerCardScaleVal >= 16; TrainerCardScaleVal-=16)
			{
				REG_BLDY = (256 - TrainerCardScaleVal) / 20;
				DoVBlank();
			}
			flip ^= 1;
			if(flip == 0)
			{
				TrainerCardFront();
			} else
			{
				TrainerCardBack();
			}
			for(TrainerCardScaleVal = 16; TrainerCardScaleVal < 256; TrainerCardScaleVal+=16)
			{
				REG_BLDY = (256 - TrainerCardScaleVal) / 20;
				DoVBlank();
			}
//			if(flip == 0)
//			{
//				TrainerCardFront(1);
//			} else
//			{
//				TrainerCardBack(1);
//			}
			Trg = 0;
		}

		if(TotalFrames % 60 == 0)
		{
			TimeKeeper();
			if(flip == 0)
			{
				sprintf(buffy,"%2d:%02d", MyPlayer.Hours, MyPlayer.Minutes);
				vwWrite(5,48,buffy);
			}
		}

		if(
				((Trg & B_BUTTON) && (flip == 0)) ||
				((Trg & A_BUTTON) && (flip == 1))
			)
		{
			break;
		}
	}

	FadeOut();
	TrainerCardScaleVal = 256;
	TrainerCardScale(1);
	vwNormalLUT();
}
