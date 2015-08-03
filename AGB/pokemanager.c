//
//	OpenPoké monster manager
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"

extern void MakeHPBar(int value, int max, int target, int nolabel);	//From battle.c
extern void spindaDrawSpots(void *dst, u32 pv);
extern aLearnedMove* GetRef_PokemonMoveset(int species);

extern const char Abilities[][14];
extern const char * const AbilityDescriptions[];
extern const unsigned long XPRequirements[808];
extern const u8 TMAllowances[][8];
extern const unsigned char GaemLut[4][24];

aPokemon HisParty[6] INEWRAM;
aPokemon MyParty[7] INEWRAM;
aBoxedMon MyBox[14*30] INEWRAM;
aPokemon InMyHand;
aPokemon DaycareMon[2] INEWRAM;

aRoamer Roamers[16];

//-----------------------------------------------------
// FUNCTIONS
//-----------------------------------------------------

//-----------------------------------------------------
// LoadPokemonPic
// --------------
// Loads the given species' image into VRAM.
// Flags:
//   LPP_BACK - Load back-facing image
//   LPP_SHINY - Load alternate colors
// Can likely be condensed into less statements.
void LoadPokemonPic(unsigned short species, unsigned char flags, u16* imgTarget, u16* palTarget, unsigned long pv)
{
	const unsigned short *thisPic;
	const unsigned short *thisPal;
	thisPic = (flags & LPP_BACK) ? PokePicsBack[species] : PokePicsFront[species];
	thisPal = (flags & LPP_SHINY) ? PokePicsShinyPal[species] : PokePicsPalette[species];
#ifdef pkUNOWN
	if(species == pkUNOWN)
	{
		int letter = GetUnownLetter(pv);
		if(letter)
			thisPic = (flags & LPP_BACK) ? PokePicsBack[pkUNOWN_B + letter - 1] : PokePicsFront[pkUNOWN_B + letter - 1];
		LZ77UnCompVram(thisPic, imgTarget);
		DmaCopy(thisPal, palTarget, 32);
		return;
	}
#endif
#ifdef pkSPINDA
	if(species == pkSPINDA && pv)
	{
		LZ77UnCompVram(thisPic, imgTarget);
		DmaCopy(thisPal, palTarget, 32);
		spindaDrawSpots(imgTarget, pv);
		return;
	}
#endif
	LZ77UnCompVram(thisPic, imgTarget);
	DmaCopy(thisPal, palTarget, 32);
	return;
}

//-----------------------------------------------------
// LoadPokemonPicToBG
// ------------------
// Loads the given species' image into background VRAM.
// Flags:
//   LPP_BACK	- Load back-facing image
//   LPP_SHINY	- Load alternate colors
// Can likely be condensed into less statements.
void LoadPokemonPicToBG(unsigned short index, unsigned char flags, unsigned char palstrip, unsigned short* target)
{
	const unsigned short *thisPic;
	const unsigned short *thisPal;
	unsigned short *targetPal;
	thisPic = (flags & LPP_BACK) ? PokePicsBack[index] : PokePicsFront[index];
	thisPal = (flags & LPP_SHINY) ? PokePicsShinyPal[index] : PokePicsPalette[index];
	targetPal = (u16*)MEM_PAL_BG + (palstrip << 4);
	LZ77UnCompVram(thisPic, target);
	DmaCopy(thisPal, targetPal, 32);
}

//-----------------------------------------------------
// SetupPokemonSprite
// ------------------
// Changes settings for given sprite index.
void SetupPokemonSprite(unsigned char oamIndex)
{
	OamBak[oamIndex].Shape = 0;
	OamBak[oamIndex].Size = 3;
	OamBak[oamIndex].CharNo = oamIndex << 6;
	OamBak[oamIndex].Pltt = oamIndex;
}
//-----------------------------------------------------
// DecryptMonster
// --------------
// Does the encryption thing on a monster.
aPokemon * dDecryptMonster(aPokemon *mon)
{
	unsigned int i, crypted, uncrypted;
	unsigned int key = mon->Personal.Personal ^ mon->Personal.OTID;
	unsigned int *subs = (unsigned int*)mon->Data;
	for(i=0; i<12; i++)
	{
		crypted = *(unsigned int*)(mon->Data + (i * 4));
		uncrypted = crypted ^ key;
		subs[i] = uncrypted;
	}
	return (aPokemon*)mon;
}

void eEncryptMonster(aPokemon *mon)
{
	unsigned int i, crypted, uncrypted;
	unsigned int key = mon->Personal.Personal ^ mon->Personal.OTID;
	unsigned int *subs = (unsigned int*)mon->Data;
	for(i=0; i<12; i++)
	{
		crypted = *(unsigned int*)(mon->Data + (i * 4));
		uncrypted = crypted ^ key;
		subs[i] = uncrypted;
	}
}

//-----------------------------------------------------
// GetGAEMSubstruct
// ----------------
// Used by GetXXXSubstruct.
void *GetGAEMSubstruct(aPokemon *mon, int type)
{
	return &mon->Data[GaemLut[type][mon->Personal.Personal % 24]];
}

//-----------------------------------------------------
// GetStatusStruct
// ---------------
// Returns a pointer to the status structure.
inline ssStatus *GetStatusStruct(aPokemon *mon)
{
	return &mon->Status;
}

//-----------------------------------------------------
// GetPartySize
// ------------
// Returns the amount of Pokémon in a party, judged by
// species.
int GetPartySize(aPokemon * party)
{
	int i;
	for(i=0; i<( (sizeof(MyParty)) / (sizeof(aPokemon)) ); i++)
		if(GetMonsterStats(&party[i], pSpecies) == 0)
			return i;
		//if(party[i].Personal.OTID == 0) return i;
	return 5;
}

//-----------------------------------------------------
// InjectXP
// --------
// Gives the specified amount of experience to a Pokémon.
void InjectXP(aPokemon *mon, int exp)
{
	int newexp = GetMonsterStats(mon, pExperience) + exp;
	SetMonsterStats(mon, pExperience, newexp);
}

