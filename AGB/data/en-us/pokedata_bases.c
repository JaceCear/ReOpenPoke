#include "../../openpoke.h"

const aBaseStat BaseStats[] =
{ // HP, Attack, Defense, Speed, Sp.Atk, Sp.Def
	// Types
	// Catch rate, Exp. Yield, Effort, Items
	// Gender, Hatch Steps, Tameness, Gradient, Egg Groups
	// Abilities, Safari, Color
	{ //0 - ??????????
		0, 0, 0, 0, 0, 0,
		tpNormal, tpNormal,
		0, 0, 0x0, 0, 0,
		0, 0, 0, gdMedium, 0, 0,
		0, 0, 0, 0
	},
	{ //1 - Bulbasaur
		45, 49, 49, 45, 65, 65,
		tpGrass, tpPoison,
		45, 64, 0x100, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggPlant,
		abilityOvergrow, 0, 0, 3
	},
	{ //2 - Ivysaur
		60, 62, 63, 60, 80, 80,
		tpGrass, tpPoison,
		45, 141, 0x500, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggPlant,
		abilityOvergrow, 0, 0, 3
	},
	{ //3 - Venusaur
		80, 82, 83, 80, 100, 100,
		tpGrass, tpPoison,
		45, 208, 0x600, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggPlant,
		abilityOvergrow, 0, 0, 3
	},
	{ //4 - Charmander
		39, 52, 43, 65, 60, 50,
		tpFire, tpFire,
		45, 65, 0x40, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggDragon,
		abilityBlaze, 0, 0, 0
	},
	{ //5 - Charmeleon
		58, 64, 58, 80, 80, 65,
		tpFire, tpFire,
		45, 142, 0x140, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggDragon,
		abilityBlaze, 0, 0, 0
	},
	{ //6 - Charizard
		78, 84, 78, 100, 109, 85,
		tpFire, tpFlying,
		45, 209, 0x300, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggDragon,
		abilityBlaze, 0, 0, 0
	},
	{ //7 - Squirtle
		44, 48, 65, 43, 50, 64,
		tpWater, tpWater,
		45, 66, 0x10, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //8 - Wartortle
		59, 63, 80, 58, 65, 80,
		tpWater, tpWater,
		45, 143, 0x410, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //9 - Blastoise
		79, 83, 100, 78, 85, 105,
		tpWater, tpWater,
		45, 210, 0xC00, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //10 - Caterpie
		45, 30, 35, 45, 20, 20,
		tpBug, tpBug,
		255, 53, 0x1, 0, 0,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShieldDust, 0, 0, 3
	},
	{ //11 - Metapod
		50, 20, 55, 30, 25, 25,
		tpBug, tpBug,
		120, 72, 0x20, 0, 0,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShedSkin, 0, 0, 3
	},
	{ //12 - Butterfree
		60, 45, 50, 70, 80, 80,
		tpBug, tpFlying,
		45, 160, 0x600, 0, itemSilverPowder,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityCompoundEyes, 0, 0, 8
	},
	{ //13 - Weedle
		40, 35, 30, 50, 20, 20,
		tpBug, tpPoison,
		255, 52, 0x40, 0, 0,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShieldDust, 0, 0, 5
	},
	{ //14 - Kakuna
		45, 25, 50, 35, 25, 25,
		tpBug, tpPoison,
		120, 71, 0x20, 0, 0,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShedSkin, 0, 0, 2
	},
	{ //15 - Beedrill
		65, 80, 40, 75, 45, 80,
		tpBug, tpPoison,
		45, 159, 0x408, 0, itemPoisonBarb,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilitySwarm, 0, 0, 2
	},
	{ //16 - Pidgey
		40, 45, 40, 56, 35, 35,
		tpNormal, tpFlying,
		255, 55, 0x40, 0, 0,
		127, 15, 70, gdMidSlow, eggFlying, eggFlying,
		abilityKeenEye, 0, 0, 5
	},
	{ //17 - Pidgeotto
		63, 60, 55, 71, 50, 50,
		tpNormal, tpFlying,
		120, 113, 0x80, 0, 0,
		127, 15, 70, gdMidSlow, eggFlying, eggFlying,
		abilityKeenEye, 0, 0, 5
	},
	{ //18 - Pidgeot
		83, 80, 75, 91, 70, 70,
		tpNormal, tpFlying,
		45, 172, 0xC0, 0, 0,
		127, 15, 70, gdMidSlow, eggFlying, eggFlying,
		abilityKeenEye, 0, 0, 5
	},
	{ //19 - Rattata
		30, 56, 35, 72, 25, 35,
		tpNormal, tpNormal,
		255, 57, 0x40, 0, 0,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, abilityGuts, 0, 6
	},
	{ //20 - Raticate
		55, 81, 60, 97, 50, 70,
		tpNormal, tpNormal,
		127, 116, 0x80, itemOrange, itemCitrus,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, abilityGuts, 0, 5
	},
	{ //21 - Spearow
		40, 60, 30, 70, 31, 31,
		tpNormal, tpFlying,
		255, 58, 0x40, 0, 0,
		127, 15, 70, gdMedium, eggFlying, eggFlying,
		abilityKeenEye, 0, 0, 5
	},
	{ //22 - Fearow
		65, 90, 65, 100, 61, 61,
		tpNormal, tpFlying,
		90, 162, 0x80, 0, itemSharpBeak,
		127, 15, 70, gdMedium, eggFlying, eggFlying,
		abilityKeenEye, 0, 0, 5
	},
	{ //23 - Ekans
		35, 60, 44, 55, 40, 54,
		tpPoison, tpPoison,
		255, 62, 0x4, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggDragon,
		abilityIntimidate, abilityShedSkin, 0, 6
	},
	{ //24 - Arbok
		60, 85, 69, 80, 65, 79,
		tpPoison, tpPoison,
		90, 147, 0x8, 0, itemPoisonBarb,
		127, 20, 70, gdMedium, eggGround, eggDragon,
		abilityIntimidate, abilityShedSkin, 0, 6
	},
	{ //25 - Pikachu
		35, 55, 30, 90, 50, 40,
		tpElectric, tpElectric,
		190, 82, 0x80, 0, 0,
		127, 10, 70, gdMedium, eggGround, eggFairy,
		abilityStatic, 0, 0, 2
	},
	{ //26 - Raichu
		60, 90, 55, 100, 90, 80,
		tpElectric, tpElectric,
		75, 122, 0xC0, 0, 0,
		127, 10, 70, gdMedium, eggGround, eggFairy,
		abilityStatic, 0, 0, 2
	},
	{ //27 - Sandshrew
		50, 75, 85, 40, 20, 30,
		tpGround, tpGround,
		255, 93, 0x10, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilitySandVeil, 0, 0, 2
	},
	{ //28 - Sandslash
		75, 100, 110, 65, 45, 55,
		tpGround, tpGround,
		90, 163, 0x20, 0, itemSoftSand,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilitySandVeil, 0, 0, 2
	},
	{ //29 - Nidoran\x8b
		55, 47, 52, 41, 40, 40,
		tpPoison, tpPoison,
		235, 59, 0x1, 0, 0,
		254, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilityPoisonPoint, 0, 50, 1
	},
	{ //30 - Nidorina
		70, 62, 67, 56, 55, 55,
		tpPoison, tpPoison,
		120, 117, 0x2, 0, 0,
		254, 20, 70, gdMidSlow, eggNone, eggNone,
		abilityPoisonPoint, 0, 75, 1
	},
	{ //31 - Nidoqueen
		90, 82, 87, 76, 75, 85,
		tpPoison, tpGround,
		45, 194, 0x3, 0, 0,
		254, 20, 70, gdMidSlow, eggNone, eggNone,
		abilityPoisonPoint, 0, 0, 1
	},
	{ //32 - Nidoran\x8a
		46, 57, 40, 50, 40, 40,
		tpPoison, tpPoison,
		235, 60, 0x4, 0, 0,
		0, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilityPoisonPoint, 0, 50, 6
	},
	{ //33 - Nidorino
		61, 72, 57, 65, 55, 55,
		tpPoison, tpPoison,
		120, 118, 0x8, 0, 0,
		0, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilityPoisonPoint, 0, 75, 6
	},
	{ //34 - Nidoking
		81, 92, 77, 85, 85, 75,
		tpPoison, tpGround,
		45, 195, 0xC, 0, 0,
		0, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilityPoisonPoint, 0, 0, 6
	},
	{ //35 - Clefairy
		70, 45, 48, 35, 60, 65,
		tpNormal, tpNormal,
		150, 68, 0x2, 0, itemMoonStone,
		191, 10, 140, gdQuick, eggFairy, eggFairy,
		abilityCuteCharm, 0, 0, 9
	},
	{ //36 - Clefable
		95, 70, 73, 60, 85, 90,
		tpNormal, tpNormal,
		25, 129, 0x3, 0, itemMoonStone,
		191, 10, 140, gdQuick, eggFairy, eggFairy,
		abilityCuteCharm, 0, 0, 9
	},
	{ //37 - Vulpix
		38, 41, 40, 65, 50, 65,
		tpFire, tpFire,
		190, 63, 0x40, itemStrawberry, 0,
		191, 20, 70, gdMedium, eggGround, eggGround,
		abilityFlashFire, 0, 0, 5
	},
	{ //38 - Ninetales
		73, 76, 75, 100, 81, 100,
		tpFire, tpFire,
		75, 178, 0x440, itemStrawberry, 0,
		191, 20, 70, gdMedium, eggGround, eggGround,
		abilityFlashFire, 0, 0, 2
	},
	{ //39 - Jigglypuff
		115, 45, 20, 20, 45, 25,
		tpNormal, tpNormal,
		170, 76, 0x2, itemOrange, 0,
		191, 10, 70, gdQuick, eggFairy, eggFairy,
		abilityCuteCharm, 0, 0, 9
	},
	{ //40 - Wigglytuff
		140, 70, 45, 45, 75, 50,
		tpNormal, tpNormal,
		50, 109, 0x3, itemOrange, 0,
		191, 10, 70, gdQuick, eggFairy, eggFairy,
		abilityCuteCharm, 0, 0, 9
	},
	{ //41 - Zubat
		40, 45, 35, 55, 30, 40,
		tpPoison, tpFlying,
		255, 54, 0x40, 0, 0,
		127, 15, 70, gdMedium, eggFlying, eggFlying,
		abilityInnerFocus, 0, 0, 6
	},
	{ //42 - Golbat
		75, 80, 70, 90, 65, 75,
		tpPoison, tpFlying,
		90, 171, 0x80, 0, 0,
		127, 15, 70, gdMedium, eggFlying, eggFlying,
		abilityInnerFocus, 0, 0, 6
	},
	{ //43 - Oddish
		45, 50, 55, 30, 75, 65,
		tpGrass, tpPoison,
		255, 78, 0x100, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 1
	},
	{ //44 - Gloom
		60, 65, 70, 40, 85, 75,
		tpGrass, tpPoison,
		120, 132, 0x200, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 1
	},
	{ //45 - Vileplume
		75, 80, 85, 50, 100, 90,
		tpGrass, tpPoison,
		45, 184, 0x300, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 0
	},
	{ //46 - Paras
		35, 70, 55, 25, 45, 55,
		tpBug, tpGrass,
		190, 70, 0x4, itemTinyMushroom, itemBigMushroom,
		127, 20, 70, gdMedium, eggBug, eggPlant,
		abilityEffectSpore, 0, 50, 0
	},
	{ //47 - Parasect
		60, 95, 80, 30, 60, 80,
		tpBug, tpGrass,
		75, 128, 0x18, itemTinyMushroom, itemBigMushroom,
		127, 20, 70, gdMedium, eggBug, eggPlant,
		abilityEffectSpore, 0, 75, 0
	},
	{ //48 - Venonat
		60, 55, 50, 45, 40, 55,
		tpBug, tpPoison,
		190, 75, 0x400, 0, 0,
		127, 20, 70, gdMedium, eggBug, eggBug,
		abilityCompoundEyes, 0, 50, 6
	},
	{ //49 - Venomoth
		70, 65, 60, 90, 90, 75,
		tpBug, tpPoison,
		75, 138, 0x140, 0, itemSilverPowder,
		127, 20, 70, gdMedium, eggBug, eggBug,
		abilityShieldDust, 0, 75, 6
	},
	{ //50 - Diglett
		10, 55, 25, 95, 35, 45,
		tpGround, tpGround,
		255, 81, 0x40, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilitySandVeil, abilityArenaTrap, 0, 5
	},
	{ //51 - Dugtrio
		35, 80, 50, 120, 50, 70,
		tpGround, tpGround,
		50, 153, 0x80, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilitySandVeil, abilityArenaTrap, 0, 5
	},
	{ //52 - Meowth
		40, 45, 35, 90, 40, 40,
		tpNormal, tpNormal,
		255, 69, 0x40, 0, itemNugget,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityPickup, 0, 0, 2
	},
	{ //53 - Persian
		65, 70, 60, 115, 65, 65,
		tpNormal, tpNormal,
		90, 148, 0x80, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityLimber, 0, 0, 2
	},
	{ //54 - Psyduck
		50, 52, 48, 55, 65, 50,
		tpWater, tpWater,
		190, 80, 0x100, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggGround,
		abilityDamp, abilityCloudNine, 50, 2
	},
	{ //55 - Golduck
		80, 82, 78, 85, 95, 80,
		tpWater, tpWater,
		75, 174, 0x200, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggGround,
		abilityDamp, abilityCloudNine, 0, 1
	},
	{ //56 - Mankey
		40, 80, 35, 70, 35, 45,
		tpFighting, tpFighting,
		190, 74, 0x4, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityVitalSpirit, 0, 0, 5
	},
	{ //57 - Primeape
		65, 105, 60, 95, 60, 70,
		tpFighting, tpFighting,
		75, 149, 0x8, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityVitalSpirit, 0, 0, 5
	},
	{ //58 - Growlithe
		55, 70, 45, 60, 70, 50,
		tpFire, tpFire,
		190, 91, 0x4, itemStrawberry, 0,
		63, 20, 70, gdSlow, eggGround, eggGround,
		abilityIntimidate, abilityFlashFire, 0, 5
	},
	{ //59 - Arcanine
		90, 110, 80, 95, 100, 80,
		tpFire, tpFire,
		75, 213, 0x8, itemStrawberry, 0,
		63, 20, 70, gdSlow, eggGround, eggGround,
		abilityIntimidate, abilityFlashFire, 0, 5
	},
	{ //60 - Poliwag
		40, 50, 40, 90, 40, 40,
		tpWater, tpWater,
		255, 77, 0x40, 0, 0,
		127, 20, 70, gdMidSlow, eggWater1, eggWater1,
		abilityWaterAbsorb, abilityDamp, 50, 129
	},
	{ //61 - Poliwhirl
		65, 65, 65, 90, 50, 50,
		tpWater, tpWater,
		120, 131, 0x80, 0, 0,
		127, 20, 70, gdMidSlow, eggWater1, eggWater1,
		abilityWaterAbsorb, abilityDamp, 0, 129
	},
	{ //62 - Poliwrath
		90, 85, 95, 70, 70, 90,
		tpWater, tpFighting,
		45, 185, 0x30, 0, 0,
		127, 20, 70, gdMidSlow, eggWater1, eggWater1,
		abilityWaterAbsorb, abilityDamp, 0, 129
	},
	{ //63 - Abra
		25, 20, 15, 90, 105, 55,
		tpPsychic, tpPsychic,
		200, 73, 0x100, 0, itemTwistedSpoon,
		63, 20, 70, gdMidSlow, eggHuman, eggHuman,
		abilitySynchronize, abilityInnerFocus, 0, 5
	},
	{ //64 - Kadabra
		40, 35, 30, 105, 120, 70,
		tpPsychic, tpPsychic,
		100, 145, 0x200, 0, itemTwistedSpoon,
		63, 20, 70, gdMidSlow, eggHuman, eggHuman,
		abilitySynchronize, abilityInnerFocus, 0, 5
	},
	{ //65 - Alakazam
		55, 50, 45, 120, 135, 85,
		tpPsychic, tpPsychic,
		50, 186, 0x300, 0, itemTwistedSpoon,
		63, 20, 70, gdMidSlow, eggHuman, eggHuman,
		abilitySynchronize, abilityInnerFocus, 0, 5
	},
	{ //66 - Machop
		70, 80, 50, 35, 35, 35,
		tpFighting, tpFighting,
		180, 88, 0x4, 0, 0,
		63, 20, 70, gdMidSlow, eggHuman, eggHuman,
		abilityGuts, 0, 0, 7
	},
	{ //67 - Machoke
		80, 100, 70, 45, 50, 60,
		tpFighting, tpFighting,
		90, 146, 0x8, 0, itemFocusBand,
		63, 20, 70, gdMidSlow, eggHuman, eggHuman,
		abilityGuts, 0, 0, 7
	},
	{ //68 - Machamp
		90, 130, 80, 55, 65, 85,
		tpFighting, tpFighting,
		45, 193, 0xC, 0, itemFocusBand,
		63, 20, 70, gdMidSlow, eggHuman, eggHuman,
		abilityGuts, 0, 0, 7
	},
	{ //69 - Bellsprout
		50, 75, 35, 40, 70, 30,
		tpGrass, tpPoison,
		255, 84, 0x4, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 3
	},
	{ //70 - Weepinbell
		65, 90, 50, 55, 85, 45,
		tpGrass, tpPoison,
		120, 151, 0x8, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 3
	},
	{ //71 - Victreebel
		80, 105, 65, 70, 100, 60,
		tpGrass, tpPoison,
		45, 191, 0xC, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 3
	},
	{ //72 - Tentacool
		40, 40, 35, 70, 50, 100,
		tpWater, tpPoison,
		190, 105, 0x400, 0, 0,
		127, 20, 70, gdSlow, eggWater3, eggWater3,
		abilityClearBody, abilityLiquidOoze, 0, 1
	},
	{ //73 - Tentacruel
		80, 70, 65, 100, 80, 120,
		tpWater, tpPoison,
		60, 205, 0x800, 0, 0,
		127, 20, 70, gdSlow, eggWater3, eggWater3,
		abilityClearBody, abilityLiquidOoze, 0, 1
	},
	{ //74 - Geodude
		40, 80, 100, 20, 30, 30,
		tpRock, tpGround,
		255, 86, 0x10, 0, 0,
		127, 15, 70, gdMidSlow, eggMineral, eggMineral,
		abilityRockHead, abilitySturdy, 0, 5
	},
	{ //75 - Graveler
		55, 95, 115, 35, 45, 45,
		tpRock, tpGround,
		120, 134, 0x20, 0, itemHardStone,
		127, 15, 70, gdMidSlow, eggMineral, eggMineral,
		abilityRockHead, abilitySturdy, 0, 5
	},
	{ //76 - Golem
		80, 110, 130, 45, 55, 65,
		tpRock, tpGround,
		45, 177, 0x30, 0, itemHardStone,
		127, 15, 70, gdMidSlow, eggMineral, eggMineral,
		abilityRockHead, abilitySturdy, 0, 5
	},
	{ //77 - Ponyta
		50, 85, 55, 90, 65, 65,
		tpFire, tpFire,
		190, 152, 0x40, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, abilityFlashFire, 0, 2
	},
	{ //78 - Rapidash
		65, 100, 70, 105, 80, 80,
		tpFire, tpFire,
		60, 192, 0x80, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, abilityFlashFire, 0, 2
	},
	{ //79 - Slowpoke
		90, 65, 65, 15, 40, 40,
		tpWater, tpPsychic,
		190, 99, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggMonster, eggWater1,
		abilityOblivious, abilityOwnTempo, 50, 9
	},
	{ //80 - Slowbro
		95, 75, 110, 30, 100, 80,
		tpWater, tpPsychic,
		75, 164, 0x20, 0, 0,
		127, 20, 70, gdMedium, eggMonster, eggWater1,
		abilityOblivious, abilityOwnTempo, 0, 9
	},
	{ //81 - Magnemite
		25, 35, 70, 45, 95, 55,
		tpElectric, tpSteel,
		190, 89, 0x100, 0, 0,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilityMagnetPull, abilitySturdy, 0, 7
	},
	{ //82 - Magneton
		50, 60, 95, 70, 120, 70,
		tpElectric, tpSteel,
		60, 161, 0x200, 0, itemMagnet,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilityMagnetPull, abilitySturdy, 0, 7
	},
	{ //83 - Farfetch'd
		52, 65, 55, 60, 58, 62,
		tpNormal, tpFlying,
		45, 94, 0x4, 0, itemStick,
		127, 20, 70, gdMedium, eggFlying, eggGround,
		abilityKeenEye, abilityInnerFocus, 0, 5
	},
	{ //84 - Doduo
		35, 85, 45, 75, 35, 35,
		tpNormal, tpFlying,
		190, 96, 0x4, 0, 0,
		127, 20, 70, gdMedium, eggFlying, eggFlying,
		abilityRunaway, abilityEarlyBird, 50, 5
	},
	{ //85 - Dodrio
		60, 110, 70, 100, 60, 60,
		tpNormal, tpFlying,
		45, 158, 0x8, 0, itemSharpBeak,
		127, 20, 70, gdMedium, eggFlying, eggFlying,
		abilityRunaway, abilityEarlyBird, 0, 5
	},
	{ //86 - Seel
		65, 45, 55, 45, 45, 70,
		tpWater, tpWater,
		190, 100, 0x400, itemAsianPear, 0,
		127, 20, 70, gdMedium, eggWater1, eggGround,
		abilityThickFat, 0, 0, 8
	},
	{ //87 - Dewgong
		90, 70, 80, 70, 70, 95,
		tpWater, tpIce,
		75, 176, 0x800, itemAsianPear, itemNevermeltIce,
		127, 20, 70, gdMedium, eggWater1, eggGround,
		abilityThickFat, 0, 0, 8
	},
	{ //88 - Grimer
		80, 80, 50, 25, 40, 50,
		tpPoison, tpPoison,
		190, 90, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggIndeterminate, eggIndeterminate,
		abilityStench, abilityStickyHold, 0, 6
	},
	{ //89 - Muk
		105, 105, 75, 50, 65, 100,
		tpPoison, tpPoison,
		75, 157, 0x5, 0, 0,
		127, 20, 70, gdMedium, eggIndeterminate, eggIndeterminate,
		abilityStench, abilityStickyHold, 0, 6
	},
	{ //90 - Shellder
		30, 65, 100, 40, 45, 25,
		tpWater, tpWater,
		190, 97, 0x10, itemPearl, itemBigPearl,
		127, 20, 70, gdSlow, eggWater3, eggWater3,
		abilityShellArmor, 0, 0, 6
	},
	{ //91 - Cloyster
		50, 95, 180, 70, 85, 45,
		tpWater, tpIce,
		60, 203, 0x20, itemPearl, itemBigPearl,
		127, 20, 70, gdSlow, eggWater3, eggWater3,
		abilityShellArmor, 0, 0, 6
	},
	{ //92 - Gastly
		30, 35, 30, 80, 100, 35,
		tpGhost, tpPoison,
		190, 95, 0x100, 0, 0,
		127, 20, 70, gdMidSlow, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 6
	},
	{ //93 - Haunter
		45, 50, 45, 95, 115, 55,
		tpGhost, tpPoison,
		90, 126, 0x200, 0, itemSpellTag,
		127, 20, 70, gdMidSlow, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 6
	},
	{ //94 - Gengar
		60, 65, 60, 110, 130, 75,
		tpGhost, tpPoison,
		45, 190, 0x300, 0, itemSpellTag,
		127, 20, 70, gdMidSlow, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 6
	},
	{ //95 - Onix
		35, 45, 160, 70, 30, 45,
		tpRock, tpGround,
		45, 108, 0x10, 0, itemHardStone,
		127, 25, 70, gdMedium, eggMineral, eggMineral,
		abilityRockHead, abilitySturdy, 0, 7
	},
	{ //96 - Drowzee
		60, 48, 45, 42, 43, 90,
		tpPsychic, tpPsychic,
		190, 102, 0x400, 0, 0,
		127, 20, 70, gdMedium, eggHuman, eggHuman,
		abilityInsomnia, 0, 0, 2
	},
	{ //97 - Hypno
		85, 73, 70, 67, 73, 115,
		tpPsychic, tpPsychic,
		75, 165, 0x800, 0, 0,
		127, 20, 70, gdMedium, eggHuman, eggHuman,
		abilityInsomnia, 0, 0, 2
	},
	{ //98 - Krabby
		30, 105, 90, 50, 25, 25,
		tpWater, tpWater,
		225, 115, 0x4, 0, 0,
		127, 20, 70, gdMedium, eggWater3, eggWater3,
		abilityHyperCutter, abilityShellArmor, 0, 0
	},
	{ //99 - Kingler
		55, 130, 115, 75, 50, 50,
		tpWater, tpWater,
		60, 206, 0x8, 0, 0,
		127, 20, 70, gdMedium, eggWater3, eggWater3,
		abilityHyperCutter, abilityShellArmor, 0, 128
	},
	{ //100 - Voltorb
		40, 30, 50, 100, 55, 55,
		tpElectric, tpElectric,
		190, 103, 0x40, 0, 0,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilitySoundproof, abilityStatic, 0, 0
	},
	{ //101 - Electrode
		60, 50, 70, 140, 80, 80,
		tpElectric, tpElectric,
		60, 150, 0x80, 0, 0,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilitySoundproof, abilityStatic, 0, 0
	},
	{ //102 - Exeggcute
		60, 40, 80, 40, 60, 45,
		tpGrass, tpPsychic,
		90, 98, 0x10, 0, 0,
		127, 20, 70, gdSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 75, 9
	},
	{ //103 - Exeggutor
		95, 95, 85, 55, 125, 65,
		tpGrass, tpPsychic,
		45, 212, 0x200, 0, 0,
		127, 20, 70, gdSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 2
	},
	{ //104 - Cubone
		50, 50, 95, 35, 40, 50,
		tpGround, tpGround,
		190, 87, 0x10, 0, itemThickClub,
		127, 20, 70, gdMedium, eggMonster, eggMonster,
		abilityRockHead, abilityLightningRod, 0, 5
	},
	{ //105 - Marowak
		60, 80, 110, 45, 50, 80,
		tpGround, tpGround,
		75, 124, 0x20, 0, itemThickClub,
		127, 20, 70, gdMedium, eggMonster, eggMonster,
		abilityRockHead, abilityLightningRod, 0, 5
	},
	{ //106 - Hitmonlee
		50, 120, 53, 87, 35, 110,
		tpFighting, tpFighting,
		45, 139, 0x8, 0, 0,
		0, 25, 70, gdMedium, eggHuman, eggHuman,
		abilityLimber, 0, 0, 5
	},
	{ //107 - Hitmonchan
		50, 105, 79, 76, 35, 110,
		tpFighting, tpFighting,
		45, 140, 0x800, 0, 0,
		0, 25, 70, gdMedium, eggHuman, eggHuman,
		abilityKeenEye, 0, 0, 5
	},
	{ //108 - Lickitung
		90, 55, 75, 30, 60, 75,
		tpNormal, tpNormal,
		45, 127, 0x2, 0, 0,
		127, 20, 70, gdMedium, eggMonster, eggMonster,
		abilityOwnTempo, abilityOblivious, 0, 9
	},
	{ //109 - Koffing
		40, 65, 95, 35, 60, 45,
		tpPoison, tpPoison,
		190, 114, 0x10, 0, 0,
		127, 20, 70, gdMedium, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 6
	},
	{ //110 - Weezing
		65, 90, 120, 60, 85, 70,
		tpPoison, tpPoison,
		60, 173, 0x20, 0, 0,
		127, 20, 70, gdMedium, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 6
	},
	{ //111 - Rhyhorn
		80, 85, 95, 25, 30, 30,
		tpGround, tpRock,
		120, 135, 0x10, 0, 0,
		127, 20, 70, gdSlow, eggMonster, eggGround,
		abilityLightningRod, abilityRockHead, 75, 7
	},
	{ //112 - Rhydon
		105, 130, 120, 40, 45, 45,
		tpGround, tpRock,
		60, 204, 0x8, 0, 0,
		127, 20, 70, gdSlow, eggMonster, eggGround,
		abilityLightningRod, abilityRockHead, 0, 7
	},
	{ //113 - Chansey
		250, 5, 5, 50, 35, 105,
		tpNormal, tpNormal,
		30, 255, 0x2, 0, itemLuckyEgg,
		254, 40, 140, gdQuick, eggFairy, eggFairy,
		abilityNaturalCure, abilitySereneGrace, 125, 9
	},
	{ //114 - Tangela
		65, 55, 115, 60, 100, 40,
		tpGrass, tpGrass,
		45, 166, 0x10, 0, 0,
		127, 20, 70, gdMedium, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 1
	},
	{ //115 - Kangaskhan
		105, 95, 80, 90, 40, 80,
		tpNormal, tpNormal,
		45, 175, 0x2, 0, 0,
		254, 20, 70, gdMedium, eggMonster, eggMonster,
		abilityEarlyBird, 0, 125, 5
	},
	{ //116 - Horsea
		30, 40, 70, 60, 70, 25,
		tpWater, tpWater,
		225, 83, 0x100, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggDragon,
		abilitySwiftswim, 0, 0, 1
	},
	{ //117 - Seadra
		55, 65, 95, 85, 95, 45,
		tpWater, tpWater,
		75, 155, 0x110, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggDragon,
		abilityPoisonPoint, 0, 0, 1
	},
	{ //118 - Goldeen
		45, 67, 60, 63, 35, 50,
		tpWater, tpWater,
		225, 111, 0x4, 0, 0,
		127, 20, 70, gdMedium, eggWater2, eggWater2,
		abilitySwiftswim, abilityWaterveil, 50, 0
	},
	{ //119 - Seaking
		80, 92, 65, 68, 65, 80,
		tpWater, tpWater,
		60, 170, 0x8, 0, 0,
		127, 20, 70, gdMedium, eggWater2, eggWater2,
		abilitySwiftswim, abilityWaterveil, 75, 0
	},
	{ //120 - Staryu
		30, 45, 55, 85, 70, 55,
		tpWater, tpWater,
		225, 106, 0x40, itemStardust, itemStarPiece,
		255, 20, 70, gdSlow, eggWater3, eggWater3,
		abilityIlluminate, abilityNaturalCure, 0, 5
	},
	{ //121 - Starmie
		60, 75, 85, 115, 100, 85,
		tpWater, tpPsychic,
		60, 207, 0x80, itemStardust, itemStarPiece,
		255, 20, 70, gdSlow, eggWater3, eggWater3,
		abilityIlluminate, abilityNaturalCure, 0, 6
	},
	{ //122 - Mr. Mime
		40, 45, 65, 90, 100, 120,
		tpPsychic, tpPsychic,
		45, 136, 0x800, 0, 0,
		127, 25, 70, gdMedium, eggHuman, eggHuman,
		abilitySoundproof, 0, 0, 9
	},
	{ //123 - Scyther
		70, 110, 80, 105, 55, 80,
		tpBug, tpFlying,
		45, 187, 0x4, 0, 0,
		127, 25, 70, gdMedium, eggBug, eggBug,
		abilitySwarm, 0, 125, 3
	},
	{ //124 - Jynx
		65, 50, 35, 95, 115, 95,
		tpIce, tpPsychic,
		45, 137, 0x200, 0, 0,
		254, 25, 70, gdMedium, eggHuman, eggHuman,
		abilityOblivious, 0, 0, 0
	},
	{ //125 - Electabuzz
		65, 83, 57, 105, 95, 85,
		tpElectric, tpElectric,
		45, 156, 0x80, 0, 0,
		63, 25, 70, gdMedium, eggHuman, eggHuman,
		abilityStatic, 0, 0, 130
	},
	{ //126 - Magmar
		65, 95, 57, 93, 100, 85,
		tpFire, tpFire,
		45, 167, 0x200, 0, 0,
		63, 25, 70, gdMedium, eggHuman, eggHuman,
		abilityFlameBody, 0, 0, 0
	},
	{ //127 - Pinsir
		65, 125, 100, 85, 55, 70,
		tpBug, tpBug,
		45, 200, 0x8, 0, 0,
		127, 25, 70, gdSlow, eggBug, eggBug,
		abilityHyperCutter, 0, 125, 5
	},
	{ //128 - Tauros
		75, 100, 95, 110, 40, 70,
		tpNormal, tpNormal,
		45, 211, 0x44, 0, 0,
		0, 20, 70, gdSlow, eggGround, eggGround,
		abilityIntimidate, 0, 125, 5
	},
	{ //129 - Magikarp
		20, 10, 55, 80, 15, 20,
		tpWater, tpWater,
		255, 20, 0x40, 0, 0,
		127, 5, 70, gdSlow, eggWater2, eggDragon,
		abilitySwiftswim, 0, 25, 0
	},
	{ //130 - Gyarados
		95, 125, 79, 81, 60, 100,
		tpWater, tpFlying,
		45, 214, 0x8, 0, 0,
		127, 5, 70, gdSlow, eggWater2, eggDragon,
		abilityIntimidate, 0, 0, 1
	},
	{ //131 - Lapras
		130, 85, 80, 60, 85, 95,
		tpWater, tpIce,
		45, 219, 0x2, 0, 0,
		127, 40, 70, gdSlow, eggMonster, eggWater1,
		abilityWaterAbsorb, abilityShellArmor, 0, 1
	},
	{ //132 - Ditto
		48, 48, 48, 48, 48, 48,
		tpNormal, tpNormal,
		35, 61, 0x1, 0, itemMetalPowder,
		255, 20, 70, gdMedium, eggDitto, eggDitto,
		abilityLimber, 0, 0, 6
	},
	{ //133 - Eevee
		55, 55, 50, 55, 45, 65,
		tpNormal, tpNormal,
		45, 92, 0x400, 0, 0,
		31, 35, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, 0, 0, 5
	},
	{ //134 - Vaporeon
		130, 65, 60, 65, 110, 95,
		tpWater, tpWater,
		45, 196, 0x2, 0, 0,
		31, 35, 70, gdMedium, eggGround, eggGround,
		abilityWaterAbsorb, 0, 0, 1
	},
	{ //135 - Jolteon
		65, 65, 60, 130, 110, 95,
		tpElectric, tpElectric,
		45, 197, 0x80, 0, 0,
		31, 35, 70, gdMedium, eggGround, eggGround,
		abilityVoltAbsorb, 0, 0, 2
	},
	{ //136 - Flareon
		65, 130, 60, 65, 95, 110,
		tpFire, tpFire,
		45, 198, 0x8, 0, 0,
		31, 35, 70, gdMedium, eggGround, eggGround,
		abilityFlashFire, 0, 0, 0
	},
	{ //137 - Porygon
		65, 60, 70, 40, 85, 75,
		tpNormal, tpNormal,
		45, 130, 0x100, 0, 0,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilityTrace, 0, 0, 9
	},
	{ //138 - Omanyte
		35, 40, 100, 35, 90, 55,
		tpRock, tpWater,
		45, 120, 0x10, 0, 0,
		31, 30, 70, gdMedium, eggWater1, eggWater3,
		abilitySwiftswim, abilityShellArmor, 0, 1
	},
	{ //139 - Omastar
		70, 60, 125, 55, 115, 70,
		tpRock, tpWater,
		45, 199, 0x20, 0, 0,
		31, 30, 70, gdMedium, eggWater1, eggWater3,
		abilitySwiftswim, abilityShellArmor, 0, 1
	},
	{ //140 - Kabuto
		30, 80, 90, 55, 55, 45,
		tpRock, tpWater,
		45, 119, 0x10, 0, 0,
		31, 30, 70, gdMedium, eggWater1, eggWater3,
		abilitySwiftswim, abilityBattleArmor, 0, 5
	},
	{ //141 - Kabutops
		60, 115, 105, 80, 65, 70,
		tpRock, tpWater,
		45, 201, 0x8, 0, 0,
		31, 30, 70, gdMedium, eggWater1, eggWater3,
		abilitySwiftswim, abilityBattleArmor, 0, 5
	},
	{ //142 - Aerodactyl
		80, 105, 65, 130, 60, 75,
		tpRock, tpFlying,
		45, 202, 0x80, 0, 0,
		31, 35, 70, gdSlow, eggFlying, eggFlying,
		abilityRockHead, abilityPressure, 0, 6
	},
	{ //143 - Snorlax
		160, 110, 65, 30, 65, 110,
		tpNormal, tpNormal,
		25, 154, 0x2, itemChestnut, itemChestnut,
		31, 40, 70, gdSlow, eggMonster, eggMonster,
		abilityImmunity, abilityThickFat, 0, 4
	},
	{ //144 - Articuno
		90, 85, 100, 85, 95, 125,
		tpIce, tpFlying,
		3, 215, 0xC00, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 1
	},
	{ //145 - Zapdos
		90, 90, 85, 100, 125, 90,
		tpElectric, tpFlying,
		3, 216, 0x300, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 2
	},
	{ //146 - Moltres
		90, 100, 90, 90, 125, 85,
		tpFire, tpFlying,
		3, 217, 0x300, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 2
	},
	{ //147 - Dratini
		41, 64, 45, 50, 50, 50,
		tpDragon, tpDragon,
		45, 67, 0x4, 0, 0,
		127, 40, 35, gdSlow, eggWater1, eggDragon,
		abilityShedSkin, 0, 100, 1
	},
	{ //148 - Dragonair
		61, 84, 65, 70, 70, 70,
		tpDragon, tpDragon,
		45, 144, 0x8, 0, itemDragonFang,
		127, 40, 35, gdSlow, eggWater1, eggDragon,
		abilityShedSkin, 0, 125, 1
	},
	{ //149 - Dragonite
		91, 134, 95, 80, 100, 100,
		tpDragon, tpFlying,
		45, 218, 0xC, 0, itemDragonFang,
		127, 40, 35, gdSlow, eggWater1, eggDragon,
		abilityInnerFocus, 0, 0, 5
	},
	{ //150 - Mewtwo
		106, 110, 90, 130, 154, 90,
		tpPsychic, tpPsychic,
		3, 220, 0x300, 0, 0,
		255, 120, 0, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 6
	},
	{ //151 - Mew
		100, 100, 100, 100, 100, 100,
		tpPsychic, tpPsychic,
		45, 64, 0x3, 0, 0,
		255, 120, 100, gdMidSlow, eggNone, eggNone,
		abilitySynchronize, 0, 0, 9
	},
	{ //152 - Chikorita
		45, 49, 65, 45, 49, 65,
		tpGrass, tpGrass,
		45, 64, 0x400, itemMulberry, itemMulberry,
		31, 20, 70, gdMidSlow, eggMonster, eggPlant,
		abilityOvergrow, 0, 0, 3
	},
	{ //153 - Bayleef
		60, 62, 80, 60, 63, 80,
		tpGrass, tpGrass,
		45, 141, 0x410, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggPlant,
		abilityOvergrow, 0, 0, 3
	},
	{ //154 - Meganium
		80, 82, 100, 80, 83, 100,
		tpGrass, tpGrass,
		45, 208, 0x810, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggPlant,
		abilityOvergrow, 0, 0, 3
	},
	{ //155 - Cyndaquil
		39, 52, 43, 65, 60, 50,
		tpFire, tpFire,
		45, 65, 0x40, 0, 0,
		31, 20, 70, gdMidSlow, eggGround, eggGround,
		abilityBlaze, 0, 0, 2
	},
	{ //156 - Quilava
		58, 64, 58, 80, 80, 65,
		tpFire, tpFire,
		45, 142, 0x140, 0, 0,
		31, 20, 70, gdMidSlow, eggGround, eggGround,
		abilityBlaze, 0, 0, 2
	},
	{ //157 - Typhlosion
		78, 84, 78, 100, 109, 85,
		tpFire, tpFire,
		45, 209, 0x300, 0, 0,
		31, 20, 70, gdMidSlow, eggGround, eggGround,
		abilityBlaze, 0, 0, 2
	},
	{ //158 - Totodile
		50, 65, 64, 43, 44, 48,
		tpWater, tpWater,
		45, 66, 0x4, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //159 - Croconaw
		65, 80, 80, 58, 59, 63,
		tpWater, tpWater,
		45, 143, 0x14, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 129
	},
	{ //160 - Feraligatr
		85, 105, 100, 78, 79, 83,
		tpWater, tpWater,
		45, 210, 0x18, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //161 - Sentret
		35, 46, 34, 20, 35, 45,
		tpNormal, tpNormal,
		255, 57, 0x4, 0, itemOrange,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, abilityKeenEye, 0, 5
	},
	{ //162 - Furret
		85, 76, 64, 90, 45, 55,
		tpNormal, tpNormal,
		90, 116, 0x80, itemOrange, itemCitrus,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, abilityKeenEye, 0, 5
	},
	{ //163 - Hoothoot
		60, 30, 30, 50, 36, 56,
		tpNormal, tpFlying,
		255, 58, 0x1, 0, 0,
		127, 15, 70, gdMedium, eggFlying, eggFlying,
		abilityInsomnia, abilityKeenEye, 0, 5
	},
	{ //164 - Noctowl
		100, 50, 50, 70, 76, 96,
		tpNormal, tpFlying,
		90, 162, 0x2, 0, 0,
		127, 15, 70, gdMedium, eggFlying, eggFlying,
		abilityInsomnia, abilityKeenEye, 0, 5
	},
	{ //165 - Ledyba
		40, 20, 30, 55, 40, 80,
		tpBug, tpFlying,
		255, 54, 0x400, 0, 0,
		127, 15, 70, gdQuick, eggBug, eggBug,
		abilitySwarm, abilityEarlyBird, 0, 0
	},
	{ //166 - Ledian
		55, 35, 50, 85, 55, 110,
		tpBug, tpFlying,
		90, 134, 0x800, 0, 0,
		127, 15, 70, gdQuick, eggBug, eggBug,
		abilitySwarm, abilityEarlyBird, 0, 0
	},
	{ //167 - Spinarak
		40, 60, 40, 30, 40, 40,
		tpBug, tpPoison,
		255, 54, 0x4, 0, 0,
		127, 15, 70, gdQuick, eggBug, eggBug,
		abilitySwarm, abilityInsomnia, 0, 3
	},
	{ //168 - Ariados
		70, 90, 70, 40, 60, 60,
		tpBug, tpPoison,
		90, 134, 0x8, 0, 0,
		127, 15, 70, gdQuick, eggBug, eggBug,
		abilitySwarm, abilityInsomnia, 0, 0
	},
	{ //169 - Crobat
		85, 90, 80, 130, 70, 80,
		tpPoison, tpFlying,
		90, 204, 0xC0, 0, 0,
		127, 15, 70, gdMedium, eggFlying, eggFlying,
		abilityInnerFocus, 0, 0, 6
	},
	{ //170 - Chinchou
		75, 38, 38, 67, 56, 56,
		tpWater, tpElectric,
		190, 90, 0x1, 0, itemYellowShard,
		127, 20, 70, gdSlow, eggWater2, eggWater2,
		abilityVoltAbsorb, abilityIlluminate, 0, 1
	},
	{ //171 - Lanturn
		125, 58, 58, 67, 76, 76,
		tpWater, tpElectric,
		75, 156, 0x2, 0, itemYellowShard,
		127, 20, 70, gdSlow, eggWater2, eggWater2,
		abilityVoltAbsorb, abilityIlluminate, 0, 1
	},
	{ //172 - Pichu
		20, 40, 15, 60, 35, 35,
		tpElectric, tpElectric,
		190, 42, 0x40, 0, 0,
		127, 10, 70, gdMedium, eggNone, eggNone,
		abilityStatic, 0, 0, 2
	},
	{ //173 - Cleffa
		50, 25, 28, 15, 45, 55,
		tpNormal, tpNormal,
		150, 37, 0x400, 0, itemMoonStone,
		191, 10, 140, gdQuick, eggNone, eggNone,
		abilityCuteCharm, 0, 0, 9
	},
	{ //174 - Igglybuff
		90, 30, 15, 15, 40, 20,
		tpNormal, tpNormal,
		170, 39, 0x1, itemOrange, 0,
		191, 10, 70, gdQuick, eggNone, eggNone,
		abilityCuteCharm, 0, 0, 137
	},
	{ //175 - Togepi
		35, 20, 65, 20, 40, 65,
		tpNormal, tpNormal,
		190, 74, 0x400, 0, 0,
		31, 10, 70, gdQuick, eggNone, eggNone,
		abilityHustle, abilitySereneGrace, 0, 8
	},
	{ //176 - Togetic
		55, 40, 85, 40, 80, 105,
		tpNormal, tpFlying,
		75, 114, 0x800, 0, 0,
		31, 10, 70, gdQuick, eggFlying, eggFairy,
		abilityHustle, abilitySereneGrace, 0, 8
	},
	{ //177 - Natu
		40, 50, 45, 70, 70, 45,
		tpPsychic, tpFlying,
		190, 73, 0x100, 0, 0,
		127, 20, 70, gdMedium, eggFlying, eggFlying,
		abilitySynchronize, abilityEarlyBird, 0, 3
	},
	{ //178 - Xatu
		65, 75, 70, 95, 95, 70,
		tpPsychic, tpFlying,
		75, 171, 0x140, 0, 0,
		127, 20, 70, gdMedium, eggFlying, eggFlying,
		abilitySynchronize, abilityEarlyBird, 0, 3
	},
	{ //179 - Mareep
		55, 40, 40, 35, 65, 45,
		tpElectric, tpElectric,
		235, 59, 0x100, 0, 0,
		127, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilityStatic, 0, 0, 8
	},
	{ //180 - Flaaffy
		70, 55, 55, 45, 80, 60,
		tpElectric, tpElectric,
		120, 117, 0x200, 0, 0,
		127, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilityStatic, 0, 0, 9
	},
	{ //181 - Ampharos
		90, 75, 75, 55, 115, 90,
		tpElectric, tpElectric,
		45, 194, 0x300, 0, 0,
		127, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilityStatic, 0, 0, 2
	},
	{ //182 - Bellossom
		75, 80, 85, 50, 90, 100,
		tpGrass, tpGrass,
		45, 184, 0xC00, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 3
	},
	{ //183 - Marill
		70, 20, 50, 40, 20, 50,
		tpWater, tpWater,
		190, 58, 0x2, 0, 0,
		127, 10, 70, gdQuick, eggWater1, eggFairy,
		abilityThickFat, abilityHugePower, 0, 1
	},
	{ //184 - Azumarill
		100, 50, 80, 50, 50, 80,
		tpWater, tpWater,
		75, 153, 0x3, 0, 0,
		127, 10, 70, gdQuick, eggWater1, eggFairy,
		abilityThickFat, abilityHugePower, 0, 1
	},
	{ //185 - Sudowoodo
		70, 100, 115, 30, 30, 65,
		tpRock, tpRock,
		65, 135, 0x20, 0, 0,
		127, 20, 70, gdMedium, eggMineral, eggMineral,
		abilitySturdy, abilityRockHead, 0, 5
	},
	{ //186 - Politoed
		90, 75, 75, 70, 90, 100,
		tpWater, tpWater,
		45, 185, 0xC00, 0, itemKingsRock,
		127, 20, 70, gdMidSlow, eggWater1, eggWater1,
		abilityWaterAbsorb, abilityDamp, 0, 131
	},
	{ //187 - Hoppip
		35, 35, 40, 50, 35, 55,
		tpGrass, tpFlying,
		255, 74, 0x400, 0, 0,
		127, 20, 70, gdMidSlow, eggFairy, eggPlant,
		abilityChlorophyll, 0, 0, 9
	},
	{ //188 - Skiploom
		55, 45, 50, 80, 45, 65,
		tpGrass, tpFlying,
		120, 136, 0x80, 0, 0,
		127, 20, 70, gdMidSlow, eggFairy, eggPlant,
		abilityChlorophyll, 0, 0, 3
	},
	{ //189 - Jumpluff
		75, 55, 70, 110, 55, 85,
		tpGrass, tpFlying,
		45, 176, 0xC0, 0, 0,
		127, 20, 70, gdMidSlow, eggFairy, eggPlant,
		abilityChlorophyll, 0, 0, 1
	},
	{ //190 - Aipom
		55, 70, 55, 85, 40, 55,
		tpNormal, tpNormal,
		45, 94, 0x40, 0, 0,
		127, 20, 70, gdQuick, eggGround, eggGround,
		abilityRunaway, abilityPickup, 0, 6
	},
	{ //191 - Sunkern
		30, 30, 30, 30, 30, 30,
		tpGrass, tpGrass,
		235, 52, 0x100, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 2
	},
	{ //192 - Sunflora
		75, 75, 55, 30, 105, 85,
		tpGrass, tpGrass,
		120, 146, 0x200, 0, 0,
		127, 20, 70, gdMidSlow, eggPlant, eggPlant,
		abilityChlorophyll, 0, 0, 2
	},
	{ //193 - Yanma
		65, 65, 45, 95, 75, 45,
		tpBug, tpFlying,
		75, 147, 0x80, 0, 0,
		127, 20, 70, gdMedium, eggBug, eggBug,
		abilitySpeedBoost, abilityCompoundEyes, 0, 0
	},
	{ //194 - Wooper
		55, 45, 45, 15, 25, 25,
		tpWater, tpGround,
		255, 52, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggGround,
		abilityDamp, abilityWaterAbsorb, 0, 1
	},
	{ //195 - Quagsire
		95, 85, 85, 35, 65, 65,
		tpWater, tpGround,
		90, 137, 0x2, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggGround,
		abilityDamp, abilityWaterAbsorb, 0, 1
	},
	{ //196 - Espeon
		65, 65, 60, 110, 130, 95,
		tpPsychic, tpPsychic,
		45, 197, 0x200, 0, 0,
		31, 35, 70, gdMedium, eggGround, eggGround,
		abilitySynchronize, 0, 0, 6
	},
	{ //197 - Umbreon
		95, 65, 110, 65, 60, 130,
		tpDark, tpDark,
		45, 197, 0x800, 0, 0,
		31, 35, 35, gdMedium, eggGround, eggGround,
		abilitySynchronize, 0, 0, 4
	},
	{ //198 - Murkrow
		60, 85, 42, 91, 85, 42,
		tpDark, tpFlying,
		30, 107, 0x40, 0, 0,
		127, 20, 35, gdMidSlow, eggFlying, eggFlying,
		abilityInsomnia, 0, 0, 4
	},
	{ //199 - Slowking
		95, 75, 80, 30, 100, 110,
		tpWater, tpPsychic,
		70, 164, 0xC00, 0, itemKingsRock,
		127, 20, 70, gdMedium, eggMonster, eggWater1,
		abilityOblivious, abilityOwnTempo, 0, 9
	},
	{ //200 - Misdreavus
		60, 60, 60, 85, 85, 85,
		tpGhost, tpGhost,
		45, 147, 0x500, 0, itemSpellTag,
		127, 25, 35, gdQuick, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 7
	},
	{ //201 - Unown
		48, 72, 48, 48, 72, 48,
		tpPsychic, tpPsychic,
		225, 61, 0x104, 0, 0,
		255, 40, 70, gdMedium, eggNone, eggNone,
		abilityLevitate, 0, 0, 132
	},
	{ //202 - Wobbuffet
		190, 33, 58, 33, 33, 58,
		tpPsychic, tpPsychic,
		45, 177, 0x2, 0, 0,
		127, 20, 70, gdMedium, eggIndeterminate, eggIndeterminate,
		abilityShadowTag, 0, 0, 1
	},
	{ //203 - Girafarig
		70, 80, 65, 85, 90, 65,
		tpNormal, tpPsychic,
		60, 149, 0x200, 0, itemPersimmon,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityInnerFocus, abilityEarlyBird, 0, 2
	},
	{ //204 - Pineco
		50, 65, 90, 15, 35, 35,
		tpBug, tpBug,
		190, 60, 0x10, 0, 0,
		127, 20, 70, gdMedium, eggBug, eggBug,
		abilitySturdy, 0, 0, 7
	},
	{ //205 - Forretress
		75, 90, 140, 40, 60, 60,
		tpBug, tpSteel,
		75, 118, 0x20, 0, 0,
		127, 20, 70, gdMedium, eggBug, eggBug,
		abilitySturdy, 0, 0, 6
	},
	{ //206 - Dunsparce
		100, 70, 70, 45, 65, 65,
		tpNormal, tpNormal,
		190, 75, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilitySereneGrace, abilityRunaway, 0, 2
	},
	{ //207 - Gligar
		65, 75, 105, 85, 35, 65,
		tpGround, tpFlying,
		60, 108, 0x10, 0, 0,
		127, 20, 70, gdMidSlow, eggBug, eggBug,
		abilityHyperCutter, abilitySandVeil, 0, 6
	},
	{ //208 - Steelix
		75, 85, 200, 30, 55, 65,
		tpSteel, tpGround,
		25, 196, 0x20, 0, itemMetalCoat,
		127, 25, 70, gdMedium, eggMineral, eggMineral,
		abilityRockHead, abilitySturdy, 0, 7
	},
	{ //209 - Snubbull
		60, 80, 50, 30, 40, 40,
		tpNormal, tpNormal,
		190, 63, 0x4, 0, 0,
		191, 20, 70, gdQuick, eggGround, eggFairy,
		abilityIntimidate, abilityRunaway, 0, 9
	},
	{ //210 - Granbull
		90, 120, 75, 45, 60, 60,
		tpNormal, tpNormal,
		75, 178, 0x8, 0, 0,
		191, 20, 70, gdQuick, eggGround, eggFairy,
		abilityIntimidate, abilityIntimidate, 0, 6
	},
	{ //211 - Qwilfish
		65, 95, 75, 85, 55, 55,
		tpWater, tpPoison,
		45, 100, 0x4, 0, 0,
		127, 20, 70, gdMedium, eggWater2, eggWater2,
		abilityPoisonPoint, abilitySwiftswim, 0, 7
	},
	{ //212 - Scizor
		70, 130, 100, 65, 55, 80,
		tpBug, tpSteel,
		25, 200, 0x8, 0, 0,
		127, 25, 70, gdMedium, eggBug, eggBug,
		abilitySwarm, 0, 0, 0
	},
	{ //213 - Shuckle
		20, 10, 230, 5, 10, 230,
		tpBug, tpRock,
		190, 80, 0x410, itemBerryJuice, itemBerryJuice,
		127, 20, 70, gdMidSlow, eggBug, eggBug,
		abilitySturdy, 0, 0, 2
	},
	{ //214 - Heracross
		80, 125, 75, 85, 40, 95,
		tpBug, tpFighting,
		45, 200, 0x8, 0, 0,
		127, 25, 70, gdSlow, eggBug, eggBug,
		abilitySwarm, abilityGuts, 0, 1
	},
	{ //215 - Sneasel
		55, 95, 55, 115, 35, 75,
		tpDark, tpIce,
		60, 132, 0x40, 0, 0,
		127, 20, 35, gdMidSlow, eggGround, eggGround,
		abilityInnerFocus, abilityKeenEye, 0, 132
	},
	{ //216 - Teddiursa
		60, 80, 50, 40, 50, 50,
		tpNormal, tpNormal,
		120, 124, 0x4, itemOrange, itemCitrus,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityPickup, 0, 0, 133
	},
	{ //217 - Ursaring
		90, 130, 75, 55, 75, 75,
		tpNormal, tpNormal,
		60, 189, 0x8, itemOrange, itemCitrus,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityGuts, 0, 0, 5
	},
	{ //218 - Slugma
		40, 40, 40, 20, 70, 40,
		tpFire, tpFire,
		190, 78, 0x100, 0, 0,
		127, 20, 70, gdMedium, eggIndeterminate, eggIndeterminate,
		abilityMagmaArmor, abilityFlameBody, 0, 0
	},
	{ //219 - Magcargo
		50, 50, 120, 30, 80, 80,
		tpFire, tpRock,
		75, 154, 0x20, 0, 0,
		127, 20, 70, gdMedium, eggIndeterminate, eggIndeterminate,
		abilityMagmaArmor, abilityFlameBody, 0, 0
	},
	{ //220 - Swinub
		50, 50, 40, 50, 30, 30,
		tpIce, tpGround,
		225, 78, 0x4, itemAsianPear, 0,
		127, 20, 70, gdSlow, eggGround, eggGround,
		abilityOblivious, 0, 0, 5
	},
	{ //221 - Piloswine
		100, 100, 80, 50, 60, 60,
		tpIce, tpGround,
		75, 160, 0x5, itemAsianPear, itemNevermeltIce,
		127, 20, 70, gdSlow, eggGround, eggGround,
		abilityOblivious, 0, 0, 5
	},
	{ //222 - Corsola
		55, 55, 85, 35, 65, 85,
		tpWater, tpRock,
		60, 113, 0x410, 0, itemRedShard,
		191, 20, 70, gdQuick, eggWater1, eggWater3,
		abilityHustle, abilityNaturalCure, 0, 9
	},
	{ //223 - Remoraid
		35, 65, 35, 65, 65, 35,
		tpWater, tpWater,
		190, 78, 0x100, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggWater2,
		abilityHustle, 0, 0, 7
	},
	{ //224 - Octillery
		75, 105, 75, 45, 105, 75,
		tpWater, tpWater,
		75, 164, 0x104, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggWater2,
		abilitySuctionCups, 0, 0, 0
	},
	{ //225 - Delibird
		45, 55, 45, 75, 65, 45,
		tpIce, tpFlying,
		45, 183, 0x40, 0, 0,
		127, 20, 70, gdQuick, eggWater1, eggGround,
		abilityVitalSpirit, abilityHustle, 0, 0
	},
	{ //226 - Mantine
		65, 40, 70, 70, 80, 140,
		tpWater, tpFlying,
		25, 168, 0x800, 0, 0,
		127, 25, 70, gdSlow, eggWater1, eggWater1,
		abilitySwiftswim, abilityWaterAbsorb, 0, 6
	},
	{ //227 - Skarmory
		65, 80, 140, 70, 40, 70,
		tpSteel, tpFlying,
		25, 168, 0x20, 0, itemSharpBeak,
		127, 25, 70, gdSlow, eggFlying, eggFlying,
		abilityKeenEye, abilitySturdy, 0, 7
	},
	{ //228 - Houndour
		45, 60, 30, 65, 80, 50,
		tpDark, tpFire,
		120, 114, 0x100, 0, 0,
		127, 20, 35, gdSlow, eggGround, eggGround,
		abilityEarlyBird, abilityFlashFire, 0, 4
	},
	{ //229 - Houndoom
		75, 90, 50, 95, 110, 80,
		tpDark, tpFire,
		45, 204, 0x200, 0, 0,
		127, 20, 35, gdSlow, eggGround, eggGround,
		abilityEarlyBird, abilityFlashFire, 0, 4
	},
	{ //230 - Kingdra
		75, 95, 95, 85, 95, 95,
		tpWater, tpDragon,
		45, 207, 0x504, 0, itemDragonScale,
		127, 20, 70, gdMedium, eggWater1, eggDragon,
		abilitySwiftswim, 0, 0, 1
	},
	{ //231 - Phanpy
		90, 60, 60, 40, 40, 40,
		tpGround, tpGround,
		120, 124, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityPickup, 0, 0, 1
	},
	{ //232 - Donphan
		90, 120, 120, 50, 60, 60,
		tpGround, tpGround,
		60, 189, 0x14, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilitySturdy, 0, 0, 7
	},
	{ //233 - Porygon2
		85, 80, 90, 60, 105, 95,
		tpNormal, tpNormal,
		45, 180, 0x200, itemUpgrade, itemUpgrade,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilityTrace, 0, 0, 0
	},
	{ //234 - Stantler
		73, 95, 62, 85, 85, 65,
		tpNormal, tpNormal,
		45, 165, 0x4, 0, 0,
		127, 20, 70, gdSlow, eggGround, eggGround,
		abilityIntimidate, 0, 0, 5
	},
	{ //235 - Smeargle
		55, 20, 35, 75, 20, 45,
		tpNormal, tpNormal,
		45, 106, 0x40, 0, 0,
		127, 20, 70, gdQuick, eggGround, eggGround,
		abilityOwnTempo, 0, 0, 8
	},
	{ //236 - Tyrogue
		35, 35, 35, 35, 35, 35,
		tpFighting, tpFighting,
		75, 91, 0x4, 0, 0,
		0, 25, 70, gdMedium, eggNone, eggNone,
		abilityGuts, 0, 0, 6
	},
	{ //237 - Hitmontop
		50, 95, 95, 70, 35, 110,
		tpFighting, tpFighting,
		45, 138, 0x800, 0, 0,
		0, 25, 70, gdMedium, eggHuman, eggHuman,
		abilityIntimidate, 0, 0, 5
	},
	{ //238 - Smoochum
		45, 30, 15, 65, 85, 65,
		tpIce, tpPsychic,
		45, 87, 0x100, 0, 0,
		254, 25, 70, gdMedium, eggNone, eggNone,
		abilityOblivious, 0, 0, 9
	},
	{ //239 - Elekid
		45, 63, 37, 95, 65, 55,
		tpElectric, tpElectric,
		45, 106, 0x40, 0, 0,
		63, 25, 70, gdMedium, eggNone, eggNone,
		abilityStatic, 0, 0, 130
	},
	{ //240 - Magby
		45, 75, 37, 83, 70, 55,
		tpFire, tpFire,
		45, 117, 0x40, 0, 0,
		63, 25, 70, gdMedium, eggNone, eggNone,
		abilityFlameBody, 0, 0, 0
	},
	{ //241 - Miltank
		95, 80, 105, 100, 40, 70,
		tpNormal, tpNormal,
		45, 200, 0x20, itemMooMooMilk, itemMooMooMilk,
		254, 20, 70, gdSlow, eggGround, eggGround,
		abilityThickFat, 0, 0, 9
	},
	{ //242 - Blissey
		255, 10, 10, 55, 75, 135,
		tpNormal, tpNormal,
		30, 255, 0x2, 0, itemLuckyEgg,
		254, 40, 140, gdQuick, eggFairy, eggFairy,
		abilityNaturalCure, abilitySereneGrace, 0, 9
	},
	{ //243 - Raikou
		90, 85, 75, 115, 115, 100,
		tpElectric, tpElectric,
		3, 216, 0x180, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 2
	},
	{ //244 - Entei
		115, 115, 85, 100, 90, 75,
		tpFire, tpFire,
		3, 217, 0x9, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 5
	},
	{ //245 - Suicune
		100, 75, 115, 85, 90, 115,
		tpWater, tpWater,
		3, 215, 0x810, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 1
	},
	{ //246 - Larvitar
		50, 64, 50, 41, 45, 50,
		tpRock, tpGround,
		45, 67, 0x4, 0, 0,
		127, 40, 35, gdSlow, eggMonster, eggMonster,
		abilityGuts, 0, 0, 3
	},
	{ //247 - Pupitar
		70, 84, 70, 51, 65, 70,
		tpRock, tpGround,
		45, 144, 0x8, 0, 0,
		127, 40, 35, gdSlow, eggMonster, eggMonster,
		abilityShedSkin, 0, 0, 7
	},
	{ //248 - Tyranitar
		100, 134, 110, 61, 95, 100,
		tpRock, tpDark,
		45, 218, 0xC, 0, 0,
		127, 40, 35, gdSlow, eggMonster, eggMonster,
		abilitySandStream, 0, 0, 3
	},
	{ //249 - Lugia
		106, 90, 130, 110, 90, 154,
		tpPsychic, tpFlying,
		3, 220, 0xC00, 0, 0,
		255, 120, 0, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 8
	},
	{ //250 - Ho-oh
		106, 130, 90, 90, 110, 154,
		tpFire, tpFlying,
		3, 220, 0xC00, 0, 0,
		255, 120, 0, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 0
	},
	{ //251 - Celebi
		100, 100, 100, 100, 100, 100,
		tpPsychic, tpGrass,
		45, 64, 0x3, itemMulberry, itemMulberry,
		255, 120, 100, gdMidSlow, eggNone, eggNone,
		abilityNaturalCure, 0, 0, 3
	},
	{ //277 - Treecko
		40, 45, 35, 70, 65, 55,
		tpGrass, tpGrass,
		45, 65, 0x40, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggDragon,
		abilityOvergrow, 0, 0, 3
	},
	{ //278 - Grovyle
		50, 65, 45, 95, 85, 65,
		tpGrass, tpGrass,
		45, 141, 0x80, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggDragon,
		abilityOvergrow, 0, 0, 3
	},
	{ //279 - Sceptile
		70, 85, 65, 120, 105, 85,
		tpGrass, tpGrass,
		45, 208, 0xC0, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggDragon,
		abilityOvergrow, 0, 0, 3
	},
	{ //280 - Torchic
		45, 60, 40, 45, 70, 50,
		tpFire, tpFire,
		45, 65, 0x100, 0, 0,
		31, 20, 70, gdMidSlow, eggGround, eggGround,
		abilityBlaze, 0, 0, 0
	},
	{ //281 - Combusken
		60, 85, 60, 55, 85, 60,
		tpFire, tpFighting,
		45, 142, 0x104, 0, 0,
		31, 20, 70, gdMidSlow, eggGround, eggGround,
		abilityBlaze, 0, 0, 0
	},
	{ //282 - Blaziken
		80, 120, 70, 80, 110, 70,
		tpFire, tpFighting,
		45, 209, 0xC, 0, 0,
		31, 20, 70, gdMidSlow, eggGround, eggGround,
		abilityBlaze, 0, 0, 0
	},
	{ //283 - Mudkip
		50, 70, 50, 40, 50, 50,
		tpWater, tpWater,
		45, 65, 0x4, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //284 - Marshtomp
		70, 85, 70, 50, 60, 70,
		tpWater, tpGround,
		45, 143, 0x8, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //285 - Swampert
		100, 110, 90, 60, 85, 90,
		tpWater, tpGround,
		45, 210, 0xC, 0, 0,
		31, 20, 70, gdMidSlow, eggMonster, eggWater1,
		abilityTorrent, 0, 0, 1
	},
	{ //286 - Poochyena
		35, 55, 35, 35, 30, 30,
		tpDark, tpDark,
		255, 55, 0x4, 0, itemPeach,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityRunaway, 0, 0, 7
	},
	{ //287 - Mightyena
		70, 90, 70, 70, 60, 60,
		tpDark, tpDark,
		127, 128, 0x8, 0, itemPeach,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityIntimidate, 0, 0, 7
	},
	{ //288 - Zigzagoon
		38, 30, 41, 60, 30, 41,
		tpNormal, tpNormal,
		255, 60, 0x40, 0, itemOrange,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityPickup, 0, 0, 5
	},
	{ //289 - Linoone
		78, 70, 61, 100, 50, 61,
		tpNormal, tpNormal,
		90, 128, 0x80, itemOrange, itemCitrus,
		127, 15, 70, gdMedium, eggGround, eggGround,
		abilityPickup, 0, 0, 8
	},
	{ //290 - Wurmple
		45, 45, 35, 20, 20, 30,
		tpBug, tpBug,
		255, 54, 0x1, 0, 0,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShieldDust, 0, 0, 0
	},
	{ //291 - Silcoon
		50, 35, 55, 15, 25, 25,
		tpBug, tpBug,
		120, 71, 0x20, 0, 0,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShedSkin, 0, 0, 8
	},
	{ //292 - Beautifly
		60, 70, 50, 65, 90, 50,
		tpBug, tpFlying,
		45, 161, 0x300, 0, itemSilverPowder,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilitySwarm, 0, 0, 2
	},
	{ //293 - Cascoon
		50, 35, 55, 15, 25, 25,
		tpBug, tpBug,
		120, 72, 0x20, 0, 0,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShedSkin, 0, 0, 6
	},
	{ //294 - Dustox
		60, 50, 70, 65, 50, 90,
		tpBug, tpPoison,
		45, 160, 0xC00, 0, itemSilverPowder,
		127, 15, 70, gdMedium, eggBug, eggBug,
		abilityShieldDust, 0, 0, 3
	},
	{ //295 - Lotad
		40, 30, 30, 30, 40, 50,
		tpWater, tpGrass,
		255, 74, 0x400, 0, 0,
		127, 15, 70, gdMidSlow, eggWater1, eggPlant,
		abilitySwiftswim, abilityRainDish, 0, 3
	},
	{ //296 - Lombre
		60, 50, 50, 50, 60, 70,
		tpWater, tpGrass,
		120, 141, 0x800, 0, 0,
		127, 15, 70, gdMidSlow, eggWater1, eggPlant,
		abilitySwiftswim, abilityRainDish, 0, 3
	},
	{ //297 - Ludicolo
		80, 70, 70, 70, 90, 100,
		tpWater, tpGrass,
		45, 181, 0xC00, 0, 0,
		127, 15, 70, gdMidSlow, eggWater1, eggPlant,
		abilitySwiftswim, abilityRainDish, 0, 3
	},
	{ //298 - Seedot
		40, 40, 50, 30, 30, 30,
		tpGrass, tpGrass,
		255, 74, 0x10, 0, 0,
		127, 15, 70, gdMidSlow, eggGround, eggPlant,
		abilityChlorophyll, abilityEarlyBird, 0, 5
	},
	{ //299 - Nuzleaf
		70, 70, 40, 60, 60, 40,
		tpGrass, tpDark,
		120, 141, 0x8, 0, 0,
		127, 15, 70, gdMidSlow, eggGround, eggPlant,
		abilityChlorophyll, abilityEarlyBird, 0, 5
	},
	{ //300 - Shiftry
		90, 100, 60, 80, 90, 60,
		tpGrass, tpDark,
		45, 181, 0xC, 0, 0,
		127, 15, 70, gdMidSlow, eggGround, eggPlant,
		abilityChlorophyll, abilityEarlyBird, 0, 5
	},
	{ //301 - Nincada
		31, 45, 90, 40, 30, 30,
		tpBug, tpGround,
		255, 65, 0x10, 0, 0,
		127, 15, 70, gdFlux, eggBug, eggBug,
		abilityCompoundEyes, 0, 0, 7
	},
	{ //302 - Ninjask
		61, 90, 45, 160, 50, 50,
		tpBug, tpFlying,
		120, 155, 0x80, 0, 0,
		127, 15, 70, gdFlux, eggBug, eggBug,
		abilitySpeedBoost, 0, 0, 2
	},
	{ //303 - Shedinja
		1, 90, 45, 40, 30, 30,
		tpBug, tpGhost,
		45, 95, 0x2, 0, 0,
		255, 15, 70, gdFlux, eggMineral, eggMineral,
		abilityWonderGuard, 0, 0, 5
	},
	{ //304 - Taillow
		40, 55, 30, 85, 30, 30,
		tpNormal, tpFlying,
		200, 59, 0x40, 0, 0,
		127, 15, 70, gdMidSlow, eggFlying, eggFlying,
		abilityGuts, 0, 0, 1
	},
	{ //305 - Swellow
		60, 85, 60, 125, 50, 50,
		tpNormal, tpFlying,
		45, 162, 0x80, 0, 0,
		127, 15, 70, gdMidSlow, eggFlying, eggFlying,
		abilityGuts, 0, 0, 1
	},
	{ //306 - Shroomish
		60, 40, 60, 35, 40, 60,
		tpGrass, tpGrass,
		255, 65, 0x1, 0, 0,
		127, 15, 70, gdErratic, eggFairy, eggPlant,
		abilityEffectSpore, 0, 0, 5
	},
	{ //307 - Breloom
		60, 130, 80, 70, 60, 60,
		tpGrass, tpFighting,
		90, 165, 0x8, 0, 0,
		127, 15, 70, gdErratic, eggFairy, eggPlant,
		abilityEffectSpore, 0, 0, 3
	},
	{ //308 - Spinda
		60, 60, 60, 60, 60, 60,
		tpNormal, tpNormal,
		255, 85, 0x100, 0, itemChestnut,
		127, 15, 70, gdQuick, eggGround, eggHuman,
		abilityOwnTempo, 0, 0, 133
	},
	{ //309 - Wingull
		40, 30, 30, 85, 55, 30,
		tpWater, tpFlying,
		190, 64, 0x40, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggFlying,
		abilityKeenEye, 0, 0, 8
	},
	{ //310 - Pelipper
		60, 50, 100, 65, 85, 70,
		tpWater, tpFlying,
		45, 164, 0x20, 0, 0,
		127, 20, 70, gdMedium, eggWater1, eggFlying,
		abilityKeenEye, 0, 0, 2
	},
	{ //311 - Surskit
		40, 30, 32, 65, 50, 52,
		tpBug, tpWater,
		200, 63, 0x40, 0, 0,
		127, 15, 70, gdMedium, eggWater1, eggBug,
		abilitySwiftswim, 0, 0, 1
	},
	{ //312 - Masquerain
		70, 60, 62, 60, 80, 82,
		tpBug, tpFlying,
		75, 128, 0x500, 0, itemSilverPowder,
		127, 15, 70, gdMedium, eggWater1, eggBug,
		abilityIntimidate, 0, 0, 1
	},
	{ //313 - Wailmer
		130, 70, 35, 60, 70, 35,
		tpWater, tpWater,
		125, 137, 0x1, 0, 0,
		127, 40, 70, gdErratic, eggGround, eggWater2,
		abilityWaterveil, abilityOblivious, 0, 1
	},
	{ //314 - Wailord
		170, 90, 45, 60, 90, 45,
		tpWater, tpWater,
		60, 206, 0x2, 0, 0,
		127, 40, 70, gdErratic, eggGround, eggWater2,
		abilityWaterveil, abilityOblivious, 0, 1
	},
	{ //315 - Skitty
		50, 45, 45, 50, 35, 35,
		tpNormal, tpNormal,
		255, 65, 0x40, 0, itemApple,
		191, 15, 70, gdQuick, eggGround, eggFairy,
		abilityCuteCharm, 0, 0, 9
	},
	{ //316 - Delcatty
		70, 65, 65, 70, 55, 55,
		tpNormal, tpNormal,
		60, 138, 0x41, 0, itemApple,
		191, 15, 70, gdQuick, eggGround, eggFairy,
		abilityCuteCharm, 0, 0, 6
	},
	{ //317 - Kecleon
		60, 90, 70, 40, 60, 120,
		tpNormal, tpNormal,
		200, 132, 0x400, 0, itemPersimmon,
		127, 20, 70, gdMidSlow, eggGround, eggGround,
		abilityColorChange, 0, 0, 3
	},
	{ //318 - Baltoy
		40, 40, 55, 55, 40, 70,
		tpGround, tpPsychic,
		255, 58, 0x400, 0, 0,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilityLevitate, 0, 0, 5
	},
	{ //319 - Claydol
		60, 70, 105, 75, 70, 120,
		tpGround, tpPsychic,
		90, 189, 0x800, 0, 0,
		255, 20, 70, gdMedium, eggMineral, eggMineral,
		abilityLevitate, 0, 0, 4
	},
	{ //320 - Nosepass
		30, 45, 135, 30, 45, 90,
		tpRock, tpRock,
		255, 108, 0x10, 0, 0,
		127, 20, 70, gdMedium, eggMineral, eggMineral,
		abilitySturdy, abilityMagnetPull, 0, 7
	},
	{ //321 - Torkoal
		70, 85, 140, 20, 85, 70,
		tpFire, tpFire,
		90, 161, 0x20, 0, 0,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityWhiteSmoke, 0, 0, 5
	},
	{ //322 - Sableye
		50, 75, 75, 50, 65, 65,
		tpDark, tpGhost,
		45, 98, 0x14, 0, 0,
		127, 25, 35, gdMidSlow, eggHuman, eggHuman,
		abilityKeenEye, 0, 0, 6
	},
	{ //323 - Barboach
		50, 48, 43, 60, 46, 41,
		tpWater, tpGround,
		190, 92, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggWater2, eggWater2,
		abilityOblivious, 0, 0, 7
	},
	{ //324 - Whiscash
		110, 78, 73, 60, 76, 71,
		tpWater, tpGround,
		75, 158, 0x2, 0, 0,
		127, 20, 70, gdMedium, eggWater2, eggWater2,
		abilityOblivious, 0, 0, 1
	},
	{ //325 - Luvdisc
		43, 30, 55, 97, 40, 65,
		tpWater, tpWater,
		225, 110, 0x40, itemHeartScale, 0,
		191, 20, 70, gdQuick, eggWater2, eggWater2,
		abilitySwiftswim, 0, 0, 9
	},
	{ //326 - Corphish
		43, 80, 65, 35, 50, 35,
		tpWater, tpWater,
		205, 111, 0x4, 0, 0,
		127, 15, 70, gdErratic, eggWater1, eggWater3,
		abilityHyperCutter, abilityShellArmor, 0, 0
	},
	{ //327 - Crawdaunt
		63, 120, 85, 55, 90, 55,
		tpWater, tpDark,
		155, 161, 0x8, 0, 0,
		127, 15, 70, gdErratic, eggWater1, eggWater3,
		abilityHyperCutter, abilityShellArmor, 0, 0
	},
	{ //328 - Feebas
		20, 15, 20, 80, 10, 55,
		tpWater, tpWater,
		255, 61, 0x40, 0, 0,
		127, 20, 70, gdFlux, eggWater1, eggDragon,
		abilitySwiftswim, 0, 0, 5
	},
	{ //329 - Milotic
		95, 60, 79, 81, 100, 125,
		tpWater, tpWater,
		60, 213, 0x800, 0, 0,
		127, 20, 70, gdFlux, eggWater1, eggDragon,
		abilityMarvelScale, 0, 0, 9
	},
	{ //330 - Carvanha
		45, 90, 20, 65, 65, 20,
		tpWater, tpDark,
		225, 88, 0x4, 0, 0,
		127, 20, 35, gdSlow, eggWater2, eggWater2,
		abilityRoughSkin, 0, 0, 0
	},
	{ //331 - Sharpedo
		70, 120, 40, 95, 95, 40,
		tpWater, tpDark,
		60, 175, 0x8, 0, 0,
		127, 20, 35, gdSlow, eggWater2, eggWater2,
		abilityRoughSkin, 0, 0, 1
	},
	{ //332 - Trapinch
		45, 100, 45, 10, 45, 45,
		tpGround, tpGround,
		255, 73, 0x4, 0, itemSoftSand,
		127, 20, 70, gdMidSlow, eggBug, eggBug,
		abilityHyperCutter, abilityArenaTrap, 0, 5
	},
	{ //333 - Vibrava
		50, 70, 50, 70, 50, 50,
		tpGround, tpDragon,
		120, 126, 0x44, 0, 0,
		127, 20, 70, gdMidSlow, eggBug, eggBug,
		abilityLevitate, abilityLevitate, 0, 3
	},
	{ //334 - Flygon
		80, 100, 80, 100, 80, 80,
		tpGround, tpDragon,
		45, 197, 0x84, 0, 0,
		127, 20, 70, gdMidSlow, eggBug, eggBug,
		abilityLevitate, abilityLevitate, 0, 3
	},
	{ //335 - Makuhita
		72, 60, 30, 25, 20, 30,
		tpFighting, tpFighting,
		180, 87, 0x1, 0, 0,
		63, 20, 70, gdErratic, eggHuman, eggHuman,
		abilityThickFat, abilityGuts, 0, 2
	},
	{ //336 - Hariyama
		144, 120, 60, 50, 40, 60,
		tpFighting, tpFighting,
		200, 184, 0x2, 0, itemKingsRock,
		63, 20, 70, gdErratic, eggHuman, eggHuman,
		abilityThickFat, abilityGuts, 0, 5
	},
	{ //337 - Electrike
		40, 45, 40, 65, 65, 40,
		tpElectric, tpElectric,
		120, 104, 0x40, 0, 0,
		127, 20, 70, gdSlow, eggGround, eggGround,
		abilityStatic, abilityLightningRod, 0, 3
	},
	{ //338 - Manectric
		70, 75, 60, 105, 105, 60,
		tpElectric, tpElectric,
		45, 168, 0x80, 0, 0,
		127, 20, 70, gdSlow, eggGround, eggGround,
		abilityStatic, abilityLightningRod, 0, 2
	},
	{ //339 - Numel
		60, 60, 40, 35, 65, 45,
		tpFire, tpGround,
		255, 88, 0x100, itemStrawberry, itemStrawberry,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityOblivious, 0, 0, 2
	},
	{ //340 - Camerupt
		70, 100, 70, 40, 105, 75,
		tpFire, tpGround,
		150, 175, 0x104, itemStrawberry, itemStrawberry,
		127, 20, 70, gdMedium, eggGround, eggGround,
		abilityMagmaArmor, 0, 0, 0
	},
	{ //341 - Spheal
		70, 40, 50, 25, 55, 50,
		tpIce, tpWater,
		255, 75, 0x1, 0, 0,
		127, 20, 70, gdMidSlow, eggWater1, eggGround,
		abilityThickFat, 0, 0, 1
	},
	{ //342 - Sealeo
		90, 60, 70, 45, 75, 70,
		tpIce, tpWater,
		120, 128, 0x2, 0, 0,
		127, 20, 70, gdMidSlow, eggWater1, eggGround,
		abilityThickFat, 0, 0, 1
	},
	{ //343 - Walrein
		110, 80, 90, 65, 95, 90,
		tpIce, tpWater,
		45, 192, 0x3, 0, 0,
		127, 20, 70, gdMidSlow, eggWater1, eggGround,
		abilityThickFat, 0, 0, 1
	},
	{ //344 - Cacnea
		50, 85, 40, 35, 85, 40,
		tpGrass, tpGrass,
		190, 97, 0x100, 0, itemPoisonBarb,
		127, 20, 35, gdMidSlow, eggPlant, eggHuman,
		abilitySandVeil, 0, 0, 3
	},
	{ //345 - Cacturne
		70, 115, 60, 55, 115, 60,
		tpGrass, tpDark,
		60, 177, 0x104, 0, itemPoisonBarb,
		127, 20, 35, gdMidSlow, eggPlant, eggHuman,
		abilitySandVeil, 0, 0, 3
	},
	{ //346 - Snorunt
		50, 50, 50, 50, 50, 50,
		tpIce, tpIce,
		190, 74, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggFairy, eggMineral,
		abilityInnerFocus, 0, 0, 7
	},
	{ //347 - Glalie
		80, 80, 80, 80, 80, 80,
		tpIce, tpIce,
		75, 187, 0x2, 0, itemNevermeltIce,
		127, 20, 70, gdMedium, eggFairy, eggMineral,
		abilityInnerFocus, 0, 0, 7
	},
	{ //348 - Lunatone
		70, 55, 65, 70, 95, 85,
		tpRock, tpPsychic,
		45, 150, 0x200, 0, itemMoonStone,
		255, 25, 70, gdQuick, eggMineral, eggMineral,
		abilityLevitate, 0, 0, 2
	},
	{ //349 - Solrock
		70, 95, 85, 70, 55, 65,
		tpRock, tpPsychic,
		45, 150, 0x8, 0, itemSunStone,
		255, 25, 70, gdQuick, eggMineral, eggMineral,
		abilityLevitate, 0, 0, 0
	},
	{ //350 - Azurill
		50, 20, 40, 20, 20, 40,
		tpNormal, tpNormal,
		150, 33, 0x1, 0, 0,
		191, 10, 70, gdQuick, eggNone, eggNone,
		abilityThickFat, abilityHugePower, 0, 1
	},
	{ //351 - Spoink
		60, 25, 35, 60, 70, 80,
		tpPsychic, tpPsychic,
		255, 89, 0x400, 0, 0,
		127, 20, 70, gdQuick, eggGround, eggGround,
		abilityThickFat, abilityOwnTempo, 0, 4
	},
	{ //352 - Grumpig
		80, 45, 65, 80, 90, 110,
		tpPsychic, tpPsychic,
		60, 164, 0x800, 0, 0,
		127, 20, 70, gdQuick, eggGround, eggGround,
		abilityThickFat, abilityOwnTempo, 0, 6
	},
	{ //353 - Plusle
		60, 50, 40, 95, 85, 75,
		tpElectric, tpElectric,
		200, 120, 0x40, 0, 0,
		127, 20, 70, gdMedium, eggFairy, eggFairy,
		abilityPlus, 0, 0, 2
	},
	{ //354 - Minun
		60, 40, 50, 95, 75, 85,
		tpElectric, tpElectric,
		200, 120, 0x40, 0, 0,
		127, 20, 70, gdMedium, eggFairy, eggFairy,
		abilityMinus, 0, 0, 2
	},
	{ //355 - Mawile
		50, 85, 85, 50, 55, 55,
		tpSteel, tpSteel,
		45, 98, 0x14, 0, 0,
		127, 20, 70, gdQuick, eggGround, eggFairy,
		abilityHyperCutter, abilityIntimidate, 0, 4
	},
	{ //356 - Meditite
		30, 40, 55, 60, 40, 55,
		tpFighting, tpPsychic,
		180, 91, 0x40, 0, 0,
		127, 20, 70, gdMedium, eggHuman, eggHuman,
		abilityPurePower, 0, 0, 1
	},
	{ //357 - Medicham
		60, 60, 75, 80, 60, 75,
		tpFighting, tpPsychic,
		90, 153, 0x80, 0, 0,
		127, 20, 70, gdMedium, eggHuman, eggHuman,
		abilityPurePower, 0, 0, 0
	},
	{ //358 - Swablu
		45, 40, 60, 50, 40, 75,
		tpNormal, tpFlying,
		255, 74, 0x400, 0, 0,
		127, 20, 70, gdFlux, eggFlying, eggDragon,
		abilityNaturalCure, 0, 0, 1
	},
	{ //359 - Altaria
		75, 70, 90, 80, 70, 105,
		tpDragon, tpFlying,
		45, 188, 0x800, 0, 0,
		127, 20, 70, gdFlux, eggFlying, eggDragon,
		abilityNaturalCure, 0, 0, 1
	},
	{ //360 - Wynaut
		95, 23, 48, 23, 23, 48,
		tpPsychic, tpPsychic,
		125, 44, 0x1, 0, 0,
		127, 20, 70, gdMedium, eggNone, eggNone,
		abilityShadowTag, 0, 0, 1
	},
	{ //361 - Duskull
		20, 40, 90, 25, 30, 90,
		tpGhost, tpGhost,
		190, 97, 0x410, 0, itemSpellTag,
		127, 25, 35, gdQuick, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 4
	},
	{ //362 - Dusclops
		40, 70, 130, 25, 60, 130,
		tpGhost, tpGhost,
		90, 179, 0x810, 0, itemSpellTag,
		127, 25, 35, gdQuick, eggIndeterminate, eggIndeterminate,
		abilityPressure, 0, 0, 4
	},
	{ //363 - Roselia
		50, 60, 45, 65, 100, 80,
		tpGrass, tpPoison,
		150, 152, 0x100, 0, itemPoisonBarb,
		127, 20, 70, gdMidSlow, eggFairy, eggPlant,
		abilityNaturalCure, abilityPoisonPoint, 0, 131
	},
	{ //364 - Slakoth
		60, 60, 60, 30, 35, 35,
		tpNormal, tpNormal,
		255, 83, 0x1, 0, 0,
		127, 15, 70, gdSlow, eggGround, eggGround,
		abilityTruant, 0, 0, 5
	},
	{ //365 - Vigoroth
		80, 80, 80, 90, 55, 55,
		tpNormal, tpNormal,
		120, 126, 0x80, 0, 0,
		127, 15, 70, gdSlow, eggGround, eggGround,
		abilityVitalSpirit, 0, 0, 8
	},
	{ //366 - Slaking
		150, 160, 100, 100, 95, 65,
		tpNormal, tpNormal,
		45, 210, 0x3, 0, 0,
		127, 15, 70, gdSlow, eggGround, eggGround,
		abilityTruant, 0, 0, 5
	},
	{ //367 - Gulpin
		70, 43, 53, 40, 43, 53,
		tpPoison, tpPoison,
		225, 75, 0x1, 0, itemBigPearl,
		127, 20, 70, gdErratic, eggIndeterminate, eggIndeterminate,
		abilityLiquidOoze, abilityStickyHold, 0, 3
	},
	{ //368 - Swalot
		100, 73, 83, 55, 73, 83,
		tpPoison, tpPoison,
		75, 168, 0x2, 0, itemBigPearl,
		127, 20, 70, gdErratic, eggIndeterminate, eggIndeterminate,
		abilityLiquidOoze, abilityStickyHold, 0, 6
	},
	{ //369 - Tropius
		99, 68, 83, 51, 72, 87,
		tpGrass, tpFlying,
		200, 169, 0x2, 0, 0,
		127, 25, 70, gdSlow, eggMonster, eggPlant,
		abilityChlorophyll, 0, 0, 3
	},
	{ //370 - Whismur
		64, 51, 23, 28, 51, 23,
		tpNormal, tpNormal,
		190, 68, 0x1, 0, itemChestnut,
		127, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilitySoundproof, 0, 0, 9
	},
	{ //371 - Loudred
		84, 71, 43, 48, 71, 43,
		tpNormal, tpNormal,
		120, 126, 0x2, 0, itemChestnut,
		127, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilitySoundproof, 0, 0, 1
	},
	{ //372 - Exploud
		104, 91, 63, 68, 91, 63,
		tpNormal, tpNormal,
		45, 184, 0x3, 0, itemChestnut,
		127, 20, 70, gdMidSlow, eggMonster, eggGround,
		abilitySoundproof, 0, 0, 1
	},
	{ //373 - Clamperl
		35, 64, 85, 32, 74, 55,
		tpWater, tpWater,
		255, 142, 0x10, 0, itemBlueShard,
		127, 20, 70, gdFlux, eggWater1, eggWater1,
		abilityShellArmor, 0, 0, 1
	},
	{ //374 - Huntail
		55, 104, 105, 52, 94, 75,
		tpWater, tpWater,
		60, 178, 0x14, 0, 0,
		127, 20, 70, gdFlux, eggWater1, eggWater1,
		abilitySwiftswim, 0, 0, 1
	},
	{ //375 - Gorebyss
		55, 84, 105, 52, 114, 75,
		tpWater, tpWater,
		60, 178, 0x200, 0, 0,
		127, 20, 70, gdFlux, eggWater1, eggWater1,
		abilitySwiftswim, 0, 0, 9
	},
	{ //376 - Absol
		65, 130, 60, 75, 75, 60,
		tpDark, tpDark,
		30, 174, 0x8, 0, 0,
		127, 25, 35, gdMidSlow, eggGround, eggGround,
		abilityPressure, 0, 0, 136
	},
	{ //377 - Shuppet
		44, 75, 35, 45, 63, 33,
		tpGhost, tpGhost,
		225, 97, 0x4, 0, itemSpellTag,
		127, 25, 35, gdQuick, eggIndeterminate, eggIndeterminate,
		abilityInsomnia, 0, 0, 4
	},
	{ //378 - Banette
		64, 115, 65, 65, 83, 63,
		tpGhost, tpGhost,
		45, 179, 0x8, 0, itemSpellTag,
		127, 25, 35, gdQuick, eggIndeterminate, eggIndeterminate,
		abilityInsomnia, 0, 0, 4
	},
	{ //379 - Seviper
		73, 100, 60, 65, 100, 60,
		tpPoison, tpPoison,
		90, 165, 0x104, 0, 0,
		127, 20, 70, gdErratic, eggGround, eggDragon,
		abilityShedSkin, 0, 0, 132
	},
	{ //380 - Zangoose
		73, 115, 60, 90, 60, 60,
		tpNormal, tpNormal,
		90, 165, 0x8, 0, 0,
		127, 20, 70, gdFlux, eggGround, eggGround,
		abilityImmunity, 0, 0, 136
	},
	{ //381 - Relicanth
		100, 90, 130, 55, 45, 65,
		tpWater, tpRock,
		25, 198, 0x11, 0, itemGreenShard,
		31, 40, 70, gdSlow, eggWater1, eggWater2,
		abilitySwiftswim, abilityRockHead, 0, 7
	},
	{ //382 - Aron
		50, 70, 100, 30, 40, 40,
		tpSteel, tpRock,
		180, 96, 0x10, 0, itemHardStone,
		127, 35, 35, gdSlow, eggMonster, eggMonster,
		abilitySturdy, abilityRockHead, 0, 7
	},
	{ //383 - Lairon
		60, 90, 140, 40, 50, 50,
		tpSteel, tpRock,
		90, 152, 0x20, 0, itemHardStone,
		127, 35, 35, gdSlow, eggMonster, eggMonster,
		abilitySturdy, abilityRockHead, 0, 7
	},
	{ //384 - Aggron
		70, 110, 180, 50, 60, 60,
		tpSteel, tpRock,
		45, 205, 0x30, 0, itemHardStone,
		127, 35, 35, gdSlow, eggMonster, eggMonster,
		abilitySturdy, abilityRockHead, 0, 7
	},
	{ //385 - Castform
		70, 70, 70, 70, 70, 70,
		tpNormal, tpNormal,
		45, 145, 0x1, itemMysticWater, itemMysticWater,
		127, 25, 70, gdMedium, eggFairy, eggIndeterminate,
		abilityForecast, 0, 0, 8
	},
	{ //386 - Volbeat
		65, 73, 55, 85, 47, 75,
		tpBug, tpBug,
		150, 146, 0x40, 0, 0,
		0, 15, 70, gdFlux, eggBug, eggHuman,
		abilityIlluminate, abilitySwarm, 0, 7
	},
	{ //387 - Illumise
		65, 47, 55, 85, 73, 75,
		tpBug, tpBug,
		150, 146, 0x40, 0, 0,
		254, 15, 70, gdErratic, eggBug, eggHuman,
		abilityOblivious, 0, 0, 6
	},
	{ //388 - Lileep
		66, 41, 77, 23, 61, 87,
		tpRock, tpGrass,
		45, 121, 0x400, 0, 0,
		31, 30, 70, gdFlux, eggWater3, eggWater3,
		abilitySuctionCups, 0, 0, 6
	},
	{ //389 - Cradily
		86, 81, 97, 43, 81, 107,
		tpRock, tpGrass,
		45, 201, 0x800, 0, 0,
		31, 30, 70, gdFlux, eggWater3, eggWater3,
		abilitySuctionCups, 0, 0, 3
	},
	{ //390 - Anorith
		45, 95, 50, 75, 40, 50,
		tpRock, tpBug,
		45, 119, 0x4, 0, 0,
		31, 30, 70, gdFlux, eggWater3, eggWater3,
		abilityBattleArmor, 0, 0, 7
	},
	{ //391 - Armaldo
		75, 125, 100, 45, 70, 80,
		tpRock, tpBug,
		45, 200, 0x8, 0, 0,
		31, 30, 70, gdFlux, eggWater3, eggWater3,
		abilityBattleArmor, 0, 0, 7
	},
	{ //392 - Ralts
		28, 25, 25, 40, 45, 35,
		tpPsychic, tpPsychic,
		235, 70, 0x100, 0, 0,
		127, 20, 35, gdSlow, eggIndeterminate, eggIndeterminate,
		abilitySynchronize, abilityTrace, 0, 8
	},
	{ //393 - Kirlia
		38, 35, 35, 50, 65, 55,
		tpPsychic, tpPsychic,
		120, 140, 0x200, 0, 0,
		127, 20, 35, gdSlow, eggIndeterminate, eggIndeterminate,
		abilitySynchronize, abilityTrace, 0, 8
	},
	{ //394 - Gardevoir
		68, 65, 65, 80, 125, 115,
		tpPsychic, tpPsychic,
		45, 208, 0x300, 0, 0,
		127, 20, 35, gdSlow, eggIndeterminate, eggIndeterminate,
		abilitySynchronize, abilityTrace, 0, 8
	},
	{ //395 - Bagon
		45, 75, 60, 50, 40, 30,
		tpDragon, tpDragon,
		45, 89, 0x4, 0, itemDragonScale,
		127, 40, 35, gdSlow, eggDragon, eggDragon,
		abilityRockHead, 0, 0, 1
	},
	{ //396 - Shelgon
		65, 95, 100, 50, 60, 50,
		tpDragon, tpDragon,
		45, 144, 0x20, 0, itemDragonScale,
		127, 40, 35, gdSlow, eggDragon, eggDragon,
		abilityRockHead, 0, 0, 8
	},
	{ //397 - Salamence
		95, 135, 80, 100, 110, 80,
		tpDragon, tpFlying,
		45, 218, 0xC, 0, itemDragonScale,
		127, 40, 35, gdSlow, eggDragon, eggDragon,
		abilityIntimidate, 0, 0, 1
	},
	{ //398 - Beldum
		40, 55, 80, 30, 35, 60,
		tpSteel, tpPsychic,
		3, 103, 0x10, 0, itemMetalCoat,
		255, 40, 35, gdSlow, eggMineral, eggMineral,
		abilityClearBody, 0, 0, 1
	},
	{ //399 - Metang
		60, 75, 100, 50, 55, 80,
		tpSteel, tpPsychic,
		3, 153, 0x20, 0, itemMetalCoat,
		255, 40, 35, gdSlow, eggMineral, eggMineral,
		abilityClearBody, 0, 0, 1
	},
	{ //400 - Metagross
		80, 135, 130, 70, 95, 90,
		tpSteel, tpPsychic,
		3, 210, 0x30, 0, itemMetalCoat,
		255, 40, 35, gdSlow, eggMineral, eggMineral,
		abilityClearBody, 0, 0, 1
	},
	{ //401 - Regirock
		80, 100, 200, 50, 50, 100,
		tpRock, tpRock,
		3, 217, 0x30, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityClearBody, 0, 0, 5
	},
	{ //402 - Regice
		80, 50, 100, 50, 100, 200,
		tpIce, tpIce,
		3, 216, 0xC00, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityClearBody, 0, 0, 1
	},
	{ //403 - Registeel
		80, 75, 150, 50, 75, 150,
		tpSteel, tpSteel,
		3, 215, 0x420, 0, 0,
		255, 80, 35, gdSlow, eggNone, eggNone,
		abilityClearBody, 0, 0, 7
	},
	{ //404 - Kyogre
		100, 100, 90, 90, 150, 140,
		tpWater, tpWater,
		5, 218, 0x300, 0, 0,
		255, 120, 0, gdSlow, eggNone, eggNone,
		abilityDrizzle, 0, 0, 1
	},
	{ //405 - Groudon
		100, 150, 140, 90, 100, 90,
		tpGround, tpGround,
		5, 218, 0xC, 0, 0,
		255, 120, 0, gdSlow, eggNone, eggNone,
		abilityDrought, 0, 0, 0
	},
	{ //406 - Rayquaza
		105, 150, 90, 95, 150, 90,
		tpDragon, tpFlying,
		3, 220, 0x108, 0, 0,
		255, 120, 0, gdSlow, eggNone, eggNone,
		abilityAirlock, 0, 0, 3
	},
	{ //407 - Latias
		80, 80, 90, 110, 110, 130,
		tpDragon, tpPsychic,
		3, 211, 0xC00, 0, 0,
		254, 120, 90, gdSlow, eggNone, eggNone,
		abilityLevitate, 0, 0, 0
	},
	{ //408 - Latios
		80, 90, 80, 110, 130, 110,
		tpDragon, tpPsychic,
		3, 211, 0x300, 0, 0,
		0, 120, 90, gdSlow, eggNone, eggNone,
		abilityLevitate, 0, 0, 1
	},
	{ //409 - Jirachi
		100, 100, 100, 100, 100, 100,
		tpSteel, tpPsychic,
		3, 215, 0x3, itemStarPiece, itemStarPiece,
		255, 120, 100, gdSlow, eggNone, eggNone,
		abilitySereneGrace, 0, 0, 2
	},
	{ //410 - Deoxys
		50, 150, 50, 150, 150, 50,
		tpPsychic, tpPsychic,
		3, 215, 0x144, 0, 0,
		255, 120, 0, gdSlow, eggNone, eggNone,
		abilityPressure, 0, 0, 128
	},
	{ //411 - Chimecho
		65, 50, 70, 65, 95, 80,
		tpPsychic, tpPsychic,
		45, 147, 0x500, 0, 0,
		127, 25, 70, gdQuick, eggIndeterminate, eggIndeterminate,
		abilityLevitate, 0, 0, 1
	},
};

