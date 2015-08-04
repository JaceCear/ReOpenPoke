//======================================================================
//
//	American English on-screen text for OpenPoké
//
//	Time-stamp: missing
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================

#include "openpoke.h"

const char * const strArrow = "\x80\x00"; //">"
const char * const strArrowBlank = "\x80\x01";

const char TypeNames[18][10] =
{
	"Normal",
	"Fighting",
	"Flying",
	"Poison",
	"Ground",
	"Rock",
	"Bug",
	"Ghost",
	"Steel",
	"",
	"Fire",
	"Water",
	"Grass",
	"Electric",
	"Psychic",
	"Ice",
	"Dragon",
	"Dark"
};

const CSTRING Flavors[] = { "spicy","sour","sweet","dry","bitter" };

const CSTRING Statnames[] = { "Attack", "Defense", "Speed", "Special Attack", "Special Defense" };
const CSTRING BattleStatNames[] = { "attack", "defense", "speed", "Sp.Atk", "Sp.Def", "accuracy", "evasiveness" };

const CSTRING natures[0x19] =
{
	"Hardy",	"Lonely",	"Brave",
	"Adamant","Naughty","Bold",
	"Docile",	"Relaxed","Impish",
	"Lax",		"Timid",	"Hasty",
	"Serious","Jolly",	"Naive",
	"Modest",	"Mild",		"Quiet",
	"Bashful","Rash",		"Calm",
	"Gentle",	"Sassy",	"Careful",
	"Quirky"
};

const CSTRING Characteristics[] =
{
	//HP
	"Loves to eat.",
	"Often dozes off.",
	"Often naps.",
	"Scatters things often.",
	"Likes to relax.",
	//Attack
	"Proud of its power.",
	"Likes to trash about.",
	"A little quick tempered.",
	"Likes to fight.",
	"Hot tempered.",
	//Defense
	"Sturdy body.",
	"Capable of taking hits.",
	"Highly persistent.",
	"Good endurance.",
	"Good perseverence.",
	//Speed
	"Likes to run.",
	"Alert to sounds.",
	"Impetuous and silly.",
	"Somewhat of a clown.",
	"Quick to flee.",
	//Special Attack
	"Highly curious.",
	"Mischievous.",
	"Thoroughly cunning.",
	"Often lost in thought.",
	"Very finiky.",
	//Special Defense
	"Strong willed.",
	"Somewhat vain.",
	"Strongly defiant.",
	"Hates to lose.",
	"Somewhat stubborn.",
};

const CSTRING strHelpExit = "Exit";
const CSTRING strHelpCancel = "Cancel";

const CSTRING strGotAMonster = "%s recieved a\n%s!\1";
const CSTRING strGotAnItem = "%s got %d \n%s!\7\x8\x30\1";
const CSTRING strPutAwayItem = "%s put the %s\nin the %s pocket.\7\x8\x30\1";

const CSTRING strTimeAndPlaceForEverything = "There's a time and place for\neverything, \x1F\1.";

const CSTRING strSaveError = "%s was not\nproperly saved.";
const CSTRING strSaveRequired = "This test requires a savegame.\r\nChoose “Normal Boot” and save\nyour game first.";
const CSTRING strWantToSave = "Would you like to save the game?\1";
const CSTRING strStillWantToSave = "There is already a saved file.\nIs it okay to overwrite it?\1";
const CSTRING strSaving = "SAVING…\nDON'T TURN OFF THE POWER!\1";
const CSTRING strSaved = "Game saved.";

const CSTRING strImportError = "Warning: it says there are "POKEMON"\nwaiting for import,\r\nbut the counter is set to zero.";
const CSTRING strImportOne = "There is a "POKEMON" waiting for import.\nWould you like to import it now?\1";
const CSTRING strImportMore = "There are %d "POKEMON" waiting for import.\nWould you like to import them now?\1";
const CSTRING strImporting = "Importing…\1";
const CSTRING strImported = "%s was imported\nto box “%s”.";
const CSTRING strImportOneNot = "Would you rather not import it at all?\1";
const CSTRING strImportMoreNot = "Would you rather not import them at all?\1";
const CSTRING strImportWipe = "Clearing…\1";

const CSTRING strHMUse = "%s used %s!";
const CSTRING strHMOfferCut = "This tree looks like it can be cut down.\nWould you like to cut it?\1";
const CSTRING strHMOfferSmash = "This rock appears to be breakable.\nWould you like to use %s?\1";
const CSTRING strHMCouldCut = "This tree looks like it can be cut down.";
const CSTRING strHMCouldSmash = "It's a rugged rock, but a "POKEMON"\nmay be able to smash it.";

//Introduction part 1
const CSTRING strIntroLetter[] =
{
	"In the world which you are about to\n"
	"enter, you will embark on a grand\n"
	"adventure with you as the hero.\n"
	"\n"
	"Speak to people and check things\n"
	"wherever you go, be it towns, roads\n"
	"or caves. Gather information and\n"
	"hints from every source.",
	"New paths will open to you by helping\n"
	"people in need, overcoming challenges\n"
	"and solving mysteries.\n"
	"\n"
	"At times, you will be challenged by\n"
	"others and attacked by wild creatures.\n"
	"Be brave and keep pushing on.",
	"Through your adventure, we hope\n"
	"that you will interact with all sorts\n"
	"of people and achieve personal growth.\n"
	"That is our biggest objective.\n"
	"\n"
	"Press the A button, and let your\n"
	"adventure begin!"
};

