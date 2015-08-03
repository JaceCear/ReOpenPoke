#ifndef __POKEMANAGER
#define __POKEMANAGER

typedef enum eTypes
{
	tpNormal, tpFighting, tpFlying, tpPoison, tpGround, tpRock, tpBug, tpGhost, tpSteel,
	tpNone,
	tpFire, tpWater, tpGrass, tpElectric, tpPsychic, tpIce, tpDragon, tpDark
} eTypes;

typedef enum eLevelGradients
{
	gdMedium, gdFlux, gdErratic, gdMidSlow, gdQuick, gdSlow, gdUnk1, gdUnk2
} eLevelGradients;

typedef enum eEggGroups
{
	eggNull,
	eggMonster, eggWater1, eggBug, eggFlying, eggGround, eggFairy, eggPlant, //lol eggplant
	eggHuman, eggWater3, eggMineral, eggIndeterminate, eggWater2,
	eggDitto, eggDragon, eggNone
} eEggGroups;

extern const unsigned short EggMoves[];

// --------------------------------------------------------------------
// EVOLUTION
// --------------------------------------------------------------------

typedef enum eEvolutionTypes
{
	evoNull = 0, //Pokémon does not evolve at all or given slot is unused

//These have null parameters and trigger when the proper stat is maxed out
	evoHappy = 1, //Pokémon evolves if happy enough
	evoHappyDay = 2, //Pokémon evolves if happy enough in daytime
	evoHappyNight = 3, //Pokémon evolves if happy enough in nighttime

//These have non-null parameters and trigger when a specific level is reached
	evoLevel = 4, //Pokémon evolves at given level
	evoAttGtDef = 8, //Pokémon evolves if attack is greater than defense
	evoAttEqDef = 9, //Pokémon evolves if attack equals defense
	evoAttLtDef = 10, //Pokémon evolves if attack is lower than defense
	evoHighPers = 11, //Pokémon evolves if personality is INSERT FORMULA HERE
	evoLowPers = 12, //Pokémon evolves if personality is INSERT FORMULA HERE
	evoAllowCreate = 13, //Something about Ninjask
	evoCreateExtra = 14, //Something about Shedinja

//These trigger for other reasons
	evoTrade = 5, //Pokémon evolves when traded
	evoItemTrade = 6, //Pokémon evolves when traded while holding an item
	evoItem = 7, //Pokémon evolves when an item is used on it
	evoBeauty = 15, //Pokémon evolves if beauty stat reaches Param
} eEvolutionTypes;

// --------------------------------------------------------------------
// DEXENTRY
// --------------------------------------------------------------------

typedef struct aDexEntry
{
	char species[12];		//Monster species - "MOUSE POKéMON"
	unsigned short height;	//Height in decimeters
	unsigned short weight;	//Weight in	hectograms
	char *text;
	char *text2;
	unsigned short moffset;	//Size comparison offset for monster
	unsigned short mscale;	//Size comparison scale for monster (8.8 fixed)
	unsigned short toffset;	//Size comparison offset for trainer
	unsigned short tscale;	//Size comparison scale for trainer (8.8 fixed)
} aDexEntry;

extern const aDexEntry DexEntries[];

// --------------------------------------------------------------------
// BASESTAT
// --------------------------------------------------------------------

typedef struct aBaseStat
{
	unsigned char BaseHP;			//HP for lv.1
	unsigned char BaseAttack;		//Attack for lv.1
	unsigned char BaseDefense;		//Defense for lv.1
	unsigned char BaseSpeed;		//Speed for lv.1
	unsigned char BaseSpAttack;		//Special Attack for lv.1
	unsigned char BaseSpDef;		//Special Defense for lv.1
	unsigned char Type1;			//Primary type
	unsigned char Type2;			//Secondary type
	unsigned char CatchRate;		//Base catch rate
	unsigned char ExpYield;			//Base experience given
	unsigned short EffortYield;		//Effort points given
	unsigned short Item1;			//Item
	unsigned short Item2;			//Item
	unsigned char Gender;			//Chance of being female
	unsigned char HatchSteps;		//Steps needed to hatch egg
	unsigned char BaseHappiness;	//Starting happiness
	unsigned char LevelSlope;		//Experience graph to use
	unsigned char EggGroup1;		//Primary breeding egg group
	unsigned char EggGroup2;		//Secondary breeding egg group
	unsigned char Ability1;			//Primary ability
	unsigned char Ability2;			//Secondary ability
	unsigned char SafariRate;
	unsigned char Color;
} aBaseStat;

