//
//  BIOS call functions
//
//! \file tonc_bios.h
//! \author J Vijn
//! \date 20060508 - 20070208
//
// === NOTES ===
//
// Pretty much copied verbatim from Pern and dkARM's libgba
// (which in turn is copied from CowBite Spec (which got its info from 
//  GBATek))
// 
//
// === NOTES ===
// * Make SURE your data is aligned to 32bit boundaries. Defining data
//   as u32 (and I do mean define; not merely cast) ensures this. Either 
//   that or use __attribute__(( aligned(4) ))
// * There is a large (70 cycle in and out) overhead for SWIs. If you 
//   know what they do, consider creating replacement code
// * div by 0 locks up GBA. 
// * Cpu(Fast)Set's count is in chunks, not bytes. CpuFastSet REQUIRES
//   n*32 byte data
// * SoftReset is funky with interrupts on.
// * VBlankIntrWait is your friend. If you have a VBlank isr that clears 
//   REG_IFBIOS as well. Use this instead of REG_VCOUNT polling for
//   VSync.
// * I haven't tested many of these functions. The ones that are have a 
//   plus (+) behind their numbers.
// * I'm switched to the standard BIOS names. 

#ifndef TONC_BIOS
#define TONC_BIOS

#include "tonc_types.h"



/*!	\defgroup grpBiosDef	BIOS informalities
*	\ingroup grpBios
*/
/*!	\{	*/


// === CONSTANTS ======================================================

//! \name RegisterRamReset flags
//\{
#define RESET_EWRAM		0x01	//!< Clear 256K on-board WRAM
#define RESET_IWRAM		0x02	//!< Clear 32K in-chip WRAM
#define RESET_PALETTE	0x04	//!< Clear Palette
#define RESET_VRAM		0x08	//!< Clear VRAM
#define RESET_OAM		0x10	//!< Clear OAM. does NOT disable OBJs!
#define RESET_SIO		0x20	//!< Switches to general purpose mode
#define RESET_SOUND		0x40	//!< Reset Sound registers
#define RESET_OTHER		0x80	//!< All other registers
//\}

//! \name Cpu(Fast)Set flags
//\{
#define CS_CPY      0			//!< Copy mode
#define CS_FILL    (1<<24)		//!< Fill mode
#define CS_CPY16    0			//!< Copy in halfwords
#define CS_CPY32   (1<<26)		//!< Copy words
#define CS_FILL32  (5<<24)		//!< Fill words

#define CFS_CPY     CS_CPY		//!< Copy words
#define CFS_FILL    CS_FILL		//!< Fill words
//\}

//! \name ObjAffineSet P-element offsets
//\{
#define BG_AFF_OFS      2		//!< BgAffineDest offsets
#define OBJ_AFF_OFS	    8		//!< ObjAffineDest offsets
//\}

//! \name Decompression routines
#define BUP_ALL_OFS     (1<<31)

#define LZ_TYPE         0x00000010
#define LZ_SIZE_MASK    0xFFFFFF00
#define LZ_SIZE_SHIFT     8

#define HUF_BPP_MASK    0x0000000F
#define HUF_TYPE        0x00000020
#define HUF_SIZE_MASK   0xFFFFFF00
#define HUF_SIZE_SHIFT    8

#define RL_TYPE         0x00000030
#define RL_SIZE_MASK    0xFFFFFF00
#define RL_SIZE_SHIFT     8

#define DIF_8           0x00000001
#define DIF_16          0x00000002
#define DIF_TYPE	    0x00000080
#define DIF_SIZE_MASK   0xFFFFFF00
#define DIF_SIZE_SHIFT    8
//\}


// === MACROS =========================================================

//! BIOS calls from C
/*!	You can use this macro in a C BIOS-call wrapper. The wrapper 
*	  should declare the flags, then this call will do the rest.
*	\param x	Number of swi call (THUMB number)
*	\note	It checks the __thumb__ #define to see whether we're
*	  in ARM or THUMB mode and fixes the swi number accordingly. 
*	  Huzzah for the C proprocessor!
*/
#if	defined	( __thumb__ )
#define	swi_call(x)	 asm volatile("swi\t"#x ::: "r0", "r1", "r2", "r3")
#else
#define	swi_call(x)	 asm volatile("swi\t"#x"<<16" ::: "r0", "r1", "r2", "r3")
#endif


