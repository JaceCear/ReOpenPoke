
@{{BLOCK(print032)

@=======================================================================
@
@	print032, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:19
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print032Tiles		@ 32 unsigned chars
	.hidden print032Tiles
print032Tiles:
	.hword 0x0000,0x4000,0xC040,0xE0E0,0x0000,0x0200,0x0302,0x0707
	.hword 0xE0E0,0xC0C0,0x0080,0x0000,0x0707,0x0303,0x0001,0x0000

@}}BLOCK(print032)
