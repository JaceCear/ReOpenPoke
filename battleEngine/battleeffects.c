//======================================================================
//
//	OpenPoké battle system
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "../openpoke.h"
#include "btlmessages.h"

int effect_CanPoison(int index, int showMessages)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if((fighters_HasType(index, tpPoison)) || (fighters_HasType(index, tpSteel)))
	{
		if(showMessages)
			btlsayf(BT_ItDoesntAffectX, fighters_This(index));
		return false;
	}

	if(fighters[index].mon->Status.AilmentPoison)
	{
		if(showMessages)
			btlsayf(BT_XIsAlreadyPoisoned, fighters_This(index));
		return false;
	}

	if(fighters[index].mon->Status.AilmentPoison)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[index].ability == abilityImmunity)
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsPoisoning, fighters_This(index), Abilities[fighters[index].ability]);
		return false;
	}

	if(fighters[index].effSubstitute)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(sides[fighters_OwnSide(index)].effSafeguard)
	{
		if(showMessages)
			btlsayf(BT_XsPartyIsProtectedBySafeguard, fighters_This(index));
		return false;
	}

	return true;
}

void effect_Sleep(int index, int duration)
{
	if(duration)
		fighters[index].mon->Status.AilmentSleep = 2 + rrand(6);
	else
		fighters[index].mon->Status.AilmentSleep = duration;

	fighters_CancelMoves(index);
}

void effect_Freeze(int index)
{
	fighters[index].mon->Status.AilmentFrozen = 1;
	fighters_CancelMoves(index);
}

void effect_ConfuseSelf(index)
{
	if((fighters[index].effConfusion == 0) && (fighters[index].ability != abilityOwnTempo))
	{
		fighters[index].effConfusion = 2 + rrand(4);
		btlsayf(BT_XBecameConfused, fighters_This(index));
	}
}

int effect_CanPoisonSynchronize(int index, int opponent)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(fighters_HasType(index, tpPoison) || fighters_HasType(index, tpSteel))
	{
		btlsayf(BT_XsXHadNoEffectOnX, fighters_This(opponent), Abilities[abilitySynchronize], fighters_This(index));
		return false;
	}

	if(fighters[index].mon->Status.Ailment)
	{
		btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[opponent].ability == abilityImmunity)
	{
		btlsayf(BT_XsXPreventedXsXFromWorking, fighters_This(index), Abilities[abilityImmunity], fighters_This(opponent), Abilities[abilitySynchronize]);
		return false;
	}

	return true;
}

int effect_CanSleepYawn(int index)
{
	if(fighters[index].ability != abilitySoundproof)
	{
		int i;
		for(i = 0; i < 4; i++)
			if(fighters[i].effUproar)
				return false;
	}

	if((fighters[index].ability == abilityVitalSpirit) || (fighters[index].ability == abilityInsomnia))
		return false;

	if(fighters[index].mon->Status.Ailment)
	{
		btlsayf(BT_ButItFailed);
		return false;
	}

	return true;
}

int effect_CanSleep(int index, int showMessages, int selfsleep)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if((!selfsleep) && (fighters[index].effSubstitute))
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[index].mon->Status.AilmentSleep)
	{
		if(showMessages)
			btlsayf(BT_XIsAlreadyAsleep, fighters_This(index));
		return false;
	}

	if(fighters[index].ability != abilitySoundproof)
	{
		int i;
		for(i = 0; i < 4; i++)
			if(fighters[i].effUproar)
			{
				if(showMessages)
					btlsayf(BT_ButTheUproarKeptXAwake, fighters_This(index));
				return false;
			}
	}

	if((fighters[index].ability == abilityVitalSpirit) || (fighters[index].ability == abilityInsomnia))
	{
		if(showMessages)
			btlsayf(BT_XStayedAwakeUsingItsX, fighters_This(index), Abilities[fighters[index].ability]);
		return false;
	}

	if((!selfsleep) && (fighters[index].mon->Status.Ailment))
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if((!selfsleep) && (sides[fighters_OwnSide(index)].effSafeguard))
	{
		if(showMessages)
			btlsayf(BT_XsPartyIsProtectedBySafeguard, fighters_This(index));
		return false;
	}

	return true;
}

int effect_CanParalyze(int index, int showMessages)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(fighters[index].ability == abilityLimber)
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsParalysis, fighters_This(index), Abilities[fighters[index].ability]);
		return false;
	}

	if(fighters[index].effSubstitute)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[index].mon->Status.AilmentParalysis)
	{
		if(showMessages)
			btlsayf(BT_XIsAlreadyParalyzed, fighters_This(index));
		return false;
	}

	if(sides[fighters_OwnSide(index)].effSafeguard)
	{
		if(showMessages)
			btlsayf(BT_XsPartyIsProtectedBySafeguard, fighters_This(index));
		return false;
	}

	return true;
}