//-----------------------------------------------------
// UpdateLiveStats
// ---------------
// Updates a monster's level based on its' total amount
// of experience and updates the live stats block
// accordingly.
void UpdateLiveStats(aPokemon *mon)
{
	int i = mon->Status.Level;
	int exp = GetMonsterStats(mon, pExperience);
	aBaseStat *myBase = (aBaseStat*)&BaseStats[GetMonsterStats(mon, pSpecies)];

	AGBPrintf("UpdateLiveStats: experience is %d.\n", exp); //myG->Experience);

	for(; i < 100; i++)
	{
		if(exp <= XPRequirements[(myBase->LevelSlope * 101) + i])
		{
			mon->Status.Level = i-1;
			break;
		}
	}
	AGBPrintf("UpdateLiveStats: final level is %d.\n", mon->Status.Level);

#define DOSTAT(st,bs,dv,ef) \
	i = \
		( \
			( \
				(2 * myBase->bs) \
					+ \
				GetMonsterStats(mon,dv) \
					+ \
				(GetMonsterStats(mon,ef) / 4) \
			) \
				* \
			GetMonsterStats(mon,pLevel) \
				/ \
			100 \
		) \
			+ \
		5 \
	; \
	SetMonsterStats(mon, st, i);

	mon->Status.TotalHP = (((  2*myBase->BaseHP)+GetMonsterStats(mon,pDVHP) + (GetMonsterStats(mon,pEffortHP) / 4)) * GetMonsterStats(mon,pLevel) / 100) + 10 + GetMonsterStats(mon,pLevel);

	DOSTAT(pAttack,   BaseAttack,  pDVAttack, pEffortAttack);
	DOSTAT(pDefense,  BaseDefense, pDVDefense,pEffortDefense);
	DOSTAT(pSpeed,    BaseSpeed,   pDVSpeed,  pEffortSpeed);
	DOSTAT(pSPAttack, BaseSpAttack,pDVSPAtk,  pEffortSPAtk);
	DOSTAT(pSPDefense,BaseSpDef,   pDVSPDef,  pEffortSPDef);
#undef DOSTAT
#define DONATURE(st, id) mon->Status.st = ((10+natureBonus[NATURE(mon->Personal.Personal)][id]) \
												 * mon->Status.st)/10
	DONATURE(Attack,0);
	DONATURE(Defense,1);
	DONATURE(Speed,2);
	DONATURE(SpAttack,3);
	DONATURE(SpDefense,4);
#undef DONATURE
}

int CanLearnTM(int species, int tmno)
{
	AGBPrintf("CanLearnTM: %d, %d", species, tmno);
	if(GETBIT(TMAllowances[species],tmno)) return 1;
	return 0;
}

//-----------------------------------------------------
// CreateMonster
// -------------
// Creates a Pokémon of the given species and level at
// the specified address and teaches it the moves it
// would know at that level.
// Assumes it's yours and is caught with a Poké Ball,
// which is just fine. When caught, the Poké Ball value
// would be reset to whatever you caught it with anyway.
void CreateMonster(aPokemon *target, int species, int level)
{
	extern unsigned short GetMonsterChecksum(aPokemon *mon);
	const aLearnedMove* moveset;
	int l, r=0;
	aPokemon * mon = (aPokemon*)target;
	ssPersonal *myP = (ssPersonal*)&mon->Personal;
	aBaseStat *myBase = (aBaseStat*)&BaseStats[species];
	ssGrowth *myG;
	ssAttacks *myA;
	//ssEffort *myE;	|not used until now (check allocation below)
	ssMisc *myM;

	CpuFastClear(0, target, sizeof(aBoxedMon));

	myP->Personal = rand();
	myP->OTID = MyPlayer.trainerid;

	//FORCE SHINY
	/* //v1 by MasterMind_X
	myP->Personal = MyPlayer.trainerid;
	*/
	/* //v2 by Andrea Sartori
	l = rand() & 0xFFFF;
	l+= l << 16;
	myP->Personal = MyPlayer.trainerid ^ l;
	*/
	/* //v3 also by Andrea
	l = rand() & 0xFFFF;
	l+= l << 16;
	r = rand() % SHINY_MAGIC;
	l ^= r;
	myP->Personal = MyPlayer.trainerid ^= l;
	*/

	myG = (ssGrowth*) GetGAEMSubstruct(mon, 0);
	myA = (ssAttacks*)GetGAEMSubstruct(mon, 1);
	//myE = (ssEffort*) GetGAEMSubstruct(mon, 2);
	myM = (ssMisc*)   GetGAEMSubstruct(mon, 3);

	myG->Species = species;
	SetNickname(target, (char*)PokeNames[species], 0);
	sprintf(myP->OTName, "%s", PlayerName);

	myG->Experience = XPRequirements[(myBase->LevelSlope * 101) + level] + 1;

	moveset = GetRef_PokemonMoveset(species);
	for(l = 0; l < GetAmountOfMoves(species); l++)
	{
		if(moveset[l].Move == 0x1FF)
			break;

		if(moveset[l].Level <= level)
		{
			// If the Pokemon doesn't know the move already,
			// teach it the move
			if(	myA->Attack[0] != moveset[l].Move &&
				myA->Attack[1] != moveset[l].Move &&
				myA->Attack[2] != moveset[l].Move &&
				myA->Attack[3] != moveset[l].Move )
			{
				myA->Attack[r] = moveset[l].Move;
				myA->PP[r] = moves[moveset[l].Move].pp;
				r=(r+1) % 4;
				AGBPrintf(" * %s @ Lv.%d...\n", moveNames[moveset[l].Move], moveset[l].Level);
			}
		}
		else
		{
			AGBPrintf(" * Not learning %s @ Lv.%d. Too high. Stopping...\n", moveNames[moveset[l].Move], moveset[l].Level);
			break;
		}
	}

	myG->Tameness = myBase->BaseHappiness;

	myM->Location = 0xFF; //MyPlayer.currentMap;
	myM->Level = level;
	myM->OriginGame = 10;
	myM->Pokeball = 4; //assume Poké Ball by default
	myM->TrainerGender = MyPlayer.gender;
	myM->DVHP = rand() % 0x1F;
	myM->DVAttack = rand() % 0x1F;
	myM->DVDefense = rand() % 0x1F;
	myM->DVSpeed = rand() % 0x1F;
	myM->DVSpAttack = rand() % 0x1F;
	myM->DVSpDefense = rand() % 0x1F;

	myP->Checksum = GetMonsterChecksum(mon);
	eEncryptMonster(mon);

	UpdateLiveStats(target);
	mon->Status.CurrentHP = mon->Status.TotalHP;
}

