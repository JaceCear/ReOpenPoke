@********************************************************************
@*          AgbMemoryMap.s                                          *
@*            AGB Memory Map Constants (GAS)                        *
@*                                                                  *
@*          Copyright (C) 1999-2001 NINTENDO Co.,Ltd.               *
@********************************************************************


@--------------------------------------------------------------------
@-                      Memory Map                                  -
@--------------------------------------------------------------------

BOOT_ROM                =   0x00000000          @ Boot ROM
BOOT_ROM_END            =   (BOOT_ROM + 0x4000)
EX_WRAM                 =   0x02000000          @ CPU External Work RAM
EX_WRAM_END             =   (EX_WRAM + 0x40000)
CPU_WRAM                =   0x03000000          @ CPU Internal Work RAM
CPU_WRAM_END            =   (CPU_WRAM + 0x8000)
WRAM                    =    EX_WRAM            @ Entire Work RAM
WRAM_END                =    CPU_WRAM_END
SOUND_AREA_ADDR_BUF     =   (CPU_WRAM_END - 0x10)@ Sound Driver Work Address
INTR_CHECK_BUF          =   (CPU_WRAM_END - 0x8)@ Interrupt Check
SOFT_RESET_DIRECT_BUF   =   (CPU_WRAM_END - 0x6)@ SoftReset() Specify Return To
INTR_VECTOR_BUF         =   (CPU_WRAM_END - 0x4)@ Interrupt Branch Address
REG_BASE                =   0x04000000          @ Registers
REG_END                 =   (REG_BASE +  0x300)
PLTT                    =   0x05000000          @ Palette RAM
PLTT_END                =   (PLTT +      0x400)
BG_PLTT                 =   (PLTT +        0x0) @ BG Palette RAM
BG_PLTT_END             =   (PLTT +      0x200)
OBJ_PLTT                =   (PLTT +      0x200) @ OBJ Palette RAM
OBJ_PLTT_END            =   (PLTT +      0x400)
VRAM                    =   0x06000000          @ VRAM
VRAM_END                =   (VRAM +    0x18000)
BG_VRAM                 =   (VRAM +        0x0) @ BG Character/Screen RAM
BG_BITMAP0_VRAM         =   (VRAM +        0x0) @ BG Bitmap 0 RAM
BG_BITMAP1_VRAM         =   (VRAM +     0xa000) @ BG Bitmap 1 RAM
OBJ_MODE0_VRAM          =   (VRAM +    0x10000) @ OBJ Character RAM
OBJ_MODE1_VRAM          =   (VRAM +    0x10000)
OBJ_MODE2_VRAM          =   (VRAM +    0x10000)
OBJ_MODE3_VRAM          =   (VRAM +    0x14000)
OBJ_MODE4_VRAM          =   (VRAM +    0x14000)
OBJ_MODE5_VRAM          =   (VRAM +    0x14000)
OBJ_VRAM_END            =   (VRAM +    0x18000)
OAM                     =   0x07000000          @ OAM
OAM_END                 =   (OAM +       0x400)

ROM_BANK0               =   0x08000000          @ ROM Bank 0
ROM_BANK0_END           =   0x0a000000
ROM_BANK1               =   0x0a000000          @ ROM Bank 1
ROM_BANK1_END           =   0x0c000000
ROM_BANK2               =   0x0c000000          @ ROM Bank 2
ROM_BANK2_END           =   0x0e000000
RAM_BANK                =   0x0c000000          @ RAM Bank
RAM_BANK_END            =   0x10000000

FLASH_1M                =   0x09fe0000          @ 1M Flash Memory
FLASH_1M_END            =   0x0a000000

@--------------------------------------------------------------------
@-                      Memory Size                                 -
@--------------------------------------------------------------------

