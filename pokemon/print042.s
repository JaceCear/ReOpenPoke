
@{{BLOCK(print042)

@=======================================================================
@
@	print042, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:20
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print042Tiles		@ 32 unsigned chars
	.hidden print042Tiles
print042Tiles:
	.hword 0x0000,0x8000,0x8080,0x0000,0x0000,0x0703,0x0707,0x0307
	.hword 0x8080,0xE0C0,0x0060,0x0000,0x0103,0x0001,0x0000,0x0000

@}}BLOCK(print042)
