
@{{BLOCK(print250)

@=======================================================================
@
@	print250, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:44
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print250Tiles		@ 32 unsigned chars
	.hidden print250Tiles
print250Tiles:
	.hword 0x0000,0x9080,0x9898,0xB0B0,0x0000,0x0901,0x1919,0x0D0D
	.hword 0xE0B0,0xC0E0,0x80C0,0x8080,0x070D,0x0307,0x0103,0x0101

@}}BLOCK(print250)