BOOT_ROM_SIZE           =   0x4000              @ Boot ROM
EX_WRAM_SIZE            =   0x40000             @ CPU External Work RAM
CPU_WRAM_SIZE           =   0x8000              @ CPU Internal Work RAM
WRAM_SIZE               =   0x48000             @ Entire Work RAM
USR_BUF_SIZE            =   0x47fa0             @ User Area
SYS_BUF_SIZE            =   0x80                @ System Area
PLTT_SIZE               =   (2*256*2)           @ Palette RAM
BG_PLTT_SIZE            =   (2*256)             @ BG Palette RAM
OBJ_PLTT_SIZE           =   (2*256)             @ OBJ Palette RAM
VRAM_SIZE               =   0x18000             @ VRAM
BG_MODE0_VRAM_SIZE      =   0x10000             @ BG Character/Screen
BG_MODE1_VRAM_SIZE      =   0x10000
BG_MODE2_VRAM_SIZE      =   0x10000
BG_MODE3_VRAM_SIZE      =   0x14000             @ BG Bitmap
BG_MODE4_VRAM_SIZE      =   0x0a000
BG_MODE5_VRAM_SIZE      =   0x0a000
OBJ_MODE0_VRAM_SIZE     =   0x08000             @ OBJ Character
OBJ_MODE1_VRAM_SIZE     =   0x08000
OBJ_MODE2_VRAM_SIZE     =   0x08000
OBJ_MODE3_VRAM_SIZE     =   0x04000
OBJ_MODE4_VRAM_SIZE     =   0x04000
OBJ_MODE5_VRAM_SIZE     =   0x04000
OAM_SIZE                =   (8*128)             @ OAM

ROM_BANK_SIZE           =   0x02000000          @ ROM Bank
ROM_BANK0_SIZE          =   0x02000000          @ ROM Bank 0
ROM_BANK1_SIZE          =   0x02000000          @ ROM Bank 1
ROM_BANK2_SIZE          =   0x02000000          @ ROM Bank 2
RAM_BANK_SIZE           =   0x02000000          @ RAM Bank

FLASH_1M_SIZE           =   0x20000             @ 1M Flash Memory

@--------------------------------------------------------------------
@-                      Register Address                            -
@--------------------------------------------------------------------

REG_IME         =   (REG_BASE + 0x208)  @ Interrupt Master Enable
REG_IE          =   (REG_BASE + 0x200)  @ Interrupt Enable
REG_IF          =   (REG_BASE + 0x202)  @ Interrupt Request

REG_WAITCNT     =   (REG_BASE + 0x204)  @ Game Pak Wait Control

REG_DISPCNT     =   (REG_BASE + 0x0)    @ Display Control

REG_STAT        =   (REG_BASE + 0x4)    @ Status
REG_VCOUNT      =   (REG_BASE + 0x6)    @ V Counter

REG_MOSAIC      =   (REG_BASE + 0x4c)   @ Mosaic Size

REG_BLDCNT      =   (REG_BASE + 0x50)   @ Blend Mode Control
REG_BLDALPHA    =   (REG_BASE + 0x52)   @ Semi-transparent Parameter
REG_BLDY        =   (REG_BASE + 0x54)   @ Brightness Change Parameter

REG_WINCNT      =   (REG_BASE + 0x40)   @ Window Control
REG_WIN0H       =   (REG_BASE + 0x40)   @ Window 0 Horizontal Area
REG_WIN1H       =   (REG_BASE + 0x42)   @ Window 1 Horizontal Area
REG_WIN0V       =   (REG_BASE + 0x44)   @ Window 0 Vertical Area
REG_WIN1V       =   (REG_BASE + 0x46)   @ Window 1 Vertical Area
REG_WININ       =   (REG_BASE + 0x48)   @ Internal Window Control
REG_WIN0        =   (REG_BASE + 0x48)   @ Window 0 Control
REG_WIN1        =   (REG_BASE + 0x49)   @ Window 1 Control
REG_WINOUT      =   (REG_BASE + 0x4a)   @ External Window Control
REG_OBJWIN      =   (REG_BASE + 0x4b)   @ OBJ Window Control


