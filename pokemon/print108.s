
@{{BLOCK(print108)

@=======================================================================
@
@	print108, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:28
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print108Tiles		@ 32 unsigned chars
	.hidden print108Tiles
print108Tiles:
	.hword 0x0000,0xE0C0,0xF8F0,0xFCF8,0x0000,0x0301,0x0F07,0x1F0F
	.hword 0x3CFC,0x1818,0xF038,0x00C0,0x1E1F,0x0C0C,0x070E,0x0001

@}}BLOCK(print108)
