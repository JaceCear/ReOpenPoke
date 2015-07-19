
@{{BLOCK(print160)

@=======================================================================
@
@	print160, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:33
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print160Tiles		@ 32 unsigned chars
	.hidden print160Tiles
print160Tiles:
	.hword 0x4000,0x6040,0xE060,0xE0E0,0x0900,0x1B0B,0x1F1B,0x1F1F
	.hword 0xC0E0,0xC0C0,0xC0C0,0x0080,0x0F1F,0x0F0F,0x0707,0x0003

@}}BLOCK(print160)
