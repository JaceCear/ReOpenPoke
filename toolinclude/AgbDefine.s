@********************************************************************
@*          AgbDefine.s                                             *
@*            AGB Standard Constants (GAS)                          *
@*                                                                  *
@*          Copyright (C) 1999-2001 NINTENDO Co.,Ltd.               *
@********************************************************************


@--------------------------------------------------------------------
@-                            Constants                             -
@--------------------------------------------------------------------

ON                      =   1
OFF                     =   0
ENABLE                  =   1
DISABLE                 =   0
TRUE                    =   1
FALSE                   =   0

LCD_WIDTH               =   240         @ Screen Width
LCD_HEIGHT              =   160         @ Screen Height

SYSTEM_CLOCK            =  (16 * 1024 * 1024)   @ System Clock


@--------------------------------------------------------------------
@-                Register & RAM Reset System Call                  -
@--------------------------------------------------------------------

RESET_ALL_FLAG          =   0xFF        @ Reset All

RESET_ALL_REG_FLAG      =   0xe0        @ Reset all registers

RESET_REG_FLAG          =   0x80        @ Reset Register 
                                        @ (Other than stated below)
RESET_REG_SOUND_FLAG    =   0x40        @ Reset Sound Register
RESET_REG_SIO_FLAG      =   0x20        @ Reset SIO Register

RESET_ALL_RAM_FLAG      =   0x1f        @ Clear the entire RAM

RESET_EX_WRAM_FLAG      =   0x01        @ Clear CPU External RAM
RESET_CPU_WRAM_FLAG     =   0x02        @ Clear CPU Internal RAM
RESET_PLTT_FLAG         =   0x04        @ Clear Palette
RESET_VRAM_FLAG         =   0x08        @ Clear VRAM
RESET_OAM_FLAG          =   0x10        @ Clear OAM


@--------------------------------------------------------------------
@-                    BG Screen Data                                -
@--------------------------------------------------------------------

BG_SC_CHAR_NO_MASK      =   0x03ff      @ Character No
BG_SC_FLIP_MASK         =   0x0c00      @ Flip
BG_SC_PLTT_MASK         =   0xf000      @ Color Palette No

BG_SC_CHAR_NO_SHIFT     =   0
BG_SC_FLIP_SHIFT        =   10
BG_SC_PLTT_SHIFT        =   12

BG_SC_H_FLIP            =   0x0400      @ H Flip
BG_SC_V_FLIP            =   0x0800      @ V Flip

@--------------------------------------------------------------------
@-                        Affine Transformation                     -
@--------------------------------------------------------------------

SIN_SHIFT               =   14
AFFINE_DIV_SHIFT        =   8
AFFINE_REG_SHIFT        =   8
AFFINE_CAL_SHIFT        =   SIN_SHIFT + AFFINE_DIV_SHIFT - AFFINE_REG_SHIFT

@--------------------------------------------------------------------
@-                        OAM Data                             -
@--------------------------------------------------------------------

OAM_V_POS_MASK          =   0x000000ff  @ OBJ X Coordinate
OAM_H_POS_MASK          =   0x01ff0000  @ OBJ Y Coordinate
OAM_SHAPE_MASK          =   0x0000c000  @ OBJ Shape
OAM_SIZE_MASK           =   0xc0000000  @ OBJ Size
OAM_OBJ_MODE_MASK       =   0x00000c00  @ OBJ Mode
OAM_AFFINE_MODE_MASK    =   0x00000300  @ Affine Mode
OAM_AFFINE_NO_MASK      =   0x3e000000  @ Affine Parameter No
OAM_FLIP_MASK           =   0x30000000  @ Flip
OAM_CHAR_NO_MASK        =   0x000003ff  @ Character No
OAM_PRIORITY_MASK       =   0x00000c00  @ BG Relative Priority
OAM_PLTT_MASK           =   0x0000f000  @ Color Palette No
OAM_AFFINE_PARAM_MASK   =   0xffff0000  @ Affine Parameter

OAM_V_POS_SHIFT         =   0
OAM_H_POS_SHIFT         =   16
OAM_SHAPE_SHIFT         =   14
OAM_SIZE_SHIFT          =   30
OAM_AFFINE_MODE_SHIFT   =   8
OAM_OBJ_MODE_SHIFT      =   10
OAM_AFFINE_NO_SHIFT     =   25
OAM_FLIP_SHIFT          =   28
OAM_CHAR_NO_SHIFT       =   0
OAM_PRIORITY_SHIFT      =   10
OAM_PLTT_SHIFT          =   12
OAM_AFFINE_PARAM_SHIFT  =   16

