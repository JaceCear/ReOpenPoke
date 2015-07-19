
@{{BLOCK(print192)

@=======================================================================
@
@	print192, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:37
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print192Tiles		@ 32 unsigned chars
	.hidden print192Tiles
print192Tiles:
	.hword 0x4000,0x6060,0xE060,0xE0E0,0x0300,0x0707,0x0707,0x0707
	.hword 0xC0E0,0xC0C0,0xC0C0,0x0080,0x0707,0x0307,0x0303,0x0001

@}}BLOCK(print192)
