
@{{BLOCK(print387)

@=======================================================================
@
@	print387, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:58
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print387Tiles		@ 32 unsigned chars
	.hidden print387Tiles
print387Tiles:
	.hword 0x0000,0x0000,0x8000,0xC0C0,0x0000,0x0000,0x0100,0x0303
	.hword 0xC0C0,0x80C0,0x0000,0x0000,0x0707,0x0307,0x0000,0x0000

@}}BLOCK(print387)
