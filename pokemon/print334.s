
@{{BLOCK(print334)

@=======================================================================
@
@	print334, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:51
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print334Tiles		@ 32 unsigned chars
	.hidden print334Tiles
print334Tiles:
	.hword 0xC080,0x60C0,0xC0A0,0xE0E0,0x0301,0x0603,0x0305,0x0707
	.hword 0xC0E0,0x80C0,0xC080,0x80C0,0x0303,0x0103,0x0301,0x0103

@}}BLOCK(print334)
