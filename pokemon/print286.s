
@{{BLOCK(print286)

@=======================================================================
@
@	print286, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:45
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print286Tiles		@ 32 unsigned chars
	.hidden print286Tiles
print286Tiles:
	.hword 0x0000,0xC080,0xCCC0,0x1C9C,0x0000,0x0100,0x1901,0x1C1C
	.hword 0xE0D8,0x70F0,0x0020,0x0000,0x030D,0x0707,0x0002,0x0000

@}}BLOCK(print286)
