
@{{BLOCK(print002)

@=======================================================================
@
@	print002, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:16
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print002Tiles		@ 32 unsigned chars
	.hidden print002Tiles
print002Tiles:
	.hword 0x0000,0x0000,0xB010,0xF8F0,0x0000,0x0100,0x1B11,0x3F1F
	.hword 0xF8F8,0xF0F0,0x80E0,0x0000,0x3F3F,0x1F1F,0x030F,0x0000

@}}BLOCK(print002)
