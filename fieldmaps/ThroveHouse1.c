#include "../openpoke.h"

extern const Map16_Tile tileset_Indoors[];

extern const unsigned char ThroveHouse1_Welcome_Script[];

const unsigned short ThroveHouse1_Map[] =
{
	0x6B, 0x6C, 0x6D, 0x6D, 0x69, 0x6D,
	0x73, 0x74, 0x99, 0x99, 0x71, 0x71,
	0x7B, 0x7C, 0x7D, 0x7E, 0x79, 0x6F,
	0x81, 0x81, 0x81, 0x81, 0x81, 0x77,
	0x8C, 0x81, 0x81, 0x81, 0x81, 0x7F,
	0x94, 0x88, 0x89, 0x8A, 0x81, 0xA7,
	0x8,  0x1A, 0x1B, 0x1C, 0x8,  0x8
};

const aBorderTile ThroveHouse1Border = { 0x8,  0x8,  0x8,  0x8 };

const aMap ThroveHouse1Map =
{
	6,7,
	(aBorderTile*)&ThroveHouse1Border,
	(unsigned short*)ThroveHouse1_Map,
	(aTileset*)tileset_Indoors,
	(aTileset*)0
};

const aPeopleEvent ThroveHouse1People[] =
{
	{ 3,2, 0x0, 0, (unsigned int)ThroveHouse1_Welcome_Script, sprNerd, 0, 0, 0, 2, 0 }
};

const aWarpEvent ThroveHouse1Warps[] =
{
	{ 2,5,WARP_DOORINSIDE,2,2 } //To map #2 - Throve
};

const aEventSet ThroveHouse1Events =
{
	1,1,0,0,
	(aPeopleEvent*)ThroveHouse1People, (aWarpEvent*)ThroveHouse1Warps, 0, 0
};

const aMapHeader mhdrThroveHouse1 =
{
	(aMap*)&ThroveHouse1Map, //map
	(aEventSet*)&ThroveHouse1Events, //events
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

