
#ifndef __ITEMMANAGER
#define __ITEMMANAGER

#define IR_REDRAW 0
#define IR_BREAK 1
#define IR_FADE 2

typedef struct anItem
{
	char	name[14];
	u16		id;
	u16		price;
	u8		special1;
	u8		special2;
	const char* description;
	u16		foo;
	u16		pocket;
	int		(*fielduse) (u16 index, u16 special1, u16 special2, u32 param1, u32 param2);
	u32		param1;
	int		(*battleuse)(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);
	u32		param2;
} anItem;

extern const anItem items[];

typedef struct anInventoryItem
{
	u16 itemidx;
	u16 itemcnt;
} anInventoryItem;

extern anInventoryItem inventory[200] INEWRAM;

typedef struct anInventoryPage
{
	u16 offset;
	u16 length;
	const char const * name;
	const char const * name2;
} anInventoryPage;

extern const anInventoryPage InventoryPages[6];

extern int ShowInventory();
extern int BattleInventory();
extern int HoldInventory();
extern void GiveItem(int index);
extern void GiveItems(int index, int amount);
extern void TakeItem(int index);
extern int HasItem(int index);
extern void UseRegisteredItem();

#define POCKET_ITEMS 1
#define POCKET_KEYITEMS 2
#define POCKET_BALLS 3
#define POCKET_TMHM 4
#define POCKET_BERRIES 5

int item_BtlEnigma	(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Enigma Berry during battle
int item_BtlEther		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Ether-likes during battle
int item_BtlFlute		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//PokéFlute during battle
int item_BtlHeal		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Healers during battle
int item_BerryPouch	(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Berry Pouch (if wanted, else use bag pocket)
int item_Bike				(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Bicycle, Acro Bike, Mach Bike
int item_BlockCase	(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Pez Dispenser
int item_Candy			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Rare Candy
int item_CoinCase		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Coin Case
int item_Decoy			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//PokéDoll and Fluffy Tail
int item_Enigma			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Enigma Berry
int item_Escape			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Escape Rope
int item_Ether			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Ethers, Elixirs and Leppa Berry (special = amount)
int item_FishRod		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Fishing Rods
int item_Flute			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//PokéFlute
int item_Heal				(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Healing items (special = amount)
int item_ItemFinder	(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Item Finder
int item_Mail				(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Stationery
int item_NoUse			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//There's a time and place for everything...
int item_PokeBall		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//PokéBalls (battle only, use param2)
int item_PPUp				(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//PP Up and PP Max
int item_Repel			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Repellants (special = steps)
int item_SacrAsh		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Sacred Ash
int item_StatMod		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Status Modifiers (Guard Spec, Dire Hit, X Foo)
int item_EvStone		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Evolution Stones (use item index)
int item_TM					(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//TMs and HMs (use item index)
int item_TMCase			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//TM Case (if wanted, else use bag pocket)
int item_TownMap		(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Town Map
int item_Water			(u16 index, u16 special1, u16 special2, u32 param1, u32 param2);	//Wailmer Pail and such


#endif

// EOF
