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

#define btlYesNoLoop() btlMultipleChoice(21,8,8, 0,0) //Choice_YesNo)

#ifdef WITH_SHIRTCOLORS
extern const unsigned short shirtcolors[32];
#endif

extern const unsigned long XPRequirements[808];

extern int btlWindowShifts[3];
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

aBattle ThisBattle;	//Main state of battle
aFighter fighters[4];	//Fighter status... statuses? Statii?
int priority[4];		//Order of execution
aBattleSide sides[2];	//Arena statii
int choices[4][4];		//Choices made
unsigned char participants[6];	//Which of YOUR party members have fought the CURRENT opponent?

//Fade colors
const unsigned short RedStrip[16] =
{
	0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,
	0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,0x25BF,
};
const unsigned short WhiteStrip[16] =
{
	0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,
	0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,0x7FFF,
};

char __pbThis[4][64];

#define BTLBACK(x)  extern const unsigned short battle ## x ## Pal[]; \
					extern const unsigned short battle ## x ## Tiles[]; \
					extern const unsigned short battle ## x ## Map[];
	BTLBACK(grass)
	BTLBACK(gym)
	BTLBACK(water)
#undef BTLBACK
#define BTLBACK(x,y) battle ## x ## Tiles, battle ## x ## Map, battle ## x ## Pal, (unsigned short*)y,
const unsigned short * const battlebacks[] =
{
	BTLBACK(grass,BTLENV_TALLGRASS)
	BTLBACK(gym,BTLENV_NONE)
	BTLBACK(water,BTLENV_MOVINGWATER)
};
#undef BTLBACK

extern const char TrainerRewards[][2];
int GetCashReward()
{
	int i, maxlevel=0;
	int kind = Trainers[ThisBattle.trainerindex].kind;
	int ps = Trainers[ThisBattle.trainerindex].partysize;
	aTrainerMonster *team = Trainers[ThisBattle.trainerindex].pack;

	//Find the trainer's highest level as a payout multiplier.
	for(i = 0; i < ps; i++)
		if(team[i].level > maxlevel)
			maxlevel = team[i].level;

	//This should scan through the list, break at the first entry that matches the current trainer type, or end up at the terminating 0xFF, in which case that entry's payout is given by default.
	i = 0;
	while(TrainerRewards[i][0] != 0xFF)
	{
		if(TrainerRewards[i][0] == kind)
			break;
		i++;
	}

	return (TrainerRewards[i][1] * 4) * maxlevel;
}


int Battle(int kind, int opponent, int background, void * onWin)
{
//	fighters[0].pokemonIndex = 0;
//	fighters[1].pokemonIndex = 1;
//	fighters[2].pokemonIndex = 2;
//	fighters[3].pokemonIndex = 3;

//	ThisBattle.background = battlebacklist[MyPlayer.currentMap]; //background;
	memset((char*)&ThisBattle, 0, sizeof(ThisBattle));

//	ThisBattle.background = background;

	if(kind == 1)
		ThisBattle.trainer = kind;

	scene_BuildBattleScreen();

	if (kind == 0) //wild
	{
		scene_StartWildBattle();
//KAWA - This part is for the demo game.
		if(ThisBattle.decision == 10)
		{
			extern void ZeldaHomage();

			FadeOut();
			ClearOamBak();
			scene_BreakBattleScreen();
			ZeldaHomage();
			FadeOut();
			return 1;
		}
// </demo>
		//Runaway hack
		if(ThisBattle.decision == 3)
		{
			Trg = 0;
			Cont = 0;
			FadeOut();
			ClearOamBak();
			scene_BreakBattleScreen();
			return 0;
		}
	}
	else if (kind == 1) //trainer
	{
		ExpandTrainerTeam((aTrainer*)&Trainers[opponent]);
		ThisBattle.onWin = onWin;
		scene_StartTrainerBattle(opponent);
	}
	else if (kind == 2) //roamer
	{
		scene_StartWildBattle();
		ThisBattle.roamer = 1;
	}

	if (ThisBattle.weather == WEATHER_SUNNYDAY)
	{
		//No message
	}
	else if (ThisBattle.weather == WEATHER_RAINDANCE)
		btlsayf(BT_ItIsRaining);
	else if (ThisBattle.weather == WEATHER_HAIL)
		btlsayf(BT_ASandstormIsRaging);

	battle_OnActiveAll();

	while (1)
	{
		DoVBlank();
		battle_CommandPhase();
		if (ThisBattle.decision)
			break;
		battle_AttackPhase();
		if (ThisBattle.decision)
			break;
		battle_EndOfRoundPhase();
		if (ThisBattle.decision)
			break;
	}

	if (ThisBattle.decision == 1) //WIN
	{
		if(ThisBattle.trainer)
		{
			btlsayf(BT_PlayerDefeatedXX,
					TrainerTypes[Trainers[ThisBattle.trainerindex].kind],
					scene_GetTrainerName(ThisBattle.trainerindex));

			ThisBattle.cashwon = GetCashReward();

			if(ThisBattle.internalbattle)
			{
				if(ThisBattle.onWin)
					scene_DoTrainerDefeatSpeech();
				btlsayf(BT_XGotYForWinning, PlayerName, ThisBattle.cashwon);
				MyPlayer.cash += ThisBattle.cashwon;
				if (MyPlayer.cash == 999999)
					MyPlayer.cash = 999999;
			}
		}
	}
	else if(ThisBattle.decision == 2) //LOSE
	{
		int moneylost;
		moneylost = battle_MaxLevel(MyParty)*120;
		if (moneylost > MyPlayer.cash) moneylost = MyPlayer.cash;
		MyPlayer.cash -= moneylost;

		if(ThisBattle.trainer)
		{
			btlsayf(BT_XIsOutOfUsablePokemonPlayerLostAgainstXX, PlayerName,
					TrainerTypes[Trainers[ThisBattle.trainerindex].kind],
					scene_GetTrainerName(ThisBattle.trainerindex));
			if(moneylost)
				btlsayf(BT_XPaidXAsThePrizeMoneyXWhitedOut, PlayerName, moneylost, PlayerName);
		}
		else
		{
			btlsayf(BT_XIsOutOfUsablePokemon, PlayerName);
			if(moneylost)
			{
				btlsayf(BT_XPanickedAndLostXXWhitedOut, PlayerName, moneylost, PlayerName);
			}
		}
	}

	Trg = 0;
	Cont = 0;
	FadeOut();
	ClearOamBak();
	scene_BreakBattleScreen();
	return ThisBattle.decision - 1;
	return 0;
}


int GetTypeAdvantage1(int atktype, int opptype)
{
	return TypeAdvantages[atktype * 18 + opptype];
}
int GetTypeAdvantage2(int atktype, int opptype1, int opptype2)
{
	int m1 = TypeAdvantages[atktype * 18 + opptype1];
	int m2 = TypeAdvantages[atktype * 18 + opptype2];
	return m1 * m2;
}

//Handles the whole "wipe open and scroll" animation
void battle_OpenAnimation()
{
	REG_BLDCNT = 0;
	u8 i;
	BattlePan(0);
	for(i = 0; i < 128; i++)
	{
		if(i <= 40)
			REG_WIN0V = ((80-(i*2)) << 8) + (80+(i*2));

		BattlePanOffset = i*2;
		AGBPrintf("*BattlePanOffset: %d\n", BattlePanOffset);
	// Move player's sprite
		OamBak[0].HPos = 256 + 24 - BattlePanOffset;
	// Move wild Pokémon's sprite
		OamBak[1].HPos = 256 + SINGLE_BTL_OPP_HPOS + BattlePanOffset;
		DoVBlank();
	}
	BattlePan(1);
}

