//======================================================================
//
//	OpenPoké battle system
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "../openpoke.h"
#include "btlmessages.h"

int move_TypeModMessages(int mid, int type, int opponent)
{
	if(type < 0)
		return 4;
	if(	(fighters[opponent].ability == abilityFlashFire) &&
		(type == tpFire))
	{
		if(!fighters[opponent].effFlashFire)
		{
			btlsayf(BT_XsXRaisedItsFirePower, fighters_This(opponent), Abilities[fighters[opponent].ability]);
			fighters[opponent].effFlashFire = 1;
		}
		else
		{
			btlsayf(BT_XsXMadeItIneffective, fighters_This(opponent), Abilities[fighters[opponent].ability]);
			return false;
		}
	}
	if( ((fighters[opponent].ability == abilityWaterAbsorb) && (type == tpWater)) ||
		((fighters[opponent].ability == abilityVoltAbsorb) && (type == tpElectric)) )
	{
		int hpgain = fighters[opponent].mon->Status.CurrentHP / 4;
		//hpgain = fighters_pbRecoverHP(hpgain);
		fighters_RestoreHP(opponent, hpgain);

		if(hpgain==0)
			btlsayf(BT_XsXMadeXUseless, fighters_This(opponent), Abilities[fighters[opponent].ability], moveNames[mid]);
		else
			btlsayf(BT_XsXRestoredHealth, fighters_This(opponent), Abilities[fighters[opponent].ability]);

		return false;
	}

	int typemod = move_TypeModifier(mid, type, opponent);
	if(typemod == 0)
		btlsayf(BT_ItDoesntAffectX, fighters_This(opponent));

	return typemod;
}

int move_IsCritical(int mid, int attacker, int opponent)
{
	if(	(fighters[opponent].ability == abilityShellArmor) ||
		(fighters[opponent].ability == abilityBattleArmor) )
		return false;

	int c = 0;
	int ratios[] = { 16, 8, 4, 3, 2 };
	if(fighters[attacker].effFocusEnergy)
		c+=2;
	if(	(moves[mid].effect == 0x2B) ||
		(moves[mid].effect == 0x4B) ||
		(moves[mid].effect == 0xC8) ||
		(moves[mid].effect == 0xD1) )
		c++;

	//Check for Chansey/Luckypunch and Farfetch'd/Stick combo here, worth +2
	//if((fighters[attacker].species == pkCHANSEY) &&
	//Check for Scope Lens here, worth +1
	if(c > 4) c = 4;
	return (rrand(ratios[c]) == 0);
}

int move_IsSpecial(int mid, int type)
{
#ifdef BATTLE_DS_SPECIALS
	return (moves[mid].type & MOV_TOUCH == MOV_TOUCH);
#else
	return (type >= tpNone);
#endif
}

void move_OnDamageLost(int mid, int damage, int attacker, int opponent)
{
	int type = moves[mid].type;

	if(fighters[opponent].effBide)
	{
		fighters[opponent].effBideDamage += damage;
		fighters[opponent].effBideTarget = attacker;
	}

	if(mid == moveHiddenPower)
		type = tpNormal;

	if(move_IsSpecial(mid, type))
	{
		fighters[opponent].effCounter = damage;
		fighters[opponent].effCounterTarget = attacker;
	}
	else
	{
		fighters[opponent].effMirrorCoat = damage;
		fighters[opponent].effMirrorCoatTarget = attacker;
	}

	fighters[opponent].lastHPLost = damage;
	fighters[opponent].lastAttacker = attacker;
}

