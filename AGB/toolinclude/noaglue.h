	//#define DmaArrayCopy(DmaNo, Srcp, Destp, Bit)   CpuFastArrayCopy(Srcp, Destp)
//#define DmaCopy(DmaNo, Srcp, Destp, Size, Bit)  CpuFastCopy(Srcp, Destp, Size)
//#define DmaArrayClear(DmaNo, Data, Destp, Bit)  CpuFastArrayClear(Data, Destp)
//#define DmaClear(DmaNo, Data, Destp, Size, Bit) CpuFastClear(Data, Destp, Size)
#define DmaCopy(Srcp, Destp, Size)		dma3_cpy((void*)(Destp), (void*)(Srcp), Size)
#define DmaClear(Data, Destp, Size)		dma3_fill((void*)(Destp), Data, Size)
#define DmaArrayCopy(Srcp, Destp)			dma3_cpy((void*)(Destp), (void*)(Srcp), sizeof(Srcp))
#define DmaArrayClear(Data, Destp)		dma3_fill((void*)(Destp), Data, sizeof(Destp))

//---------------//

#define CpuFastClear(Data, Destp, Size)                     \
{                                                           \
    vu32 Tmp = (vu32 )(Data);                               \
    CpuFastSet((u8 *)&(Tmp), (u8 *)(Destp), (               \
        DMA_SRC_FIX        | ((Size)/(32/8) & 0x1fffff)));  \
}
#define CpuFastArrayClear(Data, Destp)                      \
        CpuFastClear(     Data, Destp, sizeof(Destp))

#define CpuFastCopy(Srcp, Destp, Size)                      \
                                                            \
    CpuFastSet((u8 *)(Srcp), (u8 *)(Destp),  (              \
        DMA_SRC_INC           | ((Size)/(32/8) & 0x1fffff)))

#define CpuFastArrayCopy(Srcp, Destp)                       \
        CpuFastCopy(     Srcp, Destp, sizeof(Srcp))

#define CpuClear(Data, Destp, Size)                    \
{                                                           \
    vu32 Tmp = (vu32 )(Data);                         \
    CpuSet((u8 *)&(Tmp), (u8 *)(Destp), (                   \
        DMA_SRC_FIX        |                                \
        0x04000000 | ((Size)/(32/8) & 0x1fffff))); \
}

#define CpuArrayClear(Data, Destp)                     \
        CpuClear(     Data, Destp, sizeof(Destp))

#define CST_ROM0_1ST_3WAIT      0x0004      //                 3 wait
#define CST_ROM0_2ND_1WAIT      0x0010      //                 1 wait
#define CST_PREFETCH_ENABLE     0x4000      // Enable prefetch buffer
#define V_BLANK_INTR_FLAG       0x0001      // V Blank Interrupt
#define H_BLANK_INTR_FLAG       0x0002      // H Blank Interrupt
#define CASSETTE_INTR_FLAG      0x2000      // Game Pak Interrupt
#define STAT_V_BLANK_IF_ENABLE  0x0008      // V Blank Interrupt Request, Enable
#define STAT_H_BLANK_IF_ENABLE  0x0010      // H Blank Interrupt Request, Enable
#define INTR_VECTOR_BUF         (0x03008000 - 0x4)
#define INTR_CHECK_BUF          (0x03008000 - 0x8)

#define A_BUTTON                0x0001      // A Button
#define B_BUTTON                0x0002      // B Button
#define SELECT_BUTTON           0x0004      // SELECT
#define START_BUTTON            0x0008      // START
#define R_KEY                   0x0010      // Right Button
#define L_KEY                   0x0020      // Left Button
#define U_KEY                   0x0040      // Up Button
#define D_KEY                   0x0080      // Down Button
//#define R_BUTTON                0x0100      // R Button
//#define L_BUTTON                0x0200      // L Button

typedef struct {
    u32 VPos:8;             // Y Coordinate
    u32 AffineMode:2;       // Affine Mode
    u32 ObjMode:2;          // OBJ Mode
    u32 Mosaic:1;           // Mosaic
    u32 ColorMode:1;        // 16 colors/256 colors Select
    u32 Shape:2;            // OBJ Shape

    u32 HPos:9;             // X Coordinate
    u32 AffineParamNo_L:3;  // Affine Transformation Parameter No.  Lower 3 bits
    u32 HFlip:1;            // H Flip
    u32 VFlip:1;            // V Flip
    u32 Size:2;             // OBJ Size

    u16 CharNo:10;          // Character No.
    u16 Priority:2;         // Display priority
    u16 Pltt:4;             // Palette No.
    u16 AffineParam;        // Affine Trasnformation Parameter
} OamData;

typedef struct {
    u16 SrcNum;             // Source Data Byte Size
    u8  SrcBitNum;          // 1 Source Data Bit Number
    u8  DestBitNum;         // 1 Destination Data Bit Number
    u32 DestOffset:31;      // Number added to Source Data
    u32 DestOffset0_On:1;   // Flag to add/not add Offset to 0 Data
} BitUnPackParam;


