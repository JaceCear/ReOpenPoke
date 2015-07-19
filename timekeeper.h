#define TIMEKEEPER_DISABLED 0
#define TIMEKEEPER_ENABLED 1
#define TIMEKEEPER_BROKEN 2

void TimeKeeper_StopAndReset();
void TimeKeeper_Stop();
void TimeKeeper_Continue();
void TimeKeeper();
void TimeKeeper_Break();
