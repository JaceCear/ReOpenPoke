	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global Std_NurseJoy_Script
	.global Std_Television_Script
	.global Std_PkCenterSign_Script
	.global Std_PkMartSign_Script

	.global StdMessage
	.global StdYesNoMessage
	.global	StdItemBall


@	.global	itemtest
@itemtest:
@	.byte COPYVARIFNOT0
@	 .short 0x8000
@	 .short 0x000D
@	.byte COPYVARIFNOT0
@	 .short 0x8001
@	 .short 0x1
@	.byte CALLSTD
@	 .byte 3
@	.byte END

@ -------------------------------------
@ NurseJoy
@ -------------------------------------
Std_NurseJoy_Script:
	.byte LOCK
	.byte GETTIME
	 .byte 0
	.byte COMPARE
	 .short 0x800D, 2 @ night
	.byte IFGOTO
	 .byte 0
	 .word Std_NurseJoy_NotNight
	.byte LOADPOINTER
	 .byte 0
	 .word Std_NurseJoy_Text_WelcomeNight
	.byte JUMP
	 .word Std_NurseJoy_Ask
Std_NurseJoy_NotNight:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_NurseJoy_Text_Welcome
Std_NurseJoy_Ask:
	.byte CALLSTD
	 .byte 5
	.byte COMPARE
	 .short 0x800D, 1
	.byte IFGOTO
	 .byte 1
	 .word Std_NurseJoy_SeeYa
	.byte SPECIAL
	 .short 1
	.byte COMPARE
	 .short 0x800D, 0
	.byte IFGOTO
	 .byte 1
	 .word Std_NurseJoy_NoParty
	.byte LOADPOINTER
	 .byte 0
	 .word Std_NurseJoy_Text_Okay
	.byte CALLSTD
	 .byte 4
	.byte APPLYMOVE
	 .short 1
	 .word Std_NurseJoy_Path_Turn
	.byte WAITFORMOVE
	 .short 1
	.byte SPECIAL
	 .short 3 @ Heal Pokémon center-style
	.byte APPLYMOVE
	 .short 1
	 .word Std_NurseJoy_Path_TurnBack
	.byte WAITFORMOVE
	 .short 1
	.byte LOADPOINTER
	 .byte 0
	 .word Std_NurseJoy_Text_ThankYou
	.byte CALLSTD
	 .byte 4
	.byte APPLYMOVE
	 .short 1
	 .word Std_NurseJoy_Path_Nod
	.byte WAITFORMOVE
	 .short 1
Std_NurseJoy_SeeYa:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_NurseJoy_Text_SeeYa
	.byte CALLSTD
	 .byte 4
	.byte END
Std_NurseJoy_NoParty:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_NurseJoy_Text_NoParty
	.byte CALLSTD
	 .byte 4
	.byte END
Std_NurseJoy_Text_Welcome:
	.asciz	"Welcome to our Pokémon Center!\r\fWould you like me to heal your\nPokémon back to perfect health?"
Std_NurseJoy_Text_WelcomeNight:
	.asciz	"Goodnight!\r\fWould you like me to heal your\nPokémon back to perfect health?"
Std_NurseJoy_Text_Okay:
	.asciz	"Okay, I'll take your Pokémon for a\nfew seconds.\1"
Std_NurseJoy_Text_ThankYou:
	.asciz	"Thank you for waiting.\nWe've restored your Pokémon to\r\nfull health.\1"
Std_NurseJoy_Text_SeeYa:
	.asciz	"We hope to see you again!"
Std_NurseJoy_Text_NoParty:
	.asciz	"You don't have any Pokémon to heal!"
	
Std_NurseJoy_Path_Turn:
	.byte 8, 254
Std_NurseJoy_Path_TurnBack:
	.byte 5, 254
Std_NurseJoy_Path_Nod:
	.byte 101, 254

@ -------------------------------------
@ Television
@ -------------------------------------
Std_Television_Script:
	.byte LOCK
	@ Check for regular program's time-based shows
	.byte GETTIME
	 .byte 1
	.byte COMPARE
	 .short 0x800D, 10 @ 10 AM
	.byte IFGOTO
	 .byte 1
	 .word Std_Television_LoadShow1
	.byte COMPARE
	 .short 0x800D, 21 @ 9 PM
	.byte IFGOTO
	 .byte 1
	 .word Std_Television_LoadShow2

	@ Continue with regular programming
	.byte GETRANDOM
	 .short 11
	.byte COMPARE
	 .short 0x800D, 0
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd1
	.byte COMPARE
	 .short 0x800D, 1
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd2
	.byte COMPARE
	 .short 0x800D, 2
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd3
	.byte COMPARE
	 .short 0x800D, 3
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd4
	.byte COMPARE
	 .short 0x800D, 4
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd5
	.byte COMPARE
	 .short 0x800D, 5
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd6
	.byte COMPARE
	 .short 0x800D, 6
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd7
	.byte COMPARE
	 .short 0x800D, 7
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd8
	.byte COMPARE
	 .short 0x800D, 8
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd9
	.byte COMPARE
	 .short 0x800D, 9
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd10
	.byte COMPARE
	 .short 0x800D, 10
	.byte IFGOTO
	 .byte 1 @ equal to zero
	 .word Std_Television_LoadRnd11
	.byte END
