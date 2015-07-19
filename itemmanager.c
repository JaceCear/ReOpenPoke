/**	\file itemmanager.c
		\brief Item manager
		\author Kawa
*/
#include "openpoke.h"

extern const unsigned short inventoryPal[16];
extern const unsigned short inventoryTiles[1056];
extern const unsigned short inventoryMap[640];

extern const unsigned long  * const itemicons[];

extern const unsigned short maleBagTiles[4096];
extern const unsigned short maleBagPal[16];
extern const unsigned short femaleBagTiles[4096];
extern const unsigned short femaleBagPal[16];

extern const anInventoryPage InventoryPages[6];

anInventoryItem inventory[200] INEWRAM;

void Inventory_ShowItem(int index);
void Inventory_WriteList(int page, int scrolloffset, int cursor);
int Inventory_MultipleChoice(int left, int top, int width, int choices, int bcancel); //CHOICELIST choices);

extern void ItemUseAnimation(int itemindex, aPokemon * target);

void DrawInventoryScreen(int page, int scrolloffset, int cursor)
{
	int idx;
	short * bagTiles;
	short * bagPal;

	CleanUpCrap();
	ClearOamBak();
	DmaArrayCopy(inventoryTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(inventoryPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(inventoryMap, MEM_VRAM + 0xE800);
	LoadFrame();

	vwWhiteTransparentLUT();
	vwWrite(148,32,(char*)InventoryPages[page].name2);
	vwSetLine(1,10,1,242,15);

	if(MyPlayer.gender == 0)
	{
		bagTiles = (short*)maleBagTiles;
		bagPal = (short*)maleBagPal;
	}
	else
	{
		bagTiles = (short*)femaleBagTiles;
		bagPal = (short*)femaleBagPal;
	}

	DmaCopy(bagTiles, MEM_VRAM_OBJ + 0x0800,0x2000);
	DmaCopy(bagPal, MEM_PAL_OBJ + 0x0020,32);

	REG_BG1HOFS= 8;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;

	OamBak[0].CharNo = 0;
	OamBak[0].Pltt = 0;
	OamBak[0].HPos = 8;
	OamBak[0].VPos = 124;
	OamBak[0].Shape = 0;
	OamBak[0].Size = 2;

	OamBak[1].HPos = 8;
	OamBak[1].VPos = 36;
	OamBak[1].CharNo = 64 + (page*64);
	OamBak[1].Pltt = 1;
	OamBak[1].Size = 3;
	OamBak[1].Shape = 0;

	Inventory_WriteList(page, scrolloffset, cursor);
	Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
	for(idx=0; idx<6; idx++)
		vwSetLine(11,18,(idx<<1)+1,224+(64*idx),15);
	vwWrite(6,(cursor+2)*16,strArrow);
}

/** \brief Main inventory screen handler */
int ShowInventory()
{
	int page = 0;
	int cursor = 0;
	int scrolloffset = 0;
	int foo, bar=0;
	int itemuseret;

	REG_DISPCNT = 0;

	DrawInventoryScreen(page, scrolloffset, cursor);
	ResetDispCnt();
	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & A_BUTTON)
		{
			if(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx == 0)
				break; //cancel
			vwNormalLUT();
			switch(page)
			{
			case 0:
				foo = Inventory_MultipleChoice(21,10,9, 1,1); //Choice_Items);
				if(foo == 0) //use
					bar = 1;
				if(foo == 1) //give
					bar = 2;
				if(foo == 2) //toss
					bar = 3;
				if(foo == 3) //cancel
					bar = 0;
				break;
			case 1:
				if(MyPlayer.Registereditem == inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx)
					foo = Inventory_MultipleChoice(21,12,9, 3,1); //Choice_KeyItems2);
				else
					foo = Inventory_MultipleChoice(21,12,9, 2,1); //Choice_KeyItems);
				if(foo == 0)
					bar = 1; //use
				if(foo == 1)	
					bar = 4; //Pokedex_RegisterPkmn
				if(foo == 2)
					bar = 0; //cancel
				break;
			case 2:
				foo = Inventory_MultipleChoice(21,12,9, 4,1); //Choice_Balls);
				if(foo == 0) bar = 2; //give
				if(foo == 1) bar = 3; //toss
				if(foo == 2) bar = 0; //cancel
				break;
			case 3:
				bar = 1;
				break;
			}

			if(bar==0) //Cancel
				Trg = 0; //Cancel can be selected with B, which echos through and closes the screen.
			if(bar==4) //Pokedex_RegisterPkmn
			{
				if(MyPlayer.Registereditem == inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx)
				{
					//Deselect
					MyPlayer.Registereditem = 0;
				} else
				{
					//Pokedex_RegisterPkmn
					MyPlayer.Registereditem = inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx;
				}
				DrawInventoryScreen(page, scrolloffset, cursor);
			}

			if(bar==1)
			{
				OamBak[0].HPos = -32;
				if(items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].fielduse)
				{
					itemuseret = items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].fielduse(
													items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].id,
													items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].special1,
													items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].special2,
													items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].param1,
													items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].param2
												);

					if(itemuseret == IR_REDRAW) //Redraw and continue.
					{
						DrawInventoryScreen(page, scrolloffset, cursor);
					}
					if(itemuseret == IR_BREAK) //Return IMMEDIATELY. Don't worry about cleaning up, but let the item do that itself.
						return 1;

					if(itemuseret == IR_FADE) //Redraw and fade in.
					{
						REG_DISPCNT = 0;
						DrawInventoryScreen(page, scrolloffset, cursor);
						ResetDispCnt();
						FadeIn();
					}

				}
				else
				{
					if((items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].id >= itemTM01) &&
						 (items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].id <= itemHM08))
					{
						itemuseret = item_TM(items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].id, 0,0,0,0);
						if(itemuseret == IR_REDRAW) //Redraw and continue.
						{
							DrawInventoryScreen(page, scrolloffset, cursor);
						}
						if(itemuseret == IR_BREAK) //Return IMMEDIATELY. Don't worry about cleaning up, but let the item do that itself.
							return 1;

						if(itemuseret == IR_FADE) //Redraw and fade in.
						{
							REG_DISPCNT = 0;
							DrawInventoryScreen(page, scrolloffset, cursor);
							ResetDispCnt();
							FadeIn();
						}
					}
					else
					{
						sayf(SYSTEM,"lol nullpointer exception");
					}
				}
				OamBak[0].HPos = 8;
			}
			DrawInventoryScreen(page, scrolloffset, cursor);
		}
		if(Trg & B_BUTTON)
		{
			break;
		}
		if(Trg & U_KEY)
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			if(cursor==0)
			{
				if(scrolloffset > 0) scrolloffset--;
				Inventory_WriteList(page, scrolloffset, cursor);
			} else
			{
				cursor--;
			}
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
		}
		else if((Trg & D_KEY) && (inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx)) //can't pass Cancel.
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			if(cursor==5)
			{
				if(scrolloffset < 40)
					scrolloffset++;
				Inventory_WriteList(page, scrolloffset, cursor);
			}
			else
			{
				cursor++;
			}
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
		}
		else if((Trg & L_KEY) && (page > 0))
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			page--;
			scrolloffset = 0;
			cursor = 0;
			OamBak[1].CharNo = 64 + (page*64);
			Inventory_WriteList(page, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			vwWhiteTransparentLUT();
			vwWrite(148,32,(char*)InventoryPages[page].name2);
		}
		else if((Trg & R_KEY) && (page < 2)) //set to 4 to allow TMs and Berries without case/pouch
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			page++;
			scrolloffset = 0;
			cursor = 0;
			OamBak[1].CharNo = 64 + (page*64);
			Inventory_WriteList(page, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			vwWhiteTransparentLUT();
			vwWrite(148,32,(char*)InventoryPages[page].name2);
		}
	}
	FadeOut();
	vwNormalLUT();
	ClearOamBak();
	CleanUpCrap();
	return 0;
}

