#define DEF(x) \
	extern const unsigned short mon ## x ## _frntPal[16]; \
	extern const unsigned short mon ## x ## _backPal[16]; \
	extern const unsigned short mon ## x ## _frntTiles[1024]; \
	extern const unsigned short mon ## x ## _backTiles[1024]; \
	extern const unsigned short print ## x ## Tiles[16];
	#include "pokedata_images.txt"
#undef DEF

extern const unsigned short eggPal[16];
extern const unsigned short eggTiles[1024];

#define DEF(x) \
	extern const unsigned short unknown_ ## x ## _frntTiles[1024]; \
	extern const unsigned short unknown_ ## x ## _backTiles[1024];
	#include "pokedata_unown.txt"
#undef DEF
