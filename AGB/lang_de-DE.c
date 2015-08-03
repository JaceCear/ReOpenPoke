//======================================================================
//
//	German on-screen text for OpenPoké
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
	"Kampf",
	"Flug",
	"Gift",
	"Boden",
	"Gestein",
	"Käfer",
	"Geist",
	"Stahl",
	"???",
	"Feuer",
	"Wasser",
	"Pflanze",
	"Elektro",
	"Psycho",
	"Eis",
	"Drache",
	"Unlicht"
};

const CSTRING Flavors[] = { "scharf","sauer","süß","trocken","bitter" };

const CSTRING Statnames[] = { "Angriff", "Verteidigung", "Initiative", "Spezial Angriff", "Spezial Verteidigung" };
const CSTRING BattleStatNames[] = { "Angriff", "Vert.", "Init.", "Sp.Ang", "Sp.Vert", "Genauigkeit", "Fluchtwert" };

const CSTRING natures[0x19] =
{
	"Robust",
	"Solo",
	"Mutig",
	"Hart",
	"Frech",
	"Kühn",
	"Sanft",
	"Locker",
	"Pfiffig",
	"Lasch",
	"Scheu",
	"Hastig",
	"Ernst",
	"Froh",
	"Naiv",
	"Mäßig",
	"Mild",
	"Ruhig",
	"Zaghaft",
	"Hitzig",
	"Still",
	"Zart",
	"Forsch",
	"Sacht",
	"Kauzig"
};

const CSTRING Characteristics[] =
{
	//HP
	"Liebt es zu essen.",
	"Nickt oft ein.",
	"Schläft gern.",
	"Macht oft Unordnung.",
	"Mag es zu entspannen.",
	//Attack
	"Stolz auf seine Stärke.",
	"Prügelt sich gern.",
	"Besitzt Temperament.",
	"Liebt Kämpfe.",
	"Impulsiv.",
	//Defense
	"Hat robusten Körper.",
	"Kann Treffer gut ab.",
	"Äußerst ausdauernd.",
	"Hat eine gute Ausdauer.",
	"Ist beharrlich.",
	//Speed
	"Liebt es zu rennen.",
	"Achtet auf Geräusche.",
	"Ungestüm und einfältig.",
	"Ein bisschen albern.",
	"Flüchtet schnell.",
	//Special Attack
	"Sehr neugierig.",
	"Hinterhältig.",
	"Äußerst gerissen.",
	"Ist oft in Gedanken.",
	"Sehr pedantisch.",
	//Special Defense
	"Besitzt starken Willen.",
	"Etwas eitel.",
	"Sehr aufsässig.",
	"Hasst Niederlagen.",
	"Dickköpfig.",
};

const CSTRING strHelpExit = "Zurück";
const CSTRING strHelpCancel = "Abbrechen";

const CSTRING strGotAMonster = "%s hat ein\n%s erhalten!\1";
const CSTRING strGotAnItem = "%s hat %d \n%s gefunden!\7\x8\x30\1";
const CSTRING strPutAwayItem = "%s packt die %s\nin die %s-Tasche.\7\x8\x30\1";

const CSTRING strTimeAndPlaceForEverything = "Dies ist weder der rechte Ort noch\nder rechte Zeitpunkt dafür, \x1F\1!";

const CSTRING strSaveError = "%s wurde nicht\nrichtig gespeichert.";
const CSTRING strSaveRequired = "Dieser Test benötigt\neinen Speicherstand.\r\nWähle zuerst \"%s\"\num einen zu erstellen.";
const CSTRING strWantToSave = "Möchtest du das Spiel speichern?\1";
const CSTRING strStillWantToSave = "Es gibt bereits einen Spielstand.\nSpielstand überschreiben?\1";
const CSTRING strSaving = "SPEICHERN...\nBITTE NICHT AUSSCHALTEN!\1";
const CSTRING strSaved = "Spielstand gespeichert.";

const CSTRING strImportError = "Warnung: Scheinbar warten "POKEMON"\n auf einen Import,\r\naber der Zähler ist gleich 0.";
const CSTRING strImportOne = "Es wartet ein "POKEMON" auf einen Import.\nWillst du es jetzt importieren?\1";
const CSTRING strImportMore = "Es warten %d "POKEMON" auf einen Import.\nSollen sie jetzt importiert werden?\1";
const CSTRING strImporting = "Importiere…\1";
const CSTRING strImported = "%s wurde in die Box\n“%s” importiert.";
const CSTRING strImportOneNot = "Willst du es lieber nicht importieren?\1";
const CSTRING strImportMoreNot = "Willst du sie lieber nicht importieren?\1";
const CSTRING strImportWipe = "Lösche…\1";

const CSTRING strHMUse = "%s setzt %s ein!";
const CSTRING strHMOfferCut = "Der Baum kann zerschnitten werden.\nWillst du Zerschneider\neinsetzen?\1";
const CSTRING strHMOfferSmash = "Dieser Fels sieht instabil aus.\nWillst du %s einsetzen?\1";
const CSTRING strHMCouldCut = "Dieser Baum sieht aus,\nals könnte er zerschnitten werden..";
const CSTRING strHMCouldSmash = "Ein brüchiger Felsen. Ein"POKEMON"kann\nihn vielleicht zertrümmern.";

