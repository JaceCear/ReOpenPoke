#include "openpoke.h"

//--------------------------------------------------------//
// Section 2 - support routines, equally hand-decompiled  //
//--------------------------------------------------------//

void ShutDownRubikon(Script *script)
{
	script->State = 0;
	script->IP = 0;
}

void ScriptReturn(Script *script)
{
	script->IP = GetReturnAddress(script);
}

unsigned int ScriptCompare(int what, int with)
{
	     if(what <  with) return 0;
	else if(what == with) return 1;
	else if(what  > with) return 2;
	return 0;
}

unsigned int GetScriptWord(Script *script)
{
	unsigned int a, b, c, d;
	a = *script->IP++;
	b = *script->IP++;
	c = *script->IP++;
	d = *script->IP++;
	return d << 24 | c << 16 | b << 8 | a;
}

unsigned int GetScriptHWord(Script *script)
{
	unsigned int a, b;
	a = *script->IP++;
	b = *script->IP++;
	return b << 8 | a;
}

unsigned short * GetScriptVar(signed short index)
{
	if(index < 0)	return (unsigned short*)SystemVars[index + 0x8000];
	if(index < 0x4000) return 0;
	return &ScriptVars[index - 0x4000];
}

unsigned int GetScript___(signed short index)
{
	unsigned short * i = GetScriptVar(index);
	if(i == 0)
	{
		AGBPrintf("GetScript___: i = %x, returning val %d\n",i,index);
		return index;
	} else
	{
		AGBPrintf("GetScript__: i != %x, returning var value %d\n",i,*i);
		return *i;
	}
}

void ScriptGosub(Script *script, unsigned char * target)
{
	SetReturnAddress(script, script->IP);
	script->IP = target;
}

void ScriptGoto(Script *script, unsigned char * target)
{
	script->IP = target;
}

unsigned char * GetReturnAddress(Script *script)
{
	if(script->RetAdrCount == 0) return 0;
	return script->RetAdrs[script->RetAdrCount--];
}

int SetReturnAddress(Script *script, unsigned char * target)
{
	int newCount = script->RetAdrCount + 1;
	if(newCount > STACKSIZE) return 1;
	script->RetAdrs[newCount] = target;
	script->RetAdrCount = newCount;
	return 0;
}

void ScriptSetFlag(int flag)
{
	SETBIT(ScriptFlags, flag);
}

void ScriptClearFlag(int flag)
{
	CLRBIT(ScriptFlags, flag);
}

int ScriptCheckFlag(int flag)
{
	return GETBIT(ScriptFlags, flag);
}

void SetScriptGlobalPtr(Script *script, void * stuff)
{
	script->State = 2;
	script->GlobalPtr = stuff;
}

void ResetScript(Script * script, void * Commands, void * CommandsEnd)
{
	AGBPrintf("ResetScript\n");
	script->State = 0;
	script->IP = 0;
	script->RetAdrCount = 0;
	script->GlobalPtr = 0;
	script->Commands = Commands;
	script->CommandsEnd = CommandsEnd;

/*
ROM:080697BE                 MOVS    R2, #0          ; Rd = Op2
ROM:080697C0                 MOVS    R1, #3          ; Rd = Op2
ROM:080697C2                 ADDS    R0, R3, #0      ; Rd = Op1 + Op2
ROM:080697C4                 ADDS    R0, #0x70 ; 'p' ; Rd = Op1 + Op2

ROM:080697C6 loop                                    ; CODE XREF: ResetScript+22j
ROM:080697C6                 STR     R2, [R0]        ; Store to Memory
ROM:080697C8                 SUBS    R0, #4          ; Rd = Op1 - Op2
ROM:080697CA                 SUBS    R1, #1          ; Rd = Op1 - Op2
ROM:080697CC                 CMP     R1, #0          ; Set cond. codes on Op1 - Op2
ROM:080697CE                 BGE     loop            ; Branch

ROM:080697D0                 ADDS    R1, R3, #0      ; Rd = Op1 + Op2
ROM:080697D2                 ADDS    R1, #0xC        ; Rd = Op1 + Op2
ROM:080697D4                 MOVS    R2, #0          ; Rd = Op2
ROM:080697D6                 ADDS    R0, R3, #0      ; Rd = Op1 + Op2
ROM:080697D8                 ADDS    R0, #0x58 ; 'X' ; Rd = Op1 + Op2

ROM:080697DA loop2                                   ; CODE XREF: ResetScript+34j
ROM:080697DA                 STR     R2, [R0]        ; Store to Memory
ROM:080697DC                 SUBS    R0, #4          ; Rd = Op1 - Op2
ROM:080697DE                 CMP     R0, R1          ; Set cond. codes on Op1 - Op2
ROM:080697E0                 BGE     loop2           ; Branch

ROM:080697E2                 POP     {R0}            ; Pop Registers
ROM:080697E4                 BX      R0              ; Branch to/from Thumb mode
*/
}

int StartScriptWith(Script * script, unsigned char * newscript)
{
	AGBPrintf("StartScriptWith\n");
	script->IP = newscript;
	script->State = 1;
	return 1;
}

int GetScriptByte(Script * script)
{
	AGBPrintf("GetScriptByte: ");

	switch(script->State)
	{
	case 0:
		AGBPrintf("State 0, not going.\n");
		return 0;

	case 1:
		AGBPrintf("State 1 - ");
		break;

	case 2:
		AGBPrintf("State 2, global pointer? ");
		if(script->GlobalPtr)
		{
			int (*gf)(Script*) = script->GlobalPtr;
			if(gf(script) == 1)
			{
				AGBPrintf("Switching to state 1...\n");
				script->State = 1;
				break; //?
			}
			return 0; //1
		} else
		{
			AGBPrintf("No global pointer, fallback to state 1.\n");
			script->State = 1;
			break;
		}

	default:
		AGBPrintf("Impossible state %d, definately not going.\n", script->State);
	}

	AGBPrintf("Starting fetch quest...\n");

	while(1)
	{
		AGBPrintFlush1Block();
		if(script->IP == 0)
		{
			script->State = 0;
			return 0;
		} else
		{
			#ifndef NDEBUG
			int oldip = (int)script->IP;
			#endif
			int command = * script->IP++;
			if(command > COMMANDS)
			{
				script->State = 0;
				return 0;
			}
			if(command)
			{
				AGBPrintf("0x%X: [0x%02X] ", oldip, command);
				int (*func)(Script *script) = (void*)script->Commands[command];
				if(func)
				{
					if(func(script) == 1)
					{
						AGBPrintf("Switching to state 2...\n");
						script->State = 2;
						break;
					}
				}
				else
					AGBPrintf("---\n");
			}
		}
	}
	return 1;
}

void InitScriptEngine(unsigned char * newscript)
{
	extern u32 LockDown;

	AGBPrintf("InitScriptEngine\n");
	ResetScript((Script*)&MyScript, (void*)ScriptCommands, (void*)ScriptCommandsEnd);
	StartScriptWith((Script*)&MyScript, newscript);
	while(GetScriptByte((Script*)&MyScript) == 1);
	AGBPrintf("End of the script.\n");
	LockDown = 0;
	AGBPrintf("FYI, 0x800D is 0x%X.\n", ScriptVar_800D);
}

void ScriptLoop(unsigned char * newscript)
{
	InitScriptEngine(newscript);
}
