#include "openpoke.h"

void Spec_GetPartySize()
{
	//ScriptMemory[SM_LASTRESULT] = GetPartySize(MyParty);
	ScriptVar_800D = GetPartySize(MyParty);
	AGBPrintf("Spec_GetPartySize: %d\n",ScriptVar_800D);
}

void Spec_HealSilently()
{
	extern void HealParty();
	AGBPrintf("Spec_HealSilently\n");
	HealParty();
}

//This should be a script animation like with using an HM or something.
void Spec_HealCenter()
{
	extern const unsigned short healscrnPal[16];
	extern const unsigned short healscrnTiles[576];
	const int stiles[6] = { 544,552,560,568,560,552 };
	int i,j,p = GetPartySize(MyParty);
	DmaArrayCopy(healscrnPal, MEM_PAL_OBJ+0x160);
	DmaArrayCopy(healscrnTiles, MEM_VRAM_OBJ+0x4400);
	OamBak[64].CharNo = 544;
	OamBak[64].HPos = 111;
	OamBak[64].VPos = 16;
	OamBak[64].Shape = 1;
	OamBak[64].Size = 2;
	OamBak[64].Pltt = 11;
	for(i = 0; i < p; i++)
	{
		for(j = 0; j < 20; j++) DoVBlank();
		OamBak[74-i].CharNo = 576;
		OamBak[74-i].Pltt = 11;
		OamBak[74-i].HPos = 89 + ((i % 2 == 1) ? 7 : 0);
		OamBak[74-i].VPos = 32 + ((i/2) * 4);
		sndPlayEffectByNum(SFX_PLACEBALL);
	}
	sndPauseSound();
	HealParty();
	sndPlayEffectByNum(SFX_HEAL);
	for(i = 0; i < 120; i++)
	{
		DoVBlank();
		OamBak[64].CharNo = stiles[(i>>2) % 6];
	}
	OamBak[64].HPos = 250;
	for(i = 0; i < 6; i++)
		OamBak[74-i].HPos = 250;
	sndResumeSound();
}


//The original dex rating was an unnecessarily complicated conditional thing. In fact, a simple look up table using the dex progress / 10 would've sufficed, using conditionals only for fringe cases like #151.
//Therefore, we're using a LUT now, adding a conditional when it becomes needed.
void Spec_DexRating()
{
	int i = MyDex.seenrate, j = MyDex.caughtrate;
	sayf(SYSTEM, strDexRating, i,j);
	sayf(SYSTEM, DexRatings[i / 10]);
}

extern void GetDaycareNames(aPokemon * mon);
void Spec_GetDaycareNames()
{
	GetDaycareNames(&DaycareMon[0]);
}