//Introduction part 1
const CSTRING strIntroLetter[] =
{
	"Die Welt, in die du jetzt gelangst,\n"
	"wird dir ein Abenteuer bescheren,\n"
	"in dem du der Held bist.\n"
	"Rede mit den Leuten und überprüfe\n"
	"Dinge, wo immer du bist, in\n"
	"Städten, auf Straßen oder in\n"
	"Höhlen. Sammle überall\n"
	"Informationen.",
	"Neue Wege werden sich auftun,\n"
	"indem du Menschen in Not hilfst,\n"
	"Herausforderungen meisterst und\n"
	"Rätsel löst.\n"
	"Manchmal wirst du von anderen\n"
	"herausgefordert und von wilden\n"
	"Geschöpfen angegriffen. Sei\n"
	"tapfer und lass dich nicht beirren.",
	"Während deines Abenteuers\n"
	"interagierst du hoffentlich mit\n"
	"allen möglichen Personen, um\n"
	"deinen Charakter zu festigen.\n"
	"Das ist unser Hauptziel.\n"
	"Drücke den A-Knopf, um das\n"
	"Abenteuer zu beginnen!"
};

//Introduction part 2
const CSTRING strIntroSpeech[] =
{
	"Hallo und willkommen zur\n"
	"OpenPoké-Demo.\r\n"
	"Ich bin Kawa und hab das hier mit\n"
	"etwas Hilfe meiner Freunde erschaffen.\r\f"
	"Nun, falls du es noch nicht wusstest…\1",
	"...das ist ein "POKEMON". Manche halten sie\n"
	"als Haustiere, andere kämpfen mit ihnen.",
	"Nun zum wichtigen Teil!",
	"Hast du was zwischen den Beinen\noder nicht?\1",
	"Ein \x1F\xE also, okay…\n"
	"Und wie ist dein Name, \x1F\xE?\1",
	"Gib deinen Namen ein!",
	"Du heißt %s?\1",
	"Das ist dein Rivale.\n"
	"Er ist ziemlich hochnäsig.\1",
	"Name des Rivalen?",
	"Ach ja, stimmt!\n"
	"Er heißt \x1F\2!\r\f"
	"Komm ihm besser nicht\nin die Quere.",
	"\x1F\x01! Hiermit beginnt\n"
	"dein Abenteuer!\r\f"
	"Viel Spaß mit der Demo! Aber vorsicht!\n"
	"Miese Bugs sind keine Seltenheit!\7\x10\x3B\x00\7\x8\x20\1"
};
#ifdef WITH_SHIRTCOLORS
//Extra prompt
const CSTRING strShirtPrompt = "Wähle die Farbe\ndeines Shirts.\1";
#endif

//Player names
const CSTRING strIntroNewName = "Neuer Name";
const CSTRING playernames[3][12] =
{
	{
		"Daniel",
		"Jo",
		"Alex",
		"Gregor",
		"Hektor",
		"Ash",
		"Richard",
		"Silber",
		"Gold",
		"Edd",
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
		"Dania",
		"Mira",
		"Asuka",
		"Janne",
		"Kagura",
		"Erika",
		"Misty",
		"Tanja",
		"Nadja",
		"Helen",
		"Martha",
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
		"Terri",
		"Douche",
	}
};

//Main menu screen items
const CSTRING strMainClockDry =	"Die interne Batterie ist leer.\n"
							"Das Spiel kann\nfortgesetzt werden.\r\f"
							"Aber zeitbasierende Events werden\n"
							"nicht mehr aktiviert.";
const CSTRING strMainSaveLost = "Der Spielstand ist zerstört!";
const CSTRING strMainMenuContinue = "Weiter";
const CSTRING strMainMenuNewGame = "Neues Spiel";
const CSTRING strMainMenuOptions = "Optionen";
const CSTRING strMainMenuPlayer = "Spieler:";
const CSTRING strMainMenuPokedex = POKE"Dex:";
const CSTRING strMainMenuBadges = "Ordnen:";
const CSTRING strMainMenuTime = "Zeit:";
const int StartMenuWidth = 9;

//Inventory screen - watch out for the centering on the page names.
const anInventoryPage InventoryPages[6] =
{
	{   0, 40, "Items"		,  "ITEMS" },
	{  40, 28, "Basis-Items"	,  "BASIS-ITEMS" },
	{  68, 12, "Bälle"		,  "BÄLLE" },
	{  80,100, "TMs/VMs"	,  "TMs/VMs" },
	{ 180,200, "Beeren"		,  "BEEREN" }
};
const CSTRING strInventCancel = "Zurück             "; //yes, padded
const CSTRING strInventCloseBag = "Beutel schließen";
const CSTRING strInventCantBeHeld = "Es kann kein %s tragen.";
const CSTRING strInventUseTM = "TM aktiviert.\r\f%s enhält %s.\r\fEinem "POKEMON" beibringen?\1";
const CSTRING strInventUseHM = "VM aktiviert.\r\f%s enhält %s.\r\fEinem "POKEMON" beibringen?\1";
//const CSTRING strInventRestoredHP = "Restored %d HP";
const CSTRING strItemWasUsed = "%s auf das %s eingesetzt.";
const CSTRING strItemHasNoEffect = "Es wird keinen Effekt haben.";
const CSTRING strNoRegisteredItem = "Ein Basis-Item kann auf\nSELECT gelegt werden.";
const CSTRING strHPRestored = "%ss KP wurden\num %d %s gefüllt.";
const CSTRING strHPRestoredPoints = "Punkte"; //this is pluralized into strHPRestored.
const CSTRING strPPIncreased = "%ss AP erhöht.";
const CSTRING strLevelElevated = "%s erreicht Lv. %d";
const CSTRING strLevelEvolved = "Dein %s wurde zu\n einem %s.";
const CSTRING strNoEffect = "Es wird keine Wirkung haben.";