//Handles the sending out of a fighter.
void battle_SendOut(int side, int partyindex, int flags)
{
	ssPersonal *myP;
	int i, scale;

	if(side==0)
		fighters[side].mon = &MyParty[partyindex];
	else
		fighters[side].mon = &HisParty[partyindex];

	int species = GetMonsterStats(fighters[side].mon, pSpecies);
	myP = (ssPersonal*)&fighters[side].mon->Personal;

	Pokedex_RegisterPkmn(species,0);

//	if(BaseStats[species].Gender < 0xFF)
//	{
//		if((u8)myP->Personal > BaseStats[species].Gender)
//		{
//			genderchar = 0x8A; //Male
//			gendercolor = 11;
//		} else
//		{
//			genderchar = 0x8B; //Female
//			gendercolor = 10;
//		}
//	}

	if(side == 0) //you
	{
		LoadPokemonPic(species,LPP_BACK | (LPP_SHINY*IsShiny(fighters[side].mon)),MEM_VRAM_OBJ,pal_obj_bank[0],fighters[side].mon->Personal.Personal);

		SetupPokemonSprite(0);
		fighters[side].spriteVOffset = HeightDataBack[species];
		OamBak[0].HPos = SINGLE_BTL_PLAYER_HPOS;
		OamBak[0].VPos = SINGLE_BTL_PLAYER_VPOS + fighters[side].spriteVOffset; //54;
		OamBak[0].Priority = 2;
		//DmaArrayCopy(playerwindowTiles, MEM_VRAM_OBJ + 0x1380);
		//sprintf(foo, "%s\a\1%c%c", GetNickname(fighters[side].mon), gendercolor, genderchar);
		//scene_WriteInBox(0, foo);
		//sprintf(foo, " \x81%d", GetMonsterStats(fighters[side].mon, pLevel));
		//scene_WriteInBox(2, foo);
		//sprintf(foo, "%d/%d", GetMonsterStats(fighters[side].mon, pCurrentHP), GetMonsterStats(fighters[side].mon, pTotalHP));
		//scene_WriteInBox(4, foo);
		//MakeHPBar(GetMonsterStats(fighters[side].mon, pCurrentHP), GetMonsterStats(fighters[side].mon, pTotalHP), MEM_VRAM_OBJ + 0x3380, 0);
//		btlWindowShifts[0] = -72;
//		scene_BuildPlayerWin();

		if(flags & SEND_POOF)
		{
			//Work in progress...
			OamBak[0].Pltt = 8;
			OamBak[0].AffineMode = 1;
			OamBak[0].AffineParamNo_L = 0;
			OamBak[0].HPos = 250;
			pal_blend_asm5((u16*)MEM_PAL_OBJ, RedStrip, (u16*)MEM_PAL_OBJ+0x80,16,32);
			DmaCopy(MEM_PAL, MEM_PAL + 0x20, 32);
			for(i=0; i < 32; i+=2)
			{
				pal_blend_asm5((u16*)MEM_PAL+0x10, WhiteStrip, (u16*)MEM_PAL,16,i);
				DoVBlank();
			}
			OamBak[0].HPos = 39;
			for(i=32; i >= 0; i--)
			{
				scale = 0x100 + (i << 4);
				OamBak[0].AffineParam = scale;
				OamBak[3].AffineParam = scale;
				OamBak[0].VPos = 48 + fighters[side].spriteVOffset + (i>>1);
				pal_blend_asm5((u16*)MEM_PAL_OBJ, RedStrip, (u16*)MEM_PAL_OBJ+0x80,16,i);
				pal_blend_asm5((u16*)MEM_PAL+0x10, WhiteStrip, (u16*)MEM_PAL,16,i);
				DoVBlank();
			}
			OamBak[0].Pltt = 0;
			OamBak[0].AffineMode = 0;
		}

		if(flags & SEND_CRY)
		{
			sndPlayCry(species, 60);
		}

		if(flags & SEND_SCROLLWIN)
			scene_BuildPlayerWin();
//		{
//			for(i = 0; i < 44; i+=4)
//			{
//				btlWindowShifts[0] = -40 + i;
//				OamBak[2].HPos = 158 + (124 - (i * 4));
//				OamBak[3].HPos = 190 + (124 - (i * 4));
//				OamBak[6].HPos = 140 + (124 - (i * 4));
//				OamBak[8].HPos = 126 + (124 - (i * 4));
//				OamBak[9].HPos = 190 + (124 - (i * 4));
//				DoVBlank();
//			}
//		}

	}
	else // Opponent
	{
		LoadPokemonPic(species, LPP_NORMAL | (LPP_SHINY*IsShiny(fighters[side].mon)),MEM_VRAM_OBJ+0x800,pal_obj_bank[1],fighters[side].mon->Personal.Personal);

		SetupPokemonSprite(1);
		fighters[side].spriteVOffset = HeightDataFront[species];
		OamBak[1].HPos = SINGLE_BTL_OPP_HPOS;
		OamBak[1].VPos = SINGLE_BTL_OPP_VPOS + fighters[1].spriteVOffset; //16;
		OamBak[1].Priority = 2;
		//DmaArrayCopy(enemywindowTiles, MEM_VRAM_OBJ + 0x2380);
		//sprintf(foo, "%s\a\1%c%c", GetNickname(fighters[side].mon), gendercolor, genderchar);
		//scene_WriteInBox(1, foo);
		//sprintf(foo, " \x81%d", GetMonsterStats(fighters[side].mon, pLevel));
		//scene_WriteInBox(3, foo);
		//MakeHPBar(GetMonsterStats(fighters[side].mon, pCurrentHP), GetMonsterStats(fighters[side].mon, pTotalHP), MEM_VRAM_OBJ + 0x3480, 0);
//		scene_BuildOpponentWin();
//		btlWindowShifts[1] = -110;

		if(flags & SEND_POOF)
		{
			OamBak[1].Pltt = 9;
			pal_blend_asm5((u16*)MEM_PAL_OBJ+0x10, RedStrip, (u16*)MEM_PAL_OBJ+0x90,16,32);
			DmaCopy(MEM_PAL, MEM_PAL + 0x20, 32);
			for(i=0; i < 32; i+=2)
			{
				pal_blend_asm5((u16*)MEM_PAL+0x10, WhiteStrip, (u16*)MEM_PAL,16,i);
				DoVBlank();
			}
			for(i=32; i >= 0; i--)
			{
				pal_blend_asm5((u16*)MEM_PAL_OBJ+0x10, RedStrip, (u16*)MEM_PAL_OBJ+0x90,16,i);
				pal_blend_asm5((u16*)MEM_PAL+0x10, WhiteStrip, (u16*)MEM_PAL,16,i);
				DoVBlank();
			}
			OamBak[1].Pltt = 1;
		}

		if(flags & SEND_CRY)
		{
			sndPlayCry(species, 60);
		}

		if(flags & SEND_SCROLLWIN)
			scene_BuildOpponentWin();
//		{
//			for(i = 0; i < 110; i+=4)
//			{
//				btlWindowShifts[1] = -160 - i;
//				OamBak[2].HPos = 158 + (124 - (i * 4));
//				OamBak[3].HPos = 190 + (124 - (i * 4));
//				OamBak[6].HPos = 140 + (124 - (i * 4));
//				OamBak[8].HPos = 126 + (124 - (i * 4));
//				OamBak[9].HPos = 190 + (124 - (i * 4));
//				DoVBlank();
//			}
//		}
	}

	if(myP->Personal % 2)	i = BaseStats[species].Ability1;
	else									i = BaseStats[species].Ability2;
	if(i==0)							i = BaseStats[species].Ability1;
	fighters[side].ability = i;
	fighters[side].species = species;

	fighters[side].pokemonIndex = partyindex;
}



int battle_IsOpposing(int index)
{
	return (index%2);
}

int battle_IsDoubleBattler(int index)
{
	return (index>=2);
}

aPokemon * battle_Party(int index)
{
	return battle_IsOpposing(index) ? HisParty : MyParty;
}

const char * battle_ThisEx(int fighterindex, int monsterindex)
{
	char namebuf[12];
	aPokemon * party = battle_Party(fighterindex);
	int i;
	for(i = 0; i < 10; i++)
	{
		if(party[monsterindex].Personal.Nickname[i] == 0)
			break;
		namebuf[i] = party[monsterindex].Personal.Nickname[i];
	}
	namebuf[i] = 0;

	sprintf(__pbThis[monsterindex],"%s",namebuf);

	return  __pbThis[monsterindex];
}

int battle_MaxLevel(aPokemon * party)
{
	int lv=0, i;
	for(i=0; i < 6; i++)
	{
		if(party[i].Personal.OTID)
		{
			if(party[i].Status.Level > lv)
				lv = party[i].Status.Level;
		}
		else
		{
			break;
		}
	}
	return lv;
}

int battle_CheckGlobalAbility(int a)
{
	int i;
	for(i=0; i < 4; i++) //in order from own first, opposing first, own second, opposing second
	{
		if(fighters[i].ability == a)
		{
			return i;
		}
	}
	return -1;
}

int battle_Weather()
{
	int i;
	for(i=0; i < 4; i++)
	{
		if((fighters[i].ability == abilityCloudNine) || (fighters[i].ability == abilityAirlock))
		{
			return false;
		}
	}
	return ThisBattle.weather;
}

int battle_Run(int idxPokemon, int duringBattle)
{
	if(battle_IsOpposing(idxPokemon))
	{
		if(ThisBattle.trainer)
		{
			return false;
		} else
		{
			btlsayf(BT_WildXFled, fighters[idxPokemon].mon->Personal.Nickname);
			return true;
		}
	}
	if(demo==1) //are we running a demo?
	{
		btlsays(strBattleDemoQuit);
		ThisBattle.decision = 3;
		return true;
		//always succeed
	}
	if(ThisBattle.trainer)
	{
		btlsayf(BT_NoTheresNoRunningFromATrainerBattle);
		return false;
	}
	if(GetMonsterStats(fighters[idxPokemon].mon, pHeldItem) == itemSmokeBall)
	{
		if(ThisBattle.duringBattle)
			btlsayf(BT_GotAwaySafely);
		else
			btlsayf(BT_XFledUsingItsX, fighters_This(idxPokemon), items[itemSmokeBall].name);
		return true;
	}
	if(fighters[idxPokemon].ability == abilityRunaway)
	{
		if(ThisBattle.duringBattle)
			btlsayf(BT_GotAwaySafely);
		else
			btlsayf(BT_XFledUsingX, fighters_This(idxPokemon), Abilities[fighters[idxPokemon].ability]);
		return true;
	}
	if((!ThisBattle.duringBattle) && (!battle_CanSwitch(idxPokemon,-1,1)))
	{
		btlsayf(BT_CantEscape);
		//ThisBattle.decision = 0;
		return false;
	}

	//Note: not pbSpeed, because using unmodified Speed
	int opposer = fighters_OppositeOpposing(idxPokemon);
	int speedPlayer = fighters[idxPokemon].mon->Status.Speed;
	int speedEnemy = fighters[opposer].mon->Status.Speed;
	int rate = speedPlayer * 128 / speedEnemy;
	rate+=ThisBattle.runCommand*30;
	rate&=0xFF;
	int ret = 1;
	if(rrand(256)<rate)
	{
		btlsayf(BT_GotAwaySafely);
		ThisBattle.decision = 3;
	} else
	{
		btlsayf(BT_CantEscape);
		ret = -1;
	}

	if(!duringBattle)
		ThisBattle.runCommand++;

	return ret;
}

int battle_RegisterMove(int idxPokemon, int idxMove)
{
	if(!battle_CanChooseMove(idxPokemon,idxMove,1))
		return false;

//	aMove * thisMove = (aMove*)&moves[GetMonsterStats(fighters[idxPokemon].mon, pMove1 + idxMove)];
	choices[idxPokemon][0] = CHOICE_MOVE;
	choices[idxPokemon][1] = idxMove; //myA->Attack[idxMove]; //index of move
//	choices[idxPokemon][2] = (u32)thisMove; //move object
	choices[idxPokemon][3] = -1; //no target chosen
	return true;
}

