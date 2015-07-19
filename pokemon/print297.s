
@{{BLOCK(print297)

@=======================================================================
@
@	print297, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print297Tiles		@ 32 unsigned chars
	.hidden print297Tiles
print297Tiles:
	.hword 0x7000,0x78F8,0x7C7C,0x7C7C,0x0700,0x0F0F,0x1F1F,0x1F1F
	.hword 0xFCFC,0xF8F8,0xF0F8,0xC0F0,0x1F1F,0x0F0F,0x070F,0x0107

@}}BLOCK(print297)
