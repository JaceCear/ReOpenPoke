	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global Amber_YourHouse_Script
	.global Amber_MapScript_Script
	.global Amber_Villager1_Script
	.global Amber_Villager2_Script
	.global Amber_Villager3_Script
	.global Amber_Warning_Script
	.global Amber_HisHouse_Script

@ -------------------------------------
@ YourHouse
@ -------------------------------------
Amber_YourHouse_Script:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_YourHouse_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Amber_YourHouse_Str0:
	.asciz "\x1F\x01's House."

@ -------------------------------------
@ MapScript
@ -------------------------------------
Amber_MapScript_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word Amber_MapScript_EndIt @ target
	.byte CHECKFLAG
	 .short 0x4 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Amber_MapScript_EndIt @ target
	.byte SETFLAG
	 .short 0x4 @ index
	.byte SETFLAG
	 .short 0x5 @ index
	.byte APPLYMOVE
	 .short 0 @ target
	 .word Amber_MapScript_DannyTurn @ path
	.byte APPLYMOVE
	 .short 4 @ target
	 .word Amber_MapScript_DaniApproach @ path
	.byte WAITFORMOVE
	 .short 4 @ target
	.byte MSGBOXNORMAL
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_MapScript_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte APPLYMOVE
	 .short 4 @ target
	 .word Amber_MapScript_DaniRetreat @ path
	.byte WAITFORMOVE
	 .short 4 @ target
	.byte CLEARFLAG
	 .short 0x5 @ index
	.byte END
	.align 4
Amber_MapScript_EndIt:
	.byte CHECKFLAG
	 .short 0xB @ index
	.byte IFGOTO
	 .byte 0 @ condition
	 .word Amber_MapScript_ReallyEndIt @ target
	.byte CHECKFLAG
	 .short 0xF @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Amber_MapScript_ReallyEndIt @ target
	.byte SETFLAG
	 .short 0xF @ index
	.byte SETFLAG
	 .short 0x5 @ index
	.byte APPLYMOVE
	 .short 4 @ target
	 .word Amber_MapScript_DaniApproach2 @ path
	.byte WAITFORMOVE
	 .short 4 @ target
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_MapScript_Str1
	.byte CALLSTD
	 .byte 4 @ routine
	.byte GETGENDER
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOSUB
	 .byte 1 @ condition
	 .word Amber_MapScript_FightDanny @ target
	.byte IFGOSUB
	 .byte 0 @ condition
	 .word Amber_MapScript_FightDani @ target
	.byte COMPARE
	 .short 0x800D @ index
	 .short 0 @ value
	.byte IFGOSUB
	 .byte 1 @ condition
	 .word Amber_MapScript_Won @ target
	.byte IFGOSUB
	 .byte 0 @ condition
	 .word Amber_MapScript_Lost @ target
	.byte APPLYMOVE
	 .short 4 @ target
	 .word Amber_MapScript_DaniRetreat2 @ path
	.byte WAITFORMOVE
	 .short 4 @ target
	.byte CLEARFLAG
	 .short 0x5 @ index
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_MapScript_Str4
	.byte CALLSTD
	 .byte 4 @ routine
	.byte GIVEITEM
	 .short 4
	 .short 5
	.byte SETFLAG
	 .short 0x829
	.byte END
	.align 4
Amber_MapScript_FightDanny:
	.byte TRAINERBATTLE
	 .short 1 @ index
	 .word 0
	 .word Foo
	 .word 0
	 .word 0
	.byte RETURN
	.align 4
Amber_MapScript_FightDani:
	.byte TRAINERBATTLE
	 .short 0 @ index
	 .word 0
	 .word Foo
	 .word 0
	 .word 0
	.byte RETURN
	.align 4
Amber_MapScript_Won:
	.byte SETFLAG
	 .short 0x10 @ index
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_MapScript_Str2
	.byte CALLSTD
	 .byte 4 @ routine
	.byte RETURN
	.align 4
Amber_MapScript_Lost:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_MapScript_Str3
	.byte CALLSTD
	 .byte 4 @ routine
	.byte RETURN
	.align 4
Amber_MapScript_ReallyEndIt:
	.byte END
	.align 4
Amber_MapScript_DannyTurn:

	.byte 0x06, 0xFE
	.align 4
Amber_MapScript_DaniApproach:

	.byte 0x04, 0x04, 0x04, 0x04, 0x04, 0xFE
	.align 4
Amber_MapScript_DaniRetreat:

	.byte 0x02, 0x02, 0x02, 0x02, 0x02, 0xFE
	.align 4
Amber_MapScript_DaniApproach2:
	.byte 4,3,3,3,3,3,3,2,2,2,100,7,0xFE
	@.byte 0x03, 0x03, 0x03, 0x03, 0xFE
	.align 4
Amber_MapScript_DaniRetreat2:
	.byte 4,4,4,4,4,4,4,4,0xFE
	@.byte 0x01, 0x01, 0x01, 0x01, 0xFE

