#include "openpoke.h"

//--------------------------------------------------------//
// Section 3 - tables of things                           //
//--------------------------------------------------------//

Script MyScript;

// This truth table is used by the conditional commands.
const unsigned char TruthTable[18] =
{
//< = >
	1,0,0, // <
	0,1,0, // ==
	0,0,1, // >
	1,1,0, // <=
	0,1,1, // =>
	1,0,1, // !=
};

// This is basically just a huge list of command pointers.
const void * const ScriptCommands[] =
{
	0, //Script_NOP,
	0, //Script_NOP1,
	Script_END,
	Script_RETURN,
	Script_CALL,
	Script_GOTO,
	Script_IFGOTO,
	Script_IFCALL,
	Script_JUMPSTD,
	Script_CALLSTD,
	Script_JUMPSTDIF,
	Script_CALLSTDIF,
	Script_JUMPRAM,
	Script_KILLSCRIPT,
	Script_SETBYTE,
	Script_LOADPOINTER,
	Script_SETBYTE2,
	Script_WRITEBYTETOOFFSET,
	Script_LOADBYTEFROMPOINTER,
	Script_SETFARBYTE,
	Script_COPYSCRIPTBANKS,
	Script_COPYBYTE,
	Script_SETVAR,
	Script_ADDVAR,
	Script_SUBVAR,
	Script_COPYVAR,
	Script_COPYVARIFNOTZERO,
	Script_COMPAREVARS,
	Script_COMPAREVARTOBYTE,
	Script_COMPAREVARTOFARBYTE,
	Script_COMPAREFARBYTETOVAR,
	Script_COMPAREFARBYTETOBYTE,
	Script_COMPAREFARBYTETOFARBYTE,
	Script_COMPARE,
	Script_COMPAREVARS2,
	Script_CALLASM,
	Script_CALLASM, //Script_CALLASM2,
	Script_SPECIAL,
	Script_SPECIAL2,
	Script_WAITSTATE,
	Script_PAUSE,
	Script_SETFLAG,
	Script_CLEARFLAG,
	Script_CHECKFLAG,
	0, // 0x2C	dummy
	0, // 0x2D	dummy
	Script_RESETVARS,
	Script_SOUND,
	Script_CHECKSOUND,
	Script_FANFARE,
	Script_WAITFANFARE,
	Script_PLAYSONG,
	Script_PLAYSONG2,
	Script_FADEDEFAULT,
	Script_FADESONG,
	Script_FADEOUT,
	Script_FADEIN,
	Script_WARP,
	Script_WARP2,
	Script_WARPWALK,
	0, // 0x3C	WARPHOLE
	Script_WARPTELEPORT,
	Script_WARP3,
	Script_WARPELEVATOR,
	Script_WARP4,
	Script_WARP5,
	Script_GETPLAYERPOS,
	Script_COUNTPOKEMON,
	Script_ADDITEM,
	Script_REMOVEITEM,
	Script_CHECKITEMAMOUNT,
	Script_CHECKITEM,
	Script_CHECKITEMTYPE,

	0, // 0x49	ADDPCITEM
	0, // 0x4A	CHECKPCITEM
	0, // 0x4B	dummy
	0, // 0x4C	dummy
	0, // 0x4D	dummy
	0, // 0x4E	dummy
	Script_APPLYMOVEMENT,
	0, // 0x50	APPLYMOVEMENT2
	Script_WAITMOVEMENT,
	0, // 0x52	WAITMOVEMENT2
	Script_HIDESPRITE,
	0, // 0x54	HIDESPRITE2
	Script_SHOWSPRITE,
	0, // 0x56	SHOWSPRITE2
	0, // 0x57	MOVESPRITE
	0, // 0x58	SPRITEVISIBLE
	0, // 0x59	SPRITEINVISIBLE
	Script_FACEPLAYER,
	0, // 0x5B	SPRITEFACE
	Script_TRAINERBATTLE,
	0, // 0x5D	REPEATTRAINERBATTLE
	0, // 0x5E	ENDTRAINERBATTLE
	0, // 0x5F	ENDTRAINERBATTLE2
	Script_GETTRAINERFLAG,
	Script_CLEARTRAINERFLAG,
	Script_SETTRAINERFLAG,
	0, // 0x63	MOVESPRITE2
	0, // 0x64	MOVEOFFSCREEN
	0, // 0x65	SPRITEBEHAVE
	Script_WAITMSGBOX,
	Script_MSGBOX2,
	0, // 0x68	CLOSEONKEYPRESS
	0, // 0x69	LOCKALL
	Script_LOCK,
	0, // 0x6B	RELEASEALL
	Script_RELEASE,
	Script_WAITKEYPRESS,
	Script_YESNOBOX,
	0, // 0x6F	MULTICHOICE
	0, // 0x70	MULTICHOICE2
	0, // 0x71	MULTICHOICE3
	0, // 0x72	dummy
	0, // 0x73	dummy
	0, // 0x74	dummy
	Script_SHOWPOKEPIC,
	Script_HIDEPOKEPIC,
	0, // 0x77	dummy
	Script_BRAILLE,
	Script_GIVEPOKEMON,
	0, // 0x7A	GIVEEGG
	0, // 0x7B	SETPOKEMONPP
	0, // 0x7C	CHECKATTACK
	0, // 0x7D	BUFFERPOKEMON
	0, // 0x7E	BUFFERFIRSTPOKEMON
	0, // 0x7F	BUFFERPOKEMON2
	Script_BUFFERITEM,
	0, // 0x81	dummy
	Script_BUFFERATTACK,
	Script_BUFFERNUMBER,
	Script_BUFFERSTANDARD,
	Script_BUFFERSTRING,
	Script_MART,
	0, // 0x87	MART2
	0, // 0x88	MART3
	0, // 0x89	CASINO
	0, // 0x8A	dummy
	0, // 0x8B	CHOOSECONTESTPKMN
	0, // 0x8C	dummy
	0, // 0x8D	dummy
	0, // 0x8E	dummy
	Script_GETRANDOM,
	Script_GIVEMONEY,
	Script_PAYMONEY,
	0, // 0x92	CHECKMONEY
	0, // 0x93	SHOWMONEY
	0, // 0x94	HIDEMONEY
	0, // 0x95	UPDATEMONEY
	0, // 0x96	dummy
	Script_FADESCREEN,
	0, // 0x98	FADESCREEN2
	0, // 0x99	DARKEN
	0, // 0x9A	LIGHTEN
	0, // 0x9B	MSGBOX3
	0, // 0x9C	DOANIMATION
	0, // 0x9D	SETANIMATION
	0, // 0x9E	CHECKANIMATION
	Script_SETHEALINGPLACE,
	Script_CHECKGENDER,
	0, // 0xA1	CRY
	Script_SETMAPTILE,
	0, // 0xA3	RESETWEATHER
	Script_SETWEATHER,
	Script_DOWEATHER,
	0, // 0xA6
	0, // 0xA7	SETMAPFOOTER
	0, // 0xA8	SPRITELEVELUP
	0, // 0xA9	RESTORESPRITELEVEL
	0, // 0xAA	CREATESPRITE
	0, // 0xAB	SPRITEFACE2
	0, // 0xAC	SETDOOROPENED
	0, // 0xAD	SETDOORCLOSED
	0, // 0xAE	DOORCHANGE
	0, // 0xAF	SETDOOROPENED2
	0, // 0xB0	SETDOORCLOSED2
	0, // 0xB1	dummy
	0, // 0xB2	dummy
	0, // 0xB3	CHECKCOINS
	0, // 0xB4	GIVECOINS
	0, // 0xB5	REMOVECOINS
	0, // 0xB6	STARTWILDBATTLE
	0, // 0xB7	REPEATWILDBATTLE
	0, // 0xB8	SETVIRTUALADDRESS
	0, // 0xB9	VIRTUALJUMP
	0, // 0xBA	VIRTUALCALL
	0, // 0xBB	VIRTUALJUMPIF
	0, // 0xBC	VIRTUALCALLIF
	0, // 0xBD	VIRTUALMSGBOX
	0, // 0xBE	VIRTUALLOADPOINTER
	0, // 0xBF	VIRTUALBUFFER
	0, // 0xC0	SHOWCOINS
	0, // 0xC1	HIDECOINS
	0, // 0xC2	UPDATECOINS
	0, // 0xC3
	0, // 0xC4	WARP6
	0, // 0xC5	WAITCRY
	0, // 0xC6	BUFFERBOXNAME
	Script_TEXTCOLOR,
	0, // 0xC8
	0, // 0xC9
	Script_MSGBOXSIGN,
	Script_MSGBOXNORMAL,
	0, // 0xCC	COMPAREHIDDENVAR
	0, // 0xCD	SETOBEDIENCE
	0, // 0xCE	CHECKOBEDIENCE
	0, // 0xCF	EXECUTERAM
	0, // 0xD0	SETWORLDMAPFLAG
	0, // 0xD1	WARPTELEPORT2
	0, // 0xD2	SETCATCHLOCATION
	0, // 0xD3	BRAILLE2
	0, // 0xD4	BUFFERITEMS

	Script_PHONE, //0xD5
	Script_GETTIME, //0xD6
	Script_REBUILDMAP, //0xD7
	Script_BLACKMAP, //0xD8
	Script_SETNICKNAME, //0xD9
	Script_SETSPRITE, //0xDA
	Script_SETTIMER, //0xDB
	Script_CHECKBADGE, //0xDC
	Script_BUFFERNUMBERORDINAL, //0xDD
	Script_CHOICE, //0xDE
	Script_WARPTO, //0xDF
	0, //0xE0  used to be TURRETBATTLE but I removed that for the rerelease -- KAWA
	Script_TITLECARD, //0xE1
};
const void * const ScriptCommandsEnd = Script_NOP;

