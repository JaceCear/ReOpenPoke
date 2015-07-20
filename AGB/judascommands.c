#include "openpoke.h"

void DoSpecialEvents(u16 index);

extern u32 LockDown;
extern u16 MapBuffer[] INEWRAM;

//--------------------------------------------------------//
// Section 1 - actual, hand-decompiled script commands    //
//--------------------------------------------------------//

int Script_NOP(Script *script)
{
	AGBPrintf("NOP\n");
	return 0;
}

int Script_END(Script *script)
{
	AGBPrintf("END\n");
	ShutDownRubikon(script);
	return 0;
}

int Script_RETURN(Script *script)
{
	AGBPrintf("RETURN\n");
	ScriptReturn(script);
	return 0;
}

int Script_CALL(Script *script)
{
	int target = GetScriptWord(script);
	AGBPrintf("CALL 0x%X\n",target);
	ScriptGosub(script, (unsigned char*)target);
	return 0;
}

int Script_GOTO(Script *script)
{
	int target = GetScriptWord(script);
	AGBPrintf("GOTO 0x%X\n",target);
	ScriptGoto(script, (unsigned char*)target);
	return 0;
}

int Script_IFGOTO(Script *script)
{
	int ifval = *script->IP++;
	int target = GetScriptWord(script);
	AGBPrintf("IFGOTO %d 0x%X\n",ifval,target);
	if(!TruthTable[3 * ifval + script->IfFlag]) return 0;
	ScriptGoto(script, (unsigned char*)target);
	return 0;
}

int Script_IFCALL(Script *script)
{
	int ifval = *script->IP++;
	int target = GetScriptWord(script);
	AGBPrintf("IFCALL %d 0x%X\n",ifval,target);
	if(!TruthTable[3 * ifval + script->IfFlag]) return 0;
	ScriptGosub(script, (unsigned char*)target);
	return 0;
}

int Script_JUMPSTD(Script *script)
{
	int func = *script->IP++;
	AGBPrintf("JUMPSTD %d\n",func);
	if(func > STANDARDFUNCS) return 0;

	//SM_Dialoguebox.style = func; //HACK

	ScriptGoto(script, (unsigned char*)StandardFuncs[func]);
	return 0;
}

int Script_CALLSTD(Script *script)
{
	int func = *script->IP++;
	AGBPrintf("CALLSTD %d\n",func);
	if(func > STANDARDFUNCS) return 0;

	//SM_Dialoguebox.boxset = func; //HACK

	ScriptGosub(script, (unsigned char*)StandardFuncs[func]);
	return 0;
}

int Script_JUMPSTDIF(Script *script)
{
	int ifval = *script->IP++;
	int func = *script->IP++;
	AGBPrintf("JUMPSTDIF %d %d\n",ifval,func);
	if(!TruthTable[3 * ifval + script->IfFlag]) return 0;
	if(func > STANDARDFUNCS) return 0;
	ScriptGoto(script, (unsigned char*)StandardFuncs[func]);
	return 0;
}

int Script_CALLSTDIF(Script *script)
{
	int ifval = *script->IP++;
	int func = *script->IP++;
	AGBPrintf("CALLSTDIF %d %d\n",ifval,func);
	if(!TruthTable[3 * ifval + script->IfFlag]) return 0;
	if(func > STANDARDFUNCS) return 0;
	ScriptGosub(script, (unsigned char*)StandardFuncs[func]);
	return 0;
}

int Script_JUMPRAM(Script *script)
{
	// Because we don't know what's at offset 0x20370A4 yet,
	// the actual use of this function is foggy. But it
	// basically just reads whatever pointer is found there
	// and calls ScriptGoto on it. So without further ado:
	// ScriptGoto(script, (unsigned char*)off_20370A4);
	AGBPrintf("JUMPRAM ***DUMMY***\n");
	return 0;
}

int Script_KILLSCRIPT(Script *script)
{
	AGBPrintf("KILLSCRIPT\n");
	//sub_8069CD4(...);
	ShutDownRubikon(script);
	return 0;
}

int Script_SETBYTE(Script *script)
{
	int i = *script->IP++;
	AGBPrintf("SETBYTE %d ***DUMMY***\n",i);
	//sub_80DA8E8(...);
	return 0;
}

int Script_LOADPOINTER(Script *script)
{
	int r5 = *script->IP++;
	unsigned char * j = (unsigned char*)GetScriptWord(script);
	AGBPrintf("LOADPOINTER %d 0x%X\n",r5,j);
	//(int*)(script + (r5 * 4 * 64)) = j;
	//SneakyPointerHack = j;
	script->LoadedPointer = j;
	return 0;
}

int Script_SETBYTE2(Script *script)
{
	int i = *script->IP++;
	AGBPrintf("SETBYTE2 %d ***DUMMY***\n",i);
	return 0;
}

int Script_WRITEBYTETOOFFSET(Script *script)
{
	int i = *script->IP++;
	unsigned char * j = (unsigned char*)GetScriptWord(script);
	AGBPrintf("WRITEBYTETOOFFSET %d 0x%X\n",i,j);
	*j = i;
	return 0;
}

int Script_LOADBYTEFROMPOINTER(Script *script)
{
	int i = *script->IP++;
	int j = GetScriptWord(script);
	AGBPrintf("LOADBYTEFROMPOINTER %d 0x%X ***DUMMY***\n",i,j);
	return 0;
}

int Script_SETFARBYTE(Script *script)
{
	int i = *script->IP++;
	int j = GetScriptWord(script);
	AGBPrintf("SETFARBYTE %d 0x%X ***DUMMY***\n",i,j);
	return 0;
}

int Script_COPYSCRIPTBANKS(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	AGBPrintf("COPYSCRIPTBANKS %d %d ***DUMMY***\n",i,j);
	return 0;
}

int Script_COPYBYTE(Script *script)
{
	unsigned char * r5 = (unsigned char*)GetScriptWord(script);
	unsigned char * r0 = (unsigned char*)GetScriptWord(script);
	AGBPrintf("COPYBYTE 0x%X 0x%X\n",r5,r0);
	*r5 = *r0;
	return 0;
}

int Script_SETVAR(Script *script)
{
	unsigned short * var = GetScriptVar(GetScriptHWord(script));
	unsigned short val = GetScriptHWord(script);
	AGBPrintf("SETVAR 0x%X 0x%X\n",var,val);
	*var = val;
	AGBPrintf("Variable 0x%X is now 0x%X.\n", var, *var);
	return 0;
}

int Script_ADDVAR(Script *script)
{
	unsigned short * var = GetScriptVar(GetScriptHWord(script));
	unsigned short val = GetScript___(GetScriptHWord(script));
	AGBPrintf("ADDVAR 0x%X 0x%X\n",var,val);
	*var += val;
	AGBPrintf("Variable 0x%X is now 0x%X.\n", var, *var);
	return 0;
}


int Script_SUBVAR(Script *script)
{
	unsigned short * var = GetScriptVar(GetScriptHWord(script));
	unsigned short val = GetScript___(GetScriptHWord(script));
	AGBPrintf("SUBVAR 0x%X 0x%X\n",var,val);
	*var -= val;
	AGBPrintf("Variable 0x%X is now 0x%X.\n", var, *var);
	return 0;
}

int Script_COPYVAR(Script *script)
{
	unsigned short * to = GetScriptVar(GetScriptHWord(script));
	unsigned short * fr = GetScriptVar(GetScriptHWord(script));
	AGBPrintf("COPYVAR 0x%X 0x%X\n",fr,to);
	*to = *fr;
	AGBPrintf("Variable 0x%X is now 0x%X.\n", to, *to);
	return 0;
}

int Script_COPYVARIFNOTZERO(Script *script)
{
	unsigned short * var = GetScriptVar(GetScriptHWord(script));
	int val = GetScript___(GetScriptHWord(script));
	//unsigned short * fr = GetScriptVar(GetScriptHWord(script));
	AGBPrintf("COPYVARIFNOTZERO 0x%X 0x%X\n",var,val);
	*var = val;
	//if(*fr) *to = *fr;
	//else AGBPrintf("Variable 0x%X is 0x%X - not copying.\n", fr, *fr);
	AGBPrintf("Variable 0x%X is now 0x%X.\n", var, *var);
	return 0;
}

int Script_COMPAREVARS(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	AGBPrintf("COMPAREVARS %d %d ***DUMMY***\n",i,j);
	return 0;
}