//Names of people that can call you on the phone, shown on the top of the screen with a little cellphone glyph
const CSTRING phonenames[] =
{
	"???",
	PROFOAK,
	BILLNAME,
	"Kommandant Olsen",
	"Herr Tokuoka",
	"Mama",
	"Kawa",
	"Barry",
	"Herr Tajiri",
};

//These are used by command 0x84, BufferStandard
const CSTRING StandardStrings[] =
{
	//0 - contest stats
	"Cool", "Beauty", "Cute", "Smart", "Tough",
	//5 - the same again
	"Cool", "Beauty", "Cute", "Smart", "Tough",
	//10 - pocket names
	"Items", "Basis-Items", POKE"Bälle", "TMs & VMs", "Beeren",
	//15 - badges
	"Quantenorden", "...orden", "...orden", "...orden",
	"...orden", "...orden", "...orden", "...orden",
	//23 - suddenly
	"Münzen",
	//24 - pocket names, but with the "pocket"
	"Item-Tasche", "Basis-Item Tasche", POKE"Ball-Tasche",
	"TMs/VMs", "Beerentüte",
};

//Game options list. The last value per item is the length of each setting in characters:
//SLOW...
//MEDIUM.
//FAST...
//^----^-- 7 characters, including final terminator
// The pre-last option ist the number of options
const anOption GameOptions[] =
{
	{ OPT_TEXTSPEED, OPTTYPE_SIMPLE, "Text-Tempo", "Lahm\0\0\0\0\0Mittel\0\0\0Schnell\0\0Superfix", 4, 9 },
	{ OPT_BATTLESCENE, OPTTYPE_SIMPLE, "Animation", "An\0\0Aus", 2, 4 },
	{ OPT_BATTLESTYLE, OPTTYPE_SIMPLE, "Kampfstil", "Wechsel\0Folge", 2, 8 },
	{ OPT_SOUND, OPTTYPE_SIMPLE, "Ton", "Mono\0\0Stereo", 2, 6 },
	{ OPT_BUTTONMODE, OPTTYPE_SIMPLE, "Knopfbelegung", "Hilfe\0L/R\0\0\0L=A", 3, 6 },
	{ OPT_FRAME, OPTTYPE_NUMBER, "Rahmen", "Typ  ", NUMFRAMES, 0 },
#ifdef DEBUG
	{ OPT_BEEPSTYLE, OPTTYPE_SIMPLE, "8bit Stil", "Normal\0Kurz\0\0\0Kein", 3, 7 },
	{ OPT_BATTLESKIP, OPTTYPE_SIMPLE, "Kampf-Übersprung", "An\0Aus", 2, 3 },
	{ OPT_WALKTHRU, OPTTYPE_SIMPLE, "Durch Wände gehen", "Aus\0An\0\0", 2, 4 },
#endif
	{ OPT_CANCEL, OPTTYPE_CANCEL, "Zurück", 0, 0, 0 },
};

//Status screen stuff
const CSTRING strStatusNature = "Wesen: %s";
const CSTRING strStatusMetInATrade = "Im Tausch erhalten.";
const CSTRING strStatusFatedAt = "Schicksalhafte Begegnung mit \x80\x1C %d.";
const CSTRING strStatusHatchedAt = "Geschlüft: %s auf \x80\x1C 5.";
const CSTRING strStatusMetAt = "In %s auf \x80\x1C %d gefunden\n";
const CSTRING strStatusExpToNext = "%d EP zum nächsten \x80\x1C.";
const CSTRING strStatusHatchTimes[] =
{
	// >40
	"Sieht so aus, als\n"
	"würde es noch lange\n"
	"dauern, bis es schlüpft.",
	// <= 40
	"Was wohl schlüp-\n"
	"fen wird? Es wird noch\n"
	"lange dauern.",
	// <= 10
	"Es macht Bewegungen\n"
	"Bald schlüpt es sicher!",
	// <= 5
	"Es macht Geräusche!\n"
	"Bald ist es soweit!"
};

//Shop system
const CSTRING strShopHiThere =	"Hallo!\n"
								"Wie kann ich helfen?\1";
const CSTRING strShopNotEnoughMoney = "Du hast nicht genug Geld!";
const CSTRING strShopCertainly = "%s? Klar!\n"
							"Wie viele?\1";
const CSTRING strShopSellHowMany = "%s? Wie viele\nwillst du verkaufen?\1";
const CSTRING strShopSellICanPayX = "Ich kann %d$ bezahlen.\nWäre das in Ordnung?\1";
const CSTRING strShopIcantBuyThat = "%s? Oh nein!\nDas kann ich nicht kaufen!";
const CSTRING strShopConfirm =	"Du willst %dx %s?\n"
								"Das macht %d$. Okay?\1";
const CSTRING strShopThankYou =	"Bitteschön!\n"
								"Danke.";
