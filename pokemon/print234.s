
@{{BLOCK(print234)

@=======================================================================
@
@	print234, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:42
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print234Tiles		@ 32 unsigned chars
	.hidden print234Tiles
print234Tiles:
	.hword 0x0000,0x0000,0xC080,0xC0C0,0x0000,0x0000,0x0602,0x0707
	.hword 0xC0C0,0x80C0,0x0000,0x0000,0x0707,0x0307,0x0000,0x0000

@}}BLOCK(print234)
