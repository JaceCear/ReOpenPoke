
@{{BLOCK(print163)

@=======================================================================
@
@	print163, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:34
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print163Tiles		@ 32 unsigned chars
	.hidden print163Tiles
print163Tiles:
	.hword 0x0000,0x6000,0x6070,0xCCC0,0x0000,0x0C00,0x0C1C,0x6706
	.hword 0xF8FC,0xC0E0,0x0000,0x0000,0x3F7F,0x070F,0x0001,0x0000

@}}BLOCK(print163)