/** \brief Adaptation of ShowInventory for in-battle purposes */
int BattleInventory()
{
	int idx, page = 0;
	int cursor = 0;
	int scrolloffset = 0;

	REG_DISPCNT = 0;
	CleanUpCrap();
	ClearOamBak();
	DmaArrayCopy(inventoryTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(inventoryPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(inventoryMap, MEM_VRAM + 0xE800);
	LoadFrame();

	Inventory_WriteList(page, scrolloffset, cursor);
	Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
	for(idx=0; idx<6; idx++)
		vwSetLine(11,18,(idx<<1)+1,224+(64*idx),15);
	vwWrite(6,(cursor+2)*16,strArrow);

	vwWhiteTransparentLUT();
	vwWrite(148,32,(char*)InventoryPages[page].name2);
	vwSetLine(1,10,1,240,15);

	REG_BG1HOFS= 8;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;

	OamBak[0].CharNo = 0;
	OamBak[0].Pltt = 0;
	OamBak[0].HPos = 8;
	OamBak[0].VPos = 124;
	OamBak[0].Shape = 0;
	OamBak[0].Size = 2;

	ResetDispCnt();
	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & A_BUTTON)
		{
			if(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx == 0) break; //cancel
			vwNormalLUT();
			if(page == 0)

			OamBak[0].HPos = -32;
			if(items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].battleuse)
			{
				return inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx;
			} else
			{
				return 0;
			}
			OamBak[0].HPos = 8;
		}
		if(Trg & B_BUTTON)
		{
			break;
		}
		if(Trg & U_KEY)
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			if(cursor==0)
			{
				if(scrolloffset > 0) scrolloffset--;
				Inventory_WriteList(page, scrolloffset, cursor);
			} else
			{
				cursor--;
			}
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
		} else if((Trg & D_KEY) && (inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx)) //can't pass Cancel.
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			if(cursor==5)
			{
				if(scrolloffset < 40) scrolloffset++;
				Inventory_WriteList(page, scrolloffset, cursor);
			} else
			{
				cursor++;
			}
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
		}
		else if((Trg & L_KEY) && (page>0))
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			page--;
			scrolloffset = 0;
			cursor = 0;
			Inventory_WriteList(page, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			vwWhiteTransparentLUT();
			vwWrite(148,32,(char*)InventoryPages[page].name2);
		}
		else if((Trg & R_KEY) && (page < 2)) //set to 4 to allow TMs and Berries without case/pouch
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			page++;
			scrolloffset = 0;
			cursor = 0;
			Inventory_WriteList(page, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			vwWhiteTransparentLUT();
			vwWrite(148,32,(char*)InventoryPages[page].name2);
		}
	}
	FadeOut();
	vwNormalLUT();
	ClearOamBak();
	CleanUpCrap();
	return 0;
}

