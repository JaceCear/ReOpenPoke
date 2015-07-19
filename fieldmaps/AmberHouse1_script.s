	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global AmberHouse1_MomBot5000_Script
	.global AmberHouse1_MapScript_Script

@ -------------------------------------
@ MomBot5000
@ -------------------------------------
AmberHouse1_MomBot5000_Script:
	.byte LOCK
	.byte FACEPLAYER
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberHouse1_MomBot5000_EndIt @ target
	.byte CHECKFLAG
	 .short 3 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberHouse1_MomBot5000_SecondThing @ target
	.align 4
AmberHouse1_MomBot5000_FirstThing:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberHouse1_MomBot5000_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte SETFLAG
	 .short 3 @ index
	.byte END
	.align 4
AmberHouse1_MomBot5000_SecondThing:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberHouse1_MomBot5000_Str1
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberHouse1_MomBot5000_EndIt:
	.byte END

@ String pool
AmberHouse1_MomBot5000_Str0:
	.asciz "Here, I made breakfast for you."
AmberHouse1_MomBot5000_Str1:
	.asciz "Well, you need to get going!"

@ -------------------------------------
@ MapScript
@ -------------------------------------
AmberHouse1_MapScript_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberHouse1_MapScript_EndIt @ target
	.byte CHECKFLAG
	 .short 0x101 @ index
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberHouse1_MapScript_EndIt @ target
	.byte SETFLAG
	 .short 0x802 @ index
	.align 4
AmberHouse1_MapScript_EndIt:
	.byte END