const unsigned char * const StandardFuncs[] =
{
	0,
	StdItemBall,
	0,
	0,
	StdMessage,
	StdYesNoMessage,
	0,
	0,
	0,
	0,
};


unsigned short ScriptVar_8000, ScriptVar_8001, ScriptVar_8002, ScriptVar_8003;
unsigned short ScriptVar_8004, ScriptVar_8005, ScriptVar_8006, ScriptVar_8007;
unsigned short ScriptVar_8008, ScriptVar_8009, ScriptVar_800A, ScriptVar_800B;
unsigned short ScriptVar_800C, ScriptVar_800D, ScriptVar_800E, ScriptVar_800F;
unsigned short ScriptVar_8010, ScriptVar_8011, ScriptVar_8012, ScriptVar_8013;
unsigned short ScriptVar_8014;

unsigned short ScriptVars[MAXVARS] INEWRAM;
const unsigned short * const SystemVars[] =
{
	&ScriptVar_8000,
	&ScriptVar_8001,
	&ScriptVar_8002,
	&ScriptVar_8003,
	&ScriptVar_8004,
	&ScriptVar_8005,
	&ScriptVar_8006,
	&ScriptVar_8007,
	&ScriptVar_8008,
	&ScriptVar_8009,
	&ScriptVar_800A,
	&ScriptVar_800B,
	&ScriptVar_800C,
	&ScriptVar_800D,
	&ScriptVar_800E,
	&ScriptVar_800F,
	&ScriptVar_8010,
	&ScriptVar_8011,
	&ScriptVar_8012,
	&ScriptVar_8013,
	&ScriptVar_8014,
};

const void * const SpecialFuncs[] =
{
	0,
	Spec_GetPartySize,
	Spec_HealSilently,
	Spec_HealCenter,
	SetupApartment,
	Spec_DexRating,
	Spec_GetDaycareNames,
};
