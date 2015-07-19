
@{{BLOCK(print106)

@=======================================================================
@
@	print106, 16x16@1, 
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
	.global print106Tiles		@ 32 unsigned chars
	.hidden print106Tiles
print106Tiles:
	.hword 0x8000,0xC888,0xF8D8,0xF8F8,0x0000,0x0908,0x0F0D,0x0F0F
	.hword 0xFCFC,0x183C,0x1018,0xC030,0x1F1F,0x0C1E,0x040C,0x0106

@}}BLOCK(print106)