int move_CalcDamage(int mid, int attacker, int opponent, int options)
{
	fighters[opponent].damagestate.critical = 0;
	fighters[opponent].damagestate.typemod = 0;
	fighters[opponent].damagestate.calcdamage = 0;
	fighters[opponent].damagestate.hplost = 0;

	if(moves[mid].basepower == 0)
		return false;

	if(!(options & CALCDMG_NOCRITICAL))
		fighters[opponent].damagestate.critical = move_IsCritical(mid,attacker,opponent);

	int stagemul[] = { 10,10,10,10,10,10,10,15,20,25,30,35,40 };
	int stagediv[] = { 40,35,30,25,20,15,10,10,10,10,10,10,10 };

	int basedmg = __move_BaseDamage(mid,moves[mid].basepower,attacker,opponent);

	int type;
	if(!(options & CALCDMG_NOTYPES))
		type = moves[mid].type;
	else
		type = -1; //Will be treated as physical

	//Gym Badges
	if(ThisBattle.internalbattle)
	{
		//
	}

	//Stat stages
	int atkstage = fighters[attacker].stageAttack + 6;
	int spatkstage = fighters[attacker].stageSpAtk + 6;
	int defstage = fighters[attacker].stageDefense + 6;
	int spdefstage = fighters[attacker].stageSpDef + 6;
	if(fighters[opponent].damagestate.critical)
	{
		if(atkstage > 6)
			atkstage = 6;
		if(spatkstage > 6)
			spatkstage = 6;
		if(defstage > 6)
			defstage = 6;
		if(spdefstage > 6)
			spdefstage = 6;
	}

	int atk = fighters[attacker].mon->Status.Attack * stagemul[atkstage] / stagediv[atkstage];
	int spatk = fighters[attacker].mon->Status.SpAttack * stagemul[spatkstage] / stagediv[spatkstage];
	int def = fighters[attacker].mon->Status.Defense * stagemul[defstage] / stagediv[defstage];
	int spdef = fighters[attacker].mon->Status.SpDefense * stagemul[spdefstage] / stagediv[spdefstage];

	if(	MonHasAbility(fighters[opponent].mon, abilityMarvelScale) &&
			fighters[opponent].mon->Status.Ailment)
		def = def + (def / 2);

	if(mid == moveSelfdestruct || mid == moveExplosion)
		def >>= 1;

	int speciesA = GetMonsterStats(fighters[attacker].mon, pSpecies);
	int helditemA = GetMonsterStats(fighters[attacker].mon, pHeldItem);
	int speciesO = GetMonsterStats(fighters[opponent].mon, pSpecies);
	int helditemO = GetMonsterStats(fighters[opponent].mon, pHeldItem);

	if(speciesO == pkClamperl && helditemO == itemDeepseaScale)
		spdef <<= 1;

	//TODO -- not in Battle Tower
	if((speciesO == pkLatios || speciesO == pkLatias) && helditemO == itemSoulDew)
		spdef <<= 1;
	if((speciesA == pkLatios || speciesA == pkLatias) && helditemA == itemSoulDew)
		spatk <<= 1;

	if(speciesO == pkDitto && helditemO == itemMetalPowder)
		def <<= 1;

	//Type boosting items
	int modatk = atk * 1.1; //floor
	int modspatk = spatk * 1.1; //floor
	//Check items here
	if(	(helditemA == itemSilkScarf && type == tpNormal) ||
			(helditemA == itemBlackBelt && type == tpFighting) ||
			(helditemA == itemSharpBeak && type == tpFlying) ||
			(helditemA == itemPoisonBarb && type == tpPoison) ||
			(helditemA == itemSoftSand && type == tpGround) ||
			(helditemA == itemHardStone && type == tpRock) ||
			(helditemA == itemSilverPowder && type == tpBug) ||
			(helditemA == itemSpellTag && type == tpGhost) ||
			(helditemA == itemMetalCoat && type == tpSteel))
		atk = modatk;
	if(	(helditemA == itemCharcoal && type == tpFire) ||
			(helditemA == itemMysticWater && type == tpWater) ||
			(helditemA == itemMiracleSeed && type == tpGrass) ||
			(helditemA == itemMagnet && type == tpElectric) ||
			(helditemA == itemTwistedSpoon && type == tpPsychic) ||
			(helditemA == itemNevermeltIce && type == tpIce) ||
			(helditemA == itemDragonFang && type == tpDragon) ||
			(helditemA == itemBlackGlasses && type == tpDark))
		spatk = modspatk;

	//Sea Incense + Water
	//Choice Band

	if(speciesA == pkClamperl && helditemA == itemDeepseaTooth)
		spatk <<= 1;

	if(speciesA == pkPikachu && helditemA == itemLightBall)
		spatk <<= 1;

	if((speciesA == pkCubone || speciesA == pkMarowak) && helditemA == itemThickClub)
		atk <<= 1;

	if(	MonHasAbility(fighters[attacker].mon, abilityHugePower) ||
			MonHasAbility(fighters[attacker].mon, abilityPurePower))
		atk <<= 1;

	if(MonHasAbility(fighters[attacker].mon, abilityHustle))
		atk = atk + (atk / 2);

	if(MonHasAbility(fighters[attacker].mon, abilityGuts) || fighters[attacker].mon->Status.Ailment)
		atk = atk + (atk / 2);

	//Plus
	//Minus

	//Flash Fire + Fire
	if(	MonHasAbility(fighters[attacker].mon, abilityFlashFire) &&
			fighters[attacker].effFlashFire && type == tpFire)
		basedmg = basedmg + (basedmg / 2);

	if(fighters[attacker].mon->Status.CurrentHP <= fighters[attacker].mon->Status.TotalHP / 3)
	{
		int modbasedmg = basedmg + (basedmg / 2);
		if(	(MonHasAbility(fighters[attacker].mon, abilityOvergrow) && type == tpGrass) ||
				(MonHasAbility(fighters[attacker].mon, abilityBlaze) && type == tpFire) ||
				(MonHasAbility(fighters[attacker].mon, abilityTorrent) && type == tpWater) ||
				(MonHasAbility(fighters[attacker].mon, abilitySwarm) && type == tpBug))
			basedmg = modbasedmg;
	}

	//Mud Sport
	//Water Sport

	if(	MonHasAbility(fighters[opponent].mon, abilityThickFat) &&
			(type == tpIce || type == tpFire))
		atk >>= 1;

	//Damage formula
	int defense = def;
	if(move_IsSpecial(mid, type))
	{
		atk = spatk;
		defense = spdef;
	}
	if(defense < 1)
		defense = 1;
	if(atk < 1)
		atk = 1;

	int damage = (((2 * fighters[attacker].mon->Status.Level / 5 + 2) * atk * basedmg / defense) / 50);

	if(moves[mid].target == TGT_ALLOPS)
		damage >>= 1;

	//Weather check
	if(ThisBattle.weather == WEATHER_SUNNYDAY)
	{
		if(type == tpFire)
			damage <<= 1;
		else if(type == tpWater)
			damage >>= 1;
	}
	if(ThisBattle.weather == WEATHER_RAINDANCE)
	{
		if(type == tpFire)
			damage >>= 1;
		else if(type == tpWater)
			damage <<= 1;
	}
	if(	(ThisBattle.weather == WEATHER_SANDSTORM) ||
			(ThisBattle.weather == WEATHER_HAIL) ||
			(ThisBattle.weather == WEATHER_RAINDANCE))
		if(mid == moveSolarBeam)
			damage >>= 1;

	damage += 2;

	if(!(options && CALCDMG_IGNOREPKMNTYPES))
	{
		//Same-Type Attack Bonus
		if(fighters_HasType(attacker,moves[mid].type))
			damage = damage + (damage / 2); //+150%

		//Type Effectiveness (incl. Levitate/Wonder Guard)
		int typemod = move_TypeModMessages(mid, moves[mid].type, opponent);
		damage = (damage * typemod / 4);
		fighters[opponent].damagestate.typemod = typemod;
		if(typemod==0)
		{
			fighters[opponent].damagestate.calcdamage = 0;
			return false;
		}
	}
	else
		fighters[opponent].damagestate.typemod = 4;

	damage = __move_ModifyDamage(damage, attacker, opponent);

	//Helping Hand

	if(	(fighters[attacker].mon->Status.AilmentBurned) &&
			(fighters[attacker].ability != abilityGuts) &&
			(mid != moveFacade))
		damage = damage / 2;

	//Charge
	//…

	//Damage weighting
	if(!(options & CALCDMG_NOWEIGHTING))
	{
		int random = 85 + rrand(16);
		damage = (damage * random / 100);
	}

	if(fighters[opponent].damagestate.critical)
		damage *= 2;

	if(damage < 1)
		damage = 1;

	fighters[opponent].damagestate.calcdamage = damage;
	return damage;
}