//-----------------------------------------------------
// CreateMonsterInParty
// --------------------
// Checks the player's party size. If there is space
// left, creates the specified monster as described in
// CreateMonster. Also Registers the species as caught
// in the PokéDex. Returns 255 if the party is too big.
unsigned short CreateMonsterInParty(int species, int level)
{
	int ps = 0;
	AGBPrintf("CreateMonsterInParty: asked to create a level %d %s.\n", level, PokeNames[species]);
	AGBPrint("CreateMonsterInParty: finding party size... ");
	ps = GetPartySize(MyParty);
	AGBPrintf("size is %d.\n", ps);
	if(ps==6)
	{
		AGBPrint("CreateMonsterInParty - party full!\n");
		return 255;
	}
	AGBPrint("CreateMonsterInParty - space left in party. Calling CreateMonster()...\n");
	CreateMonster(&MyParty[ps], species, level);
	AGBPrint("CreateMonsterInParty - Registering...\n");
	Pokedex_RegisterPkmn(species, REG_CAUGHT);
	return ps;
}

//-----------------------------------------------------
// IsShiny
// -------
//
int IsShiny(aPokemon *mon)
{
#ifdef BULBAPEDIA_SHINY_METHOD
	//(Trainer ID) xor (Secret ID) = E
	//(First byteword of personality value) xor (Second byteword of personality value) = F
	//if E xor F is less than eight, then the Pokémon is shiny.
#ifndef NDEBUG
	AGBPrintf("OTID 0x%08x\n",mon->Personal.OTID);
	int tid = mon->Personal.OTID >> 16;
	int sid = mon->Personal.OTID & 0xFFFF;
	AGBPrintf("Trainer ID 0x%04x\n",tid);
	AGBPrintf("Secret ID 0x%04x\n",sid);
	int e = tid ^ sid;
	AGBPrintf("E 0x%04x\n", e);
	AGBPrintf("Personal Value 0x%08x\n",mon->Personal.Personal);
	int first = mon->Personal.Personal & 0xFF;
	int second = (mon->Personal.Personal & 0xFF00) >> 8;
	AGBPrintf("First byte 0x%02x\n",first);
	AGBPrintf("Second byte 0x%02x\n",second);
	int f = first ^ second;
	AGBPrintf("F 0x%02x\n", f);
	int shiny = e ^ f;
	AGBPrintf("Shiny 0x%04x\n",shiny);
	return (shiny < SHINY_MAGIC);
#else
	return (
		(
			(
				(mon->Personal.OTID >> 16)
				^
				(mon->Personal.OTID & 0xFFFF)
			)
			^
			(
				(mon->Personal.Personal & 0xFF)
				^
				((mon->Personal.Personal & 0xFF00) >> 8)
			)
		) < SHINY_MAGIC);
#endif
#else //BULBAPEDIA_SHINY_METHOD
	int xkey = mon->Personal.Personal ^ mon->Personal.OTID;
	int first = (xkey >> 16) & 0xFFFF;
	int secnd = xkey & 0xFFFF;
	int shiny = first ^ secnd;
	AGBPrintf("xkey 0x%x\n", xkey);
	AGBPrintf("first 0x%x\n", first);
	AGBPrintf("secnd 0x%x\n", secnd);
	AGBPrintf("shiny 0x%x\n", shiny);
	return (shiny < SHINY_MAGIC);
#endif
}

//-----------------------------------------------------
// GetUnownLetter
// --------------
// Calculates which Unown letter a given Pokémon would
// be.
int GetUnownLetter(unsigned long pv)
{
	int A=(pv >> 24) & 3;
	int B=(pv >> 16) & 3;
	int C=(pv >> 8 ) & 3;
	int D=(pv      ) & 3;

	//% 28 should've been OUTSIDE of the parens -_-;
	int l=(D | (C<<2) | (B<<4) | (A<<6)) % 28;

	const unsigned char UnownLetters[] =
	{
		'A','B','C','D','E','F','G',
		'H','I','J','K','L','M','N',
		'O','P','Q','R','S','T','U',
		'V','W','X','Y','Z','?','!',
	};
	AGBPrintf("PV %d, letter %c\n", pv, UnownLetters[l]);
	return l;
}

//Returns the max PP for a given move (0-3), including PP-Up bonuses
int GetPPForMove(aPokemon *mon, int move)
{
	int a = GetMonsterStats(mon, pMove1 + move);
	int p = (GetMonsterStats(mon, pPPBonus) >> (move * 2)) % 4;
	return moves[a].pp + p;
}

//-----------------------------------------------------
// HealParty
// ---------
// Iterates through the player's party and sets each
// monster's health to its' maximum.
void HealParty()
{
	int ps = GetPartySize(MyParty);
	int i, j;
	for(i=0; i < ps; i++)
	{
		SetMonsterStats(&MyParty[i], pCurrentHP, GetMonsterStats(&MyParty[i], pTotalHP));
		SetMonsterStats(&MyParty[i], pAilment, 0);
		for(j = 0; j < 4; j++)
		{
			SetMonsterStats(&MyParty[i], pPP1 + j, GetPPForMove(&MyParty[i], j));
		}
	}
}

//-----------------------------------------------------
//
// --------------
//
void Transcode(void *in_dst, const void *in_src, unsigned int length, const unsigned char *table)
{
	unsigned char *src = (unsigned char *)in_src;
	unsigned char *dst = (unsigned char *)in_dst;

	AGBPrintf("Translating strings...\n");
	for(; length > 0; length--)
	{
		AGBPrintf("%x > %x (%c) [%c]\n", src[0], table[src[0]], table[src[0]], table[table[src[0]]]);
		*dst++ = table[*src++];
	}
}

