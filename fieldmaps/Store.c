#include "../openpoke.h"

extern const Map16_Tile tileset_Indoors[];
extern const Map16_Tile tileset_Store[];

extern const unsigned char Store_Shopkeep_Script[];

const unsigned short Store_Map[] =
{
	0x290,0x285,0x286,0x285,0x287,0x287,0x287,0x292,0x293,0x294,0x291,
	0x298,0x2B5,0x28E,0x295,0x28F,0x28F,0x28F,0x29A,0x29B,0x29C,0x299,
	0x2A0,0x2B6,0x284,0x29D,0x283,0x284,0x284,0x2A2,0x2A3,0x2A4,0x2A1,
	0x2A8,0x2A9,0x2AA,0x2A5,0x28B,0x281,0x281,0x296,0x297,0x281,0x296,
	0x2B0,0x2B1,0x2B2,0x2AD,0x28B,0x281,0x281,0x29E,0x29F,0x28B,0x29E,
	0x282,0x2B7,0x2BC,0x284,0x28C,0x281,0x281,0x2A6,0x2A7,0x28B,0x2A6,
	0x282,0x2C1,0x2C2,0x28B,0x281,0x281,0x281,0x2AE,0x2AF,0x28B,0x2AE,
	0x2BD,0x28A,0x284,0x2B8,0x2B9,0x2BA,0x281,0x28A,0x284,0x28C,0x2BE,
	0x8,  0x8,  0x8,  0x1A, 0x1B, 0x1C, 0x8,  0x8,  0x8,  0x8,  0x8
};

const aBorderTile StoreBorder = { 0x8,  0x8,  0x8,  0x8 };

const aMap StoreMap =
{
	11,9,
	(aBorderTile*)&StoreBorder,
	(unsigned short*)Store_Map,
	(aTileset*)tileset_Indoors,
	(aTileset*)tileset_Store
};

const aPeopleEvent StorePeople[] =
{
	{ 2,3, 0x0, 0, (unsigned int)Store_Shopkeep_Script, sprNerd, 0, 0, 0, 0, 0 }
};

const aWarpEvent StoreWarps[] =
{
	{ 4,7,WARP_DOORINSIDE,0,2 } //To map #2 - Throve
};

const aEventSet StoreEvents =
{
	1,1,0,0,
	(aPeopleEvent*)StorePeople, (aWarpEvent*)StoreWarps, 0, 0
};

const aMapHeader mhdrStore =
{
	(aMap*)&StoreMap, //map
	(aEventSet*)&StoreEvents, //events
	0, //init script
	0, //after script
	0, //conns
	75, //music
	0, //filler
	2, //name
	0, //cave
	0, //weather
	0, //transition
	0, //show name
	0, //perms
	0, //floor
	0, //battleground
	0, //encounters
};
