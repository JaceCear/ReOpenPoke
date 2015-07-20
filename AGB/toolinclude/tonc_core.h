//
//  Core functionality
//
//! \file tonc_core.h
//! \author J Vijn
//! \date 20060508 - 20060508
//
// === NOTES ===
// * Contents: bits, random, dma, timer

#ifndef TONC_CORE
#define TONC_CORE

#include "tonc_memmap.h"
#include "tonc_memdef.h"



// --------------------------------------------------------------------
// BITS and BITFIELDS
// --------------------------------------------------------------------



/*! \defgroup grpCoreBit	Bit(field) macros
*	\ingroup grpCore
*/
/*!	\{	*/

//! \name Simple bit macros
//\{

//! Create value with bit \a n set
#define BIT(n)					( 1<<(n) )

//! Shift \a a by \a n
#define BIT_SHIFT(a, n)			( (a)<<(n) )

//! Set the \a flag bits in \a word
#define BIT_SET(y, flag)		( y |=  (flag) )

//! Clear the \a flag bits in \a word
#define BIT_CLEAR(y, flag)	( y &= ~(flag) )

//! Flip the \a flag bits in \a word
#define BIT_FLIP(y, flag)	( y ^=  (flag) )

//! Test whether all the \a flag bits in \a word are set
#define BIT_EQ(y, flag)		( ((y)&(flag)) == (flag) )

//\}


/*! \name some EVIL bit-field operations, >:)
*	These allow you to mimic bitfields with macros. Most of the
*	bitfields in the registers have <i>foo</i>_SHIFT and
*	<i>foo</i>_SHIFT macros indicating the mask and shift values
*	of the bitfield named <i>foo</i> in a variable.
*	These macros let you prepare, get and set the bitfields.
*/
//\{

//! Massage \a x for use in bitfield \a name.
#define BF_PREP(x, name)	( ((x)<<name##_SHIFT) & name##_MASK )

//! Get the value of bitfield \a name from \a y. Equivalent to (var=) y.name
#define BF_GET(y, name)		( ((y) & name##_MASK)>>name##_SHIFT )

//! Set bitfield \a name from \a y to \a x: y.name= x.
#define BF_SET(y, x, name)	(y = ((y)&~name##_MASK) | BF_PREP(x,name) )

//! Massage \a x for use in bitfield \a name with pre-shifted \a x
#define BF_PREP2(x, name)	( (x) & name##_MASK )

//! Get the value of bitfield \a name from \a y, but don't down-shift
#define BF_GET2(y, name)	( (y) & name##_MASK )

//! Set bitfield \a name from \a y to \a x with pre-shifted \a x
#define BF_SET2(y, x, name)	(y = ((y)&~name##_MASK) | BF_PREP2(x,name) )


// tribool: 1 if {plus} on, -1 if {minus} on, 0 if {plus}=={minus}
INLINE int bit_tribool(u32 x, int plus, int minus);

//\}

/*!	\}	*/



// --------------------------------------------------------------------
// DATA
// --------------------------------------------------------------------



/*! \defgroup grpData	Data routines
*	\ingroup grpCore
*/
/*!	\{	*/


//! \name Copying and filling routines
//\{

//! Simplified copier for GIT-exported data
#define GIT_CPY(dst, name)	memcpy16(dst, name, name##Len/2)

// memcpy/set
void memset16(void *dst, u16 hw, u32 hwcount);
void memcpy16(void *dst, const void* src, u32 hwcount);

CODE_IN_IWRAM void memset32(void *dst, u32 wd, u32 wcount);
CODE_IN_IWRAM void memcpy32(void *dst, const void* src, u32 wcount);


//!	Fastfill for halfwords, analogous to memset()
/*!	Uses <code>memset32()</code> if \a hwcount>5
*	\param dst	Destination address.
*	\param src	Source halfword (not address).
*	\param hwcount	Number of halfwords to fill.
*	\note	\a dst <b>must</b> be halfword aligned.
*	\note \a r0 returns as \a dst + \a hwcount*2.
*/
void memset16(void *dst, u16 hw, u32 hwcount);

//!	\brief Copy for halfwords.
/*!	Uses <code>memcpy32()</code> if \a hwn>6 and
	  \a src and \a dst are aligned equally.
	\param dst	Destination address.
	\param src	Source address.
	\param hwcount	 Number of halfwords to fill.
	\note \a dst and \a src <b>must</b> be halfword aligned.
	\note \a r0 and \a r1 return as
	  \a dst + \a hwcount*2 and \a src + \a hwcount*2.
*/
void memcpy16(void *dst, const void* src, u32 hwcount);


