#define DEF(x) \
	, tp ## x
typedef enum eTrainerPics
{
	tpNull = 0
	#include "trainerdata.txt"
	, tpTotal
} eTrainerPics;
#undef DEF
