//
// Variable-width font header
//
//! \file vwf.h
//! \author J Vijn
//! \date 20070517 - 20071229
//
// === NOTES ===


#ifndef __VWF_H__
#define __VWF_H__

#include <tonc.h>


/*!	\addtogroup	grpText		*/
/*!	\{	*/

/*
Control codes in Fire Red
-------------------------
FA	Scroll away one line
FB	Wait for key and clear
FC	Special
  01	Set ink to XX
  02	Set background to XX
  03	Set shadow to XX
  04	Set ink to XX and background to YY
  06	Set font to XX
    00	Small
    01>	Normal
  08	Wait XX ticks
  09	Wait for key
  0D	Set cursor X pos to XX
  10	Play song YYXX
  15	Switch to Japanese font
  16	Switch to American font
  17	Pause music
  18	Resume music
FD	Insert variable, among which...
  01	Player
FE	Newline
FF	End of string

*/


// --------------------------------------------------------------------
// CONSTANTS
// --------------------------------------------------------------------


#define VWF_PITCH		32

//! \name	Color-LUT indices (or palette-index LUT, really).
//\{
#define TEXT_INK		1		//!< Index for ink color.
#define TEXT_SHADOW		2		//!< Index for shade color.
#define TEXT_PAPER		3		//!< Index for paper/text background color.
//\}

// === Control codes ===

//! \name	Dialog system control codes.
//\{
//#define TCC_SCROLL				0xFA	//!< Scroll the dialog window.
//#define TCC_WAIT_AND_CLEAR		0xFB	//!< Wait for input, then clear dialog window.
#define TCC_SPECIAL			0x07	//0xFC
#define TCC_VAR					0x1F //0xFD	//!< Output variable.
//#define TCC_NEWLINE				0xFE	//!< Move to next line.
//#define TCC_END					0xFF	//!< End of string.
//\}

//!	\name	Dialog system sub-control codes.
//\{
#define TCC_SPEC_INK			0x01	//!< Set ink color.
#define TCC_SPEC_PAPER			0x02	//!< Set paper color.
#define TCC_SPEC_SHADOW			0x03	//!< Set shadow color.
#define TCC_SPEC_COLOR			0x04	//!< Set colors.
#define TCC_SPEC_FONT			0x06	//!< Change font.
#define TCC_SPEC_WAIT			0x08	//!< Wait a while.
#define TCC_SPEC_KEY			0x09	//!< Wait for key.
#define TCC_SPEC_POS			0x0D	//!< Change cursor position (?).
#define TCC_SPEC_SONG			0x10	//!< Set song.
#define TCC_SPEC_JAP			0x15	//!< Set font to Japanese.
#define TCC_SPEC_USA			0x16	//!< Set foont to Western.
#define TCC_SPEC_SONG_PAUSE		0x17	//!< Pause song.
#define TCC_SPEC_SONG_RESUME	0x18	//!< Resume song play.
//\}

#define DBCS_LEADER	0x80

// --------------------------------------------------------------------
// MACROS
// --------------------------------------------------------------------

//! Default Text system initialization: bg 0, cbb 2, sbb 31, western font.
#define vwf_init_dflt()		vwf_init(0, BG_CBB(2) | BG_SBB(31), \
	fontWesternTiles, fontWesternWidths)

//! Macro for easy font changing.
#define VWF_SET_FONT(name)	vwf_set_font(name##Tiles, name##Widths)

// --------------------------------------------------------------------
// CLASSES
// --------------------------------------------------------------------


typedef int (*fn_putc)(int);

//!
typedef struct TVwf
{
	u32	flags;			//!< Random flags
	const u32	*fontD;	//!< Font data
	const u8	*fontWidths;	//!< Character widths
//	u8	*charLut;		//!< ASCII->tile map
	u8	charW;			//!< Character width (PONDER: units?)
	u8	charH;			//!< Character height (pixels)
	u16 dstP;			//!< Destination pitch
	u32 *dstD;			//!< Destination base pointer
	u16	dstX;			//!< Destination X-coordinate
	u16	dstY;			//!< Destination Y-coordinate
	u8	colors[4];		//!< Color LUT: ( NULL, FG, shadow, BG)
	fn_putc putc_;		//!< function to write a character
} TVwf;

void vwf_init(int bgnr, u16 bgcnt, const void *font, const void *widths);

// --------------------------------------------------------------------
// GLOBALS
// --------------------------------------------------------------------

extern TVwf __vwf;
extern TVwf *gp_vwf;

// --------------------------------------------------------------------
// PROTOTYPES
// --------------------------------------------------------------------

void vwf_set_color(int type, u8 clrid);
void vwf_load_colors(const u8 *clrlut);

void vwf_set_font(const void *font, const u8 *widths);

int vwf_write(int x, int y, const char *str, const u8 *clrlut);
int vwf_measure_string(const char *text);

int vw_DrawWide(u8 ch);
int vw_DrawBraille(u8 ch);

CODE_IN_IWRAM int vwf_putc8x16(int c);
CODE_IN_IWRAM int vwf_putc8x16T(int c);
CODE_IN_IWRAM int vwf_putc8x16Tasm(int ch);


/*!	\}	*/


#endif // __VWF_H__

// EOF