int effect_CanParalyzeSynchronize(int index, int opponent)
{
	if(fighters[opponent].ability == abilityLimber)
	{
		btlsayf(BT_XsXPreventedXsXFromWorking, fighters_This(index), Abilities[abilityLimber], fighters_This(opponent), Abilities[abilitySynchronize]);
		return false;
	}

	if(fighters[index].mon->Status.Ailment)
		return false;

	return true;
}

int effect_CanFreeze(int index, int showMessages)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(	(ThisBattle.weather == WEATHER_SUNNYDAY) ||
			(fighters[index].mon->Status.Ailment) ||
			(sides[fighters_OwnSide(index)].effSafeguard) ||
			(fighters[index].effSubstitute))
		return false;

	return true;
}

int effect_CanConfuse(int index, int showMessages)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(fighters[index].effSubstitute)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[index].ability == abilityOwnTempo)
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsConfusion, fighters_This(index));
		return false;
	}

	if(sides[fighters_OwnSide(index)].effSafeguard)
	{
		if(showMessages)
			btlsayf(BT_XsPartyIsProtectedBySafeguard, fighters_This(index));
		return false;
	}

	if(fighters[index].effConfusion)
	{
		if(showMessages)
			btlsayf(BT_XIsAlreadyConfused, fighters_This(index));
		return false;
	}

	return true;
}

int effect_CanBurn(int index, int showMessages)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(fighters[index].mon->Status.AilmentBurned)
	{
		if(showMessages)
			btlsayf(BT_XAlreadyHasABurn, fighters_This(index));
		return false;
	}

	if(fighters_HasType(index, tpFire))
	{
		if(showMessages)
			btlsayf(BT_ItDoesntAffectX, fighters_This(index));
		return false;
	}

	if(fighters[index].mon->Status.Ailment)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[index].effSubstitute)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[index].ability == abilityWaterveil)
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsBurns, fighters_This(index),Abilities[abilityWaterveil]);
		return false;
	}

	if(sides[fighters_OwnSide(index)].effSafeguard)
	{
		if(showMessages)
			btlsayf(BT_XsPartyIsProtectedBySafeguard, fighters_This(index));
		return false;
	}

	return true;
}

int effect_CanBurnFromFireMove(int index, int mid, int showMessages)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(fighters[index].mon->Status.AilmentBurned)
	{
		if(showMessages)
			btlsayf(BT_XAlreadyHasABurn, fighters_This(index));
		return false;
	}

	if(fighters_HasType(index, tpFire))
	{
		if(showMessages)
			btlsayf(BT_ItDoesntAffectX, fighters_This(index));
		return false;
	}

	if(fighters[index].mon->Status.Ailment)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(fighters[index].effSubstitute)
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if((fighters[index].ability == abilityFlashFire) && (moves[mid].type == tpFire))
	{
		if(!fighters[index].effFlashFire)
		{
			btlsayf(BT_XsXRaisedItsFirePower, fighters_This(index), Abilities[abilityFlashFire]);
			fighters[index].effFlashFire = true;
		} else
		{
			btlsayf(BT_XsXMadeXIneffective, fighters_This(index), Abilities[abilityFlashFire], moveNames[mid]);
		}
		return false;
	}

	if(fighters[index].ability == abilityWaterveil)
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsBurns, fighters_This(index),Abilities[abilityWaterveil]);
		return false;
	}

	if(sides[fighters_OwnSide(index)].effSafeguard)
	{
		if(showMessages)
			btlsayf(BT_XsPartyIsProtectedBySafeguard, fighters_This(index));
		return false;
	}

	return true;
}

int effect_CanBurnSynchronize(int index, int opponent)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(fighters_HasType(index, tpFire))
	{
		btlsayf(BT_XsXHadNoEffectOnX, fighters_This(opponent), Abilities[abilitySynchronize], fighters_This(index));
		return false;
	}

	if(fighters[opponent].ability == abilityWaterveil)
	{
		btlsayf(BT_XsXPreventedXsXFromWorking, fighters_This(index), Abilities[abilityWaterveil], fighters_This(opponent), Abilities[abilitySynchronize]);
		return false;
	}

	if(fighters[index].mon->Status.Ailment)
		return false;

	return true;
}

int effect_CanReduceStatStage(int index, int stat, int showMessages)
{
	if(fighters[index].mon->Status.CurrentHP <= 0)
		return false;

	if(fighters[index].effSubstitute) //Note: not used if move is Tickle
	{
		if(showMessages)
			btlsayf(BT_ButItFailed);
		return false;
	}

	if(sides[fighters_OwnSide(index)].effMist)
	{
		if(showMessages)
			btlsayf(BT_XIsProtectedByMist, fighters_This(index));
		return false;
	}

	if(	(fighters[index].ability == abilityClearBody) ||
			(fighters[index].ability == abilityWhiteSmoke))
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsStatLoss, fighters_This(index), Abilities[fighters[index].ability]);
		return false;
	}

	if((stat == STAT_ATTACK) && (fighters[index].ability == abilityHyperCutter))
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsXLoss, fighters_This(index), Abilities[fighters[index].ability], BattleStatNames[STAT_ATTACK]);
		return false;
	}

	if((stat == STAT_ACCURACY) && (fighters[index].ability == abilityKeenEye))
	{
		if(showMessages)
			btlsayf(BT_XsXPreventsXLoss, fighters_This(index), Abilities[fighters[index].ability], BattleStatNames[STAT_ACCURACY]);
		return false;
	}

	return true;
}

