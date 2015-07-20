
//{{BLOCK(font)

//======================================================================
//
//	font, 128x224@4,
//	+ 448 tiles 1x2 metatiles not compressed
//	Total size: 14336 = 14336
//
//	Time-stamp: 2007-05-17, 18:56:44
//	Exported by Cearn's Usenti v1.7.7
//	(comments, kudos, flames to "daytshen@hotmail.com")
//
//======================================================================

#ifndef __FONT__
#define __FONT__

#define fontWesternTilesLen 16384
extern const unsigned int fontWesternTiles[4096];

extern const unsigned char fontWesternWidths[];

#endif // __FONT__

//}}BLOCK(font)

//{{BLOCK(fontSmall)

//======================================================================
//
//	fontSmall, 128x224@4,
//	+ 448 tiles 1x2 metatiles not compressed
//	Total size: 14336 = 14336
//
//	Time-stamp: 2007-05-17, 19:03:34
//	Exported by Cearn's Usenti v1.7.7
//	(comments, kudos, flames to "daytshen@hotmail.com")
//
//======================================================================

#ifndef __FONTSMALL__
#define __FONTSMALL__

#define fontSmallTilesLen 16384
extern const unsigned int fontSmallTiles[4096];

extern const unsigned char fontSmallWidths[];

#endif // __FONTSMALL__

//}}BLOCK(fontSmall)

#define fontWideTilesLen 4096
extern const unsigned char fontWideTiles[1024];


//{{BLOCK(fontBraille)

//======================================================================
//
//	fontBraille, 256x64@4,
//	+ 256 tiles 1x4 metatiles not compressed
//	Total size: 8192 = 8192
//
//	Time-stamp: 2008-07-13, 05:19:14
//	Exported by Cearn's GBA Image Transmogrifier
//	( http://www.coranac.com )
//
//======================================================================

#ifndef __FONTBRAILLE__
#define __FONTBRAILLE__

#define fontBrailleTilesLen 12288
extern const unsigned int fontBrailleTiles[3072];

#endif // __FONTBRAILLE__

//}}BLOCK(fontBraille)

extern const unsigned int fontJapaneseTiles[4096];

extern const unsigned char fontJapaneseWidths[];
