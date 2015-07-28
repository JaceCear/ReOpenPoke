//======================================================================
//
//	OpenPoké shopping system
//
//	(comments, kudos, flames to "foo@helmetedrodent.kickassgamers.com")
//
//======================================================================
#include "openpoke.h"

extern void RepairMap();

extern const CSTRING strShopSellHowMany;
extern const CSTRING strShopSellICanPayX;
extern const CSTRING strShopIcantBuyThat;

extern const unsigned long* itemicons[];
extern const unsigned short shopPal[16];
extern const unsigned short shopTiles[528];
extern const unsigned short shopMap[640];

// Draws the names and prices of the sold shop items onto the screen
void Store_WriteList(u16* offeredItems, int scrolloffset, int cursor)
{
	#define DISPLAYED_ITEMS_AT_ONCE 6 // do not change!
	int idx,i=0;
	char blub[32];

	vwBlackTransparentLUT();
	for(idx = 0; idx < DISPLAYED_ITEMS_AT_ONCE; idx++)
	{
		// Draw any item but the Cancel option
		if(offeredItems[idx+scrolloffset])
		{
			// Item is not affordable
			if(items[offeredItems[idx+scrolloffset]].price > MyPlayer.cash)
			{
				// color item name grey
				vwf_set_color(TEXT_INK, 3);
				vwf_set_color(TEXT_SHADOW, 1);
			}
			// Item is affordable
			else
			{
				// color item name black
				vwf_set_color(TEXT_INK, 2);
				vwf_set_color(TEXT_SHADOW, 3);
			}
			// Clear old item name
			vwWrite(128+8,(idx+3)*16,"                            ");

			// Write new item name
			vwWrite(128+8,(idx+3)*16,items[offeredItems[idx+scrolloffset]].name);

			// Write item's price
			vw_SetSmall();
			sprintf(blub,"$%4d ", items[offeredItems[idx+scrolloffset]].price);
			vwWrite(224,(idx+3)*16,(char*)blub);
			vw_SetBig();
		}
		// Draw Cancel-Button
		else
		{
			// textcolor = black
			vwf_set_color(TEXT_INK, 2);
			vwf_set_color(TEXT_SHADOW, 3);

			// clean the line from old
			// item name and price
			vwWrite(128+8,(idx+3)*16,"                                       ");

			if(i==0)
			{
				vwWrite(128+8,(idx+3)*16,strShopBack);
				i++;
			}
		}
	}
	#undef DISPLAYED_ITEMS_AT_ONCE
}

void Store_ShowItem(int index)
{
	/*icon_width * icon_height * sizeof(color) =
			24	*		24		*		2		*/
	int itempicbuf[0x120];

	CpuFastClear(0, vwDestination, 0x1800);

	// Draw item description to screen
	vwWhiteTransparentLUT();
	if(index==0)
		vwWrite(0,3,strShopBack);
	else
		vwWrite(0,3,(char*)items[index].description);
	vwBlackTransparentLUT();

	// Copy OBJ palette
	DmaCopy(itemicons[(index*2)+1], MEM_PAL_OBJ + 0xA0, 32);

	LZ77UnCompWram((u8*)itemicons[index*2], itempicbuf);
	DmaCopy(itempicbuf, MEM_VRAM_OBJ+0x6000, 0x60);
	DmaCopy(itempicbuf + 0x18, MEM_VRAM_OBJ+0x6000 + 0x80, 0x60);
	DmaCopy(itempicbuf + 0x30, MEM_VRAM_OBJ+0x6000 + 0x100, 0x60);
}

