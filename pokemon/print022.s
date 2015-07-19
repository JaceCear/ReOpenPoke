
@{{BLOCK(print022)

@=======================================================================
@
@	print022, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:18
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print022Tiles		@ 32 unsigned chars
	.hidden print022Tiles
print022Tiles:
	.hword 0x9000,0x9890,0xB8B8,0xF0F0,0x0800,0x1909,0x1D1D,0x0F0F
	.hword 0xE0E0,0x80C0,0x8080,0x0080,0x0707,0x0303,0x0101,0x0000

@}}BLOCK(print022)
