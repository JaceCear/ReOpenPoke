
@{{BLOCK(print044)

@=======================================================================
@
@	print044, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:20
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print044Tiles		@ 32 unsigned chars
	.hidden print044Tiles
print044Tiles:
	.hword 0x0000,0x0000,0x8000,0xC080,0x0000,0x0000,0x0703,0x0707
	.hword 0xE0C0,0xC0E0,0x0000,0x0000,0x0303,0x0001,0x0000,0x0000

@}}BLOCK(print044)
