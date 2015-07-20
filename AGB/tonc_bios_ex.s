//
//  Additional BIOS functions
//
//! \file tonc_bios_ex.s
//! \author J Vijn
//! \date 20060508 - 20060508

	.file	"tonc_bios_ex.s"
	.text
	.align 2
	.thumb
@ === VBlankIntrDelay [05h] ===========================================
@ DECL: void VBlankIntrDelay(u32 count);
@ DESC: wait count frames
@ NOTE: swi 5 uses r0, which is why I need r4 here
	.align 2
	.thumb_func
	.global VBlankIntrDelay
VBlankIntrDelay:
	push	{r4}
	sub		r4, r0, #0
	beq		.LVIDelay_done
.LVIDelay_loop:
	swi		0x05
	sub		r4, #1
	bhi		.LVIDelay_loop
.LVIDelay_done:
	pop		{r4}
	bx		lr

@ === DivSafe [06h] ===================================================
@ DECL: int DivSafe(int num, int den);
@ DESC: a div by 0 safe version
	.align 2
	.thumb_func
	.global DivSafe
DivSafe:
	cmp		r1, #0
	beq		.Ldiv_bad
	swi		0x06
	bx		lr
.Ldiv_bad:
	cmp		r0, #0		@ PONDER: use carry bit for less instrs ?
	blt		.Ldiv_bad_neg
	mvn		r0, r1		@ 0xFFFF:FFFF
	lsr		r0, #1		@ 0x7FFF:FFFF
	bx		lr
.Ldiv_bad_neg:
	mov		r0, #0x80
	lsl		r0, #24
	bx		lr
	

@ === Mod [06h] =======================================================
@ DECL: int Mod(int num, int den);
@ DESC: 
	.align 2
	.thumb_func
	.global Mod
Mod:
	swi		0x06
	mov		r0, r1
	bx		lr

@ === CpuFastFill [0Ch] ===============================================
@ DECL: void CpuFastFill(u32 wd, void *dst, u32 count);
@ DESC: 
	.align 2
	.thumb_func
	.global CpuFastFill
CpuFastFill:
	push	{r0}			@ push wd on stack
	mov		r0, #128
	lsl		r0, r0, #17
	orr		r2, r2, r0		@ add fill flag
	mov		r0, sp			@ point to stack (where w is)
	swi		0x0C
	add		sp, sp, #4		@ 'pop'
	bx		lr

@ EOF
