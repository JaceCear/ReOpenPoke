//======================================================================
//
//	OpenPoké VWF engine
//
//	(comments, kudos, flames to "cearn@coranac.com" I guess)
//
//======================================================================

//
// Main variable-width font stuff
//
//! \file vwf.c
//! \author J Vijn
//! \date 20070517 - 20071229
//
// === NOTES ===

#include <tonc.h>

#include "vwf.h"
#include "font.h"
#include "sound.h"

/*!	\addtogroup	grpText		*/
/*!	\{	*/

void vw_SetSmall(); 	// Kawa
void vw_SetBig();		// Kawa

// --------------------------------------------------------------------
// CONSTANTS
// --------------------------------------------------------------------

//! \name	Font character-width tables.
//\{

//! Western font.
const u8 fontWesternWidths[] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	3,6,7,8,8,8,8,3,5,5,8,8,5,6,5,6, //  to /
	6,6,6,6,6,6,6,6,6,6,5,5,8,8,8,6, //0 to ?
	0,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6, //@ to O
	6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,8, //P to _
	3,6,6,6,6,6,6,6,6,4,6,5,5,6,5,6, //' to o
	6,6,5,5,5,6,6,6,6,6,6,7,4,7,7,6, //p to house
	8,8,8,8,8,6,8,8,8,8,7,7,8,8,8,8, //> to 9
	8,3,3,6,6,5,6,8,8,8,8,8,8,8,8,8, //_ to re
	4,6,6,8,8,8,8,2,2,8,6,2,2,0,8,8, //  to ¯
	8,8,8,8,8,8,8,5,0,4,6,0,8,8,8,6, //^ to ¿
	6,6,6,6,6,6,8,6,6,6,6,6,6,6,6,6, //À to Ï
	7,6,6,6,6,8,6,8,6,6,6,6,6,6,5,6, //Ð to ß
	6,6,6,6,6,6,8,6,6,6,6,6,6,6,6,6, //à to ï
	6,6,6,6,6,6,6,8,8,6,6,6,6,6,6,6, //ð to
};

//! Small font.
const u8 fontSmallWidths[] =
{
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	4,4,5,8,8,7,7,5,5,5,8,8,5,5,5,5, //  to /
	5,5,5,5,5,5,5,5,5,5,7,7,7,8,7,5, //0 to ?
	8,5,5,5,5,5,5,5,5,4,5,5,5,5,5,5, //@ to O
	5,5,5,5,4,5,5,5,5,4,5,6,6,6,6,8, //P to _
	5,5,5,5,5,5,5,5,5,4,5,5,5,5,5,5, //' to o
	5,5,5,5,5,5,5,5,5,5,5,7,4,7,7,0, //p to house
	8,8,0,0,6,6,0,0,0,0,5,5,5,0,0,0, //> to 9
	0,5,5,5,5,5,5,0,0,8,0,0,6,0,0,0, //_ to re
	4,4,8,8,8,8,8,0,0,8,5,0,0,0,8,5, //  to ¯
	8,8,7,8,8,7,0,5,0,4,5,8,8,8,8,5, //^ to ¿
	5,5,5,5,5,5,7,5,5,5,5,5,4,4,4,4, //À to Ï
	6,5,5,5,5,5,5,8,6,5,5,5,5,4,5,5, //Ð to ß
	5,5,5,5,5,5,7,5,5,5,5,4,4,4,4,4, //à to ï
	6,5,5,5,5,5,5,0,0,5,5,5,5,5,5,5, //ð to
};

// Kawa
const u8 fontWideRealWidths[] =
{
	  7,   7,  10,  10,  10,  10,  10,  10,  10,  10,  10,  10,   8,  10,  16,  16,
	  8,   8,   9,  10,   8,   5,  10,  10,  10,  10,  10,  10,   9,  10,   8,   8,
};
const u8 fontWideWidths[] =
{
	7,0, 7,0, 8,2, 8,2, 8,2, 8,2, 8,2, 8,2, 8,2, 8,2, 8,2, 8,2, 8,0, 8,2, 8,8, 8,8,
	8,0, 8,0, 8,1, 8,2, 8,0, 5,0, 8,2, 8,2, 8,2, 8,2, 8,2, 8,1, 8,2, 8,2, 8,0, 8,0,
};
const u8 fontBrailleWidths[] =
{
	8,8,8,5,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,5,8,5,8,5,8,5,8,5,8,5,8,5,8,5,
	8,5,8,5,8,5,8,5,8,5,8,5,8,5,8,5,
	8,5,8,5,8,5,8,5,8,5,8,5,8,5,8,5,
	8,5,8,5,8,5,8,5,8,5,8,5,8,5,8,5,
};

