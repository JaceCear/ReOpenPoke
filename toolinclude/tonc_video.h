//
//  Basic video functions
//
//! \file tonc_video.h
//! \author J Vijn
//! \date 20060604 - 20060604
//
// === NOTES ===
// * Basic video-IO, color, background and object functionality

#ifndef TONC_VIDEO
#define TONC_VIDEO

#include "tonc_memmap.h"
#include "tonc_memdef.h"
#include "tonc_core.h"

/*! \defgroup grpVideoPal	Colors
*	\ingroup grpVideo
*/

/*! \defgroup grpVideoBg	Tiled Backgrounds
*	\ingroup grpVideo
*/

/*! \defgroup grpVideoBmp	Bitmaps
*	\ingroup grpVideo
*/

/*! \defgroup grpVideoObj	Objects
*	\ingroup grpVideo
*/

/*! \defgroup grpVideoAffine	Affine functions
*	\ingroup grpVideo
*/


// --------------------------------------------------------------------
// VIDEO CORE
// --------------------------------------------------------------------



// --- Constants ------------------------------------------------------

// sizes in pixels
#define VID_WIDTH    240
#define VID_HEIGHT   160

#define M3_WIDTH     VID_WIDTH
#define M3_HEIGHT    VID_HEIGHT
#define M4_WIDTH     VID_WIDTH
#define M4_HEIGHT    VID_HEIGHT
#define M5_WIDTH     160
#define M5_HEIGHT    128

// sizes in tiles
#define VID_WIDTH_TL  (VID_WIDTH>>3)
#define VID_HEIGHT_TL (VID_HEIGHT>>3)

// total scanlines
#define VID_LINES    228

// or a bit shorter
#define SCR_W     VID_WIDTH
#define SCR_H     VID_HEIGHT
#define SCR_WT    VID_WIDTH_TL
#define SCR_HT    VID_HEIGHT_TL

#define LAYER_BG0   0x0001
#define LAYER_BG1   0x0002
#define LAYER_BG2   0x0004
#define LAYER_BG3   0x0008
#define LAYER_OBJ   0x0010
#define LAYER_BD    0x0020

// --- Prototypes -----------------------------------------------------

INLINE void vid_vsync();
void vid_wait(u32 frames);
u16 *vid_flip();



// --------------------------------------------------------------------
// COLOR and PALETTE
// --------------------------------------------------------------------



//! \addtogroup grpVideoPal
/*!	\{	*/

//! \name Base Color constants
//\{

#define CLR_BLACK   0x0000
#define CLR_RED     0x001F
#define CLR_LIME    0x03E0	// yup. Green == darker green
#define CLR_YELLOW  0x03FF
#define CLR_BLUE    0x7C00
#define CLR_MAG     0x7C1F
#define CLR_CYAN    0x7FE0
#define CLR_WHITE   0x7FFF

//\}

//! \name Additional colors
//\{

#define CLR_DEAD		0xDEAD
#define CLR_MAROON      0x0010
#define CLR_GREEN       0x0200
#define CLR_OLIVE       0x0210
#define CLR_ORANGE      0x021F
#define CLR_NAVY        0x4000
#define CLR_PURPLE      0x4010
#define CLR_TEAL        0x4200
#define CLR_GRAY        0x4210
#define CLR_MEDGRAY     0x5294
#define CLR_SILVER      0x6318
#define CLR_MONEYGREEN  0x6378
#define CLR_FUCHSIA     0x7C1F
#define CLR_SKYBLUE     0x7B34
#define CLR_CREAM       0x7BFF

//\}


#define CLR_MASK    0x001F

#define RED_MASK    0x001F
#define RED_SHIFT        0
#define GREEN_MASK  0x03E0
#define GREEN_SHIFT      5
#define BLUE_MASK   0x7C00
#define BLUE_SHIFT      10

INLINE COLOR RGB15(int red, int green, int blue);
INLINE COLOR RGB15_SAFE(int red, int green, int blue);

/*!	\}	*/


// --------------------------------------------------------------------
// TILED BACKGROUNDS
// --------------------------------------------------------------------


//! \addtogroup grpVideoBg
/*!	\{	*/


// --- Macros ---------------------------------------------------------

#define CBB_CLEAR(cbb) memset32(&tile_mem[cbb], 0, CBB_SIZE/4)

