//
//  Main tonc header
//
//! \file tonc.h
//! \author J Vijn
//! \date 20060508 - 20060508
//
// === NOTES ===


#ifndef TONC_MAIN
#define TONC_MAIN

#ifdef __cplusplus
extern "C" {
#endif

#include "tonc_types.h"
#include "tonc_memmap.h"
#include "tonc_memdef.h"

#include "tonc_bios.h"
#include "tonc_core.h"
#include "tonc_input.h"
#include "tonc_irq.h"
#include "tonc_math.h"
#include "tonc_text.h"
#include "tonc_video.h"

#ifdef __cplusplus
}
#endif

// --- Doxygen modules: ---

/*!	\defgroup grpBios	Bios Calls		*/
/*!	\defgroup grpCore	Core			*/
/*! \defgroup grpDma	DMA				*/
/*! \defgroup grpInput	Input			*/
/*! \defgroup grpIrq	Interrupt		*/
/*! \defgroup grpMath	Math			*/
/*!	\defgroup grpMemmap Memory Map		*/
/*! \defgroup grpAudio	Sound			*/
/*! \defgroup grpText	Text			*/
/*! \defgroup grpTimer	Timer			*/
/*! \defgroup grpVideo	Video			*/

#endif // TONC_MAIN