REG_BGCNT       =   (REG_BASE + 0x8)    @ BG Control
REG_BG0CNT      =   (REG_BASE + 0x8)    @ BG 0 Control
REG_BG1CNT      =   (REG_BASE + 0xa)    @ BG 1 Control
REG_BG2CNT      =   (REG_BASE + 0xc)    @ BG 2 Control
REG_BG3CNT      =   (REG_BASE + 0xe)    @ BG 3 Control
REG_BGOFS       =   (REG_BASE + 0x10)   @ BG Offset
REG_BG0HOFS     =   (REG_BASE + 0x10)   @ BG 0 H Offset
REG_BG0VOFS     =   (REG_BASE + 0x12)   @ BG 0 V Offset
REG_BG1HOFS     =   (REG_BASE + 0x14)   @ BG 1 H Offset
REG_BG1VOFS     =   (REG_BASE + 0x16)   @ BG 1 V Offset
REG_BG2HOFS     =   (REG_BASE + 0x18)   @ BG 2 H Offset
REG_BG2VOFS     =   (REG_BASE + 0x1a)   @ BG 2 V Offset
REG_BG3HOFS     =   (REG_BASE + 0x1c)   @ BG 3 H Offset
REG_BG3VOFS     =   (REG_BASE + 0x1e)   @ BG 3 V Offset
REG_BG2AFFINE   =   (REG_BASE + 0x20)   @ BG 2 Affine Transformation Parameters
REG_BG2PA       =   (REG_BASE + 0x20)   @ BG 2 Line Direction X Coordinate Differernce
REG_BG2PB       =   (REG_BASE + 0x22)   @ BG 2 Vertical Direction X Coordinate Difference
REG_BG2PC       =   (REG_BASE + 0x24)   @ BG 2 Line Direction Y Coordinate Difference
REG_BG2PD       =   (REG_BASE + 0x26)   @ BG 2 Vertical Direction Y Coordinate Difference
REG_BG2X        =   (REG_BASE + 0x28)   @ BG 2 Start X Coordinate
REG_BG2X_L      =   (REG_BASE + 0x28)
REG_BG2X_H      =   (REG_BASE + 0x2a)
REG_BG2Y        =   (REG_BASE + 0x2c)   @ BG 2 Start Y Coordinate
REG_BG2Y_L      =   (REG_BASE + 0x2c)
REG_BG2Y_H      =   (REG_BASE + 0x2e)
REG_BG3AFFINE   =   (REG_BASE + 0x30)   @ BG 3 Affine Transformation Parameters
REG_BG3PA       =   (REG_BASE + 0x30)   @ BG 3 Line Direction X Coordinate Difference
REG_BG3PB       =   (REG_BASE + 0x32)   @ BG 3 Vertical Direction X Coordinate Difference
REG_BG3PC       =   (REG_BASE + 0x34)   @ BG 3 Line Direction Y Coordinate Difference
REG_BG3PD       =   (REG_BASE + 0x36)   @ BG 3 Vertical Direction Y Coordinate Difference
REG_BG3X        =   (REG_BASE + 0x38)   @ BG 3 Start X Coordinate
REG_BG3X_L      =   (REG_BASE + 0x38)
REG_BG3X_H      =   (REG_BASE + 0x3a)
REG_BG3Y        =   (REG_BASE + 0x3c)   @ BG 3 Start Y Coordinate
REG_BG3Y_L      =   (REG_BASE + 0x3c)
REG_BG3Y_H      =   (REG_BASE + 0x3e)


REG_SOUNDCNT    =   (REG_BASE + 0x80)   @ Sound Control
REG_SOUNDCNT_L  =   (REG_BASE + 0x80)
REG_SOUNDCNT_H  =   (REG_BASE + 0x82)
REG_SOUNDCNT_X  =   (REG_BASE + 0x84)

REG_SOUNDBIAS   =   (REG_BASE + 0x88)   @ Sound BIAS

REG_SOUND1CNT   =   (REG_BASE + 0x60)   @ Sound 1 Control
REG_SOUND1CNT_L =   (REG_BASE + 0x60)
REG_SOUND1CNT_H =   (REG_BASE + 0x62)
REG_SOUND1CNT_X =   (REG_BASE + 0x64)
REG_SOUND2CNT   =   (REG_BASE + 0x68)   @ Sound 2 Control
REG_SOUND2CNT_L =   (REG_BASE + 0x68)
REG_SOUND2CNT_H =   (REG_BASE + 0x6c)
REG_SOUND3CNT   =   (REG_BASE + 0x70)   @ Sound 3 Control
REG_SOUND3CNT_L =   (REG_BASE + 0x70)
REG_SOUND3CNT_H =   (REG_BASE + 0x72)
REG_SOUND3CNT_X =   (REG_BASE + 0x74)
REG_SOUND4CNT   =   (REG_BASE + 0x78)   @ Sound 4 Control
REG_SOUND4CNT_L =   (REG_BASE + 0x78)
REG_SOUND4CNT_H =   (REG_BASE + 0x7c)

