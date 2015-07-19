
@{{BLOCK(print145)

@=======================================================================
@
@	print145, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:32
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print145Tiles		@ 32 unsigned chars
	.hidden print145Tiles
print145Tiles:
	.hword 0x0000,0x0800,0x9C8C,0xB898,0x0100,0x2101,0x7363,0x3B33
	.hword 0xE0F0,0x80C0,0x8080,0x0000,0x0F1F,0x0307,0x0303,0x0001

@}}BLOCK(print145)
