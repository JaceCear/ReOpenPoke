
@{{BLOCK(print144)

@=======================================================================
@
@	print144, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:32
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print144Tiles		@ 32 unsigned chars
	.hidden print144Tiles
print144Tiles:
	.hword 0x0000,0x8C88,0x9C9C,0xB898,0x0101,0x3313,0x3933,0x1D19
	.hword 0xE0F0,0xC0E0,0xC0C0,0x0080,0x070F,0x0103,0x0101,0x0000

@}}BLOCK(print144)
