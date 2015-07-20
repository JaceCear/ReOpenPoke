@
@ asm test routines
@

@ === pal_blend_asm5 ==================================================
/*
void pal_blend_asm5(COLOR *pa, COLOR *pb, COLOR *pc, 
	int nclrs, u32 alpha) CODE_IN_IWRAM;
//!	Blends palettes pa and pb into pc. 
//! \param pa, pb. Source palettes
//! \param pc. Destination palette
//! \param nclrs Number of colors
//! \param alpha Blend weight 0-32
//! \note u32 version, 2 clrs/loop. Loop: 16i/30c, Barrel shifter FTW.
*/
	.section .iwram,"ax", %progbits
	.align 2
	.arm
	.global pal_blend_asm5
pal_blend_asm5:
	movs	r3, r3, lsr #1			@ adjust nclrs for u32 run
	bxeq	lr						@ quit on nclrs=0
	ldr		r12, [sp]				@ get alpha from stack
	stmfd	sp!, {r4-r10}
	ldr		r7, =0x03E07C1F			@ MASKLO: -g-|b-r
	mov		r6, r7, lsl #5			@ MASKHI: g-|b-r-
.Lpbld5_loop:
		ldr		r8, [r0], #4			@ a= *pa++
		ldr		r9, [r1], #4			@ b= *pb++
		@ --- -g-|b-r
		and		r4, r6, r8, lsl #5		@ x/32: (-g-|b-r)
		and		r5, r7, r9				@ y: -g-|b-r
		sub		r5, r5, r4, lsr #5		@ z: y-x
		mla		r4, r5, r12, r4			@ z: (y-x)*w + x*32
		and		r10, r7, r4, lsr #5		@ blend(-g-|b-r)			
		@ --- b-r|-g- (rotated by 16 for cheapskatiness)
		and		r4, r6, r8, ror #11		@ x/32: -g-|b-r (ror16)
		and		r5, r7, r9, ror #16		@ y: -g-|b-r (ror16)
		sub		r5, r5, r4, lsr #5		@ z: y-x
		mla		r4, r5, r12, r4			@ z: (y-x)*w + x*32
		and		r4, r7, r4, lsr #5		@ blend(-g-|b-r (ror16))
		@ --- mix -g-|b-r and b-r|-g-
		orr		r10, r10, r4, ror #16
		@ --- write blended, loop
		str		r10, [r2], #4			@ *pc++= c
		subs	r3, r3, #1
		bgt		.Lpbld5_loop		
	ldmfd	sp!, {r4-r10}
	bx		lr

@ === pal_blend_asm ===================================================
@ DECL: void pal_blend_asm1(COLOR *pa, COLOR *pb, COLOR *pc, 
@		int nclrs, u32 alpha) CODE_IN_IWRAM;
@ DESC: blends palettes pa and pb into pc. 
@   \param pa, pb. Source palettes
@   \param pc. Destination palette
@   \param nclrs. Number of colors
@   \param alpha. Blend weight 0-32
@ NOTES: u32 version; 2 clrs at a time. Loop: 22i/38c
@ --- Reglist: ---
@   r0, r1, r2: (u32*)pa, (u32*)pb, (u32*)pc 
@   r3: nclrs
@   r4, r5: work color components a & b
@   r6, r7: green/a & red/b masks (gm, rm)
@   r8, r9, r10: current colors (a0=pa[ii], b0=.., c=..)
@   r12: alpha
	.section .iwram,"ax", %progbits
	.align 2
	.code 32
	.global pal_blend_asm1
pal_blend_asm1:
	movs	r3, r3, lsr #1		@ adjust nclrs for u32 run
	bxeq	lr		@ only run if there's something to do
	ldr		r12, [sp]				@ get alpha from stack
	stmfd	sp!, {r4-r10}
	mov		r7, #31
	orr		r7, r7, r7, lsl #16		@ rm= 0x001F001F
	mov		r6, r7, lsl #5			@ gm= 0x03E003E0
.Lpbld_loop:
	ldr		r8, [r0], #4			@ a0= *pa++
	ldr		r9, [r1], #4			@ b0= *pb++
	@ --- reds: rc = (ra*32 + alpha*(rb-ra))/32
	and		r4, r6, r8, lsl #5		@ a= ra<<5
	and		r5, r9, r7				@ b= rb
	sub		r5, r5, r4, lsr #5		@ b -= a>>5
	mla		r4, r5, r12, r4			@ a += alpha*b
	and		r10, r7, r4, asr #5		@ c= rm & (a>>5)
	@ --- greens: gc= ga + alpha*(gb-ga)/32
	and		r4, r8, r6				@ a= ga
	and		r5, r7, r9, lsr #5		@ b= gb>>5
	sub		r5, r5, r4, lsr #5		@ b -= a>>5
	mla		r4, r5, r12, r4			@ a += alpha*b
	and		r4, r4, r6				@ a &= gm
	orr		r10, r10, r4			@ c |= a
	@ --- blues: bc= ba + alpha*((bb-ba)/32)
	and		r4, r6, r8, lsr #5		@ a= ba>>5
	and		r5, r7, r9, lsr #10		@ b= bb>>10
	sub		r5, r5, r4, lsr #5		@ b -= a>>5
	mla		r4, r5, r12, r4			@ a += alpha*b
	and		r4, r4, r6				@ a &= gm
	orr		r10, r10, r4, lsl #5	@ c |= a<<5
	@ --- write blended, loop
	str		r10, [r2], #4			@ *pc++= c
	subs	r3, r3, #1
	bgt		.Lpbld_loop		
	ldmfd	sp!, {r4-r10}
	bx		lr

