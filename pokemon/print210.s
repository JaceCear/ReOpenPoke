
@{{BLOCK(print210)

@=======================================================================
@
@	print210, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:39
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print210Tiles		@ 32 unsigned chars
	.hidden print210Tiles
print210Tiles:
	.hword 0x0000,0xB000,0xF8B8,0xFCF8,0x0000,0x0D00,0x1F1D,0x3F1F
	.hword 0xFCFC,0xF8F8,0xC0F0,0x0000,0x3F3F,0x1F1F,0x030F,0x0000

@}}BLOCK(print210)
