
@{{BLOCK(print065)

@=======================================================================
@
@	print065, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:23
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print065Tiles		@ 32 unsigned chars
	.hidden print065Tiles
print065Tiles:
	.hword 0x0800,0x1C1C,0xF83C,0xF8F8,0x0800,0x1C1C,0x0F1E,0x0F0F
	.hword 0xF8F8,0xE0F0,0xC0C0,0x80C0,0x0F0F,0x0307,0x0101,0x0001

@}}BLOCK(print065)