//!	Fast-fill by words, analogous to memset()
/*! Like CpuFastSet(), only without the requirement of
*	  32byte chunks and no awkward store-value-in-memory-first issue.
*	\param dst	Destination address.
*	\param src	Fill word (not address).
*	\param wdcount	Number of words to fill.
*	\note	\a dst <b>must</b> be word aligned.
*	\note \a r0 returns as \a dst + \a wdcount*4.
*/
CODE_IN_IWRAM void memset32(void *dst, u32 wd, u32 wdcount);


//!	\brief Fast-copy by words.
/*! Like CpuFastFill(), only without the requirement of 32byte chunks
*	\param dst	Destination address.
*	\param src	Source address.
*	\param wdcount	Number of words.
*	\note	\a src and \a dst <b>must</b> be word aligned.
*	\note	\a r0 and \a r1 return as
*	  \a dst + \a wdcount*4 and \a src + \a wdcount*4.
*/
CODE_IN_IWRAM void memcpy32(void *dst, const void* src, u32 wdcount);

//\}


/*! \name Repeated-value creators
*	These function take a hex-value and duplicate it to all fields,
*	like 0x88 -> 0x88888888.
*/
//\{
INLINE u16 dup8(u8 x);
INLINE u32 dup16(u16 x);
INLINE u32 quad8(u8 x);
INLINE u32 octup(u8 x);
//\}


/*!	\}	*/



// --------------------------------------------------------------------
// DMA
// --------------------------------------------------------------------



/*!	\addtogroup grpDma	*/
/*!	\{	*/


//! General purpose DMA transfer macro
/*!	\param _dst	destination address
*/
#define DMA_TRANSFER(_dst, _src, count, ch, mode)	\
do {										\
	REG_DMA[ch].cnt= 0;						\
	REG_DMA[ch].src= (const void*)(_src);	\
	REG_DMA[ch].dst= (void*)(_dst);			\
	REG_DMA[ch].cnt= (count) | (mode);		\
} while(0)


INLINE void dma_cpy(void *dst, const void *src, u32 count, int ch, u32 mode);
INLINE void dma_fill(void *dst, volatile u32 src, u32 count, int ch, u32 mode);

INLINE void dma3_cpy(void *dst, const void *src, u32 size);
INLINE void dma3_fill(void *dst, volatile u32 src, u32 size);

/*! \}	*/



// --------------------------------------------------------------------
// TIMER
// --------------------------------------------------------------------



INLINE void profile_start();
INLINE u32 profile_stop();



// === TONE GENERATOR =================================================

typedef enum
{
	NOTE_C=0, NOTE_CIS, NOTE_D,   NOTE_DIS,
	NOTE_E,   NOTE_F,   NOTE_FIS, NOTE_G,
	NOTE_GIS, NOTE_A,   NOTE_BES, NOTE_B
} eSndNoteId;

extern const u32 __snd_rates[12];

//! Gives the period of a note for the tone-gen registers.
/*! GBA sound range: 8 octaves: [-2, 5]; 8*12= 96 notes (kinda).
*	\param note	ID (range: [0,11>). See eSndNoteId.
*	\param oct	octave (range [-2,4)>).
*/
#define SND_RATE(note, oct) ( 2048-(__snd_rates[note]>>(4+(oct))) )



// --------------------------------------------------------------------
// MISC
// --------------------------------------------------------------------

/*! \defgroup grpCoreMisc	Miscellaneous routines
*	\ingroup grpCore
*/
/*!	\{	*/

//! \name Inline assembly
//\{

//! Assembly comment
#define ASM_CMT(str) asm volatile("@@ " str)

//! No$gba breakpoint
#define ASM_BREAK()	asm volatile("\tmov\t\tr11, r11")

//\}


//! \name Sector checking
//\{

//! Range check
#define IN_RANGE(x, min, max)	( (x) >= (min) && (x) < (max) )

u32 octant(int x, int y);
u32 octant_rot(int x0, int y0);

//\}


//! \name Random numbers
//\{

#define QRAN_SHIFT 15
#define QRAN_MASK  ((1<<QRAN_SHIFT)-1)
#define QRAN_MAX   QRAN_MASK

int sqran(int seed);
INLINE int qran();
INLINE int qran_range(int min, int max);

//\}

/*!	\}	*/

// --- globals --------------------------------------------------------

extern const u8 oam_sizes[3][4][2];
extern const BG_AFFINE bg_aff_dflt;
extern COLOR *vid_page;

extern int __qran_seed;
extern u16 __key_curr, __key_prev;



// --------------------------------------------------------------------
// INLINES
// --------------------------------------------------------------------



// --- Bit and bitfields -----------------------------------------------


