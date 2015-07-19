/**	\file spinda.c
		\author Cearn
*/
#include "openpoke.h"

typedef struct TSpot
{
	u8	x;			//!< Spot x-coord.
	u8	y;			//!< Spot y-coord.
	u8	height;		//!< Spot height.
	u8	index;		//!< Index to spotData.
} ALIGN(4) TSpot;

static const TSpot spindaSpots[4]=
{
	{  9,  0, 12,  0 },
	{ 32,  0, 13, 12 },
	{ 14, 17,  9, 25 },
	{ 26, 18,  8, 34 }
};

static const u16 spindaSpotData[ ]=
{
	0x0070, 0x01FC, 0x03FE, 0x07FE,
	0x07FF, 0x0FFF, 0x0FFF, 0x0FFF,
	0x07FE, 0x07FE, 0x03FC, 0x01F0,

	0x01E0, 0x03F8, 0x07FC, 0x0FFE,
	0x0FFE, 0x1FFF, 0x1FFF, 0x1FFF,
	0x0FFE, 0x0FFE, 0x07FC, 0x07F8,
	0x00E0,

	0x001C, 0x003E, 0x007F, 0x007F,
	0x007F, 0x007F, 0x007F, 0x003E,
	0x001C,

	0x003C, 0x007E, 0x00FF, 0x00FF,
	0x00FF, 0x00FF, 0x007E, 0x003C,
};

// Assuming 64x64@4 objects
INLINE u32 monGetPixel(void *srcBase, u32 x, u32 y)
{
	u32 *srcD= (u32*)(srcBase+y/8*8*32 + y%8*4 + x/8*32);

	return (*srcD>>x%8*4)&15;
}

INLINE void monSetPixel(void *dstBase, u32 x, u32 y, u32 color)
{
	u32 *dstD= (u32*)(dstBase+y/8*8*32 + y%8*4 + x/8*32);
	u32 shift= x%8*4;
	*dstD= (*dstD &~ (15<<shift)) | (color<<shift);
}

void spindaDrawSpots(void *dst, u32 pv)
{
	int i, ix, iy;

	for(i=0; i<4; i++)		// spot loop
	{
		int x0= spindaSpots[i].x + (pv   &15);
		int y0= spindaSpots[i].y + (pv>>4&15);
		int srcH= spindaSpots[i].height;
		const u16 *srcD= &spindaSpotData[spindaSpots[i].index];

		for(iy=0; iy<srcH; iy++)
		{
			u32 data= srcD[iy];
			for(ix=x0; data; ix++, data >>= 1)
			{
				if(data&1)
				{
					u32 color= monGetPixel(dst, ix, iy+y0);
					if(1 <= color && color <= 4)
						monSetPixel(dst, ix, iy+y0, color+4);
				}
			}
		}
		pv >>= 8;
	}

}
