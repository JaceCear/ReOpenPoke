typedef struct aTrainerMonster
{
	u8 ai;
	u8 level;
	u16 species;
	u16 moves[4];
	u16 item;
} aTrainerMonster;

typedef struct aTrainer
{
	u8 kind;
	u8 music;
	u8 image;
	char name[12];
	u16 items[4];
	u32 dual;
	u32 flags;
	u32 partysize;
	aTrainerMonster *pack;
} aTrainer;


//typedef struct aTrainerTaunts
//{
//	char * taunts[6];
//} aTrainerTaunts;

typedef struct aBattle
{
	int decision;
	int trainer;
	int roamer;
	int switching;
	int trainerindex;
	int internalbattle;
	int runCommand;
	int background;
	int weather;
	int weatherduration;
	int duringBattle;
	int doublebattle;
	int usepriority;
	int cashwon;
	int environment;
	void * onWin;
} aBattle;
typedef struct aBattleSide
{
	int effLightScreen;
	int effMist;
	int effSpikes;
	int effReflect;
	int effSafeguard;
} aBattleSide;
typedef struct aDamageState
{
	int critical;
	int typemod;
	int calcdamage;
	int hplost;
	int endured;
	int focusbandused;
	int focusband;
	int substitute;
} aDamageState;
typedef struct fighter
{
	aPokemon * mon;
	int lastused;
	int ability;
	int currentMove;
	int species;
	int lastHPLost;
	int lastAttacker;
	int lastMoveCalled;
	int lastMoveUsed;
	int lastMoveUsedSketch;
	int spriteVOffset;

	int convertedType; //for 0x1E Conversion and 0x5D Conversion-2

	int effAttract;
	int effBide;
	int effBideDamage;
	int effBideTarget;
	int effCharge;
	int effChoiceBand;
	int effConfusion;
	int effConversion2Move;
	int effConversion2Type;
	int effCounter;
	int effCounterTarget;
	int effCurse;
	int effDefenseCurl;
	int effDestinyBond;
	int effDisableMove;
	int effDisableTimer;
	int effDive;
	int effEncore;
	int effEncoreIndex;
	int effEndure;
	int effFlashFire;
	int effFlinch;
	int effFocusEnergy;
	int effFollowMe;
	int effForesight;
	int effFutureSight;
	int effFutureSightDamage;
	int effFutureSightMove;
	int effFutureSightUser;
	int effFuryCutter;
	int effGrudge;
	int effHelpingHand;
	int effHyperBeam;
	int effImprison;
	int effIngrain;
	int effLeechSeed;
	int effLightScreen;
	int effLockOn;
	int effLockOnPos;
	int effMagicCoat;
	int effMeanLook;
	int effMinimize;
	int effMirrorCoat;
	int effMirrorCoatTarget;
	int effMirrorMove;
	int effMist;
	int effMudSport;
	int effMultiTurn;
	int effMultiTurnAttack;
	int effMultiTurnUser;
	int effNightmare;
	int effOutrage;
	int effPerishSong;
	int effPinch;
	int effProtect;
	int effProtectRate;
	int effPursuit;
	int effRage;
	int effRecycleItem;
	int effRevenge;
	int effRollout;
	int effSnatch;
	int effStockpile;
	int effSubstitute;
	int effTaunt;
	int effTorment;
	int effToxic;
	int effTrace;
	int effTransform;
	int effTruant;
	int effTwoTurnAttack;
	int effUproar;
	int effWaterSport;
	int effWish;
	int effWishMaker;
	int effYawn;
	int effTimeStop;
	int effTimeStopDmg;

	int turncount;
	int pokemonIndex;
	int stageAttack;
	int stageDefense;
	int stageSpeed;
	int stageSpAtk;
	int stageSpDef;
	int stageAccuracy;
	int stageEvasiveness;
	aDamageState damagestate;
} aFighter;

#define SINGLE_BTL_PLAYER_HPOS	39
#define SINGLE_BTL_PLAYER_VPOS	48

#define SINGLE_BTL_OPP_HPOS	144
#define SINGLE_BTL_OPP_VPOS	  8

#define WEATHER_SUNNYDAY 1
#define WEATHER_RAINDANCE 2
#define WEATHER_SANDSTORM 3
#define WEATHER_HAIL 4

#define SEND_SCROLLWIN	1
#define SEND_CRY		2
#define SEND_POOF		8
#define SEND_SCROLLCRY	SEND_SCROLLWIN | SEND_CRY
#define SEND_ALL		SEND_SCROLLWIN | SEND_CRY | SEND_POOF

#define COMMAND_FIGHT	1
#define COMMAND_ITEM 2
#define COMMAND_SWITCH 3
#define COMMAND_RUN 4
#define CHOICE_NONE 0
#define CHOICE_MOVE 1
#define CHOICE_SWITCH 2
#define CHOICE_RUN 3
#define CHOICE_ITEM 4

#define true 1
#define false 0