REG_WAVE_RAM    =   (REG_BASE + 0x90)   @ Sound 3 Waveform RAM
REG_WAVE_RAM0   =   (REG_BASE + 0x90)
REG_WAVE_RAM0_L =   (REG_BASE + 0x90)
REG_WAVE_RAM0_H =   (REG_BASE + 0x92)
REG_WAVE_RAM1   =   (REG_BASE + 0x94)
REG_WAVE_RAM1_L =   (REG_BASE + 0x94)
REG_WAVE_RAM1_H =   (REG_BASE + 0x96)
REG_WAVE_RAM2   =   (REG_BASE + 0x98)
REG_WAVE_RAM2_L =   (REG_BASE + 0x98)
REG_WAVE_RAM2_H =   (REG_BASE + 0x9a)
REG_WAVE_RAM3   =   (REG_BASE + 0x9c)
REG_WAVE_RAM3_L =   (REG_BASE + 0x9c)
REG_WAVE_RAM3_H =   (REG_BASE + 0x9e)

REG_FIFO        =   (REG_BASE + 0xa0)   @ Sound FIFO
REG_FIFO_A      =   (REG_BASE + 0xa0)
REG_FIFO_A_L    =   (REG_BASE + 0xa0)
REG_FIFO_A_H    =   (REG_BASE + 0xa2)
REG_FIFO_B      =   (REG_BASE + 0xa4)
REG_FIFO_B_L    =   (REG_BASE + 0xa4)
REG_FIFO_B_H    =   (REG_BASE + 0xa6)


REG_DMA0        =   (REG_BASE + 0xb0)   @ DMA 0
REG_DMA0SAD     =   (REG_BASE + 0xb0)   @ (Internal Memory -> Internal Memory)
REG_DMA0SAD_L   =   (REG_BASE + 0xb0)
REG_DMA0SAD_H   =   (REG_BASE + 0xb2)
REG_DMA0DAD     =   (REG_BASE + 0xb4)
REG_DMA0DAD_L   =   (REG_BASE + 0xb4)
REG_DMA0DAD_H   =   (REG_BASE + 0xb6)
REG_DMA0CNT     =   (REG_BASE + 0xb8)
REG_DMA0CNT_L   =   (REG_BASE + 0xb8)
REG_DMA0CNT_H   =   (REG_BASE + 0xba)
REG_DMA1        =   (REG_BASE + 0xbc)   @ DMA 1
REG_DMA1SAD     =   (REG_BASE + 0xbc)   @ (Internal Memory -> Sound FIFO/Internal Memory)
REG_DMA1SAD_L   =   (REG_BASE + 0xbc)
REG_DMA1SAD_H   =   (REG_BASE + 0xbe)
REG_DMA1DAD     =   (REG_BASE + 0xc0)
REG_DMA1DAD_L   =   (REG_BASE + 0xc0)
REG_DMA1DAD_H   =   (REG_BASE + 0xc2)
REG_DMA1CNT     =   (REG_BASE + 0xc4)
REG_DMA1CNT_L   =   (REG_BASE + 0xc4)
REG_DMA1CNT_H   =   (REG_BASE + 0xc6)
REG_DMA2        =   (REG_BASE + 0xc8)   @ DMA 2
REG_DMA2SAD     =   (REG_BASE + 0xc8)   @ (Internal Memory -> Sound FIFO/Internal Memory)
REG_DMA2SAD_L   =   (REG_BASE + 0xc8)
REG_DMA2SAD_H   =   (REG_BASE + 0xca)
REG_DMA2DAD     =   (REG_BASE + 0xcc)
REG_DMA2DAD_L   =   (REG_BASE + 0xcc)
REG_DMA2DAD_H   =   (REG_BASE + 0xce)
REG_DMA2CNT     =   (REG_BASE + 0xd0)
REG_DMA2CNT_L   =   (REG_BASE + 0xd0)
REG_DMA2CNT_H   =   (REG_BASE + 0xd2)
REG_DMA3        =   (REG_BASE + 0xd4)   @ DMA 3
REG_DMA3SAD     =   (REG_BASE + 0xd4)   @ (Game Pak/Internal Memory <--> Internal Memory)
REG_DMA3SAD_L   =   (REG_BASE + 0xd4)
REG_DMA3SAD_H   =   (REG_BASE + 0xd6)
REG_DMA3DAD     =   (REG_BASE + 0xd8)
REG_DMA3DAD_L   =   (REG_BASE + 0xd8)
REG_DMA3DAD_H   =   (REG_BASE + 0xda)
REG_DMA3CNT     =   (REG_BASE + 0xdc)
REG_DMA3CNT_L   =   (REG_BASE + 0xdc)
REG_DMA3CNT_H   =   (REG_BASE + 0xde)


