
@{{BLOCK(print009)

@=======================================================================
@
@	print009, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:17
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print009Tiles		@ 32 unsigned chars
	.hidden print009Tiles
print009Tiles:
	.hword 0x8000,0xD8C0,0xFCDC,0xF8F8,0x0100,0x1B03,0x3F3B,0x1F1F
	.hword 0xF8F8,0xF0F8,0xC0C0,0x0080,0x1F1F,0x0F1F,0x0303,0x0001

@}}BLOCK(print009)
