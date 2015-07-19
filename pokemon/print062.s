
@{{BLOCK(print062)

@=======================================================================
@
@	print062, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:22
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print062Tiles		@ 32 unsigned chars
	.hidden print062Tiles
print062Tiles:
	.hword 0x0000,0x8000,0xC0C0,0xC0C0,0x0000,0x0F07,0x1F1F,0x1F1F
	.hword 0x8080,0xC0C0,0x80C0,0x0000,0x0F1F,0x070F,0x0307,0x0000

@}}BLOCK(print062)
