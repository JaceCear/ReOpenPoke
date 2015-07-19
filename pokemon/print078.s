
@{{BLOCK(print078)

@=======================================================================
@
@	print078, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:24
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print078Tiles		@ 32 unsigned chars
	.hidden print078Tiles
print078Tiles:
	.hword 0xC000,0xF8F0,0xFCF8,0xFCFC,0x0300,0x1F0F,0x3F1F,0x3F3F
	.hword 0xFCFC,0xF8F8,0x60F0,0x0000,0x3F3F,0x1F1F,0x060F,0x0000

@}}BLOCK(print078)
