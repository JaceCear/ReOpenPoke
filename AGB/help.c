/**	\file help.c
		\brief Help system
		\author Kawa
*/
#include "openpoke.h"

extern const aHelpList help_index[];
extern char *TextBuffer;

unsigned int HelpContext; /**< \brief Determines which list to show, adapting to the current situation. */
unsigned short InHelpMode; /**< \brief Determines wether Help is currently active. */
unsigned short HelpBufferC800[0x3000] INEWRAM; // Tileset is backed up here. FRLG uses 0x4000, but this is sufficient.

/**	\brief Backs up the part of VRAM that Help uses. This lets Help restore things later with \a RestoreC800. */
inline void SaveC800()
{
	CpuFastCopy(MEM_VRAM+0x8c00, HelpBufferC800, sizeof(HelpBufferC800));
}

/**	\brief Restores the VRAM data backed up by \a SaveC800. */
inline void RestoreC800()
{
	CpuFastCopy(HelpBufferC800, MEM_VRAM+0x8c00, sizeof(HelpBufferC800));
}

const unsigned short helptilePal[16]=
{
	0x532E,0x7FFF,0x318C,0x675A,0x043C,0x3AFF,0x0664,0x4BD2,
	0x6546,0x7B14,0x7FFF,0x7729,0x6EA2,0x3940,0x45C0,0x61E0,
};
const unsigned short helptileTiles[16]=
{
	0xDDDD,0xDDDD,0xDDDD,0xDDDD,0xCCCC,0xCCCC,0xFFFF,0xFFFF,
	0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,0xFFFF,
};

//---------------------------------------------------------//