/** \brief Adaptation of ShowInventory for giving items to hold */
int HoldInventory()
{
	int idx, page = 0;
	int cursor = 0;
	int scrolloffset = 0;

	REG_DISPCNT = 0;
	CleanUpCrap();
	ClearOamBak();
	DmaArrayCopy(inventoryTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(inventoryPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(inventoryMap, MEM_VRAM + 0xE800);
	LoadFrame();

	Inventory_WriteList(page, scrolloffset, cursor);
	Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
	for(idx=0; idx<6; idx++)
		vwSetLine(11,18,(idx<<1)+1,224+(64*idx),15);
	vwWrite(6,(cursor+2)*16,strArrow);

	vwWhiteTransparentLUT();
	vwWrite(148,32,(char*)InventoryPages[page].name2);
	vwSetLine(1,10,1,240,15);

	REG_BG1HOFS= 8;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;

	OamBak[0].CharNo = 0;
	OamBak[0].Pltt = 0;
	OamBak[0].HPos = 8;
	OamBak[0].VPos = 124;
	OamBak[0].Shape = 0;
	OamBak[0].Size = 2;

	ResetDispCnt();
	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & A_BUTTON)
		{
			if(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx == 0) break; //cancel
			vwNormalLUT();

			OamBak[0].HPos = -32;
			if(page == 1)
			{
				sayf(SYSTEM, strInventCantBeHeld, items[inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx].name);
				Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			} else
			{
				return inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx;
			}
			OamBak[0].HPos = 8;
		}
		if(Trg & B_BUTTON)
		{
			break;
		}
		if(Trg & U_KEY)
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			if(cursor==0)
			{
				if(scrolloffset > 0) scrolloffset--;
				Inventory_WriteList(page, scrolloffset, cursor);
			} else
			{
				cursor--;
			}
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
		} else if((Trg & D_KEY) && (inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx)) //can't pass Cancel.
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			if(cursor==5)
			{
				if(scrolloffset < 40) scrolloffset++;
				Inventory_WriteList(page, scrolloffset, cursor);
			} else
			{
				cursor++;
			}
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
		}
		else if((Trg & L_KEY) && (page>0))
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			page--;
			scrolloffset = 0;
			cursor = 0;
			Inventory_WriteList(page, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			vwWhiteTransparentLUT();
			vwWrite(148,32,(char*)InventoryPages[page].name2);
		}
		else if((Trg & R_KEY) && (page < 4)) //set to 4 to allow TMs and Berries without case/pouch
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			page++;
			scrolloffset = 0;
			cursor = 0;
			Inventory_WriteList(page, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			vwWhiteTransparentLUT();
			vwWrite(148,32,(char*)InventoryPages[page].name2);
		}
	}
	FadeOut();
	vwNormalLUT();
	ClearOamBak();
	CleanUpCrap();
	return 0;
}

/** \brief Writes the inventory list.
		\param page Which inventory page to start from
		\param scrolloffset Scrolling offset to start from
		\param cursor Where to point to
*/
void Inventory_WriteList(int page, int scrolloffset, int cursor)
{
	int idx,i=0;
	char blub[32];
	char blarg[4];
	int pageoffset = InventoryPages[page].offset;

	vwBlackTransparentLUT();
	for(idx = 0; idx < 6; idx++)
	{

		if((inventory[pageoffset+idx+scrolloffset].itemidx) && (inventory[pageoffset+idx+scrolloffset].itemcnt))
		{
		// Write the items' names
		// to the screen
			// store formatted text in blub
			sprintf(blub,"%s              ",(char*)items[inventory[pageoffset+idx+scrolloffset].itemidx].name);
			// write it to the screen
			vwWrite(16,(idx+2)*16,(char*)blub);

			// set the font-size to 'small'
			vw_SetSmall();

			if(page == 1)
			{
				vwWrite(118,((idx+2)*16)+1, "     ");
				if(MyPlayer.Registereditem == inventory[pageoffset+idx+scrolloffset].itemidx)
				{
					vwRedTransparentLUT();
					vwWrite(118,((idx+2)*16)+1, "set");
					vwBlackTransparentLUT();
				}
			}
			else
			{
				sprintf(blarg,"×%02d",inventory[pageoffset+idx+scrolloffset].itemcnt);
				vwWrite(118,((idx+2)*16)+1, blarg);
			}
			// reset font-size
			vw_SetBig();
		}
		else
		{
			if(i) sprintf(blub,"                             ");
			else	sprintf(blub,strInventCancel);
			i++;
			vwWrite(16,(idx+2)*16,(char*)blub);
			vw_SetSmall();
			vwWrite(118,((idx+2)*16)+1, "     ");
			vw_SetBig();
		}
	}
}