REG_TM0CNT      =   (REG_BASE + 0x100)  @ Timer 0
REG_TM0CNT_L    =   (REG_BASE + 0x100)
REG_TM0CNT_H    =   (REG_BASE + 0x102)
REG_TM1CNT      =   (REG_BASE + 0x104)  @ Timer 1
REG_TM1CNT_L    =   (REG_BASE + 0x104)
REG_TM1CNT_H    =   (REG_BASE + 0x106)
REG_TM2CNT      =   (REG_BASE + 0x108)  @ Timer 2
REG_TM2CNT_L    =   (REG_BASE + 0x108)
REG_TM2CNT_H    =   (REG_BASE + 0x10a)
REG_TM3CNT      =   (REG_BASE + 0x10c)  @ Timer 3
REG_TM3CNT_L    =   (REG_BASE + 0x10c)
REG_TM3CNT_H    =   (REG_BASE + 0x10e)


REG_RCNT	=   (REG_BASE + 0x134)	@ General Input/Ouput Control

REG_SIOCNT      =   (REG_BASE + 0x128)  @ Serial Communication Control
REG_SIODATA8    =   (REG_BASE + 0x12a)  @ 8 bit Serial Communication Data
REG_SIODATA32   =   (REG_BASE + 0x120)  @ 32 bit Serial Communication Data
REG_SIOMLT_SEND =   (REG_BASE + 0x12a)  @ Multi-play SIO Send Data
REG_SIOMLT_RECV =   (REG_BASE + 0x120)  @ Multi-play SIO Receive Data
REG_SIOMULTI0   =   (REG_BASE + 0x120)
REG_SIOMULTI1   =   (REG_BASE + 0x122)
REG_SIOMULTI2   =   (REG_BASE + 0x124)
REG_SIOMULTI3   =   (REG_BASE + 0x126)

REG_JOYCNT      =   (REG_BASE + 0x140)  @ JOY Bus Communication Control
REG_JOYSTAT     =   (REG_BASE + 0x158)  @ JOY Bus Status
REG_JOY_RECV    =   (REG_BASE + 0x150)  @ JOY Bus Receive Data
REG_JOY_RECV_L  =   (REG_BASE + 0x150)
REG_JOY_RECV_H  =   (REG_BASE + 0x152)
REG_JOY_TRANS   =   (REG_BASE + 0x154)  @ Joy Bus Send Data
REG_JOY_TRANS_L =   (REG_BASE + 0x154)
REG_JOY_TRANS_H =   (REG_BASE + 0x156)


REG_KEYINPUT    =   (REG_BASE + 0x130)  @ Key Input
REG_KEYCNT      =   (REG_BASE + 0x132)  @ Key Control


@--------------------------------------------------------------------
@-                      Register Offset                             -
@--------------------------------------------------------------------

OFFSET_REG_IME          =   0x208       @ Interrupt Master Enable
OFFSET_REG_IE           =   0x200       @ Interrupt Enable
OFFSET_REG_IF           =   0x202       @ Interrupt Request

OFFSET_REG_WAITCNT      =   0x204       @ Game Pak Wait Control

