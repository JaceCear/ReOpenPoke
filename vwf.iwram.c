//======================================================================
//
//	OpenPoké VWF engine (high performance part)
//
//	(comments, kudos, flames to "cearn@coranac.com" I guess)
//
//======================================================================

//
// Variable-width font renderer(s)
//
//! \file vwf.iwram.c
//! \author J Vijn
//! \date 20070517 - 20071229
//
// === NOTES ===
/*
  * 20070516,jv: There are some heavy micro optimizations here
	involving pre-loading and pointer-math. The compiler should
	do these itself, but it doesn't :(
  * 20070516,jv: separating rendering into split/non-split isn't
	worth it. Only 2% diff.
  * 20070516,jv: ALWAYS use temporaries in loops. Pre-load the
    limit; use { x= foo[ii] & MASK; foo[ii]= x | bar; } instead
	of "foo[ii] &=" and "|=". These things have made the renderer
	25% faster.
  * 20070517,jv: I've moved the actual rendered to vwf_asm.s. It's
    faster. This file is mainly for backup and documentation for what
	the hell I'm  doing there.
  * 20071229, jv: I have much faster versions in tonc right now.
	Remind me to redo these routines.
*/


#include <tonc.h>

#include "vwf.h"

/*!	\addtogroup	grpText		*/
/*!	\{	*/

//! Tiled vwf renderer for 8x16 characters
/*!	\param srcD		Pointer to character source (pre-colored).
	\param width	Character width.
	\note	Mainly for internal use.
	\todo	Integrate into vwf_putc8x16 ?
*/
CODE_IN_IWRAM void vwf_render8x16(const u32 *srcD, int width)
{
	TVwf *vwf= gp_vwf;

	// Find destination
	u32 x= vwf->dstX, y= vwf->dstY;
	u32 *dstL= vwf->dstD;
	//dstL += y/8*VWF_PITCH*8 + y%8;
	dstL += y/8*vwf->dstP*8 + y%8;
	dstL += x/8*8;
	vwf->dstX= x+width;
	x &= 7;

	// Write pixels
	u32 mask= 0xFFFFFFFF >> (4*(8-width));
	u32 lsl= 4*x, lsr= 32-4*x, right= x+width;
	u32 ny= vwf->charH, raw;
	const u32 *srcL= srcD;

	// Write pixels
	while(ny--)
	{
		raw= srcL[0];
		srcL++;

		// Right tile (if any)
		if(right > 8)
			dstL[8]= (dstL[8] &~ (mask>>lsr) ) | (raw>>lsr);

		// Left tile :
		dstL[0] = (dstL[0] &~ (mask<<lsl) ) | (raw<<lsl);
		dstL++;

		if( ((u32)dstL)%32 == 0 )
			dstL += (vwf->dstP-1)*8;
	}
}

//! Write a character with a 8x16 glyph base, version 2.
/*!	\param ch	Ascii character to write.
	\return		Written character.
	\todo		Remove buffering, render internally and generalize to any width-height.
*/
CODE_IN_IWRAM int vwf_putc8x16(int ch)
{
	int ny, width;
	TVwf *vwf= gp_vwf;

	//ch -= ' ';

	// Get char pixels and width
	const u32 *srcL= &vwf->fontD[ch*sizeof(TILE)*2/4];
	width= vwf->fontWidths[ch];

	// Prep char buffer
	u32 buffy[32], *bufL= buffy;
	u32 raw, line, maska= 0x11111111;

	u32 ink  = vwf->colors[TEXT_INK];
	u32 shade= vwf->colors[TEXT_SHADOW];
	u32 paper= vwf->colors[TEXT_PAPER];

	// Fix colors
	ny= vwf->charH;
	while(ny--)
	{
		raw= *srcL++;
		line  = (raw    & maska)*ink;
		line += (raw>>1 & maska)*shade;
		line += (raw>>2 & maska)*paper;
		*bufL++= line;
	}

	vwf_render8x16(buffy, width);

	return ch;
}


// --------------------------------------------------------------------
// Masked versions
// --------------------------------------------------------------------

//! Tiled vwf renderer for 8x16 characters, with transparency
/*!	\param srcD	Pre-rendered character buffer. Interlaced
	  with transparency mask.
	\param width	Character width.
	\note	Mainly for internal use.
	\todo	Integrate into vwf_putc8x16 ?
*/
CODE_IN_IWRAM void vwf_render8x16T(const u32 *srcD, int width)
{
	TVwf *vwf= gp_vwf;

	// Find destination
	u32 x= vwf->dstX, y= vwf->dstY;
	u32 *dstL= vwf->dstD;
	dstL += y/8*vwf->dstP*8 + y%8;
	//dstL += y/8*VWF_PITCH*8 + y%8;
	dstL += x/8*8;
	vwf->dstX= x+width;
	x &= 7;

	u32 lsl= 4*x, lsr= 32-4*x, right= x+width;
	u32 ny= vwf->charH, mask, raw;
	const u32 *srcL= srcD;

	// Write pixels
	while(ny--)
	{
		raw= srcL[0];
		mask= srcL[1];
		srcL += 2;

		// Right tile (if any)
		if(right > 8)
			dstL[8]= (dstL[8] &~ (mask>>lsr) ) | (raw>>lsr);

		// Left tile :
		dstL[0] = (dstL[0] &~ (mask<<lsl) ) | (raw<<lsl);
		dstL++;

		if( ((u32)dstL)%32 == 0 )
			dstL += (vwf->dstP-1)*8;
	}
}

//! Write a character with a 8x16 glyph base, version 3.
/*!	Background pixels are transparent.
	\param ch	Ascii character to write.
	\return		Written character.
	\todo		Remove buffering, render internally and generalize to any width-height.
*/
CODE_IN_IWRAM int vwf_putc8x16T(int ch)
{
	int ny, width;
	TVwf *vwf= gp_vwf;

	//ch -= ' ';

	// Get char pixels and width
	const u32 *srcL= &vwf->fontD[ch*sizeof(TILE)*2/4];
	width= vwf->fontWidths[ch];

	// Prep char buffer
	u32 buffy[32], *bufL= buffy;
	u32 raw, line, mask= 0x11111111;

	u32 ink=  vwf->colors[TEXT_INK];
	u32 shade= vwf->colors[TEXT_SHADOW];
	u32 paper;

	// Fix colors
	ny= vwf->charH;
	while(ny--)
	{
		raw= *srcL++;
		// Pixel colors
		paper = (raw	& mask);
		line  = (raw    & mask)*ink;
		paper|= (raw>>1 & mask);
		line += (raw>>1 & mask)*shade;
		paper *= 15;

		bufL[0]= line;
		bufL[1]= paper;
		bufL += 2;
	}

	vwf_render8x16T(buffy, width);

	return ch;
}

/*!	\}	*/

// EOF

