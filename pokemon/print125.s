
@{{BLOCK(print125)

@=======================================================================
@
@	print125, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:29
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print125Tiles		@ 32 unsigned chars
	.hidden print125Tiles
print125Tiles:
	.hword 0x1010,0xF830,0xF8F8,0xF0F0,0x0202,0x0703,0x0707,0x0303
	.hword 0xF0F0,0xE0F0,0xC0C0,0x0040,0x0303,0x0103,0x0000,0x0000

@}}BLOCK(print125)