extern const aBaseStat BaseStats[];

// --------------------------------------------------------------------
// POKEPIC
// --------------------------------------------------------------------

extern const unsigned short * const PokePicsFront[];
extern const unsigned short * const PokePicsPalette[];
extern const unsigned short * const PokePicsBack[];
extern const unsigned short * const PokePicsShinyPal[];

typedef struct aRoamer
{
	unsigned short species;	//Species of roaming monster
	unsigned char level;	//Level of roaming monster
	unsigned short hp;		//Health since last encounter
	unsigned short map;		//Map roaming monster is currently on
} aRoamer;
extern aRoamer Roamers[16];

//Move flags
#define MOV_FLINCH	0x01	//Move may cause opponent to flinch if user has a King's Rock
#define MOV_CHECK		0x02	//Move is checked for accuracy
#define MOV_SNATCH	0x04	//Move can be reflected back by opponent's Snatch Move
#define MOV_COAT		0x08	//Move can be reflected back by opponent's Magic Coat Move
#define MOV_PROTECT	0x10	//Move can be defended against by Protect and Detect
#define MOV_TOUCH		0x20	//Move requires physically touching the target
#define MOV_SIMPLE	0x33	//Move is direct, checked for accuracy, causes flinching and is protectable
#define MOV_NOTOUCH	0x13	//Move is checked for accuracy, causes flinching and is protectable
#define MOV_BEAM		0x12	//Move is checked for accuracy and is protectable, good for beam Moves

#define TGT_SELECT	0x00	//Just the opponent, or user's selection if Double Battle
#define TGT_SPECIAL	0x01	//Determined by the move
#define TGT_ERROR		0x02	//Not used
#define TGT_RANDOM	0x04	//Randomly picked
#define TGT_ALLOPS	0x08	//All opponents
#define TGT_USER		0x10	//Move's user
#define TGT_OTHERS	0x20	//Everybody but the user
#define TGT_SPIKES	0x40	//Opponent's field

typedef struct aMove
{
	unsigned char effect;		//Effect index
	unsigned char basepower;	//Base damage
	unsigned char type;			//Type of move
	unsigned char accuracy;		//Base accuracy

	unsigned char pp;				//Starting amount of PP
	unsigned char effectaccuracy;	//Chance of additional effect occuring
	unsigned char target;			//Target, see TGT_xxx list
	unsigned char priority;			//Base priority

	unsigned char flags;		//See ATK_xxx list
} aMove;

extern const aMove moves[];
extern const char moveNames[][13];

typedef struct aLearnedMove
{
	u16 Level:7;
	u16 Move:9;
} aLearnedMove;

extern const char PokeNames[][11];

extern const char TypeNames[18][10];
extern const unsigned char TypeAdvantages[];

// --------------------------------------------------------------------
// MISC
// --------------------------------------------------------------------

typedef enum ePartyScreenModes
{
	psmGeneral,
	psmBattleSwitch,
	psmTeachTM,
	psmSelectOnly,
} ePartyScreenModes;

extern void LoadPokemonPic(unsigned short index, unsigned char flags, u16* imgTarget, u16* palTarget, unsigned long pv);
extern void SetupPokemonSprite(u8 slot);
extern int GetPartySize();
extern void HealParty();

#define GetPokemonDescription(x) DexEntries[x].text
#define GetPokemonSpecies(x) DexEntries[x].species
#define GetPokemonName(x) PokeNames[x]

#define LPP_NORMAL 0
#define LPP_BACK 1
#define LPP_SHINY 2
#define LPP_FEMALE 4

/*
	Substruct orders
	----------------
	Growth, Attacks, Effort, Misc
	00. GAEM  06. AGEM  12. EGAM  18. MGAE
	01. GAME  07. AGME  13. EGMA  19. MGEA
	02. GEAM  08. AEGM  14. EAGM  20. MAGE
	03. GEMA  09. AEMG  15. EAMG  21. MAEG
	04. GMAE  10. AMGE  16. EMGA  22. MEGA
	05. GMEA  11. AMEG  17. EMAG  23. MEAG
*/

