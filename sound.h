
#ifndef __SOUNDENGINE
#define __SOUNDENGINE

void sndInit();
void sndMain();
void sndSync();
void sndPlaySound(int track, int flags);
void sndFadeToSound(int track);
void sndPauseSound();
void sndResumeSound();
int sndIsMusicPlaying();
void sndPlayFanfare(int track);
void sndSetStereo(int setting);

void sndCursor();
void sndPlayEffectByNum(int index);
void sndHelp(int wut);

void sndPlayCry(int species, int freq);
void sndWaitForCry(int species, int freq);

void sndTest();

#define SOUND_NORMAL 0
#define SOUND_NORESTART 1 //don't restart the song if new track == old track
#define SOUNDSTAT_STOPPED 0
#define SOUNDSTAT_PLAYING 1
#define SOUNDSTAT_NEWWAITING 2
#define SOUNDSTAT_FADEIN 3

#define SFX_NULL 0
#define SFX_HEAL 1
#define SFX_PLACEBALL 2

#endif	// __SOUNDENGINE

// EOF