//Introduction part 2
const CSTRING strIntroSpeech[] =
{
	"Hello there and welcome to the\n"
	"OpenPoké demo.\r\n"
	"I'm Kawa and I made this thing, with\n"
	"a little help from my friends.\r\f"
	"Now, in case you didn't already know…\1",
	"…this is a "POKEMON". They make great\n"
	"pets and are also used in battle.",
	"Now, let's get crackin'.",
	"Do you have boy parts or\ngirl parts?\1",
	"A \x1F\xE, allrighty…\n"
	"Tell me your name please.\1",
	"Enter your name",
	"So it's %s?\1",
	"This is your rival.\n"
	"He's a bit of a jerk.\1",
	"Rival's name?",
	"Yeah that's right.\n"
	"His name's \x1F\2!\r\f"
	"Watch out for him.",
	"\x1F\x01! This is where\n"
	"your adventure begins!\r\f"
	"Enjoy the demo and watch out for\n"
	"grid bugs!\7\x10\x3B\x00\7\x8\x20\1"
};
#ifdef WITH_SHIRTCOLORS
//Extra prompt
const CSTRING strShirtPrompt = "Select your shirt color.\1";
#endif

//Player names
const CSTRING strIntroNewName = "New name";
const CSTRING playernames[3][12] =
{
	{
		"Danny",
		"Joe",
		"Alex",
		"Craig",
		"Hiro",
		"Ash",
		"Richard",
		"Silver",
		"Gold",
		"Eddy",
		"Simon",
		"Ted"
/*",
		"Ash",
		"Fire",
		"Gary",
		"Geki",
		"Green",
		"Hiro",
		"Jack",
		"Janne",
		"John",
		"Kamon",
		"Karl",
		"Kay",
		"Kaz",
		"Kene",
		"Leaf",
		"Max",
		"Oscar",
		"Ralph",
		"Red",
		"Roak",
		"Taylor",
		"Toru",
		"Tosh"
*/
	},
	{
		"Dani",
		"Miranda",
		"Asuka",
		"Janet",
		"Kagura",
		"Erika",
		"Misty",
		"Tanya",
		"Nadia",
		"Helen",
		"Marsha",
		"Tina"
/*",
		"Amanda",
		"Cassie",
		"Hillary",
		"Jodi",
		"June",
		"Kiko",
		"Makey",
		"Michi",
		"Mina",
		"Momo",
		"Norie",
		"Omi",
		"Paula",
		"Rey",
		"Sai",
		"Seda",
		"Suzi"
*/
	},
	//Rival names
	{
		"Arbe",
		"Nathan",
		"Terry",
		"Douche",
	}
};

//Main menu screen items
const CSTRING strMainClockDry = "The clock battery has run dry.\n"
															 "The game can be played.\r\f"
															 "However, clock-based events will\n"
															 "no longer occur.";
const CSTRING strMainSaveLost = "Save game lost -_-";
const CSTRING strMainMenuContinue = "Continue";
const CSTRING strMainMenuNewGame = "New Game";
const CSTRING strMainMenuOptions = "Options";
const CSTRING strMainMenuPlayer = "Player:";
const CSTRING strMainMenuPokedex = POKE"Dex:";
const CSTRING strMainMenuBadges = "Badges:";
const CSTRING strMainMenuTime = "Time:";
const int StartMenuWidth = 9;

//Inventory screen - watch out for the centering on the page names.
const anInventoryPage InventoryPages[6] =
{
	{   0, 40, "items",    "     ITEMS    " },
	{  40, 28, "key items","  KEY ITEMS   " },
	{  68, 12, "balls",    "     BALLS    " },
	{  80,100, "TMs/HMs",  "    TMs/HMs   " },
	{ 180,200, "berries",  "    BERRIES   " }
};
const CSTRING strInventCancel = "Cancel             "; //yes, padded
const CSTRING strInventCloseBag = "Close bag";
const CSTRING strInventCantBeHeld = "The %s can't be held.";
const CSTRING strInventUseTM = "Booted up a TM.\r\f%s contained %s.\r\fTeach this to a "POKEMON"?\1";
const CSTRING strInventUseHM = "Booted up an HM.\r\f%s contained %s.\r\fTeach this to a "POKEMON"?\1";
//const CSTRING strInventRestoredHP = "Restored %d HP";
const CSTRING strItemWasUsed = "%s was used on %s.";
const CSTRING strItemHasNoEffect = "It won't have any effect";
const CSTRING strNoRegisteredItem = "An item in the bag can be\nRegistered to SELECT for easy use.";
const CSTRING strHPRestored = "%s's HP was restored\nby %d %s.";
const CSTRING strHPRestoredPoints = "point"; //this is pluralized into strHPRestored.
const CSTRING strPPIncreased = "%s's PP increased.";
const CSTRING strLevelElevated = "%s was elevated to\nLv. %d";
const CSTRING strLevelEvolved = "%s evolved into\n%s.";
const CSTRING strNoEffect = "It won't have any effect.";

//Names of people that can call you on the phone, shown on the top of the screen with a little cellphone glyph
const CSTRING phonenames[] =
{
	"???",
	PROFOAK,
	BILLNAME,
	"Commander Olson",
	"Mr. Tokuoka",
	"Mom",
	"Kawa",
	"Barry",
	"Mr. Tajiri",
};

//These are used by command 0x84, BufferStandard
const CSTRING StandardStrings[] =
{
	//0 - contest stats
	"Cool", "Beauty", "Cute", "Smart", "Tough",
	//5 - the same again
	"Cool", "Beauty", "Cute", "Smart", "Tough",
	//10 - pocket names
	"Items", "Key Items", POKE" Balls", "TMs & HMs", "Berries",
	//15 - badges
	"Quantumbadge", "...badge", "...badge", "...badge",
	"...badge", "...badge", "...badge", "...badge",
	//23 - suddenly
	"Coins",
	//24 - pocket names, but with the "pocket"
	"items pocket", "key items pocket", POKE" balls pocket",
	"TM case", "berry pouch",
};

