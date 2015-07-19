//======================================================================
//
//	OpenPoké battle system, specific move effects.
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "../openpoke.h"
#include "btlmessages.h"

//Determines the basic amount of damage done by an attack, because some moves don't follow the rules.
int __move_BaseDamage(int mid, int basedmg, int attacker, int opponent)
{
	switch(moves[mid].effect)
	{
		case 0x00:
		{
			if(mid == moveSurf && fighters[opponent].effDive)
				return basedmg * 2;

			break;
		}
		case 0x63:
		{
			int n = fighters[attacker].mon->Status.CurrentHP * 48 / fighters[attacker].mon->Status.TotalHP;

			basedmg = 20;

			if(n < 33) basedmg = 40;
			if(n < 17) basedmg = 80;
			if(n < 10) basedmg = 100;
			if(n <  5) basedmg = 150;
			if(n <  2) basedmg = 200;

			break;
		}
		case 0x68:
		{
			int damage = fighters[opponent].damagestate.calcdamage; //calcbasedmg;
			fighters[opponent].damagestate.calcdamage += basedmg; //calcbasedmg += basedmg;

			return damage;
		}
		case 0x75:
		{
			int shift = (4 - fighters[attacker].effRollout); //from 0 to 4, 0 is the most powerful
			if(fighters[attacker].effDefenseCurl)
				shift++;
			basedmg <<= shift;

			break;
		}
		case 0x77:
		{
			basedmg <<= (fighters[attacker].effFuryCutter - 1); //Fury Cutter can be 1 to 5.

			break;
		}
		case 0x79:
		{
			basedmg = GetMonsterStats(fighters[attacker].mon, pTameness) * 10 / 25;

			break;
		}
		case 0x7A:
		{
			//TODO
			//basedmg = calcbasdmg

			break;
		}
		case 0x7B:
		{
			basedmg = (255 - GetMonsterStats(fighters[attacker].mon, pTameness) ) * 10 / 25;

			break;
		}
		case 0x7E:
		{
			if(fighters[opponent].effTwoTurnAttack == moveDig)
				return basedmg * 2;

			break;
		}
		case 0x87:
		{
			int base=0;

			base |= (GetMonsterStats(fighters[attacker].mon, pDVHP) & 2) >> 1;
			base |= (GetMonsterStats(fighters[attacker].mon, pDVAttack) & 2);
			base |= (GetMonsterStats(fighters[attacker].mon, pDVDefense) & 2) << 1;
			base |= (GetMonsterStats(fighters[attacker].mon, pDVSpeed) & 2) << 2;
			base |= (GetMonsterStats(fighters[attacker].mon, pDVSPAtk) & 2) << 3;
			base |= (GetMonsterStats(fighters[attacker].mon, pDVSPDef) & 2) << 4;
			base = (base*40/64)+30;

			return base;
		}
		case 0x92:
		case 0x95:
		case 0x98:
		{
			if(	fighters[opponent].effTwoTurnAttack == moveFly ||
					fighters[opponent].effTwoTurnAttack == moveBounce)
				return basedmg * 2;

			break;
		}
		case 0x93:
		{
			if(fighters[opponent].effTwoTurnAttack == moveDig)
				return basedmg * 2;

			break;
		}
		case 0xBE:
		{
			//TODO
			//basedmg = calcbasdmg

			break;
		}
		case 0xC4:
		{
			int species = GetMonsterStats(fighters[attacker].mon, pSpecies);

			basedmg = 20;

			if(DexEntries[species].weight >= 100)  basedmg = 40;
			if(DexEntries[species].weight >= 250)  basedmg = 60;
			if(DexEntries[species].weight >= 500)  basedmg = 80;
			if(DexEntries[species].weight >= 1000) basedmg = 100;
			if(DexEntries[species].weight >= 2000) basedmg = 120;

			break;
		}
	}
	return basedmg;
}

//Determines any additional effect. These -might- happen, by chance.
int __move_AdditionalEffect(int mid, int attacker, int opponent)
{
	switch(moves[mid].effect)
	{
		case 0x02:
		case 0x4D:
		case 0xD1:
		{
			if(effect_CanPoison(opponent,1))
			{
				fighters[opponent].mon->Status.AilmentPoison = 1;
				fighters[opponent].mon->Status.AilmentBadPoison = 0;
				btlsayf(BT_XWasPoisoned,fighters_This(opponent));
				return 1;
			}

			return 0;
		}
		case 0x04:
		case 0x7D:
		case 0xC8:
		{
			if(effect_CanBurn(opponent,0))
			{
				fighters[opponent].mon->Status.AilmentBurned = 1;
				btlsayf(BT_XWasBurned,fighters_This(opponent));
				return 1;
			}

			return 0;
		}
		case 0x05:
		{
			if(effect_CanFreeze(opponent,0));
			{
				fighters[opponent].mon->Status.AilmentFrozen = 1;
				btlsayf(BT_XWasFrozenSolid,fighters_This(opponent));
				return 1;
			}

			return 0;
		}
		case 0x06:
		case 0x98:
		case 0x9B:
		{
			if(effect_CanParalyze(opponent,0))
			{
				fighters[opponent].mon->Status.AilmentParalysis = 1;
				btlsayf(BT_XIsParalyzedItMayBeUnableToMove, fighters_This(opponent));

				return 1;
			}

			return 0;
		}
		case 0x1F:
		{
			if(fighters[opponent].ability != abilityInnerFocus)
				fighters[opponent].effFlinch = 1;

			break;
		}
		case 0x24:
		{
			int rnd = rrand(3);
			switch(rnd)
			{
				case 0: __move_AdditionalEffect(moveFirePunch,attacker,opponent); break;
				case 1: __move_AdditionalEffect(moveIcePunch,attacker,opponent); break;
				case 2: __move_AdditionalEffect(moveThunderPunch,attacker,opponent); break;
			}

			break;
		}
		case 0x44:
		{
			return effect_ReduceStat(opponent, 0, 1, 0);
		}
		case 0x45:
		{
			return effect_ReduceStat(opponent, 1, 1, 0);
		}
		case 0x46:
		{
			return effect_ReduceStat(opponent, 2, 1, 0);
		}
		case 0x47:
		{
			return effect_ReduceStat(opponent, 3, 1, 0);
		}
		case 0x48:
		{
			return effect_ReduceStat(opponent, 4, 1, 0);
		}
		case 0x49:
		{
			return effect_ReduceStat(opponent, 5, 1, 0);
		}
		case 0x4B:
		case 0x5C:
		case 0x92:
		case 0x96:
		{
			if(fighters[opponent].ability != abilityInnerFocus)
				fighters[opponent].effFlinch = 1;

			break;
		}
		case 0x4C:
		{
			if(effect_CanConfuse(opponent,1));
			{
				fighters[opponent].effConfusion = 2+rrand(4);
				btlsayf(BT_XBecameConfused, fighters_This(opponent));
				return 1;
			}

			return 0;
		}
		case 0x8A:
		{
			if(fighters[attacker].stageDefense < 6)
			{
				fighters[attacker].stageDefense++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Rose]);
			}

			return 1;
		}
		case 0x8B:
		{
			if(fighters[attacker].stageAttack < 6)
			{
				fighters[attacker].stageAttack++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_ATTACK], BattleStrings[BT_Rose]);
			}

			return 1;
		}
		case 0x8C:
		{
			if(fighters[attacker].stageAttack < 6)
			{
				fighters[attacker].stageAttack++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_ATTACK], BattleStrings[BT_Rose]);
			}
			if(fighters[attacker].stageDefense < 6)
			{
				fighters[attacker].stageDefense++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Rose]);
			}
			if(fighters[attacker].stageSpeed < 6)
			{
				fighters[attacker].stageSpeed++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPEED], BattleStrings[BT_Rose]);
			}
			if(fighters[attacker].stageSpAtk < 6)
			{
				fighters[attacker].stageSpAtk++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPATK], BattleStrings[BT_Rose]);
			}
			if(fighters[attacker].stageSpDef < 6)
			{
				fighters[attacker].stageSpDef++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPDEF], BattleStrings[BT_Rose]);
			}

			return 1;
		}
		case 0x9E:
		{
			if(fighters[opponent].ability != abilityInnerFocus)
			{
				fighters[opponent].effFlinch = 1;
			}
			else
			{
				btlsayf(BT_XsXPreventsFlinching, fighters_This(opponent), Abilities[fighters[opponent].ability]);
				return 0;
			}

			break;
		}
		case 0xC5:
		{
			switch(ThisBattle.environment)
			{
				case BTLENV_NONE:
				{
					if(!effect_CanParalyze(opponent,0))
						return 0;

					fighters[opponent].mon->Status.AilmentParalysis = 1;
					btlsayf(BT_XIsParalyzedItMayBeUnableToMove, fighters_This(opponent));

					return 1;
				}
				case BTLENV_GRASS:
				{
					if(!effect_CanPoison(opponent,0))
						return 0;

					fighters[opponent].mon->Status.AilmentPoison = 1;
					btlsayf(BT_XWasPoisoned, fighters_This(opponent));

					return 1;
				}
				case BTLENV_TALLGRASS:
				{
					if(!effect_CanSleep(opponent,0,1))
						return 0;

					effect_Sleep(opponent,-1);
					btlsayf(BT_XWentToSleep, fighters_This(opponent));

					return 1;
				}
				case BTLENV_MOVINGWATER:
				{
					if(effect_TooLow(opponent, STAT_ATTACK))
						return 0;

					fighters[opponent].stageAttack--;
					btlsayf(BT_XsXX,fighters_This(opponent), BattleStatNames[STAT_ATTACK], BattleStrings[BT_Fell]);

					return 1;
				}
				case BTLENV_STILLWATER:
				{
					if(effect_TooLow(opponent, STAT_SPEED))
						return 0;

					fighters[opponent].stageSpeed--;
					btlsayf(BT_XsXX,fighters_This(opponent), BattleStatNames[STAT_SPEED], BattleStrings[BT_Fell]);

					return 1;
				}
				case BTLENV_UNDERWATER:
				{
					if(effect_TooLow(opponent, STAT_DEFENSE))
						return 0;

					fighters[opponent].stageDefense--;
					btlsayf(BT_XsXX,fighters_This(opponent), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Fell]);

					return 1;
				}
				case BTLENV_ROCK:
				{
					if(!effect_CanConfuse(opponent,0))
						return 0;

					fighters[opponent].effConfusion = 2 + rrand(4);
					btlsayf(BT_XBecameConfused, fighters_This(opponent));

					return 1;
				}
				case BTLENV_CAVE:
				{
					if(fighters[opponent].ability != abilityInnerFocus)
						fighters[opponent].effFlinch = 1;
				}
				case BTLENV_SAND:
				{
					if(effect_TooLow(opponent, STAT_ACCURACY))
						return 0;

					fighters[opponent].stageAccuracy--;
					btlsayf(BT_XsXX,fighters_This(opponent), BattleStatNames[STAT_ACCURACY], BattleStrings[BT_Fell]);

					return 1;
				}
			}
			break;
		}
		case 0xCA:
		{
			if(effect_CanPoison(opponent,1))
			{
				fighters[opponent].mon->Status.AilmentPoison = 1;
				fighters[opponent].mon->Status.AilmentBadPoison = 1;
				fighters[opponent].effToxic = 0;
				btlsayf(BT_XIsBadlyPoisoned,fighters_This(opponent));
				return 1;
			}

			return 0;
		}
	}
	return 0;
}

