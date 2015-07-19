//======================================================================
//
//	OpenPoké sprite manager
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"

extern void (*WeatherEffect)(int);
//extern void Scream(char * error);

extern void LoadTimeAdjustedColors(u16 *dst, u16 *src, int nclrs);
extern const unsigned char Std_Television_Script[];

#define NUMPEOPLE currentMapHeader->events->numPeople
#define NUMSIGNS currentMapHeader->events->numSigns
extern u8 MyBattles[64];

extern const unsigned short hopshadowTiles[32];
extern const unsigned short grasswalkPal[16];
extern const unsigned short grasswalkTiles[320];
extern const unsigned short emoticonsPal[16];
extern const unsigned short emoticonsTiles[1152];
extern const unsigned short surfPal[16];
extern const unsigned short surfTiles[1536];

void InitializeWildBattle(int encat);

extern int PartyHasMove(int move);

extern void memcpy(void *dst, const void *src, int byteCount);

extern int CheckHatches();
extern int CheckPoison();

void id_sort_shell(int keys[], u8 ids[], int count);

anActor Actors[MAXACTORS];
anActor newactors[MAXACTORS];

unsigned short LastKnownPlayerOamIndex;

int StartingOamIndex = 0;
int WeatherStartOamIdx = 0;

const void * const MotorSettings[] = { 0, actLookAround, actWander };
unsigned char ApproachScript[32];

const unsigned short encounterSongs[] = { 17,18,19,20 };

