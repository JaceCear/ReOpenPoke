#include "../../openpoke.h"

extern const aMapHeader mhdrAmber;
extern const aMapHeader mhdrThrove;
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
extern const aMapHeader mhdrRoute1;
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
extern const aMapHeader mhdrAmberHouse1;
extern const aMapHeader mhdrAmberHouse1U;
extern const aMapHeader mhdrAmberHouse2;
extern const aMapHeader mhdrAmberHouse2U;
extern const aMapHeader mhdrAmberLab;
//empty map slot
//empty map slot
//empty map slot
//empty map slot
//empty map slot
extern const aMapHeader mhdrThroveHouse1;
extern const aMapHeader mhdrThroveHouse2;
extern const aMapHeader mhdrThroveHouse3;
extern const aMapHeader mhdrStore;
extern const aMapHeader mhdrCenter;

const aMapHeader * const MapHeaderList[] =
{
	0,
	(aMapHeader*)&mhdrAmber, //1
	(aMapHeader*)&mhdrThrove, //2
	0, //empty map slot 3
	0, //empty map slot 4
	0, //empty map slot 5
	0, //empty map slot 6
	0, //empty map slot 7
	0, //empty map slot 8
	0, //empty map slot 9
	0, //empty map slot 10
	(aMapHeader*)&mhdrRoute1, //11
	0, //empty map slot 12
	0, //empty map slot 13
	0, //empty map slot 14
	0, //empty map slot 15
	0, //empty map slot 16
	0, //empty map slot 17
	0, //empty map slot 18
	0, //empty map slot 19
	0, //empty map slot 20
	(aMapHeader*)&mhdrAmberHouse1, //21
	(aMapHeader*)&mhdrAmberHouse1U, //22
	(aMapHeader*)&mhdrAmberHouse2, //23
	(aMapHeader*)&mhdrAmberHouse2U, //24
	(aMapHeader*)&mhdrAmberLab, //25
	0, //empty map slot 26
	0, //empty map slot 27
	0, //empty map slot 28
	0, //empty map slot 29
	0, //empty map slot 30
	(aMapHeader*)&mhdrThroveHouse1, //31
	(aMapHeader*)&mhdrThroveHouse2, //32
	(aMapHeader*)&mhdrThroveHouse3, //33
	(aMapHeader*)&mhdrStore, //34
	(aMapHeader*)&mhdrCenter, //35
};

const char * const MapNames[] =
{
	"???",
	"Amber",
	"Throve",
	"Route 1",
};

const aMapLocation MapLocations[] =
{
	{ 1,1,0 },
	{ 7,12,0 },
	{ 7,10,0 },
	{ 7,11,0 },
	{ -1,-1,-1 },
};