int battle_IsMoveSensible(int index, int dice)
{
	int mid = GetMonsterStats(fighters[index].mon, pMove1 + dice);
	int mfx = moves[mid].effect;

	if(mfx == 0x01 && fighters[fighters_Opposing1(index)].mon->Status.AilmentSleep)
	{	//Better not put opponent to sleep again.
		return false;
	}
	if(mfx == 0x08 && !fighters[fighters_Opposing1(index)].mon->Status.AilmentSleep)
	{	//Only works if opponent is asleep
		return false;
	}
	if(mfx == 0x21 && fighters[fighters_Opposing1(index)].mon->Status.AilmentPoison)
	{	//Better not poison opponent again.
		return false;
	}
	if(mfx == 0x31 && fighters[fighters_Opposing1(index)].effConfusion)
	{	//Better not confuse opponent again.
		return false;
	}
	if(mfx == 0x42 && fighters[fighters_Opposing1(index)].mon->Status.AilmentBadPoison)
	{	//Better not badly poison opponent again.
		return false;
	}
	if(mfx == 0x54 && fighters[fighters_Opposing1(index)].effLeechSeed)
	{	//Better not leech opponent again.
		return false;
	}
	if(mfx == 0x6B && !fighters[fighters_Opposing1(index)].mon->Status.AilmentSleep)
	{	//Only works if opponent is asleep
		return false;
	}
	if(mfx == 0xB0 && !ThisBattle.doublebattle)
	{	//Helping Hand only works if there's a partner
		return false;
	}
	return true;
}

int battle_CanChooseMove(int idxPokemon, int idxMove, int showMessages)
{
	int mid = GetMonsterStats(fighters[idxPokemon].mon, pMove1 + idxMove);
	int mpp = GetMonsterStats(fighters[idxPokemon].mon, pPP1 + idxMove);
	aMove * thisMove = (aMove*)&moves[mid];

	if((!thisMove) || (mid == 0))
		return false;

	if(mpp <= 0)
	{
		if(showMessages)
			btlsayf(BT_TheresNoPPLeftForThisMove);
		return false;
	}
	if(fighters[idxPokemon].effChoiceBand &&
		 mid != fighters[idxPokemon].effChoiceBand &&
		 GetMonsterStats(fighters[idxPokemon].mon, pHeldItem) == itemChoiceBand)
	{
		if(showMessages)
		{
			btlsayf(BT_XsEffectAllowsOnlyXToBeUsed, fighters_This(idxPokemon),moveNames[fighters[idxPokemon].effChoiceBand]);
		}
		return false;
	}
/*
	if(opp1->effImprison)
	{
		move * opp1moves1 = (move*)opp1->moves[0];
		move * opp1moves2 = (move*)opp1->moves[1];
		move * opp1moves3 = (move*)opp1->moves[2];
		move * opp1moves4 = (move*)opp1->moves[3];
		if((mid == opp1moves1->id) ||
			 (mid == opp1moves2->id) ||
			 (mid == opp1moves3->id) ||
			 (mid == opp1moves4->id))
		{
			if(showMessages)
			{
				BattleTextLoop("Can't use the sealed foo!");
			}
			return false;
		}
	}
	if(opp2->effImprison)
	{
		move * opp2moves1 = (move*)opp2->moves[0];
		move * opp2moves2 = (move*)opp2->moves[1];
		move * opp2moves3 = (move*)opp2->moves[2];
		move * opp2moves4 = (move*)opp2->moves[3];
		if((mid == opp2moves1->id) ||
			 (mid == opp2moves2->id) ||
			 (mid == opp2moves3->id) ||
			 (mid == opp2moves4->id))
		{
			if(showMessages)
			{
				BattleTextLoop("Can't use the sealed foo!");
			}
			return false;
		}
	}
*/
	if(fighters[idxPokemon].effTaunt && thisMove->basepower == 0)
	{
		if(showMessages)
			btlsayf(BT_XCantUseXAfterTheTaunt,fighters_This(idxPokemon), moveNames[mid]);
		return false;
	}
	if(fighters[idxPokemon].effTorment && mid == fighters[idxPokemon].lastused)
	{
		if(showMessages)
			btlsayf(BT_XCantUseTheSameMoveInARowDueToTheTorment,fighters_This(idxPokemon));
		return false;
	}
	if(fighters[idxPokemon].effDisableTimer && mid == fighters[idxPokemon].effDisableMove)
	{
		if(showMessages)
			btlsayf(BT_XsXIsDisabled,fighters_This(idxPokemon), moveNames[mid]);
		return false;
	}

	return true;
}

void battle_AutoChooseMove(int idxPokemon)
{
	if(fighters[idxPokemon].mon->Status.CurrentHP <= 0)
	{
		choices[idxPokemon][0] = CHOICE_NONE;
		choices[idxPokemon][1] = 0;
		choices[idxPokemon][2] = 0;
		return;
	}
	if((fighters[idxPokemon].effEncore) && battle_CanChooseMove(idxPokemon,fighters[idxPokemon].effEncoreIndex,0))
	{
		choices[idxPokemon][0] = CHOICE_MOVE;
		choices[idxPokemon][1] = fighters[idxPokemon].effEncoreIndex;
		choices[idxPokemon][2] = (u32)&moves[fighters[idxPokemon].effEncoreIndex]; //I have a bad feeling about this...
		choices[idxPokemon][3] = -1;
	} else
	{
		if(!battle_IsOpposing(idxPokemon))
		{
			btlsayf(BT_XHasNoMovesLeft,fighters_This(idxPokemon));
		}
		choices[idxPokemon][0] = CHOICE_MOVE;
		choices[idxPokemon][1] = -2; //Special case to denote Struggle
		choices[idxPokemon][2] = (u32)&moves[moveStruggle]; //shouldn't be needed at all, really...
		choices[idxPokemon][3] = idxPokemon ^ 1; //single-battle hack, should Pokedex_RegisterPkmn as "the opponent". //-1;
	}
}

void battle_OnActiveAll()
{
	int i,j;
/*	Update participants in battles
	(unfainted participants will earn EXP
	even if they faint in between)*/
	for(i = 0; i < 4; i++)
	{
		if(battle_IsOpposing(i))
		{
			fighters_UpdateParticipants(i);
		}
	}
	ThisBattle.usepriority = 0;
	battle_SortPriorities(priority);
	for(i = 0; i < 4; i++)
	{
		if((fighters[priority[i]].ability == abilityDrizzle) && (fighters[priority[i]].mon->Status.CurrentHP))
		{
			ThisBattle.weather = WEATHER_RAINDANCE;
			ThisBattle.weatherduration = -1;
			btlsayf(BT_XsXMadeItRain,fighters_This(priority[i]), Abilities[fighters[priority[i]].ability]);
		}
		if((fighters[priority[i]].ability == abilitySandStream) && (fighters[priority[i]].mon->Status.CurrentHP))
		{
			ThisBattle.weather = WEATHER_SANDSTORM;
			ThisBattle.weatherduration = -1;
			btlsayf(BT_XsXWhippedUpASandstorm,fighters_This(priority[i]), Abilities[fighters[priority[i]].ability]);
		}
		if((fighters[priority[i]].ability == abilityDrought) && (fighters[priority[i]].mon->Status.CurrentHP))
		{
			ThisBattle.weather = WEATHER_SUNNYDAY;
			ThisBattle.weatherduration = -1;
			btlsayf(BT_XsXIntensifiedTheSunsRays,fighters_This(priority[i]), Abilities[fighters[priority[i]].ability]);
		}
	}
	for(i=0; i<4; i++)
	{
		if(fighters[i].mon->Status.CurrentHP <= 0) continue;
		for(j=0; j<4; j++)
		{
			if((fighters[i].ability == abilityIntimidate) && (fighters_IsOpposing(i,j)))
			{
				effect_ReducemovestatStageIntimidate(j,i);
			}
		}
	}
	for(i=0; i<4; i++)
	{
		fighters_Trace(i,true);
	}
	for(i=0; i<4; i++)
	{
		if(fighters[i].mon->Status.CurrentHP <= 0) continue;
		fighters_Forecast(i);
	}
}

int battle_OnActiveOne(int index)
{
	int i;
	if(fighters[index].mon->Status.CurrentHP <= 0) return false;
	for(i = 0; i<4; i++)
	{
		//if(fighters_IsOpposing(index,i))
		{
			fighters_UpdateParticipants(i);
		}
	}
	if(sides[fighters_OwnSide(index)].effSpikes > 0)
	{
		if((fighters[index].ability != abilityLevitate) && (fighters_HasType(index, tpFlying)))
		{
			int spikesdiv[] = { 0,8,6,4 };
			fighters_DrainHP(index, fighters[index].mon->Status.CurrentHP / spikesdiv[sides[fighters_OwnSide(index)].effSpikes]);
			btlsayf(BT_XIsHurtBySpikes, fighters_This(index));
		}
	}
	if(fighters[index].mon->Status.CurrentHP <= 0) fighters_Faint(index);
	for(i = 0; i < 4; i++)
	{
		fighters_AbilityCureCheck(i);
	}
	if(fighters[index].mon->Status.CurrentHP <= 0)
	{
		battle_GainEXP();
		battle_Switch();
		return false;
	}
	if((fighters[index].ability == abilityDrizzle) && (fighters[index].mon->Status.CurrentHP > 0))
	{
		ThisBattle.weather = WEATHER_RAINDANCE;
		ThisBattle.weatherduration = -1;
		btlsayf(BT_XsXMadeItRain,fighters_This(index), Abilities[fighters[index].ability]);
	}
	if((fighters[index].ability == abilitySandStream) && (fighters[index].mon->Status.CurrentHP > 0))
	{
		ThisBattle.weather = WEATHER_SANDSTORM;
		ThisBattle.weatherduration = -1;
		btlsayf(BT_XsXWhippedUpASandstorm,fighters_This(index), Abilities[fighters[index].ability]);
	}
	if((fighters[index].ability == abilityDrought) && (fighters[index].mon->Status.CurrentHP > 0))
	{
		ThisBattle.weather = WEATHER_SUNNYDAY;
		ThisBattle.weatherduration = -1;
		btlsayf(BT_XsXIntensifiedTheSunsRays,fighters_This(index), Abilities[fighters[index].ability]);
	}
	if(fighters[index].ability == abilityIntimidate)
	{
		for(i=0; i<4; i++)
		{
			if(fighters_IsOpposing(index,i))
			{
				effect_ReducemovestatStageIntimidate(i,index);
			}
		}
	}
	fighters_Trace(index,true);
	if((fighters[index].ability == abilitySpeedBoost) && (fighters[index].mon->Status.CurrentHP > 0))
	{
		// :3
	}
	for(i = 0; i < 4; i++)
	{
		fighters_Forecast(index);
	}
	fighters_BerryCureCheck(index,false);
	return true;
}