OAM_OBJ_ON              =   0x00000000  @ OBJ ON
OAM_OBJ_OFF             =   0x00000200  @ OBJ OFF
OAM_OBJ_NORMAL          =   0x00000000  @ OBJ Normal Mode
OAM_OBJ_BLEND           =   0x00000400  @ OBJ Semi-transparent Mode
OAM_OBJ_WINDOW          =   0x00000800  @ OBJ Window Mode
OAM_AFFINE_NONE         =   0x00000000  @ Affine Invalid Mode
OAM_AFFINE_NORMAL       =   0x00000100  @ Affine Normal Mode
OAM_AFFINE_TWICE        =   0x00000300  @ Affine Double-size Mode
OAM_AFFINE_ERASE        =   0x00000200  @ Affine non-display Mode
OAM_MOS_ON              =   0x00001000  @ Mosaic ON
OAM_MOS_OFF             =   0x00000000  @ Mosaic OFF
OAM_COLOR_16            =   0x00000000  @ Select 16 
OAM_COLOR_256           =   0x00002000  @ Select 256 Color
OAM_H_FLIP              =   0x10000000  @ H Flip
OAM_V_FLIP              =   0x20000000  @ V Flip
OAM_SQUARE              =   0x00000000  @ Square OBJ
OAM_H_RECTANGLE         =   0x00004000  @ Horizontally-oriented rectangle OBJ
OAM_V_RECTANGLE         =   0x00008000  @ Vertically-oriented rectangle OBJ
OAM_SIZE_NO_0           =   0x00000000  @ OBJ size No 0
OAM_SIZE_NO_1           =   0x40000000  @ OBJ size No 1
OAM_SIZE_NO_2           =   0x80000000  @ OBJ size No 2
OAM_SIZE_NO_3           =   0xc0000000  @ OBJ size No 3
OAM_SIZE_8x8            =   0x00000000  @ OBJ 8 x 8 dot
OAM_SIZE_16x16          =   0x40000000  @ OBJ 16 x 16 dot
OAM_SIZE_32x32          =   0x80000000  @ OBJ 32 x 32 dot
OAM_SIZE_64x64          =   0xc0000000  @ OBJ 64 x 64 dot
OAM_SIZE_16x8           =   0x00004000  @ OBJ 16 x 8 dot
OAM_SIZE_32x8           =   0x40004000  @ OBJ 32 x 8 dot
OAM_SIZE_32x16          =   0x80004000  @ OBJ 32 x 16 dot
OAM_SIZE_64x32          =   0xc0004000  @ OBJ 64 x 32 dot
OAM_SIZE_8x16           =   0x00008000  @ OBJ 8 x 16 dot
OAM_SIZE_8x32           =   0x40008000  @ OBJ 8 x 32 dot
OAM_SIZE_16x32          =   0x80008000  @ OBJ 16 x 32 dot
OAM_SIZE_32x64          =   0xc0008000  @ OBJ 32 x 64 dot


@--------------------------------------------------------------------
@-                      Color Palette Data                          -
@--------------------------------------------------------------------

PLTT_RED_MASK           =   0x001f      @ Red
PLTT_GREEN_MASK         =   0x03e0      @ Green
PLTT_BLUE_MASK          =   0x7c00      @ Blue

PLTT_RED_SHIFT          =   0
PLTT_GREEN_SHIFT        =   5
PLTT_BLUE_SHIFT         =   10


@********************************************************************
@*             AGB Register Control Bit                             *
@********************************************************************

@--------------------------------------------------------------------
@-                  Program Status Register                         -
@--------------------------------------------------------------------

PSR_CPU_MODE_MASK       =   0x1f        @ CPU Mode

PSR_USER_MODE           =   0x10        @ User
PSR_FIQ_MODE            =   0x11        @ FIQ
PSR_IRQ_MODE            =   0x12        @ IRQ
PSR_SVC_MODE            =   0x13        @ Supervisor
PSR_ABORT_MODE          =   0x17        @ Abort (Prefetch/Data)
PSR_UNDEF_MODE          =   0x1b        @ Undefined Command
PSR_SYS_MODE            =   0x1f        @ System

PSR_THUMB_STATE         =   0x20        @ THUMB State
PSR_FIQ_DISABLE         =   0x40        @ FIQ Disable
PSR_IRQ_DISABLE         =   0x80        @ IRQ Disable
PSR_IRQ_FIQ_DISABLE     =   0xc0        @ IRQ & FIQ Disable

PSR_V_FLAG              =   0x10000000  @ Overflow
PSR_C_FLAG              =   0x20000000  @ Carry/Borrow/Expand
PSR_Z_FLAG              =   0x40000000  @ Zero
PSR_N_FLAG              =   0x80000000  @ Negative/Less than


@--------------------------------------------------------------------
@-                  Interrupt Request/Enable Flag                   -
@--------------------------------------------------------------------

V_BLANK_INTR_FLAG       =   0x0001      @ V Blank Interrupt
H_BLANK_INTR_FLAG       =   0x0002      @ H Blank Interrupt
V_COUNT_INTR_FLAG       =   0x0004      @ V Counter Corresponding Interrupt
TIMER0_INTR_FLAG        =   0x0008      @ Timer 0 Interrupt
TIMER1_INTR_FLAG        =   0x0010      @ Timer 1 Interrupt
TIMER2_INTR_FLAG        =   0x0020      @ Timer 2 Interrupt
TIMER3_INTR_FLAG        =   0x0040      @ Timer 3 Interrupt
SIO_INTR_FLAG           =   0x0080      @ Serial Communication Interrupt
DMA0_INTR_FLAG          =   0x0100      @ DMA 0 Interrupt
DMA1_INTR_FLAG          =   0x0200      @ DMA 1 Interrupt
DMA2_INTR_FLAG          =   0x0400      @ DMA 2 Interrupt
DMA3_INTR_FLAG          =   0x0800      @ DMA 3 Interrupt
KEY_INTR_FLAG           =   0x1000      @ Key Interrupt
CASSETTE_INTR_FLAG      =   0x2000      @ Game Pak Interrupt