void Store_DrawBackdrop()
{
	//TODO: Detect player's orientation and draw accordingly

	extern u8	gMapOfsX, gMapOfsY;
	int ix, iy;
	DmaClear(0, MEM_VRAM+0xE000, 0x1800);

	gMapOfsX = 0;
	gMapOfsY = 0;
	for(iy=1; iy<7; iy++)
		for(ix=0; ix<5; ix++)
			mapDrawMeta(ix, iy, mhGetMetaTile(currentMapHeader, ix, iy));

	CpuFastCopy(Sprites[Actors[0].sprite].spriteStart + 0x80, (u16*)MEM_VRAM_OBJ, 0x100);
	CpuFastCopy(Sprites[Actors[1].sprite].spriteStart, (u16*)MEM_VRAM_OBJ+0x100, 0x100);
	OamBak[0].HPos = 32;
	OamBak[0].VPos = 64;
	OamBak[1].HPos = 32;
	OamBak[1].VPos = 32;


	DmaArrayCopy(shopTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(shopPal, MEM_PAL_BG + 0x01A0);

	for(ix=0; ix<640; )
	{
		if(shopMap[++ix]) //skip null tiles
			BG1MAP[ix-1] = shopMap[ix] | 0xD000;
	}
}

void Store_DrawUI(int cursor)
{
	int i;
	char buffy[32];

	CleanUpBG0();
	REG_BG0HOFS= 0;	REG_BG0VOFS= 0;
	REG_BG1HOFS= 0;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;

	vwBlackTransparentLUT();
	for(i=0; i<6; i++)
		vwSetLine(12,16,(i<<1)+1,304+(64*i),15);
	vwWrite(128,(cursor+3)*16,strArrow);
	vwSetLine(5,24,14,96,15);
	vwSetLine(5,24,16,160,15);
	vwSetLine(5,24,18,224,15);
	vwWrite(4,102,strShopMoney);
	sprintf(buffy,"$%4d ",MyPlayer.cash);
	vw_SetSmall();
	vwWrite(32,116,buffy);
	vw_SetBig();
	vwSetLine(1,8,1,512,15);
	vwSetLine(1,8,2,544,15);

	OamBak[120].CharNo = 768;
	OamBak[120].Pltt = 5;
	OamBak[120].HPos = 8;
	OamBak[120].VPos = 124;
	OamBak[120].Shape = 0;
	OamBak[120].Size = 2;
	OamBak[120].Priority = 0;
}

/* Writes the amount and price of an item to the screen that:
	a) is bought;
		offeredItems != 0 (points to the sold items)
		wantedct > 0
		value = cursor
	b) is sold
		offeredItems == 0
		wantedct < 0
		value = price
	Those were 2 functions earlier but to save space
	they were merged together */
void Store_WriteRelevantCt(u16* offeredItems, int wantedct, int value)
{
	char buffy[32];

	if(wantedct < 0)
		wantedct = wantedct * -1;

	vwClearLine(1,36);

	vw_SetSmall();
	sprintf(buffy, "%2d", wantedct);
	vwWrite(4,145,buffy);

	// Write amount of items
	sprintf(buffy,
			"%d$",
			(offeredItems[0] == 0) ?
				wantedct * value
			:	items[offeredItems[value]].price * wantedct);

	vwWrite(62,145,buffy);
	vw_SetBig();
}

void Store_Buy(u16* offeredItems)
{
	int cursor = 0;
	int scrolloffset = 0;
	u16 wantedct;

	u16 i = 0;

	vwClear(0);

	//We impose a 128 item limit here to minimize damage from unterminated inventories.
	AGBPrintf("DoStore: determining inventory size...\n");
	while(offeredItems[i] && i < 128)
		i++;

	AGBPrintf("DoStore: inventory size determined: %d\n", i);

	Store_WriteList(offeredItems, scrolloffset, cursor);
	Store_ShowItem(offeredItems[scrolloffset+cursor]);
	Store_DrawUI(cursor);
	Store_DrawBackdrop();

	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

	// Quit the "Buy-Screen"
		if(Trg & B_BUTTON)
			break;

		// Draw the amount-counter
		if(Trg & A_BUTTON)
		{
			// exit
			if(offeredItems[scrolloffset+cursor] == 0)
				break;

			OamBak[120].Priority = 3;
			if(items[offeredItems[cursor+scrolloffset]].price > MyPlayer.cash)
			{	// "You don't have enough money!"
				sayf(SPEECH, strShopNotEnoughMoney);
			}
			// open up box to determine
			// how many items to buy
			else
			{
				sayf(SPEECH,strShopCertainly, items[offeredItems[cursor+scrolloffset]].name);

				wantedct = 1;
				DrawFrame(16, 14, 10, 4);
				Store_WriteRelevantCt(offeredItems, wantedct,cursor+scrolloffset);
				vwSetLine(17,12,11,672,15);
				i = 1;
				while(1)
				{
					DoVBlank();
					KeyRead();
					Store_WriteRelevantCt(offeredItems, wantedct,cursor+scrolloffset);
					if(Trg & B_BUTTON)
					{
						wantedct = 0;
						break;
					}
					if(Trg & A_BUTTON)
						break;
					if(Trg & U_KEY)
					{
						if(items[offeredItems[cursor+scrolloffset]].price * (wantedct + 1) > MyPlayer.cash)
						{
							wantedct = 1;
						}
						else
						{
							wantedct++;
						}
					}
					if(Trg & D_KEY)
					{
						if(wantedct == 1)
						{
						while( (items[offeredItems[cursor+scrolloffset]].price * ++wantedct) <= MyPlayer.cash)
							{ ;}
							wantedct--;
						}
						else
						{
							wantedct--;
						}
					}
										if(Trg & L_KEY)
					{
						if( (wantedct - 10) > 0 )
						{
							wantedct -= 10;
						}
						else
						{
							wantedct = 1;
						}
					}
					if(Trg & R_KEY)
					{
						while( (items[offeredItems[cursor+scrolloffset]].price * ++i) <= MyPlayer.cash)
							{ ;}
						i--;

						if( (wantedct + 10) > i )
							wantedct = i;
						else
						{
							wantedct += 10;
						}
					}
				}

				if(wantedct)
				{
					Store_DrawUI(cursor);
					OamBak[120].Priority = 3;

					sayf(SPEECH,strShopConfirm, wantedct, items[offeredItems[cursor+scrolloffset]].name, items[offeredItems[cursor+scrolloffset]].price * wantedct);
					if(!SimpleYesNoLoop())
					{
						MyPlayer.cash -= items[offeredItems[cursor+scrolloffset]].price * wantedct;
						while(wantedct--)
							GiveItem(offeredItems[cursor+scrolloffset]);
						sayf(SPEECH,strShopThankYou);
					}
				}
			}
			Store_DrawUI(cursor);
			Store_DrawBackdrop();
			Store_WriteList(offeredItems, scrolloffset, cursor);
			Store_ShowItem(offeredItems[scrolloffset+cursor]);
		}

		if(Trg & U_KEY)
		{
			vwWrite(128,(cursor+3)*16,strArrowBlank);
			if(cursor==0)
			{
				if(scrolloffset > 0) scrolloffset--;
				Store_WriteList(offeredItems, scrolloffset, cursor);
			} else
			{
				cursor--;
			}
			Store_ShowItem(offeredItems[scrolloffset+cursor]);
			vwWrite(128,(cursor+3)*16,strArrow);
		}
		else if((Trg & D_KEY) && (offeredItems[scrolloffset+cursor])) //can't pass Cancel.
		{
			vwWrite(128,(cursor+3)*16,strArrowBlank);
			if(cursor==5)
			{
				if(scrolloffset < 40) scrolloffset++;
				Store_WriteList(offeredItems, scrolloffset, cursor);
			} else
			{
				cursor++;
			}
			Store_ShowItem(offeredItems[scrolloffset+cursor]);
			vwWrite(128,(cursor+3)*16,strArrow);
		}
	}
}