// === CLASSES ========================================================

// --- affine function 0x0E and 0x0F ---

/* 
*  Notational convention: postfix underscore is 2d vector
*
*	p_ = (px, py)		= texture coordinates
*	q_ = (qx, qy)		= screen coordinates
*	P  = | pa pb |		= affine matrix
*	     | pc pd |
*	d_ = (dx, dy)		= background displacement
*
*  Then: 
*
* (1)	p_ = P*q_ + d_
*
*  For transformation around a different point 
*  (texture point p0_ and screen point q0_), do
*
* (2)	p_ - p0_ = P*(q_-q0_)
*  
*  Subtracting eq 2 from eq1 we immediately find:
*
* (3)	_d = p0_ - P*q0_
*
*  For the special case of a texture->screen scale-then-rotate 
*  transformation with 
*	s_ = (sx, sy)	= inverse scales (s>1 shrinks)
*	a = alpha		= Counter ClockWise (CCW) angle
*
* (4)	P  = | sx*cos(a) -sx*sin(a) |
*            | sy*sin(a)  sy*cos(a) |
*
*
*  ObjAffineSet takes a and s_ as input and gives P
*  BgAffineSet does that and fills in d_ as well
*
*/

// affine types in tonc_types.h

//! BitUpPack ( for swi 10h)
typedef struct BUP
{
    u16 src_len;	//!< source length (bytes)	
    u8 src_bpp;		//!< source bitdepth (1,2,4,8)
    u8 dst_bpp;		//!< destination bitdepth (1,2,4,8,16,32)
    u32 dst_ofs;	//!< {0-30}: added offset {31}: zero-data offset flag
} BUP;

//! Multiboot struct
typedef	struct
{
	u32	reserved1[5];
	u8	handshake_data;
	u8	padding;
	u16	handshake_timeout;
	u8	probe_count;
	u8	client_data[3];
	u8	palette_data;
	u8	response_bit;
	u8	client_bit;
	u8	reserved2;
	u8	*boot_srcp;
	u8	*boot_endp;
	u8	*masterp;
	u8	*reserved3[3];
	u32	system_work2[4];
	u8	sendflag;
	u8	probe_target_bit;
	u8	check_wait;
	u8	server_type;
} MultiBootParam;


/*!	\}	*/


// === PROTOTYPES =====================================================


/*!	\defgroup grpBiosMain	BIOS functions
*	\ingroup grpBios
*/
/*! \{	*/

//! \name Reset functions
//\{
void SoftReset();
void RegisterRamReset(u32 flags);
//\}

//! \name Halt functions
//\{
void Halt();
void Stop();
void IntrWait(u32 flagClear, u32 irq);
void VBlankIntrWait();
//\}


//! \name Math functions
//\{
s32 Div(s32 num, s32 den);
s32 DivArm(s32 den, s32 num);
u32 Sqrt(u32 num);
s16 ArcTan(s16 dydx);
s16 ArcTan2(s16 x, s16 y);
//\}

//! \name Memory copiers/fillers
//\{
// Technically, these are misnomers. The convention is that 
// xxxset is used for fills (comp memset, strset). Or perhaps
// the C library functions are misnomers, since set can be applied 
// to both copies and fills. 
void CpuSet(const void *src, void *dst, u32 mode);
void CpuFastSet(const void *src, void *dst, u32 mode);
//\}

//! \name Rot/scale functions
//\{
// These functions are misnomers, because ObjAffineSet is merely
// a special case of/precursor to BgAffineSet. Results from either
// can be used for both objs and bgs. Oh well.
void ObjAffineSet(const ObjAffineSource *src, void *dst, s32 num, s32 offset);
void BgAffineSet(const BgAffineSource *src, BgAffineDest *dst, s32 num);
//\}

//! \name Decompression (see GBATek for format details) 
//\{
void BitUnPack(const void *src, void *dst, BUP *bup);
void LZ77UnCompWram(const void *src, void *dst);
void LZ77UnCompVram(const void *src, void *dst);
void HuffUnComp(const void *src, void *dst);
void RLUnCompWram(const void *src, void *dst);
void RLUnCompVram(const void *src, void *dst);
void Diff8bitUnFilterWram(const void *src, void *dst);
void Diff8bitUnFilterVram(const void *src, void *dst);
void Diff16bitUnFilter(const void *src, void *dst);	
//\}