extern const aPokemon TestingPikachu;
extern const char TypeNames[18][10];
//-----------------------------------------------------
//
// --------------
//
void DecodeOriginalMonster(const aPokemon *src, aPokemon *dst, int to)
{
	u32 i;
	u32 *srcsubs = (u32*)src->Data;
	u32 *dstsubs = (u32*)dst->Data;

	dst->Personal.Personal = src->Personal.Personal;
	dst->Personal.OTID = src->Personal.OTID;
	dst->Personal.Font = src->Personal.Font;
	dst->Personal.Sanity = src->Personal.Sanity;
	dst->Personal.Marking = src->Personal.Marking;
	dst->Personal.Checksum = src->Personal.Checksum;
	dst->Personal.Unknown2 = src->Personal.Unknown2;

	for(i=0; i<12; i++)
	{
		dstsubs[i] = srcsubs[i];
	}

	//dst->Status.Ailment = src->Status.Ailment;
	dst->Status.Ailment = 0;
	dst->Status.Level = src->Status.Level;
	dst->Status.Unknown = src->Status.Unknown;
	dst->Status.CurrentHP = src->Status.CurrentHP;
	dst->Status.TotalHP = src->Status.TotalHP;
	dst->Status.Attack = src->Status.Attack;
	dst->Status.Defense = src->Status.Defense;
	dst->Status.Speed = src->Status.Speed;
	dst->Status.SpAttack = src->Status.SpAttack;
	dst->Status.SpDefense = src->Status.SpDefense;

	if(to == 0)
	{
		if(dst->Personal.Font == 1)
		{
			Transcode(dst->Personal.Nickname, src->Personal.Nickname,10, PCS3JtoShiftPCS3J);
			Transcode(dst->Personal.OTName, src->Personal.OTName,7, PCS3JtoShiftPCS3J);
		}
		else
		{
			Transcode(dst->Personal.Nickname, src->Personal.Nickname,10, PCS3WtoWin1252);
			Transcode(dst->Personal.OTName, src->Personal.OTName,7, PCS3WtoWin1252);
		}
	}
	else
	{
		Transcode(dst->Personal.Nickname, src->Personal.Nickname,10, Win1252toPCS3W);
		Transcode(dst->Personal.OTName, src->Personal.OTName,7, Win1252toPCS3W);
	}
}

#ifndef NDEBUG
//-----------------------------------------------------
// WriteCompleteDocs
// -----------------
// Prints every single value in the 100-byte Pokémon
// structure to the logger. Every last fucking thing.
void WriteCompleteDocs(aPokemon *toshow)
{
	int i;

	AGBPrintf("\nPOKéMON INFO\n------------\n");
	int species = GetMonsterStats(toshow, pSpecies);
	AGBPrintf("Lv.%d %s", GetMonsterStats(toshow, pLevel), PokeNames[species]);
	if(BaseStats[species].Gender < 0xFF)
	{
		if((u8)toshow->Personal.Personal > BaseStats[species].Gender)
			AGBPrintf(" (male)");
		else
			AGBPrintf(" (female)");
	}

	AGBPrintf("\nMarkings: ");
	int marking = GetMonsterStats(toshow, pMarking);
	if(marking == 0)
	{
		AGBPrintf("none\n");
	} else
	{
		if(marking & 1) AGBPrintf("circle ");
		if(marking & 2) AGBPrintf("square ");
		if(marking & 4) AGBPrintf("triangle ");
		if(marking & 8) AGBPrintf("heart ");
		AGBPrintf("\n");
	}
	int ball = GetMonsterStats(toshow, pPokeBall);
	AGBPrintf("Pokéball: %d - %s\n", ball, items[ball].name);
	int item = GetMonsterStats(toshow, pHeldItem);

	AGBPrintf("No. %d\n", species);
	AGBPrintf("Name: %s\n", GetNickname(toshow));
	AGBPrintf("Type: %s", TypeNames[BaseStats[species].Type1]);
	if(BaseStats[species].Type1 != BaseStats[species].Type2)
		AGBPrintf("/%s", TypeNames[BaseStats[species].Type2]);
	AGBPrintf("\nOT: %s\n", toshow->Personal.OTName);
	AGBPrintf("IDNo: %d\n", (u16)toshow->Personal.OTID);
	AGBPrintf("Item: 0x%x - %s\n", item, items[item].name);

	AGBPrintf("\nTRAINER MEMO\n");
	AGBPrintf("%s nature.\n", natures[toshow->Personal.Personal % 25]);

	AGBPrintf("\nPOKéMON SKILLS\n--------------\n");
	AGBPrintf("HP: %d/%d\n", toshow->Status.CurrentHP, toshow->Status.TotalHP);
	AGBPrintf("Attack: %d\n", toshow->Status.Attack);
	AGBPrintf("Defense: %d\n", toshow->Status.Defense);
	AGBPrintf("SP.Atk: %d\n", toshow->Status.SpAttack);
	AGBPrintf("SP.Def: %d\n", toshow->Status.SpDefense);
	AGBPrintf("Speed: %d\n", toshow->Status.Speed);
	AGBPrintf("\nEXP.\n");
	AGBPrintf("EXP.Points: %d\n", GetMonsterStats(toshow, pExperience));

	int toNext = XPRequirements[(BaseStats[species].LevelSlope * 101) + toshow->Status.Level + 1] - GetMonsterStats(toshow, pExperience);
	AGBPrintf("Next Lv.: %d\n", toNext);

	AGBPrintf("\nABILITY\n");
	if(toshow->Personal.Personal % 2)	i = BaseStats[species].Ability2;
	else															i = BaseStats[species].Ability1;
	if(i==0)													i = BaseStats[species].Ability1;
	AGBPrintf("%s\n",Abilities[i]);
	AGBPrintf("%s\n",AbilityDescriptions[i]);

	AGBPrintf("\nKNOWN MOVES\n-----------\n");
	for(i = 0; i < 4; i++)
	{
		int atk = GetMonsterStats(toshow, pMove1 + i);
		int pp = GetMonsterStats(toshow, pPP1 + i);
		AGBPrintf("%s - %s\n", TypeNames[moves[atk].type], moveNames[atk]);
		AGBPrintf("  pp %d/%d\n", pp, moves[pp].pp);
	}

	AGBPrintf("\nHIDDEN DATA\n-----------\n");
	AGBPrintf("Font: %d\n", GetMonsterStats(toshow, pFont));
	AGBPrintf("Checksum: 0x%x\n", GetMonsterStats(toshow, pChecksum));
	AGBPrintf("Encryption key: 0x%x\n", toshow->Personal.Personal ^ toshow->Personal.OTID);
	AGBPrintf("PP Bonuses: 0x%x\n", GetMonsterStats(toshow, pPPBonus));
	AGBPrintf("Tameness: %d\n", GetMonsterStats(toshow, pTameness));
	AGBPrintf("Effort for HP: %d\n", GetMonsterStats(toshow, pEffortHP));
	AGBPrintf("Effort for Attack: %d\n", GetMonsterStats(toshow, pEffortAttack));
	AGBPrintf("Effort for Defense: %d\n", GetMonsterStats(toshow, pEffortDefense));
	AGBPrintf("Effort for Speed: %d\n", GetMonsterStats(toshow, pEffortSpeed));
	AGBPrintf("Effort for SpAttack: %d\n", GetMonsterStats(toshow, pEffortSPAtk));
	AGBPrintf("Effort for SpDefense: %d\n", GetMonsterStats(toshow, pEffortSPDef));
	AGBPrintf("Effort for Cool: %d\n", GetMonsterStats(toshow, pEffortCool));
	AGBPrintf("Effort for Beauty: %d\n", GetMonsterStats(toshow, pEffortBeauty));
	AGBPrintf("Effort for Cute: %d\n", GetMonsterStats(toshow, pEffortCute));
	AGBPrintf("Effort for Smart: %d\n", GetMonsterStats(toshow, pEffortSmart));
	AGBPrintf("Effort for Tough: %d\n", GetMonsterStats(toshow, pEffortTough));
	AGBPrintf("Effort for Feel: %d\n", GetMonsterStats(toshow, pEffortFeel));
	AGBPrintf("Caught by: %s\n", "BOY\0GIRL"+(GetMonsterStats(toshow, pTrainerGender)*4));
	AGBPrintf("DVs for HP: %d\n", GetMonsterStats(toshow, pDVHP));
	AGBPrintf("DVs for Attack: %d\n", GetMonsterStats(toshow, pDVAttack));
	AGBPrintf("DVs for Defense: %d\n", GetMonsterStats(toshow, pDVDefense));
	AGBPrintf("DVs for Speed: %d\n", GetMonsterStats(toshow, pDVSpeed));
	AGBPrintf("DVs for SpAttack: %d\n", GetMonsterStats(toshow, pDVSPAtk));
	AGBPrintf("DVs for SpDefense: %d\n", GetMonsterStats(toshow, pDVSPDef));
	AGBPrintf("Nicknamed: %d\n", GetMonsterStats(toshow, pNicknamed));
	AGBPrintf("Egg Flag: %d\n", GetMonsterStats(toshow, pEgg));
	//AGBPrintf("Ribbons: 0x%x\n", myM->Ribbons);

	unsigned char UnownLetters[] =
	{
		'A','B','C','D','E','F','G',
		'H','I','J','K','L','M','N',
		'O','P','Q','R','S','T','U',
		'V','W','X','Y','Z','?','!',
	};
	AGBPrintf("\nIf this was an Unown, it'd be #%d - '%c'.\n", GetUnownLetter(toshow->Personal.Personal), UnownLetters[GetUnownLetter(toshow->Personal.Personal)]);

	AGBPrintf("If this was a Wurmple, it'd evolve into ");
	if(toshow->Personal.Personal % 10 < 5)	AGBPrintf("Silcoon.\n");
	else																		AGBPrintf("Cascoon.\n");

	i = toshow->Status.Level * BaseStats[species].ExpYield / 7;
	AGBPrintf("Defeating this Pokémon in battle nets you roughly %d Exp.\n", i);

	AGBPrintf("\nIf you want to check, mon=0x%08x\n", toshow);

	AGBPrintf("\n\n");
}
#endif

