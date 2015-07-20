//======================================================================
//
//	OpenPoké battle system
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "../openpoke.h"
#include "btlmessages.h"

//const int battlebacklist[] = { 0,0,1,0,1,0,0,1 }; //hack

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

extern const char * const StatNames[];

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



int fighters_DrainHP(int who, int damage)
{
	ssPersonal *myP[2];
	ssStatus *myS[2];
	//char foo[255];
	int totaldrained = 0;
	myS[0] = (ssStatus*)&fighters[0].mon->Status;
	myS[1] = (ssStatus*)&fighters[1].mon->Status;
	myP[0] = (ssPersonal*)&fighters[0].mon->Personal;
	myP[1] = (ssPersonal*)&fighters[1].mon->Personal;

	if(damage > fighters[who].mon->Status.CurrentHP)
	{
		AGBPrintf("WARNING: Draining too much hitpoints. %s has only %d but we drain %d. Capping...\n", fighters_This(who),fighters[who].mon->Status.CurrentHP,damage);
		damage = fighters[who].mon->Status.CurrentHP;
	}

	if(fighters[fighters_Opposing1(who)].effTimeStop)
	{
		fighters[fighters_Opposing1(who)].effTimeStopDmg += damage;
		btlsays("Time Stop diverted the damage.");
		return 0;
	}

	for(; damage > 0; damage--)
	{
		DoVBlank();
		myS[who]->CurrentHP--;
		totaldrained++;
		if(who == 0)
			scene_BuildPlayerWin();
		else
			scene_BuildOpponentWin();
		//MakeHPBar(myS[0]->CurrentHP, myS[0]->TotalHP, MEM_VRAM_OBJ + 0x3380, 0);
		//MakeHPBar(myS[1]->CurrentHP, myS[1]->TotalHP, MEM_VRAM_OBJ + 0x3480, 0);
		//if(who==0)
		//{
			//DmaCopy(playerwindowTiles + 0x500, MEM_VRAM_OBJ + 0x1D80, 0x400);
			//sprintf(foo, "%d/%d", myS[0]->CurrentHP, myS[0]->TotalHP); scene_WriteInBox(4, foo);
		//}
	}

	return totaldrained;
}

int fighters_RestoreHP(int who, int amount)
{
	ssPersonal *myP[2];
	ssStatus *myS[2];
	//char foo[255];
	int totalrestored = 0;

	myS[0] = (ssStatus*)&fighters[0].mon->Status;
	myS[1] = (ssStatus*)&fighters[1].mon->Status;
	myP[0] = (ssPersonal*)&fighters[0].mon->Personal;
	myP[1] = (ssPersonal*)&fighters[1].mon->Personal;

	if(fighters[who].mon->Status.CurrentHP + amount > fighters[who].mon->Status.TotalHP)
	{
		AGBPrintf("WARNING: Restoring too much hitpoints. %s has at most %d but we restore %d. Capping...\n", fighters_This(who),fighters[who].mon->Status.TotalHP,amount);
		amount = fighters[who].mon->Status.TotalHP - fighters[who].mon->Status.CurrentHP;
	}

	for(; amount > 0; amount--)
	{
		DoVBlank();
		myS[who]->CurrentHP++;
		totalrestored++;
		if(who == 0)
			scene_BuildPlayerWin();
		else
			scene_BuildOpponentWin();
		//MakeHPBar(myS[0]->CurrentHP, myS[0]->TotalHP, MEM_VRAM_OBJ + 0x3380, 0);
		//MakeHPBar(myS[1]->CurrentHP, myS[1]->TotalHP, MEM_VRAM_OBJ + 0x3480, 0);
		//if(who==0)
		//{
			//DmaCopy(playerwindowTiles + 0x500, MEM_VRAM_OBJ + 0x1D80, 0x400);
			//sprintf(foo, "%d/%d", myS[0]->CurrentHP, myS[0]->TotalHP); scene_WriteInBox(4, foo);
		//}
	}

	return totalrestored;
}

//Wrapper to play a fighter's cry
void fighters_Cry(int index, int pitch)
{
	int species = GetMonsterStats(fighters[index].mon, pSpecies);
	sndPlayCry(species, pitch);
}

//Returns 1 if the given fighter has the wanted type, 0 otherwise
int fighters_HasType(int who, int what)
{
	int s = GetMonsterStats(fighters[who].mon, pSpecies); //myG->Species;
	if(BaseStats[s].Type1 == what)
		return true;
	if(BaseStats[s].Type2 == what)
		return true;

	return false;
}

void fighters_InitPermanentEffects(int index)
{
	fighters[index].effWish = 0;
	fighters[index].effWishMaker = 0;
	fighters[index].effRecycleItem = 0;
	fighters[index].effFutureSightMove = 0;
	fighters[index].effFutureSightDamage = 0;
	fighters[index].effFutureSightUser = 0;
}