//! \name Multiboot handshake
//\{
int MultiBoot(MultiBootParam* mb, u32 mode);
//\}

//! \name Sound Functions
//\{
// (I have even less of a clue what these do than for the others ---
void SoundBias(u32 bias);
void SoundDriverInit(void *src);
void SoundDriverMode(u32 mode);
void SoundDriverMain();
void SoundDriverVSync();
void SoundChannelClear();
u32 MidiKey2Freq(void *wa, u8 mk, u8 fp);
void SoundDriverVSyncOff();
void SoundDriverVSyncOn();
//\}


/*!	\}	*/


/*!	\defgroup grpBiosEx	More BIOS functions
*	\ingroup grpBios
*/
/*! \{	*/

//\{

// You can find these in swi_ex.s
void VBlankIntrDelay(u32 count);
int DivSafe(int num, int den);
int Mod(int num, int den);
void CpuFastFill(u32 wd, void *dst, u32 count);
//\}

/*!	\}	*/


// === ONCE MORE, WITH DOXYGEN! =======================================


// --- Reset ---

void SoftReset();						// swi 00h
void RegisterRamReset(u32 flags);		// swi 01h

// --- Halt ---

void Halt();							// swi 02h
void Stop();							// swi 03h
void IntrWait(u32 flagClear, u32 irq);	// swi 04h

//! Wait for the next VBlank (swi 05h).
/*! \note Requires clearing of REG_IFBIOS bit 0 at the interrupt
*	  tonc's master interrupt handler does this for you.
*/
void VBlankIntrWait();


// --- Arithmetic ---

//! Basic integer division (swi 06h).
/*! \param num	Numerator.
*	\param den	Denominator.
*	\return \a num / \a den
*	\note	div/0 results in an infinite loop. Try \c DivSafe instead
*/
s32 Div(s32 num, s32 den);

//! Basic integer division, but with switched arguments (swi 07h).
/*! \param num	Numerator.
*	\param den	Denominator.
*	\return \a num / \a den
*	\note	div/0 results in an infinite loop.
*/
s32 DivArm(s32 den, s32 num);

//! Integer Square root (swi 08h).
u32 Sqrt(u32 num);

//! Arctangent of \a dydx (swi 08h)
/*! \param dydx	Slope to get the arctangent of.
*	\return	Arctangent of \a dydx in the range &lt;-4000h, 4000h&gt;, 
*	  corresponding to 
*	  \htmlonly &lt;-&frac12;&pi;, &frac12;&pi;&gt; \endhtmlonly.
*	\note Said to be inaccurate near the range's limits.
*/
s16 ArcTan(s16 dydx);

//! Arctangent of a coordinate pair (swi 09h).
/*! This is the full-circle arctan, with an angle range of [0,FFFFh].
*/
s16 ArcTan2(s16 x, s16 y);


// --- Memory fills ---
// Technically, these are misnomers. The convention is that 
// xxxset is used for fills (comp memset, strset). Or perhaps
// the C library functions are misnomers, since set can be applied 
// to both copies and fills.

//! Transfer via CPU in (half)word chunks.
/*!	The default mode is 16bit copies. With bit 24 set, it copies 
*	  words; with bit 26 set it will keep the source address constant, 
*	  effectively performing fills instead of copies.
*	\param src	Source address.
*	\param dst	Destination address.
*	\param mode	Number of transfers, and mode bits. 
*	\note	This basically does a straightforward loop-copy, and is 
*	  not particularly fast.
*	\note	In fill-mode (bit 26), the source is \e still an address, 
*	  not a value.
*/
void CpuSet(const void *src, void *dst, u32 mode);

//! A fast transfer via CPU in 32 byte chunks.
/*!	This uses ARM's ldmia/stmia instructions to copy 8 words at a time,
*	  making it rival DMA transfers in speed. With bit 26 set it will 
*	  keep the source address constant, effectively performing fills 
*	  instead of copies.
*	\param src	Source address.
*	\param dst	Destination address.
*	\param mode	Number of words to transfer, and mode bits. 
*	\note	Both source and destination must be word aligned; the 
*		number of copies must be a multiple of 8. 
*	\note	In fill-mode (bit 26), the source is \e still an address, 
*	  not a value.
*	\note	memcpy32/16 and memset32/16 basically do the same things, but 
*	  safer. Use those instead.
*/
void CpuFastSet(const void *src, void *dst, u32 mode);


