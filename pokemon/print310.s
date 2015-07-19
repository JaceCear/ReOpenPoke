
@{{BLOCK(print310)

@=======================================================================
@
@	print310, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:48
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print310Tiles		@ 32 unsigned chars
	.hidden print310Tiles
print310Tiles:
	.hword 0x8080,0xD888,0xFCFC,0xF8FC,0x1100,0x3B1B,0x3F3F,0x3F3F
	.hword 0xF8F8,0xF0F0,0xE0E0,0x80C0,0x1F1F,0x0F1F,0x070F,0x0307

@}}BLOCK(print310)