@--------------------------------------------------------------------
@-                      Display Control                             -
@--------------------------------------------------------------------

DISP_BG_MODE_MASK       =   0x0007      @ BG Mode
DISP_ON_MASK            =   0x1f00      @ OBJ, BG ON
DISP_WIN_MASK           =   0x6000      @ Window ON

DISP_BG_MODE_SHIFT      =   0
DISP_ON_SHIFT           =   8
DISP_WIN_SHIFT          =   13

DISP_MODE_0             =   0x0000      @ BG Mode 0
DISP_MODE_1             =   0x0001      @ BG Mode 1
DISP_MODE_2             =   0x0002      @ BG Mode 2
DISP_MODE_3             =   0x0003      @ BG Mode 3
DISP_MODE_4             =   0x0004      @ BG Mode 4
DISP_MODE_5             =   0x0005      @ BG Mode 5
DISP_BMP_FRAME_NO       =   0x0010      @ Bitmap Mode Display Frame
DISP_OBJ_HOFF           =   0x0020      @ OBJ Processing in H Blank OFF
DISP_OBJ_CHAR_2D_MAP    =   0x0000      @ OBJ Character Data 2D Mapping
DISP_OBJ_CHAR_1D_MAP    =   0x0040      @ OBJ Character Data 1D Mapping
DISP_LCDC_OFF           =   0x0080      @ LCDC OFF
DISP_BG0_ON             =   0x0100      @ BG0 ON
DISP_BG1_ON             =   0x0200      @ BG1 ON
DISP_BG2_ON             =   0x0400      @ BG2 ON
DISP_BG3_ON             =   0x0800      @ BG3 ON
DISP_BG_ALL_ON          =   0x0f00      @ All BG ON
DISP_OBJ_ON             =   0x1000      @ OBJ ON
DISP_OBJ_BG_ALL_ON      =   0x1f00      @ All OBJ, BG ON
DISP_WIN0_ON            =   0x2000      @ Window 0 ON
DISP_WIN1_ON            =   0x4000      @ Window 1 ON
DISP_WIN01_ON           =   0x6000      @ Window 0, 1 ON
DISP_OBJWIN_ON          =   0x8000      @ OBJ Window ON
DISP_WIN_ALL_ON         =   0xe000      @ All Window ON
DISP_ALL_ON             =   0x7f00      @ All ON

@--------------------------------------------------------------------
@-                      Status Control                              -
@--------------------------------------------------------------------

STAT_VCOUNT_CMP_MASK    =   0xff00      @ V Counter Comparison Value

STAT_VCOUNT_CMP_SHIFT   =   8

STAT_V_BLANK            =   0x0001      @ During V Blank
STAT_H_BLANK            =   0x0002      @ During H Blank
STAT_V_COUNT            =   0x0004      @ Matching V Counter
STAT_V_BLANK_IF_ENABLE  =   0x0008      @ V Blank Interrupt Request Enable
STAT_H_BLANK_IF_ENABLE  =   0x0010      @ H Blank Interrupt Request Enable
STAT_V_COUNT_IF_ENABLE  =   0x0020      @ V Counter Matching Interrupt 
                                        @ Request Enable

@--------------------------------------------------------------------
@-                      BG Control                                  -
@--------------------------------------------------------------------

BG_PRIORITY_MASK        =   0x0003      @ BG Priority
BG_CHAR_BASE_MASK       =   0x000c      @ Character Base Address
BG_SCREEN_BASE_MASK     =   0x1f00      @ Screen Base Address
BG_SCREEN_SIZE_MASK     =   0xc000      @ Screen Size (256/512)

BG_PRIORITY_SHIFT       =   0
BG_CHAR_BASE_SHIFT      =   2
BG_SCREEN_BASE_SHIFT    =   8
BG_SCREEN_SIZE_SHIFT    =   14

BG_PRIORITY_0           =   0x0000      @ BG 0 Priority
BG_PRIORITY_1           =   0x0001      @ BG 1st Priority
BG_PRIORITY_2           =   0x0002      @ BG 2nd Priority
BG_PRIORITY_3           =   0x0003      @ BG 3rd Priority
BG_MOS_ON               =   0x0040      @ Mosaic ON
BG_MOS_OFF              =   0x0000      @ Mosaic OFF
BG_COLOR_16             =   0x0000      @ Select 16 colors
BG_COLOR_256            =   0x0080      @ Select 256 colors
BG_LOOP_ON              =   0x2000      @ Loop ON
BG_LOOP_OFF             =   0x0000      @ Loop OFF
BG_SCREEN_SIZE_0        =   0x0000      @ Screen Size (256x256)
BG_SCREEN_SIZE_1        =   0x4000      @ Screen Size (512x256)
BG_SCREEN_SIZE_2        =   0x8000      @ Screen Size (256x512)
BG_SCREEN_SIZE_3        =   0xc000      @ Screen Size (512x512)

