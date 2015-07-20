/**	\file timekeeper.c
		\author Kawa
*/
#include "openpoke.h"

int TimeKeeperState = TIMEKEEPER_DISABLED;

void TimeKeeper_StopAndReset()
{
	TimeKeeperState = TIMEKEEPER_DISABLED;
	MyPlayer.Hours = 0;
	MyPlayer.Minutes = 0;
	MyPlayer.Seconds = 0;
	MyPlayer.Milliseconds = 0;
}

void TimeKeeper_Stop()
{
	TimeKeeperState = TIMEKEEPER_DISABLED;
}

void TimeKeeper_Continue()
{
	TimeKeeperState = TIMEKEEPER_ENABLED;
	if(MyPlayer.Hours == 999)
		TimeKeeper_Break();
}

void TimeKeeper()
{
	if(TimeKeeperState != TIMEKEEPER_ENABLED)
		return;

	MyPlayer.Milliseconds++;
	if(MyPlayer.Milliseconds < 59)
		return;

	MyPlayer.Milliseconds = 0;
	MyPlayer.Seconds++;
	if(MyPlayer.Seconds < 59)
		return;

	MyPlayer.Seconds = 0;
	MyPlayer.Minutes++;
	if(MyPlayer.Minutes < 59)
		return;

	MyPlayer.Minutes = 0;
	MyPlayer.Hours++;
	//This part is not how FRLG does it, but it
	//should be close in effect.
	if(MyPlayer.Hours < 999)
		return;

	TimeKeeper_Break();
}

void TimeKeeper_Break()
{
	TimeKeeperState = TIMEKEEPER_BROKEN;
	MyPlayer.Hours = 999;
	MyPlayer.Minutes = 59;
	MyPlayer.Seconds = 59;
	MyPlayer.Milliseconds = 59;
}
