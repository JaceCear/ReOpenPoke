@
@  Basic BIOS functions
@
@! \file tonc_bios_ex.s
@! \author J Vijn
@! \date 20060508 - 20060508

	.file	"tonc_bios.s"
	.text
	.align	2
	.code	16

@ === SoftReset [00h] =================================================
@ DECL: void SoftReset();
@ DESC: 
	.align 2
	.global SoftReset
	.thumb_func
SoftReset:
	swi		0x00
	bx		lr

@ === RegisterRamReset [01h] ==========================================
@ DECL: void RegisterRamReset(u32 flags);
@ DESC: 
	.align 2
	.global RegisterRamReset
	.thumb_func
RegisterRamReset:
	swi		0x01
	bx		lr

@ === Halt [02h] ======================================================
@ DECL: void Halt();
@ DESC: 
	.align 2
	.global Halt
	.thumb_func
Halt:
	swi		0x02
	bx		lr

@ === Stop [03h] ======================================================
@ DECL: void Stop();
@ DESC: 
	.align 2
	.global Stop
	.thumb_func
Stop:
	swi		0x03
	bx		lr

@ === IntrWait [04h] ==================================================
@ DECL: void IntrWait(u32 flagClear, u32 irq);
@ DESC: 
	.align 2
	.global IntrWait
	.thumb_func
IntrWait:
	swi		0x04
	bx		lr

@ === VBlankIntrWait [05h] ============================================
@ DECL: void VBlankIntrWait();
@ DESC: 
	.align 2
	.global VBlankIntrWait
	.thumb_func
VBlankIntrWait:
	swi		0x05
	bx		lr

@ === Div [06h] =======================================================
@ DECL: s32 Div(s32 num, s32 den);
@ DESC: 
	.align 2
	.global Div
	.thumb_func
Div:
	swi		0x06
	bx		lr

@ === DivArm [07h] ====================================================
@ DECL: s32 DivArm(s32 den, s32 num);
@ DESC: 
	.align 2
	.global DivArm
	.thumb_func
DivArm:
	swi		0x07
	bx		lr

@ === Sqrt [08h] ======================================================
@ DECL: u32 Sqrt(u32 num);
@ DESC: 
	.align 2
	.global Sqrt
	.thumb_func
Sqrt:
	swi		0x08
	bx		lr

@ === ArcTan [09h] ====================================================
@ DECL: s16 ArcTan(s16 dydx);
@ DESC: 
	.align 2
	.global ArcTan
	.thumb_func
ArcTan:
	swi		0x09
	bx		lr

@ === ArcTan2 [0Ah] ===================================================
@ DECL: s16 ArcTan2(s16 x, s16 y);
@ DESC: 
	.align 2
	.global ArcTan2
	.thumb_func
ArcTan2:
	swi		0x0A
	bx		lr

@ === CpuSet [0Bh] ====================================================
@ DECL: void CpuSet(const void *src, void *dst, u32 mode);
@ DESC: 
	.align 2
	.global CpuSet
	.thumb_func
CpuSet:
	swi		0x0B
	bx		lr

@ === CpuFastSet [0Ch] ================================================
@ DECL: void CpuFastSet(const void *src, void *dst, u32 mode);
@ DESC: 
	.align 2
	.global CpuFastSet
	.thumb_func
CpuFastSet:
	swi		0x0C
	bx		lr

@ === BgAffineSet [0Eh] ===============================================
@ DECL: void BgAffineSet(const BgAffineSource *src, BgAffineDest *dst, s32 num);
@ DESC: 
	.align 2
	.global BgAffineSet
	.thumb_func
BgAffineSet:
	swi		0x0E
	bx		lr

@ === ObjAffineSet [0Fh] ==============================================
@ DECL: void ObjAffineSet(const ObjAffineSource *src, void *dst, s32 num, s32 offset);
@ DESC: 
	.align 2
	.global ObjAffineSet
	.thumb_func
ObjAffineSet:
	swi		0x0F
	bx		lr

@ === BitUnPack [10h] =================================================
@ DECL: void BitUnPack(const void *src, void *dst, BUP *bup);
@ DESC: 
	.align 2
	.global BitUnPack
	.thumb_func
BitUnPack:
	swi		0x10
	bx		lr

@ === LZ77UnCompWram [11h] ============================================
@ DECL: void LZ77UnCompWram(const void *src, void *dst);
@ DESC: 
	.align 2
	.global LZ77UnCompWram
	.thumb_func
LZ77UnCompWram:
	swi		0x11
	bx		lr

@ === LZ77UnCompVram [12h] ============================================
@ DECL: void LZ77UnCompVram(const void *src, void *dst);
@ DESC: 
	.align 2
	.global LZ77UnCompVram
	.thumb_func