OFFSET_REG_DISPCNT      =   0x0         @ Display Control

OFFSET_REG_STAT         =   0x4         @ Status
OFFSET_REG_VCOUNT       =   0x6         @ V Counter

OFFSET_REG_MOSAIC       =   0x4c        @ Mosaic Size

OFFSET_REG_BLDCNT       =   0x50        @ Blend Mode Control
OFFSET_REG_BLDALPHA     =   0x52        @ Semi-transparent Parameter
OFFSET_REG_BLDY         =   0x54        @ Brightness Change Parameter

OFFSET_REG_WINCNT       =   0x40        @ Window Control
OFFSET_REG_WIN0H        =   0x40        @ Window 0 Horizontal Area
OFFSET_REG_WIN1H        =   0x42        @ Window 1 Horizontal Area
OFFSET_REG_WIN0V        =   0x44        @ Window 0 Vertical Area
OFFSET_REG_WIN1V        =   0x46        @ Window 1 Vertical Area
OFFSET_REG_WININ        =   0x48        @ Internal Window Control
OFFSET_REG_WIN0         =   0x48        @ Window 0 Control
OFFSET_REG_WIN1         =   0x49        @ Window 1 Control
OFFSET_REG_WINOUT       =   0x4a        @ External Window Control
OFFSET_REG_OBJWIN       =   0x4b        @ OBJ Window Control


OFFSET_REG_BGCNT        =   0x8         @ BG Control
OFFSET_REG_BG0CNT       =   0x8         @ BG 0 Control
OFFSET_REG_BG1CNT       =   0xa         @ BG 1 Control
OFFSET_REG_BG2CNT       =   0xc         @ BG 2 Control
OFFSET_REG_BG3CNT       =   0xe         @ BG 3 Control
OFFSET_REG_BGOFS        =   0x10        @ BG Offset
OFFSET_REG_BG0HOFS      =   0x10        @ BG 0 H Offset
OFFSET_REG_BG0VOFS      =   0x12        @ BG 0 V Offset
OFFSET_REG_BG1HOFS      =   0x14        @ BG 1 H Offset
OFFSET_REG_BG1VOFS      =   0x16        @ BG 1 V Offset
OFFSET_REG_BG2HOFS      =   0x18        @ BG 2 H Offset
OFFSET_REG_BG2VOFS      =   0x1a        @ BG 2 V Offset
OFFSET_REG_BG3HOFS      =   0x1c        @ BG 3 H Offset
OFFSET_REG_BG3VOFS      =   0x1e        @ BG 3 V Offset
OFFSET_REG_BG2AFFINE    =   0x20        @ BG 2 Affine Transformation Parameters
OFFSET_REG_BG2PA        =   0x20        @ BG 2 Line Direction X Coordinate Difference
OFFSET_REG_BG2PB        =   0x22        @ BG 2 Vertical Direction X Coordinate Difference
OFFSET_REG_BG2PC        =   0x24        @ BG 2 Line Direction Y Coordinate Difference
OFFSET_REG_BG2PD        =   0x26        @ BG 2 Vertical Direction Y Coordinate Difference
OFFSET_REG_BG2X         =   0x28        @ BG 2 Start X Coordinate
OFFSET_REG_BG2X_L       =   0x28
OFFSET_REG_BG2X_H       =   0x2a
OFFSET_REG_BG2Y         =   0x2c        @ BG 2 Start Y Coordinate
OFFSET_REG_BG2Y_L       =   0x2c
OFFSET_REG_BG2Y_H       =   0x2e
OFFSET_REG_BG3AFFINE    =   0x30        @ BG 3 Affine Transformation Parameters
OFFSET_REG_BG3PA        =   0x30        @ BG 3 Line Direction X Coordinate Difference
OFFSET_REG_BG3PB        =   0x32        @ BG 3 Vertical Direction X Coordinate Difference
OFFSET_REG_BG3PC        =   0x34        @ BG 3 Line Direction Y Coordinate Difference
OFFSET_REG_BG3PD        =   0x36        @ BG 3 Vertical Direction Y Coordinate Difference
OFFSET_REG_BG3X         =   0x38        @ BG 3 Start X Coordinate
OFFSET_REG_BG3X_L       =   0x38
OFFSET_REG_BG3X_H       =   0x3a
OFFSET_REG_BG3Y         =   0x3c        @ BG 3 Start Y Coordinate
OFFSET_REG_BG3Y_L       =   0x3c
OFFSET_REG_BG3Y_H       =   0x3e


