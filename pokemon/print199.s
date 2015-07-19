
@{{BLOCK(print199)

@=======================================================================
@
@	print199, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:37
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print199Tiles		@ 32 unsigned chars
	.hidden print199Tiles
print199Tiles:
	.hword 0x0000,0x0000,0xE0C0,0xF0F0,0x0000,0x0000,0x0301,0x0707
	.hword 0xF0F0,0xE0F0,0x0000,0x0000,0x0707,0x0307,0x0000,0x0000

@}}BLOCK(print199)