int battle_CanShowCommands(int idxPokemon)
{
	if(fighters[idxPokemon].mon->Status.CurrentHP <= 0)	return false;
	if(fighters[idxPokemon].effTwoTurnAttack) return false;
	if(fighters[idxPokemon].effHyperBeam) return false; //too busy recovering
	if(fighters[idxPokemon].effRollout)	return false;
	if(fighters[idxPokemon].effOutrage)	return false;
	if(fighters[idxPokemon].effUproar)	return false;
	if(fighters[idxPokemon].effBide)	return false;
	return true;
}

int battle_CanShowFightMenu(int idxPokemon)
{
	if(!battle_CanShowCommands(idxPokemon))
		return false;
	//No moves that can be chosen
	if((!battle_CanChooseMove(idxPokemon,0,0)) &&
		 (!battle_CanChooseMove(idxPokemon,1,0)) &&
		 (!battle_CanChooseMove(idxPokemon,2,0)) &&
		 (!battle_CanChooseMove(idxPokemon,3,0)))
	{
		return false;
	}
	//Encore
	if(fighters[idxPokemon].effEncore) return false;
	return true;
}

int battle_CanSwitchLax(int idxPokemon, int idxTo, int showMessages)
{
	if(idxTo >= 0)
	{
		aPokemon * party = battle_Party(idxPokemon);
		if(idxTo > GetPartySize(party))
		{
			return false;
		}
		if(party[idxTo].Status.CurrentHP <= 0)
		{
			if(showMessages)
			{
				btlsays(strBattleNoEnergyToFight, party[idxTo].Personal.Nickname);
			}
			return false;
		}
		if(fighters[idxPokemon].pokemonIndex == idxTo)
		{
			if(showMessages)
			{
				btlsays(strBattleAlreadyThere, party[idxTo].Personal.Nickname);
			}
			return false;
		}
		int partner = fighters_Partner(idxPokemon);
		if(fighters[partner].pokemonIndex == idxTo)
		{
			if(showMessages)
			{
				btlsays(strBattleAlreadyThere, party[idxTo].Personal.Nickname);
			}
			return false;
		}
	}
	return true;
}

int battle_CanSwitch(int idxPokemon, int idxTo, int showMessages)
{
	AGBPrintf("battle_CanSwitch(%d,%d,%d) > ",idxPokemon,idxTo,showMessages);
	//Multi-Turn moves/Mean Look
	if(!battle_CanSwitchLax(idxPokemon, idxTo, showMessages))
	{
		AGBPrintf("failed on Multi-Turn moves/Mean Look\n");
		return false;
	}
	int isOpposing = battle_IsOpposing(idxPokemon);
	//aPokemon * party = battle_Party(idxPokemon);
	int i;
	for(i = 0; i < 4; i++)
	{
		if(isOpposing != battle_IsOpposing(i)) continue;
		if((choices[i][0] == CHOICE_SWITCH) && (choices[i][1]==idxTo))
		{
			if(showMessages)
			{
				btlsays(strBattleAlreadySelected, MyParty[idxTo].Personal.Nickname);
			}
			AGBPrintf("%s has already been selected.\n", MyParty[idxTo].Personal.Nickname);
			return false;
		}
	}
	if((fighters[idxPokemon].effMultiTurn) || (fighters[idxPokemon].effMeanLook > 0))
	{
		if(showMessages)
		{
			btlsays(strBattleCantSwitch, fighters_This(idxPokemon));
		}
		AGBPrintf("%s can't be switched out due to Multi-Turn/Mean Look.\n", fighters_This(idxPokemon));
		return false;
	}
	//Ingrain
	if(fighters[idxPokemon].effIngrain)
	{
		if(showMessages)
		{
			btlsays(strBattleCantSwitch, fighters_This(idxPokemon));
		}
		AGBPrintf("%s can't be switched out due to Ingrain.\n", fighters_This(idxPokemon));
		return false;
	}
	int opp1 = fighters_Opposing1(idxPokemon);
	int opp2 = fighters_Opposing2(idxPokemon);
	int opp = -1;
	if(fighters_HasType(idxPokemon, tpSteel))
	{
		if(fighters[opp1].ability == abilityMagnetPull) opp = opp1;
		if(fighters[opp2].ability == abilityMagnetPull) opp = opp2;
	}
	if((!fighters_HasType(idxPokemon,tpFlying)) && (fighters[idxPokemon].ability == abilityLevitate))
	{
		if(fighters[opp1].ability == abilityArenaTrap) opp = opp1;
		if(fighters[opp2].ability == abilityArenaTrap) opp = opp2;
	}
	if(fighters[opp1].ability == abilityShadowTag)
		opp = opp1;
	if(fighters[opp2].ability == abilityShadowTag)
		opp = opp2;
	if(opp > -1)
	{
		if(showMessages)
		{
			btlsays(strBattleSwitchPrevented, Abilities[fighters[opp].ability]);
		}
		AGBPrintf("Opponent's %s prevents switching!\n", Abilities[fighters[opp].ability]);
		return false;
	}
	AGBPrintf("OK\n");
	return true;
}

int battle_RegisterSwitch(int idxPokemon, int idxTo)
{
	AGBPrintf("battle_RegisterSwitch(%d,%d)\n",idxPokemon,idxTo);
	if(!battle_CanSwitch(idxPokemon,idxTo,0))	return false;
	choices[idxPokemon][0] = CHOICE_SWITCH;
	choices[idxPokemon][1] = idxTo;
	choices[idxPokemon][2] = 0;
	return true;
}

int battle_RegisterItem(int idxPokemon, int idxItem)
{
	fighters_UseItem(idxPokemon,idxItem);
	choices[idxPokemon][0] = CHOICE_ITEM;
	choices[idxPokemon][1] = idxItem;
	choices[idxPokemon][2] = 0;
	return true;
}

int battle_RegisterTarget(int idxPokemon, int idxTarget)
{
	choices[idxPokemon][3] = idxTarget;
	return true;
}

//Okay, this is a big one. Who goes first is determined by several factors:
// -- moves with a higher priority value strike first
// -- If two or more moves have the same priority level, ties are broken
//    using each active Pokémon's Speed.
// -- At a 20% chance, all holders of Quick Claw whose moves have the same
//    priority level will strike at a random order and before other Pokémon
//    whose moves have the same priority level.
// -- If there are still ties in priority or Speed, ties are broken at random.

//Simple "player goes first" sort order by Kawa
void battle_SortPriorities(int * prios)
{
	int i;
	if(ThisBattle.usepriority)
	{
		return;
	}
	for(i=0; i<4; i++)
	{
		prios[i] = i;
	}
	return;
}
/*
//Impressive but unusable sorter by Cearn
void battle_SortPriorities(int *prios)
{
	if(ThisBattle.usepriority)
		return;

	int ii, jj;
	int speeds[4], quickclaw[4], prioritahs[4], temp[4];

	int prio, prioMin= 0, prioMax= 0;
	for(ii=0; ii<4; ii++)
	{
		prios[ii]= 0;
		speeds[ii]= fighters[ii].mon->Status.Speed;
		quickclaw[ii] = (GetMonsterStats(fighters[ii].mon, pHeldItem) == itemQuickClaw);
		prio= choices[ii][0] != 1 ? 0 : moves[choices[ii][1]].priority;
		prioritahs[ii]= prio;

		if(ii)
		{
			if(prio>prioMax)	prioMax= prio;
			if(prio>prioMin)	prioMin= prio;
		}
		else
			prioMax= prioMin= 0;	// init outside loop plz
	}

	int ip=0, it=0;
	ip= prioMax;

	// Find and order all moves with equal priorities
	for(ip= prioMax; ip>=prioMin; ip--)
	{
		it= 0;
		for(jj=0; jj<3; jj++)
			if(prioritahs[jj] == ip)
				temp[++it]= jj;

		//Sort by speed if multiple
		if(it == 0)
			prioritahs[ip]= temp[0]; //fighters[temp[0]];
		else
		{
			ii= 0;
			int nn= it+1;
			int useQuick= (rand(5)==0);
			int cmp;
			for(jj= 0; jj<=nn-1; jj++)
			{
				for(ii=jj+1; ii<nn-2; ii++)
				{
					// Rank higher if without Quick Claw, or equal if with it
					// Rank higher to higher-speed battler

					if(quickclaw[temp[ii]] && useQuick)
						cmp= quickclaw[temp[ii-1]] ? 0 : -1;
					else if(quickclaw[temp[ii-1]] && useQuick)
						cmp= 1;
					else if(speeds[temp[ii]] != speeds[temp[ii-1]])
						cmp= speeds[temp[ii]]>speeds[temp[ii-1]] ? 1 : 1;
					else
						cmp= 0;

					// random if equal speed
					if(cmp==0)
						cmp= -(rand()&1);

					// Faster goes first
					if(cmp<0)
					{
						int swapper = temp[ii];
						temp[ii] = temp[ii-1];
						temp[ii-1] = swapper;
					}
					//SWAP(temp[ii], temp[ii-1]);
				}
			}
		}
		for(ii=0; ii<it; ii++)
			prios[ii]= temp[ii]; //fighters[ii];

	}

	ThisBattle.usepriority= 1;
}
*/