//-----------------------------------------------------
//
// --------------
//
#ifdef NDEBUG
void RunTheTest()
{
	sayf(SYSTEM,"You seem to have compiled\nwithout AGBPrint support. Too bad.");
}
#else
void RunTheTest()
{
	sayf(SYSTEM,"Enable AGBPrint output and we'll\nprint out all about monster #1\x85");
	WriteCompleteDocs(&MyParty[0]);
	sayf(SYSTEM,"Now we'll import a hardcoded Pikachu\nripped out of Pokémon Fire Red\x85");
	DecodeOriginalMonster(&TestingPikachu, &MyParty[0],0);
	sayf(SYSTEM,"Watch AGBPrint again to see the\nPikachu from Fire Red\x85");
	WriteCompleteDocs(&MyParty[0]);
//	CreateMonsterInParty(pkPIKACHU,10);
//	CreateMonsterInParty(pkUNOWN,10);
	sndPlaySound(70,0);
}
#endif



void CreateBoxedMon(aBoxedMon *target, unsigned short species, unsigned char level)
{
/*
	aBoxedMon * mon = DecryptBoxedMon(target);
	ssPersonal *myP = (ssPersonal*)&mon->Personal;
	ssGrowth *myG;
	ssAttacks *myA;
	ssMisc *myM;
	aBaseStat *myBase = (aBaseStat*)&BaseStats[species];
	u32 l,r=0;
	const aLearnedMove * moveset;

	CpuFastClear(0, mon, sizeof(aBoxedMon));

	myP->Personal = rand();

	myG = GetGrowthSubstruct((aPokemon*)mon);
	myA = GetmovesSubstruct((aPokemon*)mon);
	myM = GetMiscSubstruct((aPokemon*)mon);

	myG->Species = species;
	sprintf(myP->Nickname, "%s", PokeNames[species]);
	sprintf(myP->OTName, "%s", PlayerName);
	myP->OTID = MyPlayer.trainerid;

	InjectXP((aPokemon*)mon, XPRequirements[(myBase->LevelSlope * 101) + level] + 1);

	moveset = GetRef_PokemonMoveset(species);
	for(l = 0; l < 100; l++)
	{
		if(moveset[l].Move == 0x1FF) break;

		if(moveset[l].Level <= level)
		{
			myA->Attack[r] = moveset[l].Move;
			myA->PP[r] = moves[moveset[l].Move].pp;
			r=(r+1) % 4;
		} else
		{
			break;
		}
	}

	myG->Tameness = myBase->BaseHappiness;
	myM->Pokeball = 4; //assume Poké Ball
	myM->TrainerGender = MyPlayer.gender;
	myM->Level = level;

	RecalculateChecksum((aPokemon*)mon);

	EncryptBoxedMon(mon);
*/
}

void SetNickname(aPokemon * toName, char * newName, int isActualNick)
{
//	SetMonsterStats(toName, pNickname, newName);
	int i;
	for(i = 0; i < 10; i++)
	{
		toName->Personal.Nickname[i] = newName[i];
		if(newName[i] == '\0')
			break;
	}
	AGBPrintf("SetNickname: %s\n", newName);
	AGBPrintf("Is an actual nick? %d\n", isActualNick);
	SetMonsterStats(toName, pNicknamed, isActualNick);
	AGBPrintf("Nicknamed: %d\n", GetMonsterStats(toName, pNicknamed));
}

char rufusdude[12];
char * GetNickname(aPokemon * toName)
{
	int i;
	for(i = 0; i < 10; i++)
	{
		rufusdude[i] = toName->Personal.Nickname[i];
		if(toName->Personal.Nickname[i] == '\0') break;
	}
	rufusdude[i] = '\0';
	return rufusdude;
}

