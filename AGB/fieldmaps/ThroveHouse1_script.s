	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global ThroveHouse1_Welcome_Script

@ -------------------------------------
@ Welcome
@ -------------------------------------
ThroveHouse1_Welcome_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word ThroveHouse1_Welcome_EndIt @ target
	.byte CHECKFLAG
	 .short 0x7 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word ThroveHouse1_Welcome_Balls @ target
	.byte CHECKFLAG
	 .short 0x6 @ index
	.byte IFGOTO
	 .byte 0 @ condition
	 .word ThroveHouse1_Welcome_EndIt @ target
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word ThroveHouse1_Welcome_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word ThroveHouse1_Welcome_Str1
	.byte CALLSTD
	 .byte 4 @ routine
	.byte TAKEITEM
	 .short 375 @ index
	 .short 1 @ amount
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word ThroveHouse1_Welcome_Str2
	.byte CALLSTD
	 .byte 4 @ routine
	.byte GIVEITEM
	 .short 376 @ index
	 .short 1 @ amount
	.byte SETFLAG
	 .short 0x7 @ index
	.align 4
ThroveHouse1_Welcome_Balls:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word ThroveHouse1_Welcome_Str3
	.byte CALLSTD
	 .byte 4 @ routine
	.align 4
ThroveHouse1_Welcome_EndIt:
	.byte END

@ String pool
ThroveHouse1_Welcome_Str0:
	.asciz "Oh, hello. Professor Maple called\nand said you'd have the package."
ThroveHouse1_Welcome_Str1:
	.asciz "\x1F\x01 handed over\nthe Maple Parcel.\7\x8\x30\1"
ThroveHouse1_Welcome_Str2:
	.asciz "Oh, wonderful, thank you!\r\nSorry to bother you, but could you take\nthese POKé BALLS back to the professor?"
ThroveHouse1_Welcome_Str3:
	.asciz "Be careful now, kid."

