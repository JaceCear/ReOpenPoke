
@{{BLOCK(print380)

@=======================================================================
@
@	print380, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:57
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print380Tiles		@ 32 unsigned chars
	.hidden print380Tiles
print380Tiles:
	.hword 0x0000,0x4040,0xE040,0xA0E0,0x0000,0x0504,0x0F05,0x0A0E
	.hword 0xE0A0,0x4060,0x80C0,0x0000,0x0E0B,0x040C,0x0307,0x0000

@}}BLOCK(print380)
