//
// Text system header
//
//! \file	text.h
//! \author	Kawa / cearn
//!	\date	? - 20071229

#ifndef __TEXT
#define __TEXT

/*!	\defgroup	grpText	Text system		*/

/*!	\addtogroup	grpText		*/
/*!	\{	*/

#define VWDEST_REGULAR 0x06008C00
#define VWDEST_BATTLE  0x06000C00
#define VWDEST_SPRITES 0x06010000

extern u32 *vwDestination;

extern const unsigned short speechboxPal[16];
extern const unsigned short speechboxTiles[128];
extern const unsigned short speechboxMap[180];
extern const unsigned short signboxPal[16];
extern const unsigned short signboxTiles[128];
extern const unsigned short signboxMap[180];

extern char *TextBuffer;
extern int SetText(char *target, char *source);
extern char * GetTextVarPointer(int varid);
extern void TestText();

extern char StringVar[8][32];

#define vwTileBase			0x06008c00

extern void DrawFrame(int x, int w, int y, int h);
extern void ClearFrame(int x, int w, int y, int h);
extern void vwSetLine(int x, int w, int y, int start, int pal);

#define vwClear(x)			CpuFastClear(x*0x11111111, vwDestination, 0x5000);
#define vwClearLine(x,y)	CpuFastClear(x*0x11111111, vwDestination + (y * 0x80), 0x200); \
							CpuFastClear(x*0x11111111, vwDestination + (y * 0x80) + 0x100, 0x200);

extern void vwDrawNumberR(u32 number, u8 w, int x, int y);

//#define vwRefresh() CpuFastArrayCopy(vwDestination,vwTileBase);
//#define vwRefreshHelp() CpuFastCopy(vwDestination + 0x2000, vwTileBase+0x2000,0x1400);

//Replacements that call Cearn's new masterpiece
#define vwWrite(sx, sy, t)			vwf_write(sx,sy, t, NULL)

//! \name Special text-LUT macros
//\{
#define vwSetLUT(ink, shadow, paper)	do {	\
		vwf_set_color(TEXT_INK, ink);			\
		vwf_set_color(TEXT_SHADOW, shadow);		\
		vwf_set_color(TEXT_PAPER, paper);		\
	} while(0)

#define vwRedLUT()					vwSetLUT(4, 5, 1)
#define vwNormalLUT()				vwSetLUT(2, 3, 1)
#define vwWhiteTransparentLUT()		vwSetLUT(1, 2, 0)
#define vwBlackTransparentLUT()		vwSetLUT(2, 3, 0)
#define vwRedTransparentLUT()			vwSetLUT(4, 5, 0)
#define vwBattleLUT()				vwSetLUT(1, 3, 0)
//\}

#define vwToBG()								vwDestination = (u32*)VWDEST_REGULAR;
#define vwToSPR()

#define vwWriteG(x,y,z) vwWrite((x) << 3, (y) << 3, z)

/*
extern int vwWriteChar(u32 x, u32 y, int ch, const u8 *colorLut, const u8 *font, const u8 *widths, u8 height);
extern void vwWriteSmall(u32 startx, u32 starty, char *text);
extern void vwWriteBtlWin(u32 startx, u32 starty, char *text);
extern u32 vwMeasure(char *text);
extern u32 textcursorx, textcursory;
extern u32 dontautorefresh;
void vwNormalLUT();
void vwWhiteTransparentLUT();
void vwBlackTransparentLUT();
void vwRedLUT();
void vwBattleWinLUT();
void vwToBG();
void vwToSPR();
*/

void EnterName(char *target, u32 maxlen, const char *prompt, void *spritecallback(int t));

/*!	\}	*/


#endif	// __TEXT

// EOF