void move_EffectMessages(int mid, int opponent)
{
	if(__move_IsMultiHit(mid)) return;
	if(fighters[opponent].damagestate.critical)
		btlsayf(BT_ACriticalHit);

	if(fighters[opponent].damagestate.endured)
		btlsayf(BT_XEnduredTheHit, fighters_This(opponent));
	else if(fighters[opponent].damagestate.focusbandused)
		btlsayf(BT_XHungOnUsingItsX, fighters_This(opponent), items[itemFocusBand].name);

	if((fighters[opponent].damagestate.typemod >= 1) && (fighters[opponent].damagestate.typemod < 4))
		btlsayf(BT_ItsNotVeryEffective);

	if(fighters[opponent].damagestate.typemod > 4)
		btlsayf(BT_ItsSuperEffective);
}

int move_EffectFixedDamage(int mid, int damage, int attacker, int opponent)
{
	int type = moves[mid].type;
	int typemod = move_TypeModMessages(mid, type, opponent);
	fighters[opponent].damagestate.critical = false;
	fighters[opponent].damagestate.typemod = 0;
	fighters[opponent].damagestate.calcdamage = 0;
	fighters[opponent].damagestate.hplost = 0;
	if(typemod != 0)
	{
		fighters[opponent].damagestate.calcdamage = damage;
		fighters[opponent].damagestate.typemod = 4;

		//HP reduced can't be less than 1
		if(damage < 1)
			damage = 1;

		//damage = move_ReduceHPDamage(mid,damage,attacker,opponent);
		move_EffectMessages(mid, opponent);
		move_OnDamageLost(mid,damage,attacker,opponent);
		return damage;
	}
	return 0;
	//	fighters_DrainHP(opponent,damage); ///????
}

