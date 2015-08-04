/**	\file pokedex.c
		\brief Handles the Pokedex
		\author Kawa
*/
#include "..\openpoke.h"

extern const unsigned short dexlistPal[16];
extern const unsigned short dexlistTiles[4096];
extern const unsigned short dexlistMap[640];

extern const unsigned short dexinfo1Pal[16];
extern const unsigned short dexinfo1Tiles[3360];
extern const unsigned short dexinfo1Map[2048];
extern const void *PokeDexes[];

extern const unsigned short dexfilterPal[16];
extern const unsigned short dexfilterTiles[1584];
extern const unsigned short dexfilterMap[640];

short FilteredDex[513];

void PokeDex_ShowData(int idx, int page, int flavorpage);
void PokeDex_WriteList(int scrolloffset, int cursor);
void PokeDex_SetMonTiles(int offset, int start, int pal);
void PokeDex_LoadType(int type, int slot);

//typedef struct _DexInfo
//{
//	u16 lastchoice;
//	u16 *dex;
//} _DexInfo;
//_DexInfo myDex;
short DexLastChoice;
short * DexList;

extern const unsigned short * const TrainerPics[];
extern const u8 CardPics[];
extern const unsigned short * const PokePrints[];

void PrepareDex()
{
	DexList = (void*)PokeDexes[0];
	AGBPrint("PrepareDex: Pokédex reset to National mode.\n");
}

