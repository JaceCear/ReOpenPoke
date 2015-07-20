#include "../../openpoke.h"

//#define ALL

const unsigned short * const PokePicsFront[] =
{
	#define DEF(x) \
		mon ## x ## _frntTiles,
		#include "../pokedata_images.txt"
	#undef DEF
	eggTiles,
	#define DEF(x) \
		unknown_ ## x ## _frntTiles,
		#include "../pokedata_unown.txt"
	#undef DEF
};

const unsigned short * const PokePicsPalette[] =
{
	#define DEF(x) \
		mon ## x ## _frntPal,
		#include "../pokedata_images.txt"
	#undef DEF
	eggPal,
	#define DEF(x) \
		0,
		#include "../pokedata_unown.txt"
	#undef DEF
};

const unsigned short * const PokePicsBack[] =
{
	#define DEF(x) \
		mon ## x ## _backTiles,
		#include "../pokedata_images.txt"
	#undef DEF
	eggTiles,
	#define DEF(x) \
		unknown_ ## x ## _backTiles,
		#include "../pokedata_unown.txt"
	#undef DEF
};

const unsigned short * const PokePicsShinyPal[] =
{
	#define DEF(x) \
		mon ## x ## _backPal,
		#include "../pokedata_images.txt"
	#undef DEF
	eggPal,
	#define DEF(x) \
		0,
		#include "../pokedata_unown.txt"
	#undef DEF
};

const unsigned short * const PokePrints[] =
{
	/*#define DEF(x) \
		print ## x ## Tiles,
		#include "../pokedata_images.txt"
	#undef DEF*/
};