void fighters_InitEffects(int index, int batonpass)
{
	int i;
	if(!batonpass)
	{
		//These effects are retained if
		// the attack "Baton Pass" is used
		fighters[index].stageAttack = 0;
		fighters[index].stageDefense = 0;
		fighters[index].stageSpeed = 0;
		fighters[index].stageSpAtk = 0;
		fighters[index].stageSpDef = 0;
		fighters[index].stageEvasiveness = 0;
		fighters[index].stageAccuracy = 0;
		fighters[index].effConfusion = 0;
		fighters[index].effSubstitute = 0;
		fighters[index].effFocusEnergy = 0;
		fighters[index].effCurse = 0;
		fighters[index].effLockOn = 0;
		fighters[index].effLockOnPos = 0;

		for(i=0;i<4;i++)
		{
			if((fighters[i].effLockOnPos == index) && (fighters[i].effLockOn))
			{
				fighters[i].effLockOn = 0;
				fighters[i].effLockOnPos = 0;
			}
		}

		fighters[index].effIngrain = 0;
		fighters[index].effPerishSong = 0;
		fighters[index].effLeechSeed = 0;
		fighters[index].effWaterSport = 0;
		fighters[index].effMudSport = 0;
		fighters[index].effMeanLook = 0;

		for(i=0;i<4;i++)
			if(fighters[i].effMeanLook == index)
				fighters[i].effMeanLook = 0;
	}

	fighters[index].damagestate.calcdamage = 0;
	fighters[index].damagestate.critical = 0;
	fighters[index].damagestate.endured = 0;
	fighters[index].damagestate.focusband = 0;
	fighters[index].damagestate.focusbandused = 0;
	fighters[index].damagestate.hplost = 0;
	fighters[index].damagestate.substitute = 0;
	fighters[index].damagestate.typemod = 0;

	fighters[index].effPinch = 0;
	fighters[index].effTrace = 0;
	fighters[index].effMirrorMove = 0;
	//pbOpposing1.effects[PBEffects::MirrorMove]=0 if pbOpposing1
	//pbOpposing2.effects[PBEffects::MirrorMove]=0 if pbOpposing2

	fighters[index].effConversion2Move = 0;
	fighters[index].effConversion2Type = 0;
	fighters[index].effToxic = 0;
	fighters[index].effEncore = 0;
	fighters[index].effEncoreIndex = 0;
	fighters[index].effAttract = -1;

	for(i=0;i<4;i++)
		if(fighters[i].effAttract == index)
			fighters[i].effAttract = -1;

	//@effects[PBEffects::MultiTurnUser]=0
	fighters[index].effMultiTurn = 0;
	//cancel other players' MultiTurns
	fighters[index].effTransform = 0;
	fighters[index].effYawn = 0;
	fighters[index].effMultiTurnAttack = 0;
	fighters[index].effOutrage = 0;
	fighters[index].effForesight = 0;
	fighters[index].effHyperBeam = 0;
	fighters[index].effDestinyBond = 0;
	fighters[index].effGrudge = 0;
	fighters[index].effTruant = 0;
	fighters[index].effFlinch = 0;
	fighters[index].lastMoveUsed = 0;
	fighters[index].lastMoveUsedSketch = 0;
	fighters[index].lastMoveCalled = 0;
	fighters[index].effPursuit = 0;
	fighters[index].effRevenge = 0;
	fighters[index].effBide = 0;
	fighters[index].effBideDamage = 0;
	fighters[index].effStockpile = 0;
	fighters[index].effProtect = 0;
	fighters[index].effProtectRate = 0;
	fighters[index].effEndure = 0;
	fighters[index].effHelpingHand = 0;
	fighters[index].effCharge = 0;
	fighters[index].lastHPLost = 0;
	fighters[index].lastAttacker = 0;
	fighters[index].effCounter = 0;
	fighters[index].effCounterTarget = 0;
	fighters[index].effMirrorCoat = 0;
	fighters[index].effMirrorCoatTarget = 0;
	fighters[index].effTwoTurnAttack = 0;
	fighters[index].effRollout = 0;
	fighters[index].effDefenseCurl = 0;
	fighters[index].effMagicCoat = 0;
	fighters[index].effSnatch = 0;
	fighters[index].effFollowMe = 0;
	fighters[index].effRage = 0;
	fighters[index].effMinimize = 0;
	fighters[index].effFuryCutter = 0;
	fighters[index].effImprison = 0;
	fighters[index].effChoiceBand = 0;
	fighters[index].effUproar = 0;
	fighters[index].effTorment = 0;
	fighters[index].effDisableMove = 0;
	fighters[index].effDisableTimer = 0;
}

// Set every fighter's status changes/effects to 0
void fighters_Initialize(int index, int batonpass)
{
	fighters_InitPermanentEffects(index);
	fighters_InitEffects(index, batonpass);
}

const char * fighters_This(int index)
{
	char namebuf[12];
	int i;
	for(i = 0; i < 10; i++)
	{
		if(fighters[index].mon->Personal.Nickname[i] == 0)
			break;
		namebuf[i] = fighters[index].mon->Personal.Nickname[i];
	}

	namebuf[i] = 0;

	sprintf(__pbThis[index],"%s",namebuf);

	return  __pbThis[index];
}

int fighters_Speed(int index)
{
	int stagemul[] = { 10,10,10,10,10,10,10,15,20,25,30,35,40 };
	int stagediv[] = { 40,35,30,25,20,15,10,10,10,10,10,10,10 };

	int speed = fighters[index].mon->Status.Speed;
	int stage = fighters[index].stageSpeed + 6;

	speed = (speed * stagemul[stage] / stagediv[stage]);

	if(	(ThisBattle.weather == WEATHER_RAINDANCE) &&
			(fighters[index].ability == abilitySwiftswim))
		speed = speed * 2;

	if(	(ThisBattle.weather == WEATHER_SUNNYDAY) &&
			(fighters[index].ability == abilityChlorophyll))
		speed = speed * 2;

	if(GetMonsterStats(fighters[index].mon, pHeldItem) == itemMachoBrace)
		speed = speed / 2;

	if(fighters[index].mon->Status.AilmentParalysis)
		speed = speed / 4;
/*
 # Dynamo Badge (index 2, internal battles only)
 if @battle.internalbattle
  if @battle.player.badges[2] && !@battle.pbIsOpposing(@index)
   speed=(speed*1.1).floor
  end
 end
*/
	return speed;
}

int fighters_OwnSide(int index)
{
	return index & 1; //Player: 0,2; Opponent: 1,3
}

int fighters_OpposingSide(int index)
{
	return (index & 1) ^ 1; //Player: 1,3; Opponent: 0,2
}

int fighters_IsOpposing(int index,int i)
{
	return (index & 1) != (i & 1);
}

int fighters_Partner(int index)
{
	return (index & 1) | ((index & 2) ^ 2);
}

int fighters_Opposing1(int index)
{
	return (index & 1) ^ 1;
}

int fighters_Opposing2(int index)
{
	return ((index & 1) ^ 1) + 2;
}

int fighters_OppositeOpposing(int index)
{
	return index ^ 1;
}

void fighters_UpdateParticipants(int index)
{
	AGBPrintf("fighters_UpdateParticipants(%d)\n",index);

	//Can't update if already fainted
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return;

	if(battle_IsOpposing(index))
	{
		participants[fighters[fighters_Opposing1(index)].pokemonIndex] = true;
		AGBPrintf("Adding #%d\n",fighters[fighters_Opposing1(index)].pokemonIndex);
	}

	AGBPrintf("New participant list:\n");
	int i;
	for(i=0; i<6; i++)
		AGBPrintf("%d",participants[i]);
	AGBPrintf("\n");

/*
	//AGBPrintf("beep\n");
	if(battle_IsOpposing(index))
	{
		//AGBPrintf("fighters_UpdateParticipants: is opposing...\n");
		int found1 = 0, found2 = 0;
		int i;
		for(i = 0; i < NUMPARTICIPANTS; i++)
		{
			found1 = (i == fighters[fighters_Opposing1(index)].pokemonIndex);
			found2 = (i == fighters[fighters_Opposing2(index)].pokemonIndex);
		}
		AGBPrintf("fighters_UpdateParticipants: found %d/%d\n",found1,found2);
		if((!found1) && (fighters[fighters_Opposing1(index)].mon->Status.CurrentHP > 0))
		{
			AGBPrintf("fighters_UpdateParticipants: found1...\n");
			fighters[index].participants[fighters[index].numparts] = fighters[fighters_Opposing1(index)].pokemonIndex;
			fighters[index].numparts++;
		}
		if((!found2) && (fighters[fighters_Opposing2(index)].mon->Status.CurrentHP > 0))
		{
			AGBPrintf("fighters_UpdateParticipants: found2...\n");
			fighters[index].participants[fighters[index].numparts] = fighters[fighters_Opposing2(index)].pokemonIndex;
			fighters[index].numparts++;
		}
		AGBPrintf("fighters_UpdateParticipants: numparts for %d is now %d: ", index,fighters[index].numparts);
		for(i = 0; i < fighters[index].numparts; i++)
		{
			AGBPrintf("%d (%d), ", fighters[index].participants[i], fighters[fighters[index].participants[i]].pokemonIndex);
		}
		AGBPrintf("\n");
	}
*/
}

