@********************************************************************
@*          AgbSyscallDefine.s                                      *
@*            AGB System Call (GAS)                                 *
@*                                                                  *
@*          Copyright (C) 1999-2001 NINTENDO Co.,Ltd.               *
@********************************************************************


@--------------------------------------------------------------------
@-                   System Call No.                                -
@--------------------------------------------------------------------

SWI_NO_RESTART                  =   0       @ SoftReset()
SWI_NO_REGISTER_RAM_RESET       =   1       @ SoftReset()/RegisterRamReset()
SWI_NO_HALT                     =   2       @ Halt()
SWI_NO_STOP                     =   3       @ Stop()

SWI_NO_INTR_WAIT                =   4       @ IntrWait()
SWI_NO_VBLANK_INTR_WAIT         =   5       @ VBlankIntrWait()

SWI_NO_DIV                      =   6       @ Div()/DivRem()
SWI_NO_DIV_ARM                  =   7       @ DivArm()/DivRemArm()
SWI_NO_SQRT                     =   8       @ Sqrt()
SWI_NO_ARCTAN                   =   9       @ ArcTan()
SWI_NO_ARCTAN2                  =   10      @ ArcTan2()

SWI_NO_CPU_SET                  =   11      @ CpuSet()
SWI_NO_CPU_FAST_SET             =   12      @ CpuFastSet()
SWI_NO_BG_AFFINE_SET            =   14      @ BgAffineSet()
SWI_NO_OBJ_AFFINE_SET           =   15      @ ObjAffineSet()
SWI_NO_BIT_UNPACK               =   16      @ BitUnPack()
SWI_NO_LZ77_UNCOMP_WRAM         =   17      @ LZ77UnCompWram()
SWI_NO_LZ77_UNCOMP_VRAM         =   18      @ LZ77UnCompVram()
SWI_NO_HUFF_UNCOMP              =   19      @ HuffUnComp()
SWI_NO_RL_UNCOMP_WRAM           =   20      @ RLUnCompWram()
SWI_NO_RL_UNCOMP_VRAM           =   21      @ RLUnCompVram()
SWI_NO_DIFF_8BIT_UNFILTER_WRAM  =   22      @ Diff8bitUnFilterWram()
SWI_NO_DIFF_8BIT_UNFILTER_VRAM  =   23      @ Diff8bitUnFilterVram()
SWI_NO_DIFF_16BIT_UNFILTER      =   24      @ Diff16bitUnFilter()

SWI_NO_SOUND_BIAS_CHANGE        =   25      @ SoundBiasSet()/SoundBiasReset()
SWI_NO_SOUND_DRIVER_INIT        =   26      @ SoundDriverInit()
SWI_NO_SOUND_DRIVER_MODE        =   27      @ SoundDriverMode()
SWI_NO_SOUND_DRIVER_MAIN        =   28      @ SoundDriverMain()
SWI_NO_SOUND_DRIVER_VSYNC       =   29      @ SoundDriverVSync()
SWI_NO_SOUND_DRIVER_VSYNC_OFF   =   40      @ SoundDriverVSyncOff()
SWI_NO_SOUND_DRIVER_VSYNC_ON    =   41      @ SoundDriverVSyncOn()
SWI_NO_SOUND_CHANNEL_CLEAR      =   30      @ SoundChannelClear()
SWI_NO_MIDI_KEY_2_FREQ          =   31      @ MidiKey2Freq()

SWI_NO_MULTI_BOOT               =   37      @ MultiBoot()


@--------------------------------------------------------------------
@-                   Software Reset                                -
@--------------------------------------------------------------------

    .EXTERN SoftReset

