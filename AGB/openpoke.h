#pragma once

#ifndef __POKETEST
#define __POKETEST
#define INEWRAM	__attribute__((section(".ewram")))


//#include "toolinclude/Agb.h"

#include <stdarg.h>

#include "options.h"

#include "toolinclude/tonc.h"
#include "toolinclude/isagbprint.h"
#include "toolinclude/noaglue.h"

#include "sound.h"
#include "data/pokedata.h"
#include "data/trainerdata.h"
#include "data/trainerdata2.h"
#include "data/spritedata.h"
#include "data/itemdata.h"

#include "main.h"
#include "text.h"
#include "printf.h"
#include "map16.h"
#include "miscevents.h"
#include "properties.h"
#include "pokemanager.h"
#include "spritemanager.h"
#include "itemmanager.h"
#include "intro.h"
#include "pokedex.h"
#include "rtc.h"
#include "trainercard.h"
#include "battleEngine/battle.h"
#include "timekeeper.h"

#include "data/moves.h"
#include "data/abilities.h"


#include "lang.h"

#include "help.h"

#include "vwf.h"
#include "font.h"

#include "ScriptCommands.h"

// --------------------------------------------------------------------
// --------------------------------------------------------------------

#define CSTRING const char * const

#define ASM_BREAK()	asm volatile("\tmov\t\tr11, r11")


#define Trg __key_curr
#define Cont __key_prev
//#define IN_RANGE(x, xmin, xmax) ((x) >=(xmin) && (x) < (xmax) )
#define GETBIT(f, b) ((f[(b)/8]>>((b)&7))&1)
#define SETBIT(f, b)  f[(b)/8]|=1<<((b)&7)
#define CLRBIT(f, b)  f[(b)/8]&=~(1<<((b)&7))
//inline bool GetBit(unsigned int bit, char bytes) {	return bytes[bit/8] >> (bit&7);		}
//inline void SetBit(unsigned int bit) {	bytes[bit/8] |= 1<<(bit&7);			}
//inline void ClearBit(unsigned int bit) {	bytes[bit/8] &= ~(1<<(bit&7));		}


// --------------------------------------------------------------------
// MEMORY MAP
// --------------------------------------------------------------------


#define SRAM ((unsigned char *)0x0e000000) //Pointer to saveram
//#define Wait() Trg = 0; while(1) { DoVBlank(); KeyRead(); if(Trg & A_BUTTON) break; } Trg = 0;

#define BG0MAP ((u16*)0x600F800)
#define BG1MAP ((u16*)0x600E800)
#define BG2MAP ((u16*)0x600E000)
#define BG3MAP ((u16*)0x600F000)
#define BGPAL  ((u16*)0x5000000)

// --------------------------------------------------------------------
// GLOBALS
// --------------------------------------------------------------------

extern u32 totalframes;
extern u16 Cont, Trg;
extern u16 SongPlaying;
extern OamData OamBak[128];
//OBJ_ATTR OamBak[128];


extern const unsigned short SineLutQ8[256+64];


extern const u16 spritecolors[0x3f];

void LoadSpriteColors();

#define LoadMapColors() CpuFastArrayCopy(map_Palette, BG_PLTT)
#define ClearSpriteGFX() DmaClear(0, MEM_VRAM_OBJ, VRAM_OBJ_SIZE)

extern const unsigned short framePal[256];
extern const unsigned short frameTiles[144];
extern const unsigned short uiframePal[16];
extern const unsigned short uiframeTiles[144];
extern const u16 helpbar_Palette[16];
extern const u8 helpbar_Char[32*8/8*24/8 + 0];
extern const unsigned short fogTiles[1024];
extern const unsigned short fogPal[16];
extern const unsigned short reflectedcloudsTiles[1024];
extern const unsigned short reflectedcloudsPal[16];
extern const unsigned short sandstormTiles[1280];
extern const unsigned short sandstormPal[16];

#define LoadHelpBar() CpuFastArrayCopy(helpbar_Palette,MEM_PAL_BG+0x1C0);


// --------------------------------------------------------------------
// TYPES
// --------------------------------------------------------------------

#ifdef DEBUG
typedef struct DebugField
{
	u16 wtw:1;
	u16 nbtl:1;
	u16 fbtl:1;
	u16 btlversus;
	u16 sound;
} DebugField;
extern DebugField MyDebug;

extern void startupDebug();
#endif

/** \addtogroup grpOptions \{ */
/** \brief Game options. */
typedef struct OptionField
{
	unsigned short textspeed:2; /**< \brief Slow, medium, fast or immediate */
	unsigned short beepstyle:2; /**< \brief Normal, short or none */
	unsigned short frame:4; /**< \brief Frame style (0 to 15) */

	unsigned short soundmode:1; /**< \brief Stereo or mono */
	unsigned short battlestyle:1; /**< \brief Switch or set */
	unsigned short battlescene:1; /**< \brief On or off */
	unsigned short buttonmode:2; /**< \brief Help, left-right or left=A */
	unsigned short battleskip:1;
} OptionField;
/** \} */