/**
	\brief Handles displaying and navigating the Help data.

	This first backs up everything it changes in any way so it can be seamlessly restored later.
*/
void DoHelp()
{
	u16 i, level = 0, cursor = 0, scroll = 0;
	aHelpList *currentIndex = (aHelpList*)&help_index[HelpContext];
	aHelpListPage *listedPage;
	aHelpList *listedList;
	TVwf *vwf= gp_vwf;
	u32 *oldvwd = vwf->dstD;
	u8 oldclrs[4];
	u32 bgreg = REG_DISPCNT;
	//u32 bgmov = REG_BG0HOFS;
	u32 bgbld = REG_BLDCNT;
	int liststart = 0;

	if(HelpContext == -1) return;

	REG_DISPCNT = DCNT_MODE0 | DCNT_BG0;
	REG_BG0HOFS = -8;
	REG_BG0VOFS = 0;
	REG_BLDCNT = 0;

	u16 aSavedBG0[640]; //could be stuck in save/restore routines instead.
	u16 aSavedPal[16];

	InHelpMode = 1; //so KeyRead doesn't invoke Help again

	for(i=0; i < 640; i++)
	{
		aSavedBG0[i] = BG0MAP[i]; //save...
		BG0MAP[i] = i + 96; //...and overwrite
	}
	for(i=0; i<32; i++) //set up header line
		BG0MAP[64+i] = 95;
	for(i=0; i<32; i++) //set up gutters
	{
		BG0MAP[(i*32)+28] = 94;
		BG0MAP[(i*32)+31] = 94;
	}

	for(i=0; i < 16; i++)
		aSavedPal[i] = *(u16*)(MEM_PAL_BG + (i*2));
	SaveC800();

	vwDestination=vwf->dstD=(u32*)VWDEST_REGULAR; //make sure we're writing to the right place
	oldclrs[1] = gp_vwf->colors[1]; //save ink settings
	oldclrs[2] = gp_vwf->colors[2];
	oldclrs[3] = gp_vwf->colors[3];
	gp_vwf->colors[1] = 1;
	gp_vwf->colors[2] = 2;
	gp_vwf->colors[3] = 15;

	CpuFastCopy(helptileTiles,MEM_VRAM+0x8be0,0x120);
	CpuFastCopy(helptilePal,MEM_PAL_BG,16);
	*(u16*)(MEM_PAL_BG) = 0;

	sndHelp(0);

	while(1)
	{
		//build list
		//vwClear(15);
		CpuFastClear(0xFFFFFFFF, vwDestination, 0x5000); //because vwClear warnings if you say 15.
		vwWrite(6,2,"OpenPoké Help");
		if(level == 0)
		{
			vw_SetSmall();
			vwWrite(144,3,"¥PICK ¢OK £END");
			vw_SetBig();
			liststart = 28;
		} else
		{
			vw_SetSmall();
			vwWrite(129,3,"¥PICK ¢OK £CANCEL");
			vw_SetBig();
			vwWrite(8,24,currentIndex->caption);
			liststart = 45;
		}
		for(i=0;i<7;i++)
		{
			if(currentIndex->items[i+scroll].kind == 0) //page
			{
				listedPage = (aHelpListPage*)currentIndex->items[i+scroll].meh;
				SetText(TextBuffer,(char*)listedPage->caption);
				vwWrite(16,liststart+(i*15),TextBuffer);
			} else if(currentIndex->items[i+scroll].kind == 1) //list
			{
				listedList = (aHelpList*)currentIndex->items[i].meh;
				SetText(TextBuffer,(char*)listedList->caption);
				vwWrite(16,liststart+(i*15),TextBuffer);
			} else if(currentIndex->items[i+scroll].kind == 2) //back
			{
				if(level == 0)
					vwWrite(16,liststart+(i*15),strHelpExit);
				else
					vwWrite(16,liststart+(i*15),strHelpCancel);
				break;
			}
		}
		vwWrite(9,liststart+(cursor*15),strArrow); //draw cursor

		while(1)
		{
			//select list item
			DoVBlank();
			KeyRead();

			if((Trg & KEY_L) || (Trg & KEY_R)) goto fin;

			if(Trg & U_KEY && scroll + cursor > 0)
			{
				vwWrite(9,liststart+(cursor*15),strArrowBlank);
				if(cursor==0)
				{
					scroll--;
					break;
				} else
				{
					cursor--;
				}
				vwWrite(9,liststart+(cursor*15),strArrow);
			}
			if(Trg & D_KEY && currentIndex->items[cursor+scroll].kind != 2)
			{
				vwWrite(9,liststart+(cursor*15),strArrowBlank);
				if(cursor==6)
				{
					scroll++;
					break;
				} else
				{
					cursor++;
				}
				vwWrite(9,liststart+(cursor*15),strArrow);
			}
/*
			if((Trg & U_KEY) || (Trg & D_KEY))
			{
				vwWrite(3,(6+(cursor<<1))<<3,strArrowBlank);
				cursor = wrap(cursor + key_tri_vert(), 0, currentIndex->numItems);
				vwWrite(3,(6+(cursor<<1))<<3,strArrow);
			}
*/

			if(Trg & KEY_B)
			{
				if(level == 0) goto fin;
				level--;
				currentIndex = (aHelpList*)currentIndex->items[currentIndex->numItems-1].meh;
				if(currentIndex == 0) currentIndex=(aHelpList*)&help_index[HelpContext];
				cursor=0;
				scroll=0;
				break; //return to build list phase
			}

			if(Trg & KEY_A)
			{
				AGBPrintf("Kind: %d",currentIndex->items[cursor+scroll].kind);
				if(currentIndex->items[cursor+scroll].kind == 0) //page
				{
					//show page
					listedPage = (aHelpListPage*)currentIndex->items[cursor+scroll].meh;
					//vwClear(15);
					CpuFastClear(0xFFFFFFFF, vwDestination, 0x5000);
					vwWrite(6,2,"OpenPoké Help");
					vw_SetSmall();
					vwWrite(174,3,"¢£CANCEL");
					vw_SetBig();

					SetText(TextBuffer,(char*)listedPage->caption);
					vwWrite(8,24, TextBuffer);
					SetText(TextBuffer,(char*)listedPage->content);
					vwWriteG(1,6, TextBuffer);
					while(1)
					{
						DoVBlank();
						KeyRead();
						if(Trg & KEY_A) break;
						if(Trg & KEY_B) break;
					}
					break; //return to build list phase
				} else if(currentIndex->items[cursor+scroll].kind == 1) //list
				{
					level++;
					currentIndex = (aHelpList*)currentIndex->items[cursor+scroll].meh;
					scroll=0;
					cursor=0;
					break; //return to build list phase
				} else if(currentIndex->items[cursor+scroll].kind == 2) //back
				{
					if(level == 0) goto fin;
					level--;
					currentIndex = (aHelpList*)currentIndex->items[cursor+scroll].meh;
					if(currentIndex == 0) currentIndex=(aHelpList*)&help_index[HelpContext];
					scroll=0;
					cursor=0;
					break; //return to build list phase
				}
			}
		}
	}

fin:
	sndHelp(1);
	AGBPrint("Shutting down help...\n");
	InHelpMode = 0;
	RestoreC800();
	for(i=0; i < 16; i++)
		*(u16*)(MEM_PAL_BG + (i*2)) = aSavedPal[i];
	for(i=0; i < 640; i++)
		BG0MAP[i] = aSavedBG0[i];
	vwDestination=vwf->dstD=oldvwd;
	gp_vwf->colors[1] = oldclrs[1];
	gp_vwf->colors[2] = oldclrs[2];
	gp_vwf->colors[3] = oldclrs[3];
	REG_DISPCNT = bgreg;
	REG_BG0HOFS = 0;
	REG_BG0VOFS = 0;
	REG_BLDCNT = bgbld;
	Trg = 0;
	return;
}

