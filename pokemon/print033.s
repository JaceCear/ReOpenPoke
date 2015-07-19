
@{{BLOCK(print033)

@=======================================================================
@
@	print033, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:19
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print033Tiles		@ 32 unsigned chars
	.hidden print033Tiles
print033Tiles:
	.hword 0x0000,0x9080,0xF8B0,0xF8F0,0x0000,0x0900,0x1F1D,0x1F0F
	.hword 0xF8F8,0xF0F0,0x80E0,0x0000,0x1F1F,0x0F0F,0x0107,0x0000

@}}BLOCK(print033)
