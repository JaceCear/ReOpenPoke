
#ifndef __SPRITEMANAGER
#define __SPRITEMANAGER

#define MAXACTORS 32

void FindAndRunScript();
void ScriptLoop();

extern void LoadPeople(const aMapHeader *level);
extern void UpdateSprites();
extern void MotorSprites();
extern void AnimateSprites();

extern void actPath(int i);
extern void actWander(int i);
extern void actLookAround(int i);
extern void actPlayer(int i);
extern void actPlayerSurf(int i);

extern void HandleCut(int i);
extern void HandleRockSmash(int i);

typedef struct aSprite
{
	const unsigned short *spriteStart;
	const u8 palIndex;
	const u8 size;
} aSprite;

extern const aSprite Sprites[];

#define SPRSIZE_NORMAL 0
#define SPRSIZE_SHORT 1
#define SPRSIZE_WIDE 2

typedef struct anActor
{
	u8 sprite;
	u8 slot;
	u8 direction;
	u8 frameindex;

	u8 oamindex;
	u8 timer;
	u8 speed;
	u8 motortimer;

	u8 flagonoroff;
	u8 lastfoot;
	u8 istrainer;
	u8 lineofsight;

	s16 mx;
	s16 my;

	u16 state;
	u16 pathcursor;

	u16 flag;
	u16 oldmapx;

	u16 oldmapy;
	u8 paloverrule;
	u8 isPlayer;

	void (*motor)(int i);
	void *script;
	u8 *path;
} anActor;

extern anActor Actors[MAXACTORS];
extern anActor newactors[MAXACTORS];

extern u16 LastKnownPlayerOamIndex;

#define ACTSTATE_IDLE			0
#define ACTSTATE_WALK			1
#define ACTSTATE_TURN			2
#define ACTSTATE_RUN			3
#define ACTSTATE_WAVE			4
#define ACTSTATE_HOP			5
#define ACTSTATE_JOYNOD		6
#define ACTSTATE_PING			7
#define ACTSTATE_HM				8
#define ACTSTATE_SURF			9
#define ACTSTATE_SURFUP		10
#define ACTSTATE_SURFTURN	11

#define ACTFACING_SOUTH 0
#define ACTFACING_WEST 1
#define ACTFACING_NORTH 2
#define ACTFACING_EAST 3

extern const u16 danny_Palette[16];
extern const u16 dani_Palette[16];

#endif	// __SPRITEMANAGER

// EOF