#define STAT_ATTACK 0
#define STAT_DEFENSE 1
#define STAT_SPEED 2
#define STAT_SPATK 3
#define STAT_SPDEF 4
#define STAT_ACCURACY 5
#define STAT_EVASIVENESS 6

#define CALCDMG_NOCRITICAL 1
#define CALCDMG_NOTYPES 2
#define CALCDMG_NOWEIGHTING 4
#define CALCDMG_IGNOREPKMNTYPES 8

#define BTLENV_NONE	0
#define BTLENV_GRASS 1
#define BTLENV_TALLGRASS 2
#define BTLENV_MOVINGWATER 3
#define BTLENV_STILLWATER 4
#define BTLENV_UNDERWATER 5
#define BTLENV_ROCK 6
#define BTLENV_CAVE 7
#define BTLENV_SAND 8

extern const char TypeNames[18][10];

extern u32 TotalFrames; //need this to seed the randomizer later

int Battle(int kind, int opponent, int background, void * onWin);
int battle_IsOpposing(int index);
int GetTypeAdvantage1(int atktype, int opptype);
int GetTypeAdvantage2(int atktype, int opptype1, int opptype2);

void	battle_OpenAnimation();
void	battle_SendOut(int side, int partyindex, int flags);
aPokemon * battle_Party(int index);
int		battle_MaxLevel(aPokemon * party);
int		battle_CheckGlobalAbility(int a);
int		battle_Weather();
void	battle_GainEXP();
int		battle_Run(int idxPokemon, int duringBattle);
int		battle_RegisterMove(int idxPokemon, int idxMove);
void	battle_OnActiveAll();
int		battle_OnActiveOne(int index);
int		battle_CanSwitchLax(int idxPokemon, int idxTo, int showMessages);
int		battle_CanSwitch(int idxPokemon, int idxTo, int showMessages);
int		battle_RegisterSwitch(int idxPokemon, int idxTo);
int		battle_RegisterItem(int idxPokemon, int idxTo);
int		battle_RegisterTarget(int idxPokemon, int idxTarget);
void	battle_SortPriorities(int * prios);
int		battle_AllFainted(aPokemon * party);
int		battle_FindPlayerBattler(int pkmnIndex);
void	battle_Switch();
void	battle_CommandPhase();
int		battle_ChoseMove(int i, int moveid);
void	battle_AttackPhase();
void	battle_EndOfRoundPhase();
int		battle_CanShowCommands(int idxPokemon);
int		battle_CanShowFightMenu(int idxPokemon);
int		battle_CanChooseMove(int idxPokemon, int idxMove, int showMessages);
void	battle_AutoChooseMove(int idxPokemon);
int		battle_IsDoubleBattler(int index);
void	battle_AbilityEffect(int move, int user, int target);
int		battle_IsMoveSensible(int index, int dice);

const char * fighters_This(int index);
void	fighters_UpdateParticipants(int index);
void	fighters_BeginTurn(int index);
void	fighters_EndTurn(int index);
void	fighters_CancelMoves(int index);
int		fighters_TryUseMove(int index);
void	fighters_AbilityCureCheck(int index);
void	fighters_BerryCureCheck(int index, int hpcure);
int		fighters_SuccessCheck(int mid, int user, int target, int accuracy);
int		fighters_OwnSide(int index);
int		fighters_OpposingSide(int index);
int		fighters_IsOpposing(int index, int i);
int		fighters_Partner(int index);
int		fighters_Opposing1(int index);
int		fighters_Opposing2(int index);
int		fighters_OppositeOpposing(int index);
int		fighters_GetTargetLen(int * targets);
int		__moves_AddTarget(int mid, int * targets, int target);
void	fighters_RandomTarget(int index, int * targets);
int		fighters_FindUser(int index, int * targets);
int		fighters_Faint(int index);
void	fighters_UseItem(int index, int itemidx);
void	fighters_Forecast(int index);
void	fighters_Initialize(int index, int batonpass);
void	fighters_Trace(int index, int onactive);
void	fighters_ProcessMultiHitMove(int mid, int attacker, int target,	int numhits);
void	fighters_ProcessNonMultiHitMove(int mid, int attacker, int target, int nocheck);
int 	fighters_UseMoveSimple(int index, int mid);
int		fighters_UseMove(int index);
int		fighters_ProcessTurn(int index);
int		fighters_ReducePP(int index, int mno);
void	fighters_LearnMove(int pkmnIndex, int move);
void	fighters_GainEXP();
int		fighters_HasType(int who, int what);
int		fighters_DrainHP(int who, int damage);
int		fighters_RestoreHP(int who, int amount);
void	fighters_Cry(int index, int pitch);

int		effect_CanBurn(int index, int showMessages);
int		effect_CanFreeze(int index, int showMessages);
int		effect_CanConfuse(int index, int showMessages);
int		effect_CanPoison(int index, int showMessages);
int		effect_CanPoisonSynchronize(int index, int opponent);
int		effect_CanSleep(int index, int showMessages, int selfsleep);
int		effect_CanParalyze(int index, int showMessages);
void	effect_Sleep(int index, int duration);
int		effect_CanReduceStatStage(int index, int stat, int showMessages);
int		effect_TooLow(int index, int stat);
int		effect_ReduceStat(int index, int stat, int increment, int showMessages);
int		effect_ReduceAttackStatStageIntimidate(int index, int opponent);