@--------------------------------------------------------------------
@-                      Window Control                              -
@--------------------------------------------------------------------

WIN_END_POS_MASK        =   0x00ff      @ Window End Position
WIN_START_POS_MASK      =   0xff00      @ Window Start Position

WIN_END_POS_SHIFT       =   0
WIN_START_POS_SHIFT     =   8

WIN_BG0_ON              =   0x0001      @ BG0 ON
WIN_BG1_ON              =   0x0002      @ BG1 ON
WIN_BG2_ON              =   0x0004      @ BG2 ON
WIN_BG3_ON              =   0x0008      @ BG3 ON
WIN_OBJ_ON              =   0x0010      @ OBJ ON
WIN_BLEND_ON            =   0x0020      @ Blend ON
WIN_ALL_ON              =   0x003f      @ All ON

@--------------------------------------------------------------------
@-                      Mosaic Control                              -
@--------------------------------------------------------------------

MOS_H_SIZE_MASK         =   0x000f      @ Mosaic Height
MOS_V_SIZE_MASK         =   0x00f0      @ Mosaic Width
MOS_BG_H_SIZE_MASK      =   0x000f      @ BG Mosaic Height
MOS_BG_V_SIZE_MASK      =   0x00f0      @ BG Mosaic Width
MOS_OBJ_H_SIZE_MASK     =   0x000f      @ OBJ Mosaic Height
MOS_OBJ_V_SIZE_MASK     =   0x00f0      @ OBJ Mosaic Width

MOS_H_SIZE_SHIFT        =   0
MOS_V_SIZE_SHIFT        =   4
MOS_BG_H_SIZE_SHIFT     =   0
MOS_BG_V_SIZE_SHIFT     =   4
MOS_OBJ_H_SIZE_SHIFT    =   8
MOS_OBJ_V_SIZE_SHIFT    =   12

@--------------------------------------------------------------------
@-                      Blend Control                               -
@--------------------------------------------------------------------

BLD_PIXEL_MASK          =   0x003f      @ Select Pixel
BLD_1ST_PIXEL_MASK      =   0x003f      @ Select 1st Pixel
BLD_MODE_MASK           =   0x00c0      @ Blend Mode
BLD_2ND_PIXEL_MASK      =   0x3f00      @ Select 2nd Pixel

BLD_1ST_PIXEL_SHIFT     =   0
BLD_MODE_SHIFT          =   6
BLD_2ND_PIXEL_SHIFT     =   8

BLD_BG0                 =   0x0001      @ Select BG 0 Pixel
BLD_BG1                 =   0x0002      @ Select BG 1 Pixel
BLD_BG2                 =   0x0004      @ Select BG 2 Pixel
BLD_BG3                 =   0x0008      @ Select BG 3 Pixel
BLD_OBJ                 =   0x0010      @ Select OBJ Pixel
BLD_BD                  =   0x0020      @ Select Background Color Pixel
BLD_ALL                 =   0x003f      @ Select All Pixel
BLD_BG0_1ST             =   0x0001      @ Select BG 0 1st Pixel
BLD_BG1_1ST             =   0x0002      @ Select BG 1 1st Pixel
BLD_BG2_1ST             =   0x0004      @ Select BG 2 1st Pixel
BLD_BG3_1ST             =   0x0008      @ Select BG 3 1st Pixel
BLD_OBJ_1ST             =   0x0010      @ Select OBJ 1st Pixel
BLD_BD_1ST              =   0x0020      @ Select Background Color 1st Pixel
BLD_1ST_ALL             =   0x003f      @ Select All 1st Pixel
BLD_NORMAL_MODE         =   0x0000      @ Normal Mode
BLD_A_BLEND_MODE        =   0x0040      @ Semi-transparent Mode
BLD_UP_MODE             =   0x0080      @ Brightness UP Mode
BLD_DOWN_MODE           =   0x00c0      @ Brightness DOWN Mode
BLD_BG0_2ND             =   0x0100      @ Select BG 0 2nd Pixel
BLD_BG1_2ND             =   0x0200      @ Select BG 1 2nd Pixel
BLD_BG2_2ND             =   0x0400      @ Select BG 2 2nd Pixel
BLD_BG3_2ND             =   0x0800      @ Select BG 3 2nd Pixel
BLD_OBJ_2ND             =   0x1000      @ Select OBJ 2nd Pixel
BLD_BD_2ND              =   0x2000      @ Select Background Color 2nd Pixel
BLD_2ND_ALL             =   0x3f00      @ Select All 2nd Pixel


