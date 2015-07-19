#include "../openpoke.h"

extern void BlackCredits();

void StartupIntro()
{
	AGBPrint("StartupIntro: running whole thing...\n");
	BlackCredits();

	IntroMovie();

	REG_TM1CNT = 0x80;

	TitleScreen(0);

	srand(REG_TM1D);
	REG_TM1CNT = 0;

	DmaClear(0, MEM_VRAM, VRAM_SIZE); //clean up crap
	ClearSpriteGFX();
}
