//======================================================================
//
//	OpenPoké dummy sound engine
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"
#include "sound.h"

u16 snd_TrackNowPlaying;

#define sndSetVol()

void sndInit()
{
	AGBPrint(" > Dummy sound engine initialized (?)\n");
}

void sndMain()
{
	//Called every frame to update the sound data
}

void sndSync()
{
	//Called every VBlank to update the sound Registers
}

void sndPlaySound(int track, int flags)
{
	//Plays given track.
	//If flags & SOUND_NORESTART and we're already playing
	//the specified track, just don't.
}

void sndFadeToSound(int track)
{
	//Queues a new track. SOUND_NORESTART effect is implied.
}

void sndPauseSound()
{
	//Halts playback of all sounds.
}

void sndResumeSound()
{
	//Resumes playback of all sounds.
}

int sndIsMusicPlaying()
{
	//Returns non-zero if music is playing.
	return 0;
}

void sndPlayFanfare(int track)
{
	//Mute out the music, then play a fanfare.
	//When done, fade the music back in.
}

void sndSetStereo(int setting)
{
	//Switches between mono and stereo,
	//depending on the given setting.
}

void sndCursor()
{
	//Generic sound effect routine.
	//Worth replacing with a #define.
}

void sndPlayEffectByNum(int index)
{
	//Plays given sound effect.
}

void sndHelp(int wut)
{
	//Generic sound effect routine.
	//Worth replacing with a #define.
}

void sndHeal()
{
	//Generic sound effect routine.
	//Worth replacing with a #define.
}

void sndPlaceBall()
{
	//Generic sound effect routine.
	//Worth replacing with a #define.
}

void sndPlayCry(int species, int freq)
{
	//Plays cry for given species.
}

void sndWaitForCry(int species, int freq)
{
	//Delay game until cry is no longer playing.
}

void sndTest()
{
	sayf(SYSTEM, "Sound test unavailable\nin dummy sound driver.");
}