int battle_AllFainted(aPokemon * party)
{
	int allfainted = 1, i;
	int ps = GetPartySize(party);
	for(i=0; i <= ps; i++)
	{
		if(party[i].Status.CurrentHP)
		{
			allfainted = 0;
			break;
		}
	}
	return allfainted;
}

void battle_AbilityEffect(int move, int user, int target)
{
	//TODO	Add Ability Effects.
	//UPC lacks the code...
	if(fighters[target].ability == abilityCuteCharm && fighters[target].damagestate.hplost)
	{
		if(fighters[user].ability == abilityOblivious) return;
		if(fighters[user].effAttract >= 0) return;
		int atkGender = 0, oppGender = 0;
		int species = GetMonsterStats(fighters[target].mon, pSpecies);
		if(BaseStats[species].Gender < 0xFF)
			atkGender = ((u8)fighters[user].mon->Personal.Personal > BaseStats[species].Gender) ? 1 : 2;
		species = GetMonsterStats(fighters[user].mon, pSpecies);
		if(BaseStats[species].Gender < 0xFF)
			oppGender = ((u8)fighters[user].mon->Personal.Personal > BaseStats[species].Gender) ? 1 : 2;
		if(atkGender == 0 || oppGender == 0 || atkGender == oppGender) return;
		if(rrand(100) < 30)
		{
			fighters[user].effAttract = target ^ 1;
			btlsayf(BT_XFellInLove, fighters_This(user));
		}
		return;
	}
}

int battle_FindPlayerBattler(int pkmnIndex)
{
	int i;
	for(i=0; i<4; i++)
	{
		if((!battle_IsOpposing(i)) && (fighters[i].pokemonIndex == pkmnIndex))
		{
			return i;
		}
	}
	return -1;
}

void battle_LearnMove(int idxPokemon, int move)
{
/*
 pokemon=@party1[pkmnIndex]
 return if !pokemon
 pkmnname=pokemon.name
 battler=pbFindPlayerBattler(pkmnIndex)
 movename=PokeBattle_Move.getName(move)
 for i in 0..3
  if pokemon.moves[i].id==move
   return
  end
  if pokemon.moves[i].id==0
   pokemon.moves[i]=PBMove.new(move)
   battler.moves[i]=PokeBattle_Move.pbFromPBMove(self,pokemon.moves[i]) if battler
   pbDisplayPaused("#{pkmnname} learned #{movename}!")
   return
  end
 end
 loop do
  pbDisplayPaused("#{pkmnname} wants to learn #{movename}.") #Replaces current/total PP
  pbDisplayPaused("But, #{pkmnname} can't learn more than four moves.")
  if pbDisplayConfirm("Delete a move to make room for #{movename}?")
   pbDisplayPaused("Which move should be forgotten?")
   forgetmove=@scene.pbForgetMove(pokemon)
   if forgetmove >=0
    oldmovename=PokeBattle_Move.getName(pokemon.moves[forgetmove].id)
    pokemon.moves[forgetmove]=PBMove.new(move)#Replaces current/total PP
    battler.moves[forgetmove]=PokeBattle_Move.pbFromPBMove(self,pokemon.moves[forgetmove]) if battler
    pbDisplayPaused("1,  2, and... ... ...")
    pbDisplayPaused("Poof!")
    pbDisplayPaused("#{pkmnname} forgot #{oldmovename}.")
    pbDisplayPaused("And...")
    pbDisplayPaused("#{pkmnname} learned #{movename}!")
    return
   elsif pbDisplayConfirm("Should #{pkmnname} stop learning #{movename}?")
    pbDisplayPaused("#{pkmnname} did not learn #{movename}.")
    return
   end
  elsif pbDisplayConfirm("Should #{pkmnname} stop learning #{movename}?")
   pbDisplayPaused("#{pkmnname} did not learn #{movename}.")
   return
  end
 end
*/
}

void battle_GainEXP()
{
	AGBPrintf("GAINEXP\n");
	//if(!ThisBattle.internalbattle) return;
	int successbegin = true;
	int i,j,partic, expshare;
	for(i = 0; i < 4; i++) //Not ordered by priority
	{
		AGBPrintf("Handling I #%d...\n", i);
		if((!ThisBattle.doublebattle) && (battle_IsDoubleBattler(i)))
		{
			AGBPrintf("Doublebattler\n");
			continue;
		}
		if((battle_IsOpposing(i)) && (fighters[i].mon->Status.CurrentHP == 0))
		{
//			species=@battlers[i].species	//Current species, not original species
			int baseexp = BaseStats[fighters[i].species].ExpYield;
			int level = fighters[i].mon->Status.Level;

			//First count the number of participants
			partic = 0;
			expshare = 0;
			for(j = 0; j < 6; j++)
			{
				if(participants[j] == true) partic++;
			}
			AGBPrintf("Final partic: %d\n",partic);
			//Now calculate EXP for the participants
			if(partic > 0)
			{
				if((ThisBattle.trainer == 0) && (successbegin))
				{
					//scene_WildBattleSuccess();
					successbegin = false;
				}
				for(j = 0; j < GetPartySize(MyParty)+1; j++)
				{
					AGBPrintf("j %d...\n",j);
					int ispartic = false;
					//int haveexpshare = (MyParty[j].item == itemExpShare);
					ispartic = participants[j];

					if(MyParty[j].Status.CurrentHP > 0)
					{
						AGBPrintf("Okay...\n");
						aBaseStat *myBase = (aBaseStat*)&BaseStats[GetMonsterStats(&MyParty[j], pSpecies)];

						int exp = 0;
						//if(haveexpshare)
						//{
						//	exp = ((level*baseexp/7) / 2);
						//	exp = (exp / partic) * ispartic + (exp / expshare) * haveexpshare;
						//} else
						if(ispartic==true)
						{
							exp = ((level*baseexp/7) / partic);
						}
						if(ThisBattle.trainer) exp += (exp/2); //the 1.5 trick again
						if(MyParty[j].Personal.OTID != MyPlayer.trainerid) exp += (exp/2);
						if(GetMonsterStats(&MyParty[j], pHeldItem) == itemLuckyEgg) exp += (exp/2);

						int newexp = GetMonsterStats(&MyParty[j], pExperience) + exp;
						int maxexp = XPRequirements[(myBase->LevelSlope*101)+100];
						if(newexp > maxexp) newexp = maxexp;
						exp = newexp - GetMonsterStats(&MyParty[j], pExperience);
						AGBPrintf("exp %d...\n", exp);
						if(exp > 0)
						{
							if(j == 0)
								MakeEXPBar(&MyParty[j]);
							btlsayf(BT_XGainedXYExpPoints,MyParty[j].Personal.Nickname,
											(MyParty[j].Personal.OTID != MyPlayer.trainerid) ? BattleStrings[BT_ABoosted] : BattleStrings[BT_],
											exp);

							//Gain effort value points
							//TODO	Implement effort values!
							//int totalev=myM->DVHP+myM->DVAttack+myM->DVDefense+myM->DVSpeed+myM->DVSpAttack+myM->DVSpDefense;
/*
							dexdata=File.open("PBS/dexdata.dat")
							dexdata.pos=76*species+23
							for k in 0..5
								evgain=dexdata.fgetb
								if thispoke.item==PBItems::MACHOBRACE
									evgain*=2
								end
								if thispoke.pokerus > 0
									evgain*=2
								end
								if evgain>0
									# Can't exceed overall limit
									if totalev+evgain>510
										evgain=totalev+evgain-510
									end
									# Can't exceed stat limit
									if thispoke.ev[k]+evgain>255
										evgain=thispoke.ev[k]+evgain-255
									end
									# Add EV gain
									thispoke.ev[k]+=evgain
									totalev+=evgain
								end
*/
							int newlevel = monster_GetLevelFromExperience(newexp, myBase->LevelSlope);
							int curlevel = GetMonsterStats(&MyParty[j], pLevel);
							if(newlevel < curlevel)
							{
								btlsays("The new level is less than\nthe monster's current level!");
								return;
							}
							//Find fighter
							//int fighter = battle_FindPlayerBattler(j);
							//Experience GET anim here, with sequential levelups
							//Instead, we do this:
							SetMonsterStats(&MyParty[j], pExperience, newexp);
							if(newlevel > curlevel)
							{
								int OldMax = GetMonsterStats(&MyParty[j], pTotalHP);

								UpdateLiveStats(&MyParty[j]);

								//char genderchar = 0, gendercolor = 0;
								//char foo[12];
								int species = GetMonsterStats(&MyParty[j], pSpecies);
								//if(BaseStats[species].Gender < 0xFF)
								//{
								//	if((u8)MyParty[j].Personal.Personal > BaseStats[species].Gender)
								//	{
								//		genderchar = 0x8A; //Male
								//		gendercolor = 11;
								//	} else
								//	{
								//		genderchar = 0x8B; //Female
								//		gendercolor = 10;
								//	}
								//}

								int doop = GetMonsterStats(&MyParty[j], pCurrentHP) * GetMonsterStats(&MyParty[j], pTotalHP) / OldMax;
								SetMonsterStats(&MyParty[j], pCurrentHP, doop);

								int chp = GetMonsterStats(&MyParty[j], pCurrentHP);
								int thp = GetMonsterStats(&MyParty[j], pTotalHP);

								//DmaArrayCopy(playerwindowTiles, MEM_VRAM_OBJ + 0x1380);
								//sprintf(foo, "%s\a\1%c%c", MyParty[j].Personal.Nickname, gendercolor, genderchar);
								//scene_WriteInBox(0, foo);
								//sprintf(foo, " \x81%d", GetMonsterStats(&MyParty[j], pLevel));
								//scene_WriteInBox(2, foo);
								//sprintf(foo, "%d/%d", chp, thp);
								//scene_WriteInBox(4, foo);
								//MakeHPBar(chp, thp, MEM_VRAM_OBJ + 0x3380, 0);

								btlsays(strBattleLevelUp, MyParty[j].Personal.Nickname, newlevel);

							//Check whether a new move can be taught
								// Get reference/pointer to moveset of the level-upping Pokémon
								const aLearnedMove * moveset = GetRef_PokemonMoveset(species);

								int l;
								for(l = 0; l < 100; l++)
								{
									// If l is at the end of the moveset, break
									if(moveset[l].Move == 0x1FF)
										break;

									if(	(moveset[l].Level <= newlevel) &&
										(moveset[l].Level > curlevel))
									{
										FadeOut();
										scene_BreakBattleScreen();
										int slot = SelectLearnMove(&MyParty[j],moveset[l].Move);
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
										if(slot < 4)
										{
											AGBPrintf("Teaching move %d...\n");
											LearnMove(&MyParty[j], moveset[l].Move, slot);
										}
									}
									// If the Pokémon's level is less than
									// the needed level for the list's next attack, break
									else if(moveset[l].Level > newlevel)
									{
										break;
									}
								}
							// End of "Checking level-up move"

								int evoTarget = CheckEvolution(&MyParty[j], 0, 0);
								if(evoTarget)
								{
									//TODO	Cutscene here
									btlsays("%s is about to evolve into\n%s. Okay?", MyParty[j].Personal.Nickname, PokeNames[evoTarget]);
									if(!btlYesNoLoop())
									{
										int oldspecies = species;
										if(!strcmp(MyParty[j].Personal.Nickname, PokeNames[species]))
										{
											strcpy(MyParty[j].Personal.Nickname,PokeNames[evoTarget]);
										}
										species = evoTarget;
										SetMonsterStats(&MyParty[j], pSpecies, species);
										OldMax = GetMonsterStats(&MyParty[j], pTotalHP);
										UpdateLiveStats(&MyParty[j]);
										chp = GetMonsterStats(&MyParty[j], pCurrentHP) * GetMonsterStats(&MyParty[j], pTotalHP) / OldMax;
										LoadPokemonPic(species,LPP_BACK | (LPP_SHINY*IsShiny(&MyParty[j])),MEM_VRAM_OBJ,pal_obj_bank[0],0);
										sndPlayCry(species, 60);
										btlsays(strBattleEvolved, PokeNames[oldspecies],PokeNames[species]);
									}
								}
							}
						}
					}
				}
				//Now clear the participants array
				//fighters[i].numparts = 0;
				for(j=0; j<6; j++)
				{
					participants[j] = false;
				}
			}
		}
	}
}