LZ77UnCompVram:
	swi		0x12
	bx		lr

@ === HuffUnComp [13h] ================================================
@ DECL: void HuffUnComp(const void *src, void *dst);
@ DESC: 
	.align 2
	.global HuffUnComp
	.thumb_func
HuffUnComp:
	swi		0x13
	bx		lr

@ === RLUnCompWram [14h] ==============================================
@ DECL: void RLUnCompWram(const void *src, void *dst);
@ DESC: 
	.align 2
	.global RLUnCompWram
	.thumb_func
RLUnCompWram:
	swi		0x14
	bx		lr

@ === RLUnCompVram [15h] ==============================================
@ DECL: void RLUnCompVram(const void *src, void *dst);
@ DESC: 
	.align 2
	.global RLUnCompVram
	.thumb_func
RLUnCompVram:
	swi		0x15
	bx		lr

@ === Diff8bitUnFilterWram [16h] ======================================
@ DECL: void Diff8bitUnFilterWram(const void *src, void *dst);
@ DESC: 
	.align 2
	.global Diff8bitUnFilterWram
	.thumb_func
Diff8bitUnFilterWram:
	swi		0x16
	bx		lr

@ === Diff8bitUnFilterVram [17h] ======================================
@ DECL: void Diff8bitUnFilterVram(const void *src, void *dst);
@ DESC: 
	.align 2
	.global Diff8bitUnFilterVram
	.thumb_func
Diff8bitUnFilterVram:
	swi		0x17
	bx		lr

@ === Diff16bitUnFilter [18h] =========================================
@ DECL: void Diff16bitUnFilter(const void *src, void *dst);
@ DESC: 
	.align 2
	.global Diff16bitUnFilter
	.thumb_func
Diff16bitUnFilter:
	swi		0x18
	bx		lr

@ === SoundBias [19h] =================================================
@ DECL: int MultiBoot(MultiBootParam* mb, u32 mode);
@ DESC: 
	.align 2
	.global SoundBias
	.thumb_func
SoundBias:
	swi		0x19
	bx		lr

@ === SoundDriverInit [1Ah] ===========================================
@ DECL: void SoundBias(u32 bias);
@ DESC: 
@	.align 2
@	.global SoundDriverInit
@	.thumb_func
@SoundDriverInit:
@	swi		0x1A
@	bx		lr

@ === SoundDriverMode [1Bh] ===========================================
@ DECL: void SoundDriverInit(void *src);
@ DESC: 
@	.align 2
@	.global SoundDriverMode
@	.thumb_func
@SoundDriverMode:
@	swi		0x1B
@	bx		lr

@ === SoundDriverMain [1Ch] ===========================================
@ DECL: void SoundDriverMode(u32 mode);
@ DESC: 
@	.align 2
@	.global SoundDriverMain
@	.thumb_func
@SoundDriverMain:
@	swi		0x1C
@	bx		lr

@ === SoundDriverVSync [1Dh] ==========================================
@ DECL: void SoundDriverMain();
@ DESC: 
@	.align 2
@	.global SoundDriverVSync
@	.thumb_func
@SoundDriverVSync:
@	swi		0x1D
@	bx		lr

@ === SoundChannelClear [1Eh] =========================================
@ DECL: void SoundDriverVSync();
@ DESC: 
@	.align 2
@	.global SoundChannelClear
@	.thumb_func
@SoundChannelClear:
@	swi		0x1E
@	bx		lr

@ === MidiKey2Freq [1Fh] ==============================================
@ DECL: void SoundChannelClear();
@ DESC: 
	.align 2
	.global MidiKey2Freq
	.thumb_func
MidiKey2Freq:
	swi		0x1F
	bx		lr

@ === MultiBoot [25h] =================================================
@ DECL: u32 MidiKey2Freq(void *wa, u8 mk, u8 fp);
@ DESC: 
	.align 2
	.global MultiBoot
	.thumb_func
MultiBoot:
	swi		0x25
	bx		lr

@ === SoundDriverVSyncOff [28h] =======================================
@ DECL: void SoundDriverVSyncOff();
@ DESC: 
@	.align 2
@	.global SoundDriverVSyncOff
@	.thumb_func
@SoundDriverVSyncOff:
@	swi		0x28
@	bx		lr

@ === SoundDriverVSyncOn [29h] ========================================
@ DECL: void SoundDriverVSyncOn();
@ DESC: 
@	.align 2
@	.global SoundDriverVSyncOn
@	.thumb_func
@SoundDriverVSyncOn:
@	swi		0x29
@	bx		lr

@ EOF