//Game options list. The last value per item is the length of each setting in characters:
//SLOW...
//MEDIUM.
//FAST...
//^----^-- 7 characters, including final terminator
const anOption GameOptions[] =
{
	{ OPT_TEXTSPEED, OPTTYPE_SIMPLE, "Text Speed", "Slow\0\0\0Medium\0Fast\0\0\0ZOOM!\0\0", 4, 7 },
	{ OPT_BATTLESCENE, OPTTYPE_SIMPLE, "Battle Scene", "On\0Off", 2, 3 },
	{ OPT_BATTLESTYLE, OPTTYPE_SIMPLE, "Battle Style", "Shift\0Set\0\0\0", 2, 6 },
	{ OPT_SOUND, OPTTYPE_SIMPLE, "Sound", "Mono\0\0Stereo", 2, 6 },
	{ OPT_BUTTONMODE, OPTTYPE_SIMPLE, "Button Mode", "Help\0LR\0\0\0L=A\0\0", 3, 5 },
	{ OPT_FRAME, OPTTYPE_NUMBER, "Frame", "Type ", NUMFRAMES, 0 },
	{ OPT_BEEPSTYLE, OPTTYPE_SIMPLE, "Beep Style", "Normal\0Short\0\0None\0\0\0", 3, 7 },
#ifdef DEBUG
	{ OPT_BATTLESKIP, OPTTYPE_SIMPLE, "Battle Skip", "On\0Off", 2, 3 },
	{ OPT_WALKTHRU, OPTTYPE_SIMPLE, "Walk through Walls", "Off\0On\0\0", 2, 4 },
#endif
	{ OPT_CANCEL, OPTTYPE_CANCEL, "Cancel", 0, 0, 0 },
};

//Status screen stuff
const CSTRING strStatusNature = "%s nature.";
const CSTRING strStatusMetInATrade = "Met in a trade.";
const CSTRING strStatusFatedAt = "Met in a fateful encounter when at \x80\x1C %d.";
const CSTRING strStatusHatchedAt = "Hatched: %s at \x80\x1C 5.";
const CSTRING strStatusMetAt = "Met in %s at \x80\x1C %d.\n";
const CSTRING strStatusExpToNext = "%8ld / %8ld to next";
const CSTRING strStatusHatchTimes[] =
{
	// >40
	"It looks like this\n"
	"egg will take a\n"
	"long time to hatch.",
	// <= 40
	"What will hatch\n"
	"from this? It will\n"
	"take some time.",
	// <= 10
	"It occasionally\n"
	"moves. It should\n"
	"hatch soon.",
	// <= 5
	"It's making sounds.\n"
	"It's almost ready\n"
	"to hatch!"
};

//Shop system
const CSTRING strShopHiThere = "Hi there!\n"
						 "May I help you?\1";
const CSTRING strShopNotEnoughMoney = "You don't have enough money.";
const CSTRING strShopCertainly =	"%s? Certainly\n"
							"How many would you like?\1";
const CSTRING strShopSellHowMany = "%s?\nHow many would you like to sell?\1";
const CSTRING strShopSellICanPayX = "I can pay $%d.\nWould that be okay?\1";
const CSTRING strShopIcantBuyThat = "%s? Oh, no.\nI can't buy that.";
const CSTRING strShopConfirm = "%s, and you want %d.\n"
						 "That'll be $%d. Okay?\1";
const CSTRING strShopThankYou =	"Here you are.\n"
							"Thank you.";
const CSTRING strShopComeAgain = "Please come again.";
const CSTRING strShopAnythingElse = "Is there anything else I can do?\1";
const CSTRING strShopMoney = "Money";
const CSTRING strShopBack = "Back";
const CSTRING strShopBack2 = "Back                    "; //yes, padded.

//Variable strings
const CSTRING strStringVarDaughter = "daughter";
const CSTRING strStringVarSon = "son";
const CSTRING strStringVarHis = "his";
const CSTRING strStringVarHer = "her";
const CSTRING strStringVarGirl = "girl";
const CSTRING strStringVarGuy = "guy";
const CSTRING strStringVarChick = "chick";
const CSTRING strStringVarDude = "dude";
const CSTRING strStringVarBill = BILLNAME;
const CSTRING strStringVarSomeone = "Someone";

