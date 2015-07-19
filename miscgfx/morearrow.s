
@{{BLOCK(morearrow)

@=======================================================================
@
@	morearrow, 16x8@4, 
@	+ 2 tiles not compressed
@	Total size: 64 = 64
@
@	Time-stamp: 2014-09-26, 14:52:13
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global morearrowTiles		@ 64 unsigned chars
	.hidden morearrowTiles
morearrowTiles:
	.hword 0x0000,0x0000,0x9000,0x9999,0xC000,0x9999,0x0000,0x999C
	.hword 0x0000,0x99C0,0x0000,0x9C00,0x0000,0xC000,0x0000,0x0000
	.hword 0x0000,0x0000,0x9999,0x000C,0xC999,0x000C,0xCC99,0x0000
	.hword 0x0CC9,0x0000,0x00CC,0x0000,0x000C,0x0000,0x0000,0x0000

@}}BLOCK(morearrow)
