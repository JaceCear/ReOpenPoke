//======================================================================
//
//	OpenPoké text manager
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"

u32 *vwDestination; //mirrors the TTE engine's value, used for old code

#define DTBSIZE 1000 //text buffer size, based on IDA suggestion

int textcursorx, textcursory; //also legacy

char *TextBuffer;
char StringVar[8][32];
char DefaultTextBuffer[DTBSIZE]; //INEWRAM;

//Takes a string from basically anywhere and expands 0xFD command codes.
int SetText(char *target, char *source)
{
	int sc = 0, tc = 0;
	if(TextBuffer == 0) TextBuffer = (char*)&DefaultTextBuffer;
	if(target == 0) target = TextBuffer;
	if(target == DefaultTextBuffer) memset((char*)&DefaultTextBuffer, 0, DTBSIZE);

	while(source[sc] != 0)
	{
		if(source[sc] == TCC_VAR) //control code
		{
			sc++;
			target += SetText(target+tc, GetTextVarPointer(source[sc])); //recursively expand
			sc++;
		} else
		{
			target[tc++] = source[sc++];
		}
	}
	target[tc] = 0;
	return sc;
}


extern CSTRING playernames[2][12];
char gtvTemp[64]; //temporary storage
//Returns a pointer for SetText to use. Basically, the 0xFD commands.
char *GetTextVarPointer(int varid)
{
	//TODO	Change to a handful of seperate functions, like "GetMoney", "GetSonDaughter"...
	RTCTime myTime;

	switch(varid)
	{
		case 0:
			return "<NULLVAR>";
		case 1:
			return PlayerName;
		case 2:
#ifdef CUSTOM_RIVAL_NAME
			return MyPlayer.rival;
#else
			//If you want it like D/P with a named rival -and- your opposite, just put this in a new case.
			return (char*)(MyPlayer.gender ? playernames[0][0] : playernames[1][0]);
#endif
		case 3:
		case 4:
		case 5:
			return StringVar[varid - 3];
		case 0xA:
			return (char*)(MyPlayer.gender ? strStringVarDaughter : strStringVarSon);
		case 0xB:
			return (char*)(MyPlayer.gender ? strStringVarSon : strStringVarDaughter);
		case 0xC:
			return (char*)(MyPlayer.gender ? strStringVarHis : strStringVarHer);
		case 0xD:
			return (char*)(MyPlayer.gender ? strStringVarGirl : strStringVarGuy);
		case 0xE:
			return (char*)(MyPlayer.gender ? strStringVarChick : strStringVarDude);
		case 0xF:
			RTC_GetTime(&myTime);
			sprintf(gtvTemp,"%02d:%02d:%02d", myTime.hours, myTime.minutes, myTime.seconds);
			return gtvTemp;
		case 0x10:
			return (char*)(GETBIT(ScriptFlags,KNOWBILL) ? strStringVarBill : strStringVarSomeone);
		default:
			sprintf(gtvTemp, "<BADVAR:%02x>", varid);
			return gtvTemp;;
	}
}

//Draws a window frame of the specified dimensions on BG0.
void DrawFrame(int x, int w, int y, int h)
{
	int a, b;
	for(a = x+1; a < x+w-1; a++)
	{
		BG0MAP[(y*32)+a] = 0xF002;
		BG0MAP[((y+h-1)*32)+a] = 0xF008;
		for(b=y+1; b < y+h-1; b++)
		{
			BG0MAP[(b*32)+a] = 0xF005;
		}
	}
	for(a = y+1; a < y+h-1; a++)
	{
		BG0MAP[(a*32)+x] = 0xF004;
		BG0MAP[(a*32)+x+w-1] = 0xF006;
	}
	BG0MAP[(y*32)+x] = 0xF001;
	BG0MAP[(y*32)+x+w-1] = 0xF003;
	BG0MAP[((y+h-1)*32)+x] = 0xF007;
	BG0MAP[((y+h-1)*32)+x+w-1] = 0xF009;
}

//DrawFrame's opposite. Fills the given rect with zeroes.
void ClearFrame(int x, int w, int y, int h)
{
	int a, b;
	for(a=x; a<x+w; a++)
		for(b=y; b<y+h; b++)
			BG0MAP[(b*32)+a] = 0;
}

//Old code, could likely be replaced with something better.
void vwSetLine(int x, int w, int y, int start, int pal)
{
	int b= 0;
	int tpal = pal<<12;
	for(b=x; b<x+w; b++)
	{
		BG0MAP[(y*32)+b] = start + tpal;
		BG0MAP[(y*32)+b+32] = start + 32 + tpal;
		start++;
	}
}




//NAME ENTRY SCREEN