#define SBB_CLEAR(sbb) memset32(&se_mem[sbb], 0, SBB_SIZE/4)
#define SBB_CLEAR_ROW(sbb, row)		\
	memset32(&se_mem[sbb][(row)*32], 0, 32/2)


// --- bg-types and availability checks for vid-modes 0,1,2 ---
//         3 2 1 0  avail type
// mode 0  r r r r   000F 0000
// mode 1  - a r r   0070 0040
// mode 2  a a - -   0C00 0C00  |
//                 0x0C7F0C40  
#define  __BG_TYPES ((0x0C7F<<16)|(0x0C40))

// Get affinity and availability of background n (output is 0 or 1)
#define BG_IS_AFFINE(n) ( (__BG_TYPES>>(4*(REG_DISPCNT&7)+(n)   ))&1 )
#define BG_IS_AVAIL(n)  ( (__BG_TYPES>>(4*(REG_DISPCNT&7)+(n)+16))&1 )


INLINE void se_fill(SCR_ENTRY *sbb, SCR_ENTRY se);
INLINE void se_plot(SCR_ENTRY *sbb, int x, int y, SCR_ENTRY se);
INLINE void se_rect(SCR_ENTRY *sbb, int ll, int tt, int rr, int bb, SCR_ENTRY se);
INLINE void se_frame(SCR_ENTRY *sbb, int ll, int tt, int rr, int bb, SCR_ENTRY se);

void se_window(SCR_ENTRY *sbb, int ll, int tt, int rr, int bb, SCR_ENTRY se0);

void se_hline(SCR_ENTRY *sbb, int x0, int x1, int y, SCR_ENTRY se);
void se_vline(SCR_ENTRY *sbb, int x, int y0, int y1, SCR_ENTRY se);


// --- Types ----------------------------------------------------------

//! Essential BG information (well, kinda).
//! NOTE! To be moved ~E~
typedef struct BG_BASE
{
	// misc
	union
	{
		u32 state;			//!< Background state
		struct				//!< 
		{
			u16 flags;
			u16 cnt;
		};
	};
	// Source data
	const void *src_tiles;	//!< Source tileset address
	u32 src_tiles_size;		//!< Source tileset size
	const void *src_map;	//!< Source map address
	u32 src_map_width;		//!< Source map width
	u32 src_map_height;		//!< Source map height
	FIXED map_x;			//!< X-coord on map (.8f)
	FIXED map_y;			//!< Y-coord on map (.8f)
	// Destination data
	TILE *dst_tiles;		//!< Charblock pointer
	SCR_ENTRY *dst_map;		//!< Screenblock pointer
	// PONDER: scrap this?
	union	
	{
		AFF_DST_EX adx;		//!< Affine parameters
		struct	
		{
			s16 pa, pb;
			s16 pc, pd;
			s32 dx, dy;
		};
	};
} BG_BASE;

// --- Prototypes -----------------------------------------------------

// --- affine ---
INLINE void bg_aff_set(BG_AFFINE *bgaff, 
	FIXED pa, FIXED pb, FIXED pc, FIXED pd);
INLINE void bg_aff_identity(BG_AFFINE *bgaff);
INLINE void bg_aff_scale(BG_AFFINE *bgaff, FIXED sx, FIXED sy);
INLINE void bg_aff_shearx(BG_AFFINE *bgaff, FIXED hx);
INLINE void bg_aff_sheary(BG_AFFINE *bgaff, FIXED hy);

void bg_aff_rotate(BG_AFFINE *bgaff, u16 alpha);
void bg_aff_rotscale(BG_AFFINE *bgaff, int sx, int sy, u16 alpha);
void bg_aff_premul(BG_AFFINE *dst, const BG_AFFINE *src);
void bg_aff_postmul(BG_AFFINE *dst, const BG_AFFINE *src);
void bg_aff_rotscale2(BG_AFFINE *bgaff, const AFF_SRC *as);
void bg_rotscale_ex(BG_AFFINE *bgaff, const AFF_SRC_EX *asx);

/*!	\}	*/


// --------------------------------------------------------------------
// BITMAPS
// --------------------------------------------------------------------

//! \addtogroup grpVideoBmp
/*!	\{	*/

//! \name mode 3
//\{

#define M3_CLEAR()  memset32(vid_mem,  0, M3_SIZE/4)

