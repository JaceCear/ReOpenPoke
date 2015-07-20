//
//	Map and map accessories header
//
//! \file map16.h
//! \author Kawa / cearn
//! \date ? - 20071229

#ifndef __MAP16
#define __MAP16

#include <tonc.h>

/*!	\defgroup	grpMap	Maps and Tiles		*/

/*!	\addtogroup	grpMap		*/
/*!	\{	*/

// --------------------------------------------------------------------
// MAP TYPES
// --------------------------------------------------------------------


/*
typedef struct RECT
{
	s16 l;
	s16 t;
	s16 b;
	s16 r;
} RECT;
*/

typedef struct Map8_Tile
{
	unsigned short tileno:10;
	unsigned short fliph:1;
	unsigned short flipv:1;
	unsigned short pal:4;
} Map8_Tile;

/* typedef struct Map8_Tile
{
	union {
		u16 foo;
		struct {
			u16 id:10;
			u16 hflip:1;
			u16 vflip:1;
			u16 pal:4;
		} bar;
	} baz;
} __attribute__((packed)) Map8_Tile; */

typedef struct Map16_Tile
{
	Map8_Tile lt0;
	Map8_Tile lt1;
	Map8_Tile lt2;
	Map8_Tile lt3;
	Map8_Tile ut0;
	Map8_Tile ut1;
	Map8_Tile ut2;
	Map8_Tile ut3;
	unsigned short flags;
} Map16_Tile;

typedef Map8_Tile Tile;
typedef Map16_Tile MetaTile;

typedef struct aEncounter
{
	unsigned short species;
	unsigned char levelmin;
	unsigned char levelmax;
} aEncounter;

typedef struct aEncounterSet
{
	unsigned int frequency;
	aEncounter mon[4][10]; //[4] for times of day, [10] for monsters
} aEncounterSet;

typedef struct aPeopleEvent
{
	unsigned short xpos;
	unsigned short ypos;

	unsigned short flag;
	unsigned short motor;

	unsigned int script;

	unsigned char sprite;
	unsigned char istrainer;
	unsigned char flagonoroff;
	unsigned char path;

	unsigned char facing;
	unsigned char lineofsight;
} aPeopleEvent;

typedef struct aWarpEvent
{
	unsigned short xpos;
	unsigned short ypos;
	unsigned char kind;
	unsigned char destWarp;
	unsigned char destLevel;
} aWarpEvent;

typedef struct aTrapEvent
{
	unsigned short xpos;
	unsigned short ypos;
	unsigned short scriptType;
	unsigned short variable;
	unsigned short value;
	unsigned int script;
} aTrapEvent;

typedef struct aSignEvent
{
	unsigned short xpos;
	unsigned short ypos;
	unsigned int script;
	unsigned short autoactivate;
} aSignEvent;

typedef struct aEventSet
{
	unsigned char numPeople;
	unsigned char numWarps;
	unsigned char numTraps;
	unsigned char numSigns;
	aPeopleEvent *people;
	aWarpEvent *warps;
	aTrapEvent *traps;
	aSignEvent *signs;
} aEventSet;

typedef struct aConnection
{
	unsigned char direction;
	signed char shift;
	unsigned char level;
} aConnection;

typedef struct aConnectionSet
{
	unsigned int numconns;
	aConnection *conns;
} aConnectionSet;

typedef struct aBorderTile
{
	unsigned short topleft;
	unsigned short topright;
	unsigned short bottomleft;
	unsigned short bottomright;
} aBorderTile;

typedef struct aTileset
{
	unsigned char flags;
	unsigned char *pic;
	Map16_Tile *blockdata;
	unsigned short *colordata;
	void (*animator)(void);
	unsigned char *lightmap;
} aTileset;

typedef struct aMap
{
	unsigned short width;
	unsigned short height;
	aBorderTile *border;
	unsigned short *mapdata;
	aTileset *tileseta;
	aTileset *tilesetb;
} aMap;

typedef struct aMapHeader
{
	aMap *map;
	aEventSet *events;
	void *scriptA;
	void *scriptB;

	aConnectionSet *conns;

	unsigned short Music;
	unsigned short filler; //Used to be Map Pointer Index

	unsigned char NameIndex;
	unsigned char Cave; //small circle of visibility
	unsigned char Weather;
	unsigned char BattleTransition;

	unsigned char ShowName;
	unsigned char wut; //Bit 2 - can run
	signed char floor; //to 99F. 0x7F = roof
	unsigned char BattleFloor;

	aEncounterSet *GrassMonsters;
	aEncounterSet *WaterMonsters;
	aEncounterSet *FishingMonsters;
	aEncounterSet *TreeMonsters;
} aMapHeader;

typedef struct aMapLocation
{
	unsigned char x;
	unsigned char y;
	unsigned char shape;
} aMapLocation;

// --------------------------------------------------------------------
// MAP-TYPE MACROS
// --------------------------------------------------------------------


//#define BG1MAP	((u16*)0x0600E000)
//#define BG2MAP	((u16*)0x0600E800)
//#define BG3MAP	((u16*)0x0600F000)

// FDEC BA98   7654 3210
//[.... ....] [.... RWST]

//! \name	Metatile types
//\{
#define MAP16_NORMAL					0x0000
#define MAP16_DANGEROUS				0x1000
#define MAP16_ONBG1						0x2000
#define MAP16_SOLID						0x4000
#define MAP16_WATER						0x8000

#define	MAP16_TOPSOLID				0x0001	//OP extension
#define MAP16_TALLGRASS				0x0002
#define MAP16_DESK						0x0003	//propagate scan one tile further