/** \brief Displays icon and description for the specified item */
void Inventory_ShowItem(int index)
{
	int itempicbuf[0x120];

	vwWhiteTransparentLUT();
	CpuFastClear(0, vwDestination + 0x1000, 0x1800); \
	if(index==0)
		vwWrite(0,131,strInventCloseBag);
	else
		vwWrite(0,131,(char*)items[index].description);
	vwBlackTransparentLUT();
	vwSetLine(5,24,14,608,15);
	vwSetLine(5,24,16,672,15);
	vwSetLine(5,24,18,736,15);

	DmaCopy(itemicons[(index*2)+1], MEM_PAL_OBJ, 32);

	LZ77UnCompWram((u8*)itemicons[index*2], itempicbuf);
	DmaCopy(itempicbuf, MEM_VRAM_OBJ, 0x60);
	DmaCopy(itempicbuf + 0x18, MEM_VRAM_OBJ + 0x80, 0x60);
	DmaCopy(itempicbuf + 0x30, MEM_VRAM_OBJ + 0x100, 0x60);
}

/** \brief Adaption from \a MultipleChoice with a different layout */
int Inventory_MultipleChoice(int left, int top, int width, int choices, int bcancel) //CHOICELIST choices)
{
	u32 i,j,k,l,m,c=0;
	extern const char * Choices[];
	AnOptionsSet * set = (AnOptionsSet*)&ChoiceSets[choices];
	DrawFrame(left, width, top, (set->NumChoices*2)+2);
	j = 0;
	k = 372;
	l = 0;
	m = 0;

	for(i=0; i < set->NumChoices * 2; i++) CpuFastClear(0x11111111, 0x0600AE40 + (i * 0x400), 0x1B0);
	for(i=0; i < set->NumChoices; i++)
	{
		vwWriteG(20,8+(i*2), (char*)Choices[set->Options[i]]);
		vwSetLine(left+2, width-3, top+1+(i*2), k, 15);
		k += 64;
	}

	vwWriteG(18,8,strArrow);
	vwSetLine(left+1,1,top+1,370,15);

	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & A_BUTTON)
			break;
		if(Trg & B_BUTTON && bcancel)
		{
			c = set->NumChoices - 1;
			break;
		}
		if((Trg & U_KEY) || (Trg & D_KEY))
		{
			vwSetLine(left+1,1,top+1+(c<<1),434,15);
			c = wrap(c + key_tri_vert(), 0, set->NumChoices);
			vwSetLine(left+1, 1, top+1+(c<<1), 370, 15);
		}
	}
	ClearFrame(left, width, top, (set->NumChoices*2)+2);
	return c;
}

/** \brief Gives the player an item
		\param index Item to give

		First scans the page the item should go in to see if you have at least one already. If there is, increases the \a amount value. If there is not, appends the item to the list.

		\todo Should return an error if there's no room, be it a full page or having 99 items already.
*/
void GiveItem(int index)
{
	int i, j;
	j = items[index].pocket - 1;
	for(i=InventoryPages[j].offset; i<InventoryPages[j].offset+InventoryPages[j].length; i++)
	{
		if(inventory[i].itemidx == index) //have one of these already
		{
			inventory[i].itemcnt++;
			break;
		}
		if(inventory[i].itemcnt == 0) //empty slot
		{
			inventory[i].itemidx = index;
			inventory[i].itemcnt = 1;
			break;
		}
	}
}

// "Overload" of the GiveItem-Function
void GiveItems(int index, int amount)
{
	if(amount > 0 && index > 0)
		{
			int i;

			for(i = 0 ;i < amount; i++)
				{
					GiveItem(index);
				}
		}
}

/** \brief Takes an item from the player
		\param index Item to take

		Scans the player's inventory, the full thing, as opposed to the page-aware \a GiveItem. If the specified item is found, decreases that item's \a amount value. If the \a amount is then zero, removes the item by copying everything in the page up.

		\todo Should return errors.
		\todo Should put a terminator at the (new) end of the list when needed.
*/
void TakeItem(int index)
{
	int i, j;

	if(index==0) return;

	AGBPrintf("take item index %d.\n",index);

	for(i=0; i<200; i++)
	{
		if(inventory[i].itemidx == index) //found item
		{
			AGBPrintf("found\n");
			AGBPrintf("Old item count %d\n",inventory[i].itemcnt);
			inventory[i].itemcnt--;
			AGBPrintf("New item count %d\n",inventory[i].itemcnt);
			if(inventory[i].itemcnt == 0) //that the last one?
			{
				AGBPrintf("removing...\n");
				for(j = i; j < i + InventoryPages[items[inventory[i].itemidx].pocket].length - 2; j++)
				{
					inventory[j].itemidx = inventory[j+1].itemidx;
					inventory[j].itemcnt = inventory[j+1].itemcnt;
				}
				inventory[j].itemidx = 0;
				inventory[j].itemcnt = 0;
			}
			break;
		}
	}
}