// --- Rot/scale (0Eh (+) & 0Fh (+) ) ---
// These functions are misnomers, because ObjAffineSet is merely
// a special case of / precursor to BgAffineSet. Results from either
// can be used for both objs and bgs. Oh well.

//! Sets up a simple scale-then-rotate affine transformation (swi 0Eh).
/*!	Uses a single \a ObjAffineSource struct to set up an array of affine 
*	matrices (either BG or Object) with a certain transformation. The 
*	matrix created is
\htmlonly
<table border=0 cellpadding=4 cellspacing=0>
<tr>
  <td> s<sub>x</sub>&middot;cos(&alpha;)</td>
  <td>-s<sub>x</sub>&middot;sin(&alpha;)</td>
</tr>
<tr>
  <td> s<sub>y</sub>&middot;sin(&alpha;)</td>
  <td> s<sub>y</sub>&middot;cos(&alpha;)</td>
</tr>
</table>
\endhtmlonly
*
*	\param src	Array with scale and angle information.
*	\param dst	Array of affine matrices, starting at a \a pa element.
*	\param num	Number of matrices to set.
*	\param offset	Offset between affine elements. Use 2 for BG and 
*	  8 for object matrices.
*	\note	Each element in \a src needs to be word aligned, which 
*	  devkitPro doesn't do anymore by itself.
*/
void ObjAffineSet(const ObjAffineSource *src, void *dst, s32 num, s32 offset);
void BgAffineSet(const BgAffineSource *src, BgAffineDest *dst, s32 num);


// --- Decompression (see GBATek for format details) --- 
void BitUnPack(const void *src, void *dst, BUP *bup);	// swi 10h +
void LZ77UnCompWram(const void *src, void *dst);		// swi 11h +
void LZ77UnCompVram(const void *src, void *dst);		// swi 12h +
void HuffUnComp(const void *src, void *dst);			// swi 13h +
void RLUnCompWram(const void *src, void *dst);			// swi 14h
void RLUnCompVram(const void *src, void *dst);			// swi 15h +
void Diff8bitUnFilterWram(const void *src, void *dst);	// swi 16h
void Diff8bitUnFilterVram(const void *src, void *dst);	// swi 17h
void Diff16bitUnFilter(const void *src, void *dst);		// swi 18h


// --- Multiboot handshake ---
int MultiBoot(MultiBootParam* mb, u32 mode);			// swi 25h


// --- Sound (I have even less of a clue what these do than for the others ---
void SoundBias(u32 bias);					// swi 19h
void SoundDriverInit(void *src);			// swi 1Ah
void SoundDriverMode(u32 mode);				// swi 1Bh
void SoundDriverMain();						// swi 1Ch
void SoundDriverVSync();					// swi 1Dh
void SoundChannelClear();					// swi 1Eh
u32 MidiKey2Freq(void *wa, u8 mk, u8 fp);	// swi 1Fh
void SoundDriverVSyncOff();					// swi 28h
void SoundDriverVSyncOn();					// swi 29h


// --- Extra ---

//! Wait for \a count frames
void VBlankIntrDelay(u32 count);

//! Div/0-safe division
/*! The standard Div hangs if \a den = 0. This version will return 
*	INT_MAX/MIN in that case, depending on the sign of \a num, 
*	or just \a num / \a den if \a den is not 0.
*	\param num	Numerator.
*	\param den	Denominator.
*/
int DivSafe(int num, int den);

//! Modulo: \a num % \a den.
int Mod(int num, int den);

//! A fast word fill
/*! While you can perform fills with CpuFastSet(), the fact that 
*	  swi 12 requires a source address makes it awkward to use. 
*	  This function is more like the traditional memset formulation.
*	\param wd	Fill word.
*	\param dst	Destination address.
*	\param mode	Number of words to transfer 
*/
void CpuFastFill(u32 wd, void *dst, u32 count);


#endif // TONC_BIOS


