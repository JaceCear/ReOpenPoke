
#ifndef	__ISAGBPRN_H__
#define	__ISAGBPRN_H__

#ifdef __cplusplus
extern "C" {
#endif
void bl();
#undef NDEBUG
/////////////////////////////////////////////////////////////////////////
/// Copyright 2000 INTELLIGENT SYSTEMS Co.,Ltd.
/// Copyright 2000 Nintendo of America Inc. 
/// IS-AGB-EMULATOR
/// PRINT DEBUG LIBRARY [libagbprn.a]
/////////////////////////////////////////////////////////////////////////
/// Function Description
/// 
/// [Initialize Pring Debug]
/// void AGBPrintInit(void);
///						Initializes the buffer to be used for Print Debug.  
///						0x08fd0000 - 0x08fdffff is being used right now. This address may change 
///						in the future depending on the I
///						 S-CGB-EMULATOR's emulation capacity.
///
/// [Output 1 Character]
///	 void AGBPutc(const char cChar);
///		cChar:	Adds one character in a display queue buffer.  It will not be displayed right away even when this function is called.  
///					 However, when the queue buffer becomes full, it continues to wait until 
///						it is possible to display 1  
///						block's worth. 
///
/// [Output Character String]
/// void AGBPrint(const char* pBuf);
///		 pBuf: Adds a character string in a display queue buffer.  It will not be displayed right away  
///						even when this function is called.  However, when the queue buffer becomes full, it continues to wait until 
///						it is possible to display  
///						1 block's worth. 
///
/// [Output Character String with Format]
///	void AGBPrintf(const char *pBuf, ...)
///		 pBuf:	Adds a character string formatted in a display queue buffer.  
///						It will not be displayed right 
///						away.  However, when the queue buffer becomes full, it continues to wait until it is possible to display
///						1 block's worth. (The usage is 
///						same as ANSI printf() function's usage.)
///
/// [Character String 1 block display]
/// void AGBPrintFlush1Block(void);
///						Flushes the capacity which will  
///						not affect the AGB's operation much from the display queue buffer.   
///						If this function is called every V-BLANK,without stopping the AGB completely,
///						a character string can be flushed gradually in  
///						the command views of IS-AGB-EMULATOR and IS-AGB-DEBUGGER.  
///						It is convenient when displaying every frame of character strings. 
///
/// [Flush Character String]
/// void AGBPrintFlush(void);
///						It is possible to flush character 
///						strings in the command views of IS-AGB-EMULATOR and IS-AGB-DEBUGGER until 
///						a display queue buffer becomes completely empty.  
///
/// [Macro to Check Program Normalcy]
/// AGB_ASSERT(evaluation equation);
///		 The evaluation equation is an evaluation equation written in C.  
///		 If the value of the evaluation equation is true (not ZERO), the 
///		 next program is executed.  If it is false (ZERO), the source 
///		 filename defined by AGB_ASSERT(), the line number therein, and 
///		 the evaluation equation are displayed, and the program is 
///		 suspended.
///
/// [Macro to Check Program Normalcy]
/// AGB_WARNING( expression );
///		 This is used in the same way as AGB_ASSERT().  It differs from 
///		 AGB_ASSERT() in that ASSERT does not perform any processing 
///		 after the program has been suspended (hang status), while 
///		 ABG_WARNING continues to run the program. 
/////////////////////////////////////////////////////////////////////////
/// Precautions
/// 
/// - This library is for use with gcc.
/// - This library is exclusively for thumb. Cannot be used with arm. 
/// - Even though a character string is output, it doesn't mean that it is 
///	output directly to the host. It is output to the host
///		when the buffer becomes full, or if Flush related functions 
///		are called. 
/// - A user must not change the area used for Print Debug. 
/// - Due to IS-AGB-EMULATOR hardware, while data is sent to the host, 
///		(during AGBFlash() is called)an interrupt is [temporarily] 
///		prohibited, and Memory Wait is changed. 
/// - Be sure to specify the -mthumb-interwork option for the gcc compiler. 
///  - When the ROM is created at the time of shipping, all of the print debug
///	functions can be deleted by defining NDEBUG. 
/// - It is necessary to always link libg.a before libisagbprn.a.  
///   Be careful not to include libg.a or libisagbprn.a in ROMs for shipment.
///
/////////////////////////////////////////////////////////////////////////
/// Example of Makefile Link Line
/// -lg -L. -l isagbprn

/////////////////////////////////////////////////////////////////////////
/// Sample Application
/// 
/// AGBPrintInit();
///
/// while(1) {
///   static int i;
///		AGBPrint("TEST PROGRAM %d \n", i++);
///			pSelf->X++;
///			AGB_ASSERT((pSelf != NULL) && (pSelf->X > 0));
///   AGBFlush1Block();
/// }
///
///

/////////////////////////////////////////////////////////////////////////
///

#ifdef NDEBUG
	#define AGBPrintInit()							
	#define AGBPutc(cChar)							
	#define AGBPrint(pBuf)							
	#define	AGBPrintf(...)							
	#define AGBPrintFlush1Block()				
	#define AGBPrintFlush()							
	#define AGBAssert(file,line,info)		

#else
	void AGBPrintInit(void);
	void AGBPutc(const char pBuf);
	void AGBPrint(const char* pBuf);
	void AGBPrintf(const char *pBuf, ...);
	void AGBPrintFlush1Block(void);
	void AGBPrintFlush(void);
	void AGBAssert(const char* pFile, int nLine, const char* pExpression, int nStopProgram);
#endif

/////////////////////////////////////////////////////////////////////////
///

#undef AGB_ASSERT
#ifdef NDEBUG
#define	AGB_ASSERT(exp)
#else
#define	AGB_ASSERT(exp)	(exp) ? ((void*)0) : AGBAssert(__FILE__, __LINE__, #exp, 1);
#endif

#undef AGB_WARNING
#ifdef NDEBUG
#define	AGB_WARNING(exp)
#else
#define	AGB_WARNING(exp)	 (exp) ? ((void*)0) : AGBAssert(__FILE__, __LINE__, #exp, 0);
#endif

/////////////////////////////////////////////////////////////////////////

#undef NDEBUG

#ifdef __cplusplus
}	 // extern "C"
#endif

#endif

