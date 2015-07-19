
@{{BLOCK(print123)

@=======================================================================
@
@	print123, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:29
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print123Tiles		@ 32 unsigned chars
	.hidden print123Tiles
print123Tiles:
	.hword 0x0000,0x8800,0x9098,0xF0F0,0x0100,0x2301,0x1333,0x1F1F
	.hword 0xF8F8,0xF0F8,0xE0F0,0x00C0,0x3F3F,0x1F3F,0x0F1F,0x0007

@}}BLOCK(print123)
