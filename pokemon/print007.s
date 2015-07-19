
@{{BLOCK(print007)

@=======================================================================
@
@	print007, 16x16@1, 
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
	.global print007Tiles		@ 32 unsigned chars
	.hidden print007Tiles
print007Tiles:
	.hword 0x0000,0x0000,0xD080,0xF0F0,0x0000,0x0000,0x0500,0x0707
	.hword 0xF0F0,0xC0E0,0x0000,0x0000,0x0707,0x0103,0x0000,0x0000

@}}BLOCK(print007)