BLD_A_MASK              =   0x001f      @ Blend Variable A
BLD_B_MASK              =   0x1f00      @ Blend Variable B
BLD_Y_MASK              =   0x001f      @ Blend Variable Y

BLD_A_SHIFT             =   16
BLD_B_SHIFT             =   24
BLD_Y_SHIFT             =   0


@--------------------------------------------------------------------
@-                     Sound Control                                -
@--------------------------------------------------------------------

SOUND_SO1_LEVEL_MASK    =   0x03        @ S01 Output Level
SOUND_SO2_LEVEL_MASK    =   0x30        @ S02 Output Level
SOUND_DMG_SO1_ON_MASK   =   0x0f        @ DMG Compatible Sound ->S01 ON
SOUND_DMG_SO2_ON_MASK   =   0xf0        @ DMG Compatible Sound ->S02 ON

SOUND_SWEEP_SHIFT_MASK  =   0x03        @ Sweep Shift Number
SOUND_SWEEP_TIME_MASK   =   0x30        @ Sweep Time
SOUND_COUNTS_MASK       =   0x3f        @ Sound Length (Count Number)
SOUND_DUTY_MASK         =   0xc0        @ Waveform Duty
SOUND_ENV_STEPS_MASK    =   0x03        @ Envelope Step Number
SOUND_ENV_INIT_MASK     =   0xf0        @ Envelope Initial-value
SOUND_FREQUENCY_MASK    =   0x03ff      @ Frequency
SOUND_FREQUENCY_L_MASK  =   0xff
SOUND_FREQUENCY_H_MASK  =   0x03

SOUND_3_COUNTS_MASK     =   0xff        @ Sound 3  Sound Length (Count Number)
SOUND_3_LEVEL_MASK      =   0xe0        @            Output Level

SOUND_4_PRESCALER_MASK  =   0x03        @ Sound 4 Prescaler Select
SOUND_4_POLYSHIFT_MASK  =   0xf0        @       Polynomical Counter Shift Number


SOUND_SO1_LEVEL_SHIFT   =   0
SOUND_SO2_LEVEL_SHIFT   =   4
SOUND_DMG_SO1_ON_SHIFT  =   0
SOUND_DMG_SO2_ON_SHIFT  =   4

SOUND_SWEEP_SHIFT_SHIFT =   0
SOUND_SWEEP_TIME_SHIFT  =   4
SOUND_COUNTS_SHIFT      =   0
SOUND_DUTY_SHIFT        =   6
SOUND_ENV_STEPS_SHIFT   =   0
SOUND_ENV_INIT_SHIFT    =   4
SOUND_FREQUENCY_SHIFT   =   0
SOUND_FREQUENCY_L_SHIFT =   0
SOUND_FREQUENCY_H_SHIFT =   8

SOUND_3_COUNTS_SHIFT    =   0
SOUND_3_LEVEL_SHIFT     =   5

SOUND_4_PRESCALER_SHIFT =   0
SOUND_4_POLYSHIFT_SHIFT =   4


SOUND_1_ON              =   0x01        @ Sound 1 ON
SOUND_2_ON              =   0x02        @ Sound 2 ON
SOUND_3_ON              =   0x04        @ Sound 3 ON
SOUND_4_ON              =   0x08        @ Sound 4 ON
SOUND_DMG_ON            =   0x80        @ DMG Compatible Sound ON

SOUND_1_SO1_ON          =   0x01        @ Sound 1 -> S01 ON
SOUND_2_SO1_ON          =   0x02        @ Sound 2 -> S01 ON
SOUND_3_SO1_ON          =   0x04        @ Sound 3 -> S01 ON
SOUND_4_SO1_ON          =   0x08        @ Sound 4 -> S01 ON
SOUND_1_SO2_ON          =   0x10        @ Sound 1 -> S02 ON
SOUND_2_SO2_ON          =   0x20        @ Sound 2 -> S02 ON
SOUND_3_SO2_ON          =   0x40        @ Sound 3 -> S02 ON
SOUND_4_SO2_ON          =   0x80        @ Sound 4 -> S02 ON
SOUND_DMG_ALL_SO1_ON    =   0x0f        @ DMG Compatible Sound -> S01 ON
SOUND_DMG_ALL_SO2_ON    =   0xf0        @ DMG Compatible Sound -> S02 ON
SOUND_DMG_ALL_SO_ON     =   0xff        @ DMG Compatible Sound -> S01/2 ON
SOUND_VIN_SO1_ON        =   0x80        @ Vin -> S01 ON
SOUND_VIN_SO2_ON        =   0x08        @ Vin -> S02 ON
SOUND_VIN_SO_ON         =   0x08        @ Vin -> S01/2 ON

