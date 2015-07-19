	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global AmberHouse1U_MapScriptA_Script
	.global AmberHouse1U_MapScriptB_Script
	.global AmberHouse1U_PC_Script

@ -------------------------------------
@ MapScriptA
@ -------------------------------------
AmberHouse1U_MapScriptA_Script:
	.byte HIDESPRITE
	 .short 1 @ target
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberHouse1U_MapScriptA_EndIt @ target
	.byte CLEARFLAG
	 .short 0x802 @ index
	.byte CHECKFLAG
	 .short 0x1 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberHouse1U_MapScriptA_EndIt @ target
	.byte SHOWSPRITE
	 .short 1 @ target
	.byte BLACKMAP
	.byte GETTIME
	 .byte 1 @ what
	.byte GETNUMBER
	 .byte 0 @ svar
	 .short 0x800D @ index
	.byte MSGBOXNORMAL
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberHouse1U_MapScriptA_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.align 4
AmberHouse1U_MapScriptA_EndIt:
	.byte END

@ String pool
AmberHouse1U_MapScriptA_Str0:
	.asciz "Wake up, sleepy head!\nIt's \x1F\x03 o'clock already!"

@ -------------------------------------
@ MapScriptB
@ -------------------------------------
AmberHouse1U_MapScriptB_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberHouse1U_MapScriptB_EndIt @ target
	.byte CHECKFLAG
	 .short 0x1 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberHouse1U_MapScriptB_EndIt @ target
	.byte SETFLAG
	 .short 0x1 @ index
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberHouse1U_MapScriptB_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte APPLYMOVE
	 .short 1 @ target
	 .word AmberHouse1U_MapScriptB_MomLeaves @ path
	.byte WAITFORMOVE
	 .short 1 @ target
	.byte HIDESPRITE
	 .short 1 @ target
	.align 4
AmberHouse1U_MapScriptB_EndIt:
	.byte END
	.align 4
AmberHouse1U_MapScriptB_MomLeaves:

	.byte 0x03, 0x03, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0xFE

@ String pool
AmberHouse1U_MapScriptB_Str0:
	.asciz "Finally. Anyways, Professor Maple\ncalled, she asked that you go see her.\r\nApparently she needs help\nwith something."

@ -------------------------------------
@ PC
@ -------------------------------------
AmberHouse1U_PC_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberHouse1U_PC_EndIt @ target
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberHouse1U_PC_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.align 4
AmberHouse1U_PC_EndIt:
	.byte END

@ String pool
AmberHouse1U_PC_Str0:
	.asciz "The PC is giving all sorts of error\nmessages. Strange.\r\nBetter not try to withdraw\nanything now."

