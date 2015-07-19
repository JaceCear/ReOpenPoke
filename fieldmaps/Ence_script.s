	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global Ence_ShadyMan_Script
	.global Ence_Fountain_Script

@ -------------------------------------
@ ShadyMan
@ -------------------------------------
Ence_ShadyMan_Script:
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Ence_ShadyMan_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Ence_ShadyMan_Str0:
	.asciz "Hey kid… want to buy some…\n…cookies?\r\nCarbo Cookies, only $100!"

@ -------------------------------------
@ Fountain
@ -------------------------------------
Ence_Fountain_Script:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Ence_Fountain_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Ence_Fountain_Str0:
	.asciz "See your face upon the clean water.\nHow dirty! Come! Wash your face!"

