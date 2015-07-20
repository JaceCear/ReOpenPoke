	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global AmberLab_Maple_Script
	.global AmberLab_Ball1_Script
	.global AmberLab_Ball2_Script
	.global AmberLab_Ball3_Script

@ -------------------------------------
@ Maple
@ -------------------------------------
AmberLab_Maple_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberLab_Maple_EndIt @ target
	.byte CHECKFLAG
	 .short 0x6 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Maple_HavePackage @ target
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str0
	.byte CALLSTD
	 .byte 5 @ routine
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Maple_DidntHearTheNews @ target
	.align 4
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str1
	.byte CALLSTD
	 .byte 4 @ routine
AmberLab_Maple_Explain:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str2
	.byte CALLSTD
	 .byte 4 @ routine
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str3
	.byte CALLSTD
	 .byte 4 @ routine
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str4
	.byte CALLSTD
	 .byte 4 @ routine
	.byte GIVEITEM
	 .short 375 @ index
	 .short 1 @ amount
	.byte SETFLAG
	 .short 0x6 @ index
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str5
	.byte CALLSTD
	 .byte 4 @ routine
	.byte APPLYMOVE
	 .short 0x800F @ target
	 .word AmberLab_Maple_TeeHee @ path
	.byte WAITFORMOVE
	 .short 0x800F @ target
	.byte APPLYMOVE
	 .short 0 @ target
	 .word AmberLab_Maple_Sweatdrop @ path
	.byte WAITFORMOVE
	 .short 0 @ target
	.byte END
	.align 4
AmberLab_Maple_DidntHearTheNews:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str6
	.byte CALLSTD
	 .byte 4 @ routine
	.byte JUMP
	 .word AmberLab_Maple_Explain
	.align 4
AmberLab_Maple_HavePackage:
	.byte CHECKFLAG
	 .short 0x7 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Maple_SelectMonster @ target
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str7
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberLab_Maple_SelectMonster:
	.byte CHECKFLAG
	 .short 0xB @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Maple_HaveStarter @ target
	.byte FACEPLAYER
	.byte CHECKFLAG
	 .short 0xE @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Maple_GoAhead @ target
	.byte TAKEITEM
	 .short 376 @ index
	 .short 1 @ amount
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str8
	.byte CALLSTD
	 .byte 4 @ routine
	.byte COMPARE
	 .short 0x800C
	 .short 2
	.byte IFGOSUB
	 .byte 1
	 .word AmberLab_Maple_StepAside
	.byte APPLYMOVE
	 .short 0x800F @ target
	 .word AmberLab_Maple_Iterate @ path
	.byte WAITFORMOVE
	 .short 0x800F @ target
	.byte SHOWSPRITE
	 .short 2 @ target
	.byte APPLYMOVE
	 .short 0x800F @ target
	 .word AmberLab_Maple_Iterate @ path
	.byte WAITFORMOVE
	 .short 0x800F @ target
	.byte SHOWSPRITE
	 .short 3 @ target
	.byte APPLYMOVE
	 .short 0x800F @ target
	 .word AmberLab_Maple_Iterate @ path
	.byte WAITFORMOVE
	 .short 0x800F @ target
	.byte SHOWSPRITE
	 .short 4 @ target
	.byte APPLYMOVE
	 .short 0x800F @ target
	 .word AmberLab_Maple_Finish @ path
	.byte WAITFORMOVE
	 .short 0x800F @ target
	.align 4
AmberLab_Maple_GoAhead:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str9
	.byte CALLSTD
	 .byte 4 @ routine
	.byte SETFLAG
	 .short 0xE @ index
	.align 4
AmberLab_Maple_EndIt:
	.byte END
	.align 4
AmberLab_Maple_HaveStarter:
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Maple_Str10
	.byte CALLSTD
	 .byte 4 @ routine
	.byte APPLYMOVE
	 .short 0x800F @ target
	 .word AmberLab_Maple_TeeHee @ path
	.byte WAITFORMOVE
	 .short 0x800F @ target
	.byte END
	.align 4
AmberLab_Maple_StepAside:
	.byte APPLYMOVE
	 .short 0
	 .word AmberLab_Maple_StepAsideM
	.byte WAITFORMOVE
	 .short 0
	.byte RETURN
	.align 4