//Trainer Card items
const CSTRING strTrainerCardIDNo = "IDNo.%d";
const CSTRING strTrainerCardName = "Name: %s";
const CSTRING strTrainerCardMoney = "Money";
const CSTRING strTrainerCardPokedex = POKE"Dex";
const CSTRING strTrainerCardTime = "Time";
const CSTRING BadgeFlavors[] =
{
	//Demo
	"Quantum Badge\nAllows Cut. Nothing more.",
/*
	//Kanto League
	"Builder Badge\nAllows Flash, increases attack.",
	"Cascade Badge\nAllows Cut, obey up to Lv.30.",
	"Thunder Badge\nAllows Fly, increases speed.",
	"Rainbow Badge\nAllows Strength, obey up to Lv.50.",
	"Marsh Badge\nObey up to Lv.70.",
	"Soul Badge\nAllows Surf, increases defense.",
	"Volcano Badge\nIncreases special attack/defense.",
	"Earth Badge\nAll outsider "POKEMON" obey."
*/
/*
	//Johto League
	"Zephyr Badge\nAllows Flash, increases attack.",
	"Hive Badge\nAllows Cut, obey up to Lv.30.",
	"Plain Badge\nAllows Strength, increases speed.",
	"Fog Badge\nAllows Surf, obey up to Lv.50.",
	"Storm Badge\nAllows Fly, obey up to Lv.70.",
	"Mineral Badge\nIncreases Defense.",
	"Glacier Badge\nAllows Whirlpool, increases\nspecial attack/defense.",
	"Rising Badge\nAllows Waterfall, all outsider\n"POKEMON" obey.",

	//Hoenn League
	"Stone Badge\nAllows Cut, increases attack.",
	"Knuckle Badge\nAllows Flash, obey up to Lv.30.",
	"Dynamo Badge\nAllows Rock Smash, increases speed.",
	"Heat Badge\nAllows Strength, obey up to Lv.50.",
	"Balance Badge\nAllows Surf, increases Defense.",
	"Feather Badge\nAllows Fly, obey up to Lv.70.",
	"Mind Badge\nAllows Dive, increases\nspecial attack/defense.",
	"Rain Badge\nAllows Waterfall, all outsider\n"POKEMON" obey.",

	//Sinnoh League
	"Coal Badge\nAllows Rock Smash.",
	"Forest Badge\nAllows Cut, obey up to Lv.30.",
	"Cobble Badge\nAllows Fly.",
	"Fen Badge\nAllows Defog.",
	"Relic Badge\nAllows Surf, obey up to Lv.50.",
	"Mine Badge\nAllows Strength, obey up to Lv.70.",
	"Icicle Badge\nAllows Rock Climb.",
	"Beacon Badge\nAllows Waterfall, all outsider\n"POKEMON" obey.",
*/
};

//Start menu items
const CSTRING strStartMenuItems[] =
{
	POKE"Dex",
	POKEMON,
	"Bag",
	"\x1F\1",
	"Save",
	"Option",
	"Exit",
	"Retire",
	"Gear",
};

//PokéDex items
const CSTRING strPokedexNames[] = { "National", "Regional", "Filtered", };
const CSTRING strPokedexSortings[] = { "ID", "Name", };
const CSTRING strPokedexColors[] = { "---", "Red", "Blue", "Yellow", "Green", "Black", "Brown", "Purple", "Gray", "White", "Pink", };
const CSTRING strPokedexGenderRatio = "Gender ratio: ";
const CSTRING strPokedexAlwaysMale = "always male\n";
const CSTRING strPokedexAlwaysFemale = "always female\n";
const CSTRING strPokedexChanceOfFemale = "%d%% chance of female\n";
const CSTRING strPokedexEvolvesLevel = "Evolves to %s at level %d.\n";
const CSTRING strPokedexEvolvesHappy = "Evolves to %s when happy enough.\n";
const CSTRING strPokedexEvolvesFromX = "Evolution of %s\n";

//Descriptions of the start menu items
const CSTRING StartMenuHelpStrings[] =
{
	"A device that records "POKEMON" secrets\nupon meeting or catching them.",
	"Check and organize "POKEMON" that are\ntraveling with you in your party.",
	"Equipped with pockets for storing items\nyou bought, recieved, or found.",
	"Check your money and other game data.",
	"Save your game with a complete record\nof your progress to take a break.",
	"Adjust various game settings such as text\nspeed, game rules, etc.",
	"Close this menu window.",
	"Retire from the Safari Game and return to\nthe registration counter.",
};
const CSTRING strSafariStatBalls = "Balls %3d";

const CSTRING strPartyCantLearnTM = "%s and %s\nare not compatible.\r\f%s can't be learned.";
const CSTRING strPartySwitchedItems = "Switched the %s\nwith the held %s.";
const CSTRING strPartyGaveItem = "%s was given the\n%s to hold.";
const CSTRING strPartyTookItem = "Recieved the %s\nfrom %s.";
const CSTRING strPartyNoItem = "%s isn't holding\nanything.";

const CSTRING strStatusHeaders[] = { POKEMONU" INFO", POKEMONU" SKILLS", "KNOWN MOVES" };
const CSTRING strStatusAble = "ABLE";
const CSTRING strStatusNotAble = "NOT ABLE";

//Box manager strings
const CSTRING strBoxThatsYourLast = "That's your last "POKEMON"!";
const CSTRING strBoxYourHoldingOne = "You're holding a "POKEMON"!";
const CSTRING strBoxContinueBoxOps = "Continue box operations?";
const CSTRING strBoxFooIsSelected = "%s is selected.";
const CSTRING strBoxPartyFull = "Your party's full!";
const CSTRING strBoxIsFull = "That box is full!";
const CSTRING strBoxWhatToDo = "What do you want to do?";
const CSTRING strBoxJump = "Jump to which box?";
const CSTRING strBoxPickTheme = "Please pick a theme.";
const CSTRING strBoxPickWallpaper = "Pick the wallpaper.";

