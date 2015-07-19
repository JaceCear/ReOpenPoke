
@{{BLOCK(print245)

@=======================================================================
@
@	print245, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:43
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print245Tiles		@ 32 unsigned chars
	.hidden print245Tiles
print245Tiles:
	.hword 0x0000,0x0000,0xC000,0xE0E0,0x0000,0x0000,0x0200,0x0707
	.hword 0xC0E0,0x80C0,0x0000,0x0000,0x0707,0x0307,0x0000,0x0000

@}}BLOCK(print245)