#define NATURE(x) (x % 25)
/*
	Natures list
	------------
	00. Hardy		01. Lonely		02. Brave
	03. Adamant		04. Naughty		05. Bold
	06. Docile		07. Relaxed		08. Impish
	09. Lax			0A. Timid		0B. Hasty
	0C. Serious		0D. Jolly		0E. Naive
	0F. Modest		10. Mild		11. Quiet
	12. Bashful		13. Rash		14. Calm
	15. Gentle		16. Sassy		17. Careful
	18. Quirky		19. Frivolous	1A.	Meticulous
	19 and 1A only in D/P
*/
extern const char * const natures[0x19];
extern const signed char natureBonus[25][5];

extern const aLearnedMove * const MoveSets[];

/*
	A NOTE ON ENCRYPTION
	--------------------
	The entire data structure is encrypted by
	XORing the entire Trainer ID with the
	personality value, then XORing the resulting
	value with the data, one long value at a time.
	The same process is used to decrypt the
	encrypted data.
	!!!The correct checksum is found
	by summing the original values, not the
	encrypted values!!!¯¯¯¯¯¯
*/

typedef struct ssPersonal
{
	unsigned long Personal;		//The personality value controls many things,
								//including gender, Unown letter, Spinda's dots,
								//nature, and others.
	unsigned long OTID;			//The Original Trainer's ID Number. Part of the
								//XOR encryption key for the data section, also
								//used in shiny determination and the lottery.
	char Nickname[10];
	char Font;
	char Sanity;
	char OTName[7];
	unsigned char Marking;		//The marks you see in the storage box.
								//bit 0: Circle          bit 1: Square
								//bit 2: Triangle        bit 3: Heart
	unsigned short Checksum;	//The checksum is of the 48-byte data section in
								//the structure. It is computed by simply adding
								//all the unencrypted values one short at a time.
								//If this value does not match the real checksum,
								//the Pokémon is interpreted as a Bad egg.
	unsigned short Unknown2;
} ssPersonal;

typedef struct ssStatus
{
//	unsigned long Ailment;		//The Pokémon's status ailments are stored as follows:
								//0-2: Sleep bits. Indicates turns of sleep,
								//so 111b = 7 turns, 101b = 5 turns, etc.
								//3: Poison      4: Burned    5: Frozen
								//6: Paralysis   7: Bad poison
	union
	{
		unsigned long Ailment;
		struct
		{
			unsigned long AilmentSleep:3;
			unsigned long AilmentPoison:1; //0x08
			unsigned long AilmentBurned:1; //0x10
			unsigned long AilmentFrozen:1; //0x20
			unsigned long AilmentParalysis:1; //0x40
			unsigned long AilmentBadPoison:1; //0x80
		};
	};

	unsigned char Level;
	unsigned char Unknown;
	unsigned short CurrentHP;
	unsigned short TotalHP;
	unsigned short Attack;
	unsigned short Defense;
	unsigned short Speed;
	unsigned short SpAttack;
	unsigned short SpDefense;
} ssStatus;

typedef struct aPokemon
{
	ssPersonal Personal;
	char Data[48];	//Cast into substructs
	ssStatus Status;
} aPokemon;

typedef struct aBoxedMon
{
	ssPersonal Personal;
	char Data[48];	//Also cast into substructs
	//No status struct here to save space.
} aBoxedMon;

typedef struct ssGrowth
{
	unsigned short Species;
	unsigned short HeldItem;
	unsigned long Experience;
	union
	{
		unsigned char PPBonus;	//The PP bonuses byte stores the number of PP Ups
														//used for each attack. Two bits per attack,
														//starting with the first attack from the least
														//significant bits upward to the last attack.
		struct
		{
			unsigned char PPUp1:2;
			unsigned char PPUp2:2;
			unsigned char PPUp3:2;
			unsigned char PPUp4:2;
		};
	};
	unsigned char Tameness;
} ssGrowth;

typedef struct ssAttacks
{
	unsigned short Attack[4];
	unsigned char PP[4];
} ssAttacks;

