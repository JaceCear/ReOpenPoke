
@{{BLOCK(print300)

@=======================================================================
@
@	print300, 16x16@1, 
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
	.global print300Tiles		@ 32 unsigned chars
	.hidden print300Tiles
print300Tiles:
	.hword 0x0000,0x0000,0x0000,0xFC00,0x0000,0x0000,0x0000,0x3F00
	.hword 0xFCFC,0x0000,0x0000,0x0000,0x3F3F,0x0000,0x0000,0x0000

@}}BLOCK(print300)