int fighters_Faint(int index)
{
	if(fighters[index].mon->Status.CurrentHP)
		return true;

	scene_Fainted(index);
	fighters_InitEffects(index, 0);
	fighters[index].mon->Status.Ailment = 0;
	choices[index][0]=CHOICE_NONE;
	choices[index][1]=0;
	choices[index][2]=0;
	choices[index][3]=-1;

	btlsayf(BT_XFainted, fighters_This(index));

	if(battle_AllFainted(MyParty))
	{
		ThisBattle.decision = 2;
		return false;
	}

	return true;
}

void fighters_UseItem(int index, int itemidx)
{
//	if(items[itemidx].param1 == 1)
//	{
//		FadeOut();
//		scene_BreakBattleScreen();
//	}
	items[itemidx].battleuse(items[itemidx].id,
														items[itemidx].special1,
														items[itemidx].special2,
														items[itemidx].param1,
														items[itemidx].param2
													);
	if(items[itemidx].param1 == 1)
	{
		scene_BuildBattleScreen();
		REG_BG0HOFS = 0;
		REG_BG0VOFS = 0;
		scene_BuildPlayerWin();
		scene_BuildOpponentWin();

		if(fighters[0].mon->Status.CurrentHP)
			battle_SendOut(0, fighters[0].pokemonIndex, 0);
		if(fighters[1].mon->Status.CurrentHP)
			battle_SendOut(1, fighters[1].pokemonIndex, 0);

		OamBak[2].HPos = 158;
		OamBak[3].HPos = 190;
		OamBak[4].HPos = 36;
		OamBak[5].HPos = 68;
		OamBak[8].HPos = 126;
		OamBak[9].HPos = 190;
		OamBak[10].HPos= 12;
		OamBak[11].HPos= 76;
		REG_WIN0V = ((80-(40*2)) << 8) + (80+(40*2));

		FadeIn();
	}
}

void fighters_Trace(int index, int onactive)
{
/*
 if ability==PBAbilities::TRACE && hp>0
  return if hp<=0
  return if !@effects[PBEffects::Trace] && !onactive
  choices=[]
  for i in 0..3
   if pbIsOpposing?(i)
    choices[choices.length]=i if @battle.battlers[i].ability>0
   end
  end
  if choices==0
   @effects[PBEffects::Trace]=true
  else
   choice=choices[@battle.pbRandom(choices.length)]
   battlername=@battle.battlers[choice].pbThis
   battlerability=@battle.battlers[choice].ability
   @ability=battlerability
   abilityname=PBAbilities.getName(battlerability)
   @battle.pbDisplay("#{pbThis} Traced #{battlername}'s #{abilityname}!")
   @effects[PBEffects::Trace]=false
  end
 end
*/
}

void fighters_Forecast(int index)
{
/*
 if ability==PBAbilities::FORECAST && species==PBSpecies::CASTFORM && hp>0 &&
     !@battle.pbCheckGlobalAbility(PBAbilities::CLOUDNINE) &&
     !@battle.pbCheckGlobalAbility(PBAbilities::AIRLOCK)
   weather=@battle.pbWeather
   if weather==PBWeather::SUNNYDAY && !pbHasType?(PBTypes::FIRE)
    @type1=PBTypes::FIRE
    @type2=PBTypes::FIRE
    @battle.pbDisplay("#{pbThis} transformed!")
   elsif weather==PBWeather::RAINDANCE && !pbHasType?(PBTypes::WATER)
    @type1=PBTypes::WATER
    @type2=PBTypes::WATER
    @battle.pbDisplay("#{pbThis} transformed!")
   elsif weather==PBWeather::HAIL && !pbHasType?(PBTypes::ICE)
    @type1=PBTypes::ICE
    @type2=PBTypes::ICE
    @battle.pbDisplay("#{pbThis} transformed!")
   elsif (weather==0 || weather==PBWeather::SANDSTORM) && !pbHasType?(PBTypes::NORMAL)
    @type1=PBTypes::NORMAL
    @type2=PBTypes::NORMAL
    @battle.pbDisplay("#{pbThis} transformed!")
   end
 end
*/
}

void fighters_AbilityCureCheck(int index)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return;

	if(	(fighters[index].ability == abilityLimber) &&
			(fighters[index].mon->Status.AilmentParalysis))
	{
		btlsayf(BT_XsXCuredParalysis, fighters_This(index), Abilities[fighters[index].ability]);
		fighters[index].mon->Status.Ailment = 0;
	}

	if(	(fighters[index].ability == abilityOblivious) &&
			(fighters[index].effAttract) >= 0)
	{
		btlsayf(BT_XsXCuredItsXProblem, fighters_This(index), Abilities[fighters[index].ability], "love");
		fighters[index].effAttract = -1;
	}

	if(	((fighters[index].ability == abilityVitalSpirit) ||
			(fighters[index].ability == abilityInsomnia)) &&
			(fighters[index].mon->Status.AilmentSleep))
	{
		btlsayf(BT_XsXWokeItFromItsSleep, fighters_This(index), Abilities[fighters[index].ability]);
		fighters[index].mon->Status.Ailment = 0;
	}

	if(	(fighters[index].ability == abilityImmunity) &&
			(fighters[index].mon->Status.AilmentPoison))
	{
		btlsayf(BT_XsXCuredPoison, fighters_This(index), Abilities[fighters[index].ability]);
		fighters[index].mon->Status.Ailment = 0;
	}

	if(	(fighters[index].ability == abilityOwnTempo) &&
			(fighters[index].effConfusion))
	{
		btlsayf(BT_XsXSnappedItOutOfConfusion, fighters_This(index), Abilities[fighters[index].ability]);
		fighters[index].effConfusion = 0;
	}

	if(	(fighters[index].ability == abilityMagmaArmor) &&
			(fighters[index].mon->Status.AilmentFrozen))
	{
		btlsayf(BT_XsXDefrostedIt, fighters_This(index), Abilities[fighters[index].ability]);
		fighters[index].mon->Status.Ailment = 0;
	}

	if(	(fighters[index].ability == abilityWaterveil) &&
			(fighters[index].mon->Status.AilmentBurned))
	{
		btlsayf(BT_XsXHealedItsBurn, fighters_This(index), Abilities[fighters[index].ability]);
		fighters[index].mon->Status.Ailment = 0;
	}
}


int fighters_ConfusionBerry(int index, int held, int items1, int flavor)
{
	if(	(items[held].special1 == items1) &&
			(fighters[index].mon->Status.CurrentHP <= fighters[index].mon->Status.TotalHP / 2))
	{
		btlsayf(BT_XsXRestoredHealth, fighters_This(index), items[held].name);
		fighters_RestoreHP(index, fighters[index].mon->Status.TotalHP / 8);

		if(	(fighters[index].mon->Personal.Personal % 5 == flavor) &&
				(fighters[index].mon->Personal.Personal / 5 != fighters[index].mon->Personal.Personal % 5))
		{
			btlsays(strBattleBerryTooTasty, fighters_This(index), items[held].name, Flavors[flavor]);
			if(	(fighters[index].effConfusion == 0) &&
					(fighters[index].ability != abilityOwnTempo))
			{
				fighters[index].effConfusion = rrand(4) + 2;
				btlsayf(BT_XBecameConfused, fighters_This(index));
			}
		}
		return 1;
	}

	return 0;
}