typedef struct ssEffort
{
	unsigned char HP;
	unsigned char Attack;
	unsigned char Defense;
	unsigned char Speed;
	unsigned char SpAttack;
	unsigned char SpDefense;
	unsigned char Cool;
	unsigned char Beauty;
	unsigned char Cute;
	unsigned char Smart;
	unsigned char Tough;
	unsigned char Feel;
} ssEffort;

typedef struct ssMisc
{
	union
	{
		unsigned char PokeRus;
		struct
		{
			u8 VirusTime:4;
			u8 VirusImmunity:4;
		};
	};

	u32 Location:8;

	u32 Level:7;
	u32 OriginGame:4;
	u32 Pokeball:4;
	u32 TrainerGender:1;
// 87654321
// G PPPP

	u32 DVHP:5;
	u32 DVAttack:5;
	u32 DVDefense:5;
	u32 DVSpeed:5;
	u32 DVSpAttack:5;
	u32 DVSpDefense:5;
	u32 IsNicknamed:1;
	u32 IsEgg:1;

	u32 Ribbons:32;
} ssMisc;

extern aPokemon HisParty[6] INEWRAM;	//Opponent's team, also wild Pokémon
extern aPokemon MyParty[7] INEWRAM;		//Player's team
extern aBoxedMon MyBox[14*30] INEWRAM;	//Player's boxes
extern aPokemon InMyHand;				//For box management, the Pokémon currently "held".
extern aPokemon DaycareMon[2] INEWRAM;

inline ssPersonal	*GetPersonalStruct(aPokemon *mon);
inline ssStatus		*GetStatusStruct(aPokemon *mon);
//inline ssGrowth		*GetGrowthSubstruct(aPokemon *mon);
//inline ssAttacks	*GetAttacksSubstruct(aPokemon *mon);
//inline ssEffort		*GetEffortSubstruct(aPokemon *mon);
//inline ssMisc		*GetMiscSubstruct(aPokemon *mon);
extern void			*GetGAEMSubstruct(aPokemon *mon, int type);

extern void UpdateLiveStats(aPokemon *mon);
extern void CreateMonster(aPokemon *target, int species, int level);
extern unsigned short CreateMonsterInParty(int species, int level);
extern int IsShiny(aPokemon *mon);
extern int GetPPForMove(aPokemon *mon, int move);
extern int LearnMove(aPokemon *mon, int mid, int slot);
extern void SwitchInParty(u16 from, u16 to);
extern void SwitchInBox(u16 from, u16 to);
extern void MoveToParty(u16 from, u16 to);
extern void MoveToBox(u16 from, u16 to);
extern void DrawPartyScreen(int sel, int purpose, int additional);
extern int ShowParty(int purpose, int additional);
extern int SelectLearnMove(aPokemon *mon, int mid);
//extern aPokemon * DecryptMonster(aPokemon *mon);
//extern void EncryptMonster(aPokemon *mon);
//extern aBoxedMon * DecryptBoxedMon(aBoxedMon *mon);
//extern void EncryptBoxedMon(aBoxedMon *mon);
extern int CanLearnTM(int species, int tmno);
extern void Transcode(void *in_dst, const void *in_src, unsigned int length, const unsigned char *table);
extern void ShowBoxes();
extern int GetUnownLetter(unsigned long pv);
extern void HandleUnown(aPokemon * toFix, int flags, int targetSlot);
extern void SetNickname(aPokemon * toName, char * newName, int isActualNick);
extern char * GetNickname(aPokemon * toName);

#ifdef NDEBUG
#define WriteCompleteDocs(foo)
#else
extern void WriteCompleteDocs(aPokemon *toshow);
#endif

extern void SetMonsterStats(aPokemon *mon, unsigned int property, unsigned int value);
extern void SetMonsterMainStats(aPokemon *mn, unsigned int property, unsigned int value);
extern unsigned int GetMonsterStats(aPokemon *mon, unsigned int property);
extern unsigned int GetMonsterMainStats(aPokemon *mn, unsigned int property);

extern int CheckEvolution(aPokemon * mon, int EvoTrigger, int level);

extern int MonHasAbility(aPokemon * mon, int ability);


extern const unsigned char PCS3WtoWin1252[256];
extern const unsigned char Win1252toPCS3W[256];
extern const unsigned char PCS3JtoShiftPCS3J[256];

#endif	// __POKE_MANAGER
