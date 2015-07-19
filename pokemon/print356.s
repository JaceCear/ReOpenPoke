
@{{BLOCK(print356)

@=======================================================================
@
@	print356, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:54
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print356Tiles		@ 32 unsigned chars
	.hidden print356Tiles
print356Tiles:
	.hword 0x0000,0xC000,0xE0E0,0xF0F0,0x0000,0x0300,0x0707,0x0F0F
	.hword 0xF0F0,0xE0E0,0xC0E0,0x0000,0x0F0F,0x070F,0x0307,0x0000

@}}BLOCK(print356)