const unsigned char TMAllowances[][8] =
{
	{ 32 ,7  ,53 ,132,8  ,30 ,228,0 }, //.....x..xxx.....x.x.xx....x....x...x.....xxxx.....x..xxx.. Bulbasaur
	{ 32 ,7  ,53 ,132,8  ,30 ,228,0 }, //.....x..xxx.....x.x.xx....x....x...x.....xxxx.....x..xxx.. Ivysaur
	{ 48 ,71 ,53 ,134,8  ,30 ,228,0 }, //....xx..xxx...x.x.x.xx...xx....x...x.....xxxx.....x..xxx.. Venusaur
	{ 35 ,6  ,81 ,204,164,30 ,166,0 }, //xx...x...xx.....x...x.x...xx..xx..x..x.x.xxxx....xx..x.x.. Charmander
	{ 35 ,6  ,81 ,204,164,30 ,166,0 }, //xx...x...xx.....x...x.x...xx..xx..x..x.x.xxxx....xx..x.x.. Charmeleon
	{ 51 ,70 ,81 ,206,164,94 ,174,0 }, //xx..xx...xx...x.x...x.x..xxx..xx..x..x.x.xxxx.x..xxx.x.x.. Charizard
	{ 101,50 ,83 ,204,0  ,30 ,176,3 }, //x.x..xx..x..xx..xx..x.x...xx..xx.........xxxx.......xx.xxx Squirtle
	{ 101,50 ,83 ,204,0  ,30 ,176,3 }, //x.x..xx..x..xx..xx..x.x...xx..xx.........xxxx.......xx.xxx Wartortle
	{ 117,114,83 ,206,0  ,30 ,176,3 }, //x.x.xxx..x..xxx.xx..x.x..xxx..xx.........xxxx.......xx.xxx Blastoise
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Caterpie
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Metapod
	{ 32 ,70 ,63 ,180,128,190,64 ,0 }, //.....x...xx...x.xxxxxx....x.xx.x.......x.xxxxx.x......x... Butterfree
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Weedle
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Kakuna
	{ 32 ,70 ,53 ,196,136,62 ,132,0 }, //.....x...xx...x.x.x.xx....x...xx...x...x.xxxxx....x....x.. Beedrill
	{ 32 ,6  ,19 ,132,128,126,8  ,0 }, //.....x...xx.....xx..x.....x....x.......x.xxxxxx....x...... Pidgey
	{ 32 ,6  ,19 ,132,128,126,8  ,0 }, //.....x...xx.....xx..x.....x....x.......x.xxxxxx....x...... Pidgeotto
	{ 32 ,70 ,19 ,132,128,126,8  ,0 }, //.....x...xx...x.xx..x.....x....x.......x.xxxxxx....x...... Pidgeot
	{ 32 ,62 ,211,173,2  ,62 ,132,0 }, //.....x...xxxxx..xx..x.xxx.xx.x.x.x.......xxxxx....x....x.. Rattata
	{ 48 ,126,211,173,2  ,62 ,164,0 }, //....xx...xxxxxx.xx..x.xxx.xx.x.x.x.......xxxxx....x..x.x.. Raticate
	{ 32 ,6  ,19 ,132,128,126,8  ,0 }, //.....x...xx.....xx..x.....x....x.......x.xxxxxx....x...... Spearow
	{ 32 ,70 ,19 ,132,128,126,8  ,0 }, //.....x...xx...x.xx..x.....x....x.......x.xxxxxx....x...... Fearow
	{ 32 ,6  ,87 ,142,8  ,63 ,33 ,0 }, //.....x...xx.....xxx.x.x..xxx...x...x....xxxxxx..x....x.... Ekans
	{ 32 ,70 ,87 ,142,8  ,63 ,33 ,0 }, //.....x...xx...x.xxx.x.x..xxx...x...x....xxxxxx..x....x.... Arbok
	{ 33 ,130,211,205,2  ,30 ,224,0 }, //x....x...x.....xxx..x.xxx.xx..xx.x.......xxxx........xxx.. Pikachu
	{ 33 ,194,211,205,2  ,62 ,224,0 }, //x....x...x....xxxx..x.xxx.xx..xx.x.......xxxxx.......xxx.. Raichu
	{ 33 ,6  ,81 ,206,208,62 ,164,0 }, //x....x...xx.....x...x.x..xxx..xx....x.xx.xxxxx....x..x.x.. Sandshrew
	{ 33 ,70 ,81 ,206,208,62 ,164,0 }, //x....x...xx...x.x...x.x..xxx..xx....x.xx.xxxxx....x..x.x.. Sandslash
	{ 36 ,54 ,211,141,138,62 ,164,0 }, //..x..x...xx.xx..xx..x.xxx.xx...x.x.x...x.xxxxx....x..x.x.. Nidoran\x8b
	{ 36 ,54 ,211,141,138,62 ,164,0 }, //..x..x...xx.xx..xx..x.xxx.xx...x.x.x...x.xxxxx....x..x.x.. Nidorina
	{ 53 ,126,211,239,254,63 ,180,0 }, //x.x.xx...xxxxxx.xx..x.xxxxxx.xxx.xxxxxxxxxxxxx....x.xx.x.. Nidoqueen
	{ 36 ,54 ,211,141,10 ,62 ,164,0 }, //..x..x...xx.xx..xx..x.xxx.xx...x.x.x.....xxxxx....x..x.x.. Nidoran\x8a
	{ 36 ,54 ,211,141,10 ,62 ,164,0 }, //..x..x...xx.xx..xx..x.xxx.xx...x.x.x.....xxxxx....x..x.x.. Nidorino
	{ 53 ,126,211,239,126,63 ,180,0 }, //x.x.xx...xxxxxx.xx..x.xxxxxx.xxx.xxxxxx.xxxxxx....x.xx.x.. Nidoking
	{ 45 ,182,251,253,39 ,30 ,97 ,0 }, //x.xx.x...xx.xx.xxx.xxxxxx.xxxxxxxxx..x...xxxx...x....xx... Clefairy
	{ 45 ,246,251,253,39 ,30 ,97 ,0 }, //x.xx.x...xx.xxxxxx.xxxxxx.xxxxxxxxx..x...xxxx...x....xx... Clefable
	{ 48 ,6  ,89 ,140,36 ,30 ,2  ,0 }, //....xx...xx.....x..xx.x...xx...x..x..x...xxxx....x........ Vulpix
	{ 48 ,70 ,89 ,140,36 ,30 ,2  ,0 }, //....xx...xx...x.x..xx.x...xx...x..x..x...xxxx....x........ Ninetales
	{ 37 ,182,187,253,39 ,30 ,97 ,0 }, //x.x..x...xx.xx.xxx.xxx.xx.xxxxxxxxx..x...xxxx...x....xx... Jigglypuff
	{ 37 ,246,187,253,39 ,30 ,97 ,0 }, //x.x..x...xx.xxxxxx.xxx.xx.xxxxxxxxx..x...xxxx...x....xx... Wigglytuff
	{ 32 ,14 ,23 ,164,136,127,1  ,0 }, //.....x...xxx....xxx.x.....x..x.x...x...xxxxxxxx.x......... Zubat
	{ 32 ,78 ,23 ,164,136,127,1  ,0 }, //.....x...xxx..x.xxx.x.....x..x.x...x...xxxxxxxx.x......... Golbat
	{ 32 ,7  ,53 ,132,8  ,30 ,68 ,0 }, //.....x..xxx.....x.x.xx....x....x...x.....xxxx.....x...x... Oddish
	{ 32 ,7  ,53 ,132,8  ,30 ,68 ,0 }, //.....x..xxx.....x.x.xx....x....x...x.....xxxx.....x...x... Gloom
	{ 32 ,71 ,53 ,132,8  ,30 ,68 ,0 }, //.....x..xxx...x.x.x.xx....x....x...x.....xxxx.....x...x... Vileplume
	{ 32 ,7  ,53 ,140,136,62 ,196,0 }, //.....x..xxx.....x.x.xx....xx...x...x...x.xxxxx....x...xx.. Paras
	{ 32 ,71 ,53 ,140,136,62 ,196,0 }, //.....x..xxx...x.x.x.xx....xx...x...x...x.xxxxx....x...xx.. Parasect
	{ 32 ,6  ,53 ,148,8  ,190,64 ,0 }, //.....x...xx.....x.x.xx....x.x..x...x.....xxxxx.x......x... Venonat
	{ 32 ,70 ,53 ,148,136,190,64 ,0 }, //.....x...xx...x.x.x.xx....x.x..x...x...x.xxxxx.x......x... Venomoth
	{ 32 ,6  ,17 ,142,200,62 ,132,0 }, //.....x...xx.....x...x....xxx...x...x..xx.xxxxx....x....x.. Diglett
	{ 32 ,70 ,17 ,142,200,62 ,132,0 }, //.....x...xx...x.x...x....xxx...x...x..xx.xxxxx....x....x.. Dugtrio
	{ 36 ,14 ,211,173,130,63 ,69 ,0 }, //..x..x...xxx....xx..x.xxx.xx.x.x.x.....xxxxxxx..x.x...x... Meowth
	{ 52 ,78 ,211,173,130,63 ,69 ,0 }, //..x.xx...xxx..x.xx..x.xxx.xx.x.x.x.....xxxxxxx..x.x...x... Persian
	{ 109,50 ,83 ,204,128,30 ,240,3 }, //x.xx.xx..x..xx..xx..x.x...xx..xx.......x.xxxx.......xxxxxx Psyduck
	{ 109,114,83 ,204,128,30 ,240,3 }, //x.xx.xx..x..xxx.xx..x.x...xx..xx.......x.xxxx.......xxxxxx Golduck
	{ 161,14 ,211,207,192,62 ,162,0 }, //x....x.x.xxx....xx..x.xxxxxx..xx......xx.xxxxx...x...x.x.. Mankey
	{ 161,78 ,211,207,192,62 ,162,0 }, //x....x.x.xxx..x.xx..x.xxxxxx..xx......xx.xxxxx...x...x.x.. Primeape
	{ 48 ,6  ,81 ,140,164,62 ,162,0 }, //....xx...xx.....x...x.x...xx...x..x..x.x.xxxxx...x...x.x.. Growlithe
	{ 48 ,70 ,81 ,140,164,62 ,162,0 }, //....xx...xx...x.x...x.x...xx...x..x..x.x.xxxxx...x...x.x.. Arcanine
	{ 100,50 ,19 ,156,0  ,62 ,16 ,3 }, //..x..xx..x..xx..xx..x.....xxx..x.........xxxxx......x...xx Poliwag
	{ 101,50 ,19 ,222,0  ,62 ,176,3 }, //x.x..xx..x..xx..xx..x....xxxx.xx.........xxxxx......xx.xxx Poliwhirl
	{ 229,114,19 ,222,64 ,62 ,176,3 }, //x.x..xxx.x..xxx.xx..x....xxxx.xx......x..xxxxx......xx.xxx Poliwrath
	{ 41 ,142,91 ,180,3  ,191,65 ,0 }, //x..x.x...xxx...xxx.xx.x...x.xx.xxx......xxxxxx.xx.....x... Abra
	{ 41 ,142,91 ,180,3  ,191,65 ,0 }, //x..x.x...xxx...xxx.xx.x...x.xx.xxx......xxxxxx.xx.....x... Kadabra
	{ 41 ,206,91 ,180,3  ,191,65 ,0 }, //x..x.x...xxx..xxxx.xx.x...x.xx.xxx......xxxxxx.xx.....x... Alakazam
	{ 161,6  ,19 ,206,100,62 ,160,0 }, //x....x.x.xx.....xx..x....xxx..xx..x..xx..xxxxx.......x.x.. Machop
	{ 161,6  ,19 ,206,100,62 ,160,0 }, //x....x.x.xx.....xx..x....xxx..xx..x..xx..xxxxx.......x.x.. Machoke
	{ 161,70 ,19 ,206,100,62 ,160,0 }, //x....x.x.xx...x.xx..x....xxx..xx..x..xx..xxxxx.......x.x.. Machamp
	{ 32 ,7  ,53 ,132,8  ,62 ,68 ,0 }, //.....x..xxx.....x.x.xx....x....x...x.....xxxxx....x...x... Bellsprout
	{ 32 ,7  ,53 ,132,8  ,62 ,68 ,0 }, //.....x..xxx.....x.x.xx....x....x...x.....xxxxx....x...x... Weepinbell
	{ 32 ,71 ,53 ,132,8  ,62 ,68 ,0 }, //.....x..xxx...x.x.x.xx....x....x...x.....xxxxx....x...x... Victreebel
	{ 100,50 ,23 ,132,8  ,62 ,20 ,3 }, //..x..xx..x..xx..xxx.x.....x....x...x.....xxxxx....x.x...xx Tentacool
	{ 100,114,23 ,132,8  ,62 ,20 ,3 }, //..x..xx..x..xxx.xxx.x.....x....x...x.....xxxxx....x.x...xx Tentacruel
	{ 33 ,6  ,17 ,206,116,30 ,160,0 }, //x....x...xx.....x...x....xxx..xx..x.xxx..xxxx........x.x.. Geodude
	{ 33 ,6  ,17 ,206,116,30 ,160,0 }, //x....x...xx.....x...x....xxx..xx..x.xxx..xxxx........x.x.. Graveler
	{ 49 ,70 ,17 ,206,116,30 ,160,0 }, //x...xx...xx...x.x...x....xxx..xx..x.xxx..xxxx........x.x.. Golem
	{ 32 ,6  ,113,132,36 ,30 ,34 ,0 }, //.....x...xx.....x...xxx...x....x..x..x...xxxx....x...x.... Ponyta
	{ 32 ,70 ,113,132,36 ,30 ,34 ,0 }, //.....x...xx...x.x...xxx...x....x..x..x...xxxx....x...x.... Rapidash
	{ 108,54 ,91 ,190,36 ,158,112,2 }, //..xx.xx..xx.xx..xx.xx.x..xxxxx.x..x..x...xxxx..x....xxx..x Slowpoke
	{ 109,118,91 ,254,36 ,158,240,2 }, //x.xx.xx..xx.xxx.xx.xx.x..xxxxxxx..x..x...xxxx..x....xxxx.x Slowbro
	{ 32 ,6  ,147,133,3  ,14 ,64 ,0 }, //.....x...xx.....xx..x..xx.x....xxx.......xxx..........x... Magnemite
	{ 32 ,70 ,147,133,3  ,14 ,64 ,0 }, //.....x...xx...x.xx..x..xx.x....xxx.......xxx..........x... Magneton
	{ 32 ,6  ,81 ,132,128,126,12 ,0 }, //.....x...xx.....x...x.x...x....x.......x.xxxxxx...xx...... Farfetch'd
	{ 32 ,6  ,17 ,132,128,126,8  ,0 }, //.....x...xx.....x...x.....x....x.......x.xxxxxx....x...... Doduo
	{ 32 ,78 ,17 ,132,128,127,8  ,0 }, //.....x...xxx..x.x...x.....x....x.......xxxxxxxx....x...... Dodrio
	{ 100,50 ,27 ,132,0  ,62 ,16 ,3 }, //..x..xx..x..xx..xx.xx.....x....x.........xxxxx......x...xx Seel
	{ 100,114,27 ,132,0  ,62 ,16 ,3 }, //..x..xx..x..xxx.xx.xx.....x....x.........xxxxx......x...xx Dewgong
	{ 32 ,14 ,151,141,110,63 ,0  ,0 }, //.....x...xxx....xxx.x..xx.xx...x.xxx.xx.xxxxxx............ Grimer
	{ 33 ,78 ,151,205,110,63 ,160,0 }, //x....x...xxx..x.xxx.x..xx.xx..xx.xxx.xx.xxxxxx.......x.x.. Muk
	{ 100,50 ,19 ,132,0  ,30 ,16 ,2 }, //..x..xx..x..xx..xx..x.....x....x.........xxxx.......x....x Shellder
	{ 100,114,19 ,132,0  ,31 ,16 ,2 }, //..x..xx..x..xxx.xx..x.....x....x........xxxxx.......x....x Cloyster
	{ 32 ,14 ,151,180,8  ,191,1  ,0 }, //.....x...xxx....xxx.x..x..x.xx.x...x....xxxxxx.xx......... Gastly
	{ 32 ,14 ,151,180,8  ,191,1  ,0 }, //.....x...xxx....xxx.x..x..x.xx.x...x....xxxxxx.xx......... Haunter
	{ 33 ,78 ,151,245,8  ,191,161,0 }, //x....x...xxx..x.xxx.x..xx.x.xxxx...x....xxxxxx.xx....x.x.. Gengar
	{ 48 ,14 ,81 ,142,80 ,31 ,160,0 }, //....xx...xxx....x...x.x..xxx...x....x.x.xxxxx........x.x.. Onix
	{ 41 ,142,27 ,244,1  ,191,65 ,0 }, //x..x.x...xxx...xxx.xx.....x.xxxxx.......xxxxxx.xx.....x... Drowzee
	{ 41 ,206,27 ,244,1  ,191,65 ,0 }, //x..x.x...xxx..xxxx.xx.....x.xxxxx.......xxxxxx.xx.....x... Hypno
	{ 100,50 ,19 ,140,64 ,62 ,180,2 }, //..x..xx..x..xx..xx..x.....xx...x......x..xxxxx....x.xx.x.x Krabby
	{ 100,114,19 ,140,64 ,62 ,180,2 }, //..x..xx..x..xxx.xx..x.....xx...x......x..xxxxx....x.xx.x.x Kingler
	{ 32 ,138,147,133,2  ,47 ,64 ,0 }, //.....x...x.x...xxx..x..xx.x....x.x......xxxx.x........x... Voltorb
	{ 32 ,202,147,133,2  ,47 ,64 ,0 }, //.....x...x.x..xxxx..x..xx.x....x.x......xxxx.x........x... Electrode
	{ 32 ,135,53 ,148,9  ,190,96 ,0 }, //.....x..xxx....xx.x.xx....x.x..xx..x.....xxxxx.x.....xx... Exeggcute
	{ 32 ,199,53 ,148,9  ,190,96 ,0 }, //.....x..xxx...xxx.x.xx....x.x..xx..x.....xxxxx.x.....xx... Exeggutor
	{ 33 ,54 ,81 ,206,244,62 ,160,0 }, //x....x...xx.xx..x...x.x..xxx..xx..x.xxxx.xxxxx.......x.x.. Cubone
	{ 33 ,118,81 ,206,244,62 ,160,0 }, //x....x...xx.xxx.x...x.x..xxx..xx..x.xxxx.xxxxx.......x.x.. Marowak
	{ 161,6  ,19 ,198,64 ,62 ,160,0 }, //x....x.x.xx.....xx..x....xx...xx......x..xxxxx.......x.x.. Hitmonlee
	{ 161,6  ,19 ,198,64 ,62 ,160,0 }, //x....x.x.xx.....xx..x....xx...xx......x..xxxxx.......x.x.. Hitmonchan
	{ 37 ,118,243,239,118,62 ,180,0 }, //x.x..x...xx.xxx.xx..xxxxxxxx.xxx.xx.xxx..xxxxx....x.xx.x.. Lickitung
	{ 32 ,14 ,147,165,46 ,63 ,64 ,0 }, //.....x...xxx....xx..x..xx.x..x.x.xxx.x..xxxxxx........x... Koffing
	{ 32 ,78 ,147,165,46 ,63 ,64 ,0 }, //.....x...xxx..x.xx..x..xx.x..x.x.xxx.x..xxxxxx........x... Weezing
	{ 48 ,54 ,211,143,118,62 ,160,0 }, //....xx...xx.xx..xx..x.xxxxxx...x.xx.xxx..xxxxx.......x.x.. Rhyhorn
	{ 49 ,118,211,207,118,62 ,180,0 }, //x...xx...xx.xxx.xx..x.xxxxxx..xx.xx.xxx..xxxxx....x.xx.x.. Rhydon
	{ 109,246,251,247,118,158,225,0 }, //x.xx.xx..xx.xxxxxx.xxxxxxxx.xxxx.xx.xxx..xxxx..xx....xxx.. Chansey
	{ 32 ,71 ,53 ,132,8  ,62 ,196,0 }, //.....x..xxx...x.x.x.xx....x....x...x.....xxxxx....x...xx.. Tangela
	{ 117,118,243,239,246,62 ,180,0 }, //x.x.xxx..xx.xxx.xx..xxxxxxxx.xxx.xx.xxxx.xxxxx....x.xx.x.. Kangaskhan
	{ 100,50 ,19 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xx..xx..x.....x....x.........xxxx.......x...xx Horsea
	{ 100,114,19 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xxx.xx..x.....x....x.........xxxx.......x...xx Seadra
	{ 100,50 ,19 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xx..xx..x.....x....x.........xxxx.......x...xx Goldeen
	{ 100,114,19 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xxx.xx..x.....x....x.........xxxx.......x...xx Seaking
	{ 100,178,147,149,1  ,14 ,80 ,3 }, //..x..xx..x..xx.xxx..x..xx.x.x..xx........xxx........x.x.xx Staryu
	{ 100,242,147,149,1  ,142,80 ,3 }, //..x..xx..x..xxxxxx..x..xx.x.x..xx........xxx...x....x.x.xx Starmie
	{ 41 ,206,187,245,3  ,191,65 ,0 }, //x..x.x...xxx..xxxx.xxx.xx.x.xxxxxx......xxxxxx.xx.....x... Mr. Mime
	{ 32 ,70 ,19 ,132,128,126,132,0 }, //.....x...xx...x.xx..x.....x....x.......x.xxxxxx...x....x.. Scyther
	{ 109,250,19 ,244,1  ,191,64 ,0 }, //x.xx.xx..x.xxxxxxx..x.....x.xxxxx.......xxxxxx.x......x... Jynx
	{ 33 ,194,211,213,2  ,62 ,224,0 }, //x....x...x....xxxx..x.xxx.x.x.xx.x.......xxxxx.......xxx.. Electabuzz
	{ 33 ,70 ,81 ,212,36 ,62 ,160,0 }, //x....x...xx...x.x...x.x...x.x.xx..x..x...xxxxx.......x.x.. Magmar
	{ 161,70 ,19 ,206,64 ,62 ,164,0 }, //x....x.x.xx...x.xx..x....xxx..xx......x..xxxxx....x..x.x.. Pinsir
	{ 36 ,118,243,135,118,30 ,176,0 }, //..x..x...xx.xxx.xx..xxxxxxx....x.xx.xxx..xxxx.......xx.x.. Tauros
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Magikarp
	{ 116,122,147,135,52 ,31 ,176,3 }, //..x.xxx..x.xxxx.xx..x..xxxx....x..x.xx..xxxxx.......xx.xxx Gyarados
	{ 116,114,219,149,2  ,30 ,176,3 }, //..x.xxx..x..xxx.xx.xx.xxx.x.x..x.x.......xxxx.......xx.xxx Lapras
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Ditto
	{ 32 ,6  ,83 ,172,0  ,30 ,0  ,0 }, //.....x...xx.....xx..x.x...xx.x.x.........xxxx............. Eevee
	{ 116,118,83 ,172,0  ,30 ,16 ,3 }, //..x.xxx..xx.xxx.xx..x.x...xx.x.x.........xxxx.......x...xx Vaporeon
	{ 48 ,70 ,211,173,2  ,30 ,64 ,0 }, //....xx...xx...x.xx..x.xxx.xx.x.x.x.......xxxx.........x... Jolteon
	{ 48 ,70 ,83 ,172,36 ,30 ,2  ,0 }, //....xx...xx...x.xx..x.x...xx.x.x..x..x...xxxx....x........ Flareon
	{ 32 ,118,243,181,130,46 ,64 ,0 }, //.....x...xx.xxx.xx..xxxxx.x.xx.x.x.....x.xxx.x........x... Porygon
	{ 100,50 ,19 ,132,80 ,62 ,144,3 }, //..x..xx..x..xx..xx..x.....x....x....x.x..xxxxx......x..xxx Omanyte
	{ 100,114,19 ,132,80 ,62 ,144,3 }, //..x..xx..x..xxx.xx..x.....x....x....x.x..xxxxx......x..xxx Omastar
	{ 100,50 ,23 ,140,208,62 ,144,1 }, //..x..xx..x..xx..xxx.x.....xx...x....x.xx.xxxxx......x..xx. Kabuto
	{ 100,114,23 ,204,208,62 ,148,3 }, //..x..xx..x..xxx.xxx.x.....xx..xx....x.xx.xxxxx....x.x..xxx Kabutops
	{ 50 ,78 ,83 ,134,244,127,168,0 }, //.x..xx...xxx..x.xx..x.x..xx....x..x.xxxxxxxxxxx....x.x.x.. Aerodactyl
	{ 37 ,118,179,247,118,30 ,48 ,0 }, //x.x..x...xx.xxx.xx..xx.xxxx.xxxx.xx.xxx..xxxx.......xx.... Snorlax
	{ 116,118,19 ,132,145,78 ,136,0 }, //..x.xxx..xx.xxx.xx..x.....x....xx...x..x.xxx..x....x...x.. Articuno
	{ 48 ,198,147,133,146,78 ,200,0 }, //....xx...xx...xxxx..x..xx.x....x.x..x..x.xxx..x....x..xx.. Zapdos
	{ 48 ,70 ,27 ,132,180,78 ,138,0 }, //....xx...xx...x.xx.xx.....x....x..x.xx.x.xxx..x..x.x...x.. Moltres
	{ 100,118,219,133,38 ,30 ,16 ,1 }, //..x..xx..xx.xxx.xx.xx.xxx.x....x.xx..x...xxxx.......x...x. Dratini
	{ 100,118,219,133,38 ,30 ,16 ,1 }, //..x..xx..xx.xxx.xx.xx.xxx.x....x.xx..x...xxxx.......x...x. Dragonair
	{ 119,118,219,199,246,94 ,188,3 }, //xxx.xxx..xx.xxx.xx.xx.xxxxx...xx.xx.xxxx.xxxx.x...xxxx.xxx Dragonite
	{ 237,254,251,247,247,143,225,0 }, //x.xx.xxx.xxxxxxxxx.xxxxxxxx.xxxxxxx.xxxxxxxx...xx....xxx.. Mewtwo
	{ 255,255,255,255,255,255,255,3 }, //xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx Mew
	{ 32 ,135,125,132,1  ,30 ,68 ,0 }, //.....x..xxx....xx.xxxxx...x....xx........xxxx.....x...x... Chikorita
	{ 32 ,135,125,132,1  ,30 ,228,0 }, //.....x..xxx....xx.xxxxx...x....xx........xxxx.....x..xxx.. Bayleef
	{ 32 ,199,125,134,1  ,30 ,228,0 }, //.....x..xxx...xxx.xxxxx..xx....xx........xxxx.....x..xxx.. Meganium
	{ 32 ,6  ,17 ,140,164,30 ,6  ,0 }, //.....x...xx.....x...x.....xx...x..x..x.x.xxxx....xx....... Cyndaquil
	{ 49 ,6  ,17 ,204,164,30 ,166,0 }, //x...xx...xx.....x...x.....xx..xx..x..x.x.xxxx....xx..x.x.. Quilava
	{ 49 ,70 ,17 ,206,164,30 ,166,0 }, //x...xx...xx...x.x...x....xxx..xx..x..x.x.xxxx....xx..x.x.. Typhlosion
	{ 101,50 ,83 ,204,128,30 ,20 ,3 }, //x.x..xx..x..xx..xx..x.x...xx..xx.......x.xxxx.....x.x...xx Totodile
	{ 117,50 ,83 ,204,128,30 ,180,3 }, //x.x.xxx..x..xx..xx..x.x...xx..xx.......x.xxxx.....x.xx.xxx Croconaw
	{ 119,114,83 ,206,128,30 ,180,3 }, //xxx.xxx..x..xxx.xx..x.x..xxx..xx.......x.xxxx.....x.xx.xxx Feraligatr
	{ 37 ,22 ,243,236,6  ,62 ,20 ,0 }, //x.x..x...xx.x...xx..xxxx..xx.xxx.xx......xxxxx....x.x..... Sentret
	{ 37 ,118,243,237,6  ,62 ,180,0 }, //x.x..x...xx.xxx.xx..xxxxx.xx.xxx.xx......xxxxx....x.xx.x.. Furret
	{ 32 ,6  ,19 ,180,129,126,72 ,0 }, //.....x...xx.....xx..x.....x.xx.xx......x.xxxxxx....x..x... Hoothoot
	{ 32 ,70 ,19 ,180,129,126,72 ,0 }, //.....x...xx...x.xx..x.....x.xx.xx......x.xxxxxx....x..x... Noctowl
	{ 33 ,134,61 ,204,129,62 ,64 ,0 }, //x....x...xx....xx.xxxx....xx..xxx......x.xxxxx........x... Ledyba
	{ 33 ,198,61 ,204,129,62 ,64 ,0 }, //x....x...xx...xxx.xxxx....xx..xxx......x.xxxxx........x... Ledian
	{ 32 ,6  ,53 ,156,8  ,62 ,64 ,0 }, //.....x...xx.....x.x.xx....xxx..x...x.....xxxxx........x... Spinarak
	{ 32 ,70 ,53 ,156,8  ,62 ,64 ,0 }, //.....x...xx...x.x.x.xx....xxx..x...x.....xxxxx........x... Ariados
	{ 32 ,78 ,23 ,164,136,127,9  ,0 }, //.....x...xxx..x.xxx.x.....x..x.x...x...xxxxxxxx.x..x...... Crobat
	{ 100,50 ,147,133,2  ,30 ,80 ,3 }, //..x..xx..x..xx..xx..x..xx.x....x.x.......xxxx.......x.x.xx Chinchou
	{ 100,114,147,133,2  ,30 ,80 ,3 }, //..x..xx..x..xxx.xx..x..xx.x....x.x.......xxxx.......x.x.xx Lanturn
	{ 32 ,130,211,133,2  ,30 ,64 ,0 }, //.....x...x.....xxx..x.xxx.x....x.x.......xxxx.........x... Pichu
	{ 36 ,134,123,188,39 ,30 ,64 ,0 }, //..x..x...xx....xxx.xxxx...xxxx.xxxx..x...xxxx.........x... Cleffa
	{ 36 ,134,59 ,188,39 ,30 ,64 ,0 }, //..x..x...xx....xxx.xxx....xxxx.xxxx..x...xxxx.........x... Igglybuff
	{ 36 ,134,59 ,180,39 ,30 ,192,0 }, //..x..x...xx....xxx.xxx....x.xx.xxxx..x...xxxx.........xx.. Togepi
	{ 37 ,198,59 ,244,167,94 ,200,0 }, //x.x..x...xx...xxxx.xxx....x.xxxxxxx..x.x.xxxx.x....x..xx.. Togetic
	{ 40 ,134,55 ,180,129,254,64 ,0 }, //...x.x...xx....xxxx.xx....x.xx.xx......x.xxxxxxx......x... Natu
	{ 40 ,198,55 ,180,129,254,72 ,0 }, //...x.x...xx...xxxxx.xx....x.xx.xx......x.xxxxxxx...x..x... Xatu
	{ 32 ,130,211,133,2  ,30 ,64 ,0 }, //.....x...x.....xxx..x.xxx.x....x.x.......xxxx.........x... Mareep
	{ 33 ,130,211,197,2  ,30 ,224,0 }, //x....x...x.....xxx..x.xxx.x...xx.x.......xxxx........xxx.. Flaaffy
	{ 33 ,194,211,197,2  ,30 ,224,0 }, //x....x...x....xxxx..x.xxx.x...xx.x.......xxxx........xxx.. Ampharos
	{ 32 ,71 ,61 ,132,8  ,30 ,68 ,0 }, //.....x..xxx...x.x.xxxx....x....x...x.....xxxx.....x...x... Bellossom
	{ 101,50 ,83 ,204,0  ,30 ,176,3 }, //x.x..xx..x..xx..xx..x.x...xx..xx.........xxxx.......xx.xxx Marill
	{ 101,114,83 ,204,0  ,30 ,176,3 }, //x.x..xx..x..xxx.xx..x.x...xx..xx.........xxxx.......xx.xxx Azumarill
	{ 41 ,14 ,17 ,206,80 ,62 ,160,0 }, //x..x.x...xxx....x...x....xxx..xx....x.x..xxxxx.......x.x.. Sudowoodo
	{ 101,114,19 ,222,0  ,62 ,176,3 }, //x.x..xx..x..xxx.xx..x....xxxx.xx.........xxxxx......xx.xxx Politoed
	{ 32 ,7  ,53 ,132,128,30 ,64 ,0 }, //.....x..xxx.....x.x.xx....x....x.......x.xxxx.........x... Hoppip
	{ 32 ,7  ,53 ,132,128,30 ,64 ,0 }, //.....x..xxx.....x.x.xx....x....x.......x.xxxx.........x... Skiploom
	{ 32 ,71 ,53 ,132,128,30 ,64 ,0 }, //.....x..xxx...x.x.x.xx....x....x.......x.xxxx.........x... Jumpluff
	{ 37 ,14 ,243,237,130,62 ,165,0 }, //x.x..x...xxx....xx..xxxxx.xx.xxx.x.....x.xxxxx..x.x..x.x.. Aipom
	{ 32 ,135,61 ,132,8  ,30 ,68 ,0 }, //.....x..xxx....xx.xxxx....x....x...x.....xxxx.....x...x... Sunkern
	{ 32 ,199,61 ,132,8  ,30 ,68 ,0 }, //.....x..xxx...xxx.xxxx....x....x...x.....xxxx.....x...x... Sunflora
	{ 32 ,6  ,53 ,180,128,126,64 ,0 }, //.....x...xx.....x.x.xx....x.xx.x.......x.xxxxxx.......x... Yanma
	{ 100,50 ,83 ,142,24 ,30 ,208,3 }, //..x..xx..x..xx..xx..x.x..xxx...x...xx....xxxx.......x.xxxx Wooper
	{ 101,114,83 ,206,88 ,30 ,240,3 }, //x.x..xx..x..xxx.xx..x.x..xxx..xx...xx.x..xxxx.......xxxxxx Quagsire
	{ 40 ,198,83 ,188,1  ,158,68 ,0 }, //...x.x...xx...xxxx..x.x...xxxx.xx........xxxx..x..x...x... Espeon
	{ 32 ,78 ,83 ,188,0  ,31 ,69 ,0 }, //.....x...xxx..x.xx..x.x...xxxx.x........xxxxx...x.x...x... Umbreon
	{ 40 ,14 ,19 ,164,128,127,9  ,0 }, //...x.x...xxx....xx..x.....x..x.x.......xxxxxxxx.x..x...... Murkrow
	{ 109,118,91 ,254,36 ,158,240,2 }, //x.xx.xx..xx.xxx.xx.xx.x..xxxxxxx..x..x...xxxx..x....xxxx.x Slowking
	{ 40 ,14 ,147,181,130,191,65 ,0 }, //...x.x...xxx....xx..x..xx.x.xx.x.x.....xxxxxxx.xx.....x... Misdreavus
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Unown
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Wobbuffet
	{ 40 ,134,211,183,3  ,190,224,0 }, //...x.x...xx....xxx..x.xxxxx.xx.xxx.......xxxxx.x.....xxx.. Girafarig
	{ 32 ,134,53 ,142,17 ,30 ,160,0 }, //.....x...xx....xx.x.xx...xxx...xx...x....xxxx........x.x.. Pineco
	{ 32 ,198,53 ,142,17 ,30 ,160,0 }, //.....x...xx...xxx.x.xx...xxx...xx...x....xxxx........x.x.. Forretress
	{ 44 ,54 ,243,175,102,62 ,160,0 }, //..xx.x...xx.xx..xx..xxxxxxxx.x.x.xx..xx..xxxxx.......x.x.. Dunsparce
	{ 32 ,6  ,83 ,142,216,126,164,0 }, //.....x...xx.....xx..x.x..xxx...x...xx.xx.xxxxxx...x..x.x.. Gligar
	{ 48 ,78 ,81 ,142,80 ,31 ,164,0 }, //....xx...xxx..x.x...x.x..xxx...x....x.x.xxxxx.....x..x.x.. Steelix
	{ 181,14 ,179,239,46 ,63 ,162,0 }, //x.x.xx.x.xxx....xx..xx.xxxxx.xxx.xxx.x..xxxxxx...x...x.x.. Snubbull
	{ 181,78 ,243,239,110,63 ,162,0 }, //x.x.xx.x.xxx..x.xx..xxxxxxxx.xxx.xxx.xx.xxxxxx...x...x.x.. Granbull
	{ 100,50 ,19 ,164,10 ,30 ,16 ,3 }, //..x..xx..x..xx..xx..x.....x..x.x.x.x.....xxxx.......x...xx Qwilfish
	{ 32 ,70 ,19 ,132,144,126,164,0 }, //.....x...xx...x.xx..x.....x....x....x..x.xxxxxx...x..x.x.. Scizor
	{ 32 ,6  ,25 ,142,88 ,30 ,224,0 }, //.....x...xx.....x..xx....xxx...x...xx.x..xxxx........xxx.. Shuckle
	{ 161,70 ,19 ,206,64 ,62 ,164,0 }, //x....x.x.xx...x.xx..x....xxx..xx......x..xxxxx....x..x.x.. Heracross
	{ 105,62 ,83 ,236,128,63 ,181,0 }, //x..x.xx..xxxxx..xx..x.x...xx.xxx.......xxxxxxx..x.x.xx.x.. Sneasel
	{ 177,14 ,19 ,206,128,63 ,164,0 }, //x...xx.x.xxx....xx..x....xxx..xx.......xxxxxxx....x..x.x.. Teddiursa
	{ 177,78 ,19 ,206,192,63 ,164,0 }, //x...xx.x.xxx..x.xx..x....xxx..xx......xxxxxxxx....x..x.x.. Ursaring
	{ 32 ,134,17 ,132,37 ,30 ,130,0 }, //.....x...xx....xx...x.....x....xx.x..x...xxxx....x.....x.. Slugma
	{ 32 ,198,17 ,134,117,30 ,162,0 }, //.....x...xx...xxx...x....xx....xx.x.xxx..xxxx....x...x.x.. Magcargo
	{ 112,178,19 ,142,81 ,30 ,160,0 }, //....xxx..x..xx.xxx..x....xxx...xx...x.x..xxxx........x.x.. Swinub
	{ 112,242,19 ,142,81 ,30 ,160,0 }, //....xxx..x..xxxxxx..x....xxx...xx...x.x..xxxx........x.x.. Piloswine
	{ 108,182,27 ,190,81 ,30 ,176,0 }, //..xx.xx..xx.xx.xxx.xx....xxxxx.xx...x.x..xxxx.......xx.x.. Corsola
	{ 36 ,118,19 ,148,36 ,62 ,16 ,3 }, //..x..x...xx.xxx.xx..x.....x.x..x..x..x...xxxxx......x...xx Remoraid
	{ 36 ,119,19 ,148,44 ,62 ,16 ,3 }, //..x..x..xxx.xxx.xx..x.....x.x..x..xx.x...xxxxx......x...xx Octillery
	{ 101,50 ,19 ,132,128,62 ,8  ,0 }, //x.x..xx..x..xx..xx..x.....x....x.......x.xxxxx.....x...... Delibird
	{ 100,50 ,19 ,134,128,30 ,16 ,3 }, //..x..xx..x..xx..xx..x....xx....x.......x.xxxx.......x...xx Mantine
	{ 48 ,14 ,17 ,132,144,127,140,0 }, //....xx...xxx....x...x.....x....x....x..xxxxxxxx...xx...x.. Skarmory
	{ 48 ,14 ,113,164,44 ,63 ,131,0 }, //....xx...xxx....x...xxx...x..x.x..xx.x..xxxxxx..xx.....x.. Houndour
	{ 48 ,78 ,113,164,44 ,63 ,163,0 }, //....xx...xxx..x.x...xxx...x..x.x..xx.x..xxxxxx..xx...x.x.. Houndoom
	{ 100,114,19 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xxx.xx..x.....x....x.........xxxx.......x...xx Kingdra
	{ 48 ,6  ,81 ,134,80 ,30 ,160,0 }, //....xx...xx.....x...x.x..xx....x....x.x..xxxx........x.x.. Phanpy
	{ 48 ,70 ,81 ,134,80 ,30 ,160,0 }, //....xx...xx...x.x...x.x..xx....x....x.x..xxxx........x.x.. Donphan
	{ 32 ,118,243,181,130,46 ,64 ,0 }, //.....x...xx.xxx.xx..xxxxx.x.xx.x.x.....x.xxx.x........x... Porygon2
	{ 56 ,134,243,183,3  ,190,64 ,0 }, //...xxx...xx....xxx..xxxxxxx.xx.xxx.......xxxxx.x......x... Stantler
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Smeargle
	{ 160,6  ,19 ,198,0  ,62 ,160,0 }, //.....x.x.xx.....xx..x....xx...xx.........xxxxx.......x.x.. Tyrogue
	{ 160,6  ,19 ,206,16 ,62 ,160,0 }, //.....x.x.xx.....xx..x....xxx..xx....x....xxxxx.......x.x.. Hitmontop
	{ 108,178,19 ,180,1  ,190,64 ,0 }, //..xx.xx..x..xx.xxx..x.....x.xx.xx........xxxxx.x......x... Smoochum
	{ 33 ,130,147,213,2  ,62 ,192,0 }, //x....x...x.....xxx..x..xx.x.x.xx.x.......xxxxx........xx.. Elekid
	{ 33 ,6  ,81 ,212,36 ,62 ,128,0 }, //x....x...xx.....x...x.x...x.x.xx..x..x...xxxxx.........x.. Magby
	{ 37 ,118,243,231,82 ,30 ,176,0 }, //x.x..x...xx.xxx.xx..xxxxxxx..xxx.x..x.x..xxxx.......xx.x.. Miltank
	{ 109,246,251,247,118,158,225,0 }, //x.xx.xx..xx.xxxxxx.xxxxxxxx.xxxx.xx.xxx..xxxx..xx....xxx.. Blissey
	{ 56 ,70 ,211,141,19 ,14 ,228,0 }, //...xxx...xx...x.xx..x.xxx.xx...xxx..x....xxx......x..xxx.. Raikou
	{ 56 ,70 ,115,140,53 ,14 ,228,0 }, //...xxx...xx...x.xx..xxx...xx...xx.x.xx...xxx......x..xxx.. Entei
	{ 124,118,83 ,140,17 ,14 ,148,3 }, //..xxxxx..xx.xxx.xx..x.x...xx...xx...x....xxx......x.x..xxx Suicune
	{ 32 ,78 ,19 ,206,16 ,31 ,128,0 }, //.....x...xxx..x.xx..x....xxx..xx....x...xxxxx..........x.. Larvitar
	{ 32 ,78 ,19 ,206,16 ,31 ,128,0 }, //.....x...xxx..x.xx..x....xxx..xx....x...xxxxx..........x.. Pupitar
	{ 55 ,126,211,207,246,31 ,180,0 }, //xxx.xx...xxxxxx.xx..x.xxxxxx..xx.xx.xxxxxxxxx.....x.xx.x.. Tyranitar
	{ 124,246,223,183,147,206,184,3 }, //..xxxxx..xx.xxxxxxxxx.xxxxx.xx.xxx..x..x.xxx..xx...xxx.xxx Lugia
	{ 56 ,198,191,183,183,78 ,234,0 }, //...xxx...xx...xxxxxxxx.xxxx.xx.xxxx.xx.x.xxx..x..x.x.xxx.. Ho-oh
	{ 44 ,198,63 ,180,147,142,68 ,0 }, //..xx.x...xx...xxxxxxxx....x.xx.xxx..x..x.xxx...x..x...x... Celebi
	{ 33 ,7  ,125,204,192,30 ,228,0 }, //x....x..xxx.....x.xxxxx...xx..xx......xx.xxxx.....x..xxx.. Treecko
	{ 33 ,7  ,125,204,192,30 ,228,0 }, //x....x..xxx.....x.xxxxx...xx..xx......xx.xxxx.....x..xxx.. Grovyle
	{ 51 ,71 ,125,206,192,30 ,228,0 }, //xx..xx..xxx...x.x.xxxxx..xxx..xx......xx.xxxx.....x..xxx.. Sceptile
	{ 32 ,6  ,17 ,140,228,30 ,166,0 }, //.....x...xx.....x...x.....xx...x..x..xxx.xxxx....xx..x.x.. Torchic
	{ 161,6  ,17 ,204,228,30 ,166,0 }, //x....x.x.xx.....x...x.....xx..xx..x..xxx.xxxx....xx..x.x.. Combusken
	{ 177,70 ,17 ,206,228,30 ,166,0 }, //x...xx.x.xx...x.x...x....xxx..xx..x..xxx.xxxx....xx..x.x.. Blaziken
	{ 100,50 ,83 ,140,64 ,30 ,176,3 }, //..x..xx..x..xx..xx..x.x...xx...x......x..xxxx.......xx.xxx Mudkip
	{ 100,50 ,83 ,142,64 ,30 ,176,3 }, //..x..xx..x..xx..xx..x.x..xxx...x......x..xxxx.......xx.xxx Marshtomp
	{ 117,114,83 ,206,64 ,30 ,176,3 }, //x.x.xxx..x..xxx.xx..x.x..xxx..xx......x..xxxx.......xx.xxx Swampert
	{ 48 ,14 ,83 ,172,0  ,63 ,129,0 }, //....xx...xxx....xx..x.x...xx.x.x........xxxxxx..x......x.. Poochyena
	{ 48 ,78 ,83 ,172,0  ,63 ,161,0 }, //....xx...xxx..x.xx..x.x...xx.x.x........xxxxxx..x....x.x.. Mightyena
	{ 36 ,54 ,211,173,2  ,62 ,148,0 }, //..x..x...xx.xx..xx..x.xxx.xx.x.x.x.......xxxxx....x.x..x.. Zigzagoon
	{ 52 ,118,211,173,2  ,62 ,180,0 }, //..x.xx...xx.xxx.xx..x.xxx.xx.x.x.x.......xxxxx....x.xx.x.. Linoone
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Wurmple
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Silcoon
	{ 32 ,70 ,61 ,180,128,62 ,64 ,0 }, //.....x...xx...x.x.xxxx....x.xx.x.......x.xxxxx........x... Beautifly
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Cascoon
	{ 32 ,198,53 ,180,136,62 ,64 ,0 }, //.....x...xx...xxx.x.xx....x.xx.x...x...x.xxxxx........x... Dustox
	{ 100,55 ,55 ,132,0  ,62 ,80 ,0 }, //..x..xx.xxx.xx..xxx.xx....x....x.........xxxxx......x.x... Lotad
	{ 100,55 ,55 ,196,0  ,62 ,240,3 }, //..x..xx.xxx.xx..xxx.xx....x...xx.........xxxxx......xxxxxx Lombre
	{ 101,119,55 ,196,0  ,62 ,240,3 }, //x.x..xx.xxx.xxx.xxx.xx....x...xx.........xxxxx......xxxxxx Ludicolo
	{ 32 ,7  ,53 ,172,0  ,30 ,192,0 }, //.....x..xxx.....x.x.xx....xx.x.x.........xxxx.........xx.. Seedot
	{ 32 ,71 ,53 ,236,64 ,63 ,228,0 }, //.....x..xxx...x.x.x.xx....xx.xxx......x.xxxxxx....x..xxx.. Nuzleaf
	{ 32 ,71 ,53 ,236,192,63 ,228,0 }, //.....x..xxx...x.x.x.xx....xx.xxx......xxxxxxxx....x..xxx.. Shiftry
	{ 32 ,6  ,53 ,172,144,14 ,68 ,0 }, //.....x...xx.....x.x.xx....xx.x.x....x..x.xxx......x...x... Nincada
	{ 32 ,70 ,53 ,172,144,62 ,68 ,0 }, //.....x...xx...x.x.x.xx....xx.x.x....x..x.xxxxx....x...x... Ninjask
	{ 32 ,70 ,53 ,172,144,46 ,68 ,0 }, //.....x...xx...x.x.x.xx....xx.x.x....x..x.xxx.x....x...x... Shedinja
	{ 32 ,6  ,19 ,132,128,126,8  ,0 }, //.....x...xx.....xx..x.....x....x.......x.xxxxxx....x...... Taillow
	{ 32 ,70 ,19 ,132,128,126,8  ,0 }, //.....x...xx...x.xx..x.....x....x.......x.xxxxxx....x...... Swellow
	{ 32 ,7  ,61 ,132,8  ,30 ,65 ,0 }, //.....x..xxx.....x.xxxx....x....x...x.....xxxx...x.....x... Shroomish
	{ 161,71 ,125,196,8  ,30 ,229,0 }, //x....x.xxxx...x.x.xxxxx...x...xx...x.....xxxx...x.x..xxx.. Breloom
	{ 45 ,6  ,27 ,252,66 ,190,225,0 }, //x.xx.x...xx.....xx.xx.....xxxxxx.x....x..xxxxx.xx....xxx.. Spinda
	{ 100,50 ,19 ,132,130,126,8  ,0 }, //..x..xx..x..xx..xx..x.....x....x.x.....x.xxxxxx....x...... Wingull
	{ 100,114,19 ,132,130,126,24 ,0 }, //..x..xx..x..xxx.xx..x.....x....x.x.....x.xxxxxx....xx..... Pelipper
	{ 36 ,54 ,55 ,164,0  ,62 ,64 ,0 }, //..x..x...xx.xx..xxx.xx....x..x.x.........xxxxx........x... Surskit
	{ 36 ,118,55 ,164,128,62 ,64 ,0 }, //..x..x...xx.xxx.xxx.xx....x..x.x.......x.xxxxx........x... Masquerain
	{ 116,50 ,19 ,134,64 ,30 ,176,3 }, //..x.xxx..x..xx..xx..x....xx....x......x..xxxx.......xx.xxx Wailmer
	{ 116,114,19 ,134,64 ,30 ,176,3 }, //..x.xxx..x..xxx.xx..x....xx....x......x..xxxx.......xx.xxx Wailord
	{ 44 ,54 ,251,173,2  ,30 ,64 ,0 }, //..xx.x...xx.xx..xx.xxxxxx.xx.x.x.x.......xxxx.........x... Skitty
	{ 44 ,118,251,173,2  ,30 ,224,0 }, //..xx.x...xx.xxx.xx.xxxxxx.xx.x.x.x.......xxxx........xxx.. Delcatty
	{ 37 ,54 ,243,237,230,190,229,0 }, //x.x..x...xx.xx..xx..xxxxx.xx.xxx.xx..xxx.xxxxx.xx.x..xxx.. Kecleon
	{ 32 ,150,51 ,190,81 ,142,64 ,0 }, //.....x...xx.x..xxx..xx...xxxxx.xx...x.x..xxx...x......x... Baltoy
	{ 32 ,214,51 ,190,81 ,142,224,0 }, //.....x...xx.x.xxxx..xx...xxxxx.xx...x.x..xxx...x.....xxx.. Claydol
	{ 32 ,14 ,145,135,82 ,31 ,160,0 }, //.....x...xxx....x...x..xxxx....x.x..x.x.xxxxx........x.x.. Nosepass
	{ 32 ,6  ,81 ,132,44 ,30 ,162,0 }, //.....x...xx.....x...x.x...x....x..xx.x...xxxx....x...x.x.. Torkoal
	{ 45 ,14 ,19 ,252,194,63 ,197,0 }, //x.xx.x...xxx....xx..x.....xxxxxx.x....xxxxxxxx..x.x...xx.. Sableye
	{ 100,50 ,19 ,134,80 ,30 ,16 ,3 }, //..x..xx..x..xx..xx..x....xx....x....x.x..xxxx.......x...xx Barboach
	{ 100,114,19 ,134,80 ,30 ,176,3 }, //..x..xx..x..xxx.xx..x....xx....x....x.x..xxxx.......xx.xxx Whiscash
	{ 100,50 ,27 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xx..xx.xx.....x....x.........xxxx.......x...xx Luvdisc
	{ 100,58 ,19 ,204,200,30 ,180,1 }, //..x..xx..x.xxx..xx..x.....xx..xx...x..xx.xxxx.....x.xx.xx. Corphish
	{ 100,122,19 ,204,200,30 ,180,3 }, //..x..xx..x.xxxx.xx..x.....xx..xx...x..xx.xxxx.....x.xx.xxx Crawdaunt
	{ 100,50 ,19 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xx..xx..x.....x....x.........xxxx.......x...xx Feebas
	{ 100,114,91 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xxx.xx.xx.x...x....x.........xxxx.......x...xx Milotic
	{ 100,58 ,19 ,132,0  ,63 ,16 ,3 }, //..x..xx..x.xxx..xx..x.....x....x........xxxxxx......x...xx Carvanha
	{ 116,122,19 ,134,64 ,63 ,176,3 }, //..x.xxx..x.xxxx.xx..x....xx....x......x.xxxxxx......xx.xxx Sharpedo
	{ 32 ,70 ,53 ,142,80 ,30 ,160,0 }, //.....x...xx...x.x.x.xx...xxx...x....x.x..xxxx........x.x.. Trapinch
	{ 32 ,70 ,53 ,142,80 ,94 ,168,0 }, //.....x...xx...x.x.x.xx...xxx...x....x.x..xxxx.x....x.x.x.. Vibrava
	{ 34 ,70 ,117,142,116,94 ,168,0 }, //.x...x...xx...x.x.x.xxx..xxx...x..x.xxx..xxxx.x....x.x.x.. Flygon
	{ 161,6  ,19 ,206,64 ,30 ,176,0 }, //x....x.x.xx.....xx..x....xxx..xx......x..xxxx.......xx.x.. Makuhita
	{ 161,70 ,19 ,206,64 ,30 ,176,0 }, //x....x.x.xx...x.xx..x....xxx..xx......x..xxxx.......xx.x.. Hariyama
	{ 48 ,2  ,211,133,2  ,62 ,96 ,0 }, //....xx...x......xx..x.xxx.x....x.x.......xxxxx.......xx... Electrike
	{ 48 ,66 ,211,133,2  ,62 ,96 ,0 }, //....xx...x....x.xx..x.xxx.x....x.x.......xxxxx.......xx... Manectric
	{ 32 ,6  ,17 ,142,116,30 ,162,0 }, //.....x...xx.....x...x....xxx...x..x.xxx..xxxx....x...x.x.. Numel
	{ 48 ,70 ,17 ,142,116,30 ,162,0 }, //....xx...xx...x.x...x....xxx...x..x.xxx..xxxx....x...x.x.. Camerupt
	{ 100,50 ,83 ,134,64 ,30 ,176,3 }, //..x..xx..x..xx..xx..x.x..xx....x......x..xxxx.......xx.xxx Spheal
	{ 116,50 ,83 ,134,64 ,30 ,176,3 }, //..x.xxx..x..xx..xx..x.x..xx....x......x..xxxx.......xx.xxx Sealeo
	{ 116,114,83 ,134,64 ,30 ,176,3 }, //..x.xxx..x..xxx.xx..x.x..xx....x......x..xxxx.......xx.xxx Walrein
	{ 33 ,7  ,53 ,132,16 ,30 ,68 ,0 }, //x....x..xxx.....x.x.xx....x....x....x....xxxx.....x...x... Cacnea
	{ 33 ,71 ,53 ,132,16 ,30 ,100,0 }, //x....x..xxx...x.x.x.xx....x....x....x....xxxx.....x..xx... Cacturne
	{ 100,178,27 ,164,0  ,30 ,64 ,0 }, //..x..xx..x..xx.xxx.xx.....x..x.x.........xxxx.........x... Snorunt
	{ 100,250,27 ,166,0  ,31 ,64 ,0 }, //..x..xx..x.xxxxxxx.xx....xx..x.x........xxxxx.........x... Glalie
	{ 40 ,210,27 ,182,81 ,142,64 ,0 }, //...x.x...x..x.xxxx.xx....xx.xx.xx...x.x..xxx...x......x... Lunatone
	{ 40 ,198,57 ,182,117,142,66 ,0 }, //...x.x...xx...xxx..xxx...xx.xx.xx.x.xxx..xxx...x.x....x... Solrock
	{ 100,50 ,83 ,132,0  ,30 ,16 ,1 }, //..x..xx..x..xx..xx..x.x...x....x.........xxxx.......x...x. Azurill
	{ 40 ,142,83 ,180,3  ,191,65 ,0 }, //...x.x...xxx...xxx..x.x...x.xx.xxx......xxxxxx.xx.....x... Spoink
	{ 41 ,206,83 ,180,3  ,191,65 ,0 }, //x..x.x...xxx..xxxx..x.x...x.xx.xxx......xxxxxx.xx.....x... Grumpig
	{ 32 ,130,211,133,2  ,30 ,64 ,0 }, //.....x...x.....xxx..x.xxx.x....x.x.......xxxx.........x... Plusle
	{ 32 ,130,211,133,2  ,30 ,64 ,0 }, //.....x...x.....xxx..x.xxx.x....x.x.......xxxx.........x... Minun
	{ 33 ,94 ,51 ,196,124,31 ,160,0 }, //x....x...xxxx.x.xx..xx....x...xx..xxxxx.xxxxx........x.x.. Mawile
	{ 169,134,19 ,244,65 ,30 ,224,0 }, //x..x.x.x.xx....xxx..x.....x.xxxxx.....x..xxxx........xxx.. Meditite
	{ 169,198,19 ,244,65 ,30 ,224,0 }, //x..x.x.x.xx...xxxx..x.....x.xxxxx.....x..xxxx........xxx.. Medicham
	{ 32 ,22 ,59 ,132,128,126,8  ,0 }, //.....x...xx.x...xx.xxx....x....x.......x.xxxxxx....x...... Swablu
	{ 50 ,86 ,123,134,164,126,136,0 }, //.x..xx...xx.x.x.xx.xxxx..xx....x..x..x.x.xxxxxx....x...x.. Altaria
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Wynaut
	{ 40 ,62 ,19 ,180,0  ,191,65 ,0 }, //...x.x...xxxxx..xx..x.....x.xx.x........xxxxxx.xx.....x... Duskull
	{ 41 ,126,19 ,182,64 ,191,225,0 }, //x..x.x...xxxxxx.xx..x....xx.xx.x......x.xxxxxx.xx....xxx.. Dusclops
	{ 32 ,7  ,53 ,164,8  ,30 ,68 ,0 }, //.....x..xxx.....x.x.xx....x..x.x...x.....xxxx.....x...x... Roselia
	{ 165,54 ,179,229,166,30 ,164,0 }, //x.x..x.x.xx.xx..xx..xx.xx.x..xxx.xx..x.x.xxxx.....x..x.x.. Slakoth
	{ 181,62 ,179,231,166,30 ,164,0 }, //x.x.xx.x.xxxxx..xx..xx.xxxx..xxx.xx..x.x.xxxx.....x..x.x.. Vigoroth
	{ 181,126,179,231,166,30 ,164,0 }, //x.x.xx.x.xxxxxx.xx..xx.xxxx..xxx.xx..x.x.xxxx.....x..x.x.. Slaking
	{ 36 ,23 ,55 ,164,10 ,30 ,161,0 }, //..x..x..xxx.x...xxx.xx....x..x.x.x.x.....xxxx...x....x.x.. Gulpin
	{ 36 ,87 ,55 ,164,10 ,30 ,161,0 }, //..x..x..xxx.x.x.xxx.xx....x..x.x.x.x.....xxxx...x....x.x.. Swalot
	{ 48 ,71 ,61 ,134,128,94 ,236,0 }, //....xx..xxx...x.x.xxxx...xx....x.......x.xxxx.x...xx.xxx.. Tropius
	{ 52 ,54 ,51 ,164,38 ,30 ,0  ,0 }, //..x.xx...xx.xx..xx..xx....x..x.x.xx..x...xxxx............. Whismur
	{ 52 ,62 ,51 ,230,38 ,31 ,162,0 }, //..x.xx...xxxxx..xx..xx...xx..xxx.xx..x..xxxxx....x...x.x.. Loudred
	{ 52 ,126,51 ,230,38 ,31 ,162,0 }, //..x.xx...xxxxxx.xx..xx...xx..xxx.xx..x..xxxxx....x...x.x.. Exploud
	{ 100,50 ,19 ,132,0  ,30 ,16 ,3 }, //..x..xx..x..xx..xx..x.....x....x.........xxxx.......x...xx Clamperl
	{ 100,114,19 ,132,64 ,30 ,17 ,3 }, //..x..xx..x..xxx.xx..x.....x....x......x..xxxx...x...x...xx Huntail
	{ 100,114,27 ,180,0  ,30 ,16 ,3 }, //..x..xx..x..xxx.xx.xx.....x.xx.x.........xxxx.......x...xx Gorebyss
	{ 108,126,211,165,182,63 ,229,0 }, //..xx.xx..xxxxxx.xx..x.xxx.x..x.x.xx.xx.xxxxxxx..x.x..xxx.. Absol
	{ 40 ,14 ,147,181,2  ,191,65 ,0 }, //...x.x...xxx....xx..x..xx.x.xx.x.x......xxxxxx.xx.....x... Shuppet
	{ 40 ,78 ,147,181,2  ,191,65 ,0 }, //...x.x...xxx..x.xx..x..xx.x.xx.x.x......xxxxxx.xx.....x... Banette
	{ 32 ,14 ,87 ,142,12 ,62 ,161,0 }, //.....x...xxx....xxx.x.x..xxx...x..xx.....xxxxx..x....x.x.. Seviper
	{ 53 ,62 ,247,237,166,62 ,160,0 }, //x.x.xx...xxxxx..xxx.xxxxx.xx.xxx.xx..x.x.xxxxx.......x.x.. Zangoose
	{ 108,114,27 ,134,80 ,30 ,144,3 }, //..xx.xx..x..xxx.xx.xx....xx....x....x.x..xxxx.......x..xxx Relicanth
	{ 52 ,6  ,83 ,142,210,30 ,164,0 }, //..x.xx...xx.....xx..x.x..xxx...x.x..x.xx.xxxx.....x..x.x.. Aron
	{ 52 ,6  ,83 ,142,210,30 ,164,0 }, //..x.xx...xx.....xx..x.x..xxx...x.x..x.xx.xxxx.....x..x.x.. Lairon
	{ 55 ,126,243,207,246,30 ,180,0 }, //xxx.xx...xxxxxx.xx..xxxxxxxx..xx.xx.xxxx.xxxx.....x.xx.x.. Aggron
	{ 100,54 ,179,165,54 ,62 ,64 ,0 }, //..x..xx..xx.xx..xx..xx.xx.x..x.x.xx.xx...xxxxx........x... Castform
	{ 37 ,134,183,229,130,62 ,64 ,0 }, //x.x..x...xx....xxxx.xx.xx.x..xxx.x.....x.xxxxx........x... Volbeat
	{ 37 ,134,183,229,130,62 ,64 ,0 }, //x.x..x...xx....xxxx.xx.xx.x..xxx.x.....x.xxxxx........x... Illumise
	{ 32 ,7  ,53 ,132,24 ,30 ,0  ,0 }, //.....x..xxx.....x.x.xx....x....x...xx....xxxx............. Lileep
	{ 32 ,71 ,53 ,134,88 ,30 ,160,0 }, //.....x..xxx...x.x.x.xx...xx....x...xx.x..xxxx........x.x.. Cradily
	{ 36 ,6  ,17 ,204,208,30 ,132,0 }, //..x..x...xx.....x...x.....xx..xx....x.xx.xxxx.....x....x.. Anorith
	{ 36 ,70 ,81 ,206,208,30 ,164,0 }, //..x..x...xx...x.x...x.x..xxx..xx....x.xx.xxxx.....x..x.x.. Armaldo
	{ 40 ,142,155,180,3  ,191,65 ,0 }, //...x.x...xxx...xxx.xx..x..x.xx.xxx......xxxxxx.xx.....x... Ralts
	{ 40 ,142,155,180,3  ,191,65 ,0 }, //...x.x...xxx...xxx.xx..x..x.xx.xxx......xxxxxx.xx.....x... Kirlia
	{ 40 ,206,155,180,3  ,191,65 ,0 }, //...x.x...xxx..xxxx.xx..x..x.xx.xxx......xxxxxx.xx.....x... Gardevoir
	{ 50 ,6  ,19 ,196,228,30 ,164,0 }, //.x..xx...xx.....xx..x.....x...xx..x..xxx.xxxx.....x..x.x.. Bagon
	{ 50 ,6  ,19 ,196,228,30 ,164,0 }, //.x..xx...xx.....xx..x.....x...xx..x..xxx.xxxx.....x..x.x.. Shelgon
	{ 50 ,70 ,83 ,198,228,94 ,172,0 }, //.x..xx...xx...x.xx..x.x..xx...xx..x..xxx.xxxx.x...xx.x.x.. Salamence
	{ 0  ,0  ,0  ,0  ,0  ,0  ,0  ,0 }, //.......................................................... Beldum
	{ 32 ,198,19 ,246,217,14 ,228,0 }, //.....x...xx...xxxx..x....xx.xxxxx..xx.xx.xxx......x..xxx.. Metang
	{ 32 ,198,19 ,246,217,14 ,228,0 }, //.....x...xx...xxxx..x....xx.xxxxx..xx.xx.xxx......x..xxx.. Metagross
	{ 33 ,70 ,153,207,82 ,14 ,160,0 }, //x....x...xx...x.x..xx..xxxxx..xx.x..x.x..xxx.........x.x.. Regirock
	{ 97 ,114,155,199,2  ,14 ,160,0 }, //x....xx..x..xxx.xx.xx..xxxx...xx.x.......xxx.........x.x.. Regice
	{ 33 ,70 ,155,199,210,14 ,160,0 }, //x....x...xx...x.xx.xx..xxxx...xx.x..x.xx.xxx.........x.x.. Registeel
	{ 124,114,155,199,66 ,14 ,176,3 }, //..xxxxx..x..xxx.xx.xx..xxxx...xx.x....x..xxx........xx.xxx Kyogre
	{ 178,70 ,249,207,246,14 ,166,0 }, //.x..xx.x.xx...x.x..xxxxxxxxx..xx.xx.xxxx.xxx.....xx..x.x.. Groudon
	{ 182,118,243,199,182,14 ,186,3 }, //.xx.xx.x.xx.xxx.xx..xxxxxxx...xx.xx.xx.x.xxx.....x.xxx.xxx Rayquaza
	{ 62 ,214,187,183,147,94 ,92 ,3 }, //.xxxxx...xx.x.xxxx.xxx.xxxx.xx.xxx..x..x.xxxx.x...xxx.x.xx Latias
	{ 62 ,214,187,183,147,94 ,92 ,3 }, //.xxxxx...xx.x.xxxx.xxx.xxxx.xx.xxx..x..x.xxxx.x...xxx.x.xx Latios
	{ 44 ,198,155,181,147,142,64 ,0 }, //..xx.x...xx...xxxx.xx..xx.x.xx.xxx..x..x.xxx...x......x... Jirachi
	{ 45 ,222,187,245,195,143,229,0 }, //x.xx.x...xxxx.xxxx.xxx.xx.x.xxxxxx....xxxxxx...xx.x..xxx.. Deoxys
	{ 40 ,142,27 ,180,3  ,159,65 ,0 }, //...x.x...xxx...xxx.xx.....x.xx.xxx......xxxxx..xx.....x... Chimecho
};