//Battle system strings
const CSTRING strBattleFight = "Fight";
const CSTRING strBattleBag = "Bag";
const CSTRING strBattlePokemon = POKEMON;
const CSTRING strBattleRun = "Run";
const CSTRING strBattleFooWantsToFight = "%s %s wants\nto fight!";
const CSTRING strBattleFooSentOutBar = "%s %s sent out\n%s!\1";
const CSTRING strBattleIChooseYou = "%s! I choose you!\1";
const CSTRING strBattleFooAppeared = "%s appeared!";
const CSTRING strBattleNoEnergyToFight = "%s has no energy left to battle!";
const CSTRING strBattleAlreadyThere = "%s is already in battle!";
const CSTRING strBattleAlreadySelected = "%s has already been selected.";
const CSTRING strBattleCantSwitch = "%s can't be switched out!";
const CSTRING strBattleSwitchPrevented = "Opponent's %s prevents switching!";
const CSTRING strBattleLevelUp = "%s leveled up to Lv.%d!";
const CSTRING strBattleEvolved = "Congratulations! Your %s\nevolved into %s!";
const CSTRING strBattleAboutToSwitch = "Your opponent is about\nto send in %s.\r\nWill you switch "POKEMON"?\1";
const CSTRING strBattleOpponentSent = "Your opponent sent out\n%s!";
const CSTRING strBattleOpponentWithdrew = "Your opponent withdrew %s!";
const CSTRING strBattleThatsEnough = "%s, that's enough.\nCome back.";
const CSTRING strBattleGo = "Go! %s!";
const CSTRING strBattleOkayEnough = "Okay %s, that's enough. Come back!";
const CSTRING strBattleBerryTooTasty = "For %s,\nthe %s was too %s.";
const CSTRING strBattleWhatToDo = "What should\n%s do?";

const CSTRING strBattleDemoNoParty = "You don't have any "POKEMON" to\ndefend yourself with!";
const CSTRING strBattleDemoSendOut = "The author sent out\n%s!\1";
const CSTRING strBattleDemoQuit = "KAWA: Okay kid, that's all.\nShow's over.";

const char strBattle_PP_Note[] = "PP: %d/%d";

