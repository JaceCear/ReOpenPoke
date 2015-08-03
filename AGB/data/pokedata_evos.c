#include "../openpoke.h"
//	0x3C78 before; 0x08C4 after // ignore
/*
	onePkmn:
		nrOfEvolutions,
		(Trigger, Param1, pk(Target), Param3) * nrOfEvolutions
*/

const unsigned short Evolutions[] =
{
	//#0 -
		0,
	//#1 - pkBulbasaur
		1,
		evoLevel, 16, pkIvysaur, 0,
	//#2 - pkIvysaur
		1,
		evoLevel, 32, pkVenusaur, 0,
	//#3 - pkVenusaur
		0,
	//#4 - pkCharmander
		1,
		evoLevel, 16, pkCharmeleon, 0,
	//#5 - pkCharmeleon
		1,
		evoLevel, 36, pkCharizard, 0,
	//#6 - pkCharizard
		0,
	//#7 - pkSquirtle
		1,
		evoLevel, 16, pkWartortle, 0,
	//#8 - pkWartortle
		1,
		evoLevel, 36, pkBlastoise, 0,
	//#9 - pkBlastoise
		0,
	//#10 - pkCaterpie
		1,
		evoLevel, 7, pkMetapod, 0,
	//#11 - pkMetapod
		1,
		evoLevel, 10, pkButterfree, 0,
	//#12 - pkButterfree
		0,
	//#13 - pkWeedle
		1,
		evoLevel, 7, pkKakuna, 0,
	//#14 - pkKakuna
		1,
		evoLevel, 10, pkBeedrill, 0,
	//#15 - pkBeedrill
		0,
	//#16 - pkPidgey
		1,
		evoLevel, 18, pkPidgeotto, 0,
	//#17 - pkPidgeotto
		1,
		evoLevel, 36, pkPidgeot, 0,
	//#18 - pkPidgeot
		0,
	//#19 - pkRattata
		1,
		evoLevel, 20, pkRaticate, 0,
	//#20 - pkRaticate
		0,
	//#21 - pkSpearow
		1,
		evoLevel, 20, pkFearow, 0,
	//#22 - pkFearow
		0,
	//#23 - pkEkans
		1,
		evoLevel, 22, pkArbok, 0,
	//#24 - pkArbok
		0,
	//#25 - pkPikachu
		1,
		evoItem, itemThunderStone, pkRaichu, 0,
	//#26 - pkRaichu
		0,
	//#27 - pkSandshrew
		1,
		evoLevel, 22, pkSandslash, 0,
	//#28 - pkSandslash
		0,
	//#29 - pkNidoranGirl
		1,
		evoLevel, 16, pkNidorina, 0,
	//#30 - pkNidorina
		1,
		evoItem, itemMoonStone, pkNidoqueen, 0,
	//#31 - pkNidoqueen
		0,
	//#32 - pkNidoranBoy
		1,
		evoLevel, 16, pkNidorino, 0,
	//#33 - pkNidorino
		1,
		evoItem, itemMoonStone, pkNidoking, 0,
	//#34 - pkNidoking
		0,
	//#35 - pkClefairy
		1,
		evoItem, itemMoonStone, pkClefable, 0,
	//#36 - pkClefable
		0,
	//#37 - pkVulpix
		1,
		evoItem, itemFireStone, pkNinetales, 0,
	//#38 - pkNinetales
		0,
	//#39 - pkJigglypuff
		1,
		evoItem, itemMoonStone, pkWigglytuff, 0,
	//#40 - pkWigglytuff
		0,
	//#41 - pkZubat
		1,
		evoLevel, 22, pkGolbat, 0,
	//#42 - pkGolbat
		1,
		evoHappy, 0, pkCrobat, 0,
	//#43 - pkOddish
		1,
		evoLevel, 21, pkGloom, 0,
	//#44 - pkGloom
		2,
		evoItem, itemLeafStone, pkVileplume, 0,
		evoItem, itemSunStone, pkBellossom, 0,
	//#45 - pkVileplume
		0,
	//#46 - pkParas
		1,
		evoLevel, 24, pkParasect, 0,
	//#47 - pkParasect
		0,
	//#48 - pkVenonat
		1,
		evoLevel, 31, pkVenomoth, 0,
	//#49 - pkVenomoth
		0,
	//#50 - pkDiglett
		1,
		evoLevel, 26, pkDugtrio, 0,
	//#51 - pkDugtrio
		0,
	//#52 - pkMeowth
		1,
		evoLevel, 28, pkPersian, 0,
	//#53 - pkPersian
		0,
	//#54 - pkPsyduck
		1,
		evoLevel, 33, pkGolduck, 0,
	//#55 - pkGolduck
		0,
	//#56 - pkMankey
		1,
		evoLevel, 28, pkPrimeape, 0,
	//#57 - pkPrimeape
		0,
	//#58 - pkGrowlithe
		1,
		evoItem, itemFireStone, pkArcanine, 0,
	//#59 - pkArcanine
		0,
	//#60 - pkPoliwag
		1,
		evoLevel, 25, pkPoliwhirl, 0,
	//#61 - pkPoliwhirl
		2,
		evoItem, itemWaterStone, pkPoliwrath, 0,
		evoItemTrade, itemKingsRock, pkPolitoed, 0,
	//#62 - pkPoliwrath
		0,
	//#63 - pkAbra
		1,
		evoLevel, 16, pkKadabra, 0,
	//#64 - pkKadabra
		1,
		evoTrade, 0, pkAlakazam, 0,
	//#65 - pkAlakazam
		0,
	//#66 - pkMachop
		1,
		evoLevel, 28, pkMachoke, 0,
	//#67 - pkMachoke
		1,
		evoTrade, 0, pkMachamp, 0,
	//#68 - pkMachamp
		0,
	//#69 - pkBellsprout
		1,
		evoLevel, 21, pkWeepinbell, 0,
	//#70 - pkWeepinbell
		1,
		evoItem, itemLeafStone, pkVictreebel, 0,
	//#71 - pkVictreebel
		0,
	//#72 - pkTentacool
		1,
		evoLevel, 30, pkTentacruel, 0,
	//#73 - pkTentacruel
		0,
	//#74 - pkGeodude
		1,
		evoLevel, 25, pkGraveler, 0,
	//#75 - pkGraveler
		1,
		evoTrade, 0, pkGolem, 0,
	//#76 - pkGolem
		0,
	//#77 - pkPonyta
		1,
		evoLevel, 40, pkRapidash, 0,
	//#78 - pkRapidash
		0,
	//#79 - pkSlowpoke
		2,
		evoLevel, 37, pkSlowbro, 0,
		evoItemTrade, itemKingsRock, pkSlowking, 0,
	//#80 - pkSlowbro
		0,
	//#81 - pkMagnemite
		1,
		evoLevel, 30, pkMagneton, 0,
	//#82 - pkMagneton
		0,
	//#83 - pkFarfetchd
		0,
	//#84 - pkDoduo
		1,
		evoLevel, 31, pkDodrio, 0,
	//#85 - pkDodrio
		0,
	//#86 - pkSeel
		1,
		evoLevel, 34, pkDewgong, 0,
	//#87 - pkDewgong
		0,
	//#88 - pkGrimer
		1,
		evoLevel, 38, pkMuk, 0,
	//#89 - pkMuk
		0,
	//#90 - pkShellder
		1,
		evoItem, itemWaterStone, pkCloyster, 0,
	//#91 - pkCloyster
		0,
	//#92 - pkGastly
		1,
		evoLevel, 25, pkHaunter, 0,
	//#93 - pkHaunter
		1,
		evoTrade, 0, pkGengar, 0,
	//#94 - pkGengar
		0,
	//#95 - pkOnix
		1,
		evoItemTrade, itemMetalCoat, pkSteelix, 0,
	//#96 - pkDrowzee
		1,
		evoLevel, 26, pkHypno, 0,
	//#97 - pkHypno
		0,
	//#98 - pkKrabby
		1,
		evoLevel, 28, pkKingler, 0,
	//#99 - pkKingler
		0,
	//#100 - pkVoltorb
		1,
		evoLevel, 30, pkElectrode, 0,
	//#101 - pkElectrode
		0,
	//#102 - pkExeggcute
		1,
		evoItem, itemLeafStone, pkExeggutor, 0,
	//#103 - pkExeggutor
		0,
	//#104 - pkCubone
		1,
		evoLevel, 28, pkMarowak, 0,
	//#105 - pkMarowak
		0,
	//#106 - pkHitmonlee
		0,
	//#107 - pkHitmonchan
		0,
	//#108 - pkLickitung
		0,
	//#109 - pkKoffing
		1,
		evoLevel, 35, pkWeezing, 0,
	//#110 - pkWeezing
		0,
	//#111 - pkRhyhorn
		1,
		evoLevel, 42, pkRhydon, 0,
	//#112 - pkRhydon
		0,
	//#113 - pkChansey
		1,
		evoHappy, 0, pkBlissey, 0,
	//#114 - pkTangela
		0,
	//#115 - pkKangaskhan
		0,
	//#116 - pkHorsea
		1,
		evoLevel, 32, pkSeadra, 0,
	//#117 - pkSeadra
		1,
		evoItemTrade, itemDragonScale, pkKingdra, 0,
	//#118 - pkGoldeen
		1,
		evoLevel, 33, pkSeaking, 0,
	//#119 - pkSeaking
		0,
	//#120 - pkStaryu
		1,
		evoItem, itemWaterStone, pkStarmie, 0,
	//#121 - pkStarmie
		0,
	//#122 - pkMrMime
		0,
	//#123 - pkScyther
		1,
		evoItemTrade, itemMetalCoat, pkScizor, 0,
	//#124 - pkJynx
		0,
	//#125 - pkElectabuzz
		0,
	//#126 - pkMagmar
		0,
	//#127 - pkPinsir
		0,
	//#128 - pkTauros
		0,
	//#129 - pkMagikarp
		1,
		evoLevel, 20, pkGyarados, 0,
	//#130 - pkGyarados
		0,
	//#131 - pkLapras
		0,
	//#132 - pkDitto
		0,
	//#133 - pkEevee
		5,
		evoItem, itemThunderStone, pkJolteon, 0,
		evoItem, itemWaterStone, pkVaporeon, 0,
		evoItem, itemFireStone, pkFlareon, 0,
		evoHappyDay, 0, pkEspeon, 0,
		evoHappyNight, 0, pkUmbreon, 0,
	//#134 - pkVaporeon
		0,
	//#135 - pkJolteon
		0,
	//#136 - pkFlareon
		0,
	//#137 - pkPorygon
		1,
		evoItemTrade, itemUpgrade, pkPorygon2, 0,
	//#138 - pkOmanyte
		1, 
		evoLevel, 40, pkOmastar, 0,
	//#139 - pkOmastar
		0,
	//#140 - pkKabuto
		1,
		evoLevel, 40, pkKabutops, 0,
	//#141 - pkKabutops
		0,
	//#142 - pkAerodactyl
		0,
	//#143 - pkSnorlax
		0,
	//#144 - pkArticuno
		0,
	//#145 - pkZapdos
		0,
	//#146 - pkMoltres
		0,
	//#147 - pkDratini
		1,
		evoLevel, 30, pkDragonair, 0,
	//#148 - pkDragonair
		1,
		evoLevel, 55, pkDragonite, 0,
	//#149 - pkDragonite
		0,
	//#150 - pkMewtwo
		0,
	//#151 - pkMew
		0,

// Johto

	//#152 - pkChikorita
		1,
		evoLevel, 16, pkBayleef, 0,
	//#153 - pkBayleef
		1,
		evoLevel, 32, pkMeganium, 0,
	//#154 - pkMeganium
		0,
	//#155 - pkCyndaquil
		1,
		evoLevel, 14, pkQuilava, 0,
	//#156 - pkQuilava
		1,
		evoLevel, 36, pkTyphlosion, 0,
	//#157 - pkTyphlosion
		0,
	//#158 - pkTotodile
		1,
		evoLevel, 18, pkCroconaw, 0,
	//#159 - pkCroconaw
		1,
		evoLevel, 30, pkFeraligatr, 0,
	//#160 - pkFeraligatr
		0,
	//#161 - pkSentret
		1,
		evoLevel, 15, pkFurret, 0,
	//#162 - pkFurret
		0,
	//#163 - pkHoothoot
		1,
		evoLevel, 20, pkNoctowl, 0,
	//#164 - pkNoctowl
		0,
	//#165 - pkLedyba
		1,
		evoLevel, 18, pkLedian, 0,
	//#166 - pkLedian
		0,
	//#167 - pkSpinarak
		1,
		evoLevel, 22, pkAriados, 0,
	//#168 - pkAriados
		0,
	//#169 - pkCrobat
		0,
	//#170 - pkChinchou
		1,
		evoLevel, 27, pkLanturn, 0,
	//#171 - pkLanturn
		0,
	//#172 - pkPichu
		1,
		evoHappy, 0, pkPikachu, 0,
	//#173 - pkCleffa
		1,
		evoHappy, 0, pkClefairy, 0,
	//#174 - pkIgglybuff
		1,
		evoHappy, 0, pkJigglypuff, 0,
	//#175 - pkTogepi
		1,
		evoHappy, 0, pkTogetic, 0,
	//#176 - pkTogetic
		0,
	//#177 - pkNatu
		1,
		evoLevel, 25, pkXatu, 0,
	//#178 - pkXatu
		0,
	//#179 - pkMareep
		1,
		evoLevel, 15, pkFlaaffy, 0,
	//#180 - pkFlaaffy
		1,
		evoLevel, 30, pkAmpharos, 0,
	//#181 - pkAmpharos
		0,
	//#182 - pkBellossom
		0,
	//#183 - pkMarill
		1,
		evoLevel, 18, pkAzumarill, 0,
	//#184 - pkAzumarill
		0,
	//#185 - pkSudowoodo
		0,
	//#186 - pkPolitoed
		0,
	//#187 - pkHoppip
		1,
		evoLevel, 18, pkSkiploom, 0,
	//#188 - pkSkiploom
		1,
		evoLevel, 27, pkJumpluff, 0,
	//#189 - pkJumpluff
		0,
	//#190 - pkAipom
		0,
	//#191 - pkSunkern
		1,
		evoItem, itemSunStone, pkSunflora, 0,
	//#192 - pkSunflora
		0,
	//#193 - pkYanma
		0,
	//#194 - pkWooper
		1,
		evoLevel, 20, pkQuagsire, 0,
	//#195 - pkQuagsire
		0,
	//#196 - pkEspeon
		0,
	//#197 - pkUmbreon
		0,
	//#198 - pkMurkrow
		0,
	//#199 - pkSlowking
		0,
	//#200 - pkMisdreavus
		0,
	//#201 - pkUnown
		0,
	//#202 - pkWobbuffet
		0,
	//#203 - pkGirafarig
		0,
	//#204 - pkPineco
		1,
		evoLevel, 31, pkForretress, 0,
	//#205 - pkForretress
		0,
	//#206 - pkDunsparce
		0,
	//#207 - pkGligar
		0,
	//#208 - pkSteelix
		0,
	//#209 - pkSnubbull
		1,
		evoLevel, 23, pkGranbull, 0,
	//#210 - pkGranbull
		0,
	//#211 - pkQwilfish
		0,
	//#212 - pkScizor
		0,
	//#213 - pkShuckle
		0,
	//#214 - pkHeracross
		0,
	//#215 - pkSneasel
		0,
	//#216 - pkTeddiursa
		1,
		evoLevel, 30, pkUrsaring, 0,
	//#217 - pkUrsaring
		0,
	//#218 - pkSlugma
		1,
		evoLevel, 38, pkMagcargo, 0,
	//#219 - pkMagcargo
		0,
	//#220 - pkSwinub
		1,
		evoLevel, 33, pkPiloswine, 0,
	//#221 - pkPiloswine
		0,
	//#222 - pkCorsola
		0,
	//#223 - pkRemoraid
		1,
		evoLevel, 25, pkOctillery, 0,
	//#224 - pkOctillery
		0,
	//#225 - pkDelibird
		0,
	//#226 - pkMantine
		0,
	//#227 - pkSkarmory
		0,
	//#228 - pkHoundour
		1,
		evoLevel, 24, pkHoundoom, 0,
	//#229 - pkHoundoom
		0,
	//#230 - pkKingdra
		0,
	//#231 - pkPhanpy
		1,
		evoLevel, 25, pkDonphan, 0,
	//#232 - pkDonphan
		0,
	//#233 - pkPorygon2
		0,
	//#234 - pkStantler
		0,
	//#235 - pkSmeargle
		0,
	//#236 - pkTyrogue
		3,
		evoAttLtDef, 20, pkHitmonchan, 0,
		evoAttGtDef, 20, pkHitmonlee, 0,
		evoAttEqDef, 20, pkHitmontop, 0,
	//#237 - pkHitmontop
		0,
	//#238 - pkSmoochum
		1,
		evoLevel, 30, pkJynx, 0,
	//#239 - pkElekid
		1,
		evoLevel, 30, pkElectabuzz, 0,
	//#240 - pkMagby
		1,
		evoLevel, 30, pkMagmar, 0,
	//#241 - pkMiltank
		0,
	//#242 - pkBlissey
		0,
	//#243 - pkRaikou
		0,
	//#244 - pkEntei
		0,
	//#245 - pkSuicune
		0,
	//#246 - pkLarvitar
		1,
		evoLevel, 30, pkPupitar, 0,
	//#247 - pkPupitar
		1,
		evoLevel, 55, pkTyranitar, 0,
	//#248 - pkTyranitar
		0,
	//#249 - pkLugia
		0,
	//#250 - pkHooh
		0,
	//#251 - pkCelebi
		0,

// Hoenn

	//#252 - pkTreecko
		1,
		evoLevel, 16, pkGrovyle, 0,
	//#253 - pkGrovyle
		1,
		evoLevel, 36, pkSceptile, 0,
	//#254 - pkSceptile
		0,
	//#255 - pkTorchic
		1,
		evoLevel, 16, pkCombusken, 0,
	//#256 - pkCombusken
		1,
		evoLevel, 36, pkBlaziken, 0,
	//#257 - pkBlaziken
		0,
	//#258 - pkMudkip
		1,
		evoLevel, 16, pkMarshtomp, 0,
	//#259 - pkMarshtomp
		1,
		evoLevel, 36, pkSwampert, 0,
	//#260 - pkSwampert
		0,
	//#261 - pkPoochyena
		1,
		evoLevel, 18, pkMightyena, 0,
	//#262 - pkMightyena
		0,
	//#263 - pkZigzagoon
		1,
		evoLevel, 20, pkLinoone, 0,
	//#264 - pkLinoone
		0,
	//#265 - pkWurmple
		2,
		evoHighPers, 7, pkSilcoon, 0,
		evoLowPers, 7, pkCascoon, 0,
	//#266 - pkSilcoon
		1,
		evoLevel, 10, pkBeautifly, 0,
	//#267 - pkBeautifly
		0,
	//#268 - pkCascoon
		1,
		evoLevel, 10, pkDustox, 0,
	//#269 - pkDustox
		0,
	//#270 - pkLotad
		1,
		evoLevel, 14, pkLombre, 0,
	//#271 - pkLombre
		1,
		evoItem, itemWaterStone, pkLudicolo, 0,
	//#272 - pkLudicolo
		0,
	//#273 - pkSeedot
		1,
		evoLevel, 14, pkNuzleaf, 0,
	//#274 - pkNuzleaf
		1,
		evoItem, itemLeafStone, pkShiftry, 0,
	//#275 - pkShiftry
		0,
	//#276 - pkTaillow
		1,
		evoLevel, 22, pkSwellow, 0,
	//#277 - pkSwellow
		0,
	//#278 - pkWingull
		1,
		evoLevel, 25, pkPelipper, 0,
	//#279 - pkPelipper
		0,
	//#280 - pkRalts
		1,
		evoLevel, 20, pkKirlia, 0,
	//#281 - pkKirlia
		1,
		evoLevel, 30, pkGardevoir, 0,
	//#282 - pkGardevoir
		0,
	//#283 - pkSurskit
		1,
		evoLevel, 22, pkMasquerain, 0,
	//#284 - pkMasquerain
		0,
	//#285 - pkShroomish
		1,
		evoLevel, 23, pkBreloom, 0,
	//#286 - pkBreloom
		0,
	//#287 - pkSlakoth
		1,
		evoLevel, 18, pkVigoroth, 0,
	//#288 - pkVigoroth
		1,
		evoLevel, 36, pkSlaking, 0,
	//#289 - pkSlaking
		0,
	//#290 - pkNincada
		2,
		evoAllowCreate, 20, pkNinjask, 0,
		evoCreateExtra, 20, pkShedinja, 0,
	//#291 - pkNinjask
		0,
	//#292 - pkShedinja
		0,
	//#293 - pkWhismur
		1,
		evoLevel, 20, pkLoudred, 0,
	//#294 - pkLoudred
		1,
		evoLevel, 40, pkExploud, 0,
	//#295 - pkExploud
		0,
	//#296 - pkMakuhita
		1,
		evoLevel, 24, pkHariyama, 0,
	//#297 - pkHariyama
		0,
	//#298 - pkAzurill
		1,
		evoHappy, 0, pkMarill, 0,
	//#299 - pkNosepass
		0,
	//#300 - pkSkitty
		1,
		evoItem, itemMoonStone, pkDelcatty, 0,
	//#301 - pkDelcatty
		0,
	//#302 - pkSableye
		0,
	//#303 - pkMawile
		0,
	//#304 - pkAron
		1,
		evoLevel, 32, pkLairon, 0,
	//#305 - pkLairon
		1,
		evoLevel, 42, pkAggron, 0,
	//#306 - pkAggron
		0,
	//#307 - pkMeditite
		1,
		evoLevel, 37, pkMedicham, 0,
	//#308 - pkMedicham
		0,
	//#309 - pkElectrike
		1,
		evoLevel, 26, pkManectric, 0,
	//#310 - pkManectric
		0,
	//#311 - pkPlusle
		0,
	//#312 - pkMinun
		0,
	//#313 - pkVolbeat
		0,
	//#314 - pkIllumise
		0,
	//#315 - pkRoselia
		0,
	//#316 - pkGulpin
		1,
		evoLevel, 26, pkSwalot, 0,
	//#317 - pkSwalot
		0,
	//#318 - pkCarvanha
		1,
		evoLevel, 30, pkSharpedo, 0,
	//#319 - pkSharpedo
		0,
	//#320 - pkWailmer
		1,
		evoLevel, 40, pkWailord, 0,
	//#321 - pkWailord
		0,
	//#322 - pkNumel
		1,
		evoLevel, 33, pkCamerupt, 0,
	//#323 - pkCamerupt
		0,
	//#324 - pkTorkoal
		0,
	//#325 - pkSpoink
		1,
		evoLevel, 32, pkGrumpig, 0,
	//#326 - pkGrumpig
		0,
	//#327 - pkSpinda
		0,
	//#328 - pkTrapinch
		1,
		evoLevel, 35, pkVibrava, 0,
	//#329 - pkVibrava
		1,
		evoLevel, 45, pkFlygon, 0,
	//#330 - pkFlygon
		0,
	//#331 - pkCacnea
		1,
		evoLevel, 32, pkCacturne, 0,
	//#332 - pkCacturne
		0,
	//#333 - pkSwablu
		1,
		evoLevel, 35, pkAltaria, 0,
	//#334 - pkAltaria
		0,
	//#335 - pkZangoose
		0,
	//#336 - pkSeviper
		0,
	//#337 - pkLunatone
		0,
	//#338 - pkSolrock
		0,
	//#339 - pkBarboach
		1,
		evoLevel, 30, pkWhiscash, 0,
	//#340 - pkWhiscash
		0,
	//#341 - pkCorphish
		1,
		evoLevel, 30, pkCrawdaunt, 0,
	//#342 - pkCrawdaunt
		0,
	//#343 - pkBaltoy
		1,
		evoLevel, 36, pkClaydol, 0,
	//#344 - pkClaydol
		0,
	//#345 - pkLileep
		1,
		evoLevel, 40, pkCradily, 0,
	//#346 - pkCradily
		0,
	//#347 - pkAnorith
		1,
		evoLevel, 40, pkArmaldo, 0,
	//#348 - pkArmaldo
		0,
	//#349 - pkFeebas
		1,
		evoBeauty, 170, pkMilotic, 0,
	//#350 - pkMilotic
		0,
	//#351 - pkCastform
		0,
	//#352 - pkKecleon
		0,
	//#353 - pkShuppet
		1,
		evoLevel, 37, pkBanette, 0,
	//#354 - pkBanette
		0,
	//#355 - pkDuskull
		1,
		evoLevel, 37, pkDusclops, 0,
	//#356 - pkDusclops
		0,
	//#357 - pkTropius
		0,
	//#358 - pkChimecho
		0,
	//#359 - pkAbsol
		0,
	//#360 - pkWynaut
		1,
		evoLevel, 15, pkWobbuffet, 0,
	//#361 - pkSnorunt
		1,
		evoLevel, 42, pkGlalie, 0,
	//#362 - pkGlalie
		0,
	//#363 - pkSpheal
		1,
		evoLevel, 32, pkSealeo, 0,
	//#364 - pkSealeo
		1,
		evoLevel, 44, pkWalrein, 0,
	//#365 - pkWalrein
		0,
	//#366 - pkClamperl
		2,
		evoItemTrade, itemDeepseaTooth, pkHuntail, 0,
		evoItemTrade, itemDeepseaScale, pkGorebyss, 0,
	//#367 - pkHuntail
		0,
	//#368 - pkGorebyss
		0,
	//#369 - pkRelicanth
		0,
	//#370 - pkLuvdisc
		0,
	//#371 - pkBagon
		1,
		evoLevel, 30, pkShelgon, 0,
	//#372 - pkShelgon
		1,
		evoLevel, 50, pkSalamence, 0,
	//#373 - pkSalamence
		0,
	//#374 - pkBeldum
		1,
		evoLevel, 20, pkMetang, 0,
	//#375 - pkMetang
		1,
		evoLevel, 45, pkMetagross, 0,
	//#376 - pkMetagross
		0,
	//#377 - pkRegirock
		0,
	//#378 - pkRegice
		0,
	//#379 - pkRegisteel
		0,
	//#380 - pkLatias
		0,
	//#381 - pkLatios
		0,
	//#382 - pkKyogre
		0,
	//#383 - pkGroudon
		0,
	//#384 - pkRayquaza
		0,
	//#385 - pkJirachi
		0,
	//#386 - pkDeoxys
		0,
};

u16 *GetEvolutions(u16 pkmnIndex)
{
	if(pkmnIndex < pkTotal)
	{
	// Used to determine PokémonIndex
		u16 counter;
	// Used as index to every single value
		int scrollCounter = 0;
		for(counter = 0; counter <= pkmnIndex; counter++)
		{
			// if pk(scrollCounter) has Evos
			if(Evolutions[scrollCounter])
			{
				if(counter == pkmnIndex)
				{
					return &Evolutions[scrollCounter];
				}
				else
				{
					scrollCounter += ( Evolutions[scrollCounter] * 4 ) + 1;
				}
			}
			else
			{
				scrollCounter++;
			}
		}
	}
	return &Evolutions[0];
}

// Maybe will become useful, left unused for now
// for performance reasons
u16 GetNrOfEvolutions(u16 species)
{
	__asm__ __volatile__(	"push {lr}\n"
							"bl GetEvolutions\n"
							"ldrh r0, [r0]\n"
							"pop {r1}\n"
							"bx r1\n");
}