typedef struct PlayerData
{
	char name[10];

	char gender;
	//char filler;

	int trainerid;

	//unsigned int playTime;
	unsigned short Hours;
	unsigned char Minutes;
	unsigned char Seconds;
	unsigned char Milliseconds;

	union
	{
		OptionField Options;
		u16 OptionsI;
	};

	unsigned int cash;
	unsigned short currentMapX;
	unsigned short currentMapY;
	unsigned short currentMap;
	unsigned short currentFacing;
	unsigned int Registereditem;
	char rival[10];
	int stepsToHatch;
	int stepsToPoison;
#ifdef WITH_SHIRTCOLORS
	char shirtColor;
#endif
} PlayerData;

typedef struct DexData
{
	unsigned char seen[64];
	unsigned char caught[64];
	unsigned short seenrate;
	unsigned short caughtrate;
} DexData;

//extern OptionField MyOptions INEWRAM;
extern PlayerData MyPlayer INEWRAM;
extern DexData MyDex;

#define PlayerName MyPlayer.name
//extern char PlayerName[16];


//#define SimpleYesNoLoop() MultipleChoice(21,8,8,Choice_YesNo)
#define SimpleYesNoLoop() MultipleChoice(21,8,8,0,1)
#define CleanUpCrap() DmaClear(0, MEM_VRAM, VRAM_SIZE)
#define CleanUpBG0() DmaClear(0, MEM_VRAM+0xF800,0x800)

//extern u16 ScriptMemory[1024];
extern u8	ScriptFlags[288];
//#define SM_LASTRESULT 0x800D
#define SAFARIMODE  0x800

#define HAVEGEAR    0x801
#define SOMETHINGONTV 0x802
#define ISSURFING	0x804
#define USINGSTRENGTH	0x805

#define HAVEBADGE1  0x820
#define HAVEBADGE2  0x821
#define HAVEBADGE3  0x822
#define HAVEBADGE4  0x823
#define HAVEBADGE5  0x824
#define HAVEBADGE6  0x825
#define HAVEBADGE7  0x826
#define HAVEBADGE8  0x827
#define HAVEPARTY   0x828
#define HAVEPOKEDEX 0x829
#define BIKELOCK    0x830
#define KNOWBILL    0x834
#define HAVENATIONALDEX 0x840

typedef struct aSpawnPoint
{
	u16 map;
	u16 x;
	u16 y;
} aSpawnPoint;


extern void vw_SetSmall();
extern void vw_SetBig();
extern void vw_SetJapanese();


extern void DoStore(u16* inventory);
extern void Options();

extern char* strcat(char *,const char *);
extern int strcmp(char *,const char *);
extern int strcpy(char *,const char *);
extern void* memset(char*, int, int);


/** \addtogroup grpOptions \{ */
#define OPT_TEXTSPEED 0
#define OPT_BATTLESCENE 1
#define OPT_BATTLESTYLE 2
#define OPT_SOUND 3
#define OPT_BUTTONMODE 4
#define OPT_FRAME 5
#define OPT_BEEPSTYLE 6
#define OPT_BATTLESKIP 7
#define OPT_WALKTHRU 8
#define OPT_CANCEL 9
#ifdef DEBUG
#define TOTALOPTIONS 10
#else
#define TOTALOPTIONS 9
#endif
#define OPTTYPE_SIMPLE 0
#define OPTTYPE_NUMBER 1
#define OPTTYPE_CANCEL 2
/** \brief Option screen list item */
typedef struct anOption
{
	unsigned short id; /**< \brief Option ID to change */
	unsigned short type; /**< \brief Option type */
	const char * caption; /**< \brief Caption */
	const char * choices; /**< \brief List of choices, fixed length */
	unsigned char choicect; /**< \brief Number of choices */
	unsigned char choicelen; /**< \brief Length of single choice */
} anOption;
/* \} */


typedef struct aCamera
{
	int x, y;			//!< Current coordinates.
	int oldX, oldY;		//!< Previous coordinates.
	u16 mapX0, mapY0;	//!< Map offset.
} aCamera;

extern aCamera gCam;

typedef struct anEggTimer
{
	int time; //!< Time until it pops in frames.
	void * target; //!< Script to run when it pops.
	int visible; //!< Display time in the corner.
} anEggTimer;

extern anEggTimer EggTimer;

typedef struct AnOptionsSet
{
	int * Options;
	int NumChoices;
} AnOptionsSet;

extern AnOptionsSet ChoiceSets[];

typedef struct aBerry
{
	char name[7];
	char firmness;
	//char size;
	//char internal
	short size;
	char max;
	char min;
	char * desc1;
	char * desc2;
	char time;
	char spicy;
	char dry;
	char sweet;
	char bitter;
	char sour;
	char smooth;
} aBerry;
typedef enum eFirmness
{
	bfEnigma, bfVerySoft, bfSoft, bfHard, bfVeryHard, bfSuperHard
} eFirmness;

#endif	// __POKETEST

// EOF

