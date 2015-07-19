
@{{BLOCK(print249)

@=======================================================================
@
@	print249, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:44
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print249Tiles		@ 32 unsigned chars
	.hidden print249Tiles
print249Tiles:
	.hword 0x8000,0xB8B0,0xF8F8,0xF0F8,0x0100,0x1D0D,0x1F1F,0x0F1F
	.hword 0xF0F0,0xE0E0,0xE0E0,0x00C0,0x0F0F,0x0707,0x0707,0x0003

@}}BLOCK(print249)