int battle_CanChooseNonActive(int index)
{
	int ps = GetPartySize(battle_Party(index));
	int i;
	for(i=0; i <= ps; i++)
	{
		if( battle_CanSwitchLax(index, i, 0) )
			return true;
	}
	return false;
}

void battle_Switch()
{
	int priority[4];
	battle_SortPriorities(priority);

	if(ThisBattle.decision)
	{
		return;
	}
	if(battle_AllFainted(MyParty))
	{
		ThisBattle.decision = 2;
		return;
	}
	if(battle_AllFainted(HisParty))
	{
		ThisBattle.decision = 1;
		return;
	}
	int i;
	for(i=0; i<4; i++)
	{
		if((!ThisBattle.doublebattle) && (battle_IsDoubleBattler(priority[i])))
			continue;
		if(fighters[priority[i]].mon->Status.CurrentHP)
			continue;
		if(battle_IsOpposing(priority[i]))
		{
			int newenemy = scene_ChooseNewEnemy();
			if((!ThisBattle.doublebattle) && (fighters[0].mon->Status.CurrentHP) && (MyPlayer.Options.battlestyle==0))
			{
				btlsays(strBattleAboutToSwitch,HisParty[newenemy].Personal.Nickname);
				if(!btlYesNoLoop())
				{
					int newpoke = scene_Switch(priority[i],1,0);
					if(newpoke != fighters[0].pokemonIndex)
					{
						btlsays(strBattleThatsEnough, fighters[0].mon->Personal.Nickname);
						scene_WithdrawMonster(0);
						battle_SendOut(0,newpoke,SEND_ALL);
						btlsays(strBattleGo, MyParty[newpoke].Personal.Nickname);
						battle_OnActiveOne(priority[i]);
					}
				}
			}
			btlsays(strBattleOpponentSent,HisParty[newenemy].Personal.Nickname);

			scene_WithdrawMonster(1);
			battle_SendOut(1,newenemy,SEND_ALL);
			battle_OnActiveOne(priority[i]);
		}
		else if(ThisBattle.trainer)
		{
			int newpoke = scene_Switch(priority[i],1,0);
			battle_SendOut(0,newpoke,SEND_ALL);
			btlsays(strBattleGo, MyParty[newpoke].Personal.Nickname);
			battle_OnActiveOne(priority[i]);
		}
		else
		{
			int sw = 1;
			if(sw)
			{
				int newpoke = scene_Switch(priority[i],1,0);
				battle_SendOut(0,newpoke,SEND_ALL);
				btlsays(strBattleGo, MyParty[newpoke].Personal.Nickname);
				battle_OnActiveOne(priority[i]);
			}
/*
			switch=false
			if !pbDisplayConfirm("Use next Pokemon?")
				switch=(pbRun(index,true)<=0)
			else
				switch=true
			end
			if switch
				newpoke=pbSwitchPlayer(index,true,false)
				@battlers[index].pbInitialize(@party1[newpoke],newpoke,false);
				pbDisplay("Go! #{@battlers[index].name}!")
				@scene.pbSendOut(index,@party1[newpoke])
				pbOnActiveOne(@battlers[index])
			end
*/
		}
	}
}

int battle_SwitchPlayer(int index, int lax, int canCancel)
{
	return scene_Switch(index, lax, canCancel);
/*
	 if @debug
	  PBDebug.log("[Switching...]")
	  return @scene.pbChooseNewEnemy(index,pbParty(index))
	 else
	  return @scene.pbSwitch(index,lax,canCancel)
	 end
*/
}

int battle_AutoFightMenu(int i)
{
	return false;
}

void battle_CommandPhase()
{
	int i;
	int commandDone, commandEnd;
	int target = 0;

	// Options of battle-menu (
	int cmd = 1, index, pkmn = 0, item = 0, run;

// No clue about functionality and usefulness :(
	for(i=0; i < 4; i++)
	{
		if(battle_CanShowCommands(i))
		{
			choices[i][0] = 0;
			choices[i][1] = 0;
			choices[i][2] = 0;
			choices[i][3] = -1;
		}
	}

	for(i=0; i < 4; i++)
	{
		if(	(!ThisBattle.doublebattle) &&
			(battle_IsDoubleBattler(i)))
			continue;
		if(	(battle_IsOpposing(i)) &&
			(fighters[fighters_Opposing1(i)].effTimeStop))
			continue;
		if(battle_IsOpposing(i))
		{
			if((fighters[i].turncount == 0) && (ThisBattle.roamer))
			{
				run = battle_Run(i,0);
				if(run > 0)
				{
					ThisBattle.decision = 3; //escaped
					commandDone = 1;
					return;
				} else if(run < 0)
				{
					commandDone = 1;
				}
			}
			scene_ChooseEnemyCommand(i);
			battle_RegisterTarget(i,i^1);
		}
		else
		{
			commandDone = 0;
			commandEnd = 0;
			if(battle_CanShowCommands(i))
			{
				// Allow player to choose an action
				while(1)
				{
				/* Player chooses to either:
					// - Choose an attack
					// - Open the bag
					// - Open the Pokémon party or
					// - Get away safely */
					cmd = scene_CommandMenu(i, --cmd);

					if(cmd == COMMAND_FIGHT)
					{
						if(battle_CanShowFightMenu(i))
						{
							if(battle_AutoFightMenu(i))
								commandDone=1;
							while(1)
							{
								// Choose a move
								index = scene_FightMenu(i);

								if(index < 0)
									break;
								if(!battle_RegisterMove(i,index))
									continue;
								if(ThisBattle.doublebattle)
								{
									if(moves[GetMonsterStats(fighters[i].mon, pMove1+index)].target == 0x00) //Single non-user
									{
										//target = @scene.pbChooseTarget(i);
										if(target < 0)
											continue;
										battle_RegisterTarget(i,index);
									}
								}
								else //(ThisBattle.doublebattle)
								{
									if(moves[GetMonsterStats(fighters[i].mon, pMove1+index)].target == 0x00) //Single non-user
									{
										battle_RegisterTarget(i,i^1);
									}
								}
								commandDone = 1;
								break;
							}
						}
						else
						{
							battle_AutoChooseMove(i);
							commandDone = 1;
						}
					}
					else if(cmd == COMMAND_SWITCH)
					{
						//pkmn = scene_Switch(i,0,1);
						pkmn = battle_SwitchPlayer(i,0,1);
						if(pkmn >= 0)
						{
							if(battle_RegisterSwitch(i,pkmn)) commandDone = 1;
						}
						else
							continue;
					}
					else if(cmd == COMMAND_ITEM)
					{
						item = scene_ItemMenu(i);
						if(item)
						{
							battle_RegisterItem(i,item);
							commandDone = 1;
						}
						else
							continue;
					}
					else if(cmd == COMMAND_RUN)
					{
						run = battle_Run(i,0);
						if(run > 0)
						{
							ThisBattle.decision = 3; //escaped
							return;
						}
						else if(run < 0)
						{
							commandDone = 1;
						}
					}
					if(commandDone)
						break;
				} //command loop
			} //CanShowCommands
		}
	}
}

