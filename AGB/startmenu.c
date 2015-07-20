//======================================================================
//
//	OpenPoké Start-Menu
//		(Press Start on the overworld to open it)
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"


extern int ShowInventory();
extern void Options();

extern void mapLoadMinimal(u32 index);
extern void (*WeatherEffect)(int);

void RepairMap()
{
	REG_DISPCNT = 0;
	CleanUpCrap();
	LoadSpriteColors();
	mapLoadMinimal(MyPlayer.currentMap);
	Trg = 0;
	Cont = 0;
	HandleCamera();
	UpdateSprites();
	mhRedraw(currentMapHeader, Actors[0].mx-7, Actors[0].my-5);
	HandleCamera();
	FocusCam();
	ResetDispCnt();
	FadeIn();
	if(WeatherEffect)
		WeatherEffect(1);
}


//Handlers
int Bag_OnClick()
{
	FadeOut();
	if(ShowInventory() == 0)
	{
		RepairMap();
		return 0;
	}
	else
		return 1;
}

int Mon_OnClick()
{
	FadeOut();
	ShowParty(0,0);
	RepairMap();
	return 0;
}

int Dex_OnClick()
{
	FadeOut();
	openPokeDex();
	RepairMap();
	return 0;
}

int Gear_OnClick()
{
	extern void PokeGear();

	FadeOut();
	PokeGear();
	RepairMap();
	return 0;
}

int Card_OnClick()
{
	FadeOut();
	TrainerCard();
	RepairMap();
	return 0;
}

int Save_OnClick()
{
	SaveGame();
	return 1;
}

int Option_OnClick()
{
	FadeOut();
	Options();
	REG_DISPCNT = 0;
	RepairMap();
	return 0;
}

int Exit_OnClick()
{
	//Dummy function - the main menu handler does this.
	return 1;
}

int Retire_OnClick()
{
	//Stuff goes here
	return 0;
}

int StartMenuSelection;

const void * const StartMenuHandlers[] =
{
	Dex_OnClick,
	Mon_OnClick,
	Bag_OnClick,
	Card_OnClick,
	Save_OnClick,
	Option_OnClick,
	Exit_OnClick,
	Retire_OnClick,
};

extern const unsigned short helpbarPal[16];
extern const unsigned short helpbarTiles[2560];
extern const int StartMenuWidth;

void DrawHelp(int idx)
{
	TVwf *vwf= gp_vwf;
	CpuFastArrayCopy(helpbarTiles,MEM_VRAM+0x8c00);
	CpuFastArrayCopy(helpbarPal,MEM_PAL_BG+0x1C0);
	vwWhiteTransparentLUT();
	vwf->putc_ = (fn_putc)vwf_putc8x16T;
	vwWrite(2,4,StartMenuHelpStrings[idx]);
	vwNormalLUT();
	vwf->putc_ = (fn_putc)vwf_putc8x16;
}

void DrawSafariStats()
{
	char buffer[16];
	vwClearLine(1,11);
	vwClearLine(1,15);
	sprintf(buffer,"%3d / %3d", SafariSteps, 600);
	vwWrite(132,42,buffer);
	sprintf(buffer,strSafariStatBalls, SafariBalls);
	vwWrite(132,56,buffer);
	DrawFrame(0, 12, 0, 6);
	vwSetLine(1,10,1,272,15);
	vwSetLine(1,10,3,336,15);
}

void DoStartMenu()
{
	int i, j;
	int l, m, k;

	int menuItems[8];
	int numItems = 0;
	int MenuHeight;

	AGBPrint("DoStartMenu: menu invoked - building...\n");

	if(GETBIT(ScriptFlags,SAFARIMODE)) menuItems[numItems++] = 7; //retire
	if(GETBIT(ScriptFlags,HAVEPOKEDEX)) menuItems[numItems++] = 0;
	if(GETBIT(ScriptFlags,HAVEPARTY)) menuItems[numItems++] = 1;
	menuItems[numItems++] = 2; //bag
	menuItems[numItems++] = 3; //red
	if(!GETBIT(ScriptFlags,SAFARIMODE)) menuItems[numItems++] = 4; //save
	menuItems[numItems++] = 5; //option
	menuItems[numItems++] = 6; //exit

	MenuHeight = numItems * 2 - 1;

	HelpContext = 1;

Redraw:
	LoadFrame();

	vwClearLine(1,10);
	vwClearLine(1,14);
	vwClearLine(1,18);
	vwClearLine(1,22);
	vwClearLine(1,26);
	vwClearLine(1,30);
	vwClearLine(1,34);
	vwClearLine(1,38);

	for(i=0; i < 160; i++) BG0MAP[i+0x1E0] = i + 96 + 0xE000; //Build help bar

	DrawFrame(30-StartMenuWidth, StartMenuWidth, 0, 2 + MenuHeight);
	for(i = 0; i < MenuHeight; i++)
	{
		k = 256 + (i*32);
		for(j = 0; j < StartMenuWidth - 2; j++)
			BG0MAP[63-StartMenuWidth + (i*32)+j] = 0xF000 + k++;
	}

	k = 0;
	l = 256;
	m = 1;
	j = 0;
	i = 0;
	for(i = 0; i < numItems; i++)
	{
		SetText(TextBuffer, (char*)strStartMenuItems[menuItems[i]]);
		vwWrite(8, 40+ (i * 14), TextBuffer);
		l += 16;
		m += 2;
		j += 2;
		l += 48;
	}

	vwWrite(0,40+(StartMenuSelection*14),strArrow);

	DrawHelp(menuItems[StartMenuSelection]);

	if(GETBIT(ScriptFlags,SAFARIMODE)) DrawSafariStats();

	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & B_BUTTON)
			break;

		if(Trg & A_BUTTON)
		{
			sndCursor();

			ClearFrame(30-StartMenuWidth,StartMenuWidth,0,2+ MenuHeight);
			int (*handler)(void) = (void*)StartMenuHandlers[menuItems[StartMenuSelection]];
			i = handler();
			if(i==1)
			{
				break;
			} else
			{
				goto Redraw;
			}
		}
		if(Trg & D_KEY)
		{
			sndCursor();

			vwWrite(0,40+(StartMenuSelection*14),strArrowBlank);
			StartMenuSelection++;
			if(StartMenuSelection > numItems-1)
				StartMenuSelection = 0;
			vwWrite(0,40+(StartMenuSelection*14),strArrow);
			DrawHelp(menuItems[StartMenuSelection]);
		}
		if(Trg & U_KEY)
		{
			sndCursor();

			vwWrite(0,40+(StartMenuSelection*14),strArrowBlank);
			StartMenuSelection--;
			if(StartMenuSelection < 0)
				StartMenuSelection = numItems-1;
			vwWrite(0,40+(StartMenuSelection*14),strArrow);
			DrawHelp(menuItems[StartMenuSelection]);
		}
	}

	HelpContext = 0;
	ClearFrame(0, 32, 0,32);
	vwClear(0);

	Trg = 0;
}
