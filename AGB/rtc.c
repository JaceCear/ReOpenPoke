//======================================================================
//
//	OpenPoké realtime clock
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"

extern const unsigned short clockPal[256];
extern const unsigned short clockTiles[7104];
extern const unsigned short clockMap[640];

RTCOffset GameTimeOffset;
int haveRTC;

void ShowClock()
{
	RTCTime myTime;
	char ts[10];
	int i,j;
	char d, k=0;
	u16* digitspal = (u16*)0x5000040;

	REG_DISPCNT = 0;

	LZ77UnCompVram(clockTiles, (u16*)(MEM_VRAM + 0x4000));
	LZ77UnCompVram(clockMap, (u16*)(MEM_VRAM + 0xE800));
	DmaArrayCopy(clockPal, MEM_PAL_BG + 0x0000);

	REG_BG1CNT = BG_8BPP | BG_SIZE0 | BG_PRIO(0) | 29 << BG_SBB_SHIFT | 1 << BG_CBB_SHIFT | BG_MOSAIC;
	REG_BG1HOFS = 8;
	REG_BG1VOFS = 0;
	REG_DISPCNT = REG_DISPCNT =  DCNT_MODE0 | DCNT_BG1 | DCNT_BG0;

	vw_SetSmall();
	vwWhiteTransparentLUT();
	vwWrite(6,1,"¢£CANCEL");
	vwNormalLUT();
	vw_SetBig();
	vwSetLine(22,7,0,96,15);

	while(1)
	{
		DoVBlank();
		KeyRead();
		RTC_GetTime(&myTime);
		sprintf(ts, "%02d%02d", myTime.hours, myTime.minutes);
		for(i=0; i<4; i++)
		{
			d = ts[3-i] - '0';
			for(j=0; j<8; j++) digitspal[(i*7)+j] = clockPal[0x40+j+(d*16)];
		}

		if(myTime.seconds % 2 == 1)
		{
			digitspal[0x1c] = 0x8300;
		} else
		{
			digitspal[0x1c] = 0x0180;
		}
		if(!k) { FadeIn(); k++; }

		if((Trg & KEY_A) || (Trg & KEY_B)) break;
	}

	FadeOut();

	REG_BG1HOFS = 0;
	REG_BG1CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(0) | 29 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;

}