int battle_ChoseMove(int i, int moveid)
{
	if(fighters[i].mon->Status.CurrentHP <= 0)
		return false;
	if((choices[i][0] == CHOICE_MOVE) && (choices[i][1] >= 0))
	{
		return ((choices[i][0]==CHOICE_MOVE) && (choices[i][2]==(int)&moves[moveid]));
	}
	return false;
}

void battle_AttackPhase()
{
	int i,j, index;
	for(i=0; i<4; i++) //in order from own first, opposing first, own second, opposing second
	{
		if(battle_ChoseMove(i,moveFocusPunch))
		{
			if((fighters[i].mon->Status.AilmentSleep == 0) && ((fighters[i].ability != abilityTruant) || (!fighters[i].effTruant)))
				btlsayf(BT_XIsTighteningItsFocus, fighters_This(i));
		}
	}
	for(i=0; i<4; i++)
	{
		if(fighters[i].mon->Status.CurrentHP)
			fighters[i].turncount++;
	}
	for(i=0; i<4; i++)
	{
		if(!battle_ChoseMove(i,moveRage))
			fighters[i].effRage = 0;
	}

	ThisBattle.switching = 1;
	for(i=0; i<4; i++)
	{
		if(choices[i][0]==CHOICE_SWITCH)
		{
			index = choices[i][1]; //party position of Pokemon to switch to
			if(battle_IsOpposing(i))
			{
				btlsays(strBattleOpponentWithdrew, fighters_This(i));
				scene_WithdrawMonster(1);
			} else
			{
				btlsays(strBattleOkayEnough, fighters_This(i));
				scene_WithdrawMonster(0);
			}
			for(j = 3; j >= 0; j--)
			{
				if(!fighters_IsOpposing(i,j))
					continue;
				//if Pursuit and this target (i) was chosen
				if((battle_ChoseMove(j,movePursuit)) && (choices[j][3]==i))
				{
					if( (fighters[j].mon->Status.AilmentSleep) &&
						(fighters[j].mon->Status.AilmentFrozen) &&
						((fighters[j].ability = abilityTruant) || (fighters[j].effTruant == 0)))
					{
						fighters_UseMove(j);
						fighters[i].effPursuit = 1;
						//UseMove calls GainEXP as appropriate.
						ThisBattle.switching = 0;
						if(ThisBattle.decision > 0) return;
					}
				}
				if(fighters[i].mon->Status.CurrentHP <= 0)
					break;
			}
			if(battle_IsOpposing(i))
			{
				btlsays(strBattleOpponentSent,HisParty[index].Personal.Nickname);
				fighters_Initialize(i,0);
				battle_SendOut(1,index,SEND_ALL);
			}
			else
			{
				btlsays(strBattleGo, MyParty[index].Personal.Nickname);
				fighters_Initialize(i,0);
				battle_SendOut(0,index,SEND_ALL);
			}
			if(!(battle_OnActiveOne(i)))
			{
				if(!ThisBattle.doublebattle)
				{
					ThisBattle.switching = 0;
					return;
				}
			}
		}
	}
	ThisBattle.usepriority = 0;
	battle_SortPriorities(priority);
	for(i=0; i<4; i++)
	{
		if(choices[priority[i]][0] == 1)
		{
			fighters_ProcessTurn(priority[i]);
		}
		if(ThisBattle.decision)
			return;
	}
}

void battle_EndOfRoundPhase()
{
	//TODO	Rewrite this from UPC
	int i;
	for(i = 0; i < 4; i++)
	{
		fighters[i].effProtect = 0;
		fighters[i].effEndure = 0;
		if(fighters[i].effHyperBeam) fighters[i].effHyperBeam--;
	}
	ThisBattle.usepriority = 0;
	battle_SortPriorities(priority);

	//Reflect
	//Light Screen
	//Mist
	//Safeguard
	//Wish

	if(ThisBattle.weather == WEATHER_RAINDANCE)
	{
		if(ThisBattle.weatherduration) ThisBattle.weatherduration--;
		if(ThisBattle.weatherduration==0)
		{
			btlsayf(BT_TheRainStopped);
			ThisBattle.weather = 0;
		} else
		{
			btlsayf(BT_RainContinuesToFall);
		}
	}
	if(ThisBattle.weather == WEATHER_SANDSTORM)
	{
		if(ThisBattle.weatherduration) ThisBattle.weatherduration--;
		if(ThisBattle.weatherduration==0)
		{
			btlsayf(BT_TheSandstormSubsided);
			ThisBattle.weather = 0;
		} else
		{
			btlsayf(BT_TheSandstormRages);
			for(i = 0; i < 4; i++)
			{
				if(fighters[priority[i]].mon->Status.CurrentHP <= 0) continue;
				if((fighters[priority[i]].ability != abilitySandVeil) &&
					 (fighters_HasType(priority[i], tpGround)) &&
					 (fighters_HasType(priority[i], tpRock)) &&
					 (fighters_HasType(priority[i], tpSteel)) &&
					 (fighters[priority[i]].effTwoTurnAttack != moveDig) &&
					 (fighters[priority[i]].effTwoTurnAttack != moveDive))
				{
					btlsayf(BT_XIsBuffetedByTheSandstorm, fighters_This(priority[i]));
					fighters_DrainHP(priority[i],fighters[priority[i]].mon->Status.TotalHP / 16);
					if(fighters[priority[i]].mon->Status.CurrentHP <= 0)
					{
						if(!fighters_Faint(priority[i])) return;
					}
				}
			}
		}
	}
	if(ThisBattle.weather == WEATHER_SUNNYDAY)
	{
		if(ThisBattle.weatherduration) ThisBattle.weatherduration--;
		if(ThisBattle.weatherduration==0)
		{
			btlsayf(BT_TheSunlightFaded);
			ThisBattle.weather = 0;
		} else
		{
			btlsayf(BT_TheSunlightIsStrong);
		}
	}
	//Hail

	for(i = 0; i < 4; i++)
	{
		//Ingrain
		//Rain Dish
		//Speed Boost
		//Truant
		//Shed Skin

		fighters_BerryCureCheck(priority[i], true);

		if(fighters[priority[i]].effLeechSeed)
		{
			int recipient = fighters[priority[i]].effLeechSeed;
			if(fighters[recipient].mon->Status.CurrentHP)
			{
				int hploss = fighters[recipient].mon->Status.TotalHP / 8;
				fighters_DrainHP(priority[i],hploss);
				if(fighters[priority[i]].ability == abilityLiquidOoze)
				{
					fighters_DrainHP(recipient,hploss);
					btlsayf(BT_ItSuckedUpTheLiquidOoze);
				} else
				{
					fighters_RestoreHP(recipient,hploss);
					btlsayf(BT_XsHealthIsSappedByLeechSeed,fighters_This(priority[i]));
				}
				if(fighters[priority[i]].mon->Status.CurrentHP <= 0) fighters_Faint(priority[i]);
				if(fighters[recipient].mon->Status.CurrentHP <= 0) fighters_Faint(recipient);
			}
		}
		if(ThisBattle.decision) return;
		if(fighters[priority[i]].mon->Status.CurrentHP <= 0) continue;

		//Poison/Toxic/Burn
		if(fighters[priority[i]].mon->Status.AilmentPoison)
		{
			btlsayf(BT_XIsHurtByPoison,fighters_This(priority[i]));
			if(fighters[priority[i]].mon->Status.AilmentBadPoison == 0)
			{
				fighters_DrainHP(priority[i],fighters[priority[i]].mon->Status.TotalHP/8);
			} else
			{
				fighters[priority[i]].effToxic++;
				int toxicdmg = fighters[priority[i]].mon->Status.TotalHP * fighters[priority[i]].effToxic / 16;
				if(toxicdmg > fighters[priority[i]].mon->Status.CurrentHP)
				{
					toxicdmg = fighters[priority[i]].mon->Status.CurrentHP;
				}
				fighters_DrainHP(priority[i], toxicdmg);
			}
		}
		if(fighters[priority[i]].mon->Status.CurrentHP <= 0) fighters_Faint(priority[i]);

		//Nightmare
		//Curse
		//Multi-turn moves
		//Uproar
		//Outrage
		if(fighters[priority[i]].effDisableTimer)
		{
			fighters[priority[i]].effDisableTimer--;
			if(fighters[priority[i]].effDisableTimer == 0)
			{
				btlsayf(BT_XIsDisabledNoMore,fighters_This(priority[i]));
			}
		}
		if(fighters[priority[i]].effEncore)
		{
			fighters[priority[i]].effEncore--;
			if(fighters[priority[i]].effEncore == 0)
			{
				btlsayf(BT_XsEncoreEnded,fighters_This(priority[i]));
			}
		}
		//Taunt/Lock-on/Mindreader
		//Yawn

		fighters_BerryCureCheck(priority[i], false);
	}
	battle_GainEXP();
	battle_Switch();
}

//------------------------
// MISC THINGS
//------------------------
#include <stdarg.h>
void btlsayf(int msgindex, ...)
{
	va_list args;
	char buf[256];

	va_start(args, msgindex);
	vsprintf(buf, BattleStrings[msgindex], args);
	va_end(args);

	strcat(buf,"\a\x8\x40\1"); //always autoclose in battle

	SetText(TextBuffer,buf);
	SM_Dialoguebox.state = 0;
	SM_Dialoguebox.style = 99;
	while(1)
	{
		DoVBlank();
		KeyRead();
		DialogueBox();
		btlWindowShifts[2] = 0;
		if(SM_Dialoguebox.state == 7)
			break;
	}
}