//These determine the effect of the attack itself. It's the biggest of this file.
int __move_Effect(int mid, int attacker, int opponent)
{
	char sharply[126];

	switch(moves[mid].effect)
	{
		case 0x01:
		{
			if(effect_CanSleep(opponent,1,0))
			{
				effect_Sleep(opponent,-1);
				btlsayf(BT_XWentToSleep, fighters_This(opponent));
				return 0;
			}

			return -1;
		}
		case 0x03:
		{
			int damagegiven = __move_Effect(movePound,attacker,opponent);
			if(damagegiven)
			{
				if(fighters[opponent].ability == abilityLiquidOoze)
				{
					fighters_DrainHP(attacker, damagegiven / 2);
					btlsayf(BT_ItSuckedUpTheLiquidOoze);
				}
				else
				{
					fighters_RestoreHP(attacker, damagegiven / 2);
					btlsayf(BT_XHadItsEnergyDrained,fighters_This(opponent));
				}
				return 0;
			}

			return -1;
		}
		case 0x08:
		{
			int damagegiven = __move_Effect(movePound,attacker,opponent);
			if(damagegiven)
			{
				fighters_RestoreHP(attacker, damagegiven / 2);
				btlsayf(BT_XsDreamWasEaten,fighters_This(opponent));
				return 0;
			}

			return -1;
		}
		case 0x09:
		{
			if(fighters[attacker].effMirrorMove <= 0)
			{
				btlsayf(BT_TheMirrorMoveFailed);
				return -1;
			}
			fighters_UseMoveSimple(attacker, fighters[attacker].effMirrorMove);

			return 0;
		}
		case 0x0A:
		{
			if(fighters[attacker].stageAttack == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_ATTACK]);
				return -1;
			}
			else
			{
				fighters[attacker].stageAttack++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_ATTACK], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0x0B:
		{
			if(fighters[attacker].stageDefense == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_DEFENSE]);
				return -1;
			}
			else
			{
				fighters[attacker].stageDefense++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0x0D:
		{
			if(fighters[attacker].stageSpAtk == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_SPATK]);
				return -1;
			}
			else
			{
				fighters[attacker].stageSpAtk++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPATK], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0x10:
		{
			if(fighters[attacker].stageEvasiveness == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_EVASIVENESS]);
				return -1;
			}
			else
			{
				fighters[attacker].stageEvasiveness++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_EVASIVENESS], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0x12:
		{
			return effect_ReduceStat(opponent, 0, 1, 1);
		}
		case 0x13:
		{
			return effect_ReduceStat(opponent, 1, 1, 1);
		}
		case 0x14:
		{
			return effect_ReduceStat(opponent, 2, 1, 1);
		}
		case 0x17:
		{
			return effect_ReduceStat(opponent, 5, 1, 1);
		}
		case 0x18:
		{
			return effect_ReduceStat(opponent, 6, 1, 1);
		}
		case 0x19:
		{
			int i;
			for(i=0; i<4; i++)
			{
				fighters[i].stageAttack = 0;
				fighters[i].stageDefense = 0;
				fighters[i].stageSpeed = 0;
				fighters[i].stageSpAtk = 0;
				fighters[i].stageSpDef = 0;
				fighters[i].stageAccuracy = 0;
				fighters[i].stageEvasiveness = 0;
			}
			btlsayf(BT_AllStatChangesWereEliminated);

			return 1;
		}
		case 0x1A:
		{
			if(fighters[attacker].effBideDamage == 0 || !opponent)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			int ret = move_EffectFixedDamage(mid, fighters[attacker].effBideDamage * 2, attacker, opponent);
			fighters[attacker].effBideDamage = 0;

			return ret;
		}
		case 0x1B:
		{
			int dmg = __move_Effect(movePound,attacker,opponent);
			if(dmg && fighters[attacker].effOutrage == 0 && fighters[attacker].mon->Status.AilmentSleep==0)
			{
				fighters[attacker].effOutrage = 2 + rrand(2);
				fighters[attacker].currentMove = mid;
			}
			else if(move_TypeModifier(mid, moves[mid].type,attacker) == 0)
			{
				//Cancel effect if attack is ineffective
				fighters[attacker].effOutrage = 0;
			}

			return 0;
		}
		case 0x1C:
		{
			if(fighters[opponent].ability == abilitySuctionCups)
			{
				btlsayf(BT_XAnchorsItselfWithX, fighters_This(opponent), Abilities[fighters[opponent].ability]);
				return -1;
			}

			if(fighters[opponent].effIngrain)
			{
				btlsayf(BT_XPlantedItsRoots, fighters_This(opponent));
				return -1;
			}

			if(ThisBattle.trainer == 0)
			{
				int x = rrand(256);
				int varA = ((x * fighters[attacker].mon->Status.Level + fighters[opponent].mon->Status.Level) / 256) + 1;
				int varB = (fighters[opponent].mon->Status.Level / 4);
				if(varA<=varB)
				{
					btlsayf(BT_ButItFailed);
					return -1;
				}
				ThisBattle.decision = 3; //escaped
				return 0;
			}
			else
			{
				//TODO	Handle trainer battle here.
				//Should enumerate the switchable opponent monsters and pick one.
			}
		}
		case 0x1E:
		{
			//TODO	Conversion effect (0x1E)
			btlsayf(BT_ButItFailed);
			return -1;
		}
		case 0x20:
		{
			int hpgain = fighters[attacker].mon->Status.TotalHP / 2;
			if(fighters[attacker].mon->Status.CurrentHP == fighters[attacker].mon->Status.TotalHP)
			{
				btlsayf(BT_XsHPIsFull, fighters_This(attacker));
				return -1;
			}
			else
			{
				btlsayf(BT_XRegainedHealth, fighters_This(attacker));
				fighters_RestoreHP(attacker, hpgain);
				return 0;
			}
		}
		case 0x21:
		{
			if(effect_CanPoison(opponent,1))
			{
				fighters[opponent].mon->Status.AilmentPoison = 1;
				fighters[opponent].mon->Status.AilmentBadPoison = 1;
				fighters[opponent].effToxic = 0;
				btlsayf(BT_XIsBadlyPoisoned,fighters_This(opponent));
				return 0;
			}

			return 0;
		}
		case 0x22:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			if(fighters[opponent].damagestate.calcdamage > 0 && !fighters[opponent].damagestate.substitute)
			{
				if(!battle_IsOpposing(attacker))
				{
					ThisBattle.cashwon += 5 * fighters[attacker].mon->Status.Level;
					if(ThisBattle.cashwon > 999999) ThisBattle.cashwon = 999999;
				}
				btlsayf(BT_CoinsScatteredEverywhere);
			}

			return ret;
		}
		case 0x23:
		{
			if(sides[fighters_OwnSide(attacker)].effLightScreen)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				//TODO	Requires localization
				sides[fighters_OwnSide(attacker)].effLightScreen = 5;
				if(!battle_IsOpposing(attacker))
					btlsayf(BT_XsXRaisedSpDef, "Ally's", Abilities[fighters[attacker].ability]);
				else
					btlsayf(BT_XsXRaisedSpDef, "Foe's", Abilities[fighters[attacker].ability]);
			}

			return 0;
		}
		case 0x25:
		{
			if(!effect_CanSleep(attacker,1,0)) return -1;
			if(fighters[attacker].mon->Status.CurrentHP == fighters[attacker].mon->Status.TotalHP)
			{
				btlsayf(BT_XsHPIsFull,fighters_This(attacker));
				return -1;
			}
			if(fighters[attacker].mon->Status.AilmentSleep)
				btlsayf(BT_XSleptAndBecameHealthy, fighters_This(attacker));
			else
				btlsayf(BT_XWentToSleep, fighters_This(attacker));

			effect_Sleep(attacker,3);
			fighters_RestoreHP(attacker, fighters[attacker].mon->Status.TotalHP - fighters[attacker].mon->Status.CurrentHP);
			btlsayf(BT_XRegainedHealth, fighters_This(attacker));

			return 0;
		}
		case 0x26:
		{
			int damage = move_EffectFixedDamage(mid, fighters[opponent].mon->Status.CurrentHP, attacker, opponent);
			if(fighters[opponent].mon->Status.CurrentHP == 0)
				btlsayf(BT_ItsAOneHitKo);

			return damage;
		}
		case 0x27:
		{
			if(fighters[attacker].effTwoTurnAttack)
			{
				btlsayf(BT_XWhippedUpAWhirlwind, fighters_This(attacker));
				return 0;
			}
			else
			{
				return __move_Effect(movePound, attacker, opponent);
			}
		}
		case 0x28:
		{
			return move_EffectFixedDamage(mid,(fighters[opponent].mon->Status.CurrentHP / 2), attacker, opponent);
		}
		case 0x29:
		{
			return move_EffectFixedDamage(mid, 40, attacker, opponent);
		}
		case 0x2A:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			if(fighters[opponent].damagestate.calcdamage>0 && fighters[opponent].damagestate.substitute)
			{
				if(fighters[opponent].effMultiTurn == 0)
				{
					fighters[opponent].effMultiTurn = 3 + rrand(4);
					fighters[opponent].effMultiTurnUser = fighters[attacker].pokemonIndex;
					fighters[opponent].effMultiTurnAttack = mid;
					switch(mid)
					{
						case moveBind:
						{
							btlsayf(BT_XWasSqueezedByXsBind,fighters_This(opponent),fighters_This(attacker));

							break;
						}
						case moveWhirlpool:
						{
							btlsayf(BT_XWasTrappedInTheVortex,fighters_This(opponent));

							break;
						}
						case moveFireSpin:
						{
							btlsayf(BT_XWasTrappedInTheVortex,fighters_This(opponent));

							break;
						}
						case moveSandTomb:
						{
							btlsayf(BT_XWasTrappedBySandTomb,fighters_This(opponent));

							break;
						}
						case moveWrap:
						{
							btlsayf(BT_XWasWrappedByX,fighters_This(opponent),fighters_This(attacker));

							break;
						}
						case moveClamp:
						{
							btlsayf(BT_XClampedX,fighters_This(attacker),fighters_This(opponent));

							break;
						}
					}
				}
			}
			return ret;
		}
		case 0x2E:
		{
			if(sides[fighters_OwnSide(attacker)].effMist>0)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			sides[fighters_OwnSide(attacker)].effMist = 5;

			//TODO	Requires localization
			if(battle_IsOpposing(attacker))
				btlsayf(BT_XBecameShroudedInMist, "Ally");
			else
				btlsayf(BT_XBecameShroudedInMist, "Foe");

			return 0;
		}
		case 0x2F:
		{
			if(fighters[attacker].effFocusEnergy)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				fighters[attacker].effFocusEnergy = 1;
				btlsayf(BT_XIsGettingPumped, fighters_This(attacker));
				return 0;
			}
		}
		case 0x30:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			if(fighters[opponent].damagestate.calcdamage)
			{
				if(fighters[attacker].ability != abilityRockHead || mid == moveStruggle)
				{
					if(fighters_DrainHP(attacker,fighters[opponent].damagestate.hplost / 4))
					{
						btlsayf(BT_XIsHitWithRecoil, fighters_This(attacker));
					} //else there would be a zero-damage recoil, which makes no sense to announce.
				}
			}

			return ret;
		}
		case 0x31:
		{
			if(effect_CanConfuse(opponent,1))
			{
				fighters[opponent].effConfusion = 2 + rrand(4);
				btlsayf(BT_XBecameConfused, fighters_This(opponent));
				return 0;
			}

			return -1;
		}
		case 0x32:
		{
			if(fighters[attacker].stageAttack == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_ATTACK]);
				return -1;
			}
			else
			{
				fighters[attacker].stageAttack+=2;
				if(fighters[attacker].stageAttack > 6) fighters[attacker].stageAttack=6;
				sprintf(sharply, "%s %s", BattleStrings[BT_Sharply], BattleStrings[BT_Rose]);
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[0], sharply);
			}

			return 0;
		}
		case 0x33:
		{
			if(fighters[attacker].stageDefense == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_DEFENSE]);
				return -1;
			}
			else
			{
				fighters[attacker].stageDefense+=2;
				if(fighters[attacker].stageDefense > 6) fighters[attacker].stageDefense=6;
				sprintf(sharply, "%s %s", BattleStrings[BT_Sharply], BattleStrings[BT_Rose]);
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[1], sharply);
			}

			return 0;
		}
		case 0x34:
		{
			if(fighters[attacker].stageSpeed == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_SPEED]);
				return -1;
			}
			else
			{
				fighters[attacker].stageSpeed+=2;
				if(fighters[attacker].stageSpeed > 6) fighters[attacker].stageSpeed=6;
				sprintf(sharply, "%s %s", BattleStrings[BT_Sharply], BattleStrings[BT_Rose]);
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[2], sharply);
			}

			return 0;
		}
		case 0x35:
		{
			if(fighters[attacker].stageSpAtk == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_SPATK]);
				return -1;
			}
			else
			{
				fighters[attacker].stageSpAtk+=2;
				if(fighters[attacker].stageSpAtk > 6) fighters[attacker].stageSpAtk=6;
				sprintf(sharply, "%s %s", BattleStrings[BT_Sharply], BattleStrings[BT_Rose]);
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[3], sharply);
			}

			return 0;
		}
		case 0x36:
		{
			if(fighters[attacker].stageSpDef == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_SPDEF]);
				return -1;
			}
			else
			{
				fighters[attacker].stageSpDef+=2;
				if(fighters[attacker].stageSpDef > 6) fighters[attacker].stageSpDef=6;
				sprintf(sharply, "%s %s", BattleStrings[BT_Sharply], BattleStrings[BT_Rose]);
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[4], sharply);
			}

			return 0;
		}
		case 0x39:
		{
			//TODO	Transform effect (0x39)
			//User's stats (except HP), types, moves, species, individual values, ability,
			//and stat stages become those of the opponent. Gender is not copied. Ends
			//effect of Disable for the user. Moves copied have 5 PP. Fails if opponent
			//is using Fly, Dig, Dive, or Bounce. These attributes revert to their
			//originals when user is replaced. During effect, user may use this attack,
			//and this attack fails against user.
			btlsayf(BT_ButItFailed);
			return -1;
		}
		case 0x3A:
		{
			return effect_ReduceStat(opponent, 0, 2, 1);
		}
		case 0x3B:
		{
			return effect_ReduceStat(opponent, 1, 2, 1);
		}
		case 0x3C:
		{
			return effect_ReduceStat(opponent, 2, 2, 1);
		}
		case 0x3E:
		{
			return effect_ReduceStat(opponent, 4, 2, 1);
		}
		case 0x41:
		{
			if(sides[fighters_OwnSide(attacker)].effReflect > 0)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				sides[fighters_OwnSide(attacker)].effReflect = 5;

				//TODO	Requires localization
				if(!battle_IsOpposing(attacker))
					btlsayf(BT_XsXRaisedDefense, "Ally's", moveNames[mid]);
				else
					btlsayf(BT_XsXRaisedDefense, "Foe's", moveNames[mid]);

			}

			return 0;
		}
		case 0x42:
		{
			if(effect_CanPoison(opponent,1))
			{
				fighters[opponent].mon->Status.AilmentPoison = 1;
				fighters[opponent].mon->Status.AilmentBadPoison = 0;
				btlsayf(BT_XWasPoisoned,fighters_This(opponent));

				if(fighters[opponent].ability == abilitySynchronize)
				{
					if(!effect_CanPoisonSynchronize(attacker,opponent)) return 0;
					fighters[attacker].mon->Status.AilmentPoison = 1;
					btlsayf(BT_XsXPoisonedX, fighters_This(opponent), Abilities[fighters[opponent].ability], fighters_This(attacker));
				}
				return 0;
			}

			return 0;
		}
		case 0x43:
		{
			int typemod = move_TypeModifier(mid, moves[mid].type,opponent);
			if(typemod==0)
			{
				btlsayf(BT_ItDoesntAffectX, fighters_This(opponent));
				return -1;
			}
			if(effect_CanParalyze(opponent,0));
			{
				fighters[opponent].mon->Status.AilmentParalysis = 1;
				btlsayf(BT_XIsParalyzedItMayBeUnableToMove, fighters_This(opponent));
				return 0;
			}

			return -1;
		}
		case 0x4B:
		{
			if(fighters[attacker].effTwoTurnAttack)
			{
				btlsayf(BT_XIsGlowing, fighters_This(attacker));
				return 0;
			}

			return __move_Effect(movePound,attacker,opponent);
		}
		case 0x4F:
		{
			if(fighters[attacker].effSubstitute)
			{
				btlsayf(BT_XAlreadyHasASubstitute, fighters_This(attacker));
				return -1;
			}
			int sublife = fighters[attacker].mon->Status.CurrentHP / 4;
			if((sublife == 0) || (fighters[attacker].mon->Status.CurrentHP <= sublife))
			{
				btlsayf(BT_ItWasTooWeakToMakeASubstitute);
				return -1;
			}
			fighters_DrainHP(attacker,sublife);
			fighters[attacker].effMultiTurn = 0;
			fighters[attacker].effMultiTurnAttack = 0;
			fighters[attacker].effSubstitute = sublife;
			btlsayf(BT_XMadeASubstitute, fighters_This(attacker));

			return 0;
		}
		case 0x50:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			if(fighters[opponent].damagestate.calcdamage)
			{
				fighters[attacker].effHyperBeam = 2;
				fighters[attacker].currentMove = mid;
			}

			return ret;
		}
		case 0x52:
		{
			//TODO	Mimic effect (0x52)
			//Copies last move used by opponent.
			//The copied attack has 5 PP. Fails
			//if opponent had used Metronome,
			//Mimic, Struggle, Sketch, or any move
			//user knows. Fails if Transform is
			//in effect for user.
			btlsayf(BT_ButItFailed);
			return -1;
		}
		case 0x53:
		{
			//TEST	Metronome effect (0x53)
			//Uses a random attack. Does not
			//use Metronome, Struggle, Sketch,
			//Mimic, Counter, Mirror Coat,
			//Protect, Detect, Endure,
			//Destiny Bond, Sleep Talk, Thief,
			//Follow Me, Snatch, Helping Hand,
			//Covet, Trick, or Focus Punch.
			int metronome, i, j;
			const short metronot[] =
			{
				moveMetronome,
				moveStruggle,
				moveSketch,
				moveMimic,
				moveCounter,
				moveMirrorCoat,
				moveProtect,
				moveDetect,
				moveEndure,
				moveDestinyBond,
				moveSleepTalk,
				moveThief,
				moveFollowMe,
				moveSnatch,
				moveHelpingHand,
				moveCovet,
				moveTrick,
				moveFocusPunch,
			};
			while(1)
			{
				metronome = rrand(moveCount);
				i = 0;
				for(j=0; j<18; j++)
				{
					if(metronome == metronot[j])
					{
						i = 1; //mark as found
						break;
					}
				}
				if(i == 0) break; //not found? use it
			}

			#ifdef DEBUG
			btlsays("Debug: chose %s.", moveNames[metronome]);
			#endif

			return __move_Effect(metronome,attacker,opponent);
		}
		case 0x54:
		{
			if((fighters[opponent].effLeechSeed) || (fighters[opponent].effSubstitute))
			{
				btlsayf(BT_XEvadedTheAttack, fighters_This(opponent));
				return -1;
			}
			if(fighters_HasType(opponent, tpGrass))
			{
				btlsayf(BT_ItDoesntAffectX, fighters_This(opponent));
				return -1;
			}
			fighters[opponent].effLeechSeed = attacker;
			btlsayf(BT_XWasSeeded, fighters_This(opponent));

			return 0;
		}
		case 0x55:
		{
			//NOT something I missed. This is Splash.
			btlsayf(BT_ButNothingHappened);
			return 0;
		}
		case 0x56:
		{
			if(fighters[opponent].effDisableTimer)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}

			if(fighters[opponent].lastMoveUsed)
			{
				fighters[opponent].effDisableMove = fighters[opponent].lastMoveUsed;
				fighters[opponent].effDisableTimer = 2 + rrand(4);
				btlsayf(BT_XsXWasDisabled, fighters_This(opponent), moveNames[fighters[opponent].lastMoveUsed]);
			}
			else
			{
				btlsayf(BT_ButItFailed);
			}

			return -1;
		}
		case 0x57:
		{
			return move_EffectFixedDamage(mid, fighters[attacker].mon->Status.Level, attacker, opponent);
		}
		case 0x58:
		{
			int r = rrand(11);
			int d = ((fighters[attacker].mon->Status.Level) * (r * 10 + 50) / 100);

			return move_EffectFixedDamage(mid, d, attacker, opponent);
		}
		case 0x59:
		{
			if(fighters[attacker].effCounter == 0)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			int ret = move_EffectFixedDamage(mid,fighters[attacker].effCounter * 2, attacker, opponent);

			return ret;
		}
		case 0x5A:
		{
			if(fighters[opponent].effEncore)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			if(	fighters[opponent].lastMoveUsed <= 0 ||
					fighters[opponent].lastMoveUsed == moveStruggle ||
					fighters[opponent].lastMoveUsed == moveEncore ||
					fighters[opponent].lastMoveUsed == moveMirrorMove)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}

			if(fighters[opponent].lastMoveUsed)
			{
				fighters[opponent].effEncoreIndex = fighters[opponent].lastMoveUsed;
				fighters[opponent].effEncore = 3 + rrand(4);
				btlsayf(BT_XGotAnEncore, fighters_This(opponent));
			}
			else
			{
				btlsayf(BT_ButItFailed);
			}

			return -1;
		}
		case 0x5B:
		{
			if(fighters[opponent].effSubstitute)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}

			int oldahp = fighters[attacker].mon->Status.CurrentHP;
			int oldohp = fighters[opponent].mon->Status.CurrentHP;
			int avghp = (oldohp + oldahp) / 2;
			int newahp = avghp;
			int newohp = avghp;

			if(newahp > fighters[attacker].mon->Status.TotalHP)
				newahp = fighters[attacker].mon->Status.TotalHP;
			if(newohp > fighters[opponent].mon->Status.TotalHP)
				newohp = fighters[opponent].mon->Status.TotalHP;

			fighters[attacker].mon->Status.CurrentHP = newahp;
			fighters[opponent].mon->Status.CurrentHP = newohp;
			fighters_DrainHP(0,0);
			fighters_DrainHP(1,0);
			btlsayf(BT_TheBattlersSharedTheirPain);

			return 0;
		}
		case 0x5D:
		{
			//TODO	Conversion-2 effect (0x5D)
			//User's types change to one that is resistant
			//or immune (random type) to the type of the
			//last attack that successfully targeted user.
			//Fails if there is no such move. User reverts
			//to its original types when user is replaced.
			//Considers determined types of Hidden Power and
			//Weather Ball. Can choose one of the user's types.
			btlsayf(BT_ButItFailed);
			return -1;
		}
		case 0x5E:
		{
			fighters[opponent].effLockOn = 2;
			fighters[opponent].effLockOnPos = opponent;
			btlsayf(BT_XTookAimAtX, fighters_This(attacker), fighters_This(opponent));

			return 0;
		}
		case 0x5F:
		{
			//TODO	Sketch effect (0x5F)
			//Permanently copies move opponent last
			//used (different variable). That attack
			//replaces this attack. Does not copy Sketch,
			//Struggle, or any move user knows. Fails if
			//Transform is in effect for user. Moves
			//copied this way have all PP.
			btlsayf(BT_ButItFailed);
			return -1;
		}
		case 0x61:
		{
			//TODO	Sleep Talk effect (0x61)
			//Uses one of the user's moves, at random.
			//Fails unless user is asleep. Doesn't choose
			//Bide, Sleep Talk, Assist, Mirror Move,
			//Metronome, Focus Punch, Uproar, or any
			//two-turn attack. Doesn't choose a disabled
			//move, a move the user cannot choose for use,
			//or a move with zero PP. No PP is spent for
			//the move used.
			btlsayf(BT_ButItFailed);
			return -1;
		}
		case 0x62:
		{
			fighters[attacker].effDestinyBond = 1;
			btlsayf(BT_XIsTryingToTakeItsFoeWithIt, fighters_This(attacker));

			return 0;
		}
		case 0x64:
		{
			int i, red;
			for(i = 0; i < 4; i++)
			{
				int atk = GetMonsterStats(fighters[opponent].mon, pMove1 + i);
				int pp = GetMonsterStats(fighters[opponent].mon, pPP1 + i);
				if(atk == fighters[opponent].lastMoveUsed && atk > 0 && pp > 1)
				{
					red = 2 + rrand(4);
					if(red > pp) red = pp;
					btlsayf(BT_ReducedXsXByX, fighters_This(opponent), moveNames[fighters[opponent].lastMoveUsed], red);
					return 0;
				}
			}
			btlsayf(BT_ButItFailed);

			return -1;
		}
		case 0x66:
		{
			if(mid == moveAromatherapy)
				btlsayf(BT_ASoothingAromaWaftedThroughTheArea);
			else
				btlsayf(BT_ABellChimed);

			//TODO	Cure participants on your side, feedback on Soundproof
			//Then cure the whole party, no feedback
			return 0;
		}
		case 0x69:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			int hisitem = GetMonsterStats(fighters[opponent].mon, pHeldItem);
			int youritem = GetMonsterStats(fighters[attacker].mon, pHeldItem);

			if(	fighters[opponent].damagestate.calcdamage &&
					!fighters[opponent].damagestate.substitute &&
					hisitem)
			{
				if(fighters[opponent].ability == abilityStickyHold)
				{
					btlsayf(BT_XsXMadeXIneffective, fighters_This(opponent), Abilities[fighters[opponent].ability], moveNames[mid]);
				}
				else if(youritem == 0)
				{
					youritem = hisitem;
					hisitem = 0;
					btlsayf(BT_XStoleXsX,fighters_This(attacker),fighters_This(opponent), items[youritem].name);
				}
			}
			SetMonsterStats(fighters[opponent].mon, pHeldItem, hisitem);
			SetMonsterStats(fighters[attacker].mon, pHeldItem, youritem);

			return ret;
		}
		case 0x6A:
		{
			if(fighters[opponent].effMeanLook)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				fighters[opponent].effMeanLook = fighters[attacker].pokemonIndex;
				btlsayf(BT_XCantEscapeNow, fighters_This(opponent));
				return 0;
			}
		}
		case 0x6B:
		{
			if(fighters[opponent].mon->Status.AilmentSleep==0 ||
				 fighters[opponent].effNightmare ||
				 fighters[opponent].effSubstitute)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			fighters[opponent].effNightmare = 1;
			btlsayf(BT_XFellIntoANightmare, fighters_This(opponent));

			return 0;
		}
		case 0x6C:
		{
			fighters[attacker].effMinimize = 1;
			if(fighters[attacker].stageEvasiveness == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_EVASIVENESS]);
				return -1;
			}
			else
			{
				fighters[attacker].stageEvasiveness++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_EVASIVENESS], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0x6D:
		{
			//TODO	Curse effect (0x6D)
			//If user's current type does not
			//include Ghost, decreases user's
			//Speed by one stage and increases
			//user's Attack and Defense by one
			//stage. If user's current type
			//includes Ghost, user loses half
			//of total HP (even if HP reduced
			//would faint user) and at the end
			//of every round, opponent loses
			//1/4 of total HP. This latter effect
			//ends when opponent is switched.
			//During effect, this attack fails
			//against opponent. (If user doesn't
			//choose an opponent, a random
			//opposing Pokemon is chosen as the
			//opponent.)
			return -1;
		}
		case 0x6F:
		{
			//TODO	Protect/Detect effect (0x6F)
			//User doesn't receive the effects
			//of certain moves used this round
			//by non-users. This attack fails if
			//it occurred last this round.
			//Success rate for this attack
			//decreases with consecutive use.
			return -1;
		}
		case 0x70:
		{
			if(sides[fighters_OwnSide(attacker)].effSpikes >= 3)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				sides[fighters_OwnSide(attacker)].effSpikes++;
				btlsayf(BT_SpikesWereScatteredAllAroundTheOpponentsSide);
				return 0;
			}
		}
		case 0x71:
		{
			fighters[opponent].effForesight = 1;
			btlsayf(BT_XIdentifiedX,fighters_This(attacker),fighters_This(opponent));

			return 0;
		}
		case 0x72:
		{
			int i, failed = 1;

			for(i=0; i<4;i++)
			{
				if((fighters[i].effPerishSong == 0) && (fighters[i].ability != abilitySoundproof))
					failed = 0;
			}

			if(failed)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}

			btlsayf(BT_AllAffectedPokemonWillFaintInThreeTurns);

			for(i=0; i<4; i++)
			{
				if(fighters[i].effPerishSong==0)
				{
					if(fighters[i].ability == abilitySoundproof)
						btlsayf(BT_XsXBlocksX, fighters_This(i), Abilities[fighters[i].ability], moveNames[mid]);
					else
						fighters[i].effPerishSong = 4;
				}
			}

			return 0;
		}
		case 0x73:
		{
			if(ThisBattle.weather == WEATHER_SANDSTORM)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				ThisBattle.weather = WEATHER_SANDSTORM;
				ThisBattle.weatherduration = 5;
				btlsayf(BT_ASandstormBrewed);
				return 0;
			}
		}

		case 0x74:
		{
			//TODO	Endure effect (0x74)
/*
 #TODO	Fails if attack strikes last
 successrates=[65535,32767,16383,8191]
 if attacker.lastMoveCalled!=PBMoves::PROTECT&&
    attacker.lastMoveCalled!=PBMoves::DETECT&&
    attacker.lastMoveCalled!=PBMoves::ENDURE
  attacker.effects[PBEffects::ProtectRate]=0
 end
 if attacker.effects[PBEffects::ProtectRate]<4 &&
   @battle.pbRandom(65536)<=successrates[attacker.effects[PBEffects::ProtectRate]]
  attacker.effects[PBEffects::Endure]=true
  attacker.effects[PBEffects::ProtectRate]+=1
  @battle.pbDisplay("#{attacker.pbThis} braced itself!")
  return 0
 else
  attacker.effects[PBEffects::ProtectRate]=0
  @battle.pbDisplay("But it failed!")
  return -1
 end
*/
		}
		case 0x76:
		{
			int ret = -1;
			if(fighters[opponent].effSubstitute)
			{
				btlsayf(BT_XsAttackMissed, fighters_This(attacker));
				return -1;
			}
			if(fighters[attacker].stageAttack < 6)
			{
				fighters[attacker].stageAttack+=2;
				if(fighters[attacker].stageAttack > 6) fighters[attacker].stageAttack=6;
				sprintf(sharply, "%s %s", BattleStrings[BT_Sharply], BattleStrings[BT_Rose]);
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[0], sharply);
				ret = 0;
			}

			if(fighters[opponent].effConfusion == 0 && effect_CanConfuse(opponent, 1))
			{
				fighters[opponent].effConfusion = 2 + rrand(4);
				btlsayf(BT_XBecameConfused, fighters_This(opponent));
				ret = 0;
			}

			return ret;
		}
		case 0x78:
		{
			if(fighters[opponent].ability == abilityOblivious)
			{
				btlsayf(BT_XsXPreventsRomance, fighters_This(opponent), Abilities[abilityOblivious]);
				return -1;
			}
			if(fighters[opponent].effAttract >= 0)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			int atkGender = 0, oppGender = 0;
			int atkspecies = GetMonsterStats(fighters[attacker].mon, pSpecies);
			int oppspecies = GetMonsterStats(fighters[attacker].mon, pSpecies);

			if(BaseStats[atkspecies].Gender < 0xFF)
				atkGender = ((u8)fighters[attacker].mon->Personal.Personal > BaseStats[atkspecies].Gender) ? 1 : 2;
			if(BaseStats[oppspecies].Gender < 0xFF)
				oppGender = ((u8)fighters[attacker].mon->Personal.Personal > BaseStats[oppspecies].Gender) ? 1 : 2;
			if(atkGender == 0 || oppGender == 0 || atkGender == oppGender)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			fighters[opponent].effAttract = attacker;
			btlsayf(BT_XFellInLove, fighters_This(opponent));

			return 0;
		}
		case 0x7A:
		{
			//TODO	Present effect (0x7A)
/*
 random=@battle.pbRandom(256)
 basedmg=0
 if random<52
  hpgain=opponent.pbRecoverHP((opponent.totalhp/4).floor)
  if hpgain==0
   @battle.pbDisplay("#{opponent.pbThis}'s HP is full!")
  else
   @battle.pbDisplay("#{opponent.pbThis} regained health!")
  end
  return 0
 elsif random<154
  @calcbasedmg=40
 elsif random<240
  @calcbasedmg=80
 else
  @calcbasedmg=120
 end
 # TODO	Immunity check is currently handled earlier
 return super(attacker,opponent)
*/
		}
		case 0x7C:
		{
			if(sides[fighters_OwnSide(attacker)].effSafeguard)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			sides[fighters_OwnSide(attacker)].effSafeguard = 5;

			//TODO	Requires localization
			if(battle_IsOpposing(fighters[attacker].pokemonIndex))
				btlsayf(BT_XsPartyIsCoveredByAVeil, "The ally");
			else
				btlsayf(BT_XsPartyIsCoveredByAVeil, "The foe");

			return 0;
		}
		case 0x7F:
		{
			//TODO	Baton Pass effect (0x7F)
/*
 if !@battle.pbCanChooseNonActive?(attacker.index)
  @battle.pbDisplay("But it failed!")
  return -1
 end
 party=@battle.pbParty(attacker.index)
 newpoke=0
 if @battle.pbIsOpposing?(attacker.index)
  newpoke=@battle.scene.pbChooseNewEnemy(attacker.index,party)
 else
  newpoke=@battle.pbSwitchPlayer(attacker.index,true,false)
 end
 attacker.pbInitialize(party[newpoke],newpoke,true);
 if !@battle.pbIsOpposing?(attacker.index)
  @battle.pbDisplay("Go! #{attacker.name}!")
 else
  @battle.pbDisplay("The Trainer sent out #{attacker.name}!")
 end
 @battle.pbOnActiveOne(attacker)
 return 0
*/
		}
		case 0x81:
		{
			//TODO	Rapid Spin effect (0x81)
/*
 ret=super(attacker,opponent)
 return ret if opponent.damagestate.calcdamage<=0
 if attacker.effects[PBEffects::MultiTurn]>0
  mtuser=@battle.battlers[attacker.effects[PBEffects::MultiTurnUser]]
  mtattack=PokeBattle_Move.getName(attacker.effects[PBEffects::MultiTurnAttack])
  @battle.pbDisplay("#{attacker.pbThis} got free of #{mtuser.pbThis}'s #{mtattack}!")
  attacker.effects[PBEffects::MultiTurn]=-1
  attacker.effects[PBEffects::MultiTurnUser]=-1
  attacker.effects[PBEffects::MultiTurnAttack]=0
 end
 if attacker.effects[PBEffects::LeechSeed]
  attacker.effects[PBEffects::LeechSeed]=-1
  @battle.pbDisplay("#{attacker.pbThis} shed Leech Seed!")
 end
 if attacker.pbOwnSide.effects[PBEffects::Spikes]>0
  attacker.pbOwnSide.effects[PBEffects::Spikes]=0
  @battle.pbDisplay("#{attacker.pbThis} blew away Spikes!")
 end
 return ret
*/
		}
		case 0x82:
		{
			return move_EffectFixedDamage(mid,20,attacker,opponent);
		}
		case 0x84:
		{
			int hpgain = 0;
			if(ThisBattle.weather == WEATHER_SUNNYDAY)
				hpgain = (fighters[attacker].mon->Status.TotalHP * 2/3);
			else if(ThisBattle.weather != 0)
				hpgain = (fighters[attacker].mon->Status.TotalHP / 4);
			else
				hpgain = (fighters[attacker].mon->Status.TotalHP / 2);

			hpgain = fighters_RestoreHP(attacker,hpgain);
			if(hpgain==0)
			{
				btlsayf(BT_XsHPIsFull,fighters_This(attacker));
				return -1;
			}
			else
			{
				btlsayf(BT_XRegainedHealth,fighters_This(attacker));
				return 0;
			}
		}
		case 0x85:
		{
			int hpgain = 0;
			if(ThisBattle.weather == WEATHER_SUNNYDAY)
				hpgain = (fighters[attacker].mon->Status.TotalHP * 2/3);
			else if(ThisBattle.weather != 0)
				hpgain = (fighters[attacker].mon->Status.TotalHP / 4);
			else
				hpgain = (fighters[attacker].mon->Status.TotalHP / 2);

			hpgain = fighters_RestoreHP(attacker,hpgain);
			if(hpgain==0)
			{
				btlsayf(BT_XsHPIsFull,fighters_This(attacker));
				return -1;
			}
			else
			{
				btlsayf(BT_XRegainedHealth,fighters_This(attacker));
				return 0;
			}
		}
		case 0x86:
		{
			int hpgain = 0;
			if(ThisBattle.weather==WEATHER_SUNNYDAY)
				hpgain = (fighters[attacker].mon->Status.TotalHP * 2/3);
			else if(ThisBattle.weather != 0)
				hpgain = (fighters[attacker].mon->Status.TotalHP / 4);
			else
				hpgain = (fighters[attacker].mon->Status.TotalHP / 2);

			hpgain = fighters_RestoreHP(attacker,hpgain);
			if(hpgain==0)
			{
				btlsayf(BT_XsHPIsFull,fighters_This(attacker));
				return -1;
			}
			else
			{
				btlsayf(BT_XRegainedHealth,fighters_This(attacker));
				return 0;
			}
		}
		case 0x88:
		{
			if(ThisBattle.weather == WEATHER_RAINDANCE)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				ThisBattle.weather = WEATHER_RAINDANCE;
				ThisBattle.weatherduration = 5;
				btlsayf(BT_ItStartedToRain);
			}
		}
		case 0x89:
		{
			if(ThisBattle.weather == WEATHER_SUNNYDAY)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				ThisBattle.weather = WEATHER_SUNNYDAY;
				ThisBattle.weatherduration = 5;
				btlsayf(BT_TheSunlightGotBright);
			}
		}
		case 0x8E:
		{
			//TODO	Belly Drum effect (0x8E)
/*
 if attacker.hp<=(attacker.totalhp/2).floor
  @battle.pbDisplay("But it failed!")
  return -1
 end
 if attacker.pbTooHigh?(PBStats::ATTACK)
  @battle.pbDisplay("But it failed!")
  return -1
 end
 attacker.pbReduceHP((attacker.totalhp/2).floor)
 attacker.stages[PBStats::ATTACK]=6
 @battle.pbDisplay("#{attacker.pbThis} cut its own HP and maximized Attack!")
 return 0
*/
		}
		case 0x8F:
		{
			fighters[attacker].stageAttack = fighters[opponent].stageAttack;
			fighters[attacker].stageDefense = fighters[opponent].stageDefense;
			fighters[attacker].stageSpeed = fighters[opponent].stageSpeed;
			fighters[attacker].stageSpAtk = fighters[opponent].stageSpAtk;
			fighters[attacker].stageSpDef = fighters[opponent].stageSpDef;
			btlsayf(BT_XCopiedXsStatChanges,fighters_This(attacker),fighters_This(opponent));
			return 0;
		}
		case 0x90:
		{
			if(fighters[attacker].effMirrorCoat == 0 || !opponent)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			int ret = move_EffectFixedDamage(mid, fighters[attacker].effMirrorCoat*2,attacker,opponent);
			return ret;
		}
		case 0x91:
		{
			if(fighters[attacker].effTwoTurnAttack)
			{
				btlsayf(BT_XLoweredItsHead, fighters_This(attacker));
				if(fighters[attacker].stageDefense < 6)
				{
					fighters[attacker].stageDefense++;
					btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Rose]);
				}
				return 0;
			}
			return __move_Effect(movePound,attacker,opponent);
		}
		case 0x94:
		{
			//TODO	Should ignore Wonder Guard/immunity
			if(fighters[opponent].effFutureSight)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				int damage = move_CalcDamage(mid,attacker,opponent,CALCDMG_NOCRITICAL | CALCDMG_NOWEIGHTING | CALCDMG_IGNOREPKMNTYPES);
				fighters[opponent].effFutureSight = 3;
				fighters[opponent].effFutureSightDamage = damage;
				fighters[opponent].effFutureSightMove = mid;
				if(mid == moveFutureSight)
				{
					btlsayf(BT_XForesawAnAttack, fighters_This(attacker));
				}
				else
				{
					btlsayf(BT_XChoseXAsItsDestiny, fighters_This(attacker), moveNames[moveDoomDesire]);
				}
				return 0;
			}
		}
		case 0x97:
		{
			if(fighters[attacker].effTwoTurnAttack && ThisBattle.weather != WEATHER_SUNNYDAY)
			{
				btlsayf(BT_XTookInSunlight, fighters_This(attacker));
				return 0;
			}
			return __move_Effect(movePound,attacker,opponent);
		}
		case 0x99:
		{
			if(ThisBattle.trainer)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else if(battle_CanSwitch(fighters[attacker].pokemonIndex,-1,false))
				//TODO	Add Smoke Ball and Run Away checks as seen below
			{
				btlsayf(BT_XFledFromBattle, fighters_This(attacker));
				ThisBattle.decision = 3;
				return 0;
			}
			else
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
/*
 elsif attacker.item==PBItems::SMOKEBALL||
     attacker.ability==PBAbilities::RUNAWAY||
     @battle.pbCanSwitch?(attacker.index,-1,false)
*/
		}
		case 0x9B:
		{
			if(fighters[attacker].effTwoTurnAttack)
			{
				switch(mid)
				{
					case moveDig:
					{
						btlsayf(BT_XDugAHole, fighters_This(attacker));
						break;
					}
					case moveFly:
					{
						btlsayf(BT_XFlewUpHigh, fighters_This(attacker));
						break;
					}
					case moveDive:
					{
						btlsayf(BT_XHidUnderwater, fighters_This(attacker));
						break;
					}
					case moveBounce:
					{
						btlsayf(BT_XSprangUp, fighters_This(attacker));
						break;
					}
				}
				return 0;
			}
			return __move_Effect(movePound, attacker, opponent);
		}
		case 0x9C:
		{
			fighters[attacker].effDefenseCurl = true;
			if(fighters[attacker].stageDefense == 6)
			{
				btlsayf(BT_XsXWontGoHigher, fighters_This(attacker), BattleStatNames[STAT_DEFENSE]);
				return -1;
			}
			else
			{
				fighters[attacker].stageDefense++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Rose]);
			}
			return 0;
		}
		case 0x9D:
		{
			int hpgain = (fighters[attacker].mon->Status.TotalHP / 2);
			hpgain = fighters_RestoreHP(attacker,hpgain);
			if(hpgain==0)
			{
				btlsayf(BT_XsHPIsFull,fighters_This(attacker));
				return -1;
			}
			else
			{
				btlsayf(BT_XRegainedHealth,fighters_This(attacker));
				return 0;
			}
		}
		case 0x9F:
		{
			int ret = __move_Effect(movePound, attacker, opponent);
			if(fighters[opponent].damagestate.calcdamage)
			{
				if(fighters[attacker].effUproar)
				{
					fighters[attacker].effUproar = 2 + rrand(4);
					btlsayf(BT_XCausedAnUproar, fighters_This(attacker));
					fighters[attacker].currentMove = mid;
				}
			}
			return ret;
		}
		case 0xA0:
		{
			if(fighters[attacker].effStockpile >= 3)
			{
				btlsayf(BT_XCantStockpileAnyMore, fighters_This(attacker));
				return -1;
			}
			else
			{
				fighters[attacker].effStockpile++;
				btlsayf(BT_XStockpiledX, fighters_This(attacker), fighters[attacker].effStockpile);
				return 0;
			}
		}
		case 0xA1:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			fighters[attacker].effStockpile = 0;
			return ret;
		}
		case 0xA2:
		{
			int hpgain = 0;
			switch(fighters[attacker].effStockpile)
			{
				case 0:
				{
					btlsayf(BT_ButItFailedToSwallowAThing);
					return -1;
				}
				case 1:
				{
					hpgain = (fighters[attacker].mon->Status.TotalHP / 4);
					break;
				}
				case 2:
				{
					hpgain = (fighters[attacker].mon->Status.TotalHP / 2);
					break;
				}
				case 3:
				{
					hpgain = (fighters[attacker].mon->Status.TotalHP / 1);
					break;
				}
			}
			hpgain = fighters_RestoreHP(attacker,hpgain);
			fighters[attacker].effStockpile = 0;
			if(hpgain == 0)
			{
				btlsayf(BT_XsHPIsFull,fighters_This(attacker));
				return -1;
			}
			else
			{
				btlsayf(BT_XRegainedHealth,fighters_This(attacker));
				return 0;
			}
		}
		case 0xA4:
		{
			if(ThisBattle.weather == WEATHER_HAIL)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				ThisBattle.weather = WEATHER_HAIL;
				ThisBattle.weatherduration = 5;
				btlsayf(BT_ItStartedToHail);
				return 0;
			}
		}
		case 0xA5:
		{
			if(fighters[opponent].effTorment)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				fighters[opponent].effTorment = true;
				btlsayf(BT_XWasSubjectedToTorment, fighters_This(opponent));
				return 0;
			}
		}
		case 0xA6:
		{
			int ret = -1;
			if(fighters[opponent].effSubstitute)
			{
				btlsayf(BT_ButItHadNoEffect);
				return -1;
			}
			if(fighters[attacker].stageSpAtk < 6)
			{
				fighters[attacker].stageSpAtk++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPATK], BattleStrings[BT_Rose]);
				ret = 0;
			}
			if(fighters[opponent].effConfusion == 0) //&& (effect_CanConfuse(opponent,true))
			{
				fighters[opponent].effConfusion = 2 + rrand(4);
				btlsayf(BT_XBecameConfused, fighters_This(opponent));
				ret = 0;
			}
			return ret;
		}
		case 0xA7:
		{
			if(effect_CanBurn(opponent,0))
			{
				return -1;
			}
			fighters[opponent].mon->Status.AilmentBurned = 1;
			btlsayf(BT_XWasBurned,fighters_This(opponent));
			return 0;
		}
		case 0xA8:
		{
			if(fighters[opponent].effSubstitute)
			{
				btlsayf(BT_ButItHadNoEffect);
				return -1;
			}

			if(sides[fighters_OwnSide(opponent)].effMist)
			{
				btlsayf(BT_XIsProtectedByMist,fighters_This(opponent));
				return -1;
			}

			if((fighters[opponent].ability==abilityClearBody) || (fighters[opponent].ability==abilityWhiteSmoke))
			{
				btlsayf(BT_XsXPreventsStatLoss, fighters_This(opponent),Abilities[fighters[opponent].ability]);
				return -1;
			}

			int fail = -1;
			if(fighters[opponent].ability == abilityHyperCutter)
			{
				btlsayf(BT_XsXPreventsStatLoss, fighters_This(opponent),Abilities[fighters[opponent].ability]);
			}
			else if(effect_TooLow(opponent, STAT_ATTACK))
			{
				btlsayf(BT_XsXWontGoLower, fighters_This(opponent), BattleStatNames[STAT_ATTACK]);
			}
			else
			{
				fighters[opponent].stageAttack--;
				btlsayf(BT_XsXX,fighters_This(opponent),BattleStatNames[STAT_ATTACK],BattleStrings[BT_Fell]);
				fail = 0;
			}

			if(effect_TooLow(opponent, STAT_SPATK))
			{
				btlsayf(BT_XsXWontGoLower, fighters_This(opponent), BattleStatNames[STAT_SPATK]);
			}
			else
			{
				fighters[opponent].stageSpAtk--;
				btlsayf(BT_XsXX,fighters_This(opponent),BattleStatNames[STAT_SPATK],BattleStrings[BT_Fell]);
				fail = 0;
			}

			return fail;
		}
		case 0xAB:
		{
			int ret = __move_Effect(movePound, attacker, opponent);
			if(	fighters[opponent].damagestate.calcdamage &&
					fighters[opponent].damagestate.substitute == 0 &&
					fighters[opponent].mon->Status.AilmentParalysis)
			{
				fighters[opponent].mon->Status.AilmentParalysis = 0;
				btlsayf(BT_XWasHealedOfParalysis, fighters_This(opponent));
			}

			return ret;
		}
		case 0xAC:
		{
			fighters[attacker].effFollowMe = true;
			btlsayf(BT_XBecameTheCenterOfAttention, fighters_This(opponent));
			return 0;
		}
		case 0xAD:
		{
			//TEST	Nature Power effect (0xAD)
			int move = moveSwift;
			switch((int)battlebacks[(ThisBattle.background*4)+3])
			{
				case BTLENV_NONE: move = moveSwift; break;
				case BTLENV_GRASS: move = moveStunSpore; break;
				case BTLENV_TALLGRASS: move = moveRazorLeaf; break;
				case BTLENV_MOVINGWATER: move = moveSurf; break;
				case BTLENV_STILLWATER: move = moveBubbleBeam; break;
				case BTLENV_UNDERWATER: move = moveHydroPump; break;
				case BTLENV_ROCK: move = moveRockslide; break;
				case BTLENV_CAVE: move = moveShadowBall; break;
				case BTLENV_SAND: move = moveEarthquake; break;
			}
			btlsayf(BT_NaturePowerTurnedIntoX, moveNames[move]);
			fighters_UseMoveSimple(attacker, move);
			return 0;
		}
		case 0xAE:
		{
			fighters[attacker].effCharge = 2;
			btlsayf(BT_XBeganChargingPower, fighters_This(opponent));
			return 0;
		}
		case 0xAF:
		{
			if(fighters[opponent].effTaunt)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				fighters[opponent].effTaunt = 2;
				btlsayf(BT_XFellForTheTaunt, fighters_This(opponent));
				return 0;
			}
		}
		case 0xB0:
		{
			if(ThisBattle.doublebattle == 0)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}

			if((fighters[fighters_Partner(attacker)].mon->Status.CurrentHP) && (fighters[fighters_Partner(attacker)].effHelpingHand == false))
			{
				fighters[fighters_Partner(attacker)].effHelpingHand = true;
				btlsayf(BT_XIsReadyToHelpX,fighters_This(attacker),fighters_This(fighters_Partner(attacker)));
				return 0;
			}
			else
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
		}
		case 0xB1:
		{
			//TODO	Trick effect (0xB1)
/*
 if attacker.effects[PBEffects::Substitute]>0
  @battle.pbDisplay("But it failed!")
  return -1
 end
 if attacker.item==PBItems::ENIGMABERRY||
    opponent.item==PBItems::ENIGMABERRY
  @battle.pbDisplay("But it failed!")
  return -1
 end
 if attacker.item==0&&
    opponent.item==0
  @battle.pbDisplay("But it failed!")
  return -1
 end
 if opponent.ability==PBAbilities::STICKYHOLD
  @battle.pbDisplay("#{opponent.pbThis}'s Sticky Hold made #{name} ineffective!")
  return -1
 end
 oldoppitem=opponent.item
 oldattitem=attacker.item
 tmpitem=attacker.item
 attacker.item=opponent.item
 opponent.item=tmpitem
 @battle.pbDisplay("#{attacker.pbThis} switched items with its opponent!")
 if oldoppitem>0 && oldattitem>0
  @battle.pbDisplayPaused("#{attacker.pbThis} obtained ???.")
  @battle.pbDisplay("#{opponent.pbThis} obtained ???.")
 else
  @battle.pbDisplay("#{attacker.pbThis} obtained ???.") if oldoppitem>0
  @battle.pbDisplay("#{opponent.pbThis} obtained ???.") if oldattitem>0
 end
 return 0
*/
		}
		case 0xB2:
		{
			if((fighters[opponent].ability == abilityWonderGuard) || (fighters[opponent].ability == 0))
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			fighters[attacker].ability = fighters[opponent].ability;
			btlsayf(BT_XCopiedXsX, fighters_This(attacker),fighters_This(opponent),Abilities[fighters[attacker].ability]);
			return 0;
		}
		case 0xB3:
		{
			if(fighters[attacker].effWish)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			fighters[attacker].effWish = 2;
			fighters[attacker].effWishMaker = fighters[attacker].pokemonIndex;
			return 0;
		}
		case 0xB4:
		{
			//TODO	Assist effect (0xB4)
/*
 moves=[]
 blacklist=[
  0,
  PBMoves::SLEEPTALK,
  PBMoves::ASSIST,
  PBMoves::MIRRORMOVE,
  PBMoves::METRONOME,
  PBMoves::STRUGGLE,
  PBMoves::SKETCH,
  PBMoves::MIMIC,
  PBMoves::COUNTER,
  PBMoves::MIRRORCOAT,
  PBMoves::PROTECT,
  PBMoves::DETECT,
  PBMoves::ENDURE,
  PBMoves::DESTINYBOND,
  PBMoves::THIEF,
  PBMoves::FOLLOWME,
  PBMoves::SNATCH,
  PBMoves::HELPINGHAND,
  PBMoves::COVET,
  PBMoves::TRICK,
  PBMoves::FOCUSPUNCH
 ]
 party=@battle.pbParty(attacker.index)
 for i in 0...party.length
  if i!=attacker.pokemonIndex && party[i].eggsteps==0
   found=false
   for j in party[i].moves
    for k in blacklist
     if j.id==k
      found=true
      break
     end
    end
    moves[moves.length]=j.id if !found
   end
  end
 end
 if moves.length==0
  @battle.pbDisplay("But it failed!")
  return -1
 end
 move=moves[@battle.pbRandom(moves.length)]
 attacker.pbUseMoveSimple(move)
 return 0
*/
		}
		case 0xB5:
		{
			if(fighters[attacker].effIngrain)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				fighters[attacker].effIngrain = true;
				btlsayf(BT_XPlantedItsRoots, fighters_This(attacker));
				return 0;
			}
		}
		case 0xB6:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			if(fighters[opponent].damagestate.calcdamage)
			{
				if(!effect_TooLow(attacker,STAT_ATTACK))
				{
					fighters[attacker].stageAttack--;
					btlsayf(BT_XsXX,fighters_This(attacker),BattleStatNames[STAT_ATTACK],BattleStrings[BT_Fell]);
				}
				if(!effect_TooLow(attacker,STAT_DEFENSE))
				{
					fighters[attacker].stageDefense--;
					btlsayf(BT_XsXX,fighters_This(attacker),BattleStatNames[STAT_DEFENSE],BattleStrings[BT_Fell]);
				}
			}
			return ret;
		}
		case 0xB7:
		{
			fighters[attacker].effMagicCoat = true;
			btlsayf(BT_XShroudedItselfInX, fighters_This(attacker),moveNames[mid]);
			return 0;
		}
		case 0xB8:
		{
			//TODO	Recycle effect (0xB8)
/*
 if attacker.effects[PBEffects::RecycleItem]==0
  @battle.pbDisplay("But it failed!")
  return -1
 end
 attacker.item=attacker.effects[PBEffects::RecycleItem]
 @battle.pbDisplay("#{attacker.pbThis} found one ???!")
 attacker.effects[PBEffects::RecycleItem]=0
 return 0
*/
		}
		case 0xBA:
		{
			//int reflect = false;
			if((sides[fighters_OpposingSide(attacker)].effReflect) ||
					(sides[fighters_OpposingSide(attacker)].effLightScreen))
			{
				sides[fighters_OpposingSide(attacker)].effReflect = 0;
				sides[fighters_OpposingSide(attacker)].effLightScreen = 0;
				btlsayf(BT_TheWallShattered); //TODO	Actually handled earlier
			}
			return __move_Effect(movePound,attacker,opponent);
		}
		case 0xBB:
		{
			if(effect_CanSleep(opponent,true,0))
			{
				return -1;
			}
			if(fighters[opponent].effYawn)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			fighters[opponent].effYawn = 2;
			btlsayf(BT_XMadeXDrowsy, fighters_This(attacker), fighters_This(opponent));
			return 0;
		}
		case 0xBC:
		{
			//TODO	Knock Off effect (0xBC)
/*
 ret=super(attacker,opponent)
 if opponent.damagestate.calcdamage>0&&
    !opponent.damagestate.substitute && opponent.hp>0 && opponent.item!=0
  if opponent.ability==PBAbilities::STICKYHOLD
   @battle.pbDisplay("#{opponent.pbThis}'s Sticky Hold made #{@name} ineffective!")
  else
   opponent.item=0
   @battle.pbDisplay("#{attacker.pbThis} knocked off #{opponent.pbThis}'s ???!")
  end
 end
 return ret
*/
		}
		case 0xBD:
		{
			if(fighters[attacker].mon->Status.CurrentHP >= fighters[opponent].mon->Status.CurrentHP)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				return move_EffectFixedDamage(mid,fighters[opponent].mon->Status.CurrentHP - fighters[attacker].mon->Status.CurrentHP, attacker, opponent);
			}
		}
		case 0xBF:
		{
			//TODO	Skill Swap effect (0xBF)
/*
 if attacker.ability==0&&opponent.ability==0
  @battle.pbDisplay("But it failed!")
  return -1
 end
 if attacker.ability==PBAbilities::WONDERGUARD||
    opponent.ability==PBAbilities::WONDERGUARD
  @battle.pbDisplay("But it failed!")
  return -1
 end
 tmp=attacker.ability
 attacker.ability=opponent.ability
 opponent.ability=tmp
 @battle.pbDisplay("#{attacker.pbThis} swapped abilities with its opponent!")
 return 0
*/
		}
		case 0xC0:
		{
			//TODO	Imprison effect (0xC0)
/*
 if attacker.effects[PBEffects::Imprison]
  @battle.pbDisplay("But it failed!")
  return -1
 end
 found=false
 for i in attacker.moves
  next if i.id==0
  for j in attacker.pbOpposing1.moves
   found=true if j.id==i.id
  end
  for j in attacker.pbOpposing2.moves
   found=true if j.id==i.id
  end
 end
 if !found
  @battle.pbDisplay("But it failed!")
  return -1
 end
 attacker.effects[PBEffects::Imprison]=true
 @battle.pbDisplay("#{attacker.pbThis} sealed the opponent's move(s)!")
 return 0
*/
		}
		case 0xC1:
		{
			//TODO	Refresh effect (0xC1)
/*
 if attacker.status!=PBStatuses::BURN &&
    attacker.status!=PBStatuses::POISON &&
    attacker.status!=PBStatuses::PARALYSIS
  @battle.pbDisplay("But it failed!")
 else
  attacker.status=0
  attacker.statusCount=0
  @battle.pbDisplay("#{attacker.pbThis}'s status returned to normal!")
 end
*/
		}
		case 0xC2:
		{
			fighters[attacker].effGrudge = true;
			btlsayf(BT_XWantsTheOpponentToBearAGrudge,fighters_This(attacker));
			return 0;
		}
		case 0xC3:
		{
			//TODO	Fails if attacker is last in priority
			fighters[attacker].effSnatch = true;
			btlsayf(BT_XWaitsForItsFoeToMakeAMove,fighters_This(attacker));
			return 0;
		}
		case 0xC6:
		{
			int ret=__move_Effect(movePound,attacker,opponent);
			if(fighters[opponent].damagestate.calcdamage)
			{
				if(fighters[attacker].ability != abilityRockHead)
				{
					if(fighters_DrainHP(attacker,(fighters[opponent].damagestate.hplost/3)))
					{
						btlsayf(BT_XIsHitWithRecoil,fighters_This(attacker));
					} //else there would be a zero-damage recoil, which makes no sense to announce.
				}
			}
			return ret;
		}
		case 0xC7:
		{
			//TODO	Teeter Dance effect (0xC7)
/*
 if opponent.pbCanConfuse?(true)
  opponent.effects[PBEffects::Confusion]=2+@battle.pbRandom(4)
  @battle.pbDisplay("#{opponent.pbThis} became confused!")
  return 0
 end
 return -1
*/
		}
		case 0xC9:
		{
			if(fighters[attacker].effMudSport)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				fighters[attacker].effMudSport = true;
				btlsayf(BT_ElectricitysPowerWasWeakened);
				return 0;
			}
		}
		case 0xCC:
		{
			int ret = __move_Effect(movePound,attacker,opponent);
			if((fighters[opponent].damagestate.calcdamage) && (!effect_TooLow(attacker,STAT_SPATK)))
			{
				fighters[attacker].stageSpAtk -= 2;
				if(fighters[attacker].stageSpAtk < -6) fighters[attacker].stageSpAtk = -6;
				btlsayf(BT_XsXX,fighters_This(attacker),BattleStatNames[STAT_SPATK],BattleStrings[BT_Fell]);
			}
			return ret;
		}
		case 0xCD:
		{
			if((effect_TooLow(opponent,STAT_ATTACK)) && (effect_TooLow(opponent,STAT_DEFENSE)))
			{
				btlsayf(BT_XsStatsWontGoAnyLower,fighters_This(opponent));
				return -1;
			}
			if(sides[fighters_OwnSide(opponent)].effMist)
			{
				btlsayf(BT_XIsProtectedByMist,fighters_This(opponent));
				return -1;
			}

			if(	fighters[opponent].ability == abilityClearBody ||
					fighters[opponent].ability == abilityWhiteSmoke)
			{
				btlsayf(BT_XsXPreventsStatLoss, fighters_This(opponent),Abilities[fighters[opponent].ability]);
				return -1;
			}

			int fail = -1;
			if(fighters[opponent].ability == abilityHyperCutter)
			{
				btlsayf(BT_XsXPreventsStatLoss, fighters_This(opponent),Abilities[fighters[opponent].ability]);
			}
			else if(effect_TooLow(opponent, STAT_ATTACK))
			{
				btlsayf(BT_XsXWontGoLower, fighters_This(opponent), BattleStatNames[STAT_ATTACK]);
			}
			else
			{
				fighters[opponent].stageAttack--;
				btlsayf(BT_XsXX,fighters_This(opponent),BattleStatNames[STAT_ATTACK],BattleStrings[BT_Fell]);
				fail = 0;
			}

			if(effect_TooLow(opponent, STAT_DEFENSE))
			{
				btlsayf(BT_XsXWontGoLower, fighters_This(opponent), BattleStatNames[STAT_DEFENSE]);
			}
			else
			{
				fighters[opponent].stageDefense--;
				btlsayf(BT_XsXX,fighters_This(opponent),BattleStatNames[STAT_DEFENSE],BattleStrings[BT_Fell]);
				fail = 0;
			}

			return fail;
		}
		case 0xCE:
		{
			if(	fighters[attacker].stageDefense == 6 &&
					fighters[attacker].stageSpDef == 6)
			{
				btlsayf(BT_XsStatsWontGoAnyHigher, fighters_This(attacker));
				return -1;
			}

			if(fighters[attacker].stageDefense < 6)
			{
				fighters[attacker].stageDefense++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Rose]);
			}

			if(fighters[attacker].stageSpDef < 6)
			{
				fighters[attacker].stageSpDef++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPDEF], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0xD0:
		{
			if(	fighters[attacker].stageAttack == 6 &&
					fighters[attacker].stageDefense == 6)
			{
				btlsayf(BT_XsStatsWontGoAnyHigher, fighters_This(attacker));
				return -1;
			}

			if(fighters[attacker].stageAttack < 6)
			{
				fighters[attacker].stageAttack++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_ATTACK], BattleStrings[BT_Rose]);
			}

			if(fighters[attacker].stageDefense < 6)
			{
				fighters[attacker].stageDefense++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_DEFENSE], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0xD2:
		{
			if(fighters[attacker].effWaterSport)
			{
				btlsayf(BT_ButItFailed);
				return -1;
			}
			else
			{
				fighters[attacker].effWaterSport = true;
				btlsayf(BT_FiresPowerWasWeakened);
				return 0;
			}
		}
		case 0xD3:
		{
			if(	fighters[attacker].stageSpAtk == 6 &&
					fighters[attacker].stageSpDef == 6)
			{
				btlsayf(BT_XsStatsWontGoAnyHigher, fighters_This(attacker));
				return -1;
			}

			if(fighters[attacker].stageSpAtk < 6)
			{
				fighters[attacker].stageSpAtk++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPATK], BattleStrings[BT_Rose]);
			}

			if(fighters[attacker].stageSpDef < 6)
			{
				fighters[attacker].stageSpDef++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPDEF], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0xD4:
		{
			if(	fighters[attacker].stageAttack == 6 &&
					fighters[attacker].stageSpeed == 6)
			{
				btlsayf(BT_XsStatsWontGoAnyHigher, fighters_This(attacker));
				return -1;
			}

			if(fighters[attacker].stageAttack < 6)
			{
				fighters[attacker].stageAttack++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_ATTACK], BattleStrings[BT_Rose]);
			}

			if(fighters[attacker].stageSpeed < 6)
			{
				fighters[attacker].stageSpeed++;
				btlsayf(BT_XsXX, fighters_This(attacker), BattleStatNames[STAT_SPEED], BattleStrings[BT_Rose]);
			}

			return 0;
		}
		case 0xD5:
		{
			//TODO	Camouflage effect (0xD5)
/*
 envtypes=[
  PBTypes::NORMAL,
  PBTypes::GRASS,
  PBTypes::GRASS,
  PBTypes::WATER,
  PBTypes::WATER,
  PBTypes::WATER,
  PBTypes::ROCK,
  PBTypes::ROCK,
  PBTypes::GROUND
 ]
 type=envtypes[@battle.environment]
 if attacker.pbHasType?(type)
  @battle.pbDisplay("But it failed!")
  return -1
 else
  attacker.type1=type
  attacker.type2=type
  typename=PBTypes.getName(type)
  @battle.pbDisplay("#{attacker.pbThis} transformed into the #{typename} type!")
  return 0
 end
*/
		}
		case 0xF0:
		{
			if(fighters[attacker].effTimeStop)
			{
				btlsayf(BT_ButItFailed);
			}
			else
			{
				btlsays("Toki wo Tomare!");
				fighters[attacker].effTimeStop = 4;
				fighters[attacker].effTimeStopDmg = 0;
			}

			return -1;
		}

		default:
		{
			if(opponent<0)
				return 0;

			int damage = move_CalcDamage(mid, attacker, opponent, 0);
			//damage = move_pbReduceHPDamage(mid, damage, attacker, opponent);
			move_EffectMessages(mid, opponent);
			move_OnDamageLost(damage, mid, attacker, opponent);
			if(fighters[opponent].mon->Status.CurrentHP < damage)
				damage = fighters[opponent].mon->Status.CurrentHP;
			fighters_DrainHP(opponent,damage);
			return damage;
		}
	}
}