//Big list of battle system strings, taken right out of the original game.
const CSTRING BattleStrings[] =
{
	"%s",
	"%s gained%s\n%d EXP. Points!",
	"%s grew to\nLV. %s!",
	"%s learned\n%s!",
	"%s is trying to\nlearn %s.",
	"But, %s can't learn\nmore than four moves.",
	"Delete a move to make\nroom for %s?",
	"%s forgot\n%s.",
	"Stop learning\n%s?",
	"%s did not learn\n%s.",
	"%s learned\n%s!",
	"%s's\nattack missed!",
	"%s\nprotected itself!",
	"%s's stats won't\ngo any higher!",
	"%s avoided\ndamage with %s!",
	"It doesn't affect\n%s…",
	"%s\nfainted!",
	"%s\nfainted!",
	"%s got $%d\nfor winning!",
	"%s is out of\nusable "POKEMON"!",
	"%s panicked and lost $%d…\n… … … …\r\n%s whited out!",
	"%s prevents\nescape with %s!",
	"Hit %d time(s)!",
	"%s\nfell asleep!",
	"%s's %s\nmade %s sleep!",
	"%s is\nalready asleep!",
	"%s is\nalready asleep!",
	"%s\nwasn't affected!",
	"%s\nwas poisoned!",
	"%s's %s\npoisoned %s!",
	"%s is hurt\nby poison!",
	"%s is already\npoisoned.",
	"%s is badly\npoisoned!",
	"%s had its\nenergy drained!",
	"%s was burned!",
	"%s's %s\nburned %s!",
	"%s is hurt\nby its burn!",
	"%s was\nfrozen solid!",
	"%s's %s\nfroze %s solid!",
	"%s is\nfrozen solid!",
	"%s was\ndefrosted!",
	"%s was\ndefrosted!",
	"%s was\ndefrosted by %s!",
	"%s is paralyzed!\nIt may be unable to move!",
	"%s's %s\nparalyzed %s!\nIt may be unable to move!",
	"%s is paralyzed!\nIt can't move!",
	"%s is\nalready paralyzed!",
	"%s was\nhealed of paralysis!",
	"%s's\ndream was eaten!",
	"%s's %s\nwon't go higher!",
	"%s's %s\nwon't go lower!",
	"Your team's %s\nstopped working!",
	"The foe's %s\nstopped working!",
	"%s is\nconfused!",
	"%s snapped\nout of confusion!",
	"%s became\nconfused!",
	"%s is\nalready confused!",
	"%s\nfell in love!",
	"%s is in love\nwith %s!",
	"%s is\nimmobilized by love!",
	"%s was\nblown away!",
	"%s transformed\ninto the %s type!",
	"%s flinched!",
	"%s regained\nhealth!",
	"%s's\nHP is full!",
	"%s's %s\nraised SP. Def!",
	"%s's %s\nraised Defense!",
	"%s's party is covered\nby a veil!",
	"%s's party is protected\nby Safeguard!",
	"%s's party is no longer\nprotected by Safeguard!",
	"%s went\nto sleep!",
	"%s slept and\nbecame healthy!",
	"%s whipped\nup a whirlwind!",
	"%s took\nin sunlight!",
	"%s lowered\nits head!",
	"%s is glowing!",
	"%s flew\nup high!",
	"%s dug a hole!",
	"%s was squeezed by\n%s's bind!",
	"%s was trapped\nin the vortex!",
	"%s was wrapped by\n%s!",
	"%s clamped\n%s!",
	"%s is hurt\nby %s!",
	"%s was freed\nfrom %s!",
	"%s kept going\nand crashed!",
	"%s became\nshrouded in mist!",
	"%s is protected\nby mist!",
	"%s is getting\npumped!",
	"%s is hit\nwith recoil!",
	"%s protected\nitself!",
	"%s is buffeted\nby the sandstorm!",
	"%s is pelted\nby hail!",
	"%s was seeded!",
	"%s evaded\nthe attack!",
	"%s's health is\nsapped by Leech Seed!",
	"%s is fast\nasleep.",
	"%s woke up!",
	"But %s's uproar\nkept it awake!",
	"%s woke up\nin the uproar!",
	"%s caused\nan uproar!",
	"%s is making\nan uproar!",
	"%s calmed down.",
	"But %s can't\nsleep in an uproar!",
	"%s stockpiled\n%s!",
	"%s can't\nstockpile any more!",
	"But %s can't\nsleep in an uproar!",
	"But the uproar kept\n%s awake!",
	"%s stayed awake\nusing its %s!",
	"%s is storing\nenergy!",
	"%s unleashed\nenergy!",
	"%s became\nconfused due to fatigue!",
	"%s picked up\n$%s!",
	"%s is\nunaffected!",
	"%s transformed\ninto %s!",
	"%s made\na substitute!",
	"%s already\nhas a substitute!",
	"The substitute took damage\nfor %s!",
	"%s's\nsubstitute faded!",
	"%s must\nrecharge!",
	"%s's rage\nis building!",
	"%s's %s\nwas disabled!",
	"%s's %s\nis disabled!",
	"%s is disabled\nno more!",
	"%s got\nan encore!",
	"%s's encore\nended!",
	"%s took aim\nat %s!",
	"%s sketched\n%s!",
	"%s is trying\nto take its foe with it!",
	"%s took\n%s with it!",
	"Reduced %s's\n%s by %d!",
	"%s stole\n%s's %s!",
	"%s can't\nescape now!",
	"%s fell into\na nightmare!",
	"%s is locked\nin a nightmare!",
	"%s cut its own HP and\nlaid a curse on %s!",
	"%s is afflicted\nby the curse!",
	"Spikes were scattered all around\nthe opponent's side!",
	"%s is hurt\nby spikes!",
	"%s identified\n%s!",
	"%s's perish count\nfell to %s!",
	"%s braced\nitself!",
	"%s endured\nthe hit!",
	"Magnitude %s!",
	"%s cut its own HP\nand maximized attack!",
	"%s copied\n%s's stat changes!",
	"%s got free of\n%s's %s!",
	"%s shed\nLeech Seed!",
	"%s blew away\nspikes!",
	"%s fled from\nbattle!",
	"%s foresaw\nan attack!",
	"%s took the\n%s attack!",
	"%s's attack!",
	"%s became the\ncenter of attention!",
	"%s began\ncharging power!",
	"Nature Power turned into\n%s!",
	"%s's status\nreturned to normal!",
	"%s has no\nmoves left!",
	"%s was subjected\nto torment!",
	"%s can't use the same\nmove in a row due to the torment!",
	"%s is tightening\nits focus!",
	"%s fell for\nthe taunt!",
	"%s can't use\n%s after the taunt!",
	"%s is ready to\nhelp %s!",
	"%s switched\nitems with its opponent!",
	"%s copied\n%s's %s!",
	"%s made a wish!",
	"%s's wish\ncame true!",
	"%s planted its roots!",
	"%s absorbed\nnutrients with its roots!",
	"%s anchored\nitself with its roots!",
	"%s made\n%s drowsy!",
	"%s knocked off\n%s's %s!",
	"%s swapped abilities\nwith its opponent!",
	"%s sealed the\nopponent's move(s)!",
	"%s can't use the\nsealed %s!",
	"%s wants the\nopponent to bear a grudge!",
	"%s's %s lost\nall its PP due to the grudge!",
	"%s shrouded\nitself in %s!",
	"%s's %s\nwas bounced back by Magic Coat!",
	"%s waits for its foe\nto make a move!",
	"%s snatched\n%s's move!",
	"%s's %s\nmade it rain!",
	"%s's %s\nraised its Speed!",
	"%s was protected\nby %s!",
	"%s's %s\nprevents %s\nfrom using %s!",
	"%s restored HP\nusing its %s!",
	"%s's %s\nmade it the %s type!",
	"%s's %s\nprevents paralysis!",
	"%s's %s\nprevents romance!",
	"%s's %s\nprevents poisoning!",
	"%s's %s\nprevents confusion!",
	"%s's %s\nraised its fire power!",
	"%s anchors\nitself with %s!",
	"%s's %s\ncuts %s's attack!",
	"%s's %s\nprevents stat loss!",
	"%s's %s\nhurt %s!",
	"%s traced\n%s's %s!",
	"sharply ",
	"rose!",
	"harshly ",
	"fell!",
	"%s's %s\n%s",
	"%s's %s\n%s",
	"%s's %s\n%s",
	"%s's %s\n%s",
	"A critical hit!",
	"It's a one-hit KO!",
	"1, 2, and… … … Poof!",
	"And…",
	"It's not very effective…",
	"It's super effective!",
	"Got away safely!",
	"Wild %s fled!",
	"No! There's no running\nfrom a trainer battle!",
	"Can't escape!",
	"",
	"But nothing happened!",
	"But it failed!",
	"It hurt itself in its\nconfusion!",
	"The Mirror Move failed!",
	"It started to rain!",
	"A downpour started!",
	"Rain continues to fall.",
	"The downpour continues.",
	"The rain stopped.",
	"A sandstorm brewed!",
	"The sandstorm rages.",
	"The sandstorm subsided.",
	"The sunlight got bright!",
	"The sunlight is strong.",
	"The sunlight faded.",
	"It started to hail!",
	"Hail continues to fall.",
	"The hail stopped.",
	"But it failed to spit up\na thing!",
	"But it failed to swallow\na thing!",
	"The wind turned into a\nheat wave!",
	"All stat changes were\neliminated!",
	"Coins scattered everywhere!",
	"It was too weak to make\na substitute!",
	"The battlers shared\ntheir pain!",
	"A bell chimed!",
	"All affected "POKEMON" will\nfaint in three turns!",
	"There's no PP left for\nthis move!",
	"But there was no PP left\nfor the move!",
	"%s used\n%s!",
	"The old man used\n%s!",
	"The trainer blocked the ball!",
	"Don't be a thief!",
	"It dodged the thrown ball!\nThis "POKEMON" can't be caught!",
	"You missed the "POKEMON"!",
	"Oh, no!\nThe "POKEMON" broke free!",
	"Aww!\nIt appeared to be caught!",
	"Aargh!\nAlmost had it!",
	"Shoot!\nIt was so close, too!",
	"Gotcha!\n%s was caught!",
	"Gotcha!\n%s was caught!",
	"Give a nickname to the\ncaptured %s?",
	"%s was sent to\n%s PC.",
	"%s's data was\nadded to the "POKE"Dex.",
	"It is raining.",
	"A sandstorm is raging.",
	"Can't escape!",
	"%s ignored\norders while asleep!",
	"%s ignored\norders!",
	"%s began to nap!",
	"%s is\nloafing around!",
	"%s won't\nobey!",
	"%s turned away!",
	"%s pretended\nnot to notice!",
	"%s %s is\nabout to use %s.Will %s change\n"POKEMON"?",
	"%s threw a rock\nat the %s!",
	"%s threw some bait\nat the %s!",
	"%s is watching\ncarefully!",
	"%s is angry!",
	"%s is eating!",
	"",
	"",
	"Announcer: You're out of\nSafari Balls! Game over!",
	"%s's %s\ncured paralysis!",
	"%s's %s\ncured poison!",
	"%s's %s\nhealed its burn!",
	"%s's %s\ndefrosted it!",
	"%s's %s\nwoke it from its sleep!",
	"%s's %s\nsnapped it out of confusion!",
	"%s's %s\ncured its %s problem!",
	"%s's %s\nrestored health!",
	"%s's %s\nrestored %s's PP!",
	"%s's %s\nrestored its status!",
	"%s's %s\nrestored its HP a little!",
	"%s's effect allows only\n%s to be used!",
	"%s hung on\nusing its %s!",
	"",
	"%s's %s\nprevents burns!",
	"%s's %s\nblocks %s!",
	"%s's %s\nrestored its HP a little!",
	"%s's %s\nwhipped up a sandstorm!",
	"%s's %s\nprevents %s loss!",
	"%s's %s\ninfatuated %s!",
	"%s's %s\nmade %s ineffective!",
	"%s's %s\ncured its %s problem!",
	"It sucked up the\nLiquid Ooze!",
	"%s transformed!",
	"Electricity's power was\nweakened!",
	"Fire's power was\nweakened!",
	"%s hid\nunderwater!",
	"%s sprang up!",
	"HM moves can't be\nforgotten now.",
	"%s found\none %s!",
	"Player defeated\n%s %s!",
	"A soothing aroma wafted\nthrough the area!",
	"Items can't be used now.",
	"For %s,\n%s %s",
	"Using %s, the %s\nof %s %s",
	"%s used\n%s to hustle!",
	"%s's %s\nmade %s useless!",
	"%s was trapped\nby Sand Tomb!",
	"",
	" a boosted",
	"%s's %s\nintensified the sun's rays!",
	"%s makes ground\nmoves miss with %s!",
	"You throw a ball now, right?\nI… I'll do my best!",
	"%s's %s\ntook the attack!",
	"%s chose\n%s as its destiny!",
	"%s lost its\nfocus and couldn't move!",
	"Use next "POKEMON"?",
	"%s fled\nusing its %s!",
	"%s fled\nusing %s!",
	"%s was\ndragged out!",
	"%s's %s\nprevented %s's\n%s from working!",
	"%s's %s\nnormalized its status!",
	"%s %s\nused %s!",
	"The box is full!\nYou can't catch any more!",
	"%s avoided\nthe attack!",
	"%s's %s\nmade it ineffective!",
	"%s's %s\nprevents flinching!",
	"%s already\nhas a burn.",
	"%s's stats won't\ngo any lower!",
	"%s's %s\nblocks %s!",
	"%s's %s\nwore off!",
	"%s's %s\nraised Defense a little!",
	"%s's %s\nraised Sp. Def a little!",
	"The wall shattered!",
	"%s's %s\nprevents %s's\n%s from working!",
	"%s's %s\ncured its %s problem!",
	"%s can't escape!",
	"%s obtained\n%s.",
	"%s obtained\n%s.",
	"%s obtained\n%s.%s obtained\n%s.",
	"But it had no effect!",
	"%s's %s\nhad no effect on %s!",
	OAKNAME ": Hm! Excellent!If you win, you earn prize money,\nand your "POKEMON" will grow!Battle other trainers and make\nyour "POKEMON" strong!",
	OAKNAME ": Hm…\nHow disappointing…If you win, you earn prize money,\nand your "POKEMON" grow.But if you lose, %s, you end\nup paying prize money…However, since you had no warning\nthis time, I'll pay for you.But things won't be this way once\nyou step outside these doors.That's why you must strengthen your\n"POKEMON" by battling wild "POKEMON".",
	"%s is out of\nusable "POKEMON"!\r\nPlayer lost against\n%s %s!",
	"%s paid $%d as the prize\nmoney…\r\n… … … …\n%s whited out!",
	"%s was transferred to\nsomeone's PC.It was placed in \nbox “%s.”",
	"%s was transferred to\n" BILLNAME "'s PC.It was placed in \nbox “%s.”",
	"Box “%s” on\nsomeone's PC was full.%s was transferred to\nbox “%s.”",
	"Box “%s” on\n" BILLNAME "'s PC was full.%s was transferred to\nbox “%s.”",
	"The "POKE" Dude used\n%s!",
	"%s played the %s.Now, that's a catchy tune!",
	"%s played the\n%s.",
	"The "POKEMON" hearing the flute\nawoke!",
	"%s",
	"%s",
	"%s whited out!",
	"%s is too scared to move!",
	"Ghost: Get out…… Get out……",
	"Silph Scope unveiled the ghost's\nidentity!",
	"The ghost was Marowak!\n",
	"%s: %s, come back!",
	"%s",
	"%s: %s, come back!",
	"%s: %s and\n%s, come back!",
	"",
	"%s is seriously\ncreeped out!",
};





