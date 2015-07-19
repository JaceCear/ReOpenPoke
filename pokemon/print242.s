
@{{BLOCK(print242)

@=======================================================================
@
@	print242, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:43
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print242Tiles		@ 32 unsigned chars
	.hidden print242Tiles
print242Tiles:
	.hword 0x0000,0x0000,0x0000,0x8000,0x0000,0x0E00,0x1F1E,0x0F1F
	.hword 0xC080,0xE0C0,0xC0E0,0x0000,0x070F,0x0307,0x0001,0x0000

@}}BLOCK(print242)
