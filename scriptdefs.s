	.equ	NOP,		0x00	@ No parms ; Does nothing.

	.equ	END,		0x02	@ No parms ; Stop running the script and continue regular gameplay.
	.equ	RETURN,		0x03	@ No parms ; Returns to last stored position.
	.equ	CALL,		0x04	@ ptr target ; Stores current position and jumps to target.
	.equ	JUMP,		0x05	@ ptr target ; Jumps to target.
	.equ	IFGOTO,		0x06	@ u8 condition ptr target ; If the IfValue set by COMPARE and such matches the given value, jump to or call the target.
	.equ	IFGOSUB,	0x07	@ u8 condition ptr target ; If the IfValue set by COMPARE and such matches the given value, jump to or call the target.
	.equ	JUMPSTD,	0x08	@ u8 routine ; ...
	.equ	CALLSTD,	0x09	@ u8 routine ; ...
	.equ	JUMPSTDIF,	0x0A	@ u8 condition u8 routine ; ...
	.equ	CALLSTDIF,	0x0B	@ u8 condition u8 routine ; ...
	.equ	JUMPRAM,	0x0C	@ No parms ; ...
	.equ	KILLSCRIPT,	0x0D	@ No parms ; ...
	.equ	SETBYTE,	0x0E	@ u8 value ; ...
	.equ	LOADPOINTER,	0x0F	@ u8 bank str target ; ...
	.equ	SETBYTE2,	0x10	@ u8 value ; ...




	.equ	SETVAR,		0x16	@ u16 index u16 value ; Sets given variable in ScriptMemory to the given value.
	.equ	ADDVAR,		0x17	@ u16 index u16 value ; ...
	.equ	SUBVAR,		0x18	@ u16 index u16 value ; ...
	.equ	COPYVAR,	0x19	@ u16 index u16 index ; Copies values of the given variables from first to second.
	.equ	COPYVARIFNOT0,	0x1A	@ u16 index u16 index ; ...






	.equ	COMPARE,	0x21	@ u16 index u16 value ; Compare given variable in ScriptMemory to the given value and set IfFlag accordingly.



	.equ	SPECIAL,	0x25	@ u16 index ; Runs special event.
	.equ	SPECIAL2,	0x26	@ u16 index u16 index ; Runs special event.



	.equ	SETFLAG,	0x29	@ u16 index ; Sets given ScriptFlag.
	.equ	CLEARFLAG,	0x2A	@ u16 index ; Clears given ScriptFlag.
	.equ	CHECKFLAG,	0x2B	@ u16 index ; If given ScriptFlag is set, sets IfFlag to 1.


	.equ	RESETVARS,	0x2E	@ No parms ; ...
	.equ	PLAYSOUND,	0x2F	@ u16 index ; Plays specified music track.
	.equ	CHECKSOUND,	0x30	@ No parms ; ...
	.equ	JINGLE,		0x31	@ u8 index ; Plays specified jingle.



	.equ	FADETODEFAULT,	0x35	@ No parms ; ...
	.equ	FADETOSOUND,	0x36	@ u16 index ; Plays specified music track.


	.equ	WARP,		0x39	@ u16 target u16 x u16 y ; Warps to specified location.









	.equ	GETPARTYSIZE,	0x43	@ No parms ; ...
	.equ	GIVEITEM,	0x44	@ u16 index u16 amount ; Gives the player the specified item. Sets LastResult to 1 if there was no room.
	.equ	TAKEITEM,	0x45	@ u16 index u16 amount ; Takes specified item.
	.equ	CHECKITEMAMOUNT,	0x46	@ u16 index u16 amount ; ...

	.equ	CHECKITEMTYPE,	0x48	@ u16 index ; ...






	.equ	APPLYMOVE,	0x4F	@ u16 target ptr path ; Makes target walk along specified path.

	.equ	WAITFORMOVE,	0x51	@ u16 target ; Wait for target to stop walking.

	.equ	HIDESPRITE,	0x53	@ u16 target ; ...

	.equ	SHOWSPRITE,	0x55	@ u16 target ; ...




	.equ	FACEPLAYER,	0x5A	@ No parms ; Turns the calling person towards the player.

	.equ	TRAINERBATTLE,	0x5C	@ u16 index str intro str defeat str double ptr after ; TODO: expand



	.equ	CHECKTRAINER,	0x60	@ u16 index ; ...
	.equ	ENABLETRAINER,	0x61	@ u16 index ; ...
	.equ	DISABLETRAINER,	0x62	@ u16 index ; Sets the specified battle as "won". Good for gym leaders.



	.equ	WAITMSGBOX,	0x66	@ No parms ; ...
	.equ	MSGBOX2,	0x67	@ str text ; ...

	.equ	LOCKALL,	0x69	@ No parms ; Locks all movements.
	.equ	LOCK,		0x6A	@ No parms ; Locks player movement.
	.equ	RELEASEALL,	0x6B	@ No parms ; Unlocks all movements.
	.equ	RELEASE,	0x6C	@ No parms ; Unlocks player movement.
	.equ	WAITKEYPRESS,	0x6D	@ No parms ; ...
	.equ	YESNOBOX,	0x6E	@ u8 posx u8 posy ; ...






	.equ	SHOWMONSTERPIC,	0x75	@ u16 index u8 x u8 y ; Shows specified species in a window.
	.equ	HIDEMONSTERPIC,	0x76	@ No parms ; ...

	.equ	BRAILLE,	0x78	@ str text ; ...
	.equ	GIVEMONSTER,	0x79	@ u16 species u8 level ; Gives the player a Pokémon of the specified level and species if there's room in the party.






	.equ	GETITEMNAME,	0x80	@ u8 svar u16 index ; ...

	.equ	GETATTACKNAME,	0x82	@ u8 svar u16 index ; ...
	.equ	GETNUMBER,	0x83	@ u8 svar u16 index ; ...
	.equ	GETSTANDARD,	0x84	@ u8 svar u16 index ; ...
	.equ	GETSTRING,	0x85	@ u8 svar u16 index ; ...
	.equ	DOSHOP,		0x86	@ ptr inventory ; ...








	.equ	GETRANDOM,	0x8F	@ u16 max ; ...
	.equ	GIVEMONEY,	0xD8	@ u16 amount u8 i ; Increases the player's money.
	.equ	TAKEMONEY,	0xD9	@ u16 amount u8 i ; Decreases the player's money. Sets LastResult to 1 if the player doesn't have enough.





	.equ	FADE,		0x97	@ u8 inorout ; Fades out if 0, in if 1.







	.equ	SETRESPAWN,	0x9F	@ u8 index ; Sets respawn index.
	.equ	GETGENDER,	0xA0	@ No parms ; Returns gender of player in LastResult.

	.equ	SETMAPTILE,	0xA2	@ u8 x u8 y u16 index ; Sets the map tile on the specified coordinates. Good for INIT map scripts.
	.equ	SETWEATHER,	0xA4	@ u16 weather ; ...
	.equ	DOWEATHER,	0xA5	@ No parms ; ...






	.equ	TEXTCOLOR,	0xC7	@ u8 color ; ...


	.equ	MSGBOXSIGN,	0xCA	@ No parms ; ...
	.equ	MSGBOXNORMAL,	0xCB	@ No parms ; ...



	.equ	PHONE,		0xD5	@ u8 action u8 index ; Adds given phone number to list if action = 1, signals phone call if action = 0.
	.equ	GETTIME,	0xD6	@ u8 what ; Returns the given time in LastResult (0 for the time of day, 1 for the hours, 2 for the day of the week), and sets string var #7 to the same.
	.equ	REBUILDMAP,	0xD7	@ No parms ; ...
	.equ	BLACKMAP,	0xD8	@ No parms ; ...
	.equ	SETNICKNAME,	0xD9	@ u8 index ; Shows nickname entry screen for specified party index (1-6) or last available (0).
	.equ	SETSPRITE,	0xDA	@ u8 target u8 new ; Sets the target's sprite.
	.equ	SETTIMER,	0xDB	@ u16 time ptr target ; Sets a timer to run target script after specified time in seconds.
	.equ	CHECKBADGE,	0xDC	@ u8 index ; If index is 0, returns number of badges. If index is 1 to 8, returns 1 if you have that badge.
	.equ	GETNUMBERORDIN,	0xDD	@ u8 svar u16 index ; ...
	.equ	CHOICE,		0xDE	@ u8 index ; ...
	.equ	WARPTO,		0xDF	@ u16 map u16 index ; ...
	.equ	TITLECARD,	0xE1	@ u8 index ; ...
	