//some ad-hoc graphics...
const unsigned short cursorTiles[64]=
{
	0x3300,0x0003,
	0x3330,0x0003,
	0x0333,0x0000,
	0x0033,0x0000,
	0x0033,0x0000,
	0x0033,0x0000,
	0x0000,0x0000,
	0x0000,0x0000,

	0x0000,0x0000,
	0x0000,0x0000,
	0x0000,0x0000,
	0x0000,0x0000,
	0x0000,0x0000,
	0x0000,0x0000,
	0x1110,0x0211,
	0x2220,0x0222,
};

extern const unsigned short letterboxPal[16];
extern const unsigned short letterboxTiles[240];
extern const unsigned short letterboxMap[640];
extern const unsigned short letterbackPal[16];
extern const unsigned short letterbackTiles[528];
extern const unsigned short letterbackMap[640];

const char NameTable[2][76] =
{
	{
		'A','B','C','D','E','F','G','H','I','J','K','L','M',' ','0','1','2','3','4',
		'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','5','6','7','8','9',
		'a','b','c','d','e','f','g','h','i','j','k','l','m',' ','!','?',0xBF,'-',0x99,
		'n','o','p','q','r','s','t','u','v','w','x','y','z',' ',0x91,0x92,0x93,0x94,'.',
	},
	{
		'À','Á','Â','Ä','Å','È','É','Ê','Ë','Ì','Í','Î','Ï',' ','Æ','Ç','Ð','×','Ø',
		'Ò','Ó','Ô','Õ','Ö','Ù','Ú','Û','Ü','Ý','Þ','ß','ð',' ','æ','ç','þ',0x8C,0xA1,
		'à','á','â','ä','å','è','é','ê','ë','ì','í','î','ï',' ',0x85,0x8A,0x8B,0x9C,0x95,
		'ò','ó','ô','õ','ö','ù','ú','û','ü','ý','þ','ß','ð',' ',' ',' ',' ',' ',' ',
	},
};

void DrawNameTablePage(u32 p)
{
	int x=0,y=0,c=0;
	char foo[2] = { 0,0 };
	TVwf *vwf= gp_vwf;
	vwf->putc_ = (fn_putc)vwf_putc8x16T;
	vwWhiteTransparentLUT();
	for(y=0;y<16;y++)
	{
		vwClearLine(0,y);
	}
	for(y=1; y<5; y++)
	{
		for(x=0; x<19; x++)
		{
			foo[0] = NameTable[p][c++];
			vwWrite(x*8,(y*15)-7,foo);
		}
	}
	vwBlackTransparentLUT();
	vwf->putc_ = (fn_putc)vwf_putc8x16;
}

void BuildCursor()
{
	int i;
	for(i=0; i<4; i++)
	{
		OamBak[120+i].CharNo = 992;
		OamBak[120+i].Size = 0;
		OamBak[120+i].Shape = 0;
		OamBak[120+i].Pltt = 15;
		OamBak[120+i].Priority = 0;
	}
	OamBak[120].HFlip = 0;
	OamBak[120].VFlip = 0;
	OamBak[121].HFlip = 1;
	OamBak[121].VFlip = 0;
	OamBak[122].HFlip = 0;
	OamBak[122].VFlip = 1;
	OamBak[123].HFlip = 1;
	OamBak[123].VFlip = 1;
}

void MoveCursor(u32 x, u32 y, u32 pulse)
{
	OamBak[120].HPos = 22 + (x * 8) - pulse;
	OamBak[120].VPos = 82 + (y * 15) - pulse;
	OamBak[121].HPos = 22 + (x * 8) + 1 + pulse;
	OamBak[121].VPos = 82 + (y * 15) - pulse;
	OamBak[122].HPos = 22 + (x * 8) - pulse;
	OamBak[122].VPos = 82 + (y * 15) + 6 + pulse;
	OamBak[123].HPos = 22 + (x * 8) + 1 + pulse;
	OamBak[123].VPos = 82 + (y * 15) + 6 + pulse;
}

void DrawName(char *text, u32 cursor, u32 length, u16 animate)
{
	int i=0,j=0;
	TVwf *vwf= gp_vwf;
	const u8 bob[4] = { 0, 1, 2, 1 };

	vwClearLine(0,18);
	while(text[i] != 0)
	{
		vwf->dstX = j;
		vwf->dstY = 72;
		vwf->putc_(text[i]);
		j += 10;
		i++;
	}
	for(i=0; i<length; i++)
	{
		OamBak[100+i].HPos = 87 + (i*10);
		OamBak[100+i].VPos = 56;
		OamBak[100+i].CharNo = 993;
		OamBak[100+i].Size = 0;
		OamBak[100+i].Shape = 0;
		OamBak[100+i].Pltt = 15;
		OamBak[100+i].HFlip = 0;
		OamBak[100+i].VFlip = 0;
	}
	OamBak[100+cursor].VPos = 57 + bob[animate % 4];
}