/** \brief Displays the Pokedex entry for the given species.

		Assumes it's at least seen, and allows switching to the other page and browsing to the other seen species.
*/
void ShowDexEntry(int index)
{
	BUP buh;
	int blendnow = 0, blendi = 0, page = 0, flavorpage = 0;
	int upidx, dnidx;
	int dexnum = GetDexNumber(index);

	AGBPrintf("ShowDexEntry: showing species #%d...\n", index);

	ClearOamBak();
	CleanUpCrap();

	REG_BG1CNT |= BG_SIZE1;

	DmaArrayCopy(dexinfo1Tiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(dexinfo1Pal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(dexinfo1Map, MEM_VRAM + 0xE800);

	*(u16*)0x05000016 = dexinfo1Pal[3];
	DmaClear(0x318C318C, MEM_PAL_OBJ + 0xE0, 32);
	*(u16*)0x050002E0 = 0x7FFF;

	buh.src_len = 32;
	buh.src_bpp = 1;
	buh.dst_bpp = 4;
	buh.dst_ofs = 0;

	OamBak[1].HPos = 208;
	OamBak[1].VPos = 16;
	OamBak[1].Size = 1;
	OamBak[1].CharNo = 64;
	OamBak[1].Pltt = 1;

	OamBak[2].HPos = 208;
	OamBak[2].VPos = 48;
	OamBak[2].Size = 1;
	OamBak[2].CharNo = 128;
	OamBak[2].Pltt = 4;
	OamBak[3].HPos = 208;
	OamBak[3].VPos = 32;
	OamBak[3].Size = 1;
	OamBak[3].CharNo = 132;
	OamBak[3].Pltt = 5;
	*(u16*)(MEM_PAL+0x222) = 0x318C;

	OamBak[4].Pltt = 7;
	OamBak[4].CharNo = 0;
	OamBak[4].Size = 3;
	OamBak[4].HPos = -80;
	OamBak[4].VPos = 8;
	OamBak[4].AffineMode = 1;
	OamBak[4].AffineParamNo_L = 1;
	OamBak[5].Pltt = 7;
	OamBak[5].CharNo = 160;
	OamBak[5].Size = 3;
	OamBak[5].HPos = -80;
	OamBak[5].VPos = 8;
	OamBak[5].AffineMode = 1;
	OamBak[5].AffineParamNo_L = 2;


	//PokeDex_SetMonTiles(0x21,512,14);
	SetupPokemonSprite(0);
	OamBak[0].HPos = 8;
	OamBak[0].VPos = 8;
	OamBak[0].HFlip = 1;

	REG_BG1HOFS= 8;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;

	vwSetLine(11,20,2,96,15);
	vwSetLine(11,20,4,160,15);
	vwSetLine(11,20,6,224,15);
	vwSetLine(1,30,11,288,15);
	vwSetLine(1,30,13,352,15);
	vwSetLine(1,30,15,416,15);

	//DmaCopy((u8*)TrainerPics[CardPics[MyPlayer.gender]<<1], MEM_VRAM_OBJ + 0x1400, 0x800);
	if(MyPlayer.gender)
		LZ77UnCompVram((u8*)TrainerPics[tpDani<<1], (u16*)MEM_VRAM_OBJ + 0xA00);
	else
		LZ77UnCompVram((u8*)TrainerPics[tpDanny<<1], (u16*)MEM_VRAM_OBJ + 0xA00);

	vwBlackTransparentLUT();

RedrawMonData:
	if(GETBIT(MyDex.caught,index))
		AGBPrint("Seen this one.\n");

	//if(DexEntries[DexList[index]].text2) flavorpage++;
//	if(*DexEntries[DexList[index]].text2 == 0)
//	{
//		for(i=0; i<+6; i++)
//		{
//			BG1MAP[i+0x24D] = 72;
//			BG1MAP[i+0x26D] = 90;
//		}
//	}
	vwSetLine(0,20,18, 608, 15);
	PokeDex_ShowData(index,page,flavorpage);

	LoadPokemonPic(index,0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
	AGBPrintf("Print at 0x%x.\n",PokePrints[index]);
	BitUnPack((void*)PokePrints[index], (void*)MEM_VRAM_OBJ + 0x800, &buh);

	PokeDex_LoadType(BaseStats[index].Type1, 0);
	if(BaseStats[index].Type2 != BaseStats[index].Type1)
		PokeDex_LoadType(BaseStats[index].Type2, 1);
	else
		PokeDex_LoadType(tpNormal, 1);

	OamBak[4].AffineParam = 0x14+ DexEntries[dexnum].mscale;
	OamBak[5].AffineParam = 0x0;
	OamBak[6].AffineParam = 0x0;
	OamBak[7].AffineParam = 0x14+DexEntries[dexnum].mscale;
	OamBak[8].AffineParam = 0x14+DexEntries[dexnum].tscale;
	OamBak[9].AffineParam = 0x0;
	OamBak[10].AffineParam = 0x0;
	OamBak[11].AffineParam = 0x28+DexEntries[dexnum].tscale;
	OamBak[4].VPos = 8 + DexEntries[dexnum].toffset;
	OamBak[5].VPos = 4 + 32 - (32*0x10000/(DexEntries[dexnum].tscale+0x14)>>8);

	if(blendnow==1)
	{
		REG_BLDCNT = BLD_BOT(BLD_BG1) | BLD_STD | BLD_OBJ | BLD_BG0;
		for(blendi = 0; blendi < 0x11; blendi += DEXFADESPEED)
		{
			REG_BLDALPHA = ((0x10 - blendi) << 8) + blendi;
			DoVBlank();
		}
	} else
	{
		FadeIn();
	}

//	upidx = index-1;
//	if(upidx == 0) upidx = DexList[0]-1;
//	dnidx = index+1;
//	if(dnidx == DexList[0]) dnidx = 1;
	AGBPrintf("Neighbor scan: dexnum %d, dexlist[0] %d.\n", dexnum, DexList[0]);
	upidx = wrap(dexnum-1, 1, DexList[0]+1);
	AGBPrintf("Upscan: checking dexnum %d...\n", upidx);
	while(!GETBIT(MyDex.seen, DexList[upidx]))
		upidx = wrap(upidx-1, 1, DexList[0]+1);
	AGBPrintf("Upscan: ended up with dexentry %d, index %d.\n", upidx, DexList[upidx]);
	dnidx = wrap(dexnum+1, 1, DexList[0]+1);
	AGBPrintf("Downscan: checking dexnum %d...\n", dnidx);
	while(!GETBIT(MyDex.seen, DexList[dnidx]))
		dnidx = wrap(dnidx+1, 1, DexList[0]+1);
	AGBPrintf("Downscan: ended up with dexentry %d, index %d.\n", dnidx, DexList[dnidx]);

	sndPlayCry(index,60);

	while(1)
	{
		DoVBlank();
		KeyRead();
		if(Trg & A_BUTTON) sndPlayCry(index,60);
		if(Cont & U_KEY)
		{
			index = DexList[upidx];
			dexnum = GetDexNumber(index);
			blendnow = 1;
			goto FadeMon;
		}
		if(Cont & D_KEY)
		{
			index = DexList[dnidx];
			dexnum = GetDexNumber(index);
			blendnow = 1;
			goto FadeMon;
		}
		if(Trg & B_BUTTON)
		{
			FadeOut();
			vwNormalLUT();
			ClearOamBak();
			REG_DISPCNT |= DCNT_BG0;
			REG_BG1HOFS = 8;
			return;
		}
		if((Trg & R_KEY) && (page == 0))
		{
			OamBak[0].HPos = -80;
			OamBak[1].HPos = -80;
			OamBak[2].HPos = -80;
			OamBak[3].HPos = -80;
			REG_DISPCNT &= ~DCNT_BG0;
			for(blendi = 1; blendi < 9; blendi++)
			{
				DoVBlank();
				REG_BG1HOFS = 8 + (blendi*32);
			}
			PokeDex_ShowData(index,1,flavorpage);
			REG_DISPCNT |= DCNT_BG0;
			OamBak[4].HPos = 136;
			OamBak[5].HPos = 176;
			page = 1;
		}
		if((Trg & L_KEY) && (page == 1))
		{
			OamBak[4].HPos = -80;
			OamBak[5].HPos = -80;
			REG_DISPCNT &= ~DCNT_BG0;
			for(blendi = 8; blendi > 0; blendi--)
			{
				DoVBlank();
				REG_BG1HOFS = 8 + ((blendi-1)*32);
			}
			OamBak[0].HPos = 8;
			OamBak[1].HPos = 208;
			OamBak[2].HPos = 208;
			OamBak[3].HPos = 208;
			PokeDex_ShowData(index, 0, flavorpage);
			REG_DISPCNT |= DCNT_BG0;
			page = 0;
		}
		if(Trg & KEY_SELECT && page == 0 && *DexEntries[dexnum].text2)
		{
			flavorpage ^= 1;
			PokeDex_ShowData(index, 0, flavorpage);
		}
	}

FadeMon:
	REG_BLDCNT = BLD_BOT(BLD_BG2) | BLD_STD | BLD_OBJ | BLD_BG0;
	for(blendi = 0; blendi < 0x10; blendi+=DEXFADESPEED)
	{
		REG_BLDALPHA = (blendi << 8) + (0x10 - blendi);
		DoVBlank();
	}
	flavorpage = 0;
	DmaArrayCopy(dexinfo1Map, MEM_VRAM + 0xE800);
	goto RedrawMonData;
}



int PokeSearchGetDexID()
{
	if(DexList == PokeDexes[0]) return 0;
	if(DexList == PokeDexes[1]) return 1;
	if(DexList == PokeDexes[2]) return 0;
	if(DexList == FilteredDex) return 2;
	return -1;
}

void PokeSearchSetColor(int cursor, int want)
{
	if(cursor == want)
		vwRedTransparentLUT();
	else
		vwBlackTransparentLUT();
}

void PokeSearchDrawStuff(int cursor, int dexid, int sort, int letter, int color, int type1, int type2)
{
	char NameStr[4] = { '-', ' ', '\0' };

	if(letter == 0)
		NameStr[0] = '-';
	else
		NameStr[0] = 'A'+letter-1;

	vwClear(0);

	PokeSearchSetColor(cursor,0);
	vwWrite(0,0,strPokedexNames[dexid]);

	PokeSearchSetColor(cursor,1);
	vwWrite(0,16,strPokedexSortings[sort]);

	PokeSearchSetColor(cursor,2);
	vwWrite(0,32,NameStr);

	PokeSearchSetColor(cursor,3);
	if(type1==0)
		vwWrite(0,48,"---");
	else
		vwWrite(0,48,TypeNames[type1-1]);

	PokeSearchSetColor(cursor,4);
	if(type2==0)
		vwWrite(0,64,"---");
	else
		vwWrite(0,64,TypeNames[type2-1]);

	PokeSearchSetColor(cursor,5);
	vwWrite(0,80,strPokedexColors[color]);

	vwWhiteTransparentLUT();
	vw_SetSmall();
	vwWrite(4,129,"Â¥MOVE Â¦CHANGE Â¢OK Â£BACK");
	vwSetLine(0,20,18, 608, 15);
	vw_SetBig();
	vwBlackTransparentLUT();
}

extern const unsigned short moncolorsPal[16];
extern const unsigned short moncolorsTiles[768];
void PokeSearch()
{
	int i, cursor = 0, color = 0, type1 = 0, type2 = 0, letter = 0, dexid = PokeSearchGetDexID(), sort = 0;
	signed int j;

	u16 *SortSourceDex = (u16*)PokeDexes[0];

	CleanUpCrap();
	ClearOamBak();
	DmaArrayCopy(dexfilterTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(dexfilterPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(dexfilterMap, MEM_VRAM + 0xE800);
	vwClear(1);
	vwNormalLUT();
	vwSetLine(15,16,2,96,15);
	vwSetLine(15,16,4,160,15);
	vwSetLine(15,16,6,224,15);
	vwSetLine(15,16,8,288,15);
	vwSetLine(15,16,10,352,15);
	vwSetLine(15,16,12,416,15);

	PokeSearchDrawStuff(cursor, dexid, sort, letter, color, type1, type2);

	while(1)
	{
		DoVBlank();
		KeyRead();

		if(Trg & KEY_UP || Trg & KEY_DOWN)
		{
			cursor = wrap(cursor + key_tri_vert(), 0, (dexid == 2) ? 6 : 2);
			PokeSearchDrawStuff(cursor, dexid, sort, letter, color, type1, type2);
		}

		if(Trg & KEY_LEFT || Trg & KEY_RIGHT)
		{
			switch(cursor)
			{
			case 0:
				dexid = wrap(dexid + key_tri_horz(), 0, 3);
				break;
			case 1:
				sort = wrap(sort + key_tri_horz(), 0, 2);
				break;
			case 2:
				letter = wrap(letter + key_tri_horz(), 0, 27);
				break;
			case 3:
				type1 = wrap(type1 + key_tri_horz(), 0, 19);
				if(type1 == 10) type1 += key_tri_horz();
				break;
			case 4:
				type2 = wrap(type2 + key_tri_horz(), 0, 19);
				if(type2 == 10) type2 += key_tri_horz();
				break;
			case 5:
				color = wrap(color + key_tri_horz(), 0, 11);
				break;
			}
			PokeSearchDrawStuff(cursor, dexid, sort, letter, color, type1, type2);
		}

		if(Trg & B_BUTTON)
		{
			return;
		}

		if(Trg & A_BUTTON)
		{

			if(dexid==2 && (color == 0 && type1 == 0 && type2 == 0 && letter == 0))
			{
				AGBPrint("PokeSearch: No filters specified...\n");
				dexid = PokeSearchGetDexID();
			}
			if(dexid==2) //didn't get caught on not filtering?
			{
				DmaArrayClear(0, FilteredDex);
				j = 1;
				SortSourceDex = (u16*)PokeDexes[sort * 2];
				for(i = 1; i < SortSourceDex[0]; i++)
				{
					int takeit = 1;
					if(!GETBIT(MyDex.seen, SortSourceDex[i])) takeit = 0;
					if(color && BaseStats[SortSourceDex[i]].Color != color-1) takeit = 0;
					if(type1 && BaseStats[SortSourceDex[i]].Type1 != type1-1) takeit = 0;
					if(type2 && BaseStats[SortSourceDex[i]].Type2 != type2-1) takeit = 0;
					if(letter && PokeNames[SortSourceDex[i]][0] != 'A'+letter-1) takeit = 0;
					if(takeit)
					{
						FilteredDex[j] = SortSourceDex[i];
						j++;
					}
				}
				if(j == 1)
				{
					AGBPrint("PokeSearch: nothing found.\n");
					return;
				}
				FilteredDex[0] = j;
				DexList = (void*)FilteredDex;
				AGBPrint("PokeSearch: PokÃ©dex set to Filtered mode.\n");
				return;
			} else
			{
				if(sort == 1)
				{
					AGBPrintf("PokeSearch: alphabetical sort? Okay.\n");
					DmaArrayClear(0, FilteredDex);
					j = 1;
					SortSourceDex = (u16*)PokeDexes[2];
					for(i = 1; i < SortSourceDex[0]; i++)
					{
						if(GETBIT(MyDex.seen, SortSourceDex[i]))
						{
							FilteredDex[j] = SortSourceDex[i];
							j++;
						}
					}
					FilteredDex[0] = j;
					DexList = (void*)FilteredDex;
				} else
				{
					DexList = (void*)PokeDexes[dexid];
					AGBPrintf("PokeSearch: PokÃ©dex set to #%d.\n",dexid);
				}
				return;
			}
		}
	}
}


/** \brief Displays the list of all known species.

		Calls ShowDexEntry when the user wants to.
*/
void openPokeDex()
{
	u32 idx;
	u16 cursor = 0;
	u16 scrolloffset = 1;
	u8 moziko = 15;
	char daah[3];

Redraw:
	vwBlackTransparentLUT();
	CleanUpCrap();
	ClearOamBak();
	DmaArrayCopy(dexlistTiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(dexlistPal, MEM_PAL_BG + 0x0000);
	DmaArrayCopy(dexlistMap, MEM_VRAM + 0xE800);
	PokeDex_WriteList(scrolloffset, cursor);

	for(idx=0; idx<8; idx++)
		vwSetLine(2,16,(idx<<1)+1,96+(64*idx),15);
	vwWrite(3,cursor*14,strArrow);
	//vwWrite(136,56,strArrow);
	//vwSetLine(2,1,(cursor<<1)+1,337,15);

	vwClearLine(0,1);
	vwClearLine(0,5);
	vwClearLine(0,7);
	sprintf(daah,"%03d", MyDex.seenrate);
	vwWrite(166,6,daah);
	sprintf(daah,"%03d", MyDex.caughtrate);
	vwWrite(166,23,daah);
	vw_SetSmall();
	vwWrite(139,6,"SEEN");
	vwWrite(130,22,"CAUGHT");
	vwSetLine(21,7,13, 145, 15);
	vwSetLine(20,8,15, 208, 15);
	vwWhiteTransparentLUT();
	vwWrite(4,129,"¥PICK ¢OK £CANCEL °±²OPTIONS");
	vwSetLine(0,20,18, 608, 15);
	vw_SetBig();
	vwBlackTransparentLUT();

	if(GETBIT(MyDex.seen, DexList[cursor+scrolloffset]))
		LoadPokemonPic(DexList[cursor+scrolloffset],0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
	else
		LoadPokemonPic(0,0,MEM_VRAM_OBJ,pal_obj_bank[0],0);

	SetupPokemonSprite(0);
	OamBak[0].HPos = 160;
	OamBak[0].VPos = 8;
	OamBak[0].HFlip = 0;
	OamBak[0].Mosaic = 1;
	REG_BG1HOFS= 8;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;
	REG_MOSAIC = (moziko<<8); //+(moziko<<12);

	FadeIn();
	while(1)
	{
		if(moziko)
		{
			moziko--;
			REG_MOSAIC = (moziko<<8); //+(moziko<<12);
			OamBak[0].HPos = 160 - (moziko>>1);
		}

		DoVBlank();
		KeyRead();

		if(Trg & A_BUTTON)
		{
			if(GETBIT(MyDex.seen, DexList[cursor+scrolloffset]) == 0)
			{
				//error buzz?
			} else
			{
				FadeOut();
				ShowDexEntry(DexList[cursor+scrolloffset]);
				goto Redraw;
			}
		}
		if(Trg & B_BUTTON)
		{
			break;
		}
		if(Trg & U_KEY)
		{
			vwWrite(3,cursor*14,"   ");
			if(cursor==0)
			{
				if(scrolloffset > 1) scrolloffset--;
				PokeDex_WriteList(scrolloffset, cursor);
			} else
			{
				cursor--;
			}
			if(GETBIT(MyDex.seen, DexList[cursor+scrolloffset]))
				LoadPokemonPic(DexList[cursor+scrolloffset],0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			else
				LoadPokemonPic(0,0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			moziko = 15;
			vwWrite(3,cursor*14,strArrow);
		} else if(Trg & D_KEY)
		{
			vwWrite(3,cursor*14,"   ");
			if(cursor==8)
			{
				if(scrolloffset < DexList[0] - 8) scrolloffset++;
				PokeDex_WriteList(scrolloffset, cursor);
			} else
			{
				if(DexList[cursor+scrolloffset+1]) cursor++;
			}
			if(GETBIT(MyDex.seen, DexList[cursor+scrolloffset]))
				LoadPokemonPic(DexList[cursor+scrolloffset],0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			else
				LoadPokemonPic(0,0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			moziko = 15;
			vwWrite(3,cursor*14,strArrow);
		} else if(Trg & L_KEY)
		{
			vwWrite(3,cursor*14,"   ");
			if(scrolloffset > 10)
			{
				scrolloffset-=9;
			} else
			{
				scrolloffset = 1;
				cursor=0;
			}
			PokeDex_WriteList(scrolloffset, cursor);
			if(GETBIT(MyDex.seen, DexList[cursor+scrolloffset]))
				LoadPokemonPic(DexList[cursor+scrolloffset],0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			else
				LoadPokemonPic(0,0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			moziko = 15;
			vwWrite(3,cursor*14,strArrow);
		} else if(Trg & R_KEY)
		{
			vwWrite(3,cursor*14,"   ");
			if(DexList[0] > 9)
			{
				if(scrolloffset < DexList[0] - 9)
				{
					scrolloffset+=9;
					if(scrolloffset > DexList[0] - 8) scrolloffset = DexList[0] - 8;
				} else
				{
					scrolloffset = DexList[0] - 8;
					cursor=8;
				}
			} else
			{
				cursor=DexList[0]-2;
			}
			PokeDex_WriteList(scrolloffset, cursor);
			if(GETBIT(MyDex.seen, DexList[cursor+scrolloffset]))
				LoadPokemonPic(DexList[cursor+scrolloffset],0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			else
				LoadPokemonPic(0,0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
			moziko = 15;
			vwWrite(3,cursor*14,strArrow);
		} else if(Trg & KEY_SELECT)
		{
			PokeSearch();
			goto Redraw;
		}
	}
	FadeOut();
	vwNormalLUT();
	ClearOamBak();
	ResetBackgrounds();
}

/** \brief Writes the list of species for the Pokedex */
void PokeDex_WriteList(int scrolloffset, int cursor)
{
	u32 idx;
	char blarg[3];
	char blub[32];
	AGBPrintf("Writing list from 0x%x...\n", DexList);
	for(idx = 0; idx < 9; idx++)
	{
		//vwClearLine(0,idx*4);

		if(DexList[idx+scrolloffset])
		{
			sprintf(blarg,"%03d", idx+scrolloffset); //DexList[idx+scrolloffset]);
		} else
		{
			break;
		}
		vw_SetSmall(); vwWrite(23,(idx*14)+1, blarg); vw_SetBig();

		if(GETBIT(MyDex.seen, DexList[idx+scrolloffset]))
			sprintf(blub,"%s            ",(char*)GetPokemonName(DexList[idx+scrolloffset]));
		else
			sprintf(blub,"---           ");
		blub[15] = 0;

		vwWrite(42,idx*14,(char*)blub);

		if(GETBIT(MyDex.caught, DexList[idx+scrolloffset]))
			vwWrite(12,(idx*14)-1, "\x80\x1F"); //"*");
		else
			vwWrite(12,(idx*14)-1, "   ");
	}
}

/** \brief Constructs the tilemap for the Pokedex to display the current selection */
void PokeDex_SetMonTiles(int offset, int start, int pal)
{
	u32 i,j,k=start;
	for(i=0; i<8;i++)
		for(j=0; j<8;j++)
			BG3MAP[offset+(i*32)+j] = (pal<<12) + k++;
}

extern const unsigned short typesPal[256];
extern const unsigned short typesTiles[1152];

/** \brief Loads graphics for a given type. */
void PokeDex_LoadType(int type, int slot)
{
	u16* thisPic;
	u16* thisPal;
	u16* targetPic;
	u16* targetPal;

	AGBPrintf("PokeDex_LoadType: %d to %d.\n", type, slot);

	if(type > tpNone) type--;

	thisPic = (unsigned short*)typesTiles + (type * 0x40);
	thisPal = (unsigned short*)typesPal + ((type-1) * 16);
	targetPic = (u16*)MEM_VRAM_OBJ + 0x800 + (slot * 0x40);
	targetPal = (u16*)MEM_PAL_OBJ + 0x40 + (slot << 4);
	DmaCopy(thisPic, targetPic, 0x80);
	DmaCopy(thisPal, targetPal, 32);

}

/** \brief Writes data for ShowDexEntry. */
void PokeDex_ShowData(int idx, int page, int flavorpage)
{
	char data[255];
	char foo[255];
	int meh;
	int dexnum = GetDexNumber(idx);
	int ratio = BaseStats[idx].Gender * 100 / 254;
	vwClear(0);
	if(page==0)
	{
		sprintf(data, "No.%d - %s", dexnum, (char*)GetPokemonName(idx));
		vwWrite(0,0,data);
		if(GETBIT(MyDex.caught,idx))
		{
			sprintf(data, "%s "POKEMON"\nHt: %ddm, Wt: %dhg",
				(char*)GetPokemonSpecies(dexnum),
				DexEntries[dexnum].height, DexEntries[dexnum].weight);
			vw_SetSmall(); vwWrite(0,18,data); vw_SetBig();
			//vwWrite(1,6<<3,(char*)GetPokemonDescription(idx));
			if(flavorpage == 0) vwWrite(1,6<<3,(char*)DexEntries[dexnum].text);
			else vwWrite(1,6<<3,(char*)DexEntries[dexnum].text2);

			vwWhiteTransparentLUT();
			vw_SetSmall();
			if(*DexEntries[dexnum].text2 == 0)
				vwWrite(4,129,"¥PICK ¢CRY ¦MORE");
			else
				vwWrite(4,129,"¥PICK ¢CRY ¦MORE °±²PAGE");
			vw_SetBig();
			vwBlackTransparentLUT();
		}
	}
	else
	{
		data[0] = 0; //sprintf(data,"\0");
		if(BaseStats[idx].Gender < 255)
		{
			sprintf(foo, strPokedexGenderRatio);
			strcat(data, foo);
			if(BaseStats[idx].Gender == 0)
				sprintf(foo, strPokedexAlwaysMale);
			else if(BaseStats[idx].Gender == 254)
				sprintf(foo, strPokedexAlwaysFemale);
			else
				sprintf(foo, strPokedexChanceOfFemale, ratio);
			strcat(data,foo);
		}

		u16* pEvos = GetEvolutions(idx);
		u16 nrOfEvos = *pEvos++;

		if(nrOfEvos)
		{
			for(meh = 0; meh < nrOfEvos; meh++)
			{
				switch(pEvos[(meh*4)])
				{
					case evoLevel:
						sprintf(foo, strPokedexEvolvesLevel, pEvos[(meh*4)+1], (char*)GetPokemonName(pEvos[(meh*4)+2]));
						strcat(data, foo);
						break;
					case evoHappy:
						sprintf(foo, strPokedexEvolvesHappy, (char*)GetPokemonName(pEvos[(meh*4)+2]));
						strcat(data, foo);
						break;
					case evoItem:
						sprintf(foo, "Evolves to %s with a %s.\n", (char*)GetPokemonName(pEvos[(meh*4)+2]), items[pEvos[(meh*4)+1]].name);
						strcat(data, foo);
						break;
				}
			}
		}

		meh = FindDevo(idx, 1); //using depth 1 makes it return the first link.
		if(meh != idx)
		{
			sprintf(foo, strPokedexEvolvesFromX, (char*)GetPokemonName(meh));
			strcat(data, foo);
		}

		vw_SetSmall();
		vwWrite(1,6<<3, data);
		vwWhiteTransparentLUT();
		vwWrite(4,129,"¥PICK ¦BACK");
		vw_SetBig();
		vwBlackTransparentLUT();
	}
}


const u16 regflash[] = { 0xFE94, 0xFE10, 0x7DAE, 0x7D6B, 0x7DAE, 0xFE10 };

/** \brief Edited version of ShowDexEntry. */
void ShowNewlyCaught(u16 index)
{
	signed int omgdutch;
	char data[64];
	int dexnum = GetDexNumber(index);
	BUP buh;
	u8 flasher = 0, flashtimer = 0;
	AGBPrintf("ShowNewlyCaught: showing species #%d...\n", index);

	CleanUpCrap();

	DmaArrayCopy(dexinfo1Tiles, MEM_VRAM + 0x0000);
	DmaArrayCopy(dexinfo1Pal, MEM_PAL_BG + 0x0000);
	DmaCopy(dexinfo1Map, MEM_VRAM + 0xE800, 1280 );

	buh.src_len = 32;
	buh.src_len = 1;
	buh.dst_bpp = 4;
	buh.dst_ofs = 0;

	OamBak[1].HPos = 208;
	OamBak[1].VPos = 16;
	OamBak[1].Size = 1;
	OamBak[1].CharNo = 64;
	OamBak[1].Pltt = 1;

	OamBak[2].HPos = 208;
	OamBak[2].VPos = 48;
	OamBak[2].Size = 1;
	OamBak[2].CharNo = 128;
	OamBak[2].Pltt = 4;
	OamBak[3].HPos = 208;
	OamBak[3].VPos = 32;
	OamBak[3].Size = 1;
	OamBak[3].CharNo = 132;
	OamBak[3].Pltt = 5;
	*(u16*)0x05000222 = 0x318C;

	SetupPokemonSprite(0);
	OamBak[0].HPos = 8;
	OamBak[0].VPos = 8;
	OamBak[0].HFlip = 1;

	REG_BG1HOFS= 8;	REG_BG1VOFS= 0;
	REG_BG2HOFS= 0;	REG_BG2VOFS= 0;
	REG_BG3HOFS= 0;	REG_BG3VOFS= 0;

	vwSetLine(11,20,2,96,15);
	vwSetLine(11,20,4,160,15);
	vwSetLine(11,20,6,224,15);
	vwSetLine(1,30,11,288,15);
	vwSetLine(1,30,13,352,15);
	vwSetLine(1,30,15,416,15);

	vwBlackTransparentLUT();

	vwClear(0);
	sprintf(data, "No.%d - %s", dexnum, (char*)GetPokemonName(index));
	vwWrite(0,0,data);
	sprintf(data, "%s "POKEMON"\nHt: %ddm, Wt: %dhg", (char*)GetPokemonSpecies(dexnum), DexEntries[dexnum].height, DexEntries[dexnum].weight);
	vw_SetSmall(); vwWrite(0,18,data); vw_SetBig();
	vwWrite(1,6<<3,(char*)GetPokemonDescription(dexnum));

	LoadPokemonPic(index,0,MEM_VRAM_OBJ,pal_obj_bank[0],0);
	BitUnPack((void*)PokePrints[index], (void*)MEM_VRAM_OBJ + 0x800, &buh);
	PokeDex_LoadType(BaseStats[index].Type1, 0);
	if(BaseStats[index].Type2 != BaseStats[index].Type1)
		PokeDex_LoadType(BaseStats[index].Type2, 1);
	else
		PokeDex_LoadType(tpNormal, 1);

	for(omgdutch=24; omgdutch >= 0; omgdutch--)
	{
		BG1MAP[omgdutch+0x241] = BG1MAP[omgdutch+0x242];
		BG1MAP[omgdutch+0x261] = BG1MAP[omgdutch+0x262];
	}
	*(u16*)0x05000016 = regflash[flasher];

	FadeIn();

	while(1)
	{
		DoVBlank();
		KeyRead();

		flashtimer++;
		if(flashtimer == 7)
		{
			flashtimer=0;
			flasher++;
			if(flasher == 6)
				flasher = 0;
			*(u16*)0x05000016 = regflash[flasher];
		}

		if(Trg & B_BUTTON)
		{
			FadeOut();
			vwNormalLUT();
			ClearOamBak();
			return;
		}
	}
}

/** \brief Registers a given PokÃ©mon as seen.

		Can also mark as seen and caught, and calls ShowNewlyCaught depending on the given flags.
*/
void Pokedex_RegisterPkmn(int species, int flags)
{
	if(species > pkCount)
		return;
	if(!GETBIT(MyDex.seen, species))
		MyDex.seenrate++; //increase rate if not seen before

	SETBIT(MyDex.seen, species);
	AGBPrintf("Pokedex_RegisterPkmn: species #%d is now marked as seen.\n", species);

	if(flags & REG_CAUGHT)
	{
		if(!GETBIT(MyDex.caught, species))
			MyDex.caughtrate++; //increase rate if not seen before

		SETBIT(MyDex.caught, species);
		AGBPrintf("Pokedex_RegisterPkmn: species #%d is now marked as caught.\n", species);
	}

	if(flags & REG_SHOWDEX)
		ShowNewlyCaught(species);
}