AmberLab_Maple_TeeHee:
	.byte 105, 254
	.align 4
AmberLab_Maple_Sweatdrop:
	.byte 107, 254
	.align 4
AmberLab_Maple_StepAsideM:
	.byte 4, 6, 254
	.align 4
AmberLab_Maple_Iterate:
	.byte 1, 6, 0, 0, 0, 254
	.align 4
AmberLab_Maple_Finish:
	.byte 4, 4, 4, 3, 3, 3, 6, 254
	.align 4

@ String pool
AmberLab_Maple_Str0:
	.asciz "Oh, I'm glad you came!\nDid you hear the news?"
AmberLab_Maple_Str1:
	.asciz "So yeah. Let me explain why I\nneed your help."
AmberLab_Maple_Str2:
	.asciz "With the PC Transport System offline, I\nhave to deliver a package, and I can't\r\njust send it now."
AmberLab_Maple_Str3:
	.asciz "So I was wondering if you could run it\nover for me?"
AmberLab_Maple_Str4:
	.asciz "Yes? Ah, wonderful!\r\nHere's the package.\nIt needs to go to Joshua."
AmberLab_Maple_Str5:
	.asciz "Thanks, \x1F\x01. You be\ncareful now, you hear?\r\nTee-hee!"
AmberLab_Maple_Str6:
	.asciz "You need to watch more TV, \x1F\x01."
AmberLab_Maple_Str7:
	.asciz "Thanks, \x1F\x01. You're a\nlife saver."
AmberLab_Maple_Str8:
	.asciz "Oh hey, I'm really sorry for making you\ndo all this."
AmberLab_Maple_Str9:
	.asciz "If you want, take one of these Poké\nBalls.\r\nYou can have one of the Pokémon\ninside as a make-up gift."
AmberLab_Maple_Str10:
	.asciz "You enjoy yourself now, y'hear?\nTee-hee!"

@ -------------------------------------
@ Ball1
@ -------------------------------------
AmberLab_Ball1_Script:
	.byte CHECKFLAG
	 .short 0xB @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball1_AlreadyHave @ target
	.byte CHECKFLAG
	 .short 0xE @ index
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberLab_Ball1_CantHaveOne @ target
	.byte SHOWMONSTERPIC
	 .short 25 @ index
	 .byte 10 @ x
	 .byte 3 @ y
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball1_Str0
	.byte CALLSTD
	 .byte 5 @ routine
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball1_EndItEarly @ target
	.byte HIDEMONSTERPIC
	.byte HIDESPRITE
	 .short 2 @ target
	.byte SETFLAG
	 .short 0xB @ index
	.byte APPLYMOVE
	 .short 0 @ target
	 .word AmberLab_Ball1_BeProud @ path
	.byte WAITFORMOVE
	 .short 0 @ target
	.byte GIVEMONSTER
	 .short 25 @ species
	 .byte 10 @ level
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball1_Str1
	.byte CALLSTD
	 .byte 5 @ routine
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball1_EndItAnyway @ target
	.byte SETNICKNAME
	 .byte 0 @ index
	.byte END
	.align 4
AmberLab_Ball1_EndItEarly:
	.byte HIDEMONSTERPIC
	.align 4
AmberLab_Ball1_EndItAnyway:
	.byte END
	.align 4
AmberLab_Ball1_AlreadyHave:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball1_Str2
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberLab_Ball1_CantHaveOne:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball1_Str3
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberLab_Ball1_BeProud:

	.byte 0x05, 0x06, 0x07, 0x08, 0x05, 0x64, 0xFE

@ String pool
AmberLab_Ball1_Str0:
	.asciz "So you want Pikachu?"
AmberLab_Ball1_Str1:
	.asciz "Do you want to give it\na nickname?"
AmberLab_Ball1_Str2:
	.asciz "You already have one.\nDon't be greedy."
AmberLab_Ball1_Str3:
	.asciz "It's a Poké Ball.\nInteresting."

