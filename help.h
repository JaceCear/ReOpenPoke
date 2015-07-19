#include "openpoke.h"

typedef struct aHelpListPage
{
	const char *caption;
	const char *content;
} aHelpListPage;

typedef struct aHelpListItem
{
	u8 kind;
	u32 *meh;
} aHelpListItem;

typedef struct aHelpList
{
	const char *caption;
	u16 numItems;
	aHelpListItem items[32];
} aHelpList;

extern unsigned int HelpContext;
extern unsigned short InHelpMode;


extern void DoHelp();