int fighters_StatIncreasingBerry(int index, int held, int items1)
{
	int statid = items1 - 15;
	//Cearn, please check if I'm sane
	int * stat = &fighters[index].stageAttack + (statid * sizeof(int));

	if(	(items[held].special1 == items1) &&
			(fighters[index].mon->Status.CurrentHP <= fighters[index].mon->Status.TotalHP / 4) &&
			(*stat < 6))
	{
		stat++;
		btlsayf(BT_UsingXTheXOfXX, items[held].name, BattleStatNames[statid], fighters_This(index), "rose");
		return 1;
	}

	return 0;
}

void fighters_BerryCureCheck(int index, int hpcure)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return;

	int takeit = false, item = GetMonsterStats(fighters[index].mon, pHeldItem);

	if(items[item].battleuse == item_BtlHeal)
	{
		if(items[item].special1 == 1) //HP heal
		{
			if(	(hpcure) &&
					(fighters[index].mon->Status.CurrentHP <= fighters[index].mon->Status.TotalHP / 2))
			{
				btlsayf(BT_XsXRestoredHealth, fighters_This(index), items[item].name);
				fighters_RestoreHP(index, items[item].special2);
				takeit = true;
			}
		}
		//This sequence can likely be compacted with a table of messages and ailment indices.
		//Regardless, let's do it the copypaste way first...
		else if(items[item].special1 == 2) //Cure paralysis
		{
			if(fighters[index].mon->Status.AilmentParalysis)
			{
				btlsayf(BT_XsXCuredParalysis, fighters_This(index), items[item].name);
				fighters[index].mon->Status.AilmentParalysis = 0;
				takeit = true;
			}
		}
		else if(items[item].special1 == 3) //Cure sleep
		{
			if(fighters[index].mon->Status.AilmentSleep)
			{
				btlsayf(BT_XsXWokeItFromItsSleep, fighters_This(index), items[item].name);
				fighters[index].mon->Status.AilmentSleep = 0;
				takeit = true;
			}
		}
		else if(items[item].special1 == 4) //Cure poison
		{
			if(fighters[index].mon->Status.AilmentPoison)
			{
				btlsayf(BT_XsXCuredPoison, fighters_This(index), items[item].name);
				fighters[index].mon->Status.AilmentPoison = 0;
				takeit = true;
			}
		}
		else if(items[item].special1 == 5) //Cure burn
		{
			if(fighters[index].mon->Status.AilmentBurned)
			{
				btlsayf(BT_XsXHealedItsBurn, fighters_This(index), items[item].name);
				fighters[index].mon->Status.AilmentBurned = 0;
				takeit = true;
			}
		}
		else if(items[item].special1 == 6) //Cure freeze
		{
			if(fighters[index].mon->Status.AilmentFrozen)
			{
				btlsayf(BT_XsXDefrostedIt, fighters_This(index), items[item].name);
				fighters[index].mon->Status.AilmentFrozen = 0;
				takeit = true;
			}
		//special1 == 7, Apple
/*
   if hpcure && self.item==PBItems::LEPPABERRY
    for i in 0...@pokemon.moves.length
     pokemove=@pokemon.moves[i]
     battlermove=self.moves[i]
     if pokemove.pp==0
      movename=PokeBattle_Move.getName(pokemove.id);
      pokemove.pp=10
      pokemove.pp=pokemove.totalpp if pokemove.pp>pokemove.totalpp
      battlermove.pp=pokemove.pp
      @battle.pbDisplay("#{pbThis}'s Leppa Berry restored #{movename}'s PP!")
      @effects[PBEffects::RecycleItem]=self.item
      self.item=0
      break
     end
    end
   end
*/
		}
		else if(items[item].special1 == 8)
		{
			if(fighters[index].effConfusion)
			{
				btlsayf(BT_XsXCuredItsXProblem, fighters_This(index), items[item].name, "confusion");
				fighters[index].effConfusion = 0;
				takeit = true;
			}
		}
		else if(items[item].special1 == 9)
		{
			if(fighters[index].effConfusion)
			{
				btlsayf(BT_XsXCuredItsXProblem, fighters_This(index), items[item].name, "confusion");
			} else
			{
				if(fighters[index].mon->Status.AilmentParalysis)
				{
					btlsayf(BT_XsXCuredParalysis, fighters_This(index), items[item].name);
				} else if(fighters[index].mon->Status.AilmentSleep)
				{
					btlsayf(BT_XsXWokeItFromItsSleep, fighters_This(index), items[item].name);
				} else if(fighters[index].mon->Status.AilmentPoison)
				{
					btlsayf(BT_XsXCuredPoison, fighters_This(index), items[item].name);
				} else if(fighters[index].mon->Status.AilmentBurned)
				{
					btlsayf(BT_XsXHealedItsBurn, fighters_This(index), items[item].name);
				} else if(fighters[index].mon->Status.AilmentFrozen)
				{
					btlsayf(BT_XsXDefrostedIt, fighters_This(index), items[item].name);
			 	}
			}
			fighters[index].mon->Status.Ailment = 0;
			fighters[index].effConfusion = 0;
			takeit = true;
		}
		else
		{
			AGBPrintf("%s tried to use %s, but BtlHeal effect %d is not supported yet.\n", fighters_This(index), items[item].name, items[item].special1);
		}
	}
	if(hpcure)
	{
		if(fighters_ConfusionBerry(index, item, 10, 0)) takeit = true; //Fig
		if(fighters_ConfusionBerry(index, item, 11, 3)) takeit = true; //Kiwi
		if(fighters_ConfusionBerry(index, item, 12, 2)) takeit = true; //Mango
		if(fighters_ConfusionBerry(index, item, 13, 4)) takeit = true; //Guava
		if(fighters_ConfusionBerry(index, item, 14, 1)) takeit = true; //Papaya
	}
	if(hpcure)
	{
		if(fighters_StatIncreasingBerry(index, item, 15)) takeit = true; //Litchi
		if(fighters_StatIncreasingBerry(index, item, 16)) takeit = true; //Longan
		if(fighters_StatIncreasingBerry(index, item, 17)) takeit = true; //Salak
		if(fighters_StatIncreasingBerry(index, item, 18)) takeit = true; //Pitaya
		if(fighters_StatIncreasingBerry(index, item, 19)) takeit = true; //Apricot
	}
	//TODO	Implement other berry effects:
/*
  if hpcure && self.item==PBItems::LANSATBERRY && self.hp<=(self.totalhp/4).floor && !@effects[PBEffects::FocusEnergy]
   @battle.pbDisplay("#{pbThis} used its Lansat Berry to get pumped!")
   @effects[PBEffects::FocusEnergy]=true
   @effects[PBEffects::RecycleItem]=self.item
   self.item=0
  end
  if hpcure && self.item==PBItems::STARFBERRY && self.hp<=(self.totalhp/4).floor
   stats=[]
   messages=[
    "Using Starf Berry, the Attack of {1} sharply rose!",
    "Using Starf Berry, the Defense of {1} sharply rose!",
    "Using Starf Berry, the Speed of {1} sharply rose!",
    "Using Starf Berry, the Special Attack of {1} sharply rose!",
    "Using Starf Berry, the Special Defense of {1} sharply rose!"
   ]
   for i in 0...5
    stats[stats.length]=i if !pbTooHigh?(i)
   end
   if stats.length>0
    stat=stats[@battle.pbRandom(stats.length)]
    @stages[stat]+=2
    @stages[stat]=6 if @stages[stat]>6
    @battle.pbDisplay(messages[stat].gsub(/\{1\}/){pbThis})
    @effects[PBEffects::RecycleItem]=self.item
    self.item=0
   end
  end
   if self.item==PBItems::WHITEHERB
    while true
     reducedstats=0
     for i in 0..6
      reducedstats+=1 if @stages[i]<0
     end
     break if reducedstats==0
     for i in 0..6
      @stages[i]=0 if @stages[i]<0
     end
     @battle.pbDisplay("#{pbThis}'s White Herb restored its status!")
     self.status=0
    end
   end
   while self.item==PBItems::MENTALHERB && @effects[PBEffects::Attract]>=0
    @battle.pbDisplay("#{pbThis}'s Mental Herb cured its love problem!")
    @effects[PBEffects::Attract]=-1
    @effects[PBEffects::RecycleItem]=self.item
    self.item=0
   end
   if hpcure && self.item==PBItems::LEFTOVERS && self.hp!=self.totalhp
    pbRecoverHP((self.totalhp/16).floor)
    @battle.pbDisplay("#{pbThis}'s Leftovers restored its HP a little!")
   end
*/
	if(takeit)
	{
		fighters[index].effRecycleItem = item;
		SetMonsterStats(fighters[index].mon, pHeldItem, 0);
	}
}

void fighters_RandomTarget(int index, int * targets)
{
	int c[4], tlen;

	__moves_AddTarget(0, c, fighters_Opposing1(index));
	__moves_AddTarget(0, c, fighters_Opposing2(index));
	tlen = fighters_GetTargetLen(c);

	if(tlen)
		__moves_AddTarget(0, targets, rrand(tlen));
}

void fighters_ConfusionDamage(int index)
{
	__move_Effect(moveConfusion,index,index);
	if(fighters[index].mon->Status.CurrentHP <= 0)
		fighters_Faint(index);
}

void fighters_SetPP(int index, int mno, int pp)
{
	SetMonsterStats(fighters[index].mon, pPP1 + mno, pp);
}

int fighters_ReducePP(int index, int mno)
{
	if(	(fighters[index].effTwoTurnAttack) ||
			(fighters[index].effBide) ||
			(fighters[index].effOutrage) ||
			(fighters[index].effRollout) ||
			(fighters[index].effHyperBeam) ||
			(fighters[index].effUproar))
		return true; //No need to reduce PP if two-turn attack

	int i = GetMonsterStats(fighters[index].mon, pPP1 + choices[index][1]);
	if(i == 0)
		return false;

	if(i > 0)
	{
		i--;
		SetMonsterStats(fighters[index].mon, pPP1 + choices[index][1], i);

		//Take another PP if targeting a Pressure-able opponent.
		if(fighters[fighters_Opposing1(index)].ability == abilityPressure && i > 0)
		{
			i--;
			SetMonsterStats(fighters[index].mon, pPP1 + choices[index][1], i);
		}
	}
	return true;
}

int fighters_FindUser(int index, int * targets)
{
	AGBPrintf("fighters_FindUser(idx %d)\n", index);
	targets[0] = 255;
	targets[1] = 255;
	targets[2] = 255;
	targets[3] = 255;

	aMove * move = (aMove*)choices[index][2];
	int target = choices[index][3];
	int user = index;
	AGBPrintf("User: %d\nTarget/choice3: %d\n",user,target);

	targets[0] = target;
	if(move->target == TGT_USER)
		targets[0] = user;
	if(targets[0] == -1)
		targets[0] = user ^ 1;

	//TODO	Complete WORKING rewrite
	return user;
}

int fighters_SuccessCheck(int mid, int user, int target, int accuracy)
{
	if(fighters[user].effTwoTurnAttack)
		return true;

	//TODO	"Before Protect" applies to Counter/Mirror Coat
	if(((fighters[target].mon->Status.AilmentSleep) || (fighters[target].effSubstitute)) && (mid == moveDreamEater))
	{
		btlsayf(BT_XWasntAffected, fighters_This(target));
		return false;
	}

	if(mid == moveMemento)
	{
		//if target.pbTooLow?(PBStats::ATTACK) && target.pbTooLow?(PBStats::SPATK)
		if((effect_TooLow(target,STAT_ATTACK)) && (effect_TooLow(target,STAT_SPATK)))
		{
			btlsayf(BT_ButItFailed);
			return false;
		}
		fighters[user].mon->Status.CurrentHP = 0;
	}

	if((mid == moveSpitUp) && (fighters[user].effStockpile == 0))
	{
		btlsayf(BT_ButItFailedToSpitUpAThing);
		return false;
	}

	if((fighters[target].effProtect) && (moves[mid].flags & MOV_PROTECT))
	{
		btlsayf(BT_XProtectedItself, fighters_This(target));
		return false;
	}

	if(mid == moveRage)
		fighters[user].effRage = 1;

	//TODO	Mind Reader/Lock-On
	//Sketch/FutureSight/PsychUp work even on Fly/Bounce/Dive/Dig
	if(__move_MoveFailed(mid,user,target)) //TODO	Applies to Snore/Fake Out
	{
		btlsayf(BT_ButItFailed);
		return false;
	}

	if(	(moves[mid].basepower) &&
			(mid != moveBeatUp) &&
			(mid != moveStruggle) &&
			(mid != moveFutureSight) &&
			(mid != moveDoomDesire) )
	{
		int type = moves[mid].type;
		int typemod = move_TypeModifier(mid, type, target);
		if((fighters[target].ability == abilityLevitate) && (type == tpGround))
		{
			btlsayf(BT_XMakesGroundMovesMissWithX, fighters_This(target), Abilities[fighters[target].ability]);
			return false;
		}
		if((fighters[target].ability == abilityWonderGuard) && (typemod <= 4))
		{
			btlsayf(BT_XAvoidedDamageWithX, fighters_This(target), Abilities[fighters[target].ability]);
			return false;
		}
		if(typemod == 0)
		{
			btlsayf(BT_ItDoesntAffectX, fighters_This(target));
			return false;
		}
	}

	if(accuracy)
	{
		if((fighters[target].effLockOn) && (fighters[target].effLockOnPos == fighters[user].pokemonIndex))
			return true;

		if(move_AccuracyCheck(mid,user,target)) //includes Counter/Mirror Coat
		{
			if((moves[mid].target == TGT_ALLOPS) || (moves[mid].target == TGT_OTHERS))
				btlsayf(BT_XAvoidedTheAttack, fighters_This(target));
			else if(mid == moveLeechSeed)
				btlsayf(BT_XAvoidedTheAttack, fighters_This(target));
			else
				btlsayf(BT_XsAttackMissed, fighters_This(user));
			return false;
		}
	}
	return true;
}