const u8 fontJapaneseWidths[] =
{
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};


//\}

// --------------------------------------------------------------------
// GLOBALS
// --------------------------------------------------------------------

TVwf __vwf;				//!<
TVwf *gp_vwf= &__vwf;


// --------------------------------------------------------------------
// FUNCTIONS
// --------------------------------------------------------------------

//! Load a color-index table for the text system.
void vwf_load_colors(const u8 *clrlut)
{
	int ii;
	for(ii=0; ii<4; ii++)
		gp_vwf->colors[ii]= clrlut[ii];
}

//! Set the color for \a type  to \a clrid.
void vwf_set_color(int type, u8 clrid)
{
	gp_vwf->colors[type]= clrid;
}

//! Set the vwf font and width to \a font and \a widths.
void vwf_set_font(const void *font, const u8 *widths)
{
	gp_vwf->fontD= font;
	gp_vwf->fontWidths= widths;
}

//! Initialize the VWF system.
/*!	\param bgnr		Background number to render to.
	\param bgcnt	Background control settings (obsolete).
	\param font		Character data to use.
	\param widths	Character width table.
*/
void vwf_init(int bgnr, u16 bgcnt, const void *font, const void *widths)
{
	TVwf *vwf= gp_vwf;

	//REG_BGCNT[bgnr]= bgcnt; //removed by Kawa - was done seperately.

	vwf->flags= bgcnt;
	vwf->fontD= (const u32*)font;
	vwf->fontWidths= widths;
	vwf->charW= 8;
	vwf->charH= 14;
	vwf->dstP= VWF_PITCH;		// tile-pitch
	vwf->dstD= (u32*)tile_mem[BF_GET(bgcnt, BG_CBB)] + 0x300;
	vwf->dstX= 0;
	vwf->dstY= 0;

	vwf->putc_ = (fn_putc)vwf_putc8x16; //Tasm; //transparency removed by Kawa.

	// Init colors
	vwf->colors[0]= 0;
	vwf->colors[TEXT_INK]= 2;
	vwf->colors[TEXT_SHADOW]= 3;
	vwf->colors[TEXT_PAPER]= 1;

	// All this removed for being totally not needed.
/*
	// Fill out screenblock
	//u16 *pse= se_mem[BF_GET(bgcnt, BG_SBB)];
	//for(iy=0; iy<20; iy++)
	//	for(ix=0; ix<VWF_PITCH; ix++)
	//		pse[iy*32+ix]= iy*VWF_PITCH+ix;

	// Clear out tileblock
	//memset(vwf->dstD, 0, VWF_PITCH*20*sizeof(TILE)/4);
*/
}

//! Handle special characters in strings.
/*!	\param str	Pointer to where the special character starts.
	\return		String pointer past the special character.
*/
const u8 *vwf_tcc_special(const u8 *str)
{
	TVwf *vwf= gp_vwf;
	int ch;
	int song;

	ch= *str++;
	switch(ch)
	{
	case TCC_SPEC_INK:
		vwf_set_color(TEXT_INK, *str++);
		break;
	case TCC_SPEC_PAPER:
		vwf_set_color(TEXT_PAPER, *str++);
		break;
	case TCC_SPEC_SHADOW:
		vwf_set_color(TEXT_SHADOW, *str++);
		break;
	case TCC_SPEC_COLOR:
		vwf_set_color(TEXT_INK, *str++);
		vwf_set_color(TEXT_PAPER, *str++);
		break;
	case TCC_SPEC_FONT:
		ch= *str++;
		if(ch == 0)
			vw_SetSmall(); //VWF_SET_FONT(fontSmall);
		else
			vw_SetBig(); //VWF_SET_FONT(fontWestern);
		break;
	case TCC_SPEC_POS:
		ch = *str++;
		vwf->dstX = ch;
	case TCC_SPEC_SONG:
		ch = *str++;
		song = ch;
		ch = *str++;
		song = (ch << 8) + song;
		sndPlaySound(song,SOUND_NORESTART);
		break;
	case TCC_SPEC_SONG_PAUSE:
		sndPauseSound();
		break;
	case TCC_SPEC_SONG_RESUME:
		sndResumeSound();
		break;
	//default:
	//	str--;
	}

	return str;
}