int GetDexNumber(int national)
{
	extern const unsigned short NationalDex[];
	int ii;
	for(ii = 1; ii <= NationalDex[0]; ii++)
	{
		if(NationalDex[ii] == national)
			return ii;
	}
	return national;
}

int MonHasAbility(aPokemon * mon, int ability)
{
	int a;
	int species = GetMonsterStats(mon, pSpecies);

	if( mon->Personal.Personal % 2 )
	{
		a = BaseStats[species].Ability2;
		if(a == abilityNull)
			a = BaseStats[species].Ability1;
	}
	else
		a = BaseStats[species].Ability1;

	if(a == ability)
		return 1;

	return 0;
}

int PartyHasAbility(int ability)
{
	int i = GetPartySize(MyParty);
	while(i--)
	{
		if(MonHasAbility(&MyParty[i], ability))
			return 1;
	}
	return 0;
}

int PartyHasMove(int move)
{
	int a;
	int i = GetPartySize(MyParty);
	while(i--)
	{
		for(a = 0; a < 4; a++)
		{
			if(GetMonsterStats(&MyParty[i], pMove1 + a) == move) return i;
		}
	}
	return -1;
}

void CheckHatches()
{
	MyPlayer.stepsToHatch++;
	if(PartyHasAbility(abilityFlameBody) || PartyHasAbility(abilityMagmaArmor))
		MyPlayer.stepsToHatch++; //Body heat = <3

	if(MyPlayer.stepsToHatch == 128)
	{
		MyPlayer.stepsToHatch = 0;
		int i = GetPartySize(MyParty);
		if(i == 0) return;
		while(i--)
		{
			if(GetMonsterStats(&MyParty[i], pEgg))
			{
				int t = GetMonsterStats(&MyParty[i], pTameness);
				if(t)
				{
					t--;
					SetMonsterStats(&MyParty[i], pTameness, t);
				} else
				{
					//TODO	Run this as a script instead.
					sayf(SYSTEM, "Huh?");
					SetMonsterStats(&MyParty[i], pEgg, 0);
					int species = GetMonsterStats(&MyParty[i], pSpecies);
					sayf(SYSTEM, "%s hatched.", PokeNames[species]);
					SetNickname(&MyParty[i], (char*)PokeNames[species], 0);
					SetMonsterStats(&MyParty[i], pTameness, 120);
				}
			}
		}
	}
}

void CheckPoison()
{
	int monstersHurt = 0;
	int monstersDead = 0;
	MyPlayer.stepsToPoison++;
	if(MyPlayer.stepsToPoison == 5)
	{
		MyPlayer.stepsToPoison = 0;
		int i = GetPartySize(MyParty);
		if(i == 0) return;
		while(i--)
		{
			//sayf(SYSTEM, "Poison check on %s.", MyParty[i].Personal.Nickname);
			if(GetMonsterStats(&MyParty[i], pAilment) & 8 && GetMonsterStats(&MyParty[i], pCurrentHP))
			{
				SetMonsterStats(&MyParty[i], pCurrentHP, GetMonsterStats(&MyParty[i], pCurrentHP) - 1);
				if(GetMonsterStats(&MyParty[i], pCurrentHP))
				{
					monstersHurt++;
					//Do asynchronous mosaic effect here.
					int j;
					for(j = 0; j < 4; j++)
					{
						REG_MOSAIC = 3-j;
						DoVBlank();
					}
				} else
				{
					monstersDead++;
					sayf(SYSTEM, "%s fainted.", MyParty[i].Personal.Nickname);
				}
			}
		}
		if(monstersDead == GetPartySize(MyParty))
		{
			//out of mons
			sayf(SYSTEM, "TODO: White out here.");
		}
	}
}



void RecalculateChecksum(aPokemon *mon)
{
	ssPersonal *myP = (ssPersonal*)&mon->Personal;
	unsigned short *subs = (unsigned short*)mon->Data;
	int l;
	myP->Checksum = 0;
	for(l = 0; l < 24; l++)
	{
		myP->Checksum += subs[l];
	}
}

unsigned short GetMonsterChecksum(aPokemon *mon)
{
	unsigned short *subs = (unsigned short*)mon->Data;
	int l;
	unsigned short c = 0;
	for(l = 0; l < 24; l++)
	{
		c += subs[l];
	}
	return c;
}

//This one only works for Live Stats. Anything before that is passed to SetMonsterMainStats.
void SetMonsterStats(aPokemon *mon, unsigned int property, unsigned int value)
{
#ifndef NDEBUG
	if(mon == 0)
	{
		AGBPrintf("WARNING: Tried to write Pokémon property to nullpointer.\n");
	}
#endif

	switch(property)
	{
	case pAilment:
		mon->Status.Ailment = value;
		break;
	case pLevel:
		mon->Status.Level = value;
		break;
	case pCurrentHP:
		mon->Status.CurrentHP = value;
		break;
	case pTotalHP:
		mon->Status.TotalHP = value;
		break;
	case pAttack:
		mon->Status.Attack = value;
		break;
	case pDefense:
		mon->Status.Defense = value;
		break;
	case pSpeed:
		mon->Status.Speed = value;
		break;
	case pSPAttack:
		mon->Status.SpAttack = value;
		break;
	case pSPDefense:
		mon->Status.SpDefense = value;
		break;
	//case 64:
	//	mon->b55 = value;
	//	break;
	case 65:
		break;
	default:
		SetMonsterMainStats(mon, property, value);
	}
}

