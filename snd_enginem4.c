//======================================================================
//
//	OpenPoké EngineM4 sound engine
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"
#include "sound.h"
#include "enginem4/EngineM4.h"

const unsigned short SoundEffects[] =
{
	71, //Heal
	150, //Place ball
};

int snd_TrackNowPlaying;
int snd_WaitingTrack;
int snd_Volume;
int snd_Status;

//#define sndSetVol() m4aMPlayVolumeControl(&m4a_mplay000, 0xFF, snd_Volume);
#define sndSetVol() M4Players[0].Volume = snd_Volume;

void m4a_PlaySongTbl(u32 Index)
{
	extern struct __SngTbl
	{
		SongData *Song;
		u16	Pl[2];
	} song_table[1];

	struct __SngTbl *Song = &song_table[Index];
	u32 Pl = Song->Pl[0];

	M4_PlaySong(Pl, Song->Song);
}

void sndInit()
{
	AGBPrint("sndInit() here.\n");
	M4_Init();
	snd_Volume = 128;
	AGBPrint("Engine M4 initialized.\n");
}

void sndMain()
{
	M4_Main();

	if(snd_Status == SOUNDSTAT_NEWWAITING)
	{
		snd_Volume-=2;
		sndSetVol();

		if(snd_Volume==0)
		{
			sndPlaySound(snd_WaitingTrack, SOUND_NORESTART);
			snd_Volume = 128;
			sndSetVol();
			snd_Status = SOUNDSTAT_PLAYING;
		}
	}
	else if(snd_Status == SOUNDSTAT_FADEIN)
	{
		snd_Volume+=2;
		sndSetVol();
		if(snd_Volume==128) snd_Status = SOUNDSTAT_PLAYING;
	}
}

void sndSync()
{
	M4_Intr();
}

void sndPlaySound(int track, int flags)
{
	if((flags & SOUND_NORESTART) && (track == snd_TrackNowPlaying))
	{
		AGBPrintf("sndPlaySound: told to play track %d but already playing that.\n", track);
		return;
	}
	snd_TrackNowPlaying = track;
	m4a_PlaySongTbl(track);
	AGBPrintf("sndPlaySound: playing track %d...\n", track);
}

void sndFadeToSound(int track)
{
	if(snd_TrackNowPlaying == track)
		return;
	snd_Status = SOUNDSTAT_NEWWAITING;
	snd_WaitingTrack = track;
}

void sndPauseSound()
{
	M4_PlayerStopAll();
}

void sndResumeSound()
{
	//Watch it!
	M4Players[0].Status |= 1;
	M4Players[1].Status |= 1;
	M4Players[2].Status |= 1;
	M4Players[3].Status |= 1;
}

int sndIsMusicPlaying()
{
	return (M4Players[0].Status & M4_Active);
}

void sndPlayFanfare(int track)
{
	snd_Volume = 0;
	sndSetVol();
	m4a_PlaySongTbl(track);
	while(M4Players[1].Status & M4_Active)
	{
		DoVBlank();
	}
	snd_Status = SOUNDSTAT_FADEIN;
}

void sndSetStereo(int setting)
{
	if(setting == 0)
	{
		REG_SOUNDCNT_H = 0x3302; //Mono
	} else
	{
		REG_SOUNDCNT_H = 0x210E; //Stereo
	}
}

void sndCursor()
{
	m4a_PlaySongTbl(132);
}

void sndPlayEffectByNum(int index)
{
	m4a_PlaySongTbl(SoundEffects[index]);
}

void sndHelp(int wut)
{
	snd_Volume = 64 + (wut*64);
	sndSetVol();
	m4a_PlaySongTbl(377+wut);
}

//***********************************************************************//
extern const WaveData * const crytable[];

void sndPlayCry(int species, int freq)
{
	M4_SFX(crytable[species]);
}
void sndWaitForCry(int species, int freq)
{
	M4Channel * ch = M4_SFX(crytable[species]);
	M4_SFX(crytable[species]);
	while((ch->Status & M4_Active) && (ch->Status & M4_FX))
		DoVBlank();
}
/*
extern const ToneData * const crytable[412];
SongHeader CryHeader;
u8 CryTrack[] =
{
	0xBD, 0x00, 0xBE, 0x7F, 0xBF, 0x40, 0xCF, 0x3C, 0x70, 0x90, 0xAE, 0xCE, 0xB1
};

extern const ToneData vgr_cry_000;

void sndPlayCry(int species, int freq)
{
	AGBPrintf("sndPlayCry: species %d\n", species);
	CryHeader.trks = 1;
	CryHeader.blks = 0;
	CryHeader.prio = 10;
	CryHeader.rvrb = 0;
	CryHeader.tone = (ToneData*)crytable[species];
	AGBPrintf("PlayCry: tone data at 0x%08x.\n", CryHeader.tone);
	*(u32*)CryHeader.part = (u32)&CryTrack;
	CryTrack[7] = freq;
	m4aMPlayStart(&m4a_mplay003, &CryHeader);
}

void sndWaitForCry(int species, int freq)
{
	int oldVolume = snd_Volume;
	snd_Volume /= 2;
	sndSetVol();
	sndPlayCry(species, freq);
	while(m4a_mplay003.stat != 0x80000000)
		DoVBlank();
	snd_Volume = oldVolume;
	sndSetVol();
}
*/
//***********************************************************************//

