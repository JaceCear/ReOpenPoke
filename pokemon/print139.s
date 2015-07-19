
@{{BLOCK(print139)

@=======================================================================
@
@	print139, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:31
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print139Tiles		@ 32 unsigned chars
	.hidden print139Tiles
print139Tiles:
	.hword 0x0000,0x0000,0x0000,0xC080,0x0000,0x0000,0x0300,0x0707
	.hword 0x80C0,0x0000,0x0000,0x0000,0x0103,0x0000,0x0000,0x0000

@}}BLOCK(print139)
