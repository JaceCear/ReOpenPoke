
@{{BLOCK(print048)

@=======================================================================
@
@	print048, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:21
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print048Tiles		@ 32 unsigned chars
	.hidden print048Tiles
print048Tiles:
	.hword 0x0000,0x7060,0xF070,0xF0F0,0x0000,0x0703,0x0707,0x0707
	.hword 0xF0F0,0xE0F0,0xC0E0,0x0000,0x0707,0x0307,0x0103,0x0000

@}}BLOCK(print048)