@ === pal_blend_asm2 ===================================================
@ DECL: void pal_blend_asm2(COLOR *pa, COLOR *pb, COLOR *pc, 
@		int nclrs, u32 alpha) CODE_IN_IWRAM;
@ DESC: blends palettes pa and pb into pc. 
@   \param pa, pb. Source palettes
@   \param pc. Destination palette
@   \param nclrs. Number of colors
@   \param alpha. Blend weight 0-32
@ NOTES: Generic u16 version. Meh. Loop: 21i/31c
@ --- Reglist: ---
@   r0, r1, r2: pa, pb, pc 
@   r3: nclrs
@   r4, r5: work color components a & b
@   r7: mask
@   r8, r9, r10: current colors (a0=pa[ii], b0=.., c=..)
@   r12: alpha
	.section .iwram,"ax", %progbits
	.align 2
	.code 32
	.global pal_blend_asm2
pal_blend_asm2:
	cmp		r3, #0		@ Ain't workin' if there's 
	bxeq	lr			@ nothing to do.
	ldr		r12, [sp]			@ get alpha from stack
	stmfd	sp!, {r4-r5,r7-r10}
	mov		r7, #31				@ color component mask
.Lpbld2_loop:
	ldrh	r8, [r0], #2
	ldrh	r9, [r1], #2
	@ --- reds:
	and		r4, r8, #31
	and		r5, r9, #31
	sub		r5, r5, r4
	mul		r5, r12, r5
	add		r10, r4, r5, asr #5
	@ --- greens:
	and		r4, r7, r8, lsr #5
	and		r5, r7, r9, lsr #5
	sub		r5, r5, r4
	mul		r5, r12, r5
	add		r4, r4, r5, asr #5
	orr		r10, r10, r4, lsl #5		
	@ --- blues: 
	mov		r4, r8, lsr #10
	rsb		r5, r4, r9, lsr #10
	mul		r5, r12, r5
	add		r4, r4, r5, asr #5
	orr		r10, r10, r4, lsl #10 
	@ --- write blended, loop
	strh	r10, [r2], #2
	subs	r3, r3, #1
	bgt		.Lpbld2_loop		
	ldmfd	sp!, {r4-r5,r7-r10}
	bx		lr

@ === pal_blend_asm3 ===================================================
@ DECL: void pal_blend_asm3(COLOR *pa, COLOR *pb, COLOR *pc, 
@		int nclrs, u32 alpha) CODE_IN_IWRAM;
@ DESC: blends palettes pa and pb into pc. 
@   \param pa, pb. Source palettes
@   \param pc. Destination palette
@   \param nclrs. Number of colors
@   \param alpha. Blend weight 0-32
@ NOTES: Also u16, but a _very_ special one.
@   Only one mul and 9 regs used. Loop: 20i/28
@ --- Reglist: ---
@   r0, r1, r2: pa, pb, pc 
@   r3: nclrs
@   r4, r5: colors a & b
@   r6: mask
@   r7 temp
@   r12: alpha
	.section .iwram,"ax", %progbits
	.align 2
	.code 32
	.global pal_blend_asm3
pal_blend_asm3:
	cmp		r3, #0		@ Ain't workin' if there's 
	bxeq	lr			@ nothing to do.
	ldr		r12, [sp]			@ get alpha from stack
	stmfd	sp!, {r4-r7}
	ldr		r6, =0x01F07C1F		@ load mask
.Lpbld3_loop:
	@ prep a
	ldrh	r7, [r0], #2			@ ---bgr
	and		r4, r6, r7, lsl #5		@ ---g--
	orr		r4, r4, r7, lsr #10		@ ---g-b
	and		r7, r7, r6				@ ---b-r
	orr		r4, r4, r7, lsl #20		@ -r-g-b
	@ prep b
	ldrh	r7, [r1], #2			@ ---bgr
	and		r5, r6, r7, lsl #5		@ ---g--
	orr		r5, r5, r7, lsr #10		@ ---g-b
	and		r7, r7, r6				@ ---b-r
	orr		r5, r5, r7, lsl #20		@ -r-g-b
	@ a and b are now 10.10.10 rgb with only the lower 5 bits
	@ filled. We can mul in range [0,32] without consequence
	@ c= a + w*(b-a)/32
	sub		r5, r5, r4
	mul		r7, r5, r12				@ magic: r7,r12,r5 takes longer
	add		r4, r4, r7, asr #5
	@ convert back to 15bit bgr
	and		r4, r4, r6				@ -r-g-b
	orr		r4, r4, r4, lsl #15		@ grbg-b
	mov		r5, r4, lsr #20			@ ----gr
	orr		r4, r5, r4, lsl #10		@ bg-bgr
	@ --- write blended, loop
	strh	r4, [r2], #2	
	subs	r3, r3, #1
	bgt		.Lpbld3_loop
	ldmfd	sp!, {r4-r7}
	bx		lr