void fighters_ProcessBeatUp(int index, int mid, int user, int target)
{
/*
	//TOD_O	Actually ignores Wonder Guard effect unless it really misses
	int numhits = 0;
	if(!fighters_SuccessCheck(mid,user,target,true))
	{
		return;
	}
	aPokemon * party = battle_Party(index);
	int i, ps = GetPartySize(party);
	for(i = 0; i <= ps; i++)
	{
		if((party[i].Status.CurrentHP > 0) ) //&& (party.status != 0)
		{
			thisname=@battle.pbThisEx(@index,i)
			@battle.pbDisplay("#{thisname}'s attack!");
			thismove.pbSetThisPkmn(party[i])
			pbProcessNonMultiHitMove(thismove,user,target,true)
			numhits+=1
		}
	}
 if numhits==0
  @battle.pbDisplay(BT_ButItFailed);
  return
 end
*/
}

void fighters_ProcessNonMultiHitMove(int mid,int attacker ,int target, int nocheck)
{
	if(fighters[target].effTimeStop)
	{
		btlsays("Time Stop prevented the attack from\ngetting through.");
		return;
	}

	if(!nocheck && !fighters_SuccessCheck(mid, attacker, target, true))
	{
		if(mid == moveJumpKick || mid == moveHiJumpKick)
		{
			//TODO	Not shown if message is "it doesn't affect foo…"
			btlsayf(BT_XKeptGoingAndCrashed, fighters_This(attacker));
			int damage = move_CalcDamage(mid, attacker, target, 0);
			if(damage)
			{
				if(fighters[target].effSubstitute)
					if((fighters[target].effEndure) || (fighters[target].damagestate.focusband))
						if(damage >= fighters[target].mon->Status.CurrentHP)
							damage = fighters[target].mon->Status.CurrentHP - 1;

				damage = damage / 2;
				fighters_DrainHP(attacker,damage);
			}

			if(fighters[target].mon->Status.CurrentHP <= 0)
				fighters_Faint(attacker);
		}

		if(mid == moveRollout || mid == moveIceBall)
			fighters[attacker].effRollout = 0;

		if(mid == moveFuryCutter)
			fighters[attacker].effFuryCutter = 0;

		if(mid == moveSpitUp)
			fighters[attacker].effStockpile = 0;

		fighters[attacker].effConversion2Move = -1;
		fighters[attacker].effConversion2Type = 0;
		return;
	}
	else
	{
		if(mid == moveRollout || mid == moveIceBall)
		{
			if(fighters[attacker].effRollout == 0)
				fighters[attacker].effRollout = 5;
			fighters[attacker].effRollout--;
			fighters[attacker].currentMove = mid;
		}

		if(mid == moveFuryCutter)
			if(fighters[attacker].effFuryCutter < 5)
				fighters[attacker].effFuryCutter++;

		int damage = __move_Effect(mid, attacker, target); //recoil/drain etc. are applied here

		if(	(fighters[attacker].mon->Status.CurrentHP <=0) &&
				(mid != moveExplosion) &&
				(mid != moveSelfdestruct))
		{
			fighters_Faint(attacker); //no return
			return;
		}

		//Additional effect
		if(	(fighters[target].damagestate.calcdamage > 0) &&
				(fighters[target].ability != abilityShieldDust))
		{
			int addleffect = moves[mid].effectaccuracy;
			if(fighters[target].ability == abilitySereneGrace)
				addleffect *= 2;

			if(rrand(100) < addleffect)
				__move_AdditionalEffect(mid, attacker, target);

			//King's Rock
		}

		if(	(fighters[target].mon->Status.CurrentHP) &&
				(fighters[target].effRage) &&
				(battle_IsOpposing(target)) &&
				(damage > 0)) //Rage
		{
			//TODO	Apparently triggers if opposing Pokemon uses Future Sight after a Future Sight attack
			if(fighters[target].stageAttack < 6)
			{
				fighters[target].stageAttack++;
				btlsayf(BT_XsRageIsBuilding, fighters_This(target));
			}
		}

		//Defrost
		if(	(moves[mid].type == tpNone) &&
				(mid != moveHiddenPower) &&
				(fighters[target].mon->Status.AilmentFrozen) &&
				(fighters[target].mon->Status.CurrentHP) &&
				(damage))
		{
			btlsayf(BT_XWasDefrosted, fighters_This(target));
			fighters[target].mon->Status.AilmentFrozen = 0;
		}

		//Grudge
		if(	(fighters[target].effGrudge) &&
				(fighters[target].mon->Status.CurrentHP <= 0) &&
				(fighters[attacker].mon->Status.CurrentHP > 0))
		{
			btlsayf(BT_XsXLostAllItsPPDueToTheGrudge,fighters_This(attacker),moveNames[mid]);
			fighters_SetPP(attacker,choices[attacker][1],0);
		}

		//Destiny Bond
		if(	(mid != moveBeatUp) &&
				(fighters[target].effDestinyBond) &&
				(fighters[target].mon->Status.CurrentHP <= 0) &&
				(fighters[attacker].mon->Status.CurrentHP))
		{
			btlsayf(BT_XTookXWithIt, fighters_This(target), fighters_This(attacker));
			fighters_DrainHP(attacker,fighters[target].mon->Status.CurrentHP);
			fighters_Faint(attacker);
		}

		if(fighters[target].mon->Status.CurrentHP <= 0)
		{
			fighters_Faint(target); //no return
			return;
		}
		battle_AbilityEffect(mid, attacker, target);

		int j;
		for(j=0; j < 4; j++)
			fighters_BerryCureCheck(j, false);
		//Shell Bell
		//fighters_UpdateTargetedMove(thismove,attacker);
	}
}