Std_Television_LoadRnd1:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random1
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd2:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random2
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd3:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random3
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd4:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random4
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd5:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random5
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd6:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random6
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd7:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random7
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd8:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random8
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd9:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random9
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd10:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random10
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadRnd11:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_Random11
	.byte JUMP
	 .word Std_Television_ShowRegularStuff

Std_Television_LoadShow1:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_DailyShow1
	.byte JUMP
	 .word Std_Television_ShowRegularStuff
Std_Television_LoadShow2:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_Television_Text_DailyShow2
	.byte JUMP
	 .word Std_Television_ShowRegularStuff

Std_Television_ShowRegularStuff:
	.byte CALLSTD
	 .byte 4
	.byte END
	
Std_Television_Text_Random1:
	.asciz "There's a movie on TV.\r\nFour boys are walking on railroad\ntracks.\r\f…I better go too."
Std_Television_Text_Random2:
	.asciz "There's a documentary on TV.\nIt's about the mating habits of Mudkip."
Std_Television_Text_Random3:
	.asciz "There's an interview on TV.\r\nGabby and Ty are interviewing\nProfessor Elm.\r\f“So…I heard you like Mudkips?”"
Std_Television_Text_Random4:
	.asciz "There's business news on TV.\r\nApparently, Nintendo has bought out\nSony!"
Std_Television_Text_Random5:
	.asciz "Oh, wow! It's that new anime!\nAnd…\rand…\r\n…it's translated by 4Kids." @insert sound effect here
Std_Television_Text_Random6:
	.asciz "There's a commercial on TV.\r\nI don't see why anyone would want\na PokéFlex 9001."
Std_Television_Text_Random7:
	.asciz "It's a news report questioning where\nour meat comes from.\r\nHmm…I always wondered the same thing."
Std_Television_Text_Random8:
	.asciz "It's a new action series that shows the\nJennies versus the Rockets.\r\nThough I have no idea why they gave\nTeam Rocket guns. Totally unrealistic."
Std_Television_Text_Random9:
	.asciz "Oh, a soap opera about a world without\nPokémon. What a strange world that\r\nwould be…"
Std_Television_Text_Random10:
	.asciz "“Welcome to the PokéDex hour!\nToday's Pokémon is Seaking……”\r\fAbout as boring as\nreading the dictionary."
Std_Television_Text_Random11:
	.asciz "Hey, they're advertising that new\nSeed Spit TM.\r\nWow, it must be hard for retailers to\nsell such a stupidly named TM."
Std_Television_Text_DailyShow1:
	.asciz "The Mostly Nothing Baka Rangers\nare on.\r A group of low-scoring\nschoolgirls that band together to\r\nprotect the rest of the class, even\nthough they don't need it.\r\n…I'd better go, too."
Std_Television_Text_DailyShow2:
	.asciz "'Lo there. I'm Carl Honduras.\r\fAnd I'm Minky Steve.\r\fAnd this is the nine o' clock\fFORK!!"
Std_Television_Text_NewsReport:
	.asciz "There's a news report on TV…"

Std_PkCenterSign_Script:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_PkCenterSign_Text
	.byte CALLSTD
	 .byte 4
	.byte END
Std_PkCenterSign_Text:
	.asciz "Heal your Pokémon!\nPokémon Center"

Std_PkMartSign_Script:
	.byte LOADPOINTER
	 .byte 0
	 .word Std_PkMartSign_Text
	.byte CALLSTD
	 .byte 4
	.byte END
Std_PkMartSign_Text:
	.asciz "All your item needs fulfilled!\nPokémon Mart"







StdMessage:
	.byte MSGBOX2
	 .word 0 @ Empty so it uses the earlier LOADPOINTER.
	.byte WAITMSGBOX
	.byte WAITKEYPRESS
	.byte RETURN

StdYesNoMessage:
	.byte MSGBOX2
	 .word 0 @ See above.
	.byte WAITMSGBOX
	.byte YESNOBOX
	 .byte 0x14, 8
	.byte RETURN

StdItemBall:
	@ Call with 0x8000 item index and 0x8001 item amount.
	.byte LOCK
	.byte FACEPLAYER
	@.byte CHECKSOUND
	.byte COPYVAR
	 .short 0x8004
	 .short 0x8000
	.byte COPYVAR
	 .short 0x8005
	 .short 0x8001	
	.byte CHECKITEMAMOUNT
	 .short 0x8000
	 .short 0x8001
	.byte COPYVAR
	 .short 0x8007
	 .short 0x800D
	.byte GETITEMNAME
	 .byte 1
	 .short 0x8000
	.byte CHECKITEMTYPE
	 .short 0x8000
	.byte CALL
	 .word Std_00_DetermineType
	.byte COMPARE
	 .short 0x8007
	 .short 1
	.byte IFGOSUB
	 .byte 1
	 .word StdItemBallTake
	.byte COMPARE
	 .short 0x8007
	 .short 0
	.byte IFGOSUB
	 .byte 1
	 .word StdItemBallFull
	.byte RELEASE
	.byte RETURN

