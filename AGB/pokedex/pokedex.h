
#ifndef __POKEDEX
#define __POKEDEX

#include "..\openpoke.h"

#define REG_SEEN		0
#define REG_CAUGHT		1
#define REG_SHOWDEX		2

extern void ShowDexEntry(int index);
extern void openPokeDex();
extern void Pokedex_RegisterPkmn(int species, int flags);

#endif // __POKEDEX

// EOF