int __move_ModifyDamage(int damage, int attacker, int opponent)
{
	return damage;
}

//Can be used to overrule the usual "Foo used Bar" message for specific moves.
int __move_DisplayUseMessage(int mid, int attacker)
{
	//Return values:
	//-1 if the attack should exit as a failure
	//1 if the attack should exit as a success
	//0 if the attack should proceed its effect
	if(mid==moveTimeStop)
	{
		btlsays("Time Stop! THE WORLD!");
		return 0;
	}
 	btlsayf(BT_XUsedX, fighters_This(attacker), moveNames[mid]);
	if(mid == moveLick)
		btlsayf(BT_XIsCreepedOut, fighters_This(fighters_Opposing1(attacker)));

	return 0;
}

//Returns the number of hits for a given attack.
int __move_NumHits(int mid)
{
	switch(moves[mid].effect)
	{
		case 0x1D:
		{
			int hits[] = { 2,2,2,3,3,3,4,5 };
			return hits[rrand(8)];
		}
		case 0x2C:
		case 0x4D:
		{
			return 2;
		}
		case 0x68:
		{
			return 3;
		}

		default:
		{
			return 1;
		}
	}
}

int __move_IsMultiHit(int mid)
{
	return (__move_NumHits(mid) > 1);
}

int __move_TwoTurnAttack(int mid, int attacker)
{
	switch(moves[mid].effect)
	{
		case 0x27:
		case 0x4B:
		case 0x91:
		case 0x97:
		case 0x9B:
		{
			return (fighters[attacker].effTwoTurnAttack==0);
		}

		default:
		{
			return 0;
		}
	}
}

int __move_OnStartUse(int mid, int attacker)
{
	return 1;
}

int __move_MoveFailed(int mid, int attacker, int opponent)
{
	return 0;
}

int __moves_AddTarget(int mid, int * targets, int target)
{
	int tlen = fighters_GetTargetLen(targets);
	if(fighters[target].mon->Status.CurrentHP)
	{
		targets[tlen] = fighters[target].pokemonIndex;
		return true;
	}
	return false;
}