/** \brief Checks if the player has at least one instance of the specified item.
		\param index The item to look for
*/
int HasItem(int index)
{
	int i;

	if(index==0) return 0;

	for(i=0; i<200; i++)
	{
		if(inventory[i].itemidx == index) //found item
		{
			return 1;
		}
	}
	return 0;
}

void UseRegisteredItem()
{
	if(MyPlayer.Registereditem)
	{
		if(items[MyPlayer.Registereditem].fielduse)
		{
			int i = items[MyPlayer.Registereditem].fielduse(
								items[MyPlayer.Registereditem].id,
								items[MyPlayer.Registereditem].special1,
								items[MyPlayer.Registereditem].special2,
								items[MyPlayer.Registereditem].param1,
								1
							);
			if(i == IR_FADE)
			{
				RepairMap();
				FadeIn();
			}
		}
	} else
	{
		sayf(SYSTEM, strNoRegisteredItem);
	}
}

//-----------------------//

int item_NoUse(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	sayf(SYSTEM,strTimeAndPlaceForEverything);
	return 0;
}


int item_Bike(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	if(Actors[0].sprite == 3+MyPlayer.gender) //already on
	{
		//set up walk
		Actors[0].sprite = 1+MyPlayer.gender;
		Actors[0].speed = WALKSPEED;
		Actors[0].motor = actPlayer;
	}
	else
	{
		//set up bike
		Actors[0].sprite = 3+MyPlayer.gender;
		Actors[0].speed = BIKESPEED;
		Actors[0].motor = actPlayer;
	}

	if(param2 == 1)
		return 0;

	//clean up
	FadeOut();
	vwNormalLUT();
	ClearOamBak();
	DmaClear(0, MEM_VRAM+0xF800, 0x600);

	//reload map
	LoadSpriteColors();
	mapLoad(MyPlayer.currentMap);
	mhRedraw(currentMapHeader, Actors[0].mx-7, Actors[0].my-5);
	FocusCam();
	UpdateSprites();
	FadeIn();
	return IR_BREAK;
}

extern void TownMap();
int item_TownMap(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	FadeOut();
	TownMap();
	return IR_FADE;
}

int item_TM(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	extern const unsigned short TMList[];
	int idx = index - itemTM01;
	if(index < itemHM01)
		sayf(SYSTEM,strInventUseTM, items[index].name, moveNames[TMList[idx]]);
	else
		sayf(SYSTEM,strInventUseHM, items[index].name, moveNames[TMList[idx]]);

	if(Inventory_MultipleChoice(21,8,8, 0,0)) return 0;
	int pk = ShowParty(psmTeachTM, idx);
	if(pk != -1)
	{
		int slot = SelectLearnMove(&MyParty[pk],TMList[idx]);
		if(slot < 4)
		{
			AGBPrintf("item_TM: teaching move to monster #%d, slot #%d.\n", pk, slot);
			LearnMove(&MyParty[pk], TMList[idx], slot);
			if(index < itemHM01)
			{
				AGBPrintf("item_TM: removing item #%d from inventory...\n", index);
				TakeItem(index);
			}
		}
		else
			AGBPrintf("item_TM: cancelled.\n");
	}
	return IR_FADE;
}

