
@{{BLOCK(print039)

@=======================================================================
@
@	print039, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:20
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print039Tiles		@ 32 unsigned chars
	.hidden print039Tiles
print039Tiles:
	.hword 0x0000,0xC080,0xC0C0,0xC0C0,0x0000,0x0703,0x0707,0x0707
	.hword 0xC0C0,0xC0C0,0x8080,0x0000,0x0307,0x0303,0x0101,0x0000

@}}BLOCK(print039)