void SetClock()
{
	RTCTime myTime;
	char ts[10];
	int i,j;
	char d, k=0;
	u16* digitspal = (u16*)0x5000040;
	int cursor = 0;

	DmaArrayCopy(clockTiles, MEM_VRAM + 0x4000);
	DmaArrayCopy(clockPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(clockMap, MEM_VRAM + 0xE800);

	REG_BG1CNT = BG_8BPP | BG_SIZE0 | BG_PRIO(0) | 29 << BG_SBB_SHIFT | 1 << BG_CBB_SHIFT | BG_MOSAIC;
	REG_BG1HOFS = 8;

	while(1)
	{
		DoVBlank();
		KeyRead();
		RTC_GetTime(&myTime);
		sprintf(ts, "%02d%02d", myTime.hours, myTime.minutes);
		for(i=0; i<4; i++)
		{
			d = ts[3-i] - '0';
			for(j=0; j<8; j++) digitspal[(i*7)+j] = clockPal[0x40+j+(d*16)];
		}

		if(myTime.seconds % 2 == 1)
		{
			digitspal[0x1c] = 0x8300;
		} else
		{
			digitspal[0x1c] = 0x0180;
		}

		if(!k) { FadeIn(); k++; }

		cursor = wrap(cursor+key_tri_horz(),0,2);
		if(cursor==0)
		{
			if(Trg & KEY_UP)
			{
				GameTimeOffset.minutes++;
				if(GameTimeOffset.minutes == 60) GameTimeOffset.minutes = 0;
			} else if(Trg & KEY_DOWN)
			{
				GameTimeOffset.minutes--;
				if(GameTimeOffset.minutes == 255) GameTimeOffset.minutes = 59;
			}
		}
		//if(cursor==0) GameTimeOffset.minutes = wrap(GameTimeOffset.minutes - key_tri_vert(),0,60);
		//if(cursor==1) GameTimeOffset.hours = wrap(GameTimeOffset.hours - key_tri_vert(),0,24);
		//if(Trg) break;
	}

	FadeOut();

	REG_BG1HOFS = 0;
	REG_BG1CNT = BG_4BPP | BG_SIZE0 | BG_PRIO(0) | 29 << BG_SBB_SHIFT | 0 << BG_CBB_SHIFT | BG_MOSAIC;

}

#define UNBCD(x) (((x) & 0xF) + (((x) >> 4) * 10))

char main_tmp[50];

void RTC_TurnOn()
{
	rtc_enable();
	haveRTC = rtc_check();
	AGBPrintf("RTC_TurnOn: rtc_check returns %d.\n", haveRTC);
	rtc_get(main_tmp);
}

void RTC_GetTime(RTCTime *myTime)
{
	char data[7];

	if(!haveRTC)
	{
		myTime->year = 2009;
		myTime->month = 6;
		myTime->day = 26;
		myTime->dayofweek = 1;
		myTime->hours = 12;
		myTime->minutes = 0;
		myTime->seconds = 0;
		return;
	}

	rtc_get(data);
	myTime->year = UNBCD(data[0]) + 2000;
	myTime->month = UNBCD(data[1]);
	myTime->day = UNBCD(data[2] & 0x3F);
	myTime->dayofweek = UNBCD(data[3] & 0x3F); //rtc_read();
	myTime->hours = UNBCD(data[4] & 0x3F);
	myTime->minutes = UNBCD(data[5]);
	myTime->seconds = UNBCD(data[6]);


	//KAWA: added during late-nighter, adds original-style time shifts.
	//Also lets you play on a real RTC that starts at some random time,
	//and on dead batteries. All we really need are DOW, hours and minutes
	//anyway, right? Seconds are basically only on the clock (blinking colon)
	myTime->minutes = myTime->minutes + GameTimeOffset.minutes;
	if(myTime->minutes > 59)
	{
		myTime->minutes -= 60;
		myTime->hours++;
	}
	myTime->hours = myTime->hours + GameTimeOffset.hours;
	if(myTime->hours > 23)
	{
		myTime->hours -= 24;
		myTime->dayofweek++;
	}
	myTime->dayofweek = (myTime->dayofweek + GameTimeOffset.dayofweek) % 7;
}

#define RTC_DATA ((volatile u16 *)0x080000C4)
#define RTC_RW ((volatile u16 *)0x080000C6)
#define RTC_ENABLE ((volatile u16 *)0x080000C8)

void rtc_cmd(int v)
{
	int l;
	u16 b;

	v = v<<1;

	for(l=7; l>=0; l--)
	{
		b = (v>>l) & 0x2;
		*RTC_DATA = b | 4;
		*RTC_DATA = b | 4;
		*RTC_DATA = b | 4;
		*RTC_DATA = b | 5;
	}
}

void rtc_data(int v)
{
	int l;
	u16 b;

	v = v<<1;

	for(l=0; l<8; l++)
	{
		b = (v>>l) & 0x2;
		*RTC_DATA = b | 4;
		*RTC_DATA = b | 4;
		*RTC_DATA = b | 4;
		*RTC_DATA = b | 5;
	}
}

int rtc_read(void)
{
	int j,l;
	u16 b;
	int v = 0;


	for(l=0; l<8; l++)
	{
		for(j=0;j<5; j++)
			*RTC_DATA = 4;
		*RTC_DATA = 5;
		b = *RTC_DATA;
		v = v | ((b & 2)<<l);
	}

	v = v>>1;

	return v;
}

static int check_val = 0;

void rtc_enable(void)
{
	*RTC_ENABLE = 1;

	*RTC_DATA = 1;
	*RTC_DATA = 5;
	*RTC_RW = 7;

	rtc_cmd(0x63);

	*RTC_RW = 5;

	check_val =  rtc_read();
}

// Normally returns 0x40
int rtc_check(void)
{
	return (check_val != 0);
}

int rtc_get(char *data)
{
	int i;

	*RTC_DATA = 1;
	*RTC_RW = 7;

	*RTC_DATA = 1;
	*RTC_DATA = 5;

	rtc_cmd(0x65);

	*RTC_RW = 5;

	for(i=0; i<4; i++)
		data[i] = (char)rtc_read();

	*RTC_RW = 5;

	for(i=4; i<7; i++)
		data[i] = (char)rtc_read();

	return 0;
}
