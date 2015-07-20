#include "openpoke.h"

#define STACKSIZE 13 // Maximum size of the call stack
#define COMMANDS 0xE1 // Total number of commands
#define STANDARDFUNCS 16 // Upper bound on the standard calls
#define SPECIALFUNCS 100 // Upper bound on the special calls
#define MAXVARS 0x1000

extern unsigned char StdMessage[];
extern unsigned char StdYesNoMessage[];
extern unsigned char StdItemBall[];

//extern void DoSpecialEvents(u16 index);
//extern u32 LockDown;
//extern u16 MapBuffer[] INEWRAM;
u8	ScriptFlags[288]; /**< \brief Bitfield used to hold all flags. 128 * 8 = 1024 individual flags. */
signed int	CallingPeople; /**< \brief Index of the person on the map who triggered the currently running script (if any) or -1 for "a sign". */

typedef struct Script
{
	unsigned char RetAdrCount; // Size of the call stack
	unsigned char State;
	//States: 0 - idle, 1 - ???, 2 - running
	unsigned char IfFlag; // Result of the last comparison

	void * GlobalPtr; // No idea what this is used for yet
	unsigned char * IP; // Instruction pointer
	unsigned char * RetAdrs[STACKSIZE]; // List of return addresses

	int * Commands;
	int * CommandsEnd;

	void * LoadedPointer;
	int GlobalParams[16];
} Script;

extern Script MyScript;

extern const unsigned char TruthTable[18];
extern const void * const ScriptCommands[];
extern const void * const ScriptCommandsEnd;
extern const unsigned char * const StandardFuncs[];
extern const void * const SpecialFuncs[];
extern unsigned short ScriptVars[MAXVARS] INEWRAM;
extern const unsigned short * const SystemVars[];
extern unsigned short ScriptVar_8000, ScriptVar_8001, ScriptVar_8002, ScriptVar_8003;
extern unsigned short ScriptVar_8004, ScriptVar_8005, ScriptVar_8006, ScriptVar_8007;
extern unsigned short ScriptVar_8008, ScriptVar_8009, ScriptVar_800A, ScriptVar_800B;
extern unsigned short ScriptVar_800C, ScriptVar_800D, ScriptVar_800E, ScriptVar_800F;
extern unsigned short ScriptVar_8010, ScriptVar_8011, ScriptVar_8012, ScriptVar_8013;
extern unsigned short ScriptVar_8014;

extern void ShutDownRubikon(Script *script);
extern void ScriptReturn(Script *script);
extern unsigned int ScriptCompare(int what, int with);
extern unsigned int GetScriptWord(Script *script);
extern unsigned int GetScriptHWord(Script *script);
extern unsigned short * GetScriptVar(signed short index);
extern unsigned int GetScript___(signed short index);
extern void ScriptGosub(Script *script, unsigned char * target);
extern void ScriptGoto(Script *script, unsigned char * target);
extern unsigned char * GetReturnAddress(Script *script);
extern int SetReturnAddress(Script *script, unsigned char * target);
extern void ScriptSetFlag(int flag);
extern void ScriptClearFlag(int flag);
extern int ScriptCheckFlag(int flag);
extern void SetScriptGlobalPtr(Script *script, void * stuff);
extern void InitScriptEngine(unsigned char * newscript);