void	scene_BuildBattleScreen();
void	scene_BreakBattleScreen();
void	scene_SetLine(int x, int w, int y, u16 start, u8 pal);
void  scene_DrawMoveData(aPokemon * mon, int move);
void	scene_DoTrainerDefeatSpeech();
const char * scene_GetTrainerName(int index);
void	scene_StartTrainerBattle(int index);
void	scene_StartWildBattle();
void	scene_WriteInBox(u32 where, char *what);
void	scene_BuildPlayerWin();
void	scene_BuildOpponentWin();
int		scene_CommandMenu(int index, int lastCmd);
int		scene_FightMenu(int index);
int		scene_ItemMenu(int index);
void	scene_ChooseEnemyCommand(int index);
int		scene_ChooseNewEnemy();
int 	scene_Switch(int index, int lax, int cancancel);
int		scene_Fainted(int index);
void	scene_WithdrawMonster(int side);

int		move_TypeModMessages(int mid, int type, int opponent);
int		move_IsCritical(int mid, int attacker, int opponent);
int		move_IsSpecial(int mid, int type);
void	move_OnDamageLost(int damage, int mid, int attacker, int opponent);
int		move_CalcDamage(int mid, int attacker, int opponent, int options);
void	move_EffectMessages(int mid, int opponent);
int		move_EffectFixedDamage(int mid, int damage, int attacker, int opponent);
int		move_TypeModifier(int mid, int type, int who);
int		move_AccuracyCheck(int mid, int attacker, int opponent);

int		__move_BaseDamage(int mid, int basedmg, int attacker, int opponent);
int		__move_AdditionalEffect(int mid, int attacker, int opponent);
int		__move_Effect(int mid, int attacker, int opponent);
int		__move_ModifyDamage(int damage, int attacker, int opponent);
int		__move_DisplayUseMessage(int mid, int attacker);
int		__move_NumHits(int mid);
int		__move_IsMultiHit(int mid);
int		__move_TwoTurnAttack(int mid, int attacker);
int		__move_OnStartUse(int mid, int attacker);
int 	__move_MoveFailed(int mid, int attacker, int opponent);

void btlsayf(int msgindex, ...);
void btlsays(const char *fmt, ...);
int btlMultipleChoice(int left, int top, int width, int choices, int bcancel); //CHOICELIST choices);
void WhiteOut();
void InitializeWildBattle();
void ExpandTrainerTeam(aTrainer* who);
void MakeHPBar(int value, int max, int target, int nolabel);
int monster_GetLevelFromExperience(int exp, int rate);

extern const unsigned short dannybackPal[16];
extern const unsigned short dannybackTiles[6144];
extern const unsigned short danibackPal[16];
extern const unsigned short danibackTiles[6144];
extern const unsigned short demobackPal[16];
extern const unsigned short demobackTiles[5120];

extern const unsigned short battleinterfacePal[16];
extern const unsigned short battleinterfaceTiles[304];
extern const unsigned short battleinterfaceMap[2048];
extern const unsigned short hpbarPal[16];
extern const unsigned short hpbarTiles[544];
//extern const unsigned short enemywindowTiles[1024];
//extern const unsigned short playerwindowPal[16];
//extern const unsigned short playerwindowTiles[2048];
extern const unsigned short btlstatusPal[16];
extern const unsigned short btlstatusTiles[240];
extern const unsigned short newbtlwinsPal[16];
extern const unsigned short newbtlwinsTiles[2304];

extern u16 LastKnownSafePlace;

#define btlYesNoLoop() btlMultipleChoice(21,8,8, 0,0) //Choice_YesNo)

#ifdef WITH_SHIRTCOLORS
extern const unsigned short shirtcolors[32];
#endif

extern const unsigned long XPRequirements[808];

extern void pal_blend_asm5(COLOR *pa, COLOR *pb, COLOR *pc, int nclrs, u32 alpha) CODE_IN_IWRAM;
extern int BattlePanOffset;
extern void BattlePan(int i);
extern const unsigned char HeightDataBack[];
extern const unsigned char HeightDataFront[];
extern const char * const BattleStrings[];

extern int demo;

extern const unsigned short * const TrainerPics[];
extern const aTrainer Trainers[];
extern const char TrainerTypes[][14];
extern const char Abilities[][14];

extern aBattle ThisBattle;	//Main state of battle
extern aFighter fighters[4];	//Fighter status... statuses? Statii?
extern int priority[4];		//Order of execution
extern aBattleSide sides[2];	//Arena statii
extern int choices[4][4];		//Choices made
extern unsigned char participants[6];	//Which of YOUR party members have fought the CURRENT opponent?

extern const unsigned short RedStrip[16];
extern const unsigned short WhiteStrip[16];
extern char __pbThis[4][64];

extern const unsigned short * const battlebacks[];
