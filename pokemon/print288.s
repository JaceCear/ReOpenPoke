
@{{BLOCK(print288)

@=======================================================================
@
@	print288, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:46
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print288Tiles		@ 32 unsigned chars
	.hidden print288Tiles
print288Tiles:
	.hword 0x0000,0x0000,0xD080,0x10B8,0x0000,0x0000,0x0500,0x040E
	.hword 0xF0E0,0xA070,0xE0D0,0x0000,0x0703,0x0207,0x0305,0x0000

@}}BLOCK(print288)
