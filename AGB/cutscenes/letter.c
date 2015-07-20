#include "../openpoke.h"

extern const unsigned short openingletterPal[16];
extern const unsigned short openingletterTiles[496];
extern const unsigned short openingletterMap[640];
/** \brief Writes the specified page on the welcome sequence.
\todo Make this use an array. It's ugly this way */
void WriteLetter(int page)
{
	AGBPrintf("WriteLetter: page %d\n",page);
	vwClear(0);
	vwBlackTransparentLUT();
	vwWriteG(0,0,strIntroLetter[page]);
	DoVBlank();
	vw_SetSmall();
	vwWhiteTransparentLUT();
	if(page == 0)
		vwWrite(35,125,"¢NEXT");
	else
		vwWrite(4,125,"¢NEXT £BACK");
	vwSetLine(21,20,19, 608, 15);
	vw_SetBig();
	vwNormalLUT();
}

/** \brief Handles crossfading the welcome sequence text */
void IntroLetterFadeOut()
{
	u32 blendi;
	REG_BLDCNT = BLD_BOT(BLD_BG2) | BLD_STD | BLD_BG0;

	for(blendi = 0; blendi < 0x10; blendi++)
	{
		REG_BLDALPHA = (blendi << 8) + (0x10 - blendi);
		DoVBlank();
	}
}

/** \brief Opposite of IntroLetterFadeOut */
void IntroLetterFadeIn()
{
	u32 blendi;
	REG_BLDCNT = BLD_BOT(BLD_BG2) | BLD_STD | BLD_BG0;

	for(blendi = 0; blendi < 0x11; blendi++)
	{
		REG_BLDALPHA = ((0x10 - blendi) << 8) + blendi;
		DoVBlank();
	}
}

/** \brief Displays the welcome sequence.

This had a Pikachu in the corner in the original.
*/
void OpeningLetter()
{
	int page = 0;
	//int mawile=0, mawiletimer=0;

	HelpContext = 0;

	REG_BG0VOFS = 4;
	sndPlaySound(57, SOUND_NORESTART);

	LoadFrame();
	DmaClear(0, MEM_VRAM, VRAM_SIZE); //clean up crap
	CpuFastArrayCopy(openingletterPal,MEM_PAL_BG);
	CpuFastArrayCopy(openingletterTiles,MEM_VRAM_FRONT);
	CpuFastArrayCopy(openingletterMap,MEM_VRAM_FRONT+0xE000);
	REG_BG2HOFS = 8;

	//LoadMawile();

	vwSetLine(2,32,2,96,15);
	vwSetLine(2,32,4,160,15);
	vwSetLine(2,32,6,224,15);
	vwSetLine(2,32,8,288,15);
	vwSetLine(2,32,10,352,15);
	vwSetLine(2,32,12,416,15);
	vwSetLine(2,32,14,480,15);

	ResetDispCnt();
	FadeIn();

	REG_BLDCNT = BLD_BOT(BLD_BG2) | BLD_STD | BLD_BG0;
	REG_BLDALPHA = 0x1000;
	WriteLetter(0);
	IntroLetterFadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		/*
		mawiletimer++;
		if(mawiletimer==4)
		{
			mawiletimer=0;
			mawile++;
			if(mawile==16) mawile=0;
			LoadMawileFrame(mawile);
		}
		*/

		if(page == 0)
		{
			if(Trg & A_BUTTON)
			{
				IntroLetterFadeOut();
				page = 1;
				WriteLetter(1);
				IntroLetterFadeIn();
			}
		}
		else if(page == 1)
		{
			if(Trg & A_BUTTON)
			{
				IntroLetterFadeOut();
				page = 2;
				WriteLetter(2);
				IntroLetterFadeIn();
			}
			else if(Trg & B_BUTTON)
			{
				IntroLetterFadeOut();
				page = 0;
				WriteLetter(0);
				IntroLetterFadeIn();
			}
		}
		else if(page == 2)
		{
			if(Trg & A_BUTTON)
			{
				break;
			}
			else if(Trg & B_BUTTON)
			{
				IntroLetterFadeOut();
				page = 1;
				WriteLetter(1);
				IntroLetterFadeIn();
			}
		}
	}
	FadeOut();
	REG_BG0VOFS = 0;
	REG_BG2VOFS = 0;
	DmaClear(0, MEM_VRAM, VRAM_SIZE); //clean up crap
}