int Script_COMPAREVARTOBYTE(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	AGBPrintf("COMPAREVARTOBYTE %d %d ***DUMMY***\n",i,j);
	return 0;
}

int Script_COMPAREVARTOFARBYTE(Script *script)
{
	int i = *script->IP++;
	unsigned char * j = (unsigned char*)GetScriptWord(script);
	AGBPrintf("COMPAREVARTOFARBYTE %d 0x%X\n",i,j);
	script->IfFlag = ScriptCompare(i,*j);
	return 0;
/*
ROM:0806A484 Script_COMPAREVARTOFARBYTE              ; DATA XREF: ROM:RubikonTableo
ROM:0806A484                 PUSH    {R4,R5,LR}      ; Push Registers
ROM:0806A486                 ADDS    R4, R0, #0      ; Rd = Op1 + Op2
ROM:0806A488                 LDR     R2, [R4,#sScriptMem.IP] ; Load from Memory
ROM:0806A48A                 LDRB    R1, [R2]        ; Load from Memory
ROM:0806A48C                 LSLS    R1, R1, #2      ; Logical Shift Left
ROM:0806A48E                 ADDS    R0, #100        ; Rd = Op1 + Op2
ROM:0806A490                 ADDS    R0, R0, R1      ; Rd = Op1 + Op2
ROM:0806A492                 LDRB    R5, [R0]        ; Load from Memory
ROM:0806A494                 ADDS    R2, #1          ; Rd = Op1 + Op2
ROM:0806A496                 STR     R2, [R4,#sScriptMem.IP] ; Store to Memory
ROM:0806A498                 ADDS    R0, R4, #0      ; Rd = Op1 + Op2
ROM:0806A49A                 BL      GetScriptWord   ; Branch with Link
ROM:0806A49A
ROM:0806A49E                 LDRB    R1, [R0]        ; Load from Memory
ROM:0806A4A0                 ADDS    R0, R5, #0      ; Rd = Op1 + Op2
ROM:0806A4A2                 BL      ScriptCompare   ; Branch with Link
ROM:0806A4A2
ROM:0806A4A6                 STRB    R0, [R4,#sScriptMem.IfFlag] ; Store to Memory
ROM:0806A4A8                 MOVS    R0, #0          ; Rd = Op2
ROM:0806A4AA                 POP     {R4,R5}         ; Pop Registers
ROM:0806A4AC                 POP     {R1}            ; Pop Registers
ROM:0806A4AE                 BX      R1              ; Branch to/from Thumb mode
ROM:0806A4AE
ROM:0806A4AE ; End of function Script_CMP_BYTE
*/
}

int Script_COMPAREFARBYTETOVAR(Script *script)
{
	int i = *script->IP++;
	unsigned char * j = (unsigned char*)GetScriptWord(script);
	AGBPrintf("COMPAREFARBYTETOVAR %d 0x%X\n",i,j);
	script->IfFlag = ScriptCompare(i,*j);
	return 0;
/*
ROM:0806A4B0 Script_COMPAREFARBYTETOVAR              ; DATA XREF: ROM:RubikonTableo
ROM:0806A4B0                 PUSH    {R4,LR}         ; Push Registers
ROM:0806A4B2                 ADDS    R4, R0, #0      ; Rd = Op1 + Op2
ROM:0806A4B4                 BL      GetScriptWord   ; Branch with Link
ROM:0806A4B4
ROM:0806A4B8                 LDRB    R0, [R0]        ; Load from Memory
ROM:0806A4BA                 LDR     R3, [R4,#sScriptMem.IP] ; Load from Memory
ROM:0806A4BC                 LDRB    R2, [R3]        ; Load from Memory
ROM:0806A4BE                 LSLS    R2, R2, #2      ; Logical Shift Left
ROM:0806A4C0                 ADDS    R1, R4, #0      ; Rd = Op1 + Op2
ROM:0806A4C2                 ADDS    R1, #0x64 ; 'd' ; Rd = Op1 + Op2
ROM:0806A4C4                 ADDS    R1, R1, R2      ; Rd = Op1 + Op2
ROM:0806A4C6                 LDRB    R1, [R1]        ; Load from Memory
ROM:0806A4C8                 ADDS    R3, #1          ; Rd = Op1 + Op2
ROM:0806A4CA                 STR     R3, [R4,#sScriptMem.IP] ; Store to Memory
ROM:0806A4CC                 BL      ScriptCompare   ; Branch with Link
ROM:0806A4CC
ROM:0806A4D0                 STRB    R0, [R4,#sScriptMem.IfFlag] ; Store to Memory
ROM:0806A4D2                 MOVS    R0, #0          ; Rd = Op2
ROM:0806A4D4                 POP     {R4}            ; Pop Registers
ROM:0806A4D6                 POP     {R1}            ; Pop Registers
ROM:0806A4D8                 BX      R1              ; Branch to/from Thumb mode
ROM:0806A4D8
ROM:0806A4D8 ; End of function Script_CMP_BYTE2
*/
}

int Script_COMPAREFARBYTETOBYTE(Script *script)
{
	unsigned char * i = (unsigned char*)GetScriptWord(script);
	int j = *script->IP++;
	AGBPrintf("COMPAREFARBYTETOBYTE 0x%X %d\n",i,j);
	script->IfFlag = ScriptCompare(*i,j);
	return 0;
}

int Script_COMPAREFARBYTETOFARBYTE(Script *script)
{
	unsigned char * i = (unsigned char*)GetScriptWord(script);
	unsigned char * j = (unsigned char*)GetScriptWord(script);
	AGBPrintf("COMPAREFARBYTETOFARBYTE 0x%X 0x%X\n",i,j);
	script->IfFlag = ScriptCompare(*i,*j);
	return 0;
}

int Script_COMPARE(Script *script)
{
	unsigned short * var = GetScriptVar(GetScriptHWord(script));
	unsigned short val = GetScriptHWord(script);
	AGBPrintf("COMPARE 0x%X 0x%X\n",var,val);
	script->IfFlag = ScriptCompare(*var,val);
	return 0;
}

int Script_COMPAREVARS2(Script *script)
{
	unsigned short * var1 = GetScriptVar(GetScriptHWord(script));
	unsigned short * var2 = GetScriptVar(GetScriptHWord(script));
	AGBPrintf("COMPAREVARS2 0x%X 0x%X\n",var1,var2);
	script->IfFlag = ScriptCompare(*var1,*var2);
	return 0;
}

int Script_CALLASM(Script *script)
{
	void * i = (void*)GetScriptWord(script);
	AGBPrintf("CALLASM 0x%X ***DUMMY***\n",i);
	return 0;
/*
ROM:08069F94 Script_CALLASM                          ; DATA XREF: ROM:RubikonTableo
ROM:08069F94                 PUSH    {LR}            ; Push Registers
ROM:08069F96                 BL      GetScriptWord   ; Branch with Link
ROM:08069F96
ROM:08069F9A                 BL      BranchAnywhere  ; Branch with Link
ROM:08069F9A
ROM:08069F9E                 MOVS    R0, #0          ; Rd = Op2
ROM:08069FA0                 POP     {R1}            ; Pop Registers
ROM:08069FA2                 BX      R1              ; Branch to/from Thumb mode
ROM:08069FA2
ROM:08069FA2 ; End of function Script_CALLASM
*/
}

int Script_SETGLOBALPTR(Script *script)
{
	void * newptr = (void*)GetScriptWord(script);
	AGBPrintf("SETGLOBALPTR 0x%X\n", newptr);
	SetScriptGlobalPtr(script, newptr);
	return 1;
}

int Script_SPECIAL(Script *script)
{
	int func = GetScriptHWord(script);
	AGBPrintf("SPECIAL %d\n",func);
	if(func > SPECIALFUNCS) return 0;
	int (*spec)(void) = SpecialFuncs[func];
	if(spec) spec();
	return 0;
}

int Script_SPECIAL2(Script *script)
{
	unsigned short * var = GetScriptVar(GetScriptHWord(script));
	int func = GetScriptHWord(script);
	AGBPrintf("SPECIAL2 0x%X %d\n",var,func);
	if(func > SPECIALFUNCS) return 0;
	int (*spec)(unsigned short*) = SpecialFuncs[func];
	if(spec) spec(var);
	return 0;
}