//Multiple choice options
const CSTRING Choices[] =
{
	"Cancel",
	"Yes",
	"No",
	"Enter",
	"Info",
	"Use",
	"Give",
	"Toss",
	"Pokedex_RegisterPkmn",
	"Deselect",
	"\x1F\x10's PC",
	"\x1F\x1's PC",
	PROFOAK"'s PC",
	"Log out",
	"Buy",
	"Sell",
	"See ya!",
	"Move",
	"Summary",
	"Withdraw",
	"Mark",
	"Release",
	"Place",
	"Switch",
	"Store",
	"Jump",
	"Wallpaper",
	"Name",
	"Scene 1",
	"Scene 2",
	"Scene 3",
	"Forest",
	"City",
	"Desert",
	"Savanna",
	"Crag",
	"Volcano",
	"Snow",
	"Cave",
	"Beach",
	"Seafloor",
	"Tiles",
	"Item",
	"Take",
	"Boy",
	"Girl",
	"Quickstart",
	"Normal boot",
	"Wild Battle",
	"Trainer Battle",
	"Battle with Demo",
	"FR Import Test",
	"Shop",
	"Realtime Clock",
	"View pics",
};



const CSTRING strDexRating = "The amount of progress you've made\n"
												"on your "POKE"Dex is:\r\f"
												"%d "POKEMON" seen and\n"
												"%d "POKEMON" owned.\r\f"
												PROFOAK"'s rating:";