void EnterName(char *target, u32 maxlen, const char *prompt, void *spritecallback(int t))
{
	u32 len = strnlen(target,32);
	u32 x, y, cx=0, cy=0, p=0;
	u16 cursor = len;
	u16 spritetimer = 0;
	const u8 bob[4] = { 0, 1, 2, 1 };

	HelpContext = 2;
	REG_DISPCNT = 0;
	ResetBackgrounds();

	CleanUpCrap();
	DmaArrayCopy(letterbackTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(letterbackPal, MEM_PAL + 0x0000);
	DmaArrayCopy(letterbackMap, MEM_VRAM + 0xE000);
	REG_BG1HOFS = 0;
	REG_BG1VOFS = 0;
	REG_BG2HOFS = 8;
	REG_BG2VOFS = 0;

	DmaArrayCopy(letterboxTiles, MEM_VRAM + 0x0800);
	DmaArrayCopy(letterboxPal, MEM_PAL + 0x0020);
	//DmaArrayCopy(letterboxMap, MEM_VRAM + 0xE800);
	for(x=0;x<640;x++)
		BG1MAP[x] = (64 + letterboxMap[x]) | 0x1000;

	for(x=len; x<maxlen; x++)
	{
		target[x] = 0;
	}

	DrawNameTablePage(p);
	REG_BG0VOFS = 6;

	vwBlackTransparentLUT();
	vwSetLine(11,14,7,384,15);
	vwWrite(0,84+8,prompt);
	vwSetLine(11,14,4,448,15);
	vwSetLine(11,14,5,480,15);

	ClearOamBak();

	CpuFastArrayCopy(cursorTiles,MEM_VRAM_OBJ+0x7C00);
	*(u16*)0x050003E2 = 0x318C;
	*(u16*)0x050003E4 = 0x675A;
	*(u16*)0x050003E6 = 0x25BF;
	BuildCursor();
	MoveCursor(cx,cy,0);
	DrawName((char*)target, cursor, maxlen, spritetimer++);


	for(x=0; x<18; x++)
	{
		vwSetLine(3+x, 2, 11,128+x, 15);
		vwSetLine(3+x,2, 13, 192+x, 15);
		vwSetLine(3+x,2, 15, 256+x, 15);
		vwSetLine(3+x,2, 17, 320+x, 15);
	}

	if(spritecallback != 0)
	{
		OamBak[0].HPos = 48;
		OamBak[0].VPos = 21;
		OamBak[0].Size = 2;
		OamBak[0].Shape = 2;
		OamBak[0].CharNo = 0;
		spritecallback(spritetimer);
	}

	ResetDispCnt();

	FadeIn();
	y= 2;
	x= 0;
	while(1)
	{
		DoVBlank();
		KeyRead();
		if(spritecallback != 0) spritecallback(spritetimer++);
		OamBak[100+cursor].VPos = 57 + bob[(spritetimer >> 2) % 4];

		if(Trg & START_BUTTON)
			 break;


		if(Trg & SELECT_BUTTON)
		{
			p++;
			if(p==2) p=0;
			DrawNameTablePage(p);
		}
		y--;
		x++;
		if(x == 1)
			MoveCursor(cx,cy,1);
		if(x == 8)
			MoveCursor(cx,cy,0);
		if(x == 16)
			MoveCursor(cx,cy,-1);
		if(x == 24)
			MoveCursor(cx,cy,0);
		if(x == 32)
			x=0;

		if(y == 0)
		{
			y=6;
			if(Cont & R_KEY)
			{ cx = wrap(cx+1,0,19); MoveCursor(cx,cy,0); }
			if(Cont & L_KEY)
			{ cx = wrap(cx-1,0,19); MoveCursor(cx,cy,0); }
			if(Cont & D_KEY)
			{ cy = wrap(cy+1,0,4); MoveCursor(cx,cy,0); }
			if(Cont & U_KEY)
			{ cy = wrap(cy-1,0,4); MoveCursor(cx,cy,0); }

			if(Cont & B_BUTTON)
			{
				target[cursor-1] = 0;
				if(cursor)
					cursor--;
				DrawName((char*)target, cursor, maxlen, spritetimer);
			}
		}
		if(Trg & A_BUTTON)
		{
			target[cursor] = NameTable[p][(cy*19)+cx];
			if(cursor < maxlen-1)
				cursor++;
			DrawName((char*)target, cursor, maxlen, spritetimer);
		}
	}
	AGBPrintf("EnterName: result is \"%s\".\n", target);
	FadeOut();
	vwNormalLUT();
}




