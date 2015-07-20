
#ifndef __RTC
#define __RTC

typedef struct RTCTime
{
	u16 year;
	u8 month;
	u8 day;
	u8 dayofweek;
	u8 hours;
	u8 minutes;
	u8 seconds;
} RTCTime;

typedef struct RTCOffset
{
	u8 dayofweek;
	u8 hours;
	u8 minutes;
} RTCOffset;
RTCOffset GameTimeOffset;

extern void ShowClock();

extern void RTC_TurnOn();
extern void RTC_GetTime(RTCTime *myTime);
extern int RTC_Available();

#ifndef AMPZ
	extern void rtc_cmd(int v);
	extern void rtc_data(int v);
	extern int rtc_read(void);
	extern void rtc_enable(void);
	extern int rtc_check(void);
	extern int rtc_get(char *data);
#else
	extern void rtc_command(char cmd);
	extern char rtc_read(void);
	extern int rtc_detect(void);
	extern void rtc_init_transfer(void);
	extern void rtc_end_transfer(void);
#endif

#endif	// __RTC

// EOF