const CSTRING DexRatings[] =
{
	"You still have lots to do.\r\f"
	"Go into every patch of grass you\n"
	"see and look for "POKEMON"!",

	"It looks as if you're getting on\n"
	"the right track!\r\f"
	"I've given one of my aides a Flash\n"
	"HM. Make sure you go get it!",

	"Your "POKE"Dex could use a bit more\n"
	"volume still!\r\f"
	"Try to catch other species of\n"
	""POKEMON"!",

	"Good, it's apparent that you're\n"
	"trying hard!\r\f"
	"I've given one of my aides an\n"
	"ItemFinder. Be sure to collect it!",

	"Your "POKE"Dex is coming along quite\n"
	"well!\r\f"
	"I've given one of my aides an\n"
	"Amulet Coin. Be sure to get it!",

	"Ah, you've finally topped 50\n"
	"species!\r\f"
	"I've given one of my aides an Exp.\n"
	"Share. Be sure to go get it!",

	"Hoho! This is turning into quite the\n"
	"respectable "POKE"Dex!",

	"Wonderful! Let me guess… You\n"
	"like to collect things, don't you?",

	"I'm impressed!\n"
	"It must have been difficult to do!",

	"You've finally hit 100 species!\n"
	"I can't believe how good you are!",

	"You even have the evolved forms\n"
	"of "POKEMON"! Super!",

	"Excellent! Trade with friends to\n"
	"get some more!",

	"Outstanding!\n"
	"You've become a real pro at this!",

	"I have nothing left to say!\n"
	"You're the "POKEMON" Professor now!",

	"Your "POKE"Dex is entirely complete!\n"
	"Congratulations!!",
};

const CSTRING SimpleTileMessages[] =
{
	"It's crammed full of "POKEMON"\nbooks.",
	"A town map.",
	"Wow!\nTons of "POKEMON" stuff!",
	"Dishes and plates are neatly\nlined up.",
	"It smells delicious!\nSomebody's been cooking here.",
	"It's a nicely made dresser.\nIt will hold a lot of stuff.",
	"There's a pile of snacks here.",
	"All your item needs fulfilled!\n"POKEMON" Mart",
	"Heal Your "POKEMON"!\n"POKEMON" Center",
	"It should be packed with all kinds\nof delicious things to eat.",
	"It's a blueprint of some sort.\nIt's filled with diagrams and text.",
	"It's a pretty picture of a "POKEMON".\nIt looks like it's feeling good.",
	"What could this machine be?\nBetter not mess around with it!",
	"It's a telephone.\nBetter not use it.",
	"It's all complicated words and\nnumbers that make no sense…",
	"It's an advertising poster about\nall kinds of products.",
	"Oh, that smells tasty!\nIt might get the stomach growling!",
	"Inside this…\n……\nThere's nothing here!",
	"It's a cup with a "POKEMON" mark\non it.",
	"The window is very well polished.",
	"Outside the window…\nThe sky looks fantastically\nbeautiful.",
	"Lights in different colors are\nflashing on and off.",
	"All sorts of tools are lined up\nneatly.",
	"It's a machine of some sort.\nIt sure is impressive.",
	"It's the latest video game!\nIt sure looks fun!",
	"There are obvious signs of burglary\nhere…",
	"There's a "POKEMON" on TV!\nIt looks like it's having fun.",
};


char pluralTemp[128];
char * plural(const char *oldstr, int howmuch)
{
	int i;
	if(howmuch<2) return (char*)oldstr;
	sprintf(pluralTemp,"%s",oldstr);
	for(i=0; i < 128; i++) { if(pluralTemp[i]==0) break; }
	i--;
	if(pluralTemp[i] == 's') //already a plural
		return pluralTemp;
	else
		strcat(pluralTemp,"s");
	return pluralTemp;
}