int Script_WAITSTATE(Script *script)
{
	AGBPrintf("WAITSTATE ***DUMMY***\n");
	//sub_8069B28();
	return 1;
}

int Script_PAUSE(Script *script)
{
	short i = GetScriptHWord(script);
	AGBPrintf("PAUSE %d\n", i);
//	WaitTimer = i;
//	SetScriptGlobalPtr(script, WaitFunc);
	return 1;
}

int Script_SETFLAG(Script *script)
{
	short i = GetScriptHWord(script);
	AGBPrintf("SETFLAG 0x%X\n", i);
	ScriptSetFlag(i);
	return 0;
}

int Script_CLEARFLAG(Script *script)
{
	short i = GetScriptHWord(script);
	AGBPrintf("CLEARFLAG 0x%X\n", i);
	ScriptClearFlag(i);
	return 0;
}

int Script_CHECKFLAG(Script *script)
{
	short i = GetScriptHWord(script);
	AGBPrintf("CHECKFLAG 0x%X\n", i);
	script->IfFlag = ScriptCheckFlag(i);
	return 0;
}

int Script_RESETVARS(Script *script)
{
	AGBPrintf("RESETVARS\n");
	ScriptVar_8000 = 0;
	ScriptVar_8001 = 0;
	ScriptVar_8002 = 0;
	return 0;
}

int Script_SOUND(Script *script)
{
	short i = GetScriptHWord(script);
	AGBPrintf("SOUND 0x%X\n", i);
	sndPlaySound(i, SOUND_NORMAL);
	return 0;
}

int Script_CHECKSOUND(Script *script)
{
	AGBPrintf("CHECKSOUND ***DUMMY***\n");
	//SetScriptGlobalPtr(script, sub_806B07C);
	return 1;
}

int Script_FANFARE(Script *script)
{
	short i = GetScriptHWord(script);
	AGBPrintf("FANFARE 0x%X\n", i);
	sndPlayFanfare(i);
	return 0;
}

int Script_WAITFANFARE(Script *script)
{
	AGBPrintf("WAITFANFARE ***DUMMY***\n");
	//SetScriptGlobalPtr(script, sub_806B0BC);
	return 1;
}

int Script_PLAYSONG(Script *script)
{
	int i = GetScriptHWord(script);
	int j = *script->IP++;
	AGBPrintf("PLAYSONG 0x%X %d\n",i,j);
	sndPlaySound(i, SOUND_NORMAL);
	//sub_8055E78(i);
	return 0;
}

int Script_PLAYSONG2(Script *script)
{
	int i = GetScriptHWord(script);
	AGBPrintf("PLAYSONG2 0x%X\n",i);
	sndPlaySound(i, SOUND_NORMAL);
	//sub_8055E78(i);
	return 0;
}

int Script_FADEDEFAULT(Script *script)
{
	AGBPrintf("FADEDEFAULT\n");
	sndFadeToSound(currentMapHeader->Music);
	//byte_203ADFA -= 2;
	//if(byte_203ADFA ...) sub_8055F1C();

	// CMP R0, #1
	// BLS loc_806B148

	return 0;
}