#define JDEF(x) extern int x (Script *script);
JDEF(Script_NOP);
JDEF(Script_END);
JDEF(Script_RETURN);
JDEF(Script_CALL);
JDEF(Script_GOTO);
JDEF(Script_IFGOTO);
JDEF(Script_IFCALL);
JDEF(Script_JUMPSTD);
JDEF(Script_CALLSTD);
JDEF(Script_JUMPSTDIF);
JDEF(Script_CALLSTDIF);
JDEF(Script_JUMPRAM);
JDEF(Script_KILLSCRIPT);
JDEF(Script_SETBYTE);
JDEF(Script_LOADPOINTER);
JDEF(Script_SETBYTE2);
JDEF(Script_WRITEBYTETOOFFSET);
JDEF(Script_LOADBYTEFROMPOINTER);
JDEF(Script_SETFARBYTE);
JDEF(Script_COPYSCRIPTBANKS);
JDEF(Script_COPYBYTE);
JDEF(Script_SETVAR);
JDEF(Script_ADDVAR);
JDEF(Script_SUBVAR);
JDEF(Script_COPYVAR);
JDEF(Script_COPYVARIFNOTZERO);
JDEF(Script_COMPAREVARS);
JDEF(Script_COMPAREVARTOBYTE);
JDEF(Script_COMPAREVARTOFARBYTE);
JDEF(Script_COMPAREFARBYTETOVAR);
JDEF(Script_COMPAREFARBYTETOBYTE);
JDEF(Script_COMPAREFARBYTETOFARBYTE);
JDEF(Script_COMPARE);
JDEF(Script_COMPAREVARS2);
JDEF(Script_CALLASM);
JDEF(Script_SETGLOBALPTR);
JDEF(Script_SPECIAL);
JDEF(Script_SPECIAL2);
JDEF(Script_WAITSTATE);
JDEF(Script_PAUSE);
JDEF(Script_SETFLAG);
JDEF(Script_CLEARFLAG);
JDEF(Script_CHECKFLAG);
JDEF(Script_RESETVARS);
JDEF(Script_SOUND);
JDEF(Script_CHECKSOUND);
JDEF(Script_FANFARE);
JDEF(Script_WAITFANFARE);
JDEF(Script_PLAYSONG);
JDEF(Script_PLAYSONG2);
JDEF(Script_FADEDEFAULT);
JDEF(Script_FADESONG);
JDEF(Script_FADEOUT);
JDEF(Script_FADEIN);
JDEF(Script_WARP);
JDEF(Script_WARP2);
JDEF(Script_WARPWALK);
JDEF(Script_WARPTELEPORT);
JDEF(Script_WARP3);
JDEF(Script_WARPELEVATOR);
JDEF(Script_WARP4);
JDEF(Script_WARP5);
JDEF(Script_GETPLAYERPOS);
JDEF(Script_COUNTPOKEMON);
JDEF(Script_ADDITEM);
JDEF(Script_REMOVEITEM);

JDEF(Script_CHECKITEMAMOUNT);
JDEF(Script_CHECKITEM);
JDEF(Script_CHECKITEMTYPE);

JDEF(Script_APPLYMOVEMENT);
JDEF(Script_WAITMOVEMENT);
JDEF(Script_HIDESPRITE);
JDEF(Script_SHOWSPRITE);
JDEF(Script_FACEPLAYER);
JDEF(Script_TRAINERBATTLE);
JDEF(Script_GETTRAINERFLAG);
JDEF(Script_CLEARTRAINERFLAG);
JDEF(Script_SETTRAINERFLAG);
JDEF(Script_WAITMSGBOX);
JDEF(Script_MSGBOX2);
JDEF(Script_LOCK);
JDEF(Script_RELEASE);
JDEF(Script_WAITKEYPRESS);
JDEF(Script_YESNOBOX);
JDEF(Script_SHOWPOKEPIC);
JDEF(Script_HIDEPOKEPIC);
JDEF(Script_BRAILLE);
JDEF(Script_GIVEPOKEMON);
JDEF(Script_BUFFERITEM);
JDEF(Script_BUFFERATTACK);
JDEF(Script_BUFFERNUMBER);
JDEF(Script_BUFFERSTANDARD);
JDEF(Script_BUFFERSTRING);
JDEF(Script_MART);
JDEF(Script_GETRANDOM);
JDEF(Script_GIVEMONEY);
JDEF(Script_PAYMONEY);
JDEF(Script_FADESCREEN);
JDEF(Script_SETHEALINGPLACE);
JDEF(Script_CHECKGENDER);
JDEF(Script_SETMAPTILE);
JDEF(Script_SETWEATHER);
JDEF(Script_DOWEATHER);
JDEF(Script_TEXTCOLOR);
JDEF(Script_MSGBOXSIGN);
JDEF(Script_MSGBOXNORMAL);

JDEF(Script_PHONE);
JDEF(Script_GETTIME);
JDEF(Script_REBUILDMAP);
JDEF(Script_BLACKMAP);
JDEF(Script_SETNICKNAME);
JDEF(Script_SETSPRITE);
JDEF(Script_SETTIMER);
JDEF(Script_CHECKBADGE);
JDEF(Script_BUFFERNUMBERORDINAL);
JDEF(Script_CHOICE);
JDEF(Script_WARPTO);
JDEF(Script_TITLECARD);

#undef JDEF
#define JDEF(x) extern void x ();
JDEF(Spec_GetPartySize);
JDEF(Spec_HealSilently);
JDEF(Spec_HealCenter);
JDEF(SetupApartment);
JDEF(Spec_DexRating);
JDEF(Spec_GetDaycareNames);
#undef JDEF