//! Write a string \a text at location (\a x0,\a y0) using colors from \a clrlut)
/*! \param x0	X-coord to start rendering at. Left of text.
	\param y0	Y-coord to start rendering at. Top of text.
	\param text	Text to parse and write.
	\param clrlut	If non-zero, lut indicating ink, shadow, paper colors.
	\return		Number of characters handled (not necessrily written).
*/
int vwf_write(int x0, int y0, const char *text, const u8 *clrlut)
{
	int ch;
	const u8 *str= (const u8*)text;

	TVwf *vwf= gp_vwf;

	if(clrlut)
		vwf_load_colors(clrlut);

	vwf->dstX= x0;
	vwf->dstY= y0;

	while( (ch= *str++) != 0 )
	{
		// PONDER: combine color codes?
		switch(ch)
		{
		case TCC_SPECIAL:
			str= vwf_tcc_special(str);
			break;
		case DBCS_LEADER:
			ch= *str++;
			vw_DrawWide(ch);
			break;
		// --- Newline ---
		case '\n':
			vwf->dstY += vwf->charH;
			vwf->dstX= x0;
			break;
		default:
			vwf->putc_(ch);
		}
		//VBlankIntrDelay(1);
	}

	// Return characters written
	return str - (u8*)text;
}

//! Measure the width of string \a text.
/*!	\param text		Text to get width from.
	\note	Does \e not consider newlines or special characters.
*/
int vwf_measure_string(const char *text)
{
	int ch, rl=0;
	const u8 *str= (const u8*)text;
	TVwf *vwf= gp_vwf;
	while( (ch= *str++) != 0 )
	{
		rl+=vwf->fontWidths[ch];
	}
	return rl;
}

//! Set text system to use small font.
void vw_SetSmall()	// Kawa
{
	TVwf *vwf= gp_vwf;
	vwf_set_font(fontSmallTiles, fontSmallWidths);
	vwf->charH= 12;
}

//! Set text system to use Large font.
void vw_SetBig()	// Kawa
{
	TVwf *vwf= gp_vwf;
	vwf_set_font(fontWesternTiles, fontWesternWidths);
	vwf->charH= 14;
}

void vw_SetJapanese()	// Kawa
{
	TVwf *vwf= gp_vwf;
	vwf_set_font(fontJapaneseTiles, fontJapaneseWidths);
	vwf->charH= 12;
}

//! Set text system to use multibyte characters.
int vw_DrawWide(u8 ch)	// Kawa
{
	TVwf *vwf= gp_vwf;
	void *oldfont = (void*)vwf->fontD;
	u8 *oldwidths = (u8*)vwf->fontWidths;
	u8 gl = (ch * 2); // + ' ';
	//AGBPrintf("Told to draw character %x, * 2 = %x\n", ch,gl);

	vwf_set_font(fontWideTiles, fontWideWidths);

	vwf->putc_(gl);
	if(fontWideRealWidths[ch] > 8)
		vwf->putc_(gl+1);

	vwf->fontD= oldfont;
	vwf->fontWidths= oldwidths;

	return fontWideRealWidths[ch];
}

//! Braille writer
int vw_DrawBraille(u8 ch)	// Kawa
{
	TVwf *vwf= gp_vwf;
	void *oldfont = (void*)vwf->fontD;
	u8 *oldwidths = (u8*)vwf->fontWidths;
	int gl = (ch * 2) - 32;
	int oldHeight = vwf->charH;
	vwf->charH = 16;

	vwf_set_font(fontBrailleTiles, fontBrailleWidths);

	vwf->putc_(gl);
	vwf->putc_(gl+1);

	vwf->charH = oldHeight;

	vwf->fontD= oldfont;
	vwf->fontWidths= oldwidths;

	return 16;
}

/*!	\}	*/

// EOF