int effect_TooLow(int index, int stat)
{
	if(stat == STAT_ATTACK)
		return (fighters[index].stageAttack == -6);
	if(stat == STAT_DEFENSE)
		return (fighters[index].stageDefense == -6);
	if(stat == STAT_SPEED)
		return (fighters[index].stageSpeed == -6);
	if(stat == STAT_SPATK)
		return (fighters[index].stageSpAtk == -6);
	if(stat == STAT_SPDEF)
		return (fighters[index].stageSpDef == -6);
	if(stat == STAT_ACCURACY)
		return (fighters[index].stageAccuracy == -6);
	if(stat == STAT_EVASIVENESS)
		return (fighters[index].stageEvasiveness == -6);

	return false;
}

int effect_ReduceStat(int index, int stat, int increment, int showMessages)
{
	//TODO	Rework arrStatTexts[] into something that builds up from BattleStrings[]
	const char * const arrStatTexts[] =
	{
		"%s's Attack fell!",
		"%s's Defense fell!",
		"%s's Speed fell!",
		"%s's Special Attack fell!",
		"%s's Special Defense fell!",
		"%s's accuracy fell!",
		"%s's evasiveness fell!",
		"%s's Attack harshly fell!",
		"%s's Defense harshly fell!",
		"%s's Speed harshly fell!",
		"%s's Special Attack harshly fell!",
		"%s's Special Defense harshly fell!",
		"%s's accuracy harshly fell!",
		"%s's evasiveness harshly fell!",
		"%s's Attack won't go lower!",
		"%s's Defense won't go lower!",
		"%s's Speedwon't go lower!",
		"%s's Special Attack won't go lower!",
		"%s's Special Defense won't go lower!",
		"%s's accuracy won't go lower!"
		"%s's evasiveness won't go lower!"
	};

	if(effect_CanReduceStatStage(index,stat,showMessages))
	{
		if(effect_TooLow(index,stat))
		{
			btlsays(arrStatTexts[14+stat],fighters_This(index));
			return false;
		} else
		{
			if(stat == STAT_ATTACK)
				fighters[index].stageAttack -= increment;
			if(stat == STAT_DEFENSE)
				fighters[index].stageDefense -= increment;
			if(stat == STAT_SPEED)
				fighters[index].stageSpeed -= increment;
			if(stat == STAT_SPATK)
				fighters[index].stageSpAtk -= increment;
			if(stat == STAT_SPDEF)
				fighters[index].stageSpDef -= increment;
			if(stat == STAT_ACCURACY)
				fighters[index].stageAccuracy -= increment;
			if(stat == STAT_EVASIVENESS)
				fighters[index].stageEvasiveness -= increment;

			if(fighters[index].stageAttack < -6)
				fighters[index].stageAttack = -6;
			if(fighters[index].stageDefense < -6)
				fighters[index].stageDefense = -6;
			if(fighters[index].stageSpeed < -6)
				fighters[index].stageSpeed = -6;
			if(fighters[index].stageSpAtk < -6)
				fighters[index].stageSpAtk = -6;
			if(fighters[index].stageSpDef < -6)
				fighters[index].stageSpDef = -6;
			if(fighters[index].stageAccuracy < -6)
				fighters[index].stageAccuracy = -6;
			if(fighters[index].stageEvasiveness < -6)
				fighters[index].stageEvasiveness = -6;
			if(increment == 2)
				btlsays(arrStatTexts[7+stat],fighters_This(index));
			else
				btlsays(arrStatTexts[stat],fighters_This(index));

			return true;
		}
	}

	return false;
}

int effect_ReducemovestatStageIntimidate(int index, int opponent)
{
	return false;
/*
  if hp<=0
   return false
  end
  if effects[PBEffects::Substitute]>0
   return false
  end
  if ability==PBAbilities::CLEARBODY||ability==PBAbilities::WHITESMOKE||ability==PBAbilities::HYPERCUTTER
   abilityname=PBAbilities.getName(ability)
   oppabilityname=PBAbilities.getName(opponent.ability)
   @battle.pbDisplay("#{pbThis}'s #{abilityname} prevented #{opponent.pbThis}'s #{oppabilityname} from working!")
   return false
  end
  if pbOwnSide.effects[PBEffects::Mist]>0
   @battle.pbDisplay("#{pbThis} is protected by Mist!")
   return false
  end
  if @stages[PBStats::ATTACK]>-6
   @stages[PBStats::ATTACK]-=1
   oppabilityname=PBAbilities.getName(opponent.ability)
   @battle.pbDisplay("#{opponent.pbThis}'s #{oppabilityname} cuts #{pbThis}'s Attack!")
   return true
  end
  return false
*/
}