@ String pool
Amber_MapScript_Str0:
	.asciz "Hey, \x1F\x01! How are you?\nSorry, I gotta run. We were supposed\r\nto get a few goods delivered from the\nmart, but you know that sometimes\r\nthings don't work out, huh?"
Amber_MapScript_Str1:
	.asciz "Hey, \x1F\x01! So, I see you got\nyour Pokémon?\r\fI can't believe it. I already got mine,\nand you picked one WEAK to mine!\r\fBut you know, the rules say any trainer\ncan challenge another trainer whenever\r\nthey want. So, I challenge YOU,\n\x1F\x01!"
Amber_MapScript_Str2:
	.asciz "Wow, you sure managed that one well,\n\x1F\x01! How about a challenge?\r\fNo, wait, this is just a demo.\r\fNever mind, then!"
Amber_MapScript_Str3:
	.asciz "Hoo, good try \x1F\x01.\r\nWow, I'm glad I won. Still, I bet you'll\ndo better next time!\r\nOh, wait, that's right! This is\njust a demo!"
Amber_MapScript_Str4:
	.asciz "Well, I guess that's it\nfor now.\r\nHave a good one, and good luck!\r\nIn fact, have some balls so you can\nmess around in this doomed world.\r\fNo, really. Look in your inventory."

Foo:
	.asciz "Awww dammit!"

@ -------------------------------------
@ Villager1
@ -------------------------------------
Amber_Villager1_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word Amber_Villager1_EndIt @ target
	.byte CHECKFLAG
	 .short 9 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Amber_Villager1_EndIt @ target
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_Villager1_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
Amber_Villager1_EndIt:
	.byte END

@ String pool
Amber_Villager1_Str0:
	.asciz "Oh, hey \x1F\x01. Professor\nMaple was looking for you."

@ -------------------------------------
@ Villager2
@ -------------------------------------
Amber_Villager2_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word Amber_Villager2_EndIt @ target
	.byte CHECKFLAG
	 .short 9 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Amber_Villager2_EndIt @ target
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_Villager2_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
Amber_Villager2_EndIt:
	.byte END

@ String pool
Amber_Villager2_Str0:
	.asciz "Oh, hiya! Where you off to?"

@ -------------------------------------
@ Villager3
@ -------------------------------------
Amber_Villager3_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word Amber_Villager3_EndIt @ target
	.byte CHECKFLAG
	 .short 9 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Amber_Villager3_EndIt @ target
	.byte LOCK
	.byte FACEPLAYER
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_Villager3_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END
	.align 4
Amber_Villager3_EndIt:
	.byte END

@ String pool
Amber_Villager3_Str0:
	.asciz "Oh, no! Now I've gotta get to the mart!"

@ -------------------------------------
@ Warning
@ -------------------------------------
Amber_Warning_Script:
	.byte COMPARE
	 .short 0x4000 @ index
	 .short 0 @ value
	.byte IFGOTO
	 .byte 0 @ condition
	 .word Amber_Warning_EndIt @ target
	.byte CHECKFLAG
	 .short 0x6 @ index
	.byte IFGOTO
	 .byte 1 @ condition
	 .word Amber_Warning_EndIt @ target
	.byte LOCK
	.byte MSGBOXNORMAL
	.byte APPLYMOVE
	 .short 1 @ target
	 .word Amber_Warning_KidApproach @ path
	.byte MSGBOX2
	 .word Amber_Warning_Str0
	.byte WAITMSGBOX
	.byte APPLYMOVE
	 .short 0 @ target
	 .word Amber_Warning_What @ path
	.byte WAITFORMOVE
	 .short 0 @ target
	.byte WAITFORMOVE
	 .short 1 @ target
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_Warning_Str1
	.byte CALLSTD
	 .byte 4 @ routine
	.byte APPLYMOVE
	 .short 1 @ target
	 .word Amber_Warning_KidRetreat @ path
	.byte APPLYMOVE
	 .short 0 @ target
	 .word Amber_Warning_KidRetreat @ path
	.byte WAITFORMOVE
	 .short 1 @ target
	.byte END
	.align 4
Amber_Warning_EndIt:
	.byte END
	.align 4
Amber_Warning_What:

	.byte 0x6A, 0xFE
	.align 4
Amber_Warning_KidApproach:

	.byte 0x03, 0x03, 0x03, 0x03, 0xFE
	.align 4
Amber_Warning_KidRetreat:

	.byte 0x01, 0x01, 0x01, 0x01, 0xFE

@ String pool
Amber_Warning_Str0:
	.asciz "Hey \x1F\x01!"
Amber_Warning_Str1:
	.asciz "What's the rush? Professor Maple's\nlooking for you!"

@ -------------------------------------
@ HisHouse
@ -------------------------------------
Amber_HisHouse_Script:
	.byte LOADPOINTER
	 .byte 0 @ bank
	 .word Amber_HisHouse_Str0
	.byte CALLSTD
	 .byte 4 @ routine
	.byte END

@ String pool
Amber_HisHouse_Str0:
	.asciz "\x1F\x02's House."