INLINE void m3_fill(COLOR clr);
INLINE void m3_plot(int x, int y, COLOR clr);
INLINE void m3_line(int xa, int ya, int xb, int yb, COLOR clr);
INLINE void m3_rect(int ll, int tt, int rr, int bb, COLOR clr);
INLINE void m3_frame(int ll, int tt, int rr, int bb, COLOR clr);
//void m3_hline(int x0, int x1, int y, COLOR clr);
//void m3_vline(int x, int y0, int y1, COLOR clr);

//\}


//! \name mode 4
//\{

#define M4_CLEAR()  memset32(vid_page, 0, M4_SIZE/4)

INLINE void m4_fill(u8 clrid);
INLINE void m4_plot(int x, int y, u8 clrid);
INLINE void m4_rect(int ll, int tt, int rr, int bb, u8 clrid);
//void m4_hline(int x0, int x1, int y, u8 clrid);
//void m4_vline(int x, int y0, int y1, u8 clrid);

//\}


//! \name mode 5
//\{

#define M5_CLEAR()  memset32(vid_page, 0, M5_SIZE/4)

INLINE void m5_fill(COLOR clr);
INLINE void m5_plot(int x, int y, COLOR clr);
INLINE void m5_line(int xa, int ya, int xb, int yb, COLOR clr);
INLINE void m5_rect(int ll, int tt, int rr, int bb, COLOR clr);
INLINE void m5_frame(int ll, int tt, int rr, int bb, COLOR clr);
//void m5_hline(int x0, int x1, int y, COLOR clr);
//void m5_vline(int x, int y0, int y1, COLOR clr);

//\}


//! \name Internal
//\{

// 8bit (mode 4, ase)
void bm8_hline(u8 *dst, int width, u8 clrid);
void bm8_vline(u8 *dst, int height, u8 clrid, int pitch);
//void bm8_line(u8 *dst, int dx, int y, u8 clrid, int pitch);
void bm8_rect(u8 *dst, int width, int height, u8 clrid, int pitch);
void bm8_frame(u8 *dst, int width, int height, u8 clrid, int pitch);

// 16bit (mode 3/5, se)
void bm16_hline(u16 *dst, int width, u16 clr);
void bm16_vline(u16 *dst, int height, u16 clr, int pitch);
void bm16_line(u16 *dst, int dx, int y, COLOR clr, int pitch);
void bm16_rect(u16 *dst, int width, int height, u16 clr, int pitch);
void bm16_frame(u16 *dst, int width, int height, u16 clr, int pitch);

//\}


/*!	\}	*/



// --------------------------------------------------------------------
// OBJECTS
// --------------------------------------------------------------------



//! \addtogroup grpVideoObj
/*!	\{	*/

#define OAM_CLEAR()	memset32(oam_mem, 0, OAM_SIZE/4)

// --- Prototypes -----------------------------------------------------

// --- Full OAM ---
void oam_init(OBJ_ATTR *obj, u32 count);
INLINE void oam_copy(OBJ_ATTR *dst, const OBJ_ATTR *src, u32 count);

// --- Obj attr only ---
INLINE OBJ_ATTR *obj_set_attr(OBJ_ATTR *obj, u16 a0, u16 a1, u16 a2);
INLINE void obj_set_pos(OBJ_ATTR *obj, int x, int y);
INLINE void obj_hide(OBJ_ATTR *oatr);
INLINE void obj_unhide(OBJ_ATTR *obj, u16 mode);

INLINE const u8 *obj_get_size(OBJ_ATTR *obj);
INLINE int obj_get_width(OBJ_ATTR *obj);
INLINE int obj_get_height(OBJ_ATTR *obj);

void obj_copy(OBJ_ATTR *dst, const OBJ_ATTR *src, u32 count);
void obj_hide_multi(OBJ_ATTR *obj, u32 count);
void obj_unhide_multi(OBJ_ATTR *obj, u16 mode, u32 count);

// --- Obj affine only ---
void obj_aff_copy(OBJ_AFFINE *dst, const OBJ_AFFINE *src, u32 count);

INLINE void obj_aff_set(OBJ_AFFINE *oaff, 
	FIXED pa, FIXED pb, FIXED pc, FIXED pd);