SOUND_A_SO1_ON          =   0x01        @ Direct Sound A -> S01 ON
SOUND_A_SO2_ON          =   0x02        @ Direct Sound A -> S02 ON
SOUND_B_SO1_ON          =   0x10        @ Direct Sound B -> S01 ON
SOUND_B_SO2_ON          =   0x20        @ Direct Sound B -> S02 ON
SOUND_A_ALL_SO_ON       =   0x03        @ Direct Sound A -> S01/2 ON
SOUND_B_ALL_SO_ON       =   0x30        @ Direct Sound B -> S01/2 ON
SOUND_DIRECT_ALL_SO1_ON =   0x11        @ Direct Sound A/B -> S01 ON
SOUND_DIRECT_ALL_SO2_ON =   0x22        @ Direct Sound A/B -> S02 ON
SOUND_DIRECT_ALL_SO_ON  =   0x33        @ Direct Sound A/B -> S01/2 ON
SOUND_A_TIMER_0         =   0x00        @ Timer 0 -> Direct Sound A
SOUND_A_TIMER_1         =   0x04        @ Timer 1 -> Direct Sound A
SOUND_B_TIMER_0         =   0x00        @ Timer 0 -> Direct Sound B
SOUND_B_TIMER_1         =   0x40        @ Timer 1 -> Direct Sound B
SOUND_A_FIFO_RESET      =   0x08        @ Reset Direct Sound A FIFO
SOUND_B_FIFO_RESET      =   0x80        @ Reset Direct Sound B FIFO

SOUND_DMG_MIX_1_4       =   0x00        @ DMG Compatible Sound Mix Ratio 1/4
SOUND_DMG_MIX_2_4       =   0x01        @                           2/4
SOUND_DMG_MIX_FULL      =   0x02        @                            Full Range
SOUND_A_MIX_1_2         =   0x00        @ Direct Sound A Mix Ratio 1/2
SOUND_A_MIX_FULL        =   0x04        @                            Full Range
SOUND_B_MIX_1_2         =   0x00        @ Direct Sound B Mix Ratio 1/2
SOUND_B_MIX_FULL        =   0x08        @                            Full Range
SOUND_ALL_MIX_FULL      =   0x0e        @ All Sound Mix Ratio Full Range


SOUND_INIT_ON           =   0x80        @ Initialize ON
SOUND_INIT_OFF          =   0x00        @ Initialize ON
SOUND_COUNTER_ON        =   0x40        @ Counter ON
SOUND_COUNTER_OFF       =   0x00        @ Counter OFF

SOUND_SWEEP_UP          =   0x00        @ Sweep Addition
SOUND_SWEEP_DOWN        =   0x08        @          Subtraction
SOUND_DUTY_1_8          =   0x00        @ Waveform Duty 1/8
SOUND_DUTY_2_8          =   0x40        @                  2/8
SOUND_DUTY_4_8          =   0x80        @                  4/8
SOUND_DUTY_6_8          =   0xc0        @                  6/8
SOUND_ENV_UP            =   0x08        @ Envelope UP
SOUND_ENV_DOWN          =   0x00        @              DOWN

SOUND_3_LOCAL_ON        =   0x80        @ Sound 3 ON
SOUND_3_WAVE_BANK_0     =   0x00        @ Sound 3 Waveform RAM Bank 0
SOUND_3_WAVE_BANK_1     =   0x40        @                       Bank 1
SOUND_3_WAVE_CONNECT    =   0x20        @ Sound 3 Waveform RAM Connect
SOUND_3_WAVE_DISCONNECT =   0x00        @                       Disconnect
SOUND_3_LEVEL_0_4       =   0x00        @ Sound 3 Output None
SOUND_3_LEVEL_FULL      =   0x20        @                 4/4
SOUND_3_LEVEL_2_4       =   0x40        @                 2/4
SOUND_3_LEVEL_1_4       =   0x60        @                 1/4
SOUND_3_LEVEL_3_4       =   0x80        @                 3/4

SOUND_4_POLYSTEP_15     =   0x00        @ Sound 4 Polynomical Counter 15 step
SOUND_4_POLYSTEP_7      =   0x08        @                              7 step


@--------------------------------------------------------------------
@-                      SIO Control                                 -
@--------------------------------------------------------------------

SIO_MODE_MASK           =   0x3000      @ Communication mode
SIO_BAUD_RATE_MASK      =   0x0003      @ Baud rate
SIO_ID_NO_MASK          =   0x0030      @ Communication ID

SIO_MODE_SHIFT          =   12
SIO_BAUD_RATE_SHIFT     =   0
SIO_ID_NO_SHIFT         =   4

SIO_8BIT_MODE           =   0x0000      @ Normal 8-bit communication mode
SIO_32BIT_MODE          =   0x1000      @ Normal 32-bit communication mode
SIO_MULTI_MODE          =   0x2000      @ Multi-play communication mode
SIO_UART_MODE           =   0x3000      @ UART communication mode

