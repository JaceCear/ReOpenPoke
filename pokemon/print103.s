
@{{BLOCK(print103)

@=======================================================================
@
@	print103, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:27
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print103Tiles		@ 32 unsigned chars
	.hidden print103Tiles
print103Tiles:
	.hword 0x1000,0x3838,0xFCFC,0xFCFC,0x0800,0x1C1C,0x3F3F,0x3F3F
	.hword 0xFCFC,0xF8FC,0xF0F8,0x00C0,0x3F3F,0x1F3F,0x0F1F,0x0003

@}}BLOCK(print103)