const CSTRING strShopComeAgain = "Komm gerne wieder vorbei!";
const CSTRING strShopAnythingElse = "Noch etwas?\1";
const CSTRING strShopMoney = "Geld";
const CSTRING strShopBack = "Zurück";
const CSTRING strShopBack2 = "Zurück                  "; //yes, padded.

//Variable strings
const CSTRING strStringVarDaughter = "Tochter";
const CSTRING strStringVarSon = "Sohn";
const CSTRING strStringVarHis = "sein";
const CSTRING strStringVarHer = "ihr";
const CSTRING strStringVarGirl = "Mädchen";
const CSTRING strStringVarGuy = "Junge";
const CSTRING strStringVarChick = "Mädel";
const CSTRING strStringVarDude = "Typ";
const CSTRING strStringVarBill = BILLNAME;
const CSTRING strStringVarSomeone = "Jemand";

//Trainer Card items
const CSTRING strTrainerCardIDNo = "IDNr.%d";
const CSTRING strTrainerCardName = "Name: %s";
const CSTRING strTrainerCardMoney = "Geld";
const CSTRING strTrainerCardPokedex = POKE"Dex";
const CSTRING strTrainerCardTime = "Zeit";
const CSTRING BadgeFlavors[] =
{
	//Demo
	"Quantenorden\nErlaut Zerschneider. Sonst nix.",
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
	"Beutel",
	"\x1F\1",
	"Sichern",
	"Option.",
	"Beenden",
	"Schluss",
	"PokéCom",
};

//PokéDex items
const CSTRING strPokedexNames[] = { "National", "Regional", "Gefiltert", };
const CSTRING strPokedexSortings[] = { "ID", "Name", };
const CSTRING strPokedexColors[] = { "---", "Rot", "Blau", "Gelb", "Grün", "Schwarz", "Braun", "Lila", "Grau", "Weiß", "Pink", };
const CSTRING strPokedexGenderRatio = "Geschlechtsquote: ";
const CSTRING strPokedexAlwaysMale = "immer männlich\n";
const CSTRING strPokedexAlwaysFemale = "immer weiblich\n";
const CSTRING strPokedexChanceOfFemale = "Zu %d % weiblich\n";
const CSTRING strPokedexEvolvesLevel = "Wird auf level %d zu %s.\n";
const CSTRING strPokedexEvolvesHappy = "Wird durch Liebe zu %s.\n";

//Descriptions of the start menu items
const CSTRING StartMenuHelpStrings[] =
{
	"Ein Gerät, das Daten zu "POKEMON"\nbei Treffen oder Fangen aufgezeichnet.",
	"Überprüfe und organisiere die "POKEMON"\ndie sich in deinem Team befinden.",
	"Enthält Taschen für Items, die du gekauft,\nerhalten oder gefunden hast.",
	"Überprüfe Geldbestand und Spieldaten.",
	"Sichere dein Spiel, inklusive deines\nFortschritts und mach eine Pause.",
	"Verändere Spieleinstellungen wie\nTexttempo, Regeln usw.",
	"Schließe dieses Menü-Fenster.",
	"Beende das Safari-Spiel und kehre\nzur Rezeption zurück.",
};
const CSTRING strSafariStatBalls = "Bälle %3d";

const CSTRING strPartyCantLearnTM = "%s und %s\nsind nicht kompatibel.\r\f%s kann nicht erlernt werden.";
const CSTRING strPartySwitchedItems = "%s wurde mit dem ge-\nhaltenen %s getauscht.";
const CSTRING strPartyGaveItem = "%s hat das Item\n%s zum Tragen bekommen.";
const CSTRING strPartyTookItem = "%s\nvon %s erhalten.";
const CSTRING strPartyNoItem = "%s hält nichts.";

const CSTRING strStatusHeaders[] = { POKEMONU"-INFO", POKEMONU"-FÄHIG.", "ATTACKEN" };
const CSTRING strStatusAble = "O.K.";
const CSTRING strStatusNotAble = "NEIN";

//Box manager strings
const CSTRING strBoxThatsYourLast = "Dein letztes "POKEMON"!";
const CSTRING strBoxYourHoldingOne = "Du hälst ein "POKEMON"!";
const CSTRING strBoxContinueBoxOps = "Box weiter bearbeiten?";
const CSTRING strBoxFooIsSelected = "Ausgewählt: %s";
const CSTRING strBoxPartyFull = "Dein Team ist voll!";
const CSTRING strBoxIsFull = "Diese Box is voll!";
const CSTRING strBoxWhatToDo = "Was möchtest du tun?";
const CSTRING strBoxJump = "Zu welcher Box wechseln?";
const CSTRING strBoxPickTheme = "Wähle eine Motivsammlung.";
const CSTRING strBoxPickWallpaper = "Wähle einen Hintergrund.";