SIO_SCK_OUT             =   0x0000      @ Select external clock
SIO_SCK_IN              =   0x0001      @ Select internal clock
SIO_IN_SCK_256K         =   0x0000      @ Select internal clock 256KHz
SIO_IN_SCK_2M           =   0x0002      @                  Select 2MHz
SIO_ACK_RECV            =   0x0004      @ Request transfer
SIO_ACK_SEND            =   0x0008      @ Enable transfer
SIO_9600_BPS            =   0x0000      @ Baud rate 9600 bps
SIO_38400_BPS           =   0x0001      @          68400 bps
SIO_57600_BPS           =   0x0002      @          57600 bps
SIO_115200_BPS          =   0x0003      @        115200 bps
SIO_MULTI_CONNECT       =   0x0004      @ Multi-play communication connecting
SIO_MULTI_DISCONNECT    =   0x0000      @                  Disconnect
SIO_MULTI_PARENT        =   0x0008      @ Multi-play communication  Connect master
SIO_MULTI_CHILD         =   0x0000      @                  Connect slave
SIO_MULTI_SI            =   0x0004      @ Multi-play communication SI terminal
SIO_MULTI_SD            =   0x0008      @                  SD terminal
SIO_MULTI_BUSY          =   0x0080      @ Multi-play communicating
SIO_CTS_ENABLE          =   0x0004      @ Enable UART send enable signal
SIO_UART_7BIT           =   0x0000      @ UART communication data length 7 bit
SIO_UART_8BIT           =   0x0080      @                       8 bit
SIO_ERROR               =   0x0040      @ Detect error
SIO_START               =   0x0080      @ Start transfer
SIO_ENABLE              =   0x0080      @ Enable SIO
SIO_FIFO_ENABLE         =   0x0100      @ Enable FIFO
SIO_PARITY_ENABLE       =   0x0200      @ Enable parity
SIO_PARITY_EVEN         =   0x0000      @ Even parity
SIO_PARITY_ODD          =   0x0008      @ Odd parity
SIO_TRANS_ENABLE        =   0x0400      @ Enable transmitter
SIO_TRANS_DATA_FULL     =   0x0010      @ Transmitted data full
SIO_RECV_ENABLE         =   0x0800      @ Enable receiver
SIO_RECV_DATA_EMPTY     =   0x0020      @ No data received
SIO_IF_ENABLE           =   0x4000      @ Enable interrupt request

@--------------------------------------------------------------------
@-                      Joy Bus Control                             -
@--------------------------------------------------------------------

JOY_IF_RESET            =   0x01        @ Interrupt request of JOY bus reset
JOY_IF_RECV             =   0x02        @ Interrupt request of JOY bus receive completed
JOY_IF_SEND             =   0x04        @ Interrupt request of JOY bus send completed
JOY_IF_ENABLE           =   0x40        @ Enable interrupt request

@--------------------------------------------------------------------
@-                      JOY Bus Status                              -
@--------------------------------------------------------------------

JSTAT_FLAGS_MASK        =   0x30        @ General flag

JSTAT_FLAGS_SHIFT       =   4

JSTAT_RECV              =   0x02        @ Received status
JSTAT_SEND              =   0x08        @ Sent status

@--------------------------------------------------------------------
@-                      General Input/Output Control                -
@--------------------------------------------------------------------

R_SIO_MODE_MASTER_MASK  =   0xc000      @ SIO mode master

R_SIO_MODE_MASTER_SHIFT =   14

R_SIO_MASTER_MODE       =   0x0000      @ SIO master mode
R_DIRECT_MODE           =   0x8000      @ General input/output communication mode
R_JOY_MODE              =   0xc000      @ JOY communication mode

R_SC                    =   0x0001      @ data
R_SD                    =   0x0002
R_SI                    =   0x0004
R_SO                    =   0x0008
R_SC_I_O                =   0x0010      @ Select I/O
R_SD_I_O                =   0x0020
R_SI_I_O                =   0x0040
R_SO_I_O                =   0x0080
R_SC_IN                 =   0x0000      @ Input setting
R_SD_IN                 =   0x0000
R_SI_IN                 =   0x0000
R_SO_IN                 =   0x0000
R_SC_OUT                =   0x0010      @ Output setting
R_SD_OUT                =   0x0020
R_SI_OUT                =   0x0040
R_SO_OUT                =   0x0080
R_IF_ENABLE             =   0x0100      @ Enable interrupt request


@--------------------------------------------------------------------
@-                      DMA Control                                 -
@--------------------------------------------------------------------

DMA_TIMMING_MASK        =   0x30000000  @ Start Timing
DMA_COUNT_MASK          =   0x0000ffff  @ Transfer Number

DMA_TIMMING_SHIFT       =   30
DMA_COUNT_SHIFT         =   0

DMA_ENABLE              =   0x80000000  @ DMA Enable
DMA_IF_ENABLE           =   0x40000000  @ Interrupt Request Enable
DMA_TIMMING_IMM         =   0x00000000  @ Run Immediately
DMA_TIMMING_V_BLANK     =   0x10000000  @ Run V Blank
DMA_TIMMING_H_BLANK     =   0x20000000  @ Run H Blank
DMA_TIMMING_DISP        =   0x30000000  @ Run Display
DMA_TIMMING_SOUND       =   0x30000000  @ Run Sound FIFO Request
DMA_DREQ_ON             =   0x08000000  @ Data Request Synchronize Mode ON
DMA_16BIT_BUS           =   0x00000000  @ Select Bus Size 16Bit
DMA_32BIT_BUS           =   0x04000000  @ Select Bus Size 32Bit
DMA_CONTINUOUS_ON       =   0x02000000  @ Continuous Mode ON
DMA_SRC_INC             =   0x00000000  @ Select Source Increment
DMA_SRC_DEC             =   0x00800000  @ Select Source Decrement
DMA_SRC_FIX             =   0x01000000  @ Select Source Fixed
DMA_DEST_INC            =   0x00000000  @ Select Destination Increment
DMA_DEST_DEC            =   0x00200000  @ Select Source Decrement
DMA_DEST_FIX            =   0x00400000  @ Select Source Fixed
DMA_DEST_RELOAD         =   0x00600000  @ Select Source Increment/Reload