void SetMonsterMainStats(aPokemon *mn, unsigned int property, unsigned int value)
{
	aPokemon  * mon = (aPokemon*)mn;
	ssPersonal* myP = (ssPersonal*)&mon->Personal;
	ssGrowth  * myG = 0;
	ssAttacks * myA = 0;
	ssEffort  * myE = 0;
	ssMisc    * myM = 0;
	//u8 * data = (u8*)value;

	if(property > pMagicMarker)
	{
		mon = dDecryptMonster(mn);
		myG = (ssGrowth*) GetGAEMSubstruct(mon, 0);
		myA = (ssAttacks*)GetGAEMSubstruct(mon, 1);
		myE = (ssEffort*) GetGAEMSubstruct(mon, 2);
		myM = (ssMisc*)   GetGAEMSubstruct(mon, 3);
/*
		if(GetMonsterChecksum(mon) != myP->Checksum)
		{
			sayf(SYSTEM, "Checksum error trying to set\nproperty %d on 0x%x.\r\fExpected: %d.\nFound: %d.", property, mon, GetMonsterChecksum(mon), myP->Checksum);
			myP->Sanity = 7;
			myM->IsEgg = 1;
			eEncryptMonster(mon);
			return;
		}
*/
	}

	switch(property)
	{
	case pPersonal:
		myP->Personal = value;
		break;
	case pOTID:
		myP->OTID = value;
		break;
//	case pNickname:
//		for(ii = 0; ii < 10; ii++)
//			myP->Nickname[ii] = data[ii];
//		break;
	case pFont:
		myP->Font = value;
	//case 4
	//	mon->b13 = (mon->b13 & ~1) | (value & 1);
	//	break;
	//case 5
	//	mon->b13 = (mon->b13 & ~2) | (value & 1) << 1;
	//	break;
	//case 6
	//	mon->b13 = (mon->b13 & ~4) | (value & 1) << 2;
	//	break;
//	case pOTName:
//		for(ii = 0; ii < 7; ii++)
//			myP->OTName[ii] = data[ii];
//		break;
	case pMarking:
		myP->Marking = value;
		break;
	case pChecksum:
		myP->Checksum = value;
		break;
	//case 10
	//	myP->Padding = value;
	//	break;

	//Growth
	case pSpecies:
		myG->Species = value;
		//sayf(SYSTEM, "Species set to %d.", myG->Species);
		//if(myG->Species)
		//	myP->b13 |= 2;
		//else
		//	myP->b13 &=~2;
		break;
	case pHeldItem:
		myG->HeldItem = value;
		break;
	case pExperience:
		myG->Experience = value;
		break;
	case pPPBonus:
		myG->PPBonus = value;
		break;
	case pTameness:
		myG->Tameness = value;
		break;

	//Attack
	case pMove1:
	case pMove2:
	case pMove3:
	case pMove4:
		myA->Attack[property - pMove1] = value;
		break;
	case pPP1:
	case pPP2:
	case pPP3:
	case pPP4:
		myA->PP[property - pPP1] = value;
		break;

	//Effort
	case pEffortHP:
		myE->HP = value;
		break;
	case pEffortAttack:
		myE->Attack = value;
		break;
	case pEffortDefense:
		myE->Defense = value;
		break;
	case pEffortSpeed:
		myE->Speed = value;
		break;
	case pEffortSPAtk:
		myE->SpAttack = value;
		break;
	case pEffortSPDef:
		myE->SpDefense = value;
		break;
	case pEffortCool:
		myE->Cool = value;
		break;
	case pEffortBeauty:
		myE->Beauty = value;
		break;
	case pEffortCute:
		myE->Cute = value;
		break;
	case pEffortSmart:
		myE->Smart = value;
		break;
	case pEffortTough:
		myE->Tough = value;
		break;
	case pEffortFeel:
		myE->Feel = value;
		break;

	//Misc
	case pPokeRus:
		myM->PokeRus = value;
		break;
	case pLevelMet:
		myM->Level = value;
		break;
	case pLocationMet:
		myM->Location = value;
		break;
	case pPokeBall:
		myM->Pokeball = value;
		break;
	case pDVHP:
		myM->DVHP = value;
		break;
	case pDVAttack:
		myM->DVAttack = value;
		break;
	case pDVDefense:
		myM->DVDefense = value;
		break;
	case pDVSpeed:
		myM->DVSpeed = value;
		break;
	case pDVSPAtk:
		myM->DVSpAttack = value;
		break;
	case pDVSPDef:
		myM->DVSpDefense = value;
		break;
	case pNicknamed:
		myM->IsNicknamed = value;
		break;
	case pEgg:
		myM->IsEgg = value;
		break;
	case pOriginGame:
		myM->OriginGame = value;
		break;
	}

	if(property > pMagicMarker)
	{
		myP->Checksum = GetMonsterChecksum(mon);
		eEncryptMonster(mon);
	}
	return;
}

unsigned int GetMonsterStats(aPokemon *mon, unsigned int property)
{
#ifndef NDEBUG
	if(mon == 0)
	{
		AGBPrintf("WARNING: Tried to read Pokémon property from nullpointer.\n");
		return 0;
	}
#endif

	switch(property)
	{
	case pAilment:
		return mon->Status.Ailment;
	case pLevel:
		return mon->Status.Level;
	case pCurrentHP:
		return mon->Status.CurrentHP;
	case pTotalHP:
		return mon->Status.TotalHP;
	case pAttack:
		return mon->Status.Attack;
	case pDefense:
		return mon->Status.Defense;
	case pSpeed:
		return mon->Status.Speed;
	case pSPAttack:
		return mon->Status.SpAttack;
	case pSPDefense:
		return mon->Status.SpDefense;
	default:
		return GetMonsterMainStats(mon, property);
	}
	return 0;
}

