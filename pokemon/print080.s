
@{{BLOCK(print080)

@=======================================================================
@
@	print080, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:24
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print080Tiles		@ 32 unsigned chars
	.hidden print080Tiles
print080Tiles:
	.hword 0x0000,0x2000,0xF070,0xF8F0,0x0000,0x0400,0x0F0E,0x1F0F
	.hword 0xF8F8,0xF0F8,0xE0F0,0x0000,0x1F1F,0x0F1F,0x070F,0x0000

@}}BLOCK(print080)
