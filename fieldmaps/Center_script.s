	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global Center_MapScript_Script

@ -------------------------------------
@ MapScript
@ -------------------------------------
Center_MapScript_Script:
	.byte SETRESPAWN
	 .byte 1 @ index
	.byte END

