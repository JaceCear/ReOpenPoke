@
@
@
@


#define TEXT_INK		1
#define TEXT_SHADOW	2
#define TEXT_PAPER		3

#define VWF_PITCH	32

#define OFS_fontD		 4
#define OFS_fontWidths	 8
	@ #define OFS_charLut		12
#define OFS_charW		12
#define OFS_charH		13
#define OFS_dstP		14
#define OFS_dstD		16
#define OFS_dstX		20
#define OFS_dstY		22
#define OFS_colors		24
#define OFS_putc		28

/*
typedef int (*fn_putc)(int);

typedef struct TVwf
{
	u32	flags;			//!< Random flags (TODO)
	const u32	*fontD;	//!< Font data
	const u8	*fontWidths;	//!< Character widths
//	u8	*charLut;		//!< ASCII->tile map
	u8	charW;			//!< Character width (PONDER: units?)
	u8	charH;			//!< Character height (pixels)
	u16 dstP;			//!< Destination pitch
	u32 *dstD;			//!< Destination base pointer
	u16	dstX;			//!< Destination X-coordinate
	u16	dstY;			//!< Destination Y-coordinate
	u8	colors[4];		//!< Color LUT: ( NULL, ink, shadow, paper)
	fn_putc putc_;		//!< function to write a character

} TVwf;

extern TVwf *gp_vwf;

CODE_IN_IWRAM int vwf_putc8x16Tasm(int ch);
CODE_IN_IWRAM void vwf_render8x16Tasm(const u32 *srcD, int width);

*/

	.extern	gp_vwf
	.extern	vwf_render8x16T

	.global	vwf_render8x16Tasm
	.global	vwf_putc8x16Tasm
	
	.section .iwram, "ax", %progbits
	.arm
	.align
vwf_putc8x16Tasm:
	stmfd	sp!, {r4-r8, lr}

	sub		r0, r0, #32
	ldr		r3,=gp_vwf
	ldr		r3, [r3]
	@ --- prep loop ---
	@ r0: dstL
	@ r1: srcL
	@ r2: line count
	@ r3: px	(first gpvwf)
	@ r4: pxmask
	@ r5: ink clr
	@ r6: shade clr
	@ r7: width
	@ r8: tmp
	@ ip: raw
	@ lr: planemask

	ldr		r1, [r3, #OFS_fontD]		@ prep srcL
	add		r1, r1, r0, lsl #6
	ldrb	r2, [r3, #OFS_charH]		@ prep line count
	ldrb	r5, [r3, #OFS_colors+1]		@ ink clr
	ldrb	r6, [r3, #OFS_colors+2]		@ shade clr
	ldr		r7, [r3, #OFS_fontWidths]	@ prep width
	ldrb	r7, [r7, r0]
	ldr		lr,=0x11111111
	sub		sp, sp, #32*4				@ prep dstL
	mov		r0, sp
.Lprep_loop:
		ldr		ip, [r1], #4
		and		r4, lr, ip
		mul		r3, r4, r5
		and		r8, lr, ip, lsr #1
		orr		r4, r4, r8
		mla		r3, r8, r6, r3
		rsb		r4, r4, r4, lsl #4
		stmia	r0!, {r3, r4}
		subs	r2, r2, #1
		bne		.Lprep_loop
	@ --- render ---
	mov		r0, sp
	mov		r1, r7
	bl		vwf_render8x16Tasm
	
	@ --- return ---
	add		sp, sp, #32*4
	mov		r0, r7
	ldmfd	sp!, {r4-r8, lr}
	bx		lr


/*	Loop for non-transparent
	@ r9: paper clr
	mov		r4, r7, lsl #2
	rsb		r4, r4, #32
	lsr		r4, r7, lsr r4
	rsb		r4, r4, r4, lsl #4

.Lprep_loop:
		ldr		ip, [r1], #4
		and		r8, lr, ip
		mul		r3, r4, r5
		and		r8, lr, ip, lsr #1
		mla		r3, r8, r6, r3
		and		r8, lr, ip, lsr #2
		mla		r3, r8, r9, r3
		stmia	r0!, {r3, r4}
		subs	r2, r2, #1
		bne		.Lprep_loop

*/

@ CODE_IN_IWRAM void vwf_render8x16Tasm(const u32 *srcD, int width);
	.section .iwram, "ax", %progbits
	.arm
	.align
vwf_render8x16Tasm:
	ldr		r3,=gp_vwf
	ldr		r3, [r3]
	ldrb	r2, [r3, #OFS_charH]
	cmp		r2, #0
	bxeq	lr
	stmfd	sp!, {r4-r7}

	ldr		r4, [r3, #OFS_dstD]
	@ --- +(y/8*pitch + y%8)*32 ---
	ldrh	r6, [r3, #OFS_dstY]
	mov		ip, r6, lsr #3
	rsb		ip, ip, ip, lsl #4
	add		r4, r4, ip, lsl #6
	and		r6, r6, #7
	add		r4, r4, r6, lsl #2
	@ --- + x/8*32 ---
	ldrh	r5, [r3, #OFS_dstX]
	add		ip, r5, r1
	strh	ip, [r3, #OFS_dstX]		
	mov		ip, r5, lsr #3
	@ --- prep shifts interlude ---
	and		r5, r5, #7
	add		r7, r1, r5				@ right
	mov		r5, r5, lsl #2			@ lsl
	rsb		r6, r5, #32				@ lsr
	add		r1, r4, ip, lsl #5		@ finish + x/8*32

	@ --- render ---
	@ r0: srcL
	@ r1: dstL
	@ r2: line count
	@ r3: px	(first gpvwf)
	@ r4: pxmask
	@ r5: 4*x
	@ r6: 32-4*x
	@ r7: right = width-x
	@ r8:
	@ ip: raw (from dstL)

.Lrender_loop:
		ldmia	r0!, {r3, r4}
		@ --- right tile (if any) ---
		cmp		r7, #8
		ldrhi	ip, [r1, #32]
		bichi	ip, ip, r4, lsr r6
		orrhi	ip, ip, r3, lsr r6
		strhi	ip, [r1, #32]
		@ --- left tile ---
		ldr		ip, [r1]
		bic		ip, ip, r4, lsl r5
		orr		ip, ip, r3, lsl r5
		str		ip, [r1], #4
		tst		r1, #31
		addeq	r1, #(VWF_PITCH-1)*32
		subs	r2, r2, #1
		bne		.Lrender_loop

	@ --- return ---
	ldmfd	sp!, {r4-r7}
	bx		lr

@ EOF