extern anInventoryItem inventory[200] INEWRAM;

extern const unsigned short inventoryPal[16];
extern const unsigned short inventoryTiles[1056];
extern const unsigned short inventoryMap[640];

extern const unsigned long* itemicons[];

extern const unsigned short maleBagTiles[4096];
extern const unsigned short maleBagPal[16];


extern const anInventoryPage InventoryPages[6];

extern void Inventory_ShowItem(int index);
extern void Inventory_WriteList(int pageoffset, int scrolloffset, int cursor);
extern int Inventory_MultipleChoice(int left, int top, int width, int choices, int bcancel); //CHOICELIST choices);

void Store_Sell()
{
	u16 cleanItemList[1] = {0};
	int idx, page = 0;
	int cursor = 0;
	int scrolloffset = 0;
	int red=0;
	int thisitem, wantedct;
	char monies[32];

Redraw:
	if(red==0) REG_DISPCNT = 0;
		CleanUpCrap();
	ClearOamBak();
	DmaArrayCopy(inventoryTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(inventoryPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(inventoryMap, MEM_VRAM + 0xE800);
	LoadFrame();

	Inventory_WriteList(InventoryPages[page].offset, scrolloffset, cursor);
	Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
	for(idx=0; idx<6; idx++)
		vwSetLine(11,18,(idx<<1)+1,224+(64*idx),15);
	vwWrite(6,(cursor+2)*16,strArrow);

	vwWhiteTransparentLUT();
	//vwWrite(132,32,(char*)InventoryPages[page].name2);
	sprintf(monies,"$%4d",MyPlayer.cash);
	vwWrite(148,32,monies);
	vwSetLine(1,10,1,242,15);

	DmaArrayCopy(maleBagTiles, MEM_VRAM_OBJ + 0x0800);
	DmaArrayCopy(maleBagPal, MEM_PAL_OBJ + 0x0020);

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

	if(red==0)
	{
		ResetDispCnt();
		FadeIn();
	}
	red = 1;

	// Item selection
		// TODO: Add support for
		// Key-Item and PokéBall bags
	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & A_BUTTON)
		{
			thisitem = InventoryPages[page].offset + scrolloffset + cursor;

			if(inventory[thisitem].itemidx == 0)
				break; //cancel

			vwNormalLUT();
			OamBak[0].Priority = 3;
			if(items[inventory[thisitem].itemidx].price)
			{
				if(inventory[thisitem].itemcnt > 1)
				{
					sayf(SPEECH, strShopSellHowMany, items[inventory[thisitem].itemidx].name);
					wantedct = 1;
					DrawFrame(16, 14, 10, 4); // Draw item counter onto screen
					Store_WriteRelevantCt(cleanItemList, wantedct * -1, items[inventory[thisitem].itemidx].price / 2);
					vwSetLine(17,12,11,672,15);

					// Choose how many items
					// you want to sell
					while(1)
					{
						DoVBlank();
						KeyRead();
						// Quit sell-screen
						if(Trg & B_BUTTON)
						{
							wantedct = 0;
							break;
						}
						if(Trg & A_BUTTON)
							break;
						if(Trg & U_KEY)
						{
							if(++wantedct > inventory[thisitem].itemcnt)
							{
								wantedct = 1;
							}
							
						}
						if(Trg & D_KEY)
						{
							if(wantedct == 1)
							{
								wantedct = inventory[thisitem].itemcnt;
							}
							else
							{
								wantedct--;
							}
						}
						if(Trg & L_KEY)
						{
							if( (wantedct -= 10) <= 0 )
							{
								wantedct = 1;
							}
						}
						if(Trg & R_KEY)
						{
							if((wantedct += 10) > inventory[thisitem].itemcnt)
							{
								wantedct = inventory[thisitem].itemcnt;
							}
						}
					Store_WriteRelevantCt(cleanItemList, wantedct * -1, items[inventory[thisitem].itemidx].price / 2);
					}
					ClearFrame(16, 14, 10, 4); // Wipe item counter from screen
				}
				else
				{
					wantedct=1;
				}
				if(wantedct)
				{
					sayf(SPEECH,strShopSellICanPayX, (items[inventory[thisitem].itemidx].price / 2) * wantedct);
					if(!Inventory_MultipleChoice(21,8,8, 0,1)) //Choice_YesNo))
					{
						MyPlayer.cash += (items[inventory[thisitem].itemidx].price / 2) * wantedct;
						while(wantedct--)
							TakeItem(inventory[cursor+scrolloffset].itemidx);
						sayf(SPEECH,strShopThankYou);
					}
				}
			}
			else
			{
				sayf(SPEECH, strShopIcantBuyThat, items[inventory[thisitem].itemidx].name);
			}
			goto Redraw;
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
				Inventory_WriteList(InventoryPages[page].offset, scrolloffset, cursor);
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
				Inventory_WriteList(InventoryPages[page].offset, scrolloffset, cursor);
			}
			else
			{
				cursor++;
			}
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
		}
		else if((Trg & L_KEY) && (page>0))
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			--page;
			scrolloffset = 0;
			cursor = 0;
			OamBak[1].CharNo = 64 + (page*64);
			Inventory_WriteList(InventoryPages[page].offset, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			//vwWhiteTransparentLUT();
			//vwWrite(132,32,(char*)InventoryPages[page].name2);
		}
		else if((Trg & R_KEY) && (page < 2)) //set to 4 to allow TMs and Berries without case/pouch
		{
			vwWrite(6,(cursor+2)*16,strArrowBlank);
			++page;
			scrolloffset = 0;
			cursor = 0;
			OamBak[1].CharNo = 64 + (page*64);
			Inventory_WriteList(InventoryPages[page].offset, scrolloffset, cursor);
			Inventory_ShowItem(inventory[InventoryPages[page].offset+scrolloffset+cursor].itemidx);
			vwWrite(6,(cursor+2)*16,strArrow);
			//vwWhiteTransparentLUT();
			//vwWrite(132,32,(char*)InventoryPages[page].name2);
		}
	}
	FadeOut();
	vwNormalLUT();
	ClearOamBak();
	CleanUpCrap();
	return;
}

// Handles the store interaction
void DoStore(u16 * offeredItems)
{
	// Greet the player
	sayf(SPEECH,strShopHiThere);

	// Open up the shop multipleChoiceBox
	// until the player leaves
	while(1)
	{
		switch(MultipleChoice(1,0,14,6,1)) //Choice_BuySellSeeYa))
		{
			case 0:		// Buy
				FadeOut();
				Store_Buy(offeredItems);
				break;
			case 1:		// Sell
				FadeOut();
				Store_Sell();
				break;
			default:	// Good bye
				sayf(SPEECH,strShopComeAgain);
				return;
		}
		FadeOut();
		RepairMap();
		
		sayf(SPEECH,strShopAnythingElse);
	}
}

