
@{{BLOCK(print128)

@=======================================================================
@
@	print128, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:30
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print128Tiles		@ 32 unsigned chars
	.hidden print128Tiles
print128Tiles:
	.hword 0x0000,0x0000,0xE080,0x70E0,0x0000,0x0000,0x0F03,0x1C0F
	.hword 0x3030,0x2070,0x0000,0x0000,0x1818,0x081C,0x0000,0x0000

@}}BLOCK(print128)
