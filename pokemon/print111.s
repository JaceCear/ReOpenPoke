
@{{BLOCK(print111)

@=======================================================================
@
@	print111, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:28
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print111Tiles		@ 32 unsigned chars
	.hidden print111Tiles
print111Tiles:
	.hword 0x0000,0x2000,0x7070,0xF8F8,0x0000,0x0400,0x0E0E,0x1F1F
	.hword 0xF8F8,0xF8F8,0x30F8,0x0000,0x1F1F,0x1F1F,0x0C1F,0x0000

@}}BLOCK(print111)
