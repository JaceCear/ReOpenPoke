#ifndef __MAIN
#define __MAIN

//TODO	Make the multiple choice system resemble the original even more
//typedef struct CHOICELIST
//{
//	u32 numchoices;
//	u32 bcancel;
//	u32 *choices;
//} CHOICELIST;

extern void HandlePlayerControls();
extern void StartDemo(int i);

extern void DoVBlank(void);
extern void KeyRead(void);
extern void FadeIn(void);
extern void FadeOut(void);
extern void WipeIn(void);
extern void WipeOut(void);
extern void Flash(void);

extern void memcopy(void *in_dst, const void *in_src, unsigned int length);
extern void bytecpy(void *in_dst, const void *in_src, unsigned int length);

#define ClearOamBak() DmaArrayClear(160, OamBak);
#define ResetDispCnt() REG_DISPCNT =  DCNT_MODE0 | DCNT_OBJ | DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ_1D;

extern void SetNewPlayer(char *name, int gender);

extern void DetectWarps();

extern int MultipleChoice(int left, int top, int width, int choices, int bcancel); //, CHOICELIST choices);

extern void ResetBackgrounds();
extern void LoadFrame();
extern void DrawSpeechBox();
extern void MainMenu();
extern void ClearGame();
extern void LoadGame();
extern void SaveGame();
extern void SimpleTextLoop(char *MyText);
//extern int SimpleYesNoLoop();
extern int GetChecksum(void *in_src, int length);
extern void sayf(int style, const char *fmt, ...);
extern void CheckForImports();
extern void ShowPics();

extern void RepairMap();

extern void (*CurrentProcess)(void);
extern void (*PreviousProcess)(void);

//------- STATE MACHINES -------
#define SPEECH 0
#define SYSTEM 1
typedef struct _SM_Dialoguebox
{
	int state;
	char *source;
	char *linenow;
	int style;
	int scursor;
	int tcursor;
	int linewereon;
	int blinker;
	int timer;
	int isSign;
	int totalcharacters;
	int OneUp;
} _SM_Dialoguebox;
extern _SM_Dialoguebox SM_Dialoguebox;
void DialogueBox();
#define ClearDialogueBox() DmaClear(0, 0x600FB80, 400);

typedef struct _SM_PlaceNameBox
{
	u32 state;
	u32 timer;
} _SM_PlaceNameBox;
extern _SM_PlaceNameBox SM_PlaceNameBox;
void PlaceNameBox();
//------------------------------

void BrailleBox();

int GetTimeOfDay();
void ColorAdjust(u16 *dst, u16 *src, int nclrs, u32 mr, u32 mg, u32 mb);

inline int key_tri_horz();
inline int key_tri_vert();
inline int key_tri_shoulder();
inline int key_tri_fire();
inline int key_cont_horz();
inline int key_cont_vert();
inline int key_cont_shoulder();
inline int key_cont_fire();
inline int wrap(int x, int min, int max);
inline int clamp(int x, int min, int max);
//extern u32 sqran(u32 seed);
//extern u32 qran();


char * plural(const char *oldstr, int howmuch);

//extern const CHOICELIST Choice_YesNo;

extern void srand(unsigned int seed);
extern unsigned int rand();
extern unsigned int rrand(unsigned int range);

extern void LoadTimeAdjustedColors(u16 *dst, u16 *src, int nclrs);

extern int SafariBalls;
extern int SafariSteps;


#endif

// EOF
