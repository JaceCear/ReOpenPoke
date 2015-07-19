	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global Throve_MapScript_Script
	.global Throve_Gary_Script
	.global Throve_Rocket_Script
	.global Throve_Rocket2_Script

@ -------------------------------------
@ MapScript
@ -------------------------------------
Throve_MapScript_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word Throve_MapScript_EndIt @ target
	.byte CHECKFLAG
	 .short 0xD @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Throve_MapScript_EndIt @ target
	.byte SETFLAG
	 .short 0xD @ index
	.byte PHONE
	 .byte 0 @ action
	 .byte 1 @ index
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Throve_MapScript_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.align 4
Throve_MapScript_EndIt:
	.byte END

@ String pool
Throve_MapScript_Str0:
	.asciz "Hi-i \x1F\x01! Joshua lives\nin the smaller building\r\nin front of the Poké Center."

@ -------------------------------------
@ Gary
@ -------------------------------------
Throve_Gary_Script:
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Throve_Gary_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Throve_Gary_Str0:
	.asciz "Hi \x1F\x01."

@ -------------------------------------
@ Rocket
@ -------------------------------------
Throve_Rocket_Script:
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Throve_Rocket_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Throve_Rocket_Str0:
	.asciz "Hi kid. Nice hair."

@ -------------------------------------
@ Rocket2
@ -------------------------------------
Throve_Rocket2_Script:
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Throve_Rocket2_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Throve_Rocket2_Str0:
	.asciz "Enjoy your shopping."