INLINE void obj_aff_identity(OBJ_AFFINE *oaff);
INLINE void obj_aff_scale(OBJ_AFFINE *oaff, FIXED sx, FIXED sy);
INLINE void obj_aff_shearx(OBJ_AFFINE *oaff, FIXED hx);
INLINE void obj_aff_sheary(OBJ_AFFINE *oaff, FIXED hy);

void obj_aff_rotate(OBJ_AFFINE *oaff, u16 alpha);
void obj_aff_rotscale(OBJ_AFFINE *oaff, FIXED sx, FIXED sy, u16 alpha);
void obj_aff_premul(OBJ_AFFINE *dst, const OBJ_AFFINE *src);
void obj_aff_postmul(OBJ_AFFINE *dst, const OBJ_AFFINE *src);

void obj_aff_rotscale2(OBJ_AFFINE *oaff, const AFF_SRC *as);
void obj_rotscale_ex(OBJ_ATTR *obj, OBJ_AFFINE *oaff, const AFF_SRC_EX *asx);


// inverse (object -> screen) functions, could be useful
// inverses (prototypes)
INLINE void obj_aff_scale_inv(OBJ_AFFINE *oa, FIXED wx, FIXED wy);
INLINE void obj_aff_rotate_inv(OBJ_AFFINE *oa, u16 theta);
INLINE void obj_aff_shearx_inv(OBJ_AFFINE *oa, FIXED hx);
INLINE void obj_aff_sheary_inv(OBJ_AFFINE *oa, FIXED hy);

/*!	\}	*/


// --------------------------------------------------------------------
// INLINES
// --------------------------------------------------------------------



// --- General --------------------------------------------------------

INLINE void vid_vsync()
{
	while(REG_VCOUNT >= 160);   // wait till VDraw
	while(REG_VCOUNT < 160);    // wait till VBlank
}



// --- Colors ---------------------------------------------------------


//! Create a 15bit BGR color.
INLINE COLOR RGB15(int red, int green, int blue)
{	return (blue<<10) + (green<<5) + red;					}

//! Create a 15bit BGR color, with proper masking of R,G,B components.
INLINE COLOR RGB15_SAFE(int red, int green, int blue)
{	return ((blue&31)<<10) + ((green&31)<<5) + (red&31);	}



// --- Backgrounds ----------------------------------------------------


//! Fill screenblock \a sbb with \a se
INLINE void se_fill(SCR_ENTRY *sbb, SCR_ENTRY se)
{	memset32(sbb, dup16(se), SBB_SIZE/4);	}

//! Plot a screen entry at (\a x,\a y) of screenblock \a sbb.
INLINE void se_plot(SCR_ENTRY *sbb, int x, int y, SCR_ENTRY se)
{	sbb[y*32+x]= se;	}

//! Fill a rectangle on \a sbb with \a se.
INLINE void se_rect(SCR_ENTRY *sbb, int ll, int tt, int rr, int bb, SCR_ENTRY se)
{	bm16_rect(&sbb[tt*32+ll], rr-ll, bb-tt, se, 32);			}

//! Create a border on \a sbb with \a se.
INLINE void se_frame(SCR_ENTRY *sbb, int ll, int tt, int rr, int bb, SCR_ENTRY se)
{	bm16_frame(&sbb[tt*32+ll], rr-ll, bb-tt, se, 32);		}


// --- Affine ---


//! Copy bg affine aprameters
INLINE void bg_aff_copy(BG_AFFINE *dst, const BG_AFFINE *src)
{	*dst = *src;	}

//! Set the elements of an \a bg affine matrix.
INLINE void bg_aff_set(BG_AFFINE *bgaff, 
	FIXED pa, FIXED pb, FIXED pc, FIXED pd)
{
	bgaff->pa= pa;	bgaff->pb= pb;
	bgaff->pc= pc;	bgaff->pd= pd;
}

//! Set an bg affine matrix to the identity matrix
INLINE void bg_aff_identity(BG_AFFINE *bgaff)
{
	bgaff->pa= 0x0100;	bgaff->pb= 0;
	bgaff->pc= 0;		bgaff->pd= 0x0100;
}

//! Set an bg affine matrix for scaling.
INLINE void bg_aff_scale(BG_AFFINE *bgaff, FIXED sx, FIXED sy)
{
	bgaff->pa= sx;	bgaff->pb= 0;
	bgaff->pb= 0;	bgaff->pd= sy;
}