int Script_FADESONG(Script *script)
{
	int i = GetScriptHWord(script);
	AGBPrintf("FADESONG 0x%X\n",i);
	sndFadeToSound(i);
	return 0;
/*
ROM:0806B156                 BL      GetScriptHWord  ; Branch with Link

ROM:0806B15A                 LSLS    R0, R0, #0x10   ; Logical Shift Left
ROM:0806B15C                 LSRS    R1, R0, #0x10   ; Logical Shift Right
ROM:0806B15E                 LDR     R0, =byte_203ADFA ; Load from Memory
ROM:0806B160                 LDRB    R0, [R0]        ; Load from Memory
ROM:0806B162                 SUBS    R0, #2          ; Rd = Op1 - Op2
ROM:0806B164                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806B166                 LSRS    R0, R0, #0x18   ; Logical Shift Right
ROM:0806B168                 CMP     R0, #1          ; Set cond. codes on Op1 - Op2
ROM:0806B16A                 BLS     loc_806B172     ; Branch

ROM:0806B16C                 ADDS    R0, R1, #0      ; Rd = Op1 + Op2
ROM:0806B16E                 BL      sub_8055F48     ; Branch with Link

ROM:0806B172 loc_806B172                             ; CODE XREF: Script_36+16j
ROM:0806B172                 MOVS    R0, #0          ; Rd = Op2
ROM:0806B174                 POP     {R1}            ; Pop Registers
ROM:0806B176                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_FADEOUT(Script *script)
{
	int i = *script->IP++;
	AGBPrintf("FADEOUT %d ***DUMMY***\n",i);
	return 0;
/*
ROM:0806B17E                 ADDS    R4, R0, #0      ; Rd = Op1 + Op2
ROM:0806B180                 LDR     R0, [R4,#sScriptMem.IP] ; Load from Memory
ROM:0806B182                 LDRB    R1, [R0]        ; Load from Memory
ROM:0806B184                 ADDS    R0, #1          ; Rd = Op1 + Op2
ROM:0806B186                 STR     R0, [R4,#sScriptMem.IP] ; Store to Memory
ROM:0806B188                 LDR     R0, =byte_203ADFA ; Load from Memory
ROM:0806B18A                 LDRB    R0, [R0]        ; Load from Memory
ROM:0806B18C                 SUBS    R0, #2          ; Rd = Op1 - Op2
ROM:0806B18E                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806B190                 LSRS    R0, R0, #0x18   ; Logical Shift Right
ROM:0806B192                 CMP     R0, #1          ; Set cond. codes on Op1 - Op2
ROM:0806B194                 BHI     loc_806B1A0     ; Branch

ROM:0806B196                 MOVS    R0, #0          ; Rd = Op2
ROM:0806B198                 B       loc_806B1BE     ; Branch

ROM:0806B1A0 loc_806B1A0                             ; CODE XREF: Script_37+18j
ROM:0806B1A0                 CMP     R1, #0          ; Set cond. codes on Op1 - Op2
ROM:0806B1A2                 BEQ     loc_806B1AE     ; Branch

ROM:0806B1A4                 LSLS    R0, R1, #0x1A   ; Logical Shift Left
ROM:0806B1A6                 LSRS    R0, R0, #0x18   ; Logical Shift Right
ROM:0806B1A8                 BL      sub_8071D64     ; Branch with Link

ROM:0806B1AC                 B       loc_806B1B4     ; Branch

ROM:0806B1AE loc_806B1AE                             ; CODE XREF: Script_37+26j
ROM:0806B1AE                 MOVS    R0, #4          ; Rd = Op2
ROM:0806B1B0                 BL      sub_8071D64     ; Branch with Link

ROM:0806B1B4 loc_806B1B4                             ; CODE XREF: Script_37+30j
ROM:0806B1B4                 LDR     R1, =(sub_8071D7C+1) ; Load from Memory
ROM:0806B1B6                 ADDS    R0, R4, #0      ; Rd = Op1 + Op2
ROM:0806B1B8                 BL      SetScriptGlobalPtr ; Branch with Link

ROM:0806B1BC                 MOVS    R0, #1          ; Rd = Op2
ROM:0806B1BC

ROM:0806B1BE loc_806B1BE                             ; CODE XREF: Script_37+1Cj
ROM:0806B1BE                 POP     {R4}            ; Pop Registers
ROM:0806B1C0                 POP     {R1}            ; Pop Registers
ROM:0806B1C2                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_FADEIN(Script *script)
{
	int i = *script->IP++;
	AGBPrintf("FADEIN %d ***DUMMY***\n",i);
	return 0;
/*
ROM:0806B1CA                 LDR     R1, [R0,#sScriptMem.IP] ; Load from Memory
ROM:0806B1CC                 LDRB    R2, [R1]        ; Load from Memory
ROM:0806B1CE                 ADDS    R1, #1          ; Rd = Op1 + Op2
ROM:0806B1D0                 STR     R1, [R0,#sScriptMem.IP] ; Store to Memory
ROM:0806B1D2                 LDR     R0, =byte_203ADFA ; Load from Memory
ROM:0806B1D4                 LDRB    R0, [R0]        ; Load from Memory
ROM:0806B1D6                 SUBS    R0, #2          ; Rd = Op1 - Op2
ROM:0806B1D8                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806B1DA                 LSRS    R0, R0, #0x18   ; Logical Shift Right
ROM:0806B1DC                 CMP     R0, #1          ; Set cond. codes on Op1 - Op2
ROM:0806B1DE                 BLS     loc_806B1FA     ; Branch

ROM:0806B1E0                 CMP     R2, #0          ; Set cond. codes on Op1 - Op2
ROM:0806B1E2                 BEQ     loc_806B1F4     ; Branch

ROM:0806B1E4                 LSLS    R0, R2, #0x1A   ; Logical Shift Left
ROM:0806B1E6                 LSRS    R0, R0, #0x18   ; Logical Shift Right
ROM:0806B1E8                 BL      sub_8071DA4     ; Branch with Link

ROM:0806B1EC                 B       loc_806B1FA     ; Branch

ROM:0806B1F4 loc_806B1F4                             ; CODE XREF: Script_38+1Aj
ROM:0806B1F4                 MOVS    R0, #4          ; Rd = Op2
ROM:0806B1F6                 BL      sub_8071DA4     ; Branch with Link

ROM:0806B1FA loc_806B1FA                             ; CODE XREF: Script_38+16j
ROM:0806B1FA                                         ; Script_38+24j
ROM:0806B1FA                 MOVS    R0, #0          ; Rd = Op2
ROM:0806B1FC                 POP     {R1}            ; Pop Registers
ROM:0806B1FE                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARP(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARP %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 1;
/*
ROM:0806AAAA                 MOV     R1, R9          ; Rd = Op2
ROM:0806AAAC                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AAAE                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AAB0                 MOV     R9, R1          ; Rd = Op2
ROM:0806AAB2                 MOV     R1, R8          ; Rd = Op2
ROM:0806AAB4                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AAB6                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AAB8                 MOV     R8, R1          ; Rd = Op2
ROM:0806AABA                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806AABC                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806AABE                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806AAC0                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806AAC2                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806AAC4                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806AAC6                 STR     R0, [SP]        ; Store to Memory
ROM:0806AAC8                 MOV     R0, R9          ; Rd = Op2
ROM:0806AACA                 ADDS    R2, R6, #0      ; Rd = Op1 + Op2
ROM:0806AACC                 ADDS    R3, R4, #0      ; Rd = Op1 + Op2
ROM:0806AACE                 BL      sub_805538C     ; Branch with Link

ROM:0806AAD2                 BL      sub_807E438     ; Branch with Link

ROM:0806AAD6                 BL      sub_80559E4     ; Branch with Link

ROM:0806AADA                 MOVS    R0, #1          ; Rd = Op2
ROM:0806AADC                 ADD     SP, SP, #4      ; Rd = Op1 + Op2
ROM:0806AADE                 POP     {R3,R4}         ; Pop Registers
ROM:0806AAE0                 MOV     R8, R3          ; Rd = Op2
ROM:0806AAE2                 MOV     R9, R4          ; Rd = Op2
ROM:0806AAE4                 POP     {R4-R6}         ; Pop Registers
ROM:0806AAE6                 POP     {R1}            ; Pop Registers
ROM:0806AAE8                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARP2(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARP2 %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 1;
/*
ROM:0806AB32                 MOV     R1, R9          ; Rd = Op2
ROM:0806AB34                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AB36                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AB38                 MOV     R9, R1          ; Rd = Op2
ROM:0806AB3A                 MOV     R1, R8          ; Rd = Op2
ROM:0806AB3C                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AB3E                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AB40                 MOV     R8, R1          ; Rd = Op2
ROM:0806AB42                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806AB44                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806AB46                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806AB48                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806AB4A                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806AB4C                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806AB4E                 STR     R0, [SP]        ; Store to Memory
ROM:0806AB50                 MOV     R0, R9          ; Rd = Op2
ROM:0806AB52                 ADDS    R2, R6, #0      ; Rd = Op1 + Op2
ROM:0806AB54                 ADDS    R3, R4, #0      ; Rd = Op1 + Op2
ROM:0806AB56                 BL      sub_805538C     ; Branch with Link

ROM:0806AB5A                 BL      Spec_14A        ; Branch with Link

ROM:0806AB5E                 BL      sub_80559E4     ; Branch with Link

ROM:0806AB62                 MOVS    R0, #1          ; Rd = Op2
ROM:0806AB64                 ADD     SP, SP, #4      ; Rd = Op1 + Op2
ROM:0806AB66                 POP     {R3,R4}         ; Pop Registers
ROM:0806AB68                 MOV     R8, R3          ; Rd = Op2
ROM:0806AB6A                 MOV     R9, R4          ; Rd = Op2
ROM:0806AB6C                 POP     {R4-R6}         ; Pop Registers
ROM:0806AB6E                 POP     {R1}            ; Pop Registers
ROM:0806AB70                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARPWALK(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARPWALK %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 1;
/*
ROM:0806ABBA                 MOV     R1, R9          ; Rd = Op2
ROM:0806ABBC                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806ABBE                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806ABC0                 MOV     R9, R1          ; Rd = Op2
ROM:0806ABC2                 MOV     R1, R8          ; Rd = Op2
ROM:0806ABC4                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806ABC6                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806ABC8                 MOV     R8, R1          ; Rd = Op2
ROM:0806ABCA                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806ABCC                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806ABCE                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806ABD0                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806ABD2                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806ABD4                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806ABD6                 STR     R0, [SP]        ; Store to Memory
ROM:0806ABD8                 MOV     R0, R9          ; Rd = Op2
ROM:0806ABDA                 ADDS    R2, R6, #0      ; Rd = Op1 + Op2
ROM:0806ABDC                 ADDS    R3, R4, #0      ; Rd = Op1 + Op2
ROM:0806ABDE                 BL      sub_805538C     ; Branch with Link

ROM:0806ABE2                 BL      sub_807E4DC     ; Branch with Link

ROM:0806ABE6                 BL      sub_80559E4     ; Branch with Link

ROM:0806ABEA                 MOVS    R0, #1          ; Rd = Op2
ROM:0806ABEC                 ADD     SP, SP, #4      ; Rd = Op1 + Op2
ROM:0806ABEE                 POP     {R3,R4}         ; Pop Registers
ROM:0806ABF0                 MOV     R8, R3          ; Rd = Op2
ROM:0806ABF2                 MOV     R9, R4          ; Rd = Op2
ROM:0806ABF4                 POP     {R4-R6}         ; Pop Registers
ROM:0806ABF6                 POP     {R1}            ; Pop Registers
ROM:0806ABF8                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARPTELEPORT(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARPTELEPORT %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 1;
/*
ROM:0806ACB6                 MOV     R1, R9          ; Rd = Op2
ROM:0806ACB8                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806ACBA                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806ACBC                 MOV     R9, R1          ; Rd = Op2
ROM:0806ACBE                 MOV     R1, R8          ; Rd = Op2
ROM:0806ACC0                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806ACC2                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806ACC4                 MOV     R8, R1          ; Rd = Op2
ROM:0806ACC6                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806ACC8                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806ACCA                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806ACCC                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806ACCE                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806ACD0                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806ACD2                 STR     R0, [SP]        ; Store to Memory
ROM:0806ACD4                 MOV     R0, R9          ; Rd = Op2
ROM:0806ACD6                 ADDS    R2, R6, #0      ; Rd = Op1 + Op2
ROM:0806ACD8                 ADDS    R3, R4, #0      ; Rd = Op1 + Op2
ROM:0806ACDA                 BL      sub_805538C     ; Branch with Link

ROM:0806ACDE                 BL      sub_807E59C     ; Branch with Link

ROM:0806ACE2                 BL      sub_80559E4     ; Branch with Link

ROM:0806ACE6                 MOVS    R0, #1          ; Rd = Op2
ROM:0806ACE8                 ADD     SP, SP, #4      ; Rd = Op1 + Op2
ROM:0806ACEA                 POP     {R3,R4}         ; Pop Registers
ROM:0806ACEC                 MOV     R8, R3          ; Rd = Op2
ROM:0806ACEE                 MOV     R9, R4          ; Rd = Op2
ROM:0806ACF0                 POP     {R4-R6}         ; Pop Registers
ROM:0806ACF2                 POP     {R1}            ; Pop Registers
ROM:0806ACF4                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARP3(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARP3 %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 0;
/*
ROM:0806ADD2                 MOV     R1, R9          ; Rd = Op2
ROM:0806ADD4                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806ADD6                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806ADD8                 MOV     R9, R1          ; Rd = Op2
ROM:0806ADDA                 MOV     R1, R8          ; Rd = Op2
ROM:0806ADDC                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806ADDE                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806ADE0                 MOV     R8, R1          ; Rd = Op2
ROM:0806ADE2                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806ADE4                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806ADE6                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806ADE8                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806ADEA                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806ADEC                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806ADEE                 STR     R0, [SP]        ; Store to Memory
ROM:0806ADF0                 MOV     R0, R9          ; Rd = Op2
ROM:0806ADF2                 ADDS    R2, R6, #0      ; Rd = Op1 + Op2
ROM:0806ADF4                 ADDS    R3, R4, #0      ; Rd = Op1 + Op2
ROM:0806ADF6                 BL      sub_805538C     ; Branch with Link

ROM:0806ADFA                 MOVS    R0, #0          ; Rd = Op2
ROM:0806ADFC                 ADD     SP, SP, #4      ; Rd = Op1 + Op2
ROM:0806ADFE                 POP     {R3,R4}         ; Pop Registers
ROM:0806AE00                 MOV     R8, R3          ; Rd = Op2
ROM:0806AE02                 MOV     R9, R4          ; Rd = Op2
ROM:0806AE04                 POP     {R4-R6}         ; Pop Registers
ROM:0806AE06                 POP     {R1}            ; Pop Registers
ROM:0806AE08                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARPELEVATOR(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARPELEVATOR %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 0;
/*
ROM:0806AE52                 MOV     R1, R9          ; Rd = Op2
ROM:0806AE54                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AE56                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AE58                 MOV     R9, R1          ; Rd = Op2
ROM:0806AE5A                 MOV     R1, R8          ; Rd = Op2
ROM:0806AE5C                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AE5E                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AE60                 MOV     R8, R1          ; Rd = Op2
ROM:0806AE62                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806AE64                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806AE66                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806AE68                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806AE6A                 STR     R4, [SP]        ; Store to Memory
ROM:0806AE6C                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806AE6E                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806AE70                 STR     R0, [SP,#4]     ; Store to Memory
ROM:0806AE72                 MOVS    R0, #0          ; Rd = Op2
ROM:0806AE74                 MOV     R1, R9          ; Rd = Op2
ROM:0806AE76                 MOV     R2, R8          ; Rd = Op2
ROM:0806AE78                 ADDS    R3, R6, #0      ; Rd = Op1 + Op2
ROM:0806AE7A                 BL      sub_805541C     ; Branch with Link

ROM:0806AE7E                 MOVS    R0, #0          ; Rd = Op2
ROM:0806AE80                 ADD     SP, SP, #8      ; Rd = Op1 + Op2
ROM:0806AE82                 POP     {R3,R4}         ; Pop Registers
ROM:0806AE84                 MOV     R8, R3          ; Rd = Op2
ROM:0806AE86                 MOV     R9, R4          ; Rd = Op2
ROM:0806AE88                 POP     {R4-R6}         ; Pop Registers
ROM:0806AE8A                 POP     {R1}            ; Pop Registers
ROM:0806AE8C                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARP4(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARP4 %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 0;
/*
ROM:0806AED6                 MOV     R1, R9          ; Rd = Op2
ROM:0806AED8                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AEDA                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AEDC                 MOV     R9, R1          ; Rd = Op2
ROM:0806AEDE                 MOV     R1, R8          ; Rd = Op2
ROM:0806AEE0                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AEE2                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AEE4                 MOV     R8, R1          ; Rd = Op2
ROM:0806AEE6                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806AEE8                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806AEEA                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806AEEC                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806AEEE                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806AEF0                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806AEF2                 STR     R0, [SP]        ; Store to Memory
ROM:0806AEF4                 MOV     R0, R9          ; Rd = Op2
ROM:0806AEF6                 ADDS    R2, R6, #0      ; Rd = Op1 + Op2
ROM:0806AEF8                 ADDS    R3, R4, #0      ; Rd = Op1 + Op2
ROM:0806AEFA                 BL      sub_80555F8     ; Branch with Link

ROM:0806AEFE                 MOVS    R0, #0          ; Rd = Op2
ROM:0806AF00                 ADD     SP, SP, #4      ; Rd = Op1 + Op2
ROM:0806AF02                 POP     {R3,R4}         ; Pop Registers
ROM:0806AF04                 MOV     R8, R3          ; Rd = Op2
ROM:0806AF06                 MOV     R9, R4          ; Rd = Op2
ROM:0806AF08                 POP     {R4-R6}         ; Pop Registers
ROM:0806AF0A                 POP     {R1}            ; Pop Registers
ROM:0806AF0C                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_WARP5(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	int k = *script->IP++;
	int l = GetScript___(GetScriptHWord(script));
	int m = GetScript___(GetScriptHWord(script));
	AGBPrintf("WARP5 %d %d %d 0x%X 0x%X ***DUMMY***\n",i,j,k,l,m);
	return 0;
/*
ROM:0806AF56                 MOV     R1, R9          ; Rd = Op2
ROM:0806AF58                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AF5A                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AF5C                 MOV     R9, R1          ; Rd = Op2
ROM:0806AF5E                 MOV     R1, R8          ; Rd = Op2
ROM:0806AF60                 LSLS    R1, R1, #0x18   ; Logical Shift Left
ROM:0806AF62                 ASRS    R1, R1, #0x18   ; Arithmetic Shift Right
ROM:0806AF64                 MOV     R8, R1          ; Rd = Op2
ROM:0806AF66                 LSLS    R6, R6, #0x18   ; Logical Shift Left
ROM:0806AF68                 ASRS    R6, R6, #0x18   ; Arithmetic Shift Right
ROM:0806AF6A                 LSLS    R4, R4, #0x18   ; Logical Shift Left
ROM:0806AF6C                 ASRS    R4, R4, #0x18   ; Arithmetic Shift Right
ROM:0806AF6E                 LSLS    R0, R0, #0x18   ; Logical Shift Left
ROM:0806AF70                 ASRS    R0, R0, #0x18   ; Arithmetic Shift Right
ROM:0806AF72                 STR     R0, [SP]        ; Store to Memory
ROM:0806AF74                 MOV     R0, R9          ; Rd = Op2
ROM:0806AF76                 ADDS    R2, R6, #0      ; Rd = Op1 + Op2
ROM:0806AF78                 ADDS    R3, R4, #0      ; Rd = Op1 + Op2
ROM:0806AF7A                 BL      sub_805564C     ; Branch with Link

ROM:0806AF7E                 MOVS    R0, #0          ; Rd = Op2
ROM:0806AF80                 ADD     SP, SP, #4      ; Rd = Op1 + Op2
ROM:0806AF82                 POP     {R3,R4}         ; Pop Registers
ROM:0806AF84                 MOV     R8, R3          ; Rd = Op2
ROM:0806AF86                 MOV     R9, R4          ; Rd = Op2
ROM:0806AF88                 POP     {R4-R6}         ; Pop Registers
ROM:0806AF8A                 POP     {R1}            ; Pop Registers
ROM:0806AF8C                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_GETPLAYERPOS(Script *script)
{
	unsigned short * r5 = GetScriptVar(GetScriptHWord(script));
	unsigned short * r0 = GetScriptVar(GetScriptHWord(script));
	AGBPrintf("GETPLAYERPOS 0x%X 0x%X\n",r5,r0);
	*r5 = Actors[0].mx;
	*r0 = Actors[0].my;
	return 0;
/*
ROM:0806B030                 LDR     R2, =ptrDMA_    ; Load from Memory
ROM:0806B032                 LDR     R1, [R2]        ; Load from Memory
ROM:0806B034                 LDRH    R1, [R1]        ; Load from Memory
ROM:0806B036                 STRH    R1, [R5]        ; Store to Memory
ROM:0806B038                 LDR     R1, [R2]        ; Load from Memory
ROM:0806B03A                 LDRH    R1, [R1,#2]     ; Load from Memory
ROM:0806B03C                 STRH    R1, [R0]        ; Store to Memory
ROM:0806B03E                 MOVS    R0, #0          ; Rd = Op2
ROM:0806B040                 POP     {R4,R5}         ; Pop Registers
ROM:0806B042                 POP     {R1}            ; Pop Registers
ROM:0806B044                 BX      R1              ; Branch to/from Thumb mode
*/
}