#define MAP16_SHALLOWWATER		0x0010	//show a reflection and ripples
#define MAP16_SLIPPERYSLOPE		0x0013	//can't get up -- fall down again
#define MAP16_SPLISHYWATER		0x0016	//0x10 but with splishy footsteps
#define MAP16_RAPIDSSPLISH		0x0017	//constant splish around feet
#define MAP16_REFLECT					0x001A	//show a reflection

#define MAP16_SAND						0x0021	//sandy footprints
#define MAP16_BUBBLE					0x0022	//bubbles on each step
#define MAP16_ICE							0x0023	//slide and reflect
#define	MAP16_SUBMERGED				0x0028	//body is covered by blue overlay

#define MAP16_ONLYUPORDOWN		0x0030
#define MAP16_ONLYLEFTORDOWN	0x0031
#define MAP16_ONLYLEFTORRIGHT	0x0032
#define MAP16_LEDGERIGHT			0x0038	//hop instead of walk
#define MAP16_LEDGELEFT				0x0039
#define MAP16_LEDGEUP					0x003A
#define MAP16_LEDGEDOWN				0x003B

#define MAP16_AUTOWALKRIGHT		0x0040	//on this tile, automatically walk one tile
#define MAP16_AUTOWALKLEFT		0x0041
#define MAP16_AUTOWALKUP			0x0042
#define MAP16_AUTOWALKDOWN		0x0043
#define MAP16_SLIDERIGHT			0x0044	//on this tile, automatically slide one tile
#define MAP16_SLIDELEFT				0x0045
#define MAP16_SLIDEUP					0x0046
#define MAP16_SLIDEDOWN				0x0047
#define MAP16_SLIDE						0x0048	//works like 0x23, but without a reflection

#define MAP16_AUTOWALKRIGHT_F	0x0050	//same as 0x40, but faster
#define MAP16_AUTOWALKLEFT_F	0x0051
#define MAP16_AUTOWALKUP_F		0x0052
#define MAP16_AUTOWALKDOWN_F	0x0053
#define MAP16_SPINRIGHT				0x0054	//rocket spinner
#define MAP16_SPINLEFT				0x0055
#define MAP16_SPINUP					0x0056
#define MAP16_SPINDOWN				0x0057
#define MAP16_SPINSTOPPER			0x0058	//breaks out of spin state, normal otherwise

#define MAP16_EXITRIGHT				0x0062	//shows exit arrow
#define MAP16_EXITLEFT				0x0063
#define MAP16_EXITUP					0x0064
#define MAP16_EXITDOWN				0x0065

#define MAP16_CENTERPC				0x0083
#define MAP16_WORLDMAP				0x0085
#define MAP16_TV							0x0088
#define MAP16_CLOCK						0x0089
#define MAP16_QUESTIONNAIRE		0x008F

#define MAP16_SIMPLEMESSAGE		0x0100	//from 0x100 to 0x1FF, just shows a single message

//\}

//! \name	Warp types
//\{
#define WARP_INVALID         0
#define WARP_JUSTFADE        1
#define WARP_STAIRSUP        2
#define WARP_STAIRSDOWN      3
#define WARP_STAIRSUPLEFT    4
#define WARP_STAIRSDOWNRIGHT 5
#define WARP_DOORINSIDE      6
#define WARP_DOOROUTSIDE     7
#define WARP_CAVEINSIDE      8
#define WARP_CAVEOUTSIDE     9
#define WARP_CAVEINSIDERIGHT 10
#define WARP_CAVELADDERUP    12
#define WARP_CAVELADDERDOWN  13
#define WARP_HOLE            14
#define WARP_HOLETARGET      15
//\}

#define SCROLLSIZE			255
#define SCROLLTILES			16


// --------------------------------------------------------------------
// PROTOTYPES
// --------------------------------------------------------------------

//! \name map and map-header functions
//\{
void mhInitConnRects(const aMapHeader *mh);
int	mhGetConnDir(const aMapHeader *mh, int tx, int ty);
int mhGetConnId(const aMapHeader *mh, int tx, int ty, int dir);
void mhRedraw(const aMapHeader *mh, int tx, int ty);
MetaTile *mhGetMetaTile(const aMapHeader *mh, int tx, int ty);
u16 mhGetMetaTileFlags(const aMapHeader *mh, int tx, int ty);

void mapLoad(u32 index);
void mapLoadMinimal(u32 index);
int mapGetMetaId(const aMap *map, int tx, int ty);
MetaTile *mapGetMetaTile(const aMap *map, int tx, int ty);
void mapDrawMeta(int tx, int ty, const MetaTile *meta);
//\}

void camUpdate(int px, int py);
void FocusCam();
void HandleCamera();

void CheckMapCrossing();
void DoOutdoorsAnim();
void AnimateTiles();


/* // Old prototypes
//void levelLoad(const aMapHeader *level);
void levelLoad(u32 index);
int levelGetMetaId(const aMap *level, int tx, int ty);
MetaTile *levelGetMetaTile(const aMap *level, int tx, int ty);
u16 levelGetMetaTileFlags(const aMap *level, int tx, int ty);

void mapRedraw(const aMap *level, int tx, int ty);
void mapDrawMeta(s32 tx, s32 ty, const MetaTile *meta);

void camUpdate(s32 px, s32 py);

void DrawMap();
void HandleCamera();

void CheckMapCrossing();

void AnimateTiles();

*/


// --------------------------------------------------------------------
// GLOBALS
// --------------------------------------------------------------------


extern aMapHeader *currentMapHeader;
extern aMap *currentLevel;
extern aEncounterSet *currentMonsters[4];
extern int gCameraX, gCameraY;

extern void FocusCam();

extern const aMapHeader * const MapHeaderList[];
extern const aMap * const aMapPointerList[];
extern const char * const MapNames[];
extern const aMapLocation MapLocations[];

/*!	\}	*/


#endif	// __MAP16

// EOF