INLINE void bg_aff_shearx(BG_AFFINE *bgaff, FIXED hx)
{
	bgaff->pa= 0x0100;	bgaff->pb= hx;
	bgaff->pc= 0;		bgaff->pd= 0x0100;
}

INLINE void bg_aff_sheary(BG_AFFINE *bgaff, FIXED hy)
{
	bgaff->pa= 0x0100;	bgaff->pb= 0;
	bgaff->pc= hy;		bgaff->pd= 0x0100;
}


// --- Bitmaps --------------------------------------------------------


// --- mode 3 interface ---

//! Fill the mode 3 background with color \a clr.
INLINE void m3_fill(COLOR clr)	
{	memset32(vid_mem, dup16(clr), M3_SIZE/4);	}

//! Plot a single \a clr colored pixel in mode 3 at (\a x, \a y).
INLINE void m3_plot(int x, int y, COLOR clr)
{	vid_mem[y*M3_WIDTH+x]= clr;	}

//! Draw a \a clr colored line in mode 3.
INLINE void m3_line(int xa, int ya, int xb, int yb, COLOR clr)
{	bm16_line(&vid_mem[ya*M3_WIDTH+xa], xb-xa, yb-ya, clr, M3_WIDTH);	}

//! Draw a \a clr colored rectangle in mode 3.
/*! \param ll	Left side, inclusive.
*	\param tt	Top size, inclusive.
*	\param rr	Right size, exclusive.
*	\param bb	Bottom size, exclusive.
*	\param clr	Color.
*	\note Not normalized or clipped in any way.
*/
INLINE void m3_rect(int ll, int tt, int rr, int bb, COLOR clr)
{	bm16_rect(&m3_mem[tt][ll], rr-ll, bb-tt, clr, M3_WIDTH);			}


//! Draw a \a clr colored frame in mode 3.
/*! \param ll	Left side, inclusive.
*	\param tt	Top size, inclusive.
*	\param rr	Right size, exclusive.
*	\param bb	Bottom size, exclusive.
*	\param clr	Color.
*	\note Not normalized or clipped in any way.
*/
INLINE void m3_frame(int ll, int tt, int rr, int bb, COLOR clr)
{	bm16_frame(&m3_mem[tt][ll], rr-ll, bb-tt, clr, M3_WIDTH);			}


// --- mode 4 interface ---

//! Fill the current mode 4 backbuffer with \a clrid
INLINE void m4_fill(u8 clrid) 
{	memset32(vid_page, quad8(clrid), M4_SIZE/4);	}

//! Plot a \a clrid pixel on the current mode 4 backbuffer
INLINE void m4_plot(int x, int y, u8 clrid)
{
	u16 *dst= &vid_page[(y*M4_WIDTH+x)>>1];
	if(x&1)
		*dst= (*dst& 0xFF) | (clrid<<8);
	else
		*dst= (*dst&~0xFF) | clrid;
}

//! Draw a \a clrid rectangle on the current mode 4 backbuffer
INLINE void m4_rect(int ll, int tt, int rr, int bb, u8 clrid)
{	bm8_rect(&((u8*)vid_page)[tt*M4_WIDTH+ll], rr-ll, bb-tt, clrid, M4_WIDTH);	}


// --- mode 5 interface ---

//! Fill the current mode 5 backbuffer with \a clr
INLINE void m5_fill(COLOR clr) 
{	memset16(vid_page, dup16(clr), M4_SIZE/4);		}

//! Plot a \a clrid pixel on the current mode 5 backbuffer
INLINE void m5_plot(int x, int y, COLOR clr)
{	vid_page[y*M5_WIDTH+x]= clr;	}


//! Draw a \a clr colored line on the current mode 5 backbuffer
INLINE void m5_line(int xa, int ya, int xb, int yb, COLOR clr)
{	bm16_line(&vid_page[ya*M5_WIDTH+xa], xb-xa, yb-ya, clr, M5_WIDTH);	}

//! Draw a \a clr colored rectangle on the current mode 5 backbuffer
INLINE void m5_rect(int ll, int tt, int rr, int bb, COLOR clr)
{	bm16_rect(&vid_page[tt*M5_WIDTH+ll], rr-ll, bb-tt, clr, M5_WIDTH);	}

