	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global Route1_Rocket_Script
	.global Route1_Wednesday_Script

@ -------------------------------------
@ Rocket
@ -------------------------------------
Route1_Rocket_Script:
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Route1_Rocket_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Route1_Rocket_Str0:
	.asciz "This Wednesday, at 10 PM…\na big Pokémon battle."

@ -------------------------------------
@ Wednesday
@ -------------------------------------
Route1_Wednesday_Script:
	.byte GETTIME
	 .byte 2 @ what
	.byte COMPARE
	 .short 0x800D @ index
	 .short 3 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Route1_Wednesday_TisWensday @ target
	.byte CLEARFLAG
	 .short 0x4F @ index
	.byte END
	.align 4
Route1_Wednesday_TisWensday:
	.byte SETFLAG
	 .short 0x4F @ index
	.byte FADETOSOUND
	 .short 0x23 @ index
	.byte END