const unsigned char FrameLUT[4][4] = { { 0,3,4}, { 2,7,8 }, { 1,5,6 }, { 2,7,8 } };
const unsigned char WalkDistLUT[8] = { 0x00, 0x02, 0x05, 0x08, 0x0B, 0x0E, 0x10, 0x10 };
const unsigned char WalkFeetLUT[8] = { 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00 };
const unsigned char hopOffsets[16] = {  0, 1, 4, 7,10,13,16,19,22,25,28,31,32,32,32,32 };
const unsigned char hopFeet[16] =    {  0, 1, 1, 1, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0 };
const unsigned char hopSpecial[16] = {  0, 4, 6,10,12,13,13,10, 9, 7, 5, 0, 1, 2, 3,255};
const unsigned char emoteFrames[24] ={  0,0,0,0,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 };
const unsigned char emoteOffsets[24]={  8,12,15,17,15,14,12,9,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

void StartSurfing(int withHop)
{
	Actors[0].sprite = 7+MyPlayer.gender;
	Actors[0].speed = RUNSPEED;
	Actors[0].motor = actPlayerSurf;
	Actors[0].state = ACTSTATE_SURF;
	SETBIT(ScriptFlags, ISSURFING);
	sndPlaySound(69,SOUND_NORESTART);
	if(withHop)
	{
		if(Actors[0].direction == 0) Actors[0].my++;
		if(Actors[0].direction == 1) Actors[0].mx++;
		if(Actors[0].direction == 2) Actors[0].my--;
		if(Actors[0].direction == 3) Actors[0].mx--;
	}
}
void StopSurfing(int withHop)
{
	CLRBIT(ScriptFlags, ISSURFING);
	Actors[0].sprite = 1+MyPlayer.gender;
	Actors[0].speed = WALKSPEED;
	Actors[0].motor = actPlayer;
	Actors[0].frameindex = 0;
	Actors[0].state = ACTSTATE_WALK;
	sndPlaySound(currentMapHeader->Music,SOUND_NORESTART);
	//if(withHop) Actors[0].state = ACTSTATE_SURFOFF;
}

int IsBlockedInDir(s32 tilex, s32 tiley, u32 direction, u32 me)
{
	int i, currentflags, newflags;

	currentflags = mhGetMetaTileFlags(currentMapHeader, tilex, tiley);

	if(direction == ACTFACING_SOUTH)	tiley++;
	if(direction == ACTFACING_WEST)		tilex++;
	if(direction == ACTFACING_NORTH)	tiley--;
	if(direction == ACTFACING_EAST)		tilex--;

	newflags = mhGetMetaTileFlags(currentMapHeader, tilex, tiley);
	//find sprites
	for(i = 0; i < MAXACTORS; i++)
	{
		if(Actors[i].sprite && i != me) //in use?
		{
			if((Actors[i].flag) && (GETBIT(ScriptFlags,Actors[i].flag) != Actors[i].flagonoroff)) continue;

			signed int atx = Actors[i].mx, aty = Actors[i].my;
			if(Actors[i].state == ACTSTATE_WALK) //Fix by Tepples
			{
				if(Actors[i].direction == ACTFACING_SOUTH)	aty++;
				if(Actors[i].direction == ACTFACING_WEST)		atx++;
				if(Actors[i].direction == ACTFACING_NORTH)	aty--;
				if(Actors[i].direction == ACTFACING_EAST)		atx--;
			}

			if((atx == tilex) && (aty == tiley)) return 1;
		}
	}

	if(GETBIT(ScriptFlags, ISSURFING))
	{
		if(newflags == MAP16_NORMAL)
		{
			return 2;
		} else if(newflags & MAP16_WATER)
			return 0;
		else
			return 1;
	}

	if((newflags == MAP16_TOPSOLID) && (currentflags == MAP16_NORMAL))
	{ //Trying to go from floor to higher plane
		if(direction == ACTFACING_SOUTH)
			return 1;
	} else if((newflags == MAP16_NORMAL) && (currentflags == MAP16_TOPSOLID))
	{ //Trying to go from higher floor to normal plane
		if(direction == ACTFACING_NORTH)
			return 1;
	}

	if(newflags == MAP16_LEDGEDOWN) return (direction == ACTFACING_SOUTH) ? 1024 : 1;
	if(newflags == MAP16_LEDGERIGHT) return (direction == ACTFACING_WEST) ? 1024 : 1;
	if(newflags == MAP16_LEDGELEFT) return (direction == ACTFACING_EAST) ? 1024 : 1;

	if(newflags & MAP16_SOLID)
		return 1;
	if(newflags & MAP16_WATER)
		return 1;

	return 0;
}

void FindAndRunScript()
{
	int i;
	signed int tilex, tiley;
	const unsigned short Facings800C[] = { 1,4,2,3 }; //maps actfacings to scriptvar_800C

	tilex = Actors[0].mx;
	tiley = Actors[0].my;
	if(Actors[0].direction == ACTFACING_SOUTH)
		tiley++;
	if(Actors[0].direction == ACTFACING_WEST)
		tilex++;
	if(Actors[0].direction == ACTFACING_NORTH)
		tiley--;
	if(Actors[0].direction == ACTFACING_EAST)
		tilex--;

	if(NUMPEOPLE)
	{
		for(i = 1; i <= NUMPEOPLE; i++)
		{
			if((Actors[i].mx == tilex) && (Actors[i].my == tiley))
			{
				if((Actors[i].flag) && (GETBIT(ScriptFlags,Actors[i].flag) != Actors[i].flagonoroff)) continue;
				if(Actors[i].sprite == 0) continue;

				if(Actors[i].sprite == sprTree)
				{
					HandleCut(i);
					return;
				}
				if(Actors[i].sprite == sprRock)
				{
					HandleRockSmash(i);
					return;
				}
				if(Actors[i].script > 0)
				{
					ScriptVar_800F = i;
					ScriptVar_800C = Facings800C[Actors[0].direction];
					ScriptLoop(Actors[i].script);
					return;
				}
			}
		}
	}

	if(currentMapHeader->events->signs)
	{
		//if(NUMSIGNS > 128) Scream("TOO MANY SIGNS\n");

		for(i = 1; i <= NUMSIGNS; i++)
		{
			if( (currentMapHeader->events->signs[i-1].xpos == tilex) &&
					(currentMapHeader->events->signs[i-1].ypos == tiley) &&
					(currentMapHeader->events->signs[i-1].script > 0) )
			{
				ScriptVar_800F = -1;
				ScriptLoop(currentMapHeader->events->signs[i-1].script);
				return;
			}
		}
	}

	if(!GETBIT(ScriptFlags, ISSURFING) && PartyHasMove(moveSurf) > -1 && mhGetMetaTileFlags(currentMapHeader, tilex, tiley) & MAP16_WATER)
	{
		sayf(SYSTEM,"Do you want to surf here?\1");
		if(!SimpleYesNoLoop())
		{
			AGBPrintf("HM animation for %s here.\n", GetNickname(&MyParty[PartyHasMove(moveSurf)]));
			ClearDialogueBox();
			StartSurfing(1);
		} else
		{
			ClearDialogueBox();
			return;
		}
	}

	int thisFlags = mhGetMetaTileFlags(currentMapHeader, tilex, tiley) & ~MAP16_SOLID;

	if(thisFlags > 0x00FF && thisFlags < 0x0200) //Simple Tile Messages range
	{
		sayf(SYSTEM,SimpleTileMessages[(u16)thisFlags]);
		return;
	}
	switch(thisFlags)
	{
		case MAP16_CENTERPC:
			i = MultipleChoice(0,0,16,5,1); //CenterPCChoices);
			switch(i)
			{
			case 0:
				FadeOut();
				ShowBoxes();
				RepairMap();
				break;
			case 1:
			case 2:
				sayf(SYSTEM,"“Could not resolve hostname”?");
			case 3:
				break;
			}
			return;
		case MAP16_WORLDMAP:
			sayf(SYSTEM,SimpleTileMessages[1]);
			FadeOut();
			extern void TownMap();
			RepairMap();
			return;
		case MAP16_TV:
			ScriptVar_800F = -1;
			ScriptLoop(Std_Television_Script);
			return;
		case MAP16_CLOCK:
			FadeOut();
			ShowClock(); //in rtc
			RepairMap();
			return;
		case MAP16_QUESTIONNAIRE:
			sayf(SYSTEM, "There is a questionnaire.\nBut no pen to write with.");
			return;
	}

	if(thisFlags == MAP16_DESK)
	{
		if(Actors[0].direction == ACTFACING_SOUTH)
			tiley++;
		if(Actors[0].direction == ACTFACING_WEST)
			tilex++;
		if(Actors[0].direction == ACTFACING_NORTH)
			tiley--;
		if(Actors[0].direction == ACTFACING_EAST)
			tilex--;
		for(i = 1; i <= NUMPEOPLE; i++)
		{
			if((Actors[i].mx == tilex) && (Actors[i].my == tiley) && (Actors[i].script > 0))
			{
				if((Actors[i].flag) && (GETBIT(ScriptFlags,Actors[i].flag) != Actors[i].flagonoroff)) continue;

				ScriptVar_800F = i;
				ScriptLoop(Actors[i].script);
				return;
			}
		}
	}
}

void FindAndRunSignsOnly()
{
	int i;
	signed int tilex, tiley;

	tilex = Actors[0].mx;
	tiley = Actors[0].my-1;

	if(currentMapHeader->events->signs)
	{
		//if(NUMSIGNS > 128) Scream("TOO MANY SIGNS\n");

		for(i = 1; i <= NUMSIGNS; i++)
		{
			if((currentMapHeader->events->signs[i-1].autoactivate) &&
				(currentMapHeader->events->signs[i-1].xpos == tilex) &&
				(currentMapHeader->events->signs[i-1].ypos == tiley) &&
				(currentMapHeader->events->signs[i-1].script > 0) )
			{
				SM_Dialoguebox.isSign = 1;
				ScriptVar_800F = -1;
				ScriptLoop(currentMapHeader->events->signs[i-1].script);
				return;
			}
		}
	}
}

void CheckTraps()
{
	int i;
	signed int tilex, tiley;

	tilex = Actors[0].mx;
	tiley = Actors[0].my;
	if(currentMapHeader->events->traps)
	{
		//if(currentMapHeader->events->numTraps > 128) Scream("TOO MANY SIGNS\n");

		for(i = 1; i <= currentMapHeader->events->numTraps; i++)
		{
			if( (currentMapHeader->events->traps[i-1].xpos == tilex) &&
				(currentMapHeader->events->traps[i-1].ypos == tiley) &&
				(currentMapHeader->events->traps[i-1].script) )
			{
				if(currentMapHeader->events->traps[i-1].variable == 0)
				{
					ScriptLoop(currentMapHeader->events->traps[i-1].script);
					return;
				} else
				{
					AGBPrintf("CheckTraps: checking trap %d, variable %d. Value is %d, trigger if >= %d.\n", i-1, currentMapHeader->events->traps[i-1].variable, ScriptVars[currentMapHeader->events->traps[i-1].variable], currentMapHeader->events->traps[i-1].value);
					if(ScriptVars[currentMapHeader->events->traps[i-1].variable] >= currentMapHeader->events->traps[i-1].value)
					{
						ScriptLoop(currentMapHeader->events->traps[i-1].script);
						return;
					}
				}
			}
		}
	}
}

//extern const aMapHeader mhdrTest;

#ifdef WITH_SHIRTCOLORS
extern const unsigned short shirtcolors[32];
#endif
void LoadSpriteColors()
{
	CpuFastArrayCopy(spritecolors, MEM_PAL_OBJ+0x20);
	CpuFastArrayCopy(MyPlayer.gender % 2 == 0 ? danny_Palette : dani_Palette, MEM_PAL_OBJ);
#ifdef WITH_SHIRTCOLORS
	*(u16*)0x05000212 = shirtcolors[(MyPlayer.shirtColor*2) + ((MyPlayer.gender % 2) * 16)];
	*(u16*)0x05000214 = shirtcolors[(MyPlayer.shirtColor*2)+1+((MyPlayer.gender % 2) * 16)];
#endif
}

void LoadPeople(const aMapHeader *level)
{
	int i, s=1; // x, y;

	AGBPrint("LoadPeople: killing old actors...\n");
	for(i=1; i<MAXACTORS; i++)
	{
		Actors[i].sprite = 0; //flag as Not Used
		//OamBak[i].CharNo = 516;
	}

	if(level->events == 0)
	{
		AGBPrint("LoadPeople: nullpointer on events data. Aborting...\n");
		return;
	}

	AGBPrintf("LoadPeople: loading %d people from %x...\n",
		level->events->numPeople, level->events->people);

	for(i=0; i < level->events->numPeople; i++)
	{
		AGBPrintf("* #%d @ %dx%d\n", level->events->people[i].sprite,
			level->events->people[i].xpos, level->events->people[i].ypos);

		//EXPERIMENT: not loading a person on certain times of the day.
		//POSSIBILITY: using some kind of bit field.
		//Normally, you'd do this in a level script, I'd guess >>
		//if((level->events->people[i-1].timegroup == 1) && (GetTimeOfDay() == 2)) continue;

		Actors[s].sprite = level->events->people[i].sprite;
		Actors[s].slot = s;
		Actors[s].direction = level->events->people[i].facing;

		if(Actors[s].direction == 0xFF) Actors[s].direction = 0;

		Actors[s].frameindex = 0;

		Actors[s].oamindex = 0;
		Actors[s].timer = 0;
		Actors[s].speed = WALKSPEED;
		Actors[s].motortimer = 0;

		Actors[s].flagonoroff = level->events->people[i].flagonoroff;
		Actors[s].lastfoot = 0;
		Actors[s].istrainer = level->events->people[i].istrainer;
		Actors[s].lineofsight = level->events->people[i].lineofsight;

		Actors[s].mx = level->events->people[i].xpos;
		Actors[s].my = level->events->people[i].ypos;

		Actors[s].state = ACTSTATE_IDLE;
		Actors[s].pathcursor = 0;

		Actors[s].flag = level->events->people[i].flag;
		Actors[s].oldmapx = Actors[s].mx;

		Actors[s].oldmapy = Actors[s].my;

		Actors[s].motor = MotorSettings[level->events->people[i].motor]; //actWander;
		Actors[s].script = (int*)level->events->people[i].script;

		if(Actors[s].sprite == sprDanny)
		{
			Actors[s].sprite = MyPlayer.gender % 2 == 0 ? sprDani : sprDanny;
			Actors[s].paloverrule = 5;
			CpuFastArrayCopy(MyPlayer.gender % 2 == 0 ? dani_Palette : danny_Palette, MEM_PAL_OBJ + 0xA0);
		} else
		{
			Actors[s].paloverrule = 0;
		}
		s++;
	}

	AGBPrint("LoadPeople: finished\n");
}


void UpdateSprites()
{
	int i;
	char* thisPic;
	short* targetPic;
	int size = 0x100;
	int shit = 0;
	int walkfoot;
	signed int bigsignedvalue;
	int offscreen = 0;
	int nac = 1;

	anActor *actor;
	OamData *obj;
	int keys[MAXACTORS];
	u8 ids[MAXACTORS];

	signed int infrontx, infronty;
	int grassflag = 0, shadowflag = 0, emoteflag = 0, surfflag = 0;

	int runningOamIndex = StartingOamIndex + WeatherStartOamIdx;

	//ClearOamBak();
	for(i = runningOamIndex; i < 64; i++)
	{
		OamBak[i].HPos = 250;
		OamBak[i].CharNo = 512;
	}
	//ClearSpriteGFX();
	DmaClear(0, newactors, sizeof(anActor) * MAXACTORS);
	//DmaClear(0, MEM_VRAM_OBJ, 0x4000);

	//PASS 1 -- Culling the actors
	for(i = 0; i < NUMPEOPLE+1; i++)
	{
		actor = &Actors[i];

		//KAWA - VERY BAD hack to determine if a sprite is off screen
		offscreen = 0;
		bigsignedvalue = actor->mx - Actors[0].mx;
		if(bigsignedvalue < -8) offscreen = 1;
		if(bigsignedvalue > 8) offscreen = 1;
		bigsignedvalue = actor->my - Actors[0].my;
		if(bigsignedvalue < -8) offscreen = 1;
		if(bigsignedvalue > 8) offscreen = 1;
		//End of VBH

		if((actor->flag) && (GETBIT(ScriptFlags,actor->flag) != actor->flagonoroff))
			offscreen = 1;
		if(actor->sprite == 0)
			offscreen = 1;

		if(offscreen == 0) // >0 = in use
		{
			memcpy(&newactors[nac], actor, sizeof(anActor));
			nac++;
		}
	}

	//PASS 2 - Sort the culled actors
	for(i = 0; i < nac; i++)
	{
		ids[i] = i;
		keys[i] = 42;
//		if(Actors[i].sprite)
//		{
			keys[i] = -256 * newactors[i].my+i;
			shit++;
//		}
	}
	id_sort_shell(keys, ids, shit);

	//PASS 3 -- Process the sorted actors -- final and biggest pass.
	for(i = 0; i < nac; i++)
	{
		actor = &newactors[ids[i]];
		if(actor->sprite)
		{
			thisPic = (char*)Sprites[actor->sprite].spriteStart;
			targetPic = (short*)MEM_VRAM_OBJ + (actor->slot * 0x100);
			switch(Sprites[actor->sprite].size)
			{
				case 0: //32x16
					size = 0x100;
					DmaClear(0, targetPic, 0x40);
					break;
				case 1: //16x16
					size = 0x80;
					DmaClear(0, targetPic, 0x80);
					targetPic += 0x40;
					break;
				case 2: //32x32
					size = 0x200;
					//No need to clear. These overwrite all.
					break;
			}
			walkfoot = WalkFeetLUT[actor->frameindex] * (actor->lastfoot+1);
			thisPic += size * FrameLUT[actor->direction][walkfoot];
			if(actor->state == ACTSTATE_WAVE)
				thisPic = (char*)Sprites[actor->sprite].spriteStart + (size*9);
			if(actor->state == ACTSTATE_JOYNOD)
				thisPic = (char*)Sprites[actor->sprite].spriteStart + (size*3);
			if(actor->state == ACTSTATE_HM)
				thisPic = (char*)Sprites[actor->sprite].spriteStart + (size*actor->frameindex);
			if(actor->state == ACTSTATE_HOP)
			{
				//TODO	Add proper feet animation
				if(actor->frameindex < 11)
					thisPic = (char*)Sprites[actor->sprite].spriteStart + (size * FrameLUT[actor->direction][1]);
				else
					thisPic = (char*)Sprites[actor->sprite].spriteStart + (size * FrameLUT[actor->direction][0]);
			}
			if(actor->state == ACTSTATE_PING)
			{
				//Reset to just standing.
				thisPic = (char*)Sprites[actor->sprite].spriteStart;
				thisPic += size * FrameLUT[actor->direction][0];
			}
			if(actor->state >= ACTSTATE_SURF && actor->state <= ACTSTATE_SURFTURN)
			{
				//Reset to just sitting
				thisPic = (char*)Sprites[actor->sprite].spriteStart;
				thisPic += size * FrameLUT[actor->direction][0];
			}
			DmaCopy(thisPic,targetPic,size);

			//Now, before we set up the OAM data for this actor, see if it requires any in-front effects.

			//Figure out what "in front of us" means...
			infrontx = actor->mx;
			infronty = actor->my;
			if(actor->direction == ACTFACING_SOUTH)
				infronty++;
			if(actor->direction == ACTFACING_WEST)
				infrontx++;
			if(actor->direction == ACTFACING_NORTH)
				infronty--;
			if(actor->direction == ACTFACING_EAST)
				infrontx--;

			//Handle the grass...
			if(actor->state == ACTSTATE_WALK && mhGetMetaTileFlags(currentMapHeader, infrontx, infronty) & MAP16_TALLGRASS)
			{
				obj = &OamBak[runningOamIndex];
				obj->ObjMode = 0;
				obj->Priority = 2;
				obj->Shape = 0;
				obj->Size = 1;
				obj->Pltt = 10;
				obj->CharNo = 540;
				obj->HPos = (actor->mx << 4) - gCameraX;
				obj->VPos = (actor->my << 4) - gCameraY;
				switch(actor->direction)
				{
					case ACTFACING_SOUTH:
						obj->VPos+=8;
						break;
					case ACTFACING_WEST:
						obj->HPos+=16;
						obj->VPos-=8;
						break;
					case ACTFACING_NORTH:
						if(actor->frameindex < 5) obj->Priority = 3;
						obj->VPos-=24;
						break;
					case ACTFACING_EAST:
						obj->HPos-=16;
						obj->VPos-=8;
						break;
				}
				switch(actor->frameindex)
				{
					case 0:
					case 1:
					case 2:
						obj->CharNo = 524;
						obj->Priority = 3;
						break;
					case 3:
						obj->CharNo = 528;
						break;
					case 4:
						obj->CharNo = 532;
						break;
					case 5:
						obj->CharNo = 536;
						break;
				}
				grassflag = 1;
				runningOamIndex++;
			}
			if(actor->state != ACTSTATE_HOP && !(actor->state == ACTSTATE_WALK && actor->direction == ACTFACING_SOUTH) && mhGetMetaTileFlags(currentMapHeader, actor->mx, actor->my) & MAP16_TALLGRASS)
			{
				obj = &OamBak[runningOamIndex];
				obj->ObjMode = 0;
				obj->Priority = 2;
				obj->Shape = 0;
				obj->Size = 1;
				obj->Pltt = 10;
				obj->CharNo = 520;
				obj->HPos = (actor->mx << 4) - gCameraX;
				obj->VPos = (actor->my << 4) - gCameraY-8;
				grassflag = 1;
				runningOamIndex++;
			}

			//Handle the emoticons...
			if(actor->state == ACTSTATE_PING)
			{
				obj = &OamBak[runningOamIndex];
				obj->Priority = 0;
				obj->Shape = 0;
				obj->Size = 1;
				obj->Pltt = 13;
				obj->CharNo = 544 + (emoteFrames[actor->timer / 2]*4) + (actor->frameindex * 12);
				obj->HPos = (actor->mx << 4) - gCameraX;
				obj->VPos = (actor->my << 4) - gCameraY;
				obj->VPos -= 32 + emoteOffsets[actor->timer / 2];
				emoteflag = 1;
				runningOamIndex++;
			}

			//All done with the in-front effects -- do the actor.
			obj = &OamBak[runningOamIndex];
			obj->ObjMode = 0;
			obj->HPos = (actor->mx << 4) - gCameraX;
			obj->VPos = (actor->my << 4) - gCameraY - 16 - 8;
			obj->HFlip = (actor->direction == 1 ? 1 : 0);
			obj->Shape = (Sprites[actor->sprite].size == 2 ? 0 : 2);;
			obj->Size = 2;
			obj->CharNo = actor->slot << 4;
			obj->Pltt = Sprites[actor->sprite].palIndex;
			obj->Priority = 2;
			if(Sprites[actor->sprite].size == 2) obj->HPos-=8;
			if(actor->paloverrule) obj->Pltt = actor->paloverrule;
			if(actor->state == ACTSTATE_WALK || actor->state == ACTSTATE_SURFUP) //walking a tile
			{
				if(actor->direction == 0)	obj->VPos += WalkDistLUT[actor->frameindex]; //south
				if(actor->direction == 1)	obj->HPos += WalkDistLUT[actor->frameindex]; //east
				if(actor->direction == 2)	obj->VPos -= WalkDistLUT[actor->frameindex]; //north
				if(actor->direction == 3)	obj->HPos -= WalkDistLUT[actor->frameindex]; //west
			}
			if(actor->state == ACTSTATE_HOP) //hopping, like over a ledge
			{
				if(actor->direction == 0)
				{
					obj->VPos += hopOffsets[actor->frameindex];
					if(actor->frameindex < 12)
						obj->VPos -= hopSpecial[actor->frameindex];
				}
				if(actor->direction == 1)
				{
					obj->HPos += hopOffsets[actor->frameindex];
					if(actor->frameindex < 12)
						obj->VPos -= hopSpecial[actor->frameindex];
				}
				if(actor->direction == 2)
				{
					obj->VPos += hopOffsets[actor->frameindex];
					if(actor->frameindex < 12)
						obj->VPos -= hopSpecial[actor->frameindex];
				}
				if(actor->direction == 3)
				{
					obj->HPos -= hopOffsets[actor->frameindex];
					if(actor->frameindex < 12)
						obj->VPos -= hopSpecial[actor->frameindex];
				}
			}
			if(actor->isPlayer)  //(i == 0)
				LastKnownPlayerOamIndex = runningOamIndex;

			runningOamIndex++;

			//Now do the behind effects.
			if(actor->state == ACTSTATE_HOP)
			{
				if(actor->frameindex && actor->frameindex < 12)
				{
					obj = &OamBak[runningOamIndex];
					obj->Priority = 2;
					obj->Shape = 1;
					obj->Size = 0;
					obj->Pltt = 1;
					obj->CharNo = 512;
					obj->HPos = (actor->mx << 4) - gCameraX;
					obj->VPos = (actor->my << 4) - gCameraY;
					if(actor->direction == 0) obj->VPos += hopOffsets[actor->frameindex];
					if(actor->direction == 1) obj->HPos += hopOffsets[actor->frameindex];
					if(actor->direction == 3) obj->HPos -= hopOffsets[actor->frameindex];
					shadowflag = 1; //Mark up that we'll need to load the shadow later.
					runningOamIndex++;
				}
			} //else if(actor->frameindex >= 12)
			//{
			//Could do the dust kicking up here, but that's actually an in-front effect... oh well.
			//}

			//Handle surfing
			if(actor->state >= ACTSTATE_SURF && actor->state <= ACTSTATE_SURFTURN)
			{
				obj = &OamBak[runningOamIndex];
				obj->Priority = 2;
				obj->Shape = 0;
				obj->Size = 2;
				obj->Pltt = 12;
				obj->CharNo = 640 + (16 * ((TotalFrames >> 5) % 2));
				obj->HPos = (actor->mx << 4) - gCameraX - 8;
				obj->VPos = (actor->my << 4) - gCameraY - 16;
				obj->HFlip = 0;
				if(actor->direction == 0)
				{
					obj->VPos += WalkDistLUT[actor->frameindex];
					obj->CharNo += 0;
				}
				if(actor->direction == 1)
				{
					obj->HPos += WalkDistLUT[actor->frameindex];
					obj->CharNo += 64;
					obj->HFlip = 1;
				}
				if(actor->direction == 2)
				{
					obj->VPos -= WalkDistLUT[actor->frameindex];
					obj->CharNo += 32;
				}
				if(actor->direction == 3)
				{
					obj->HPos -= WalkDistLUT[actor->frameindex];
					obj->CharNo += 64;
				}
				OamBak[LastKnownPlayerOamIndex].VPos += ((TotalFrames >> 5) % 2);
				surfflag = 1;
				runningOamIndex++;
			}
		}
	}

	//Load any special effect tiles...
	if(grassflag == 1)
	{
		CpuFastCopy(grasswalkTiles,MEM_VRAM_OBJ+0x4100,640);
		LoadTimeAdjustedColors((unsigned short*)MEM_PAL_OBJ+0xA0, (unsigned short*)grasswalkPal, 16);
	}
	if(emoteflag == 1)
	{
		CpuFastArrayCopy(emoticonsPal,MEM_PAL_OBJ+0x1A0);
		CpuFastArrayCopy(emoticonsTiles,MEM_VRAM_OBJ+0x4400);
	}
	if(shadowflag == 1)
	{
		CpuFastCopy(hopshadowTiles,MEM_VRAM_OBJ+0x4000,0x80);
	}
	if(surfflag == 1)
	{
		CpuFastArrayCopy(surfPal,MEM_PAL_OBJ+0x180);
		CpuFastArrayCopy(surfTiles,MEM_VRAM_OBJ+0x5000);
	}

	if(WeatherEffect) WeatherEffect(0); //run any weather effects we might have.
}

void MotorSprites()
{
	int i;
	for(i = 0; i < MAXACTORS; i++)
	{
		if(Actors[i].sprite) // >0 = in use
		{
			if( (Actors[i].flag) && (GETBIT(ScriptFlags,Actors[i].flag) != Actors[i].flagonoroff) )
				continue;

			if(Actors[i].motor != 0)
			{
				Actors[i].motor(i);
			}
		}
	}
}

void AnimateSprites()
{
	int i;
	for(i = 0; i < MAXACTORS; i++)
	{
		if (Actors[i].sprite) // >0 = in use
		{
			if ((Actors[i].flag) && (GETBIT(ScriptFlags, Actors[i].flag) != Actors[i].flagonoroff))
				continue;

			switch (Actors[i].state)
			{
				case ACTSTATE_WALK:
				{
					if (Actors[i].timer == 0)
					{
						Actors[i].timer = Actors[i].speed;
						if (WalkDistLUT[Actors[i].frameindex] == 0x0E)
						{
							Actors[i].state = ACTSTATE_IDLE;
							Actors[i].frameindex = 0;
							if (Actors[i].direction == 0)
								Actors[i].my++; //south
							else if (Actors[i].direction == 1)
								Actors[i].mx++; //east
							else if (Actors[i].direction == 2)
								Actors[i].my--; //north
							else if (Actors[i].direction == 3) Actors[i].mx--; //west

							Actors[i].lastfoot ^= 1;
						}
						else
						{
							Actors[i].frameindex += 1;
						}
					}
					else
					{
						Actors[i].timer--;
					}
					break;
				}
				case ACTSTATE_TURN:
				{
					if (Actors[i].timer == 0)
					{
						Actors[i].timer = Actors[i].speed;
						Actors[i].state = ACTSTATE_IDLE;
					}
					else
					{
						Actors[i].timer = 0;
					}
					break;
				}
				case ACTSTATE_WAVE:
				case ACTSTATE_JOYNOD:
				{
					Actors[i].timer++;
					if (Actors[i].timer == 40)
					{
						Actors[i].timer = 0;
						Actors[i].state = ACTSTATE_IDLE;
					}
					break;
				}

				case ACTSTATE_PING:
				{
					if (Actors[i].timer == 48)
					{
						Actors[i].timer = Actors[i].speed;
						Actors[i].state = ACTSTATE_IDLE;
						Actors[i].frameindex = 0;
					}
					else
					{
						Actors[i].timer++;
					}
					break;
				}
				case ACTSTATE_HM:
				{
					if (Actors[i].timer == 4)
					{
						if (Actors[i].frameindex < 3)
						{
							Actors[i].frameindex++;
							Actors[i].timer = 0;
						}
						else
						{
							Actors[i].timer = Actors[i].speed;
							Actors[i].state = ACTSTATE_IDLE;
						}
					}
					else
					{
						Actors[i].timer++;
					}
					break;
				}

				case ACTSTATE_HOP:
				{
					if (Actors[i].timer == 0)
					{
						Actors[i].timer = WALKSPEED;
						if (hopSpecial[Actors[i].frameindex] == 255)
						{
							Actors[i].state = ACTSTATE_IDLE;
							Actors[i].frameindex = 0;

							if (Actors[i].direction == 0) Actors[i].my += 2;
							if (Actors[i].direction == 1) Actors[i].mx += 2;
							if (Actors[i].direction == 2) Actors[i].my -= 2;
							if (Actors[i].direction == 3) Actors[i].mx -= 2;

							if (Actors[i].lastfoot == 0)
							{
								Actors[i].lastfoot = 1;
							}
							else
							{
								Actors[i].lastfoot = 0;
							}
						}
						else
						{
							Actors[i].frameindex += 1;
						}
					}
					else
					{
						Actors[i].timer--;
					}
					break;
				}

				case ACTSTATE_SURFUP:
				{
					if (Actors[i].timer == 0)
					{
						Actors[i].timer = Actors[i].speed;
						if (WalkDistLUT[Actors[i].frameindex] == 0x0E)
						{
							Actors[i].state = ACTSTATE_SURF;
							Actors[i].frameindex = 0;
							if (Actors[i].direction == 0) Actors[i].my++; //south
							if (Actors[i].direction == 1) Actors[i].mx++; //east
							if (Actors[i].direction == 2) Actors[i].my--; //north
							if (Actors[i].direction == 3) Actors[i].mx--; //west
						}
						else
						{
							Actors[i].frameindex += 1;
						}
					}
					else
					{
						Actors[i].timer--;
					}
					break;
				}
				case ACTSTATE_SURFTURN:
				{
					if (Actors[i].timer == 0)
					{
						Actors[i].timer = Actors[i].speed;
						Actors[i].state = ACTSTATE_SURF;
					}
					else
					{
						Actors[i].timer--;
					}
					break;
				}
			} // switch (Actors[i].state)
		}
	}
}

//By Cearn
void id_sort_shell(int keys[], u8 ids[], int count)
{
	int ii, inc, jj, id0;
	int key0;

	for(inc=1; inc<=count; inc++) inc *= 3;
	do
	{
		inc = (inc*0x5556)>>16; // for THUMB compile
		for(ii=inc; ii<count; ii++)
		{
			id0 = ids[ii];
			key0= keys[id0];
			for(jj=ii; jj>=inc && keys[ids[jj-inc]]>key0; jj -= inc) ids[jj]= ids[jj-inc];
			ids[jj]= id0;
		}
	} while(inc > 1);
}

void DoApproach(int target, int dist, int dir)
{
	//Oops - I forgot to change this when I mirrored the original games' command list ^^;;;
	int i;
	AGBPrintf("DoApproach: %d, %d, %d, 0x%x", target,dist,dir,ApproachScript);
	ApproachScript[0] = 0x4F; //ApplyMove
	ApproachScript[1] = (char)target;
	ApproachScript[2] = (char)(target >> 8);
	ApproachScript[3] = (int)&ApproachScript[16] >> 0;
	ApproachScript[4] = (int)&ApproachScript[16] >> 8;
	ApproachScript[5] = (int)&ApproachScript[16] >> 16;
	ApproachScript[6] = (int)&ApproachScript[16] >> 24;
	ApproachScript[7] = 0x51; //WaitForMove;
	ApproachScript[8] = (char)target;
	ApproachScript[9] = (char)(target >> 8);
	ApproachScript[10] = 0x02; //End

	ApproachScript[16] = 102; //[!]
	for(i=0; i<dist-1; i++)
	{
		ApproachScript[17+i] = dir+1;
	}
	ApproachScript[17+i] = 254;
	ScriptLoop(ApproachScript);
}

int CheckGrass()
{
	int currentflags, encat, encVal, calcVal;
	currentflags = mhGetMetaTileFlags(currentMapHeader, Actors[0].mx, Actors[0].my);
	if(!(currentflags & MAP16_DANGEROUS)) return 0;
	encat = 0;
	if(currentflags & MAP16_WATER) encat = 1; //surfing

	if(currentMonsters[encat])
	{
		encVal = currentMonsters[encat]->frequency * 16;
		calcVal = rrand(2874);
/*
		if(InvisibleBike)
			encVal = (encVal*4)/5;
		if(BlackFlute)
			encVal = (encVal*1)/2;
		else if(WhiteFlute)
			encVal = (encVal*3)/2;

		if(CleanseTag)
			encVal = (encVal*2)/3;
		else
		{
			if(Stench)
				encVal = (encVal*1)/2;
			else if(Illuminate)
				encVal = (encVal*2)/3;
		}
*/
		AGBPrintf("CheckGrass: %d against %d.\n",calcVal,encVal);

		if(calcVal < encVal)
		{
			InitializeWildBattle(encat);
			return 1;
		}
	} else
		AGBPrintf("CheckGrass: no encounters.\n");
	return 0;
}

int CheckTrainers()
{
	int i, j, dist = 0;
	signed int tx,ty;

	for(i = 0; i < MAXACTORS; i++)
	{
		//KAWA: Important midnight bugfix - disabled trainers still spotted you and hung the game because their statemachines never ran.
		if((Actors[i].flag) && (GETBIT(ScriptFlags,Actors[i].flag) != Actors[i].flagonoroff)) continue;

		dist = 0;

		if((Actors[i].sprite) && (Actors[i].istrainer))
		{
			tx = Actors[i].mx;
			ty = Actors[i].my;
			for(j = 0; j < Actors[i].lineofsight; j++)
			{
				if(Actors[i].direction == ACTFACING_SOUTH)
					ty++;
				else if(Actors[i].direction == ACTFACING_EAST)
					tx--;
				else if(Actors[i].direction == ACTFACING_NORTH)
					ty--;
				else if(Actors[i].direction == ACTFACING_WEST)
					tx++;
				dist++;

				//mapDrawMeta(tx, ty, Actors[i].direction); //ugly hack to see the LOS
				if(mhGetMetaTileFlags(currentMapHeader, tx, ty) & MAP16_SOLID) break;

				if(Actors[0].mx == tx && Actors[0].my == ty)
				{
					AGBPrintf("Spotted by person #%d.\n", i);

					if(Actors[i].istrainer == 1)
					{
						char * script = Actors[i].script; //A BAD HACK APPROACHES
						u16 index = script[1] | script[2] << 8;
						extern const aTrainer Trainers[];
						AGBPrintf("Script: %x, index found %d\n", script, index);
						if(GETBIT(MyBattles, index) == 0)
						{
							Actors[0].state = ACTSTATE_IDLE;
							Actors[0].motor = 0;
							Actors[0].sprite = sprDanny+MyPlayer.gender;
							Actors[0].direction = Actors[i].direction ^ 2;
							Actors[i].istrainer = 0;
							ScriptVar_800F = i;
							sndPlaySound(encounterSongs[Trainers[index].music],SOUND_NORESTART);
							DoApproach(i, dist, Actors[i].direction);
							AGBPrintf("Approached. Challenging...\n");
							Actors[i].istrainer = 1;
							ScriptLoop(Actors[i].script);
							Actors[0].motor = actPlayer;
							return 1;
						}
					} else if(Actors[i].istrainer == 2)
					{
						char * script = Actors[i].script; //A BAD HACK APPROACHES
						u16 index = script[1] | script[2] << 8;
						if(!GETBIT(MyBattles, index))
						{
							ScriptLoop(Actors[i].script);
						}
					}
				}
			}
		}
	}
	return 0;
}

//----------------------------------//
extern int LockDown;

void actPath(int i)
{
	int pathcom;
	if(LockDown == 2) return;

	if(Actors[i].state == ACTSTATE_IDLE)
	{
		pathcom = Actors[i].path[Actors[i].pathcursor];
		Actors[i].pathcursor++;
		AGBPrintf("ActPath: command %d\n", pathcom);
		switch(pathcom)
		{
			case 0:
				break;
			case 1: //down
			case 2: //right
			case 3: //up
			case 4: //left
				Actors[i].direction = pathcom - 1;
				Actors[i].state = ACTSTATE_WALK;
				break;

			case 5: //down
			case 6: //right
			case 7: //up
			case 8: //left
				Actors[i].direction = pathcom - 5;
				Actors[i].state = ACTSTATE_TURN;
				break;

			case 100: //wave
				Actors[i].state = ACTSTATE_WAVE;
				break;
			case 101: //special wave clone for Nurse Joy
				Actors[i].state = ACTSTATE_JOYNOD;
				break;
			case 102: //! <- pop-up emote
			case 103: //!!
			case 104: //X
			case 105: //^_^
			case 106: //?
			case 107: //-_-;
				Actors[i].state = ACTSTATE_PING;
				Actors[i].frameindex = pathcom - 102;
				break;

			case 254:
				Actors[i].pathcursor = 0;
				Actors[i].motor = 0;
				if(i==0) Actors[i].motor = actPlayer;
			case 255:
				Actors[i].pathcursor = 0;
				break;
		}
		if(Actors[i].state == ACTSTATE_WALK)
		{
			if(IsBlockedInDir(Actors[i].mx, Actors[i].my, Actors[i].direction, i))
			{
				Actors[i].state = ACTSTATE_IDLE;
			}
		}
	}
}

void actWander(int i)
{
	if(LockDown == 2) return;
	if(Actors[i].motortimer == 0)
	{
		Actors[i].motortimer = 16 + (rrand(96)>>1);

		if(Actors[i].state == ACTSTATE_IDLE)
		{
			Actors[i].direction = rrand(8) >> 1;
			//if(qran() % 10 > 5) //rng_rand(10) > 5)
			//{
				if(IsBlockedInDir(Actors[i].mx, Actors[i].my, Actors[i].direction, i))
				{
					Actors[i].state = ACTSTATE_IDLE;
				} else
				{
					Actors[i].state = ACTSTATE_WALK;
				}
			//} else
			//{
			//	Actors[i].state = ACTSTATE_IDLE;
			//}
		}
	} else Actors[i].motortimer--;
}

void actLookAround(int i)
{
	if(LockDown == 2) return;
	if(Actors[i].motortimer == 0)
	{
		Actors[i].motortimer = 16 + (rand(96)>>1);
		Actors[i].direction = rrand(8) >> 1;
		CheckTrainers();
	} else Actors[i].motortimer--;
}

void actPlayer(int i)
{
	int block;
	//if((Cont & L_BUTTON) && (Actors[i].state != ACTSTATE_WALK)) Actors[i].state = ACTSTATE_WAVE; //raise hands
	block = IsBlockedInDir(Actors[i].mx, Actors[i].my, Actors[i].direction, i);
#ifdef DEBUG
	if(MyDebug.wtw) block = 0;
#endif

	if(LockDown) return;

	if((Actors[i].oldmapx != Actors[i].mx) || (Actors[i].oldmapy != Actors[i].my))
	{
		if(CheckTrainers() == 0) CheckGrass();
		CheckTraps();
		CheckHatches();
		CheckPoison();
		Actors[i].oldmapx = Actors[i].mx;
		Actors[i].oldmapy = Actors[i].my;
	}


/* //Disabled until we implement the Running Shoes item
	if(Cont & B_BUTTON)
	{
		Actors[i].sprite = sprDANNYRUN+MyPlayer.gender;
		Actors[i].speed = RUNSPEED;
	} else if(Actors[i].sprite == sprDANNYRUN+MyPlayer.gender)
	{
		Actors[i].sprite = sprDANNY+MyPlayer.gender;
		Actors[i].speed = WALKSPEED;
	}
*/

	if(Cont & D_KEY)
	{
		if((Actors[i].direction == ACTFACING_SOUTH) && (Actors[i].state == ACTSTATE_IDLE))
		{
			if(!block) Actors[i].state = ACTSTATE_WALK;
			if(block == 1024) Actors[i].state = ACTSTATE_HOP;
		} else if(Actors[i].state == ACTSTATE_IDLE)
		{
			Actors[i].state = ACTSTATE_TURN;
			Actors[i].direction = ACTFACING_SOUTH;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	if(Cont & R_KEY)
	{
		if((Actors[i].direction == ACTFACING_WEST) && (Actors[i].state == ACTSTATE_IDLE))
		{
			if(!block) Actors[i].state = ACTSTATE_WALK;
			if(block == 1024) Actors[i].state = ACTSTATE_HOP;
		} else if(Actors[i].state == ACTSTATE_IDLE)
		{
			Actors[i].state = ACTSTATE_TURN;
			Actors[i].direction = ACTFACING_WEST;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	if(Cont & U_KEY)
	{
		if((Actors[i].direction == ACTFACING_NORTH) && (Actors[i].state == ACTSTATE_IDLE))
		{
			if(!block) Actors[i].state = ACTSTATE_WALK;
			if(block == 1024) Actors[i].state = ACTSTATE_HOP;
		} else if(Actors[i].state == ACTSTATE_IDLE)
		{
			Actors[i].state = ACTSTATE_TURN;
			Actors[i].direction = ACTFACING_NORTH;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	if(Cont & L_KEY)
	{
		if((Actors[i].direction == ACTFACING_EAST) && (Actors[i].state == ACTSTATE_IDLE))
		{
			if(!block) Actors[i].state = ACTSTATE_WALK;
			if(block == 1024) Actors[i].state = ACTSTATE_HOP;
		} else if(Actors[i].state == ACTSTATE_IDLE)
		{
			Actors[i].state = ACTSTATE_TURN;
			Actors[i].direction = ACTFACING_EAST;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	if(Trg & U_KEY && Actors[i].direction == ACTFACING_NORTH && CurrentProcess == 0)
	{
		FindAndRunSignsOnly();
	}	else if(CurrentProcess == DialogueBox && SM_Dialoguebox.isSign && Actors[i].direction != ACTFACING_NORTH)
	{
		SM_Dialoguebox.isSign = 0;
		SM_Dialoguebox.state = 6;
	}

	CheckMapCrossing();

	MyPlayer.currentMapX = Actors[i].mx;
	MyPlayer.currentMapY = Actors[i].my;
	MyPlayer.currentFacing = Actors[i].direction;
}

void actPlayerSurf(int i)
{
	int block;
	block = IsBlockedInDir(Actors[i].mx, Actors[i].my, Actors[i].direction, i);
#ifdef DEBUG
	if(MyDebug.wtw) block = 0;
#endif

	if(LockDown) return;

	if((Actors[i].oldmapx != Actors[i].mx) || (Actors[i].oldmapy != Actors[i].my))
	{
		if(CheckTrainers() == 0) CheckGrass();
		CheckTraps();
		CheckHatches();
		CheckPoison();
		Actors[i].oldmapx = Actors[i].mx;
		Actors[i].oldmapy = Actors[i].my;
	}

	if(Cont & D_KEY)
	{
		if((Actors[i].direction == ACTFACING_SOUTH) && (Actors[i].state == ACTSTATE_SURF))
		{
			if(block == 2)
			{
				StopSurfing(1);
				return;
			}
			if(!block) Actors[i].state = ACTSTATE_SURFUP;
		} else if(Actors[i].state == ACTSTATE_SURF)
		{
			Actors[i].state = ACTSTATE_SURFTURN;
			Actors[i].direction = ACTFACING_SOUTH;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	if(Cont & R_KEY)
	{
		if((Actors[i].direction == ACTFACING_WEST) && (Actors[i].state == ACTSTATE_SURF))
		{
			if(block == 2)
			{
				StopSurfing(1);
				return;
			}
			if(!block) Actors[i].state = ACTSTATE_SURFUP;
		} else if(Actors[i].state == ACTSTATE_SURF)
		{
			Actors[i].state = ACTSTATE_SURFTURN;
			Actors[i].direction = ACTFACING_WEST;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	if(Cont & U_KEY)
	{
		if((Actors[i].direction == ACTFACING_NORTH) && (Actors[i].state == ACTSTATE_SURF))
		{
			if(block == 2)
			{
				StopSurfing(1);
				return;
			}
			if(!block) Actors[i].state = ACTSTATE_SURFUP;
		} else if(Actors[i].state == ACTSTATE_SURF)
		{
			Actors[i].state = ACTSTATE_SURFTURN;
			Actors[i].direction = ACTFACING_NORTH;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	if(Cont & L_KEY)
	{
		if((Actors[i].direction == ACTFACING_EAST) && (Actors[i].state == ACTSTATE_SURF))
		{
			if(block == 2)
			{
				StopSurfing(1);
				return;
			}
			if(!block) Actors[i].state = ACTSTATE_SURFUP;
		} else if(Actors[i].state == ACTSTATE_SURF)
		{
			Actors[i].state = ACTSTATE_SURFTURN;
			Actors[i].direction = ACTFACING_EAST;
			Actors[i].timer = Actors[i].speed * 4;
		}
	}

	CheckMapCrossing();

	MyPlayer.currentMapX = Actors[i].mx;
	MyPlayer.currentMapY = Actors[i].my;
	MyPlayer.currentFacing = Actors[i].direction;
}

//----------------------------------//

void HandleCut(int i)
{
	int sc, atk, havecut = 0, species = 0;
	int ps = GetPartySize(MyParty);

	//Step one - find a Pokémon that knows Cut
	for(sc = 0; sc < ps; sc++)
	{
		for(atk = 0; atk < 4; atk++)
		{
			if(GetMonsterStats(&MyParty[sc], pMove1 + atk) == moveCut)
			{
				species = GetMonsterStats(&MyParty[sc], pSpecies); //Remember species for animation purposes
				havecut = 1;
				break;
			}
		}
		if(havecut) break;
	}

	//Step one and a half - check for badges
	if(!GETBIT(ScriptFlags,HAVEBADGE1)) havecut = 0; //Quantum Badge required

	//Step two - actually do it
	if(havecut)
	{
		sayf(SYSTEM, strHMOfferCut);
		if(SimpleYesNoLoop())
		{
			CleanUpBG0();
			return;
		}

		sndPlayCry(species, 60);
		sayf(SYSTEM, strHMUse, MyParty[sc].Personal.Nickname, moveNames[moveCut]);

		//Run HM animation

		//Run cutting animation
		Actors[i].state = ACTSTATE_HM;
		Actors[i].timer = 0;
		Actors[i].frameindex = 0;
		while(Actors[i].state == ACTSTATE_HM)
		{
			DoVBlank();
			UpdateSprites();
			AnimateSprites();
		}

		//Disable tree actor
		Actors[i].sprite = 0;
	} else
	{
		sayf(SYSTEM, strHMCouldCut);
	}
}

void HandleRockSmash(int i)
{
	int sc, atk, havesmash = 0, species = 0;
	int ps = GetPartySize(MyParty);

	//Step one - find a Pokémon that knows Rock Smash
	for(sc = 0; sc < ps; sc++)
	{
		for(atk = 0; atk < 4; atk++)
		{
			if(GetMonsterStats(&MyParty[sc], pMove1 + atk) == moveRockSmash)
			{
				species = GetMonsterStats(&MyParty[sc], pSpecies); //Remember species for animation purposes
				havesmash = 1;
				break;
			}
		}
		if(havesmash) break;
	}

	//Step two - actually do it
	if(havesmash)
	{
		sayf(SYSTEM, strHMOfferSmash, moveNames[moveRockSmash]);
		if(SimpleYesNoLoop())
		{
			CleanUpBG0();
			return;
		}

		sndPlayCry(species, 60);
		sayf(SYSTEM, strHMUse, MyParty[sc].Personal.Nickname, moveNames[moveRockSmash]);

		//Run HM animation

		//Run smashing animation
		Actors[i].state = ACTSTATE_HM;
		Actors[i].timer = 0;
		Actors[i].frameindex = 0;
		while(Actors[i].state == ACTSTATE_HM)
		{
			DoVBlank();
			UpdateSprites();
			AnimateSprites();
		}

		//Disable rock actor
		Actors[i].sprite = 0;
	} else
	{
		sayf(SYSTEM, strHMCouldSmash);
	}
}