int Script_COUNTPOKEMON(Script *script)
{
	AGBPrintf("COUNTPOKEMON\n");
	ScriptVar_800D = GetPartySize(MyParty);
	return 0;
}

int Script_ADDITEM(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	int j = GetScript___(GetScriptHWord(script));
	AGBPrintf("ADDITEM 0x%X * %d\n", i,j);
	//sayf(SYSTEM,strGotAnItem, PlayerName, j, plural(items[i].name,j));
	//sayf(SYSTEM,strPutAwayItem, PlayerName, plural(items[i].name,j), InventoryPages[items[i].pocket-1].name);
	while(j)
	{
		GiveItem(i);
		j--;
	}
	return 0;
}

int Script_REMOVEITEM(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	int j = GetScript___(GetScriptHWord(script));
	AGBPrintf("REMOVEITEM 0x%X * %d\n", i,j);
	while(j)
	{
		TakeItem(i);
		j--;
	}
	return 0;
}

int Script_CHECKITEMAMOUNT(Script *script)
{
	int index = GetScript___(GetScriptHWord(script));
	int amount = GetScript___(GetScriptHWord(script));
	AGBPrintf("CHECKITEMAMOUNT 0x%X %d\n",index,amount);

	int i, j;
	j = items[index].pocket - 1;
	for(i = InventoryPages[j].offset; i<InventoryPages[j].offset+InventoryPages[j].length; i++)
	{
		if(inventory[i].itemidx == index)
		{
			ScriptVar_800D = (inventory[i].itemcnt + amount <= 99) ? 1 : 0;
			return 0;
		}
		if(inventory[i].itemidx == 0)
		{
			//Not at the end of the list yet and this is an empty slot it can be placed in.
			ScriptVar_800D = 1;
			break;
		}
	}
	//Out of slots?
	ScriptVar_800D = 0;
	return 0;
}