StdItemBallTake:
	.byte HIDESPRITE
	 .short 0x800F
	.byte GIVEITEM
	 .short 0x8004
	 .short 0x8005

	@.byte SPECIAL2
	@ .short 0x800D
	@ .short 0x196
	.byte SETVAR
	 .short 0x800D, 0

	.byte COPYVAR
	 .short 0x8008
	 .short 0x800D
	.byte COMPARE
	 .short 0x8008
	 .short 1
	.byte IFGOSUB
	 .byte 1
	 .word StdItemBallContains
	.byte COMPARE
	 .short 0x8008
	 .short 0
	.byte IFGOSUB
	 .byte 1
	 .word StdItemBallFound
	@.byte WAITJINGLE
	.byte WAITMSGBOX
	.byte LOADPOINTER
	 .byte 0
	 .word aItemPutItIn
	.byte CALLSTD
	 .byte 4
	.byte RETURN

StdItemBallContains:
	.byte MSGBOX2
	 .word aItemBallContains
	.byte RETURN

StdItemBallFound:
	.byte MSGBOX2
	 .word aItemBallFound
	.byte RETURN

StdItemBallFull:
	.byte LOADPOINTER
	 .byte 0
	 .word aItemBallObtained
	.byte CALLSTD
	 .byte 4
	.byte LOADPOINTER
	 .byte 0
	 .word aItemBallBagFull
	.byte CALLSTD
	 .byte 4
	.byte SETVAR
	 .short 0x800D
	 .short 0
	.byte RETURN

aItemPutItIn:
	.asciz "\x1F\x01 put the \x1F\x04\nin the \x1F\x05."
aItemBallContains:
	.asciz "\x1F\x01 found a \x1F\x04!\nIt contains \x1F\x05."
aItemBallFound:
	.asciz "\x1F\x01 found one \x1F\x04!"
aItemBallObtained:
	.asciz "Obtained the \x1F\x04!"
aItemBallBagFull:
	.asciz "The Bag is full…"



Std_00_DetermineType:
	.byte COPYVAR
	 .short 0x8000
	 .short 0x800D
	.byte COMPARE
	 .short 0x8000
	 .short 1
	.byte IFGOTO
	 .byte 1
	 .word Std_00_Type1
	.byte COMPARE
	 .short 0x8000
	 .short 2
	.byte IFGOTO
	 .byte 1
	 .word Std_00_Type2
	.byte COMPARE
	 .short 0x8000
	 .short 3
	.byte IFGOTO
	 .byte 1
	 .word Std_00_Type3
	.byte COMPARE
	 .short 0x8000
	 .short 4
	.byte IFGOTO
	 .byte 1
	 .word Std_00_Type4
	.byte COMPARE
	 .short 0x8000
	 .short 5
	.byte IFGOTO
	 .byte 1
	 .word Std_00_Type5
	.byte END

Std_00_Type1:
	.byte GETSTANDARD
	 .byte 2
	 .short 24 @ "items pocket"
	.byte COMPARE
	 .short 0x8007
	 .short 1
	.byte IFGOSUB
	 .byte 1
	 .word Std_00_Jingle
	.byte RETURN

Std_00_Type2:
	.byte GETSTANDARD
	 .byte 2
	 .short 25 @ "key items pocket"
	.byte COMPARE
	 .short 0x8007
	 .short 1
	.byte IFGOSUB
	 .byte 1
	 .word Std_00_Jingle
	.byte RETURN

Std_00_Type3:
	.byte GETSTANDARD
	 .byte 2
	 .short 26 @ "poké balls pocket"
	.byte COMPARE
	 .short 0x8007
	 .short 1
	.byte IFGOSUB
	 .byte 1
	 .word Std_00_Jingle
	.byte RETURN

Std_00_Type4:
	.byte GETSTANDARD
	 .byte 2
	 .short 27 @ "tm case"
	.byte COMPARE
	 .short 0x8007
	 .short 1
	.byte IFGOSUB
	 .byte 1
	 .word Std_00_Jingle
	.byte RETURN

Std_00_Type5:
	.byte GETSTANDARD
	 .byte 2
	 .short 28 @ "berry pouch"
	.byte COMPARE
	 .short 0x8007
	 .short 1
	.byte IFGOSUB
	 .byte 1
	 .word Std_00_Jingle
	.byte RETURN

Std_00_Jingle:
	.byte JINGLE
	 .short 0x101
	.byte RETURN