//! Gives a tribool (-1, 0, or +1) depending on the state of some bits.
/*! Looks at the \a plus and \a minus bits of \a flags, and subtracts
*	  their status to give a +1, -1 or 0 result. Useful for direction flags.
*	\param plus		Bit number for positive result
*	\param minus	Bit number for negative result
*	\return	<b>+1</b> if \a plus bit is set but \a minus bit isn't<br>
*	  <b>-1</b> if \a minus bit is set and \a plus bit isn't<br>
*	  <b>0</b> if neither or both are set.
*/
INLINE int bit_tribool(u32 flags, int plus, int minus)
{	return ((flags>>plus)&1) - ((flags>>minus)&1);	}

// --- Data -----------------------------------------------------------

//! Duplicate a byte to form a halfword: 0x12 -> 0x1212.
INLINE u16 dup8(u8 x)	{	return x|(x<<8);		}

//! Duplicate a halfword to form a word: 0x1234 -> 0x12341234.
INLINE u32 dup16(u16 x)	{	return x|(x<<16);		}

//! Quadruple a byte to form a word: 0x12 -> 0x12121212.
INLINE u32 quad8(u8 x)	{	return x*0x01010101;	}

//! Octuple a nybble to form a word: 0x1 -> 0x11111111
INLINE u32 octup(u8 x)	{	return x*0x11111111;	}


// --- DMA ------------------------------------------------------------

/*!	\addtogroup grpDma	*/
/*!	\{	*/

//! Generic DMA copy routine.
/*!	\param dst	Destination address.
*	\param src	Source address.
*	\param count	Number of copies to perform.
*	\param ch	DMA channel.
*	\param mode	DMA transfer mode.
*	\note	\a count is the number of copies, not the size in bytes.
*/
INLINE void dma_cpy(void *dst, const void *src, u32 count, int ch, u32 mode)
{
	REG_DMA[ch].cnt= 0;
	REG_DMA[ch].src= src;
	REG_DMA[ch].dst= dst;
	REG_DMA[ch].cnt= mode | count;
}

//! Generic DMA fill routine.
/*!	\param dst	Destination address.
*	\param src	Source value.
*	\param count	Number of copies to perform.
*	\param ch	DMA channel.
*	\param mode	DMA transfer mode.
*	\note	\a count is the number of copies, not the size in bytes.
*/
INLINE void dma_fill(void *dst, volatile u32 src, u32 count, int ch, u32 mode)
{
	REG_DMA[ch].cnt= 0;
	REG_DMA[ch].src= (const void*)&src;
	REG_DMA[ch].dst= dst;
	REG_DMA[ch].cnt= count | mode | DMA_SRC_FIX;
}

//! Specific DMA copier, using channel 3, word transfers.
/*!	\param dst	Destination address.
*	\param src	Source address.
*	\param size	Number of bytes to copy
*	\note	\a size is the number of bytes
*/
INLINE void dma3_cpy(void *dst, const void *src, u32 size)
{	dma_cpy(dst, src, size/4, 3, DMA_CPY32);	}

//! Specific DMA filler, using channel 3, word transfers.
/*!	\param dst	Destination address.
*	\param src	Source value.
*	\param size	Number of bytes to copy
*	\note	\a size is the number of bytes
*/
INLINE void dma3_fill(void *dst, volatile u32 src, u32 size)
{	dma_fill(dst, src, size/4, 3, DMA_FILL32);	}

/*! \}	*/


// --- Random ---------------------------------------------------------

//! Quick (and very dirty) pseudo-random number generator
/*! \return random in range [0,8000h>
*/
INLINE int qran()
{
	__qran_seed= 1664525*__qran_seed+1013904223;
	return (__qran_seed>>16) & QRAN_MAX;
}


//! Ranged random number
/*! \return random in range [\a min, \a max>
*	\note (max-min) must be lower than 8000h
*/
INLINE int qran_range(int min, int max)
{	return (qran()*(max-min)>>QRAN_SHIFT)+min;		}


// --- Timer ----------------------------------------------------------

/*!	\addtogroup grpTimer	*/
/*!	\{	*/

//! Start a profiling run
/*!	\note Routine uses timers 3 and 3; if you're already using these
*	  somewhere, chaos is going to ensue.
*/
INLINE void profile_start()
{
	REG_TM2D= 0;	REG_TM3D= 0;
    REG_TM2CNT= 0;	REG_TM3CNT= 0;
    REG_TM3CNT= TM_ON | TM_CASCADE;
    REG_TM2CNT= TM_ON;
}

//! Stop a profiling run and return the time since its start.
/*!	\return 32bit cycle count
*/
INLINE u32 profile_stop()
{
   REG_TM2CNT= 0;
   return (REG_TM3D<<16)|REG_TM2D;
}

/*!	\}	/addtogroup	*/


#endif // TONC_CORE