int Script_CHECKITEM(Script *script)
{
	int index = GetScript___(GetScriptHWord(script));
	int amount = GetScript___(GetScriptHWord(script));
	AGBPrintf("CHECKITEM 0x%X %d\n",index, amount);

	int i, j;
	j = items[index].pocket - 1;
	for(i = InventoryPages[j].offset; i<InventoryPages[j].offset+InventoryPages[j].length; i++)
	{
		if(inventory[i].itemidx == index)
		{
			ScriptVar_800D = (inventory[i].itemcnt >= amount) ? 1 : 0;
			return 0;
		}
	}
	return 0;
}

int Script_CHECKITEMTYPE(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	AGBPrintf("CHECKITEMTYPE 0x%X\n",i);
	ScriptVar_800D = items[i].pocket;
	return 0;
}

//--------------------------------------------------------//
// UNSORTED HACKS RIGHT AHEAD!

int Script_APPLYMOVEMENT(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	unsigned char * j = (unsigned char*)GetScriptWord(script);
	AGBPrintf("APPLYMOVEMENT %d 0x%X\n",i,j);
	Actors[i].motor = actPath;
	Actors[i].path = j;
	return 0;
}

int Script_WAITMOVEMENT(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	AGBPrintf("WAITMOVEMENT %d\n",i);
	while(Actors[i].motor == actPath)
	{
		DoVBlank();
		if(CurrentProcess != 0) CurrentProcess();
		MotorSprites(); //lets actors move around
		AnimateSprites();	//updates actor timers and states
		AnimateTiles();		//loads new tiles
		HandleCamera();		//updates cam coords according to player and calls CamUpdate
		FocusCam();			//actually sets scroll regs according to cam coords
		UpdateSprites();	//actually places sprites
	}
	return 0;
}

int Script_HIDESPRITE(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	AGBPrintf("HIDESPRITE 0x%X\n",i);
	if(Actors[i].flag)
	{
		if(!Actors[i].flagonoroff)
			SETBIT(ScriptFlags, Actors[i].flag);
		else
			CLRBIT(ScriptFlags, Actors[i].flag);
	}
	Actors[i].sprite = 0;
	UpdateSprites();
	return 0;
}

int Script_SHOWSPRITE(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	AGBPrintf("SHOWSPRITE 0x%X\n",i);
	if(Actors[i].flag)
	{
		if(!Actors[i].flagonoroff)
			CLRBIT(ScriptFlags,Actors[i].flag);
		else
			SETBIT(ScriptFlags,Actors[i].flag);
	}
	Actors[i].sprite = currentMapHeader->events->people[i-1].sprite;
	UpdateSprites();
	return 0;
}

int Script_FACEPLAYER(Script *script)
{
	AGBPrintf("FACEPLAYER\n");
	if(ScriptVar_800F < 0) return 0;
	if(Actors[ScriptVar_800F].my < Actors[0].my)
		Actors[ScriptVar_800F].direction = 0;
	if(Actors[ScriptVar_800F].mx < Actors[0].mx)
		Actors[ScriptVar_800F].direction = 1;
	if(Actors[ScriptVar_800F].my > Actors[0].my)
		Actors[ScriptVar_800F].direction = 2;
	if(Actors[ScriptVar_800F].mx > Actors[0].mx)
		Actors[ScriptVar_800F].direction = 3;
	UpdateSprites();
	return 0;
}

int Script_TRAINERBATTLE(Script *script)
{
	extern u8 MyBattles[64];
	//extern const aTrainer Trainers[];
	//extern const char TrainerTypes[][14];
	extern void WhiteOut();
	extern void RepairMap();

	int index = GetScriptHWord(script);
	char * intro = (char*)GetScriptWord(script);
	char * defeat = (char*)GetScriptWord(script);
	char * doubl = (char*)GetScriptWord(script);
	unsigned char * after = (unsigned char*)GetScriptWord(script);

	AGBPrintf("TRAINERBATTLE 0x%X 0x%X 0x%X 0x%X 0x%X\n", index, intro, defeat, doubl, after);
	if(intro) AGBPrintf(" \"%s\"\n", intro);
	if(intro) AGBPrintf(" \"%s\"\n", defeat);
	if(doubl) AGBPrintf(" \"%s\"\n", doubl);

	if(GETBIT(MyBattles, index) == 0) //didn't win yet
	{
		if(intro)
		{
			Script_FACEPLAYER(script);
			sayf(SPEECH, intro);
		}
		sndPlaySound(after ? 4 : 5,SOUND_NORESTART);
		int result = Battle(1, index, currentMapHeader->BattleFloor, defeat);
		if(result == 0) //win
		{
			SETBIT(MyBattles, index);
			RepairMap();
			sndFadeToSound(currentMapHeader->Music);
			if(after) ScriptGoto(script, after);
		} else if(result == 1) //lose
		{
			if(intro) //if we had an intro speech, assume it's not a "friendly" battle
			{
				WhiteOut();
				return 1;
			} else
			{
				RepairMap();
				sndFadeToSound(currentMapHeader->Music);
				if(after) ScriptGoto(script, after);
			}
		} else
		{
			Scream("UNPOSSIBLE BATTLE RESULT!");
		}
		ScriptVar_800D = result;
	}
	return 0;
}

int Script_GETTRAINERFLAG(Script *script)
{
	extern u8 MyBattles[64];
	int index = GetScriptHWord(script);
	AGBPrintf("GETTRAINERFLAG 0x%X\n", index);
	script->IfFlag = GETBIT(MyBattles, index);
	return 0;
}

int Script_CLEARTRAINERFLAG(Script *script)
{
	extern u8 MyBattles[64];
	int index = GetScriptHWord(script);
	AGBPrintf("CLEARTRAINERFLAG 0x%X\n", index);
	CLRBIT(MyBattles, index);
	return 0;
}

int Script_SETTRAINERFLAG(Script *script)
{
	extern u8 MyBattles[64];
	int index = GetScriptHWord(script);
	AGBPrintf("SETTRAINERFLAG 0x%X\n", index);
	SETBIT(MyBattles, index);
	return 0;
}

void *boxsetproc;
int Script_WAITMSGBOX(Script *script)
{
	AGBPrintf("WAITMSGBOX\n");
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(SM_Dialoguebox.style == 1) MotorSprites(); //lets actors move around
		AnimateSprites();	//updates actor timers and states
		AnimateTiles();		//loads new tiles
		UpdateSprites();	//actually places sprites
		CurrentProcess();
		if(SM_Dialoguebox.state == 7)	break;
	}
	Trg = 0;
	CurrentProcess = (void*)boxsetproc;
	return 0;
}