@ -------------------------------------
@ Ball2
@ -------------------------------------
AmberLab_Ball2_Script:
	.byte CHECKFLAG
	 .short 0xB @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball2_AlreadyHave @ target
	.byte CHECKFLAG
	 .short 0xE @ index
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberLab_Ball2_CantHaveOne @ target
	.byte SHOWMONSTERPIC
	 .short 74 @ index
	 .byte 10 @ x
	 .byte 3 @ y
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball2_Str0
	.byte CALLSTD
	 .byte 5 @ routine
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball2_EndItEarly @ target
	.byte HIDEMONSTERPIC
	.byte HIDESPRITE
	 .short 3 @ target
	.byte SETFLAG
	 .short 0xB @ index
	.byte APPLYMOVE
	 .short 0 @ target
	 .word AmberLab_Ball2_BeProud @ path
	.byte WAITFORMOVE
	 .short 0 @ target
	.byte GIVEMONSTER
	 .short 74 @ species
	 .byte 10 @ level
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball2_Str1
	.byte CALLSTD
	 .byte 5 @ routine
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball2_EndItAnyway @ target
	.byte SETNICKNAME
	 .byte 0 @ index
	.byte END
	.align 4
AmberLab_Ball2_EndItEarly:
	.byte HIDEMONSTERPIC
	.align 4
AmberLab_Ball2_EndItAnyway:
	.byte END
	.align 4
AmberLab_Ball2_AlreadyHave:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball2_Str2
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberLab_Ball2_CantHaveOne:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball2_Str3
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberLab_Ball2_BeProud:

	.byte 0x05, 0x06, 0x07, 0x08, 0x05, 0x64, 0xFE

@ String pool
AmberLab_Ball2_Str0:
	.asciz "So you want Geodude?"
AmberLab_Ball2_Str1:
	.asciz "Do you want t\x6F give it\na nickname?"
AmberLab_Ball2_Str2:
	.asciz "You already have one.\nDon\x27t be greedy."
AmberLab_Ball2_Str3:
	.asciz "It\x27s a Poké Ball.\nInteresting."

@ -------------------------------------
@ Ball3
@ -------------------------------------
AmberLab_Ball3_Script:
	.byte CHECKFLAG
	 .short 0xB @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball3_AlreadyHave @ target
	.byte CHECKFLAG
	 .short 0xE @ index
	.byte IFGOTO
	 .byte 0 @ condition
	 .word AmberLab_Ball3_CantHaveOne @ target
	.byte SHOWMONSTERPIC
	 .short 116 @ index
	 .byte 10 @ x
	 .byte 3 @ y
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball3_Str0
	.byte CALLSTD
	 .byte 5 @ routine
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball3_EndItEarly @ target
	.byte HIDEMONSTERPIC
	.byte HIDESPRITE
	 .short 4 @ target
	.byte SETFLAG
	 .short 0xB @ index
	.byte APPLYMOVE
	 .short 0 @ target
	 .word AmberLab_Ball3_BeProud @ path
	.byte WAITFORMOVE
	 .short 0 @ target
	.byte GIVEMONSTER
	 .short 116 @ species
	 .byte 10 @ level
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball3_Str1
	.byte CALLSTD
	 .byte 5 @ routine
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 1 @ condition
	 .word AmberLab_Ball3_EndItAnyway @ target
	.byte SETNICKNAME
	 .byte 0 @ index
	.byte END
	.align 4
AmberLab_Ball3_EndItEarly:
	.byte HIDEMONSTERPIC
	.align 4
AmberLab_Ball3_EndItAnyway:
	.byte END
	.align 4
AmberLab_Ball3_AlreadyHave:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball3_Str2
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberLab_Ball3_CantHaveOne:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word AmberLab_Ball3_Str3
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
AmberLab_Ball3_BeProud:

	.byte 0x05, 0x06, 0x07, 0x08, 0x05, 0x64, 0xFE

@ String pool
AmberLab_Ball3_Str0:
	.asciz "So you want Horsea?"
AmberLab_Ball3_Str1:
	.asciz "Do you want to give it\na nickname?"
AmberLab_Ball3_Str2:
	.asciz "You already have one.\nDon't be greedy."
AmberLab_Ball3_Str3:
	.asciz "It's a Poké Ball.\nInteresting."