void fighters_ProcessMultiHitMove(int mid, int attacker, int target, int numhits)
{
	//TODO	ProcessMultiHitMove
	//Includes Triple Kick
	int realnumhits = 0;
	int i;
	for(i=0; i<numhits; i++)
	{
		if(!fighters_SuccessCheck(mid, attacker, target, ((i==0)||(mid==moveTripleKick))))
		{
			fighters[target].effConversion2Move = -1;
			fighters[target].effConversion2Type = 0;
			return;
		}
		realnumhits++;

		int damage = __move_Effect(mid, attacker, target); //Recoil/Drain etc. are applied here.
		if(fighters[target].damagestate.calcdamage <= 0)
			return;

		//Critical Hit message
		if(fighters[target].damagestate.critical)
			btlsayf(BT_ACriticalHit);

		//Rage
		if(	(fighters[target].mon->Status.CurrentHP) &&
				(fighters[target].effRage) &&
				fighters_IsOpposing(target, fighters[attacker].pokemonIndex) &&
				(damage > 0))
		{
			if(fighters[target].stageAttack < 6)
			{
				fighters[target].stageAttack++;
				btlsayf(BT_XsRageIsBuilding, fighters_This(target));
			}
		}

		//Ability effects
		battle_AbilityEffect(mid,attacker,target);

		//Berry check (maybe just called by ability effect, since only necessary Berries are checked)
		int j;
		for(j=0; j < 4; j++)
			fighters_BerryCureCheck(j, false);

		//Shell Bell
		/*
		if((fighters[user].item == itemShellBell) && (damage > 0) && (fighters[user].mon->Status.CurrentHP > 0))
		{
			int hpgain = fighters_RestoreHP(attacker, damage / 8);
			if(hpgain > 0)
			{
				btlsayf(BT_XsXRestoredItsHPALittle, fighters_This(attacker), items[itemShellBell].name);
			}
		}
		*/

		//Endure
		if(fighters[target].damagestate.endured)
		{
			btlsayf(BT_XEnduredTheHit, fighters_This(target));
			break;
		}

		//Focus Band
		if(fighters[target].damagestate.focusbandused)
		{
			btlsayf(BT_XHungOnUsingItsX, fighters_This(target), items[itemFocusBand].name);
			break;
		}

		//fighters_UpdateTargetedMove(thismove,attacker);
		if(fighters[target].mon->Status.CurrentHP <= 0)
			break;
	}

	//Type effectiveness
	if(	(fighters[target].damagestate.typemod>=1) &&
			(fighters[target].damagestate.typemod < 4))
		btlsayf(BT_ItsNotVeryEffective);

	if(fighters[target].damagestate.typemod > 4)
		btlsayf(BT_ItsSuperEffective);

	//Number of hits
	btlsayf(BT_HitYTimes, realnumhits);
	//Opponent faints if 0 HP
	if(fighters[target].mon->Status.CurrentHP <= 0)
		fighters_Faint(target); //no return

	//Additional effect
	if(fighters[target].ability != abilityShieldDust)
	{
		int addleffect = moves[mid].effectaccuracy;
		if(fighters[target].ability == abilitySereneGrace)
			addleffect *= 2;
		if(rrand(100) < addleffect)
			__move_AdditionalEffect(mid, attacker, target);
		//King's Rock
	}

	//TODO	If Poison Point, etc. triggered above, user's Synchronize somehow triggers here even if condition is removed before now (true except for Triple Kick)
	int j;
	for(j=0; j < 4; j++)
		fighters_BerryCureCheck(j, false);
	//fighters_UpdateTargetedMove(thismove,attacker);
}

int fighters_UseMoveSimple(int index, int mid)
{
	choices[index][0] = 1; //MOVE
	choices[index][1] = 10 + mid; //hack!!
	choices[index][2] = (u32)&moves[mid]; //Do we even -use- this?
	choices[index][3] = index ^ 1; //stop with the hacks please XD
	return fighters_UseMove(index);
}

int fighters_UseMove(int index)
{
	AGBPrintf("fighter_UseMove(idx %d)\n",index);

	if(choices[index][0] != CHOICE_MOVE)
		return false;

	int mid = GetMonsterStats(fighters[index].mon, pMove1 + choices[index][1]);
	if(choices[index][1] == -2) //Struggle?
	{
		//Don't reduce PP. Just hack the MID to be Struggle and use that.
		mid = moveStruggle;
	}
	else if(choices[index][1] > 10) //another hack...
		mid = choices[index][1] - 10; //anything higher than 10 means that MID = choice - 10...
	else
		if(!fighters_ReducePP(index,choices[index][1]))
		{
			btlsayf(BT_XUsedX, fighters_This(index), moveNames[mid]);
			btlsayf(BT_ButThereWasNoPPLeftForTheMove);
			fighters[index].lastMoveUsedSketch = mid;
			return false;
		}

	if(__move_TwoTurnAttack(mid, index))
	{
		//beginning use of two-turn attack
		fighters[index].effTwoTurnAttack = mid;
		fighters[index].currentMove = mid;
		fighters[index].lastMoveUsed = mid;
		fighters[index].lastMoveCalled = mid;
	}
	else
	{
		fighters[index].effTwoTurnAttack = 0; //cancel use of two-turn attack
		fighters[index].lastMoveUsedSketch = mid;
		fighters[index].lastMoveUsed = mid;
		fighters[index].lastMoveCalled = mid;
		switch(__move_DisplayUseMessage(mid, index))
		{
			case 1: return true;
			case -1: return false;
		}
	}

	int targets[4];
	int user = fighters_FindUser(index,targets);
	int tlen = fighters_GetTargetLen(targets);
	int selffaint = (mid == moveExplosion) || (mid == moveSelfdestruct) || (mid == moveMemento);
	//check for any player with the Damp ability, which prevents self-fainting moves

	int db;
	for(db = 0; db < tlen; db++)
	{
		AGBPrintf("Target %d = %d\n", db, targets[db]);
	}

	if(selffaint)
	{
		int bearer = battle_CheckGlobalAbility(abilityDamp);
		if(bearer >= 0)
		{
			btlsayf(BT_XsXPreventsXFromUsingX,fighters_This(bearer), Abilities[fighters[bearer].ability], moveNames[mid], fighters_This(index));
			return false;
		}
		else
		{
			fighters[index].mon->Status.CurrentHP = 0;
		}
	}

	if(!__move_OnStartUse(mid,index)) //used by Magnitude to precalc base damage
		return false;

	if(tlen==0)
	{
		//user = pbChangeUser(mid,user)
		__move_Effect(mid, user, 0);
	} else
	{
		int t;
		for(t = 0; t < tlen; t++)
		{
			int numhits = __move_NumHits(mid);
			if(__move_IsMultiHit(mid))
				fighters_ProcessMultiHitMove(mid,index,targets[t],numhits);
			else
				fighters_ProcessNonMultiHitMove(mid,index,targets[t], 1);
		}
	}

	if((mid==moveMimic)||(mid==moveSketch)||(mid==moveTransform))
	{
		fighters[index].lastMoveUsedSketch=-1;
		fighters[index].lastMoveUsed=-1;
	}
	else
	{
		fighters[index].lastMoveUsedSketch=mid;
		fighters[index].lastMoveUsed=mid;
	}

	if(selffaint)
	{
		fighters[index].mon->Status.CurrentHP=0;
		fighters_Faint(index);
	}

	battle_GainEXP();
	return true;
}

void fighters_BeginTurn(int index)
{
	fighters[index].effDestinyBond = 0;
	fighters[index].effGrudge = 0;
	if(fighters[index].effEncore)
	{
		fighters[index].effEncore = 0;
		fighters[index].effEncoreIndex = 0;
	}
	if(fighters[index].ability != abilitySoundproof)
	{
		int i;
		for(i=0; i<4;i++)
		{
			if(fighters[i].effUproar)
			{
				fighters[index].effNightmare = 0;
				btlsayf(BT_XWokeUpInTheUproar, fighters_This(index));
				fighters[index].mon->Status.AilmentSleep = 0;
				break;
			}
		}
	}
}

