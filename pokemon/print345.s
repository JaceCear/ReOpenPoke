
@{{BLOCK(print345)

@=======================================================================
@
@	print345, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:53
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print345Tiles		@ 32 unsigned chars
	.hidden print345Tiles
print345Tiles:
	.hword 0x0000,0xF8E0,0xFCF8,0xFCFC,0x0000,0x1F07,0x3F1F,0x3F3F
	.hword 0xFCFC,0xF8FC,0xE0F8,0x0000,0x3F3F,0x1F3F,0x071F,0x0000

@}}BLOCK(print345)