void btlsays(const char *fmt, ...)
{
	va_list args;
	char buf[256];

	va_start(args, fmt);
	vsprintf(buf, fmt, args);
	va_end(args);

	if(MyPlayer.Options.battleskip) strcat(buf,"\a\x8\x40\1"); //autoclose in battle

	SetText(TextBuffer,buf);
	SM_Dialoguebox.state = 0;
	SM_Dialoguebox.style = 99;
	while(1)
	{
		DoVBlank();
		KeyRead();
		DialogueBox();
		btlWindowShifts[2] = 0;
		if(SM_Dialoguebox.state == 7)
			break;
	}
}


void btlDrawFrame(int x, int w, int y, int h)
{
	u16 *BG0 = ((u16*)0x600C000);
	int a, b;
	for(a = x+1; a < x+w-1; a++)
	{
		BG0[(y*32)+a] = 0xF013;
		BG0[((y+h-1)*32)+a] = 0xF019;
		for(b=y+1; b < y+h-1; b++)
		{
			BG0[(b*32)+a] = 0xF016;
		}
	}
	for(a = y+1; a < y+h-1; a++)
	{
		BG0[(a*32)+x] = 0xF015;
		BG0[(a*32)+x+w-1] = 0xF017;
	}
	BG0[(y*32)+x] = 0xF012;
	BG0[(y*32)+x+w-1] = 0xF014;
	BG0[((y+h-1)*32)+x] = 0xF018;
	BG0[((y+h-1)*32)+x+w-1] = 0xF01A;
}
void btlClearFrame(int x, int w, int y, int h)
{
	u16 *BG0 = ((u16*)0x600C000);
	int a, b;
	for(a=x; a<x+w; a++)
		for(b=y; b<y+h; b++)
			BG0[(b*32)+a] = 0;
}
int btlMultipleChoice(int left, int top, int width, int choices, int bcancel) //CHOICELIST choices)
{
	int i,j,k,l,c=0;
	extern const char * Choices[];
	AnOptionsSet * set = (AnOptionsSet*)&ChoiceSets[choices];
	btlDrawFrame(left, width, top, (set->NumChoices*2)+2);
	j = 9;
	k = 386;
	l = 18;

	for(i=0; i < set->NumChoices; i++)
	{
		vwClearLine(1, l);
		vwWriteG(2, j, (char*)Choices[set->Options[i]]); //choices.choices[i]);

		scene_SetLine(left+2, width-4, top+1+(i*2), k, 15);
		l +=  4;
		j +=  2;
		k += 64;
	}

	vwWriteG(0,9,strArrow);
	scene_SetLine(left+1,1,top+1,384,15);

	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & A_BUTTON)
			break;
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			scene_SetLine(left+1,1,top+1+(c<<1),448,15);
			c = wrap(c + key_tri_vert(), 0, set->NumChoices);
			scene_SetLine(left+1, 1, top+1+(c<<1), 384, 15);
			sndCursor();
		}
	}
	btlClearFrame(left, width, top, (set->NumChoices*2)+2);
	return c;
}

extern void CrossWipe1();
extern void RepairMap();
extern void HealParty();
extern const aSpawnPoint WhiteoutMarkers[];
extern unsigned char gMapOfsX, gMapOfsY;
unsigned short LastKnownSafePlace;
void WhiteOut()
{
	FadeOut();
	MyPlayer.currentMap = WhiteoutMarkers[LastKnownSafePlace].map;
	MyPlayer.currentMapX = WhiteoutMarkers[LastKnownSafePlace].x;
	MyPlayer.currentMapY = WhiteoutMarkers[LastKnownSafePlace].y;
	MyPlayer.currentFacing = 0;
	gCam.mapX0 = 0; gCam.mapY0 = 0;
	mapLoad(MyPlayer.currentMap);
	HealParty();
	Actors[0].mx = MyPlayer.currentMapX;
	Actors[0].my = MyPlayer.currentMapY;
	Actors[0].direction = 0;
	RepairMap();
}

void MoveRoamer(int i)
{
	#define routemin 11
	#define routemax 19
	//edit those to match your route indices
	int n = rrand(routemax-routemin) + routemin;
	Roamers[i].map = n;
	//aMapHeader *mh = (aMapHeader*)MapHeaderList[Roamers[i].map];
	//AGBPrintf("%s fled to %s! (%d)",GetPokemonName(Roamers[i].species), MapNames[mh->NameIndex], Roamers[i].map);
}

void InitializeWildBattle(int encat)
{
	int i = 0, j = 0, tod;
	if(currentMonsters[encat] == 0)
	{
		AGBPrintf("Wild battle triggered, but no encounter data for this map.\n");
		return;
	}

	if(encat == 1 || encat == 2)
		j = 2;

	AGBPrintf("---------------------\nWILD BATTLE TRIGGERED\n---------------------\n");

	tod = GetTimeOfDay();

	for(i = 0; i < 16; i++)
	{
		if(Roamers[i].map)
		{ //We have an active roamer…
			if(Roamers[i].map == MyPlayer.currentMap)
			{ //…and it's right here.
				AGBPrintf("Roaming Pokémon %s is right here!\n",GetPokemonName(Roamers[i].species));
				CreateMonster(&HisParty[0],Roamers[i].species,Roamers[i].level);
				HisParty[0].Status.CurrentHP = Roamers[i].hp;
				sndPlaySound(2,SOUND_NORESTART);
				CrossWipe1();
				if(Battle(2,0,0,0)) //true = lose
				{
					WhiteOut();
					MoveRoamer(i);
					return;
				} else
				{
					Roamers[i].map = 0;
				}
				RepairMap();
				AGBPrintf("Ummm...\n");
				sndFadeToSound(currentMapHeader->Music);
				MoveRoamer(i);
				return;
			}
		}
	}

	if(currentMonsters[encat]->mon[tod][0].species == 0)
	{
		AGBPrintf("Nothing for this time of day. Hoping for the best on afternoon...\n");
		tod = 0;
	}

	AGBPrintf("Picking monster at random...\n");
	i = rrand(12) >> 1;
	while(currentMonsters[encat]->mon[tod][i].species == 0)
		i = rrand(12) >> 1;

	int species = currentMonsters[encat]->mon[tod][i].species;
	int level = currentMonsters[encat]->mon[tod][i].levelmin;

	AGBPrintf("Chose index %d: %s of lv.%d\n", i, GetPokemonName(species), level);

	//sayf(SYSTEM,"A wild %s appeared.",GetPokemonName(currentMonsters->mon[tod][i].species));
	CreateMonster(&HisParty[0],species,level);

	sndPlaySound(6,SOUND_NORESTART);
	CrossWipe1();
	int result = Battle(0,0,j,0);
	if(result == 1) //lose
	{
		WhiteOut();
		return;
	}
	RepairMap();
	AGBPrintf("Ummm...\n");
	sndFadeToSound(currentMapHeader->Music);

	//CreateMonster(&HisParty[0],currentMonsters->mon[0][i].species,currentMonsters->mon[0][i].levelmin);
	//fight here
}

void ExpandTrainerTeam(aTrainer* who)
{
	u8 i;
	for(i = 0; i < who->partysize; i++)
	{
		aTrainerMonster *team = (aTrainerMonster*)&who->pack[i];
		AGBPrintf("ExpandTrainerTeam: level %d %s...\n", team->level, PokeNames[team->species]);
		CreateMonster(&HisParty[i],team->species,team->level);
	}
}

void MakeHPBar(int value, int max, int target, int nolabel)
{
	u32 percent = value * 48 / max;
	u32 fullparts = percent / 8;
	u32 subparts = percent % 8;
	u32 coloroffset = 0;
	u32 i;

	if(percent < 32) coloroffset += 128;
	if(percent < 16) coloroffset += 128;

	//DmaCopy(hpbarTiles + 400, target, 64); //"HP" part

	for(i=0; i<6; i++)
		DmaCopy(hpbarTiles, target + (i*32), 32); //empty bar

	if(fullparts)
		for(i=0; i<fullparts; i++)
			DmaCopy(hpbarTiles + 128 + coloroffset, target + (i*32), 32);

	if(subparts)
		DmaCopy(hpbarTiles + (subparts*16) + coloroffset, target + (fullparts*32), 32);
}

void MakeEXPBar(aPokemon * mon)
{
	u32 value = GetMonsterStats(mon, pExperience);
	u32 max = XPRequirements[(BaseStats[GetMonsterStats(mon, pSpecies)].LevelSlope * 101) +
																			GetMonsterStats(mon, pLevel) + 1];
	u32 percent = value * 48 / max;
	u32 fullparts = percent / 8;
	u32 subparts = percent % 8;
	const u32 coloroffset = 400;
	u32 i;

	for(i=0; i<6; i++)
		DmaCopy(hpbarTiles + coloroffset, 0x6006A40 + (i*32), 32); //empty bar

	if(fullparts)
		for(i=0; i<fullparts; i++)
			DmaCopy(hpbarTiles + coloroffset + 128, 0x6006A40 + (i*32), 32);

	if(subparts)
		DmaCopy(hpbarTiles + (subparts*16) + coloroffset, 0x6006A40 + (fullparts*32), 32);
}

int monster_GetLevelFromExperience(int exp, int rate)
{
	int index = rate * 101;
	int maxexp = XPRequirements[index+100];
	if(exp>maxexp) exp=maxexp;
	int i = 0, j;
	for(j = 0; j < 101; j++)
	{
		if(exp == XPRequirements[index+i]) return i;
		if(exp < XPRequirements[index+i]) return i-1;
		i++;
	}
	return 100;
}