//Wrapper for GetTypeAdvantage2
int move_TypeModifier(int mid, int type, int who)
{
	int species = GetMonsterStats(fighters[who].mon, pSpecies);
	int typemod = GetTypeAdvantage2(type, BaseStats[species].Type1, BaseStats[species].Type2);
	return typemod;
}

int move_AccuracyCheck(int mid, int attacker, int opponent)
{
	if((moves[mid].flags & MOV_CHECK) == 0)
		return 1;

	int accuracy = moves[mid].accuracy;
	int stagemul[] = { 33,36,43,50,60,75,100,133,166,200,250,266,300 };

	//OHKO accuracy handled elsewhere
	if((ThisBattle.weather == WEATHER_RAINDANCE) && (mid == moveThunder))
		return 1;

	if((ThisBattle.weather == WEATHER_SUNNYDAY) && (mid == moveThunder))
		accuracy = 50;

	int evasion = fighters[opponent].effForesight ? 0 : fighters[opponent].stageEvasiveness;
	int stage = fighters[attacker].stageAccuracy - evasion;

	if(stage < -6)
		stage = -6;
	if(stage > 6)
		stage = 6;

	accuracy = (accuracy * stagemul[stage+6] /100);

	//Should check with Cearn if this works?
	if(fighters[attacker].ability == abilityCompoundEyes)
		accuracy = (accuracy * 1.3);

	if((ThisBattle.weather == WEATHER_SANDSTORM) && (fighters[opponent].ability == abilitySandVeil))
		accuracy = (accuracy * 4/5);

	int realtype = moves[mid].type;
	if((fighters[attacker].ability == abilityHustle) && (realtype < 9))
		accuracy = (accuracy * 4/5);

	//Bright Powder: accuracy * 90/100
	//Lax Incense: accuracy * 95/100
	return 1 + (rand(100) < accuracy);
}
