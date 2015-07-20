#include "openpoke.h"

extern const char * const strArrow;
extern const char * const strArrowBlank;

extern const char TypeNames[18][10];
extern const char * const Flavors[];
extern const char * const Statnames[];
extern const char * const BattleStatNames[];
extern const char * const natures[0x19];
extern const char * const strHelpExit;
extern const char * const strHelpCancel;
extern const char * const strGotAMonster;
extern const char * const strGotAnItem;
extern const char * const strPutAwayItem;
extern const char * const strTimeAndPlaceForEverything;
extern const char * const strSaveError;
extern const char * const strSaveRequired;
extern const char * const strWantToSave;
extern const char * const strStillWantToSave;
extern const char * const strSaving;
extern const char * const strSaved;
extern const char * const strImportError;
extern const char * const strImportOne;
extern const char * const strImportMore;
extern const char * const strImporting;
extern const char * const strImported;
extern const char * const strImportOneNot;
extern const char * const strImportMoreNot;
extern const char * const strImportWipe;
extern const char * const strHMUse;
extern const char * const strHMOfferCut;
extern const char * const strHMOfferSmash;
extern const char * const strHMCouldCut;
extern const char * const strHMCouldSmash;
extern const char * const strIntroLetter[];
extern const char * const strIntroSpeech[];
#ifdef WITH_SHIRTCOLORS
extern const char * const strShirtPrompt;
#endif
extern const char * const strIntroNewName;

extern const char * const strMainClockDry;
extern const char * const strMainSaveLost;
extern const char * const strMainMenuContinue;
extern const char * const strMainMenuNewGame;
extern const char * const strMainMenuOptions;
extern const char * const strMainMenuPlayer;
extern const char * const strMainMenuPokedex;
extern const char * const strMainMenuBadges;
extern const char * const strMainMenuTime;
extern const anInventoryPage InventoryPages[6];
extern const char * const strInventCancel;
extern const char * const strInventCloseBag;
extern const char * const strInventCantBeHeld;
extern const char * const strInventUseTM;
extern const char * const strInventUseHM;
extern const char * const strItemWasUsed;
extern const char * const strItemHasNoEffect;
extern const char * const strNoRegisteredItem;
extern const char * const strHPRestored;
extern const char * const strHPRestoredPoints;
extern const char * const strPPIncreased;
extern const char * const strLevelElevated;
extern const char * const strLevelEvolved;
extern const char * const strNoEffect;

//extern const char * const Choices_CenterPC[];

extern const char * const phonenames[];
extern const char * const StandardStrings[];

extern const char * const strStatusNature;
extern const char * const strStatusMetAt;
extern const char * const strStatusHatchedAt;
extern const char * const strStatusMetInATrade;
extern const char * const strStatusExpToNext;
extern const char * const strStatusFatedAt;
extern const char * const strStatusHatchTimes[];

extern const char * const strShopHiThere;
extern const char * const strShopNotEnoughMoney;
extern const char * const strShopCertainly;
extern const char * const strShopConfirm;
extern const char * const strShopThankYou;
extern const char * const strShopComeAgain;
extern const char * const strShopAnythingElse;
extern const char * const strShopMoney;
extern const char * const strShopBack;
extern const char * const strShopBack2;

extern const char * const strStringVarDaughter;
extern const char * const strStringVarSon;
extern const char * const strStringVarHis;
extern const char * const strStringVarHer;
extern const char * const strStringVarGirl;
extern const char * const strStringVarGuy;
extern const char * const strStringVarChick;
extern const char * const strStringVarDude;
extern const char * const strStringVarBill;
extern const char * const strStringVarSomeone;

extern const char * const strTrainerCardIDNo;
extern const char * const strTrainerCardName;
extern const char * const strTrainerCardMoney;
extern const char * const strTrainerCardPokedex;
extern const char * const strTrainerCardTime;
extern const char * const BadgeFlavors[];

extern const char * const strStartMenuItems[];

extern const char * const strPokedexNames[];
extern const char * const strPokedexSortings[];
extern const char * const strPokedexColors[];
extern const char * const strPokedexGenderRatio;
extern const char * const strPokedexAlwaysMale;
extern const char * const strPokedexAlwaysFemale;
extern const char * const strPokedexChanceOfFemale;
extern const char * const strPokedexEvolvesLevel;
extern const char * const strPokedexEvolvesHappy;

extern const char * const StartMenuHelpStrings[];
extern const char * const strSafariStatBalls;

extern const char * const PartyScreenText[];
extern const char * const PartyItemsText[];
extern const char * const strPartyCantLearnTM;
extern const char * const strPartySwitchedItems;
extern const char * const strPartyGaveItem;
extern const char * const strPartyTookItem;
extern const char * const strPartyNoItem;

extern const char * const strStatusHeaders[];
extern const char * const strStatusAble;
extern const char * const strStatusNotAble;

extern const char * const strBoxThatsYourLast;
extern const char * const strBoxYourHoldingOne;
extern const char * const strBoxContinueBoxOps;
extern const char * const strBoxFooIsSelected;
extern const char * const strBoxPartyFull;
extern const char * const strBoxIsFull;
extern const char * const strBoxWhatToDo;
extern const char * const strBoxJump;
extern const char * const strBoxPickTheme;
extern const char * const strBoxPickWallpaper;
//extern const char * const Choices_Box1[];
//extern const char * const Choices_Box2[];
//extern const char * const Choices_Box3[];
//extern const char * const Choices_Box4[];
//extern const char * const Choices_Box5[];
//extern const char * const Choices_Box6[];
//extern const char * const Choices_Box[];
//extern const char * const Choices_Wallpaper[];
//extern const char * const Choices_Wallpaper1[];
//extern const char * const Choices_Wallpaper2[];
//extern const char * const Choices_Wallpaper3[];

extern const char * const strBattleFight;
extern const char * const strBattleBag;
extern const char * const strBattlePokemon;
extern const char * const strBattleRun;
extern const char * const strBattleFooWantsToFight;
extern const char * const strBattleFooSentOutBar;
extern const char * const strBattleIChooseYou;
extern const char * const strBattleFooAppeared;
extern const char * const strBattleNoEnergyToFight;
extern const char * const strBattleAlreadyThere;
extern const char * const strBattleAlreadySelected;
extern const char * const strBattleCantSwitch;
extern const char * const strBattleSwitchPrevented;
extern const char * const strBattleLevelUp;
extern const char * const strBattleEvolved;
extern const char * const strBattleAboutToSwitch;
extern const char * const strBattleOpponentSent;
extern const char * const strBattleOpponentWithdrew;
extern const char * const strBattleThatsEnough;
extern const char * const strBattleGo;
extern const char * const strBattleOkayEnough;
extern const char * const strBattleBerryTooTasty;
extern const char * const strBattleWhatToDo;
extern const char * const strBattleDemoNoParty;
extern const char * const strBattleDemoSendOut;
extern const char * const strBattleDemoQuit;

extern const char * const BattleStrings[];

extern const char * const strDexRating;
extern const char * const DexRatings[];

extern const char * const SimpleTileMessages[];

