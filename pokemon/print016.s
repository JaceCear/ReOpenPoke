
@{{BLOCK(print016)

@=======================================================================
@
@	print016, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:17
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print016Tiles		@ 32 unsigned chars
	.hidden print016Tiles
print016Tiles:
	.hword 0x0000,0x2000,0x7020,0xE070,0x0000,0x0800,0x1C08,0x0F1C
	.hword 0xC0E0,0x8080,0x0000,0x0000,0x070F,0x0303,0x0101,0x0000

@}}BLOCK(print016)
