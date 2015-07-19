
@{{BLOCK(print181)

@=======================================================================
@
@	print181, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:35
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print181Tiles		@ 32 unsigned chars
	.hidden print181Tiles
print181Tiles:
	.hword 0x0000,0xC080,0xE0E0,0xF0F0,0x0000,0x0301,0x0707,0x0F0F
	.hword 0xF0F0,0xF0F0,0xE0E0,0x00C0,0x0F0F,0x0F0F,0x0707,0x0003

@}}BLOCK(print181)