unsigned int GetMonsterMainStats(aPokemon *mn, unsigned int property)
{
	unsigned int ii;
	aPokemon  * mon = (aPokemon*)mn;
	ssPersonal* myP = (ssPersonal*)&mon->Personal;
	ssGrowth  * myG = 0;
	ssAttacks * myA = 0;
	ssEffort  * myE = 0;
	ssMisc    * myM = 0;

	if(property > pMagicMarker)
	{
		mon = dDecryptMonster(mn);
		myG = (ssGrowth*) GetGAEMSubstruct(mon, 0);
		myA = (ssAttacks*)GetGAEMSubstruct(mon, 1);
		myE = (ssEffort*) GetGAEMSubstruct(mon, 2);
		myM = (ssMisc*)   GetGAEMSubstruct(mon, 3);
/*
		if(GetMonsterChecksum(mon) != myP->Checksum)
		{
			sayf(SYSTEM, "Checksum error trying to get\nproperty %d on 0x%x.\r\fExpected: %d.\nFound: %d.", property, mon, GetMonsterChecksum(mon), myP->Checksum);
			myP->Sanity = 7;
			myM->IsEgg = 1;
			eEncryptMonster(mon);
			return 0;
		}
*/
	}

	ii = 0;

	switch(property)
	{
	case pPersonal:
		ii = myP->Personal;
		break;
	case pOTID:
		ii = myP->OTID;
		break;
//	case pNickname:
//		for(ii = 0; ii < 10; ii++)
//			data[ii] = myP->Nickname[ii];
//		break;
	case pFont:
		ii = myP->Font;
		break;
//	case pOTName:
//		for(ii = 0; ii < 7; ii++)
//			data[ii] = myP->OTName[ii];
//		break;
	case pMarking:
		ii = myP->Marking;
		break;
	case pChecksum:
		ii = myP->Checksum;
		break;

	//Growth
	case pSpecies:
		ii = myG->Species;
		//sayf(SYSTEM, "Species get to %d.", ii);
		break;
	case pHeldItem:
		ii = myG->HeldItem;
		break;
	case pExperience:
		ii = myG->Experience;
		//sayf(SYSTEM, "Exp get to %d.", ii);
		break;
	case pPPBonus:
		ii = myG->PPBonus;
		break;
	case pTameness:
		ii = myG->Tameness;
		break;

	//Attack
	case pMove1:
	case pMove2:
	case pMove3:
	case pMove4:
		ii = myA->Attack[property - pMove1];
		break;
	case pPP1:
	case pPP2:
	case pPP3:
	case pPP4:
		ii = myA->PP[property - pPP1];
		break;

	//Effort
	case pEffortHP:
		ii = myE->HP;
		break;
	case pEffortAttack:
		ii = myE->Attack;
		break;
	case pEffortDefense:
		ii = myE->Defense;
		break;
	case pEffortSpeed:
		ii = myE->Speed;
		break;
	case pEffortSPAtk:
		ii = myE->SpAttack;
		break;
	case pEffortSPDef:
		ii = myE->SpDefense;
		break;
	case pEffortCool:
		ii = myE->Cool;
		break;
	case pEffortBeauty:
		ii = myE->Beauty;
		break;
	case pEffortCute:
		ii = myE->Cute;
		break;
	case pEffortSmart:
		ii = myE->Smart;
		break;
	case pEffortTough:
		ii = myE->Tough;
		break;
	case pEffortFeel:
		ii = myE->Feel;
		break;

	//Misc
	case pPokeRus:
		ii = myM->PokeRus;
		break;
	case pLevelMet:
		ii = myM->Level;
		break;
	case pLocationMet:
		ii = myM->Location;
		break;
	case pPokeBall:
		ii = myM->Pokeball;
		break;
	case pTrainerGender:
		ii = myM->TrainerGender;
		break;
	case pDVHP:
		ii = myM->DVHP;
		break;
	case pDVAttack:
		ii = myM->DVAttack;
		break;
	case pDVDefense:
		ii = myM->DVDefense;
		break;
	case pDVSpeed:
		ii = myM->DVSpeed;
		break;
	case pDVSPAtk:
		ii = myM->DVSpAttack;
		break;
	case pDVSPDef:
		ii = myM->DVSpDefense;
		break;
	case pNicknamed:
		ii = myM->IsNicknamed;
		break;
	case pEgg:
		ii = myM->IsEgg;
		break;
	case pOriginGame:
		ii = myM->OriginGame;
		break;
	}

	if(property > pMagicMarker)
	{
		//myP->Checksum = GetMonsterChecksum(mon); //doesn't change
		eEncryptMonster(mon);
	}
	return ii;
}

int CheckEvolution(aPokemon * mon, int EvoTrigger, int level)
{
	int evo = 0;

	u8	tameness, beauty;
	u16 helditem;
	int personal;

	int i;

	u16 species = GetMonsterStats(mon, pSpecies);

	u16* pEvos = GetEvolutions(species);
	u16 nrOfEvos = *pEvos++;

	//enigma check


	#define EVO_CAUSE pEvos[(i*4)]
	#define EVO_PARAM pEvos[((i*4)+1)]
	#define EVO_TARGET pEvos[((i*4)+2)]

// If "mon" has evolutions
	if(nrOfEvos)
	{
		if(EvoTrigger == 0) //Triggered by level-up
		{
			level = GetMonsterStats(mon, pLevel);
			tameness = GetMonsterStats(mon, pTameness);
			for(i = 0; i < nrOfEvos; i++)
			{
				switch(EVO_CAUSE)
				{
					case evoHappy:
						if(tameness >= 220)
							evo = EVO_TARGET;
						break;
					case evoLevel:
						if(EVO_PARAM <= level)
							evo = EVO_TARGET;
						break;
					case evoAttGtDef:
						if(EVO_PARAM <= level && GetMonsterStats(mon,pAttack)  > GetMonsterStats(mon,pDefense))
							evo = EVO_TARGET;
						break;
					case evoAttEqDef:
						if(EVO_PARAM <= level && GetMonsterStats(mon,pAttack) == GetMonsterStats(mon,pDefense))
							evo = EVO_TARGET;
						break;
					case evoAttLtDef:
						if(EVO_PARAM <= level && GetMonsterStats(mon,pAttack) <  GetMonsterStats(mon,pDefense))
							evo = EVO_TARGET;
						break;
					case evoHighPers:
						personal = GetMonsterStats(mon, pPersonal);

						if(EVO_PARAM < level && personal % 10 <= 4) //???	Did you mean "<= level"?
							evo = EVO_TARGET;
						break;
					case evoLowPers:
						personal = GetMonsterStats(mon, pPersonal);

						if(EVO_PARAM < level && personal % 10  > 4) //???	Did you mean "<= level"?
							evo = EVO_TARGET;
						break;
					case evoAllowCreate:
						if(EVO_PARAM <= level)
							evo = EVO_TARGET;
						break;
					case evoBeauty:
						beauty = GetMonsterStats(mon, pEffortBeauty);

						if(EVO_PARAM < beauty)
							evo = EVO_TARGET;
						break;
				}
			}
		}
		else if(EvoTrigger == 1) //Triggered by trade
		{
			for(i = 0; i < 4; i++)
			{
				helditem = GetMonsterStats(mon, pHeldItem);
				if((EVO_CAUSE == evoTrade) || (EVO_CAUSE == evoItemTrade && EVO_PARAM == helditem))
					evo = EVO_TARGET;
			}
		}
		else if(EvoTrigger == 2) //Triggered by an item
		{
			for(i = 0; i < 4; i++)
			{
				//if(EVO_CAUSE == EVOLUTION_ITEM && EVO_PARAM < level) //???	Are you sure?
				if(EVO_CAUSE == evoItem && EVO_PARAM == level)
					evo = EVO_TARGET;
			}
		}
	}
	return evo;
}

int LearnMove(aPokemon * victim, int move, int slot)
{
	SetMonsterStats(&MyParty[2], pMove1 + slot, move);
	SetMonsterStats(&MyParty[2], pPP1 + slot, moves[move].pp);
	return 1;
}
