
@{{BLOCK(print360)

@=======================================================================
@
@	print360, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:54
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print360Tiles		@ 32 unsigned chars
	.hidden print360Tiles
print360Tiles:
	.hword 0x0000,0x8000,0xC0C0,0xC0C0,0x0000,0x0300,0x0707,0x0707
	.hword 0x80C0,0x8080,0x0000,0x0000,0x0303,0x0103,0x0000,0x0000

@}}BLOCK(print360)