OFFSET_REG_SOUNDCNT     =   0x80        @ Sound Control
OFFSET_REG_SOUNDCNT_L   =   0x80
OFFSET_REG_SOUNDCNT_H   =   0x82
OFFSET_REG_SOUNDCNT_X   =   0x84

OFFSET_REG_SOUNDBIAS    =   0x88        @ Sound BIAS

OFFSET_REG_SOUND1CNT    =   0x60        @ Sound 1 Control
OFFSET_REG_SOUND1CNT_L  =   0x60
OFFSET_REG_SOUND1CNT_H  =   0x62
OFFSET_REG_SOUND1CNT_X  =   0x64
OFFSET_REG_SOUND2CNT    =   0x68        @ Sound 2 Control
OFFSET_REG_SOUND2CNT_L  =   0x68
OFFSET_REG_SOUND2CNT_H  =   0x6c
OFFSET_REG_SOUND3CNT    =   0x70        @ Sound 3 Control
OFFSET_REG_SOUND3CNT_L  =   0x70
OFFSET_REG_SOUND3CNT_H  =   0x72
OFFSET_REG_SOUND3CNT_X  =   0x74
OFFSET_REG_SOUND4CNT    =   0x78        @ Sound 4 Control
OFFSET_REG_SOUND4CNT_L  =   0x78
OFFSET_REG_SOUND4CNT_H  =   0x7c

OFFSET_REG_WAVE_RAM     =   0x90        @ Sound 3 Waveform RAM
OFFSET_REG_WAVE_RAM0    =   0x90
OFFSET_REG_WAVE_RAM0_L  =   0x90
OFFSET_REG_WAVE_RAM0_H  =   0x92
OFFSET_REG_WAVE_RAM1    =   0x94
OFFSET_REG_WAVE_RAM1_L  =   0x94
OFFSET_REG_WAVE_RAM1_H  =   0x96
OFFSET_REG_WAVE_RAM2    =   0x98
OFFSET_REG_WAVE_RAM2_L  =   0x98
OFFSET_REG_WAVE_RAM2_H  =   0x9a
OFFSET_REG_WAVE_RAM3    =   0x9c
OFFSET_REG_WAVE_RAM3_L  =   0x9c
OFFSET_REG_WAVE_RAM3_H  =   0x9e

OFFSET_REG_FIFO         =   0xa0        @ Sound FIFO
OFFSET_REG_FIFO_A       =   0xa0
OFFSET_REG_FIFO_A_L     =   0xa0
OFFSET_REG_FIFO_A_H     =   0xa2
OFFSET_REG_FIFO_B       =   0xa4
OFFSET_REG_FIFO_B_L     =   0xa4
OFFSET_REG_FIFO_B_H     =   0xa6