@--------------------------------------------------------------------
@-                      Timer Control                               -
@--------------------------------------------------------------------

TMR_PRESCALER_MASK      =   0x00030000  @ Prescaler Clock

TMR_PRESCALER_SHIFT     =   16

TMR_PRESCALER_1CK       =   0x00000000  @ Prescaler 1 Clock
TMR_PRESCALER_64CK      =   0x00010000  @           64 Clocks
TMR_PRESCALER_256CK     =   0x00020000  @         256 Clocks
TMR_PRESCALER_1024CK    =   0x00030000  @       1024 Clocks
TMR_IF_ENABLE           =   0x00400000  @ Interrupt Request Enable
TMR_ENABLE              =   0x00800000  @ Run Timer


@--------------------------------------------------------------------
@-                          Key                                     -
@--------------------------------------------------------------------

BUTTON_MASK             =   0x030f      @ Button
PLUS_KEY_MASK           =   0x00f0      @ +Control Pad
ALL_KEY_MASK            =   0x03ff      @ All Keys

A_BUTTON                =   0x0001      @ A Button
B_BUTTON                =   0x0002      @ B Button
SELECT_BUTTON           =   0x0004      @ SELECT
START_BUTTON            =   0x0008      @ START
R_KEY                   =   0x0010      @ Right Button
L_KEY                   =   0x0020      @ Left Button
U_KEY                   =   0x0040      @ Up Button
D_KEY                   =   0x0080      @ Down Button
R_BUTTON                =   0x0100      @ R Button
L_BUTTON                =   0x0200      @ L Button
KEY_IF_ENABLE           =   0x4000      @ Interrupt Request Enable
KEY_OR_INTR             =   0x0000      @ Normal Key Interrupt
KEY_AND_INTR            =   0x8000      @ AND Key Interrupt


@--------------------------------------------------------------------
@-                  Game Pak Wait Control                           -
@--------------------------------------------------------------------

CST_SRAM_4WAIT          =   0x0000      @ SRAM 4 Wait
CST_SRAM_3WAIT          =   0x0001      @          3 Wait
CST_SRAM_2WAIT          =   0x0002      @          2 Wait
CST_SRAM_8WAIT          =   0x0003      @          8 Wait
CST_ROM0_1ST_4WAIT      =   0x0000      @ ROM 0 1st 4 Wait
CST_ROM0_1ST_3WAIT      =   0x0004      @            3 Wait
CST_ROM0_1ST_2WAIT      =   0x0008      @            2 Wait
CST_ROM0_1ST_8WAIT      =   0x000c      @            8 Wait
CST_ROM0_2ND_2WAIT      =   0x0000      @       2nd 2 Wait
CST_ROM0_2ND_1WAIT      =   0x0010      @            1 Wait
CST_ROM1_1ST_4WAIT      =   0x0000      @ ROM 1 1st 4 Wait
CST_ROM1_1ST_3WAIT      =   0x0020      @             3 Wait
CST_ROM1_1ST_2WAIT      =   0x0040      @             2 Wait
CST_ROM1_1ST_8WAIT      =   0x0060      @             8 Wait
CST_ROM1_2ND_4WAIT      =   0x0000      @       2nd 4 Wait
CST_ROM1_2ND_1WAIT      =   0x0080      @            1 Wait
CST_ROM2_1ST_4WAIT      =   0x0000      @ ROM 2 1st 4 Wait
CST_ROM2_1ST_3WAIT      =   0x0100      @             3 Wait
CST_ROM2_1ST_2WAIT      =   0x0200      @             2 Wait
CST_ROM2_1ST_8WAIT      =   0x0300      @             8 Wait
CST_ROM2_2ND_8WAIT      =   0x0000      @       2nd 8 Wait
CST_ROM2_2ND_1WAIT      =   0x0400      @              1 Wait

CST_PHI_OUT_NONE        =   0x0000      @ Phi Terminal Output Clock Lo Fixed
CST_PHI_OUT_4MCK        =   0x0800      @                4MHz
CST_PHI_OUT_8MCK        =   0x1000      @                8MHz
CST_PHI_OUT_16MCK       =   0x1800      @              16 MHz
CST_PREFETCH_ENABLE     =   0x4000      @ Prefetch Buffer Enable
CST_AGB                 =   0x0000      @ AGB Game Pak
CST_CGB                 =   0x8000      @ CGB Game Pak