int Script_MSGBOX2(Script *script)
{
	unsigned char * txt = (unsigned char*)GetScriptWord(script);
	if(txt == 0) txt = (unsigned char*)script->LoadedPointer;

	AGBPrintf("MSGBOX2\n \"%s\"\n",txt);

	boxsetproc = (void*)CurrentProcess;

	SM_Dialoguebox.style = (ScriptVar_800F < 0) ? 1 : 0;

	SetText(TextBuffer, (char*)txt);
	SM_Dialoguebox.state = 0;
//	if(SM_Dialoguebox.isSign)
//	{
		CurrentProcess = DialogueBox;
//		return 0;
//	}
	return 0;
}

int Script_LOCKALL(Script *script)
{
	AGBPrintf("LOCKALL\n");
	LockDown = 2;
	return 0;
}

int Script_LOCK(Script *script)
{
	AGBPrintf("LOCK\n");
	LockDown = 1;
	return 0;
}

int Script_RELEASEALL(Script *script)
{
	AGBPrintf("RELEASEALL\n");
	LockDown = 0;
	return 0;
}

int Script_RELEASE(Script *script)
{
	AGBPrintf("RELEASE\n");
	LockDown = 0;
	return 0;
}

int Script_WAITKEYPRESS(Script *script)
{
	AGBPrintf("WAITKEYPRESS\n");
	Trg = 0;
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg && KEY_A)
			break;
	}
	SM_Dialoguebox.state = 6;
	DialogueBox();
	return 0;
}

int Script_YESNOBOX(Script *script)
{
	int x = *script->IP++;
	int y = *script->IP++;
	AGBPrintf("YESNOBOX %d %d\n", x, y);
	LoadFrame();
	ScriptVar_800D = !MultipleChoice(x,y,8,0,1);
	SM_Dialoguebox.state = 6;
	return 0;
}

//int ShowPokePicX, ShowPokePicY;
extern int StartingOamIndex;
int ShowPokePicFunc(Script *script)
{
	int x = script->GlobalParams[0];
	int y = script->GlobalParams[1];
	DrawFrame(x,10,y,10);
	OamBak[0].CharNo = 928;
	OamBak[0].Pltt = 15;
	OamBak[0].Shape = 0;
	OamBak[0].Size = 3;
	OamBak[0].HFlip = 0;
	OamBak[0].VFlip = 0;
	OamBak[0].HPos = x * 8 + 8; //88;
	OamBak[0].VPos = y * 8 + 8; //32;
	OamBak[0].Priority = 0;
	return 1;
}
int Script_SHOWPOKEPIC(Script *script)
{
	int index = GetScript___(GetScriptHWord(script));
	int x = *script->IP++;
	int y = *script->IP++;

	AGBPrintf("SHOWPOKEPIC %d %d %d\n",index,x,y);
	DmaCopy(PokePicsPalette[index], MEM_PAL_OBJ + 0x1E0, 32);
	LZ77UnCompVram(PokePicsFront[index], (u16*)(MEM_VRAM_OBJ + 0x7400));
	script->GlobalParams[0] = x;
	script->GlobalParams[1] = y;
	StartingOamIndex = 1;
	SetScriptGlobalPtr(script, ShowPokePicFunc);
	return 1;
}

int Script_HIDEPOKEPIC(Script *script)
{
	AGBPrintf("HIDEPOKEPIC\n");
	CleanUpBG0();
	SetScriptGlobalPtr(script, 0);
	StartingOamIndex = 0;
	return 0;
}

int Script_BRAILLE(Script *script)
{
	unsigned char * txt = (unsigned char*)GetScriptWord(script);
//	if(txt == 0) txt = (unsigned char*)SneakyPointerHack;
	AGBPrintf("BRAILLE\n \"%s\"\n",txt);
	boxsetproc = (void*)CurrentProcess;
	SetText(TextBuffer, (char*)txt);
	SM_Dialoguebox.state = 0;
	CurrentProcess = BrailleBox;
	return 0;
}

int Script_GIVEPOKEMON(Script *script)
{
	int species = GetScript___(GetScriptHWord(script));
	int level = *script->IP++;
	AGBPrintf("GIVEPOKEMON %d %d\n",species,level);
	CreateMonsterInParty(species,level);
	sayf(SYSTEM,strGotAMonster, PlayerName, PokeNames[species]);
	sndPlayFanfare(16);
	SETBIT(ScriptFlags, HAVEPARTY);
	return 0;
}

int Script_BUFFERITEM(Script *script)
{
	int i = *script->IP++;
	int j = GetScript___(GetScriptHWord(script));
	AGBPrintf("BUFFERITEM %d 0x%X\n",i,j);
	strcpy(StringVar[i],items[j].name);
	return 0;
}

int Script_BUFFERATTACK(Script *script)
{
	int i = *script->IP++;
	int j = GetScript___(GetScriptHWord(script));
	AGBPrintf("BUFFERATTACK %d 0x%X\n",i,j);
	strcpy(StringVar[i],moveNames[j]);
	return 0;
}

int Script_BUFFERNUMBER(Script *script)
{
	int i = *script->IP++;
	int j = GetScript___(GetScriptHWord(script));
	AGBPrintf("BUFFERNUMBER %d 0x%X\n",i,j);
	sprintf(StringVar[i],"%d",j);
	return 0;
}

int Script_BUFFERSTANDARD(Script *script)
{
	int i = *script->IP++;
	int j = GetScript___(GetScriptHWord(script));
	AGBPrintf("BUFFERSTANDARD %d 0x%X \"%s\"\n",i,j,StandardStrings[j]);
	strcpy(StringVar[i],StandardStrings[j]);
	return 0;
}

int Script_BUFFERSTRING(Script *script)
{
	int i = *script->IP++;
	char * j = (char*)GetScriptWord(script);
	AGBPrintf("BUFFERSTRING %d 0x%X\n",i,j);
	strcpy(StringVar[i],j);
	return 0;
}

int Script_MART(Script *script)	// index: DOSHOP (please change)
{
	unsigned short * j = (unsigned short*)GetScriptWord(script);
	AGBPrintf("MART 0x%X\n",j);
	DoStore(j);
	return 0;
}

int Script_GETRANDOM(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	ScriptVar_800D = rrand(i);
	AGBPrintf("GETRANDOM %d --> %d\n",i,ScriptVar_800D);
	return 0;
}

int Script_GIVEMONEY(Script *script)
{
	int i = GetScriptWord(script);
	int j = *script->IP++;
	AGBPrintf("GIVEMONEY %d %d\n",i,j);
	MyPlayer.cash += i;
	return 0;
}

int Script_PAYMONEY(Script *script)
{
	int i = GetScriptWord(script);
	int j = *script->IP++;
	AGBPrintf("PAYMONEY %d %d\n",i,j);
	MyPlayer.cash -= i;
	return 0;
}

int Script_FADESCREEN(Script *script)
{
	int i = *script->IP++;
	AGBPrintf("FADESCREEN %d\n", i);
	if(i)
		FadeOut();
	else
		FadeIn();
	return 0;
}

int Script_SETHEALINGPLACE(Script *script)
{
	int i = GetScript___(GetScriptHWord(script));
	AGBPrintf("SETHEALINGPLACE %d\n",i);
	LastKnownSafePlace = i;
	return 0;
}

int Script_CHECKGENDER(Script *script)
{
	AGBPrintf("CHECKGENDER\n");
	ScriptVar_800D = MyPlayer.gender;
	return 0;
}

int Script_SETMAPTILE(Script *script)
{
	int x = GetScript___(GetScriptHWord(script));
	int y = GetScript___(GetScriptHWord(script));
	int t = GetScript___(GetScriptHWord(script));
	int a = GetScript___(GetScriptHWord(script));
	AGBPrintf("SETMAPTILE %d %d 0x%X %d\n",x,y,t,a);
	MapBuffer[y * currentLevel->width + x] = t;
	return 0;
}

int Script_SETWEATHER(Script *script)
{
	extern void (*NextWeatherEffect)(int);
	//extern void (*WeatherEffect)(int);
	extern void * WeatherEffects[];
	int i = GetScriptHWord(script);
	if(i == 0) i = 2; //to properly shut down the weather, don't use 0
	NextWeatherEffect = WeatherEffects[i];
	return 0;
}

