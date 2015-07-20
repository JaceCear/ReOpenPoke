
@{{BLOCK(helditem)

@=======================================================================
@
@	helditem, 8x8@4, 
@	+ palette 16 entries, not compressed
@	+ 1 tiles not compressed
@	Total size: 32 + 32 = 64
@
@	Time-stamp: 2014-09-26, 14:52:16
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global helditemTiles		@ 32 unsigned chars
	.hidden helditemTiles
helditemTiles:
	.hword 0x0000,0x0000,0x4450,0x0544,0x4450,0xF544,0x4450,0xF544
	.hword 0x6670,0xF766,0x6670,0xF766,0x4450,0xF544,0xFF00,0xFFFF

	.section .rodata
	.align	2
	.global helditemPal		@ 32 unsigned chars
	.hidden helditemPal
helditemPal:
	.hword 0x3727,0x7FFF,0x7F5A,0x5A52,0x4FDF,0x3B7B,0x155E,0x2974
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x318C

@}}BLOCK(helditem)
