
#ifndef __INTRO
#define __INTRO

extern const unsigned short blackcredsPal[16];
extern const unsigned short blackcredsTiles[1696];
extern const unsigned short blackcredsMap[2048];

extern const unsigned short titlelogoPal[16];
extern const unsigned short titlelogoTiles[2624];
extern const unsigned short titlelogoMap[320];

extern const unsigned short titleflavorPal[16];
extern const unsigned short titleflavorTiles[1024];

extern const unsigned short titletextsPal[16];
extern const unsigned short titletextsTiles[512];

extern const unsigned short titlebackPal[16];
extern const unsigned short titlebackTiles[160];
extern const unsigned short titlebackMap[640];

extern const unsigned short titlemonPal[16];
extern const unsigned short titlemonTiles[640];
extern const unsigned short titlemonMap[640];

extern const unsigned short titleparticlesPal[16];
extern const unsigned short titleparticlesTiles[64];

extern void TitleScreen(int skip);
extern void StartupIntro();

extern void OpeningLetter();

extern void Welcome();

extern void IntroMovie();

extern const unsigned short intro_bg1Pal[16];
extern const unsigned short intro_bg2Pal[16];
extern const unsigned short intro_bg1Tiles[1088];
extern const unsigned short intro_bg2Tiles[512];
extern const unsigned short intro_bg1Map[2048];
extern const unsigned short intro_bg2Map[1024];
extern const unsigned short intro_dannyPal[16];
extern const unsigned short intro_dannyTiles[7168];
extern const unsigned short intro_daniPal[16];
extern const unsigned short intro_daniTiles[7168];
extern const unsigned short intro_vanPal[16];
extern const unsigned short intro_vanTiles[2048];
extern const unsigned short intro_cearnPal[16];
extern const unsigned short intro_cearnTiles[256];
extern const unsigned short intro_darkPal[16];
extern const unsigned short intro_darkTiles[640];
extern const unsigned short intro_sukaPal[16];
extern const unsigned short intro_sukaTiles[128];
extern const unsigned short intro_kawaPal[16];
extern const unsigned short intro_kawaTiles[1536];

extern const unsigned int fontOamTiles[12288 / sizeof(unsigned int)];
extern const unsigned int fontOamPal[64 / sizeof(unsigned int)];

#endif	// __INTRO

// EOF
