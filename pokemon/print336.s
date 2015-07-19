
@{{BLOCK(print336)

@=======================================================================
@
@	print336, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:52
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print336Tiles		@ 32 unsigned chars
	.hidden print336Tiles
print336Tiles:
	.hword 0xBC18,0x1EBC,0xFEEE,0xFEFE,0x1F07,0x3F1F,0x7F3E,0x7F7F
	.hword 0xFCFE,0xFCFC,0xF8F8,0xC0F0,0x3F7F,0x3F3F,0x1F1F,0x030F

@}}BLOCK(print336)