@ * Reset register and RAM specified with ResetFlags. Returns to start 
@   address of Game Pak or CPU External RAM based on value for 
@   SOFT_RESET_DIRECT_BUF(0x03007ffa).
@ * If return to CPU External RAM, do not specifiy RESET_EX_WRAM_FLAG.
@ * If return from download program to Game Pak do not specify 
@   RESET_REG_SIO_FLAG.
@ * CPU core register and CPU internal RAM area from 0x3007e00-0x3007fff
@   is forcibly cleared.
@
@ *Arguments:
@    u32 ResetFlags   Specification of reset register and RAM 
@    (SeeAgbDefine.h)
@ * *(u8 *)SOFT_RESET_DIRECT_BUF  Specify return to
@        0:                 0x08000000 (Game Pak)
@        Not 0:             0x02000000 (CPU Address(CPU External RAM)

@--------------------------------------------------------------------
@-                  Software Reset (Game Pak Return)                -
@--------------------------------------------------------------------

    .EXTERN SoftResetRom

@ * Reset register and RAM specified with ResetFlags. Return to Game 
@   Pak start address(0x08000000).
@ * When return from download program, do not specify RESET_REG_SIO_FLAG 
@   so the Game Pak program can discriminate it from a normal startup.
@ * CPU core register and CPU internal RAM area from 0x3007e00-0x3007fff
@   is forcibly cleared.
@
@ * Arguments:
@    u32 ResetFlags   Specification of reset register and RAM
@                     (See AgbDefine.h)
@--------------------------------------------------------------------
@-                   Software Reset (CPU External RAM Return)       -
@--------------------------------------------------------------------

    .EXTERN SoftResetExram

@ * Reset register and RAM specified with ResetFlags. Return to CPU
@   external RAM start address (0x02000000).
@ * To return to CPU external RAM, RESET_EX_WRAM_FLAG is cleared.
@ * CPU core register and CPU internal RAM area from 0x3007e00-0x3007fff
@   is forcibly cleared.
@
@ * Arguments:
@    u32 ResetFlags  Specification of reset register and RAM 
@                    (See AgbDefine.h)
@--------------------------------------------------------------------
@-               Reset Register & RAM                               -
@--------------------------------------------------------------------

    .EXTERN RegisterRamReset

@ * Reset the register and RAM that were specified by ResetFlags.
@ * However, the area between 0x3007e00~0x3007fff of CPU internal RAM will not be cleared.
@
@ * Arguments:
@    r0:                Specify the register and RAM that are to be 
@                       reset (See AgbDefine.s for reference)

@--------------------------------------------------------------------
@-                   HALT                                           -
@--------------------------------------------------------------------

@   .EXTERN Halt

@ * It halts CPU only.
@ * Applicable interrupt is enabled (set in IE).
@   Return by interrupt request (set in IF).

@--------------------------------------------------------------------
@-                   STOP                                           -
@--------------------------------------------------------------------

    .EXTERN SoundBiasSet
    .EXTERN SoundBiasReset

@   .EXTERN Stop

@ * Stop source oscillation.
@ * When applicable interrupt is enabled (set in IE), return with the 
@   generation of the interrupt request conditions from key, Game Pak, 
@   or SIO.
@ * IF flag will not be set since souce oscillation is stopped.
@ * LCDC must be OFF when executed.

@--------------------------------------------------------------------
@-               Interrupt Wait                                   -
@--------------------------------------------------------------------

    .EXTERN IntrWait

@ * Continue to wait in the Halt status until the interrupt specified 
@   by IntrFlags generates.
@ * Set a flag that corresponds to INTR_CHECK_BUF(0x3007ff8) by interrupt 
@   process.
@ * Overhead that calls for system call can be reduced by using multiple 
@   interrupts simultaneously when compared with the case where Halt() 
@   is called back repeatedly.
@
@ * Arguments:
@    r0:   Specify whether or not to clear when applicable flag has 
@          already been set.
@    r1:   Specify an interrupt that waits. (See AgbDefine.s)

@--------------------------------------------------------------------
@-               V-blank Interrupt Wait                             -
@--------------------------------------------------------------------

    .EXTERN VBlankIntrWait

@ * Continue to wait in Halt status until V-blank interrupt generates.
@ * Set a flag that corresponds to INTR_CHECK_BUF(0x3007ff8) in interrupt 
@   process.
@ * Overhead that calls for system call can be reduced by using 
@   multiple interrupts simultaneously when compared 
@   with the case where the Halt() is called back repeatedly.
@ * It is equivalent to IntrWait(1, V_BLANK_INTR_FLAG).

@--------------------------------------------------------------------
@-                   Signed Division (Quoitient)                           -
@--------------------------------------------------------------------

    .EXTERN Div       @ Compatible with the library by RedHat 
                      @ (Formerly Cygnus)
    .EXTERN DivArm    @ Compatible with the library by ARM
@ * Calculate Number/Denom.
@ * The register value returns by r0=Number/Denom, r1=Number%Denom, 
@  r3=|Number/Denom|.
@
@ * Arguments: (Reversal for the library by ARM)
@    r0:                 Numerator
@    r1:                 Denominator

@--------------------------------------------------------------------
@-                   Signed Division (Remainder)                    -
@--------------------------------------------------------------------

    .EXTERN DivRem              @ Compatible with the library by RedHat 
                                @ (Formerly Cygnus)
    .EXTERN DivRemArm           @ Compatible with the library by ARM
@ * Calculate Number%Denom.
@ * The register value returns by r0=Number%Denom, r1=Number%Denom, 
@  r3=|Number/Denom|.
@
@ * Arguments: (Reversal for the library by ARM)
@    r0:                 Numerator
@    r1:                 Denominator

@--------------------------------------------------------------------
@-                   Square Root                                    -
@--------------------------------------------------------------------

    .EXTERN Sqrt

@ * Calculate square root.
@ * In order to make it accurate, shift argumentX by the multiple of 
@   2 to the left, and shift return value to the right
@   by the multiplied number used in order to match digit.

@--------------------------------------------------------------------
@-                   Arc Tangent                                    -
@--------------------------------------------------------------------

    .EXTERN ArcTan

@ * Calculate arc tangent value.
@ * For return value, return -pi/2 < theta < pi/2 within the range of 
@   0xc000~0x4000.
@ * However, the range theta < -pi/4, pi/4 < theta has a problem with 
@   accuracy.
@
@ * Arguments:
@    r0:
@        Sign: 1
@        Integer part: 1
@        Decimal part: 14

@--------------------------------------------------------------------
@-                   Arc Tangent 2                                  -
@--------------------------------------------------------------------

    .EXTERN ArcTan2

@ * Calculate the arc tangent value after correction process.
@ * Use this for regular purpose.
@ * For return value, return 0 <= theta < 2pi within the range of 
@   0~0xffff.
@
@ * Arguments:
@    r0, r1:
@        Sign: 1
@        Integer part: 1
@        Decimal part: 14

@--------------------------------------------------------------------
@-                   Set CPU                                        -
@--------------------------------------------------------------------

    .EXTERN CpuSet

@ * Clear or copy RAM by using parameter that is compatible with 
@   DmaSet macro.
@ * RAM is forcefully accessed at every 4 byte boundary by 32bit 
@   transfer, and it is to be accessed at every 2 byte boundary by 
@   16bit transfer.
@ 
@
@ * Arguments:
@    r0:                 Source address
@    r1:                 Destination address
@    r2:                 Only DMA_SRC_FIX/DMA_32BIT_BUS/DMA_COUNT_MASK 
@                        are valid
@    DMA_SRC_FIX(  0, 1) = (Source address increment, Fixed source address)
@    DMA_32BIT_BUS(0, 1) = (16bit transfer, 32bit transfer)
@    DMA_COUNT_MASK & DmaCntData = Number of times transferred
@
@ * Upper macro:
@  CpuClear, CpuArrayClear, CpuCopy, CpuArrayCopy

@--------------------------------------------------------------------
@-                   High-speed Set CPU                              -
@--------------------------------------------------------------------

    .EXTERN CpuFastSet

@ * Clear or copy RAM in high speed by using parameter that is 
@   compatible with DmaSet macro.
@ * However, it is a 32bit transfer per 32 bytes (8 words).
@ * Even if an argument other than 4byte boundary is given, it is 
@   accessed forcefully at every 4 byte boundary.
@
@ * Arguments:
@    r0:                 Source address
@    r1:                 Destination address
@    r2:                 Only DMA_SRC_FIX/DMA_COUNT_MASK are valid
@    DMA_SRC_FIX(0, 1) = (Source address increment, Fixed source address)
@    DMA_COUNT_MASK & DmaCntData = Number of times transferred
@
@ * Upper macro:
@  CpuFastClear, CpuFastArrayClear, CpuFastCopy, CpuFastArrayCopy

@--------------------------------------------------------------------
@-                   Set BG Affine Transformation                   -
@--------------------------------------------------------------------

    .EXTERN BgAffineSet

@ * Calculate and set BG affine parameter.
@
@ * Arguments:
@    r0:                       Source address
@    r1:                       Destination address
@    r2:                       Number of times calculated
@
@ * BgAffineSrcData Structure
@    s32 SrcCenterX            Source data center coordinate 
@                              (8bits to the right of decimal point)
@    s32 SrcCenterY
@    s16 DispCenterX           Display center coordinate
@    s16 DispCenterY
@    s16 RatioX                Scaling ratio (8bits to the right of 
@                              decimal point)
@    s16 RatioY
@    u16 Theta                 Rotation angle (8bits to the right of 
@                              decimal point)
@                                  Valid range    0 - 0xffff
@ * BgAffineDestData Structure
@    s16 H_DiffX               Line direction X coordinate difference
@    s16 V_DiffX               Vertical direction X coordinate difference
@    s16 H_DiffY               Line direction Y coordinate difference
@    s16 V_DiffY               Vertical direction Y coordinate difference
@    s32 StartX                Start X coordinate
@    s32 StartY                Start Y coordinate

@--------------------------------------------------------------------
@-                   Set OBJ Affine Transformation                  -
@--------------------------------------------------------------------

    .EXTERN ObjAffineSet

@ * Calculate and set affine parameter of OBJ.
@
@ * Arguments:
@    r0:                       Source address
@    r1:                       Destination address
@    r2:                       Number of times calculated
@    r3:                       Offset byte size of parameter address 
@                              (normally 2|8)
@                              Designate "8" when directly setting to OAM
@
@ * ObjAffineSrcData Structure
@    s16 RatioX                Scaling ratio (8bits to the right of 
@                              decimal point)
@    s16 RatioY
@    u16 Theta                 Rotation angle (8bits to the right of 
@                                                      decimal point)
@                                  Valid range    0 - 0xffff
@ * ObjAffineDestData Structure
@    s16 H_DiffX               Line direction X coordinate difference
@    s16 V_DiffX               Vertical direction X coordinate difference
@    s16 H_DiffY               Line direction Y coordinate difference
@    s16 V_DiffY               Vertical direction Y coordinate difference

@--------------------------------------------------------------------
@-                       Expand Bit Compressed Data                 -
@--------------------------------------------------------------------

    .EXTERN BitUnPack

@ * Expand data filled with bits fixed 0.
@ * Match destination address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@    r2:                     Address of BitUnPackParam structure data
@
@ * BitUnPackParam Structure
@    u16 SrcNum              Source data byte size
@    u8  SrcBitNum           1 source data bit size
@    u8  DestBitNum          1 destination data bit size
@    u32 DestOffset:31       Offset number to add to source data
@        DestOffset0_On:1    Flag for adding/not adding offset to 0 data

@--------------------------------------------------------------------
@-                   LZ77 Compressed Data Expansion (-> Work RAM)   -
@--------------------------------------------------------------------

    .EXTERN LZ77UnCompWram

@ * Expand LZ77 compressed data and write by 8bits.
@ * Cannot expand directly to VRAM.
@ * When compressed data size is not a multiple of 4, fill with 0 to adjust.
@ * Match source address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 :4                  Reserve
@        CompType:4          Compressed type (= 1)
@        DestSize:24         Post-expansion data size
@
@ * Flag data format
@    u8  Flags               Compressed/non-compressed flag
@                            (0, 1) = (Non-compressed data, Compressed data)
@ * Code data format (Big Endian)
@    u16 Length:4            Expansion data length  - 3 (Compress only when matching length is 3 bytes or more)
@        Offset:12           Matching data offset - 1

@--------------------------------------------------------------------
@-                   Expand LZ77 Compressed Data  (->VRAM)           -
@--------------------------------------------------------------------

    .EXTERN LZ77UnCompVram

@ * Expand LZ77 compressed data and write by 16bits.
@ * Can be expanded to work RAM, however, it is slower than LZ77UnCompWram().
@ * Specify the compressed data in which matching character array was retrieved by 2 bytes before.
@ * When compressed data size is not a multiple of 4, fill with 0 to adjust.
@ * Match source address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 :4                  Reserve
@        CompType:4          Compressed type (= 1)
@        DestSize:24         Post-expansion data size
@
@ * Flag data format
@    u8  Flags               Compressed/non-compressed flag
@                            (0, 1) = (Non-compressed data, Compressed data)
@ * Code data format (Big Endian)
@    u16 Length:4            Expansion data length - 3 (Compress only when matching length is 3 bytes or more)
@        Offset:12           Matching data offset ( >= 2) - 1

@--------------------------------------------------------------------
@-                   Expand Huffman Compressed Data                         -
@--------------------------------------------------------------------

    .EXTERN HuffUnComp

@ * Expand Huffman comrpessed data and write by 32 bits.
@ * When compressed data size is not a multiple of 4, fill with 0 to adjust.
@ * Match source address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 BitSize:4           1 data bit size (normally 4|8)
@        CompType:4          Compressed type (= 2)
@        DestSize:24         Post-expansion data size
@
@ * Tree table
@    u8           TreeSize        Tree table size/2 - 1
@    TreeNodeData RootNode        Root node
@
@    TreeNodeData LeftNode        Root left node
@    TreeNodeData RightNode       Root right node
@
@    TreeNodeData LeftleftNode    Left left node
@    TreeNodeData leftRightNode   Left right node
@
@    TreeNodeData RightLeftNode   Right left node
@    TreeNodeData RightRightNode  Right right node
@
@            .
@            .
@
@  Following is the main body of compressed data
@
@ * TreeNodeData Structure
@    u8  NextNodeOffset:6    Offset to the next node data  - 1 (2Byte unit)
@        RightEndFlag:1      Right node end flag 
@        LeftEndFlag:1       Left node end flag
@                            When end flag is set
@                            Data is in the next node

@--------------------------------------------------------------------
@-                   Expand Run Length Compressed Data  (-> Work RAM)   -
@--------------------------------------------------------------------

    .EXTERN RLUnCompWram

@ * Expand run length compressed data and write by 8 bits.
@ * Cannot directly expand to VRAM.
@ * When compressed data size is not a multiple of 4, fill with 0 to adjust.
@ * Match source address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 :4                  Reserve
@        CompType:4          Compressed data  ( = 3)
@        DestSize:24         Post-expansion data size
@
@ * Flag data format
@    u8  Length:7            Expansion data length - 1 (when not compressed)
@                            Expansion data length - 3 (Compress only when continuous length is 3 bytes or more)
@        Flag:1               (0, 1) =  (Non-compressed data, Compressed data)

@--------------------------------------------------------------------
@-                   Expand Run Length Compressed Data (->VRAM)     -
@--------------------------------------------------------------------

    .EXTERN RLUnCompVram

@ * Expand expand run length compressed data and write by 16 bits.
@ * It can expand to work RAM, however, it is slower than RLUnCompWram().
@ * When compressed data size is not a multiple of 4, fill with 0 to adjust.
@ * Match source address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 :4                  Reserve
@        CompType:4          Compressed type (= 3)
@        DestSize:24         Post-expansion data size
@
@ * Flag data format
@    u8  Length:7            Expansion data length - 1 (when not compressed)
@                            Expand data length - 3 (compress only when the consecutive length is 3 bytes or more)
@        Flag:1               (0, 1) =  (Non-compressed data, Compressed data)

@--------------------------------------------------------------------
@-                   Expand Difference Filter (8bits -> Work RAM)   -
@--------------------------------------------------------------------

    .EXTERN Diff8bitUnFilterWram

@ * Expand 8-bit difference filter manipulation data and write by 8 bits.
@ * Cannot expand directly to VRAM.
@ * Match source address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 ByteSize:4          1 data byte size ( = 1)
@        FiltType:4          Filter type ( = 8)
@        DestSize:24         Post-expansion data size
@
@ * Data format
@    u8  Origin              Source data
@    u8  Diff                Difference data
@         .
@         .

@--------------------------------------------------------------------
@-                   Expand Difference Filter  (8 bits -> VRAM)     -
@--------------------------------------------------------------------

    .EXTERN Diff8bitUnFilterVram

@ * Expand 8-bit difference filter manipulation data and write by 16 bits.
@ * Can expand to work RAM, however, it is slower than Diff8bitUnFilterVram().
@ * Match source address to 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 ByteSize:4          1 data byte size ( = 1)
@        FilterType:4        Filter type ( = 8)
@        DestSize:24         Post-expansion data size
@
@ * Data format
@    u8  Origin              Source data
@    u8  Diff                Difference data
@         .
@         .

@--------------------------------------------------------------------
@-                   Expand difference filter  (16 bits)             -
@--------------------------------------------------------------------

    .EXTERN Diff16bitUnFilter

@ * Expand 16-bit difference filter manipulation data and write by 16 bits.
@ * Match source address by 4 byte boundary.
@
@ * Arguments:
@    r0:                     Source address
@    r1:                     Destination address
@
@ * Data header
@    u32 ByteSize:4          1 data byte size ( = 2)
@        FilterType:4        Filter type ( = 8)
@        DestSize:24         Post-expansion data size
@
@ * Data format
@    u16 Origin              Source data
@    u16 Diff                Difference data
@         .
@         .

@--------------------------------------------------------------------
@-              Set Sound BIAS                             -
@--------------------------------------------------------------------

    .EXTERN SoundBiasSet

@ * Move sound BIAS from 0 to intermediate value  (0x200).

@--------------------------------------------------------------------
@-              Reset Sound BIAS                           -
@--------------------------------------------------------------------

    .EXTERN SoundBiasReset

@ * Move sound BIAS from 0 to intermediate value (0x200).

@--------------------------------------------------------------------
@-              Initialize Sound Driver                             -
@--------------------------------------------------------------------

    .EXTERN SoundDriverInit

@  Initialize sound driver.
@  Call just once when game starts.
@  At that time, it is necessary to obtain the work area "sa" beforehand.  Even if the work area is prepared separately,
@  it is not possible to execute the main driver multiple times simultaneously.

@--------------------------------------------------------------------
@-              Sound Driver Move Mode                         -
@--------------------------------------------------------------------

    .EXTERN SoundDriverMode

@  Set move mode of sound driver.
@  
@  | Reverb of direct sound (Initial value 0)
@      mode = SOUND_MODE_REVERB_SET + (Reverb value 0~127);
@  
@  | Simultaneous sound number of direct sound (Initial value 8)
@      mode = (Simultaneous sound number 1~12) << SOUND_MODE_MAXCHN_SHIFT;
@  
@  | Master volume of direct sound (Initial value 15)
@      mode = (Volume 1~15) << SOUND_MODE_MASVOL_SHIFT;
@  
@  | Play frequency of direct sound (Initial value 13379Hz)
@      mode = SOUND_MODE_FREQ_?????;
@             -> a value that is defined in AgbSound.h (12 types)
@  
@  | Bit number of Final D/A converter (Initial value 8bits)
@      mode = SOUND_MODE_DA_BIT_?;
@                            (up) 9~6
@  
@  | Above value can be set simultaneously by conducting OR.

@--------------------------------------------------------------------
@-              Sound Driver Main                             -
@--------------------------------------------------------------------

    .EXTERN SoundDriverMain

@  Main of sound driver.
@  Call every 1/60 second.  The process flow is to call SoundDriverVSync(), which is stated below,
@  immediately after V-blank interrupt, then to call main routine after processing BG adn OBJ.

@--------------------------------------------------------------------
@-              Reset Sound Driver DMA                     -
@--------------------------------------------------------------------

    .EXTERN SoundDriverVSync

@  Very short system call that resets sound DMA.
@  As timing is very severe, call IMMEDIATELY AFTER V-blank interrupt, which is called 
@  every 1/60 second, is in.

@--------------------------------------------------------------------
@-              Clear Sound Channel                           -
@--------------------------------------------------------------------

    .EXTERN SoundChannelClear

@  Clear all the channels of direct sound and stop sound.
@  This function may not operate properly when the library that expands the function of 
@  sound driver is installed.  Do not use if such malfunction occurs.

@--------------------------------------------------------------------
@-                 Stop Sound DMA                             -
@--------------------------------------------------------------------

    .EXTERN SoundDriverVSyncOff

@  When SoundDriverVSync() cannot be called every 1/60 second because V-blank interrupt is 
@  stopped due to the status of the main program, etc., it is necessary to stop sound DMA by
@  using this function.  Otherwise, DMA will not stop even if it goes over the buffer, which will cause
@  terrible noise.

@--------------------------------------------------------------------
@-                 Re-opening of Sound DMA                             -
@--------------------------------------------------------------------

    .EXTERN SoundDriverVSyncOn

@  This is a function that re-opens the sound DMA which is stopped by SoundDriverVSyncOff()
@  described above.  Set it so that V-blank interrupt is entered and SoundDriverVSync() is called 
@  within 2/60 seconds after this function is called.

@--------------------------------------------------------------------
@-               Calculate Interval by MIDI Key                        -
@--------------------------------------------------------------------

    .EXTERN MidiKey2Freq

@  When playing the waveform data "wa" by the interval (MIDI KEY) mk or fine adjustment value fp, 
@  it calculates the value that is assigned to ((SoundArea)sa).vchn[x].fr.


@--------------------------------------------------------------------
@-                   Multi-play boot                             -
@--------------------------------------------------------------------

    .EXTERN MultiBoot

@ * Main process for the server of multi-play boot.
@ * The specified recognition process must be conducted in advance between all the client AGBs.