#include "battleEngine/btlmessages.h"
extern aBattle ThisBattle;
extern aFighter fighters[4];
int PokeBall_GetSuccess(int ball)
{
	//X = (((A*3-B*2)*C)/(A*3))*D
	//where A = target's total HP
	//			B = target's current HP
	//			C = catch rate
	//			D	= status modifier (2 if asleep or frozen, 1.5 if burned, paralyzed or poisoned)

	//There's more to come after this, but it involves square roots somehow so...

	int a = fighters[1].mon->Status.TotalHP;
	int b = fighters[1].mon->Status.CurrentHP;
	int catchrate = BaseStats[fighters[1].species].CatchRate;
	AGBPrintf("A = %d\nB = %d\nC = %d\n",a,b,catchrate);
	switch(ball)
	{
		case 0: catchrate = catchrate * 255; break; //Master Ball - always works
		case 1: catchrate = catchrate * 2; break; //Ultra Ball - 2x
		case 2: catchrate = catchrate + (catchrate/2); break; //Great Ball - 1.5x
		case 3: catchrate = catchrate * 1; break; //Poké Ball - 1x
		case 4: catchrate = catchrate + (catchrate/2); break; //Safari Ball - 1.5x
		case 5: catchrate = catchrate * 3; break; //Net Ball - 3x if Water/Bug
		case 6: catchrate = catchrate * 4; break; //Dive Ball - 4x if underwater
		case 7: catchrate = catchrate * 1; break; //Nest Ball - (40-(wild Pokemon's level))/10 if level < 30
		case 8: catchrate = catchrate * 3; break; //Repeat Ball - 3x if caught before
		case 9: catchrate = catchrate * 1; break; //Timer Ball - ((No. of turns)+10)/10 top off at 4x
		case 10: catchrate = catchrate * 1; break; //Luxury Ball - 1x
		case 11: catchrate = catchrate * 1; break; //Premier Ball - 1x
	}
	AGBPrintf("catchrate+ = %d\n", catchrate);

	int x1 = ((a*3-b*2)*catchrate)/(a*3);
	int x2 = x1;
	AGBPrintf("X = %d\n",x1);
	if(fighters[1].mon->Status.AilmentSleep)
		x2 = x1 * 2;
	else if(fighters[1].mon->Status.AilmentFrozen)
		x2= x1 * 2;
	else if(fighters[1].mon->Status.AilmentBurned)
		x2 = x1 + (x1/2);
	else if(fighters[1].mon->Status.AilmentParalysis)
		x2 = x1 + (x1/2);
	else if(fighters[1].mon->Status.AilmentPoison)
		x2 = x1 + (x1/2);
	AGBPrintf("X+ = %d\n",x2);
	if(x2 > 255)
		return 0;

	unsigned short y = 0x000FFFF0 / (Sqrt(Sqrt(0x00FF0000 / x2)));
	AGBPrintf("Y = %d\n",y);
	unsigned short shake, toohigh = 0;
	for(x1 = 0; x1 < 4; x1++)
	{
		shake = rand();
		AGBPrintf("Shake %d = %d\n",x1,shake);
		if(shake > y) toohigh++;
	}
	AGBPrintf("Final = %d\n", toohigh);
	return toohigh;
}
int item_PokeBall(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	btlsayf(BT_XUsedX,PlayerName,items[index].name);
	if(ThisBattle.trainer)
	{
		btlsayf(BT_TheTrainerBlockedTheBall);
		btlsayf(BT_DontBeAThief);
		return IR_REDRAW;
	}
	TakeItem(index);

	//animation here

	int i = PokeBall_GetSuccess(param2);
	if(i==0)
	{
		OamBak[1].HPos = 240;
		btlsayf(BT_GotchaXWasCaught,fighters[1].mon->Personal.Nickname);
		if(!GETBIT(MyDex.caught, fighters[1].species))
		{
			FadeOut();
			AGBPrintf("Screen fadeout...\n");
			ClearOamBak();
			AGBPrintf("Clearing OAM...\n");
			scene_BreakBattleScreen();
			Pokedex_RegisterPkmn(fighters[1].species, REG_CAUGHT | REG_SHOWDEX);
			scene_BuildBattleScreen();
			REG_BG0HOFS = 0;
			REG_BG0VOFS = 0;
			scene_BuildPlayerWin();
			scene_BuildOpponentWin();
			if(fighters[0].mon->Status.CurrentHP)
				battle_SendOut(0, fighters[0].pokemonIndex, 0);
			OamBak[2].HPos = 240;
			OamBak[3].HPos = 240;
			OamBak[4].HPos = 240;
			OamBak[5].HPos = 240;
			OamBak[6].HPos = 240;
			OamBak[7].HPos = 240;
			OamBak[8].HPos = 240;
			OamBak[9].HPos = 240;
			REG_WIN0V = ((80-(40*2)) << 8) + (80+(40*2));
			FadeIn();
		}
		aPokemon * mon = 0;
		SetMonsterStats(&HisParty[0], pPokeBall, index);
		int partysize = GetPartySize(MyParty);
		AGBPrintf("partysize: %d\n",partysize);
		if(partysize < 6)
		{
			DmaCopy(&HisParty[0], &MyParty[partysize], sizeof(aPokemon)); //assuming wild monster is always #0...
			mon = &MyParty[partysize];
		}
		else
		{
			//find next free box spot
			int boxno, boxspot;
			extern char boxnames[14][10];

			for(boxno = 0; boxno < 14; boxno++)
			{
				for(boxspot = 0; boxspot < 5*6; boxspot++)
				{
					AGBPrintf("Boxcheck: %d is PV %d.\n",boxspot, MyBox[boxspot + (boxno * 30)].Personal.Personal);
					if(MyBox[boxspot + (boxno * 30)].Personal.Personal == 0)
					{
						//found
						DmaCopy(&HisParty[0], &MyBox[boxspot + (boxno * 30)], sizeof(aBoxedMon));
						btlsayf(BT_XWasTransferredToSomeonesPCItWasPlacedInBoxX, HisParty[0].Personal.Nickname, boxnames[boxno]);
						mon = (aPokemon*)&MyBox[boxspot + (boxno * 30)];
						goto BoxPlaced;
					}
				}
			}
		}
BoxPlaced:

		//nicknaming here
		btlsayf(BT_GiveANicknameToTheCapturedX, mon->Personal.Nickname);
		if(!btlMultipleChoice(21,8,8, 0,0))
		{
			char newnick[10] = { 0,0,0,0,0,0,0,0,0,0 };
			scene_BreakBattleScreen();
			EnterName((char*)newnick, 10, "Enter nickname", 0);
			if(newnick[0]) //anything entered?
				strcpy(mon->Personal.Nickname,newnick);
		}
		ThisBattle.decision = 4;
	}
	else
	{
		while(i--)
			btlsays("…");
		btlsayf(BT_OhNoThePokemonBrokeFree);
	}
	return IR_REDRAW;
}

