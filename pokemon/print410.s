
@{{BLOCK(print410)

@=======================================================================
@
@	print410, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:14:00
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print410Tiles		@ 32 unsigned chars
	.hidden print410Tiles
print410Tiles:
	.hword 0x0000,0x0000,0x0000,0xC0C0,0x0000,0x0000,0x0000,0x0301
	.hword 0x80C0,0x0000,0x0000,0x0000,0x0303,0x0000,0x0000,0x0000

@}}BLOCK(print410)
