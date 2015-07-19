#define DEF(x) \
	, spr ## x
typedef enum eOverworldSprites
{
	sprNull = 0
	#include "spritedata.txt"
	, sprCount
} eOverworldSprites;
#undef DEF

#define DEF(x) \
	extern const unsigned short x ## Tiles[];
#include "spritedata2.txt"
#undef DEF
