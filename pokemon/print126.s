
@{{BLOCK(print126)

@=======================================================================
@
@	print126, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:30
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print126Tiles		@ 32 unsigned chars
	.hidden print126Tiles
print126Tiles:
	.hword 0x1000,0x3030,0xF0F0,0xF8F0,0x0400,0x0606,0x0707,0x0F07
	.hword 0xF8F8,0xF0F8,0xE0F0,0x00C0,0x0F0F,0x070F,0x0307,0x0001

@}}BLOCK(print126)