OFFSET_REG_DMA0         =   0xb0        @ DMA 0
OFFSET_REG_DMA0SAD      =   0xb0        @ (Internal Memory -> Internal Memory)
OFFSET_REG_DMA0SAD_L    =   0xb0
OFFSET_REG_DMA0SAD_H    =   0xb2
OFFSET_REG_DMA0DAD      =   0xb4
OFFSET_REG_DMA0DAD_L    =   0xb4
OFFSET_REG_DMA0DAD_H    =   0xb6
OFFSET_REG_DMA0CNT      =   0xb8
OFFSET_REG_DMA0CNT_L    =   0xb8
OFFSET_REG_DMA0CNT_H    =   0xba
OFFSET_REG_DMA1         =   0xbc        @ DMA 1
OFFSET_REG_DMA1SAD      =   0xbc        @ (Internal Memory -> Sound FIFO/Internal Memory)
OFFSET_REG_DMA1SAD_L    =   0xbc
OFFSET_REG_DMA1SAD_H    =   0xbe
OFFSET_REG_DMA1DAD      =   0xc0
OFFSET_REG_DMA1DAD_L    =   0xc0
OFFSET_REG_DMA1DAD_H    =   0xc2
OFFSET_REG_DMA1CNT      =   0xc4
OFFSET_REG_DMA1CNT_L    =   0xc4
OFFSET_REG_DMA1CNT_H    =   0xc6
OFFSET_REG_DMA2         =   0xc8        @ DMA 2
OFFSET_REG_DMA2SAD      =   0xc8        @ (Internal Memory -> Sound FIFO/Internal Memory)
OFFSET_REG_DMA2SAD_L    =   0xc8
OFFSET_REG_DMA2SAD_H    =   0xca
OFFSET_REG_DMA2DAD      =   0xcc
OFFSET_REG_DMA2DAD_L    =   0xcc
OFFSET_REG_DMA2DAD_H    =   0xce
OFFSET_REG_DMA2CNT      =   0xd0
OFFSET_REG_DMA2CNT_L    =   0xd0
OFFSET_REG_DMA2CNT_H    =   0xd2
OFFSET_REG_DMA3         =   0xd4        @ DMA 3
OFFSET_REG_DMA3SAD      =   0xd4        @ (Game Pak/Internal Memory <--> Internal Memory)
OFFSET_REG_DMA3SAD_L    =   0xd4
OFFSET_REG_DMA3SAD_H    =   0xd6
OFFSET_REG_DMA3DAD      =   0xd8
OFFSET_REG_DMA3DAD_L    =   0xd8
OFFSET_REG_DMA3DAD_H    =   0xda
OFFSET_REG_DMA3CNT      =   0xdc
OFFSET_REG_DMA3CNT_L    =   0xdc
OFFSET_REG_DMA3CNT_H    =   0xde


OFFSET_REG_TM0CNT       =   0x100       @ Timer 0
OFFSET_REG_TM0CNT_L     =   0x100
OFFSET_REG_TM0CNT_H     =   0x102
OFFSET_REG_TM1CNT       =   0x104       @ Timer 1
OFFSET_REG_TM1CNT_L     =   0x104
OFFSET_REG_TM1CNT_H     =   0x106
OFFSET_REG_TM2CNT       =   0x108       @ Timer 2
OFFSET_REG_TM2CNT_L     =   0x108
OFFSET_REG_TM2CNT_H     =   0x10a
OFFSET_REG_TM3CNT       =   0x10c       @ Timer 3
OFFSET_REG_TM3CNT_L     =   0x10c
OFFSET_REG_TM3CNT_H     =   0x10e


OFFSET_REG_RCNT         =   0x134       @ General Input/Output Control

OFFSET_REG_SIOCNT       =   0x128       @ Serial Communication Control
OFFSET_REG_SIODATA8     =   0x12a       @ 8 bit Serial Communication Data
OFFSET_REG_SIODATA32    =   0x120       @ 32 bit Serial Communication Data
OFFSET_REG_SIOMLT_SEND  =   0x12a       @ Multi-play SIO Send Data
OFFSET_REG_SIOMLT_RECV  =   0x120       @ Multi-play SIO Receive Data
OFFSET_REG_SIOMULTI0    =   0x120
OFFSET_REG_SIOMULTI1    =   0x122
OFFSET_REG_SIOMULTI2    =   0x124
OFFSET_REG_SIOMULTI3    =   0x126

OFFSET_REG_JOYCNT       =   0x140       @ JOY Bus Communication Control
OFFSET_REG_JOYSTAT      =   0x158       @ JOY Bus Status
OFFSET_REG_JOY_RECV     =   0x150       @ JOY Bus Receive Data
OFFSET_REG_JOY_RECV_L   =   0x150
OFFSET_REG_JOY_RECV_H   =   0x152
OFFSET_REG_JOY_TRANS    =   0x154       @ JOY Bus Send Data
OFFSET_REG_JOY_TRANS_L  =   0x154
OFFSET_REG_JOY_TRANS_H  =   0x156


OFFSET_REG_KEYINPUT     =   0x130       @ Key Input
OFFSET_REG_KEYCNT       =   0x132       @ Key Control