int item_Heal(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	int pk = ShowParty(psmSelectOnly, 0);
	if(pk != -1)
	{
		if(special2) //Potion-likes
		{
			int amount = clamp(	MyParty[pk].Status.CurrentHP + special2, 0,
								MyParty[pk].Status.TotalHP - MyParty[pk].Status.CurrentHP+1);
			int oldAmount = amount;
			if(amount == 0)
			{
				sayf(SYSTEM, strItemHasNoEffect);
				return IR_FADE;
			}
			FadeOut();
			ItemUseAnimation(index, &MyParty[pk]);
			DrawPartyScreen(pk, psmGeneral, 0);
			FadeIn();
			while(amount)
			{
				MyParty[pk].Status.CurrentHP++;
				amount--;
				DrawPartyScreen(pk, psmSelectOnly, 1);
				DoVBlank();
			}
			sayf(SYSTEM, strHPRestored, MyParty[pk].Personal.Nickname, oldAmount, plural(strHPRestoredPoints, oldAmount));
		}
		TakeItem(index);
	}
	return IR_FADE;
}

int item_BtlHeal(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	int pk = ShowParty(psmSelectOnly, 0);
	if(pk != -1)
	{
		if(special2) //Potion-likes
		{
			int amount = clamp(MyParty[pk].Status.CurrentHP + special2, 0,
												 MyParty[pk].Status.TotalHP - MyParty[pk].Status.CurrentHP + 1);
			int oldAmount = amount;
			if(amount == 0)
			{
				sayf(SYSTEM, strItemHasNoEffect);
				return IR_FADE;
			}
			while(amount)
			{
				MyParty[pk].Status.CurrentHP++;
				amount--;
				DrawPartyScreen(pk, psmSelectOnly, 1);
				DoVBlank();
			}
			sayf(SYSTEM, strHPRestored, MyParty[pk].Personal.Nickname, oldAmount, plural(strHPRestoredPoints, oldAmount));
		}
		TakeItem(index);
	}
	return IR_REDRAW;
}

int item_PPUp(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	//TODO	Replace this screen with a simple MultipleChoice imitation in the Party Screen:
	//FadeOut, ShowParty, select move in same screen, fade out, show animation with message, fade out,
	//fade back in to party screen, show final message "MOVE's PP increased.", fade out,
	//back to inventory. If a move has all three PP Up bonuses, say "It won't have any effect" in the party screen.
	//Note: the animation can be cancelled with B until the message starts.
	//Easier version? Leave out the animation and second message.
	FadeOut();
	int pk = ShowParty(psmSelectOnly, 0);
	FadeOut();
	if(pk != -1)
	{
		int m = SelectLearnMove(&MyParty[pk],-1);
		if(m < 4)
		{
			int shift = m * 2;
			unsigned int bonus = (GetMonsterStats(&MyParty[pk], pPPBonus) >> shift) & 3;
			if(bonus < 3)
			{
				TakeItem(index);
				int poop = GetMonsterStats(&MyParty[pk], pPPBonus);
				poop += 1 << shift;
				SetMonsterStats(&MyParty[pk], pPPBonus, poop);
				FadeIn();
				ItemUseAnimation(index, &MyParty[pk]);
				DrawPartyScreen(pk, psmGeneral, 0);
				FadeIn();
				sayf(SYSTEM,strPPIncreased,moveNames[GetMonsterStats(&MyParty[pk], pMove1 + m)]);
				FadeOut();
			} else
			{
				FadeIn();
				sayf(SYSTEM,strItemHasNoEffect);
				FadeOut();
			}
		}
	}
	return IR_FADE;
}