const char * const songNames[] =
{
	"Item Get", //"Level Up!",
	"Evolution",
	"Battle vs Gym Leader (RS)",
	"Battle vs Trainer (RS)",
	"Battle vs Gym Leader/Elite",
	"Battle vs Trainer",
	"Battle vs Wild Pokémon",
	"Battle vs Champion",
	"Victory vs Trainer",
	"Victory vs Wild Pokémon",
	"Victory vs Leader/Elite",
	"Victory vs Wild Monster (bis)",
	"Fanfare - Big Success",
	"Fanfare - Success",
	"Fanfare - PokéDex Evaluation",
	"Fanfare - Acquired a Pokémon",
	"Fanfare - Caught a Pokémon",
	"Trainer Appears - Bad Guy",
	"Trainer Appears - Girl",
	"Trainer Appears - Boy",
	"Tense Competition",
	"Forget Skill",
	"Bad Luck",
	"Guidance - Follow Me",
	"Game Corner",
	"Team Rocket Hideout",
	"Gym",
	"Jigglypuff's Song",
	"Game Freak",
	"Introduction Demo",
	"Title",
	"Cinnabar Island",
	"Lavender Town",
	"Viridian Forest",
	"Mount Moon",
	"Pokémon Mansion",
	"Road to Viridian City",
	"Welcome to Pokémon",
	"Road to Cerulean City",
	"Road to Fuchsia City",
	"The Last Road",
	"Pallet Town",
	"Oak Research Institute",
	"Professor Oak",
	"Pokémon Center",
	"SS Anne",
	"Pokémon Tower",
	"Silph Co.",
	"Cerulean City",
	"Celadon City",
	"Vermillion City",
	"Viridian City",
	"Floe & Chrono Islands",
	"Fortune & Quest Islands",
	"Sevii Islands",
	"Gary",
	"Gary (bis)",
	"Introduction 1",
	"Introduction 2",
	"Introduction 3",
	"Bicycle",
	"Pokémon Print",
	"Battle vs Deoxys",
	"Deoxys' Appearance",
	"Ending",
	"Hall of Fame",
	"Pokémon Institute (RS)",
	"Mystery Present",
	"Epilogue",
	"Surfing",
	"Teachy TV",
	"Healing",
	"Theme from Thexder",
	"Gyakuten Saiban",
	"Gaston",
	"RPG Maker XP",
	"Doll Judgment",
	"Zelda Death Jingle",
	"Still Alive",
	"New SMB Final Battle",
	"Rock the Mike",
	"Duel of the Fates",
	"Dr. Wily",
	"Cave Story",
	"Flowering Night",
	"Vs. Dialga and Palkia"
};

void sndTest()
{
	char buf[80];
	// int i, vol, numchans;

	int selectedTrack = 0;
	//MusicPlayerTrack * t;

	LoadFrame();
	DrawFrame(1,28,1,18);
	vwClear(1);
	vwWrite(0,0,"\x80\x1A\x80\x1B");
	sprintf(buf, "%d. %s",selectedTrack,songNames[selectedTrack]);
	vwWrite(24,0,buf);
/*
	vwWrite(0,16,"Song header");
	vwWrite(80,16,"Not playing");
	vwWrite(0,32,"Tracks");
	vwWrite(0,48,"Mix channels");
	vwWrite(0,64,"Volume");
*/
	vwSetLine(3,24,2,96,15);
	vwSetLine(3,24,6,160,15);
	vwSetLine(3,24,8,224,15);
	vwSetLine(3,24,10,288,15);
	vwSetLine(3,24,12,352,15);
	vw_SetSmall();
	vwWrite(4,129,"¦SELECT ¢PLAY £STOP");
	vwSetLine(2,18,16, 608, 15);
	vw_SetBig();
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & KEY_START)
		{
			*(u16*)0x05000000 = 0x7FFF;
			sndWaitForCry(315, 30);
			*(u16*)0x05000000 = 0x0000;
		}
		if(Trg & KEY_SELECT)
			sndWaitForCry(25, 30);
			//sndPlayFanfare(12);

		if((Trg & L_KEY) || (Trg & R_KEY))
		{
			selectedTrack = wrap(selectedTrack + key_tri_horz(), 0, (const)( sizeof(songNames) / sizeof(const char*) ) );
			vwClearLine(1,0);
			vwClearLine(1,1);
			vwWrite(0,0,"\x80\x1A\x80\x1B");
			sprintf(buf, "%d. %s",selectedTrack,songNames[selectedTrack]);
			vwWrite(24,0,buf);
		}
		if(Trg & A_BUTTON)
		{
			sndPlaySound(selectedTrack, 0);
			//sprintf(buf, "0x%08x", (unsigned int)mplay_table[0].ma->song);
			//vwWrite(80,16, buf);
		}

		if(Trg & B_BUTTON)
		{
			if(sndIsMusicPlaying())
				sndPauseSound();
			else
				SoftReset();
		}
	}
}


