/**	\file options.c
		\brief Options screen
		\author Kawa
*/

/*!	\defgroup	grpOptions	Game Options		*/
/*!	\addtogroup	grpOptions		*/
/*!	\{	*/

#include "openpoke.h"

extern const anOption GameOptions[];

/** \brief Returns the specified option's value. */
int GetOption(int id)
{
	switch(id)
	{
		case OPT_TEXTSPEED: 
			return MyPlayer.Options.textspeed;
		case OPT_BATTLESCENE:
			return MyPlayer.Options.battlescene;
		case OPT_BATTLESTYLE:
			return MyPlayer.Options.battlestyle;
		case OPT_SOUND:
			return MyPlayer.Options.soundmode;
		case OPT_BUTTONMODE:
			return MyPlayer.Options.buttonmode;
		case OPT_FRAME:
			return MyPlayer.Options.frame;
		case OPT_BEEPSTYLE:
			return MyPlayer.Options.beepstyle;
		case OPT_BATTLESKIP:
			return MyPlayer.Options.battleskip;
#ifdef DEBUG
		case OPT_WALKTHRU:
			return MyDebug.wtw;
#endif
		default: return -1;
	}
}

/** \brief Sets the specified option's value. */
void SetOption(int id, int val)
{
	switch(id)
	{
		case OPT_TEXTSPEED:
			MyPlayer.Options.textspeed = val;
			break;
		case OPT_BATTLESCENE:
			MyPlayer.Options.battlescene = val;
			break;
		case OPT_BATTLESTYLE:
			MyPlayer.Options.battlestyle = val; break;
		case OPT_SOUND:
			MyPlayer.Options.soundmode = val;
			break;
		case OPT_BUTTONMODE:
			MyPlayer.Options.buttonmode = val;
			break;
		case OPT_FRAME:
			MyPlayer.Options.frame = val;
			break;
		case OPT_BEEPSTYLE:
			MyPlayer.Options.beepstyle = val;
			break;
		case OPT_BATTLESKIP:
			MyPlayer.Options.battleskip = val;
			break;
#ifdef DEBUG
		case OPT_WALKTHRU:
			MyDebug.wtw = val;
			break;
#endif
		default: break;
	}
}

/** \brief Sets up the blending and window Registers to show a highlight. */
void DrawOptionsCursor(int cur)
{
	*(u16*)0x05000000 = 0x0000; //0x7E51;
	REG_BG0VOFS = 0;
	//REG_DISPCNT =  DCNT_MODE0 | DCNT_BG0 | DCNT_WIN0;
	REG_BLDCNT = BLD_BLACK | BLD_BG0;
	REG_BLDALPHA = 0x0000;//0x0010;
	REG_BLDY = 0x0004;
	REG_WIN0H = (16<<8) + (28*8);
	REG_WIN0V = ((55 + (cur * 14)) << 8) + (55+15 + (cur * 14));
	REG_WIN1H = (16<<8) + (28*8);
	REG_WIN1V = 0x1055;
	REG_WININ = WIN_BG0;
	REG_WINOUT = WIN_BLD | WIN_BG0;
}

/** \brief Draws the options and their values. */
void DrawOptions(int scroll)
{
	int i;
	char b[64];

	CleanUpCrap();
	LoadFrame();
	DrawFrame(1,28,6,14);
	vwClear(1);
	for(i=0; i<7; i++)
	{
		vwWrite(4,15+(i*14),GameOptions[i+scroll].caption);
		vwRedLUT();
		if(GameOptions[i+scroll].type == OPTTYPE_SIMPLE)
		{
			vwWrite(128,15+(i*14),GameOptions[i+scroll].choices + (GetOption(i+scroll) * GameOptions[i+scroll].choicelen));
		}
		else if(GameOptions[i+scroll].type == OPTTYPE_NUMBER)
		{
			sprintf(b,"%s%d",GameOptions[i+scroll].choices,GetOption(i+scroll)+1);
			vwWrite(128,15+(i*14),b);
		}
		vwNormalLUT();
	}

	for(i=0; i<6; i++)
	{
		vwSetLine(2,24,7+(i*2),160+(i*64),15);
	}
}

/** \brief Handles the options screen. */
void Options()
{
	int cur = 0, scroll = 0, id;
	char b[64];

	REG_DISPCNT = 0;
	DrawOptions(cur);
	DrawOptionsCursor(cur);
	REG_DISPCNT =  DCNT_MODE0 | DCNT_BG0 | DCNT_WIN0;

	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & U_KEY)
		{
			if(cur)
			{
				cur--;
				DrawOptionsCursor(cur);
			}
			else
			{
				if(scroll)
				{
					scroll--;
					DrawOptions(scroll);
				} else
				{
					scroll = TOTALOPTIONS - 7;
					cur = 6;
					DrawOptionsCursor(cur);
					DrawOptions(scroll);
				}
			}
		}
		if(Trg & D_KEY)
		{
			if(cur+scroll<TOTALOPTIONS-1)
			{
				cur++;
				if(cur==7)
				{
					cur--;
					scroll++;
					DrawOptions(scroll);
				}
				DrawOptionsCursor(cur);
			} else
			{
				cur = 0;
				scroll = 0;
				DrawOptionsCursor(cur);
				DrawOptions(scroll);
			}
		}

		//cur = wrap(cur + key_tri_vert(), 0, TOTALOPTIONS);
		//DrawOptionsCursor(cur);
		if((Trg & L_KEY) || (Trg & R_KEY))
		{
			id = cur+scroll;
			SetOption(GameOptions[id].id,
				wrap(GetOption(GameOptions[id].id) + key_tri_horz(), 0, GameOptions[id].choicect));
			DrawOptions(scroll);
		}

		if(Trg & A_BUTTON)
		{
			if(GameOptions[cur+scroll].type == OPTTYPE_CANCEL) break;
		}

		if(Trg & B_BUTTON)
		{
			break;
		}

		sprintf(b,"%d / %d / %d", cur,scroll,TOTALOPTIONS);
		vwWrite(0,0,b);
	}
	bytecpy(SRAM + 0x18, &MyPlayer.OptionsI, sizeof(MyPlayer.OptionsI));
	u16 check;
	bytecpy(&check, SRAM, sizeof(check));
	if(check != 0xFFFF)
	{
		check = GetChecksum(&MyPlayer, sizeof(MyPlayer));
		bytecpy(SRAM, &check, sizeof(check));
	}
	return;
}

/*!	\}	*/