void fighters_EndTurn(int index)
{
	fighters[index].effConversion2Move = 0;
	fighters[index].effConversion2Type = 0;
	int i;

	//Time Stop!
	for(i = 0; i < 4; i++)
	{
		if(fighters[i].effTimeStop)
		{
			fighters[i].effTimeStop--;
			if(fighters[i].effTimeStop == 0)
			{
				btlsays("Soshite, toki wa ugokidasu...");

				signed int diff = fighters[i].mon->Status.Speed - fighters[fighters_Opposing1(i)].mon->Status.Speed;
				if(diff > 0) fighters[i].effTimeStopDmg -= diff;

				fighters_DrainHP(fighters_Opposing1(i), fighters[i].effTimeStopDmg);
				if(fighters[fighters_Opposing1(i)].mon->Status.CurrentHP <= 0) fighters_Faint(fighters_Opposing1(i));
			}
		}
	}

	//for(i = 0; i < 4; i++)
		//fighters_pbAbilityCureCheck(i);

	for(i = 0; i < 4; i++)
		fighters_BerryCureCheck(i, false);

	//for(i = 0; i < 4; i++)
		//fighters_pbTrace(i,0);

	//for(i = 0; i < 4; i++)
		//fighters_pbForecast(i);

	for(i = 0; i < 4; i++)
		fighters_BerryCureCheck(i, false);
}

int fighters_TryUseMove(int index)
{
	if(choices[index][0] != CHOICE_MOVE) //move was not chosen
		return false;

	if(fighters[index].effPursuit) //turn is skipped
	{
		fighters[index].effPursuit = 0;
		return false;
	}

	if(	(fighters[index].effTwoTurnAttack) ||
			(fighters[index].effOutrage) ||
			(fighters[index].effHyperBeam) ||
			(fighters[index].effBide) ||
			(fighters[index].effRollout) ||
			(fighters[index].effUproar))
	{
		choices[index][2] = (u32)&moves[fighters[index].currentMove];
	} else if(fighters[index].effEncore)
	{
		if(	(battle_CanShowCommands(index)) &&
				(battle_CanChooseMove(index, fighters[index].effEncoreIndex, 0)))
		{
			choices[index][1] = fighters[index].effEncoreIndex;
			choices[index][2] = (u32)&moves[choices[index][1]];
		}
	}

	int mid = GetMonsterStats(fighters[index].mon, pMove1 + choices[index][1]);

	//aMove * thisMove = (aMove*)choices[index][2];
	fighters_BeginTurn(index);
	fighters[index].lastMoveUsed = -1;
	fighters[index].lastMoveCalled = -1;
	//if(!pbObedienceCheck(index))
	//	return false;

	if(fighters[index].mon->Status.AilmentSleep)
	{
		if(fighters[index].ability == abilityEarlyBird)
			fighters[index].mon->Status.AilmentSleep -= 2;
		else
			fighters[index].mon->Status.AilmentSleep -= 1;

		if(fighters[index].mon->Status.AilmentSleep <= 0)
		{
			fighters[index].effNightmare = 0;
			fighters[index].mon->Status.AilmentSleep = 0;
			btlsayf(BT_XWokeUp, fighters_This(index));
		}
		else
		{
			btlsayf(BT_XIsFastAsleep, fighters_This(index));
			return false;
		}
	}

	if((fighters[index].mon->Status.AilmentFrozen) && (mid != moveFlameWheel) && (mid != moveSacredFire))
	{
		if(rrand(10) == 0)
		{
			btlsayf(BT_XWasDefrosted, fighters_This(index));
			fighters[index].mon->Status.AilmentFrozen = 0;
		}
		else
		{
			btlsayf(BT_XIsFrozenSolid, fighters_This(index));
			return false;
		}
	}

	if(fighters[index].effHyperBeam)
	{
		btlsayf(BT_XMustRecharge, fighters_This(index));
		return false;
	}

	//TODO	Torment message goes here
	if((fighters[index].ability == abilityTruant) && (fighters[index].effTruant))
	{
		btlsayf(BT_XIsLoafingAround, fighters_This(index));
		return false;
	}

	if(fighters[index].effFlinch) //No Inner Focus check here
	{
		btlsayf(BT_XFlinched, fighters_This(index));
		fighters[index].effFlinch = 0;
		return false;
	}

// if @effects[PBEffects::Disable]>0 && thismove.id==@effects[PBEffects::DisableMove]
//  @battle.pbDisplayPaused("#{pbThis}'s #{thismove.name} is disabled!")
//  return false
// end
	if((fighters[index].effTaunt) && (moves[mid].basepower == 0))
	{
		btlsayf(BT_XCantUseXAfterTheTaunt, fighters_This(index), moveNames[mid]);
		return false;
	}

	//TODO	Imprisoning

	if(fighters[index].effConfusion)
	{
		fighters[index].effConfusion--;
		if(fighters[index].effConfusion == 0)
		{
			btlsayf(BT_XSnappedOutOfConfusion, fighters_This(index));
		} else
		{
			btlsayf(BT_XIsConfused, fighters_This(index));
			if(rrand(2) == 0)
			{
				btlsayf(BT_ItHurtItselfInItsConfusion);
				fighters_ConfusionDamage(index);
				return false;
			}
		}
	}

	if(fighters[index].mon->Status.AilmentParalysis)
	{
		if(rrand(4) == 0)
		{
			btlsayf(BT_XIsParalyzedItCantMove, fighters_This(index));
			return false;
		}
	}
	if(fighters[index].effAttract >= 0)
	{
		btlsayf(BT_XIsInLoveWithX, fighters_This(index), fighters_This(fighters[index].effAttract));
		if(rrand(2) == 0)
		{
			btlsayf(BT_XIsImmobilizedByLove, fighters_This(index));
			return false;
		}
	}

	if(	(fighters[index].mon->Status.AilmentFrozen) &&
			((mid == moveFlameWheel) ||
			(mid == moveSacredFire)))
	{
		btlsayf(BT_XWasDefrostedByX, fighters_This(index), moveNames[mid]);
		fighters[index].mon->Status.AilmentFrozen = 0;
	}

	return true;
}

void fighters_CancelMoves(int index)
{
	if(fighters[index].effTwoTurnAttack)
		fighters[index].effTwoTurnAttack = 0;

	fighters[index].currentMove = 0;
	fighters[index].effBide = 0;
	fighters[index].effOutrage = 0;
	fighters[index].effUproar = 0;
	fighters[index].effRollout = 0;
	fighters[index].effFuryCutter = 0;
}

int fighters_GetTargetLen(int * targets)
{
	int i;
	for(i = 0; i < 4; i++)
		if(targets[i] < 255)
			return i+1;

	return false;
}

int fighters_ProcessTurn(int index)
{
	AGBPrintf("fighters_ProcessTurn(%d)\n", index);
	if(choices[index][0] != CHOICE_MOVE)
	{
		fighters_BeginTurn(index);
		fighters_EndTurn(index);
		return false;
	}

	int ret = fighters_TryUseMove(index);
	if(!ret)
	{
		fighters_CancelMoves(index);
		fighters_EndTurn(index);
		battle_Switch();
		return false;
	}

	ret=0;
	ret=fighters_UseMove(index);
	fighters_EndTurn(index);
	battle_Switch();
	return ret;
}
