
@{{BLOCK(print064)

@=======================================================================
@
@	print064, 16x16@1, 
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
	.global print064Tiles		@ 32 unsigned chars
	.hidden print064Tiles
print064Tiles:
	.hword 0x1000,0x3830,0x7038,0xF8F8,0x0400,0x0E06,0x070E,0x0F0F
	.hword 0xF0F8,0xE0F0,0xC0C0,0x8080,0x070F,0x0307,0x0101,0x0000

@}}BLOCK(print064)