@ === pal_blend_asm4 ===================================================
@ DECL: void pal_blend_asm4(COLOR *dst, COLOR *srca, COLOR *srcb, 
@		u32 alpha, int nclrs) CODE_IN_IWRAM;
@   Loop: 16i/27
@ --- Reglist: ---
@   r0, r1, r2: dst, srca, srcb
@   r12: nclrs
@   r4, r5: colors a & b
@   r6: mask
@   r7 temp
@   r3: alpha
	.section .iwram,"ax", %progbits
	.align 2
	.code 32
	.global pal_blend_asm4
pal_blend_asm4:
	ldr		r12, [sp]			@ get nclrs from stack
	cmp		r12, #0		 
	bxeq	lr
	stmfd	sp!, {r4-r10}
	ldr		r7, =0x01F07C1F		@ load mask -m-m-m
	mov		r6, r7, lsl #5		@ load mask m-m-m-
.Lpbld4_loop:
	ldrh	r8, [r1], #2		@ a0: ---bgr
	ldrh	r9, [r2], #2		@ b0: ---bgr
	@ red & blue
	and		r4, r6, r8, lsl #5	@  a: --b-r-
	and		r5, r7, r9			@  b: ---b-r
	sub		r5, r5, r4, lsr #5	@  b: db and dr
	mla		r4, r5, r3, r4		@  a: --bxrx
	and		r10, r7, r4, asr #5	@  c: ---b-r
	@green
	and		r4, r6, r8			@  a: ----g-
	and		r5, r7, r9, lsr #5	@  b: -----g
	sub		r5, r5, r4, lsr #5	@  b: dg
	mla		r4, r5, r3, r4		@  a: ----gx
	and		r4, r6, r4
	orr		r10, r10, r4		@  c: ---bgr
	@ --- write blended, loop
	strh	r10, [r0], #2	
	subs	r12, r12, #1
	bgt		.Lpbld4_loop
	ldmfd	sp!, {r4-r10}
	bx		lr

@ === hel_PalInterpolate16 ===========================================
@ DECL: void hel_PalInterpolate16(u16 *pPaletteMemory, const void 
@	*pPaletteA, const void *pPaletteB, int nclrs, u32 Step) CODE_IN_IWRAM;
@ NOTES: Original. Loop: 24i/34c
@ --- reg list ---
@ r0 = pPaletteMemory, pointer to target palette (BG or OBJ palette in Vram) 
@ r1 = pPaletteA, source palette 
@ r2 = pPaletteB, source palette 
@ r3 = Step, between 0..31 
@ 
@ r12 = inner_loop Counter 
@ 
	.section .iwram, "ax", %progbits 
	.align 2
	.code 32 
	.global  hel_PalInterpolate16 

hel_PalInterpolate16: 
	cmp		r3, #0		@ Ain't workin' if there's 
	bxeq	lr			@ nothing to do.

	ldr		r12, [sp]			@ get alpha from stack	 
	stmfd	sp!, {r5-r10} 

	@ here starts the inner loop 
.inner_loop: 

	ldrh	r5, [r1], #2		@ clr A
	ldrh	r8, [r2], #2		@ clr B

	@ Get clr A components
	mov		r7, r5, lsr #10		@ ba
	mov		r6, r5, lsr #5		@ ga
	and		r6, r6, #31
	and		r5, r5, #31			@ ra

	@ Get clr B components
	mov		r10, r8, lsr #10	@ bb
	mov		r9, r8, lsr #5		@ gb
	and		r9, r9, #31 
	and		r8, r8, #31         @ rb

	@ Interpolation: (1-w)*A + w*B = A + w*(B-A)
	@ get dx = xb-xa	(x= r,g,b)
	sub		r8, r8, r5			@ dr 
	sub		r9, r9, r6			@ dg 
	sub		r10, r10, r7		@ db 

	@ w*dx
	mul r8, r12, r8				@ w*dr
	mul r9, r12, r9				@ w*dg
	mul r10, r12, r10			@ w*db

	@ A + w*(B-A). Since w is .5 fixed, RSH by 5
	add r5, r5, r8, lsr #5		@ r
	add r6, r6, r9, lsr #5		@ g
	add r7, r7, r10, lsr #5		@ b

	@ OR r, g, b together and store. r5= r already
	orr r5, r5, r6, lsl #5		@ r| g<<5
	orr r5, r5, r7, lsl #10		@ r| g<<5 | b<<10
	strh r5, [r0], #2

	subs r3, r3, #1 
	bne .inner_loop 

	ldmfd sp!, {r5-r10} 
	bx    lr 
