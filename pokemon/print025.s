
@{{BLOCK(print025)

@=======================================================================
@
@	print025, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:18
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print025Tiles		@ 32 unsigned chars
	.hidden print025Tiles
print025Tiles:
	.hword 0x0000,0x0000,0x0000,0xC040,0x0000,0x0000,0x0100,0x0705
	.hword 0xC0C0,0x80C0,0x0000,0x0000,0x0707,0x0307,0x0000,0x0000

@}}BLOCK(print025)