int Script_DOWEATHER(Script *script)
{
	extern void (*NextWeatherEffect)(int);
	extern void (*WeatherEffect)(int);
	extern void * WeatherEffects[];
	if(WeatherEffect)
	{
		//Already have a weather effect running - queue the next one.
		WeatherEffect(2);
	} else
	{
		//No effect right now - start the new one immediately.
		WeatherEffect = NextWeatherEffect;
		WeatherEffect(1);
	}
	return 0;
}

int Script_TEXTCOLOR(Script *script)
{
	int i = *script->IP++;
	AGBPrintf("TEXTCOLOR %d\n", i);
	ScriptVar_8013 = ScriptVar_8012;
	ScriptVar_8012 = i;
	return 0;
}

//TODO	Investigate how to do it properly
int Script_MSGBOXSIGN(Script *script)
{
	AGBPrintf("MSGBOXSIGN\n");
	ScriptVar_800F |= 0x80000000;
	return 0;
}

int Script_MSGBOXNORMAL(Script *script)
{
	AGBPrintf("MSGBOXNORMAL\n");
	ScriptVar_800F &= ~ 0x80000000;
	return 0;
}

//--------------------------------------------------------//
// EXTENSIONS

int Script_PHONE(Script *script)
{
	extern void Phonecall(char *caller);
	extern const char * const phonenames[];
	int action = *script->IP++;
	int index = *script->IP++;
	AGBPrintf("PHONE %d %d\n",action,index);
	if(action == 0)
	{
		Phonecall((char*)phonenames[index]);
	} else if(action == 1)
	{
		//Pokedex_RegisterPkmn phone number
	} else
	{
		AGBPrintf("Invalid phone action #%d. Ignoring...\n", action);
	}
	return 0;
}

int Script_GETTIME(Script *script)
{
	int what = *script->IP++;
	int answer = 0xFF;
	AGBPrintf("GETTIME %d\n",what);
	RTCTime myTime;
	RTC_GetTime(&myTime);
	if(what == 0)
		answer = GetTimeOfDay();
	else if(what == 1)
		answer = myTime.hours;
	else if(what == 2)
		answer = myTime.dayofweek;

	ScriptVar_800D = answer;
	return 0;
}

int Script_REBUILDMAP(Script *script)
{
	AGBPrintf("REBUILDMAP\n");
	CleanUpCrap();
	LoadSpriteColors();
	mapLoadMinimal(MyPlayer.currentMap);
	mhRedraw(currentMapHeader, Actors[0].mx-7, Actors[0].my-5);
	HandleCamera();
	HandleCamera();
	UpdateSprites();
	FocusCam();
	ResetDispCnt();
	return 0;
}

int Script_BLACKMAP(Script *script)
{
	AGBPrintf("BLACKMAP\n");
	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;
	REG_BLDCNT = 0;
	return 0;
}

void MonsterNickIcon(int t)
{
	extern const u8 MonIconColors[254];
	extern const unsigned short * PartyPics[];
	extern const unsigned short PartyPal[64];
	DmaCopy(PartyPics[ScriptVar_8014], MEM_VRAM_OBJ, 0x200);
	DmaArrayCopy(PartyPal, MEM_PAL_OBJ);
	OamBak[0].Pltt = MonIconColors[ScriptVar_8014];
	OamBak[0].Size = 2;
	OamBak[0].Shape = 0;
	OamBak[0].HPos = 40;
	OamBak[0].VPos = 24;
}
int Script_SETNICKNAME(Script *script)
{
	int index = *script->IP++;
	AGBPrintf("SETNICKNAME %d\n",index);
	char newname[10] = "";
	char prompt[24];
	if(index == 0)
		index = GetPartySize(&MyParty);

	AGBPrintf("Monster at %x.\n",&MyParty[index-1]);
	strcpy(newname, MyParty[index-1].Personal.Nickname);
	ScriptVar_8014 = GetMonsterStats(&MyParty[index-1], pSpecies);
	sprintf(prompt, "%s's nickname?", MyParty[index-1].Personal.Nickname);
	EnterName(newname, 10, prompt, (void*)MonsterNickIcon);

	if(newname[0] != '\0')
		SetNickname(&MyParty[index-1], newname, 1);
		//SetMonsterStats(&MyParty[index-1], pNickname, (int)newname, 1);

	REG_BG0VOFS = 0;
	Script_REBUILDMAP(script);
	FadeIn();
	return 0;
}

int Script_SETSPRITE(Script *script)
{
	int i = *script->IP++;
	int j = *script->IP++;
	AGBPrintf("SETSPRITE %d %d\n",i,j);
	Actors[i].sprite = j;
	return 0;
}

anEggTimer EggTimer;
int Script_SETTIMER(Script *script)
{
	int t = GetScriptHWord(script);
	unsigned char * j = (unsigned char*)GetScriptWord(script);
	AGBPrintf("SETTIMER %d (%d)\n", t, t * 60);
	EggTimer.time = t * 60;
	EggTimer.target = (void*)j;
	return 0;
}

int Script_CHECKBADGE(Script *script)
{
	int index = *script->IP++;
	int count = 0, i;
	if(index == 0)
	{
		for(i = 0; i < 7; i++)
		{
			if(GETBIT(ScriptFlags,HAVEBADGE1+i)) count++;
		}
		ScriptVar_800D = count;
	} else if(index > 8)
	{
		ScriptVar_800D = 0;
	} else
	{
		ScriptVar_800D = GETBIT(ScriptFlags,HAVEBADGE1+index-1);
	}
	return 0;
}

//This one is taken directly from NetHack. It might be handy.
int Script_BUFFERNUMBERORDINAL(Script *script)
{
	int i = *script->IP++;
	int j = GetScript___(GetScriptHWord(script));
	int dd = j % 10;
	AGBPrintf("BUFFERNUMBERORDINAL %d 0x%X\n",i,j);
	sprintf(StringVar[i],"%d%s",j,(dd == 0 || dd > 3 || (j % 100) / 10 == 1) ? "th" : (dd == 1) ? "st" : (dd == 2) ? "nd" : "rd");
	return 0;
}

int Script_CHOICE(Script *script)
{
	int i = GetScriptHWord(script);
	char foo[8];
	int j;

	AGBPrintf("CHOICE %d\n",i);
	//ScriptVar_800D = 2;
	DrawFrame(0,10,0,16);
	vwClear(1);
	for(j = 0; j < 7; j++)
	{
		sprintf(foo, "%dF", j+1);
		vwWriteG(2, (j*2), foo);
		vwSetLine(1,8,1+(j*2),96+(j*64),15);
	}
	j = 0;
	vwWriteG(2,14,strHelpCancel);
	vwWriteG(0,0,strArrow);
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & A_BUTTON) break;
		//if(Trg & B_BUTTON)
		//{
		//	j = 8;
		//	break;
		//}
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			vwWriteG(0,j<<1,strArrowBlank);
			j = wrap(j + key_tri_vert(), 0, 7);
			vwWriteG(0,j<<1,strArrow);
			sndCursor();
		}
	}
	Trg = 0;
	ClearFrame(0,10,0,18);

	ScriptVar_800D = j;

	return 0;
}

int Script_WARPTO(Script *script)
{
	int destLevel = GetScript___(GetScriptHWord(script));
	int destWarp = GetScriptHWord(script);
	AGBPrintf("WARPTO %d, %d\n",destLevel, destWarp);
	int x,y;
	FadeOut();
	mapLoad(destLevel);
	x = currentMapHeader->events->warps[destWarp].xpos;
	y = currentMapHeader->events->warps[destWarp].ypos;
	Actors[0].mx = x;
	Actors[0].my = y;
	Cont = 0;
	Actors[0].state = ACTSTATE_IDLE;
	ClearOamBak();
	mhRedraw(currentMapHeader, Actors[0].mx-7, Actors[0].my-5);
	HandleCamera();
	HandleCamera();
	UpdateSprites();
	AnimateSprites();
	FocusCam();
	DoWarpExitAnimation(currentMapHeader->events->warps[destWarp].kind);
	return 0;
}

int Script_TITLECARD(Script * script)
{
	int i = *script->IP++;
	extern void TitleCard(int episode);
	FadeOut();
	TitleCard(i);
	RepairMap();
	return 0;
}