//! Draw a \a clr colored frame on the current mode 5 backbuffer
INLINE void m5_frame(int ll, int tt, int rr, int bb, COLOR clr)
{	bm16_frame(&vid_page[tt*M5_WIDTH+ll], rr-ll, bb-tt, clr, M5_WIDTH);	}



// --- Objects --------------------------------------------------------


/*!	\addtogroup grpVideoObj	*/
/*! \{	*/

//! Set the attributes of an object.
INLINE OBJ_ATTR *obj_set_attr(OBJ_ATTR *obj, u16 a0, u16 a1, u16 a2)
{
	obj->attr0= a0; obj->attr1= a1; obj->attr2= a2;
	return obj;
}

//! Set the position of \a obj
INLINE void obj_set_pos(OBJ_ATTR *obj, int x, int y)
{
	BF_SET(obj->attr0, y, ATTR0_Y);
	BF_SET(obj->attr1, x, ATTR1_X);
}

//! Copies \a count OAM entries from \a src to \a dst.
INLINE void oam_copy(OBJ_ATTR *dst, const OBJ_ATTR *src, u32 count)
{	memcpy32(dst, src, count*2);	}

//! Hide an object.
INLINE void obj_hide(OBJ_ATTR *obj)
{	BF_SET2(obj->attr0, ATTR0_HIDE, ATTR0_MODE);		}

//! Unhide an object.
/*! \param obj	Object to unhide.
*	\param mode	Object mode to unhide to. Necessary because this affects
*	  the affine-ness of the object.
*/
INLINE void obj_unhide(OBJ_ATTR *obj, u16 mode)
{	BF_SET2(obj->attr0, mode, ATTR0_MODE);				}


//! Get object's sizes as a byte array
INLINE const u8 *obj_get_size(OBJ_ATTR *obj)
{	return oam_sizes[obj->attr0>>14][obj->attr1>>14];	}

//! Get object's width
INLINE int obj_get_width(OBJ_ATTR *obj)
{	return obj_get_size(obj)[0];						}
	
//! Gets object's height
INLINE int obj_get_height(OBJ_ATTR *obj)
{	return obj_get_size(obj)[1];						}


// --- Affine only ---


//! Set the elements of an \a object affine matrix.
INLINE void obj_aff_set(OBJ_AFFINE *oaff, 
	FIXED pa, FIXED pb, FIXED pc, FIXED pd)
{
	oaff->pa= pa;	oaff->pb= pb;
	oaff->pc= pc;	oaff->pd= pd;
}

//! Set an object affine matrix to the identity matrix
INLINE void obj_aff_identity(OBJ_AFFINE *oaff)
{
	oaff->pa= 0x0100l;	oaff->pb= 0;
	oaff->pc= 0;		oaff->pd= 0x0100;
}

//! Set an object affine matrix for scaling.
INLINE void obj_aff_scale(OBJ_AFFINE *oaff, FIXED sx, FIXED sy)
{
	oaff->pa= sx;	oaff->pb= 0;
	oaff->pb= 0;	oaff->pd= sy;
}

INLINE void obj_aff_shearx(OBJ_AFFINE *oaff, FIXED hx)
{
	oaff->pa= 0x0100;	oaff->pb= hx;
	oaff->pc= 0;		oaff->pd= 0x0100;
}

INLINE void obj_aff_sheary(OBJ_AFFINE *oaff, FIXED hy)
{
	oaff->pa= 0x0100;	oaff->pb= 0;
	oaff->pc= hy;		oaff->pd= 0x0100;
}


// --- Inverse operations ---

INLINE void obj_aff_scale_inv(OBJ_AFFINE *oaff, FIXED wx, FIXED wy)
{	obj_aff_scale(oaff, ((1<<24)/wx)>>8, ((1<<24)/wy)>>8);	}

INLINE void obj_aff_rotate_inv(OBJ_AFFINE *oaff, u16 theta)
{	obj_aff_rotate(oaff, -theta);		}

INLINE void obj_aff_shearx_inv(OBJ_AFFINE *oaff, FIXED hx)
{	obj_aff_shearx(oaff, -hx);								}

INLINE void obj_aff_sheary_inv(OBJ_AFFINE *oaff, FIXED hy)
{	obj_aff_sheary(oaff, -hy);								}


/*! \}	*/

#endif // TONC_VIDEO

