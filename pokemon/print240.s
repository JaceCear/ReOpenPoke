
@{{BLOCK(print240)

@=======================================================================
@
@	print240, 16x16@1, 
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
	.global print240Tiles		@ 32 unsigned chars
	.hidden print240Tiles
print240Tiles:
	.hword 0x0000,0x0000,0x6060,0xF0E0,0x0000,0x0000,0x0606,0x0F07
	.hword 0xF0F0,0x80E0,0x0000,0x0000,0x0F0F,0x0107,0x0000,0x0000

@}}BLOCK(print240)