//Battle system strings
const CSTRING strBattleFight = "Kampf";
const CSTRING strBattleBag = "Beutel";
const CSTRING strBattlePokemon = POKEMON;
const CSTRING strBattleRun = "Flucht";
const CSTRING strBattleFooWantsToFight = "%s %s möchte\nmit dir kämpfen!\1";
const CSTRING strBattleFooSentOutBar = "%s %s setzt\n%s ein!\1";
const CSTRING strBattleIChooseYou = "%s! Ich wähle dich!\1";
const CSTRING strBattleFooAppeared = "Ein wildes %s erscheint!\1";
const CSTRING strBattleNoEnergyToFight = "%s ist kampfunfähig!";
const CSTRING strBattleAlreadyThere = "%s kämpft bereits!";
const CSTRING strBattleAlreadySelected = "%s wurde bereits ausgewählt.";
const CSTRING strBattleCantSwitch = "%s kann nicht ausgewechselt\nwerden!";
const CSTRING strBattleSwitchPrevented = "%s des Gegners\nverhindert einen Wechel!";
const CSTRING strBattleLevelUp = "%s erreicht Level %d!";
const CSTRING strBattleEvolved = "Glückwunsch! Dein %s\nwurde zu einem %s!";
const CSTRING strBattleAboutToSwitch = "Dein Gegner schickt als nächstes\nein %s in den Kampf.\r\nWirst du dein"POKEMON"\nwechseln?\1";
const CSTRING strBattleOpponentSent = "Dein Gegner sendet\n%s aus!";
const CSTRING strBattleOpponentWithdrew = "Dein Gegner ruft %s\nzurück!";
const CSTRING strBattleThatsEnough = "%s, genug.\nKomm zurück.";
const CSTRING strBattleGo = "Los, %s!";
const CSTRING strBattleOkayEnough = "Okay %s, das reicht! Komm zurück!";
const CSTRING strBattleBerryTooTasty = "%s fand\ndie %s zu %s.";
const CSTRING strBattleWhatToDo = "Was soll\n%s tun?";

const CSTRING strBattleDemoNoParty = "Zu hast keine "POKEMON" um\ndich zu verteidigen!";
const CSTRING strBattleDemoSendOut = "Der Autor setzt\n%s ein!\1";
const CSTRING strBattleDemoQuit = "KAWA: Okay Kindchen, das war's.\nDie Show ist vorbei.";

const char strBattle_PP_Note[] = "AP: %d/%d";

