#include "openpoke.h"

void PhoneCall();

#define MAXAPARTMENTITEMS 32
#define MAXAPARTMENTITEMDEFS 32
typedef struct anApartmentItem
{
	unsigned char xpos;
	unsigned char ypos;
	unsigned int type;
} anApartmentItem;
typedef struct anApartmentItemDefinition
{
	unsigned char xsize;
	unsigned char ysize;
	unsigned char top;
	const unsigned short * const tiles;
	const char * name;
} anApartmentItemDefinition;
extern anApartmentItem ApartmentItems[MAXAPARTMENTITEMS] INEWRAM;
extern void EditApartment();