int item_Candy(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	FadeOut();
	int pk = ShowParty(psmSelectOnly, 0);
	FadeOut();
	if(pk != -1)
	{
		TakeItem(index);
		ItemUseAnimation(index, &MyParty[pk]);
		DrawPartyScreen(pk, psmGeneral, 0);
		FadeIn();
		aBaseStat *myBase = (aBaseStat*)&BaseStats[GetMonsterStats(&MyParty[pk], pSpecies)];
		int curlevel = GetMonsterStats(&MyParty[pk], pLevel);
		int newlevel = curlevel + 1;
		int diff = XPRequirements[(myBase->LevelSlope*101)+newlevel] - XPRequirements[(myBase->LevelSlope*101)+curlevel];

		InjectXP(&MyParty[pk], diff);
		UpdateLiveStats(&MyParty[pk]);
		DrawPartyScreen(pk, psmSelectOnly, 0);
		sayf(SYSTEM,strLevelElevated, MyParty[pk].Personal.Nickname, GetMonsterStats(&MyParty[pk], pLevel));

		//Check for moves
		const aLearnedMove* moveset = GetRef_PokemonMoveset( GetMonsterStats(&MyParty[pk], pSpecies) );
		int l;
		for(l = 0; l < 100; l++)
		{
			if(moveset[l].Move == 0x1FF) break;
			//sayf(SYSTEM, "Moveset check.\n%s @ %d?", moveNames[moveset[l].Move], moveset[l].Level);
			if((moveset[l].Level <= newlevel) && (moveset[l].Level > curlevel))
			{
				FadeOut();
				int slot = SelectLearnMove(&MyParty[pk],moveset[l].Move);
				DrawPartyScreen(pk, psmGeneral, 0);
				FadeIn();
				if(slot < 4)
				{
					AGBPrintf("Teaching move %d...\n");
					LearnMove(&MyParty[pk], moveset[l].Move, slot);
				}
			} else if(moveset[l].Level > newlevel)
			{
				//break;
			}
		}

		int evoTarget = CheckEvolution(&MyParty[pk], 0, 0);
		if(evoTarget)
		{
			//Check!
			////TODO	Cutscene here
			//sayf(SYSTEM, "%s is about to evolve into\n%s. Okay?\1", MyParty[pk].Personal.Nickname, PokeNames[evoTarget]);
			//if(!SimpleYesNoLoop())
			if(EvolutionCutscene(&MyParty[pk], evoTarget))
			{
				DrawPartyScreen(pk, psmGeneral, 0);
				int oldspecies = GetMonsterStats(&MyParty[pk], pSpecies);
				int newspecies = evoTarget;
				//if(!strcmp(MyParty[pk].Personal.Nickname, PokeNames[oldspecies]))
				if (GetMonsterStats(&MyParty[pk], pNicknamed) == 0)
					SetNickname(&MyParty[pk], (char*)PokeNames[newspecies], 0);

				SetMonsterStats(&MyParty[pk], pSpecies, newspecies);
				int OldMax = GetMonsterStats(&MyParty[pk], pTotalHP); //myS->TotalHP;
				UpdateLiveStats(&MyParty[pk]);
				int doop = GetMonsterStats(&MyParty[pk], pCurrentHP) * GetMonsterStats(&MyParty[pk], pTotalHP) / OldMax;
				SetMonsterStats(&MyParty[pk], pCurrentHP, doop);

				DrawPartyScreen(pk, psmSelectOnly, 0);
				sndPlayCry(newspecies, 60);

				extern const u8 MonIconColors[254];
				extern const unsigned short * const PartyPics[];
				DmaCopy(PartyPics[newspecies], MEM_VRAM_OBJ + (pk*0x400),1024);
				OamBak[pk].Pltt = MonIconColors[newspecies];
				//sayf(SYSTEM, strBattleEvolved, PokeNames[oldspecies],PokeNames[newspecies]);
			}
		}

		FadeOut();
	}
	return IR_FADE;
}

int item_EvStone(u16 index, u16 special1, u16 special2, u32 param1, u32 param2)
{
	//Party screen should show "No use." instead of a health bar.
	FadeOut();
	int pk = ShowParty(psmSelectOnly, 0);
	if(pk != -1)
	{
		int species = GetMonsterStats(&MyParty[pk], pSpecies);
		int evoTarget = CheckEvolution(&MyParty[pk], 2, index);
		if(evoTarget)
		{
			FadeOut();
			TakeItem(index);
			ItemUseAnimation(index, &MyParty[pk]);

			int newspecies = evoTarget;
			//Do evolution cutscene here.
			if (GetMonsterStats(&MyParty[pk], pNicknamed) == 0)
				SetNickname(&MyParty[pk], (char*)PokeNames[newspecies], 0);

			SetMonsterStats(&MyParty[pk], pSpecies, newspecies);
			int OldMax = GetMonsterStats(&MyParty[pk], pTotalHP); //myS->TotalHP;
			UpdateLiveStats(&MyParty[pk]);
			int doop = GetMonsterStats(&MyParty[pk], pCurrentHP) * GetMonsterStats(&MyParty[pk], pTotalHP) / OldMax;
			SetMonsterStats(&MyParty[pk], pCurrentHP, doop);
			DrawPartyScreen(pk, psmGeneral, 0);
			FadeIn();
			sayf(SYSTEM,strLevelEvolved, PokeNames[species], PokeNames[newspecies]);

			return IR_FADE;
		}
		//If we're here, it wasn't in the list.
		sayf(SYSTEM, strNoEffect);
	}
	return IR_FADE;
}

int item_BtlEnigma(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol enigmaberry"); return 0; }
int item_BtlEther(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol ether"); return 0; }
int item_BtlFlute(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol recorder"); return 0; }
int item_BerryPouch(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol michael moore"); return 0; }
int item_BlockCase(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol pezdispenser"); return 0; }
int item_CoinCase(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol case closed"); return 0; }
int item_Decoy(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol mccoy"); return 0; }
int item_Enigma(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol nigma"); return 0; }
int item_Escape(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol enter"); return 0; }
int item_Ether(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol aethir"); return 0; }
int item_FishRod(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol how i mine for fish"); return 0; }
int item_Flute(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol fl00t"); return 0; }
int item_ItemFinder(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol 404 itemfinder not found"); return 0; }
int item_Mail(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol u got mail"); return 0; }

int item_Repel(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol body odor"); return 0; }
int item_SacrAsh(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol secret ketchum"); return 0; }
int item_StatMod(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol status mod"); return 0; }
int item_TMCase(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol tmcase"); return 0; }
int item_Water(u16 index, u16 special1, u16 special2, u32 param1, u32 param2) { sayf(SYSTEM,"lol wut"); return 0; }