//Big list of battle system strings, taken right out of the original game.
const CSTRING BattleStrings[] =
{
	"%s",
	"%s erhält%s\n%d E.-Punkte!",
	"%s erreicht\nLv. %s!",
	"%s hat\n%s gelernt!",
	"%s versucht\n%s zu lernen.",
	"Aber %s kann nur\nvier Attacken lernen.",	//  5
	"Eine Attacke für %s\nvergessen?",
	"%s hat\n%s vergessen.",
	"Aufgeben, %s\nzu lernen?",
	"%s hat\n%s nicht erlernt.",
	"%s hat\n%s erlernt!",						// 10
	"Die Attacke von %s\nging daneben!",
	"%s\nschützt sich selbst!",
	"%s's Werte können nicht\nweiter ansteigen!",
	"%s wich durch Einsatz von\n%s aus!",
	"Es hat keine Wirkung\nauf %s…",			// 15
	"%s\nwurde besiegt!",
	"%s\nwurde besiegt!",
	"%s gewinnt %d$!",
	"%s hat kein kampffähiges\n"POKEMON" mehr!",
	"%s gerät in Panik und\nverliert %d$.\r\n… … … …\r\n%s fällt in Ohnmacht!",	// 20
	"%s verhindert\nFlucht mit %s!",
	"$%d mal getroffen!",
	"%s\nist eingeschlafen!",
	"%ss %s\nließ %s einschlafen!",
	"%s schläft bereits!",						// 25
	"%s schläft bereits!",
	"Es hatte keine Wirkung\nauf %s",
	"%s\nwurde vergiftet!",
	"%ss %s\nvergiftete %s!",
	"%s wurde durch die\nVergiftung verletzt!",		// 30
	"%s ist bereits ver-\ngiftet!",
	"%s wurde schwer\nvergiftet!",
	"%s wurde Energie\nabgesaugt!",
	"%s brennt!",
	"%ss %s\nverbrannte %s!",					// 35
	"%s wurde durch die\nVerbrennung verletzt!",
	"%s \nerstarrt zu Eis!",
	"%ss %s\nfrierte %s ein!",
	"%s ist\neingefroren!",
	"%s wurde\naufgetaut!",					// 40
	"%s wurde\naufgetaut!",
	"%s wurde\ndurch %s aufgetaut!",
	"%s wurde paralysiert!\nEs greift eventuell nicht an!",
	"%ss %s\nparalysierte %s!\nEs greift eventuell nicht an!",
	"%s ist paralysiert!\nEs kann nicht angreifen!",	// 45
	"%s ist\nbereits paralysiert!",
	"%s wurde von\nder Paralyse befreit!",
	"%ss\nTraum wurde gefressen!",
	"%ss %s\nsteigt nicht weiter!",
	"%ss %s\nsteigt nicht weiter!",				// 50
	"Der Effekt von %s\nlässt nach!",
	"Der gegnerische Effekt\nvon %s lässt nach!",
	"%s ist\nverwirrt!",
	"%s ist\nnicht mehr verwirrt!",
	"%s wurde verwirrt!",						// 55
	"%s ist\nbereits verwirrt!",
	"%s\nhat sich verliebt!",
	"%s hat sich in\n %s verliebt!",
	"%s ist\nstarr vor Liebe!",
	"%s wurde\nweggeweht!",					// 60
	"%s wurde zu\neinem %s-"POKEMON"!",
	"%s flinched!",
	"%s regained\nhealth!",
	"%s's\nHP is full!",
	"%s's %s\nraised SP. Def!",				// 65
	"%s's %s\nraised Defense!",
	"%s's party is covered\nby a veil!",
	"%s's party is protected\nby Safeguard!",
	"%s's party is no longer\nprotected by Safeguard!",
	"%s went\nto sleep!",						// 70
	"%s slept and\nbecame healthy!",
	"%s whipped\nup a whirlwind!",
	"%s took\nin sunlight!",
	"%s lowered\nits head!",
	"%s is glowing!",							// 75
	"%s flew\nup high!",
	"%s dug a hole!",
	"%s was squeezed by\n%s's bind!",
	"%s was trapped\nin the vortex!",
	"%s was wrapped by\n%s!",				// 80
	"%s clamped\n%s!",
	"%s is hurt\nby %s!",
	"%s was freed\nfrom %s!",
	"%s kept going\nand crashed!",
	"%s became\nshrouded in mist!",
	"%s is protected\nby mist!",
	"%s is getting\npumped!",
	"%s is hit\nwith recoil!",
	"%s protected\nitself!",
	"%s is buffeted\nby the sandstorm!",			// 90
	"%s is pelted\nby hail!",
	"%s was seeded!",
	"%s evaded\nthe attack!",
	"%s's health is\nsapped by Leech Seed!",
	"%s is fast\nasleep.",
	"%s woke up!",
	"But %s's uproar\nkept it awake!",
	"%s woke up\nin the uproar!",
	"%s caused\nan uproar!",
	"%s is making\nan uproar!",					// 100
	"%s calmed down.",
	"But %s can't\nsleep in an uproar!",
	"%s stockpiled\n%s!",
	"%s can't\nstockpile any more!",
	"But %s can't\nsleep in an uproar!",
	"But the uproar kept\n%s awake!",
	"%s stayed awake\nusing its %s!",
	"%s is storing\nenergy!",
	"%s unleashed\nenergy!",
	"%s became\nconfused due to fatigue!",		// 110
	"%s picked up\n$%s!",
	"%s is\nunaffected!",
	"%s transformed\ninto %s!",
	"%s made\na substitute!",
	"%s already\nhas a substitute!",
	"The substitute took damage\nfor %s!",
	"%s's\nsubstitute faded!",
	"%s must\nrecharge!",
	"%s's rage\nis building!",
	"%s's %s\nwas disabled!",					// 120
	"%s's %s\nis disabled!",
	"%s is disabled\nno more!",
	"%s got\nan encore!",
	"%s's encore\nended!",
	"%s took aim\nat %s!",
	"%s sketched\n%s!",
	"%s is trying\nto take its foe with it!",
	"%s took\n%s with it!",
	"Reduced %s's\n%s by %d!",
	"%s stole\n%s's %s!",						// 130
	"%s can't\nescape now!",
	"%s fell into\na nightmare!",
	"%s is locked\nin a nightmare!",
	"%s cut its own HP and\nlaid a curse on %s!",
	"%s is afflicted\nby the curse!",
	"Spikes were scattered all around\nthe opponent's side!",
	"%s is hurt\nby spikes!",
	"%s identified\n%s!",
	"%s's perish count\nfell to %s!",
	"%s braced\nitself!",						// 140
	"%s endured\nthe hit!",
	"Magnitude %s!",
	"%s cut its own HP\nand maximized attack!",
	"%s copied\n%s's stat changes!",
	"%s got free of\n%s's %s!",
	"%s shed\nLeech Seed!",
	"%s blew away\nspikes!",
	"%s fled from\nbattle!",
	"%s foresaw\nan attack!",
	"%s took the\n%s attack!",					// 150
	"%s's attack!",
	"%s became the\ncenter of attention!",
	"%s began\ncharging power!",
	"Nature Power turned into\n%s!",
	"%s's status\nreturned to normal!",
	"%s has no\nmoves left!",
	"%s was subjected\nto torment!",
	"%s can't use the same\nmove in a row due to the torment!",
	"%s is tightening\nits focus!",
	"%s fell for\nthe taunt!",					// 160
	"%s can't use\n%s after the taunt!",
	"%s is ready to\nhelp %s!",
	"%s switched\nitems with its opponent!",
	"%s copied\n%s's %s!",
	"%s made a wish!",
	"%s's wish\ncame true!",
	"%s planted its roots!",
	"%s absorbed\nnutrients with its roots!",
	"%s anchored\nitself with its roots!",
	"%s made\n%s drowsy!",					// 170
	"%s knocked off\n%s's %s!",
	"%s swapped abilities\nwith its opponent!",
	"%s sealed the\nopponent's move(s)!",
	"%s can't use the\nsealed %s!",
	"%s wants the\nopponent to bear a grudge!",
	"%s's %s lost\nall its PP due to the grudge!",
	"%s shrouded\nitself in %s!",
	"%s's %s\nwas bounced back by Magic Coat!",
	"%s waits for its foe\nto make a move!",
	"%s snatched\n%s's move!",				// 180
	"%s's %s\nmade it rain!",
	"%s's %s\nraised its Speed!",
	"%s was protected\nby %s!",
	"%s's %s\nprevents %s\nfrom using %s!",
	"%s restored HP\nusing its %s!",
	"%s's %s\nmade it the %s type!",
	"%s's %s\nprevents paralysis!",
	"%s's %s\nprevents romance!",
	"%s's %s\nprevents poisoning!",
	"%s's %s\nprevents confusion!",				// 190
	"%s's %s\nraised its fire power!",
	"%s anchors\nitself with %s!",
	"%s's %s\ncuts %s's attack!",
	"%s's %s\nprevents stat loss!",
	"%s's %s\nhurt %s!",
	"%s traced\n%s's %s!",
	"sharply ",
	"rose!",
	"harshly ",
	"fell!",									// 200
	"%s's %s\n%s",
	"%s's %s\n%s",
	"%s's %s\n%s",
	"%s's %s\n%s",
	"Es ist sehr\neffektiv!",
	"Ein K.O.-Treffer!",
	"1, 2, und… … … Schwupp!",
	"Und…",
	"Es ist nicht sehr\neffektiv…",
	"Es ist sehr effektiv!",						// 210
	"Du bist entkommen!",
	"Das wilde %s\nist geflohen!",
	"Du kannst von einem\nTrainer-Kampf nicht fliehen!",
	"Du kannst nicht\nweglaufen!",
	"",
	"Nichts geschieht!",
	"Es schlug fehl!",
	"It hurt itself in its\nconfusion!",
	"The Mirror Move failed!",
	"It started to rain!",						// 220
	"A downpour started!",
	"Rain continues to fall.",
	"The downpour continues.",
	"The rain stopped.",
	"A sandstorm brewed!",
	"The sandstorm rages.",
	"The sandstorm subsided.",
	"The sunlight got bright!",
	"The sunlight is strong.",
	"The sunlight faded.",						// 230
	"It started to hail!",
	"Hail continues to fall.",
	"The hail stopped.",
	"But it failed to spit up\na thing!",
	"But it failed to swallow\na thing!",
	"The wind turned into a\nheat wave!",
	"All stat changes were\neliminated!",
	"Coins scattered everywhere!",
	"It was too weak to make\na substitute!",
	"The battlers shared\ntheir pain!",			// 240
	"A bell chimed!",
	"All affected "POKEMON" will\nfaint in three turns!",
	"There's no PP left for\nthis move!",
	"But there was no PP left\nfor the move!",
	"%s used\n%s!",
	"The old man used\n%s!",
	"The trainer blocked the ball!",
	"Don't be a thief!",
	"It dodged the thrown ball!\nThis "POKEMON" can't be caught!",
	"You missed the "POKEMON"!",				// 250
	"Oh, no!\nThe "POKEMON" broke free!",
	"Aww!\nIt appeared to be caught!",
	"Aargh!\nAlmost had it!",
	"Shoot!\nIt was so close, too!",
	"Gotcha!\n%s was caught!",
	"Gotcha!\n%s was caught!",
	"Give a nickname to the\ncaptured %s?",
	"%s was sent to\n%s PC.",
	"%s's data was\nadded to the "POKE"Dex.",
	"It is raining.",							// 260
	"A sandstorm is raging.",
	"Can't escape!",
	"%s ignored\norders while asleep!",
	"%s ignored\norders!",
	"%s began to nap!",
	"%s is\nloafing around!",
	"%s won't\nobey!",
	"%s turned away!",
	"%s pretended\nnot to notice!",
	"%s %s is\nabout to use %s.Will %s change\n"POKEMON"?",	// 270
	"%s threw a rock\nat the %s!",
	"%s threw some bait\nat the %s!",
	"%s is watching\ncarefully!",
	"%s is angry!",
	"%s is eating!",
	"",
	"",
	"Announcer: You're out of\nSafari Balls! Game over!",
	"%s's %s\ncured paralysis!",
	"%s's %s\ncured poison!",					// 280
	"%s's %s\nhealed its burn!",
	"%s's %s\ndefrosted it!",
	"%s's %s\nwoke it from its sleep!",
	"%s's %s\nsnapped it out of confusion!",
	"%s's %s\ncured its %s problem!",
	"%s's %s\nrestored health!",
	"%s's %s\nrestored %s's PP!",
	"%s's %s\nrestored its status!",
	"%s's %s\nrestored its HP a little!",
	"%s's effect allows only\n%s to be used!",		// 290
	"%s hung on\nusing its %s!",
	"",
	"%s's %s\nprevents burns!",
	"%s's %s\nblocks %s!",
	"%s's %s\nrestored its HP a little!",
	"%s's %s\nwhipped up a sandstorm!",
	"%s's %s\nprevents %s loss!",
	"%s's %s\ninfatuated %s!",
	"%s's %s\nmade %s ineffective!",
	"%s's %s\ncured its %s problem!",			// 300
	"It sucked up the\nLiquid Ooze!",
	"%s transformed!",
	"Electricity's power was\nweakened!",
	"Fire's power was\nweakened!",
	"%s hid\nunderwater!",
	"%s sprang up!",
	"HM moves can't be\nforgotten now.",
	"%s found\none %s!",
	"Player defeated\n%s %s!",
	"A soothing aroma wafted\nthrough the area!",	// 310
	"Items can't be used now.",
	"For %s,\n%s %s",
	"Using %s, the %s\nof %s %s",
	"%s used\n%s to hustle!",
	"%s's %s\nmade %s useless!",
	"%s was trapped\nby Sand Tomb!",
	"",
	" a boosted",
	"%s's %s\nintensified the sun's rays!",
	"%s makes ground\nmoves miss with %s!",	// 320
	"You throw a ball now, right?\nI… I'll do my best!",
	"%s's %s\ntook the attack!",
	"%s chose\n%s as its destiny!",
	"%s lost its\nfocus and couldn't move!",
	"Use next "POKEMON"?",
	"%s fled\nusing its %s!",
	"%s fled\nusing %s!",
	"%s was\ndragged out!",
	"%s's %s\nprevented %s's\n%s from working!",
	"%s's %s\nnormalized its status!",			// 330
	"%s %s\nused %s!",
	"The box is full!\nYou can't catch any more!",
	"%s avoided\nthe attack!",
	"%s's %s\nmade it ineffective!",
	"%s's %s\nprevents flinching!",
	"%s already\nhas a burn.",
	"%s's stats won't\ngo any lower!",
	"%s's %s\nblocks %s!",
	"%s's %s\nwore off!",
	"%s's %s\nraised Defense a little!",			// 340
	"%s's %s\nraised Sp. Def a little!",
	"The wall shattered!",
	"%s's %s\nprevents %s's\n%s from working!",
	"%s's %s\ncured its %s problem!",
	"%s can't escape!",
	"%s obtained\n%s.",
	"%s obtained\n%s.",
	"%s obtained\n%s.%s obtained\n%s.",
	"But it had no effect!",
	"%s's %s\nhad no effect on %s!",			// 350
	OAKNAME ": Hm! Excellent!If you win, you earn prize money,\nand your "POKEMON" will grow!Battle other trainers and make\nyour "POKEMON" strong!",
	OAKNAME ": Hm…\nHow disappointing…If you win, you earn prize money,\nand your "POKEMON" grow.But if you lose, %s, you end\nup paying prize money…However, since you had no warning\nthis time, I'll pay for you.But things won't be this way once\nyou step outside these doors.That's why you must strengthen your\n"POKEMON" by battling wild "POKEMON".",
	"%s is out of\nusable "POKEMON"!\r\nPlayer lost against\n%s %s!",
	"%s paid $%d as the prize\nmoney…\r\n… … … …\n%s whited out!",
	"%s was transferred to\nsomeone's PC.It was placed in \nbox “%s.”",
	"%s was transferred to\n" BILLNAME "'s PC.It was placed in \nbox “%s.”",
	"Box “%s” on\nsomeone's PC was full.%s was transferred to\nbox “%s.”",
	"Box “%s” on\n" BILLNAME "'s PC was full.%s was transferred to\nbox “%s.”",
	"The "POKE" Dude used\n%s!",
	"%s played the %s.Now, that's a catchy tune!",	// 360
	"%s played the\n%s.",
	"The "POKEMON" hearing the flute\nawoke!",
	"%s",
	"%s",
	"%s whited out!",
	"%s is too scared to move!",
	"Ghost: Get out…… Get out……",
	"Silph Scope unveiled the ghost's\nidentity!",
	"The ghost was Marowak!\n",
	"%s: %s, komm zurück!",					// 370
	"%s",
	"%s: %s, komm zurück!",
	"%s: %s and\n%s, come back!",
	"",
	"%s is seriously\ncreeped out!",
};





