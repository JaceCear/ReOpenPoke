#include "openpoke.h"








const int Choices_YesNo[] = { 1, 2 }; //Yes, No
const int Choices_Items[] = { 5, 6, 7, 0 }; //Use, Give, Toss, Cancel
const int Choices_KeyItems[] = { 5, 8, 0 }; //Use, Pokedex_RegisterPkmn, Cancel
const int Choices_KeyItems2[] = { 5, 9, 0 }; //Use, Deselect, Cancel
const int Choices_Balls[] = { 6, 7, 0 }; //Give, Toss, Cancel
const int Choices_CenterPC[] = { 10, 11, 12, 13 }; //RED's PC, BILL's PC, OAK's PC, Log out
const int Choices_BuySellSeeYa[] = { 14, 15, 16 }; //Buy, Sell, See Ya
const int Choices_Box1[] = { 17, 18, 19, 20, 21, 0 }; //Move,Summ,With,Mark,Rel,Cancel
const int Choices_Box2[] = { 22, 18, 19, 20, 21, 0 }; //Plac,Summ,With,Mark,Rel,Cancel
const int Choices_Box3[] = { 23, 18, 19, 20, 21, 0 }; //Swit,Summ,With,Mark,Rel,Cancel
const int Choices_Box4[] = { 17, 18, 24, 20, 21, 0 }; //Move,Summ,Stor,Mark,Rel,Cancel
const int Choices_Box5[] = { 22, 18, 24, 20, 21, 0 }; //Plac,Summ,Stor,Mark,Rel,Cancel
const int Choices_Box6[] = { 23, 18, 24, 20, 21, 0 }; //Swit,Summ,Stor,Mark,Rel,Cancel
const int Choices_Box[] = { 25, 26, 27, 0 }; //Jump, Wallpaper, Name, Cancel
const int Choices_Wallpaper[] = { 28, 29, 30 }; //Scene 1 - 3
const int Choices_Wallpaper1[] = { 31, 32, 33, 34 }; //Forest, City, Desert, Savanna
const int Choices_Wallpaper2[] = { 35, 36, 37, 38 }; //Crag, Volcano, Snow, Cave
const int Choices_Wallpaper3[] = { 39, 40, 41 }; //Beach, Seafloor, Tiles
const int Choices_PartyScreen[] = { 18, 23, 42, 0 }; //Summary, Switch, Item, Cancel
const int Choices_PartyItems[] = { 6, 43, 0 }; //Give, Take, Cancel
const int Choices_BoyGirl[] = { 44, 45 }; //Boy, Girl
#ifdef DEBUG
const int Choices_DebugMenu1[] = { 46, 47, 48, 49, 50, 51, 52, 53, 54 };
const int Choices_DebugMenu2[] = { 55,  0,  0,  0,  0,  0,  0,  0,  0 };
#endif //DEBUG





AnOptionsSet ChoiceSets[] =
{
	{ (int*)Choices_YesNo, 2 },
	{ (int*)Choices_Items, 4 },
	{ (int*)Choices_KeyItems, 3 },
	{ (int*)Choices_KeyItems2, 3 },
	{ (int*)Choices_Balls, 3 },
	{ (int*)Choices_CenterPC, 4 },
	{ (int*)Choices_BuySellSeeYa, 3 },
	{ (int*)Choices_Box1, 6 },
	{ (int*)Choices_Box2, 6 },
	{ (int*)Choices_Box3, 6 },
	{ (int*)Choices_Box4, 6 },
	{ (int*)Choices_Box5, 6 },
	{ (int*)Choices_Box6, 6 },
	{ (int*)Choices_Box, 4 },
	{ (int*)Choices_Wallpaper, 3 },
	{ (int*)Choices_Wallpaper1, 4 },
	{ (int*)Choices_Wallpaper2, 4 },
	{ (int*)Choices_Wallpaper3, 3 },
	{ (int*)Choices_PartyScreen, 4 },
	{ (int*)Choices_PartyItems, 3 },
	{ (int*)Choices_BoyGirl, 2 },
#ifdef DEBUG
	{ (int*)Choices_DebugMenu1, 9 },
	{ (int*)Choices_DebugMenu2, 9 },
#endif //DEBUG
};