//Multiple choice options
const CSTRING Choices[] =
{
	"Zurück",
	"Ja",
	"Nein",
	"Enter",
	"Info",
	"Benutzen",
	"Geben",
	"Wegwerfen",
	"Select",
	"Aufheben",
	"\x1F\x10's PC",
	"\x1F\x1's PC",
	PROFOAK"'s PC",
	"Ausloggen",
	"Kaufen",
	"Verkaufen",
	"Tschau!",
	"Bewegen",
	"Bericht",
	"Mitnehmen",
	"Markierung",
	"Freilassen",
	"Absetzen",
	"Tauschen",
	"Store",
	"Springen",
	"Hintergrund",
	"Name",
	"Szene 1",
	"Szene 2",
	"Szene 3",
	"Wald",
	"Stadt",
	"Wüste",
	"Savanne",
	"Klippen",
	"Vulkan",
	"Schnee",
	"Höhle",
	"Strand",
	"Meeresboden",
	"Ziegel",
	"Item",
	"Nehmen",
	"Junge",
	"Mädel",
#ifdef DEBUG
	"Schnellstart",
	"Regulärer Start",
	"Wilder Kampf",
	"Trainerkampf",
	"Demokampf",
	"FR Import-Test",
	"Markt",
	"Echtzeituhr",
	"Mehr Optionen",
	"Bilder ansehen",
	"PokéDex",
#endif
};



const CSTRING strDexRating ="The amount of progress you've made\n"
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
	"Eine Karte!",
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


// Update required to match German language!
char pluralTemp[128];
char * plural(const char *oldstr, int howmuch)
{
	int i;
	if(howmuch < 2) return (char*)oldstr;
	sprintf(pluralTemp, "%s", oldstr);
	for(i=0; i < sizeof(pluralTemp); i++)
	{
		if(pluralTemp[i]==0) break;
	}
	i--;
	if(pluralTemp[i] == 's') //already a plural
		return pluralTemp;
	else
		strcat(pluralTemp,"s");
	return pluralTemp;
}
