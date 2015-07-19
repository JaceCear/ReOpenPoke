
@{{BLOCK(print098)

@=======================================================================
@
@	print098, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:26
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print098Tiles		@ 32 unsigned chars
	.hidden print098Tiles
print098Tiles:
	.hword 0x0000,0x0000,0x0000,0xF0C0,0x0000,0x0000,0x0000,0x0F03
	.hword 0xF8F8,0x0070,0x0000,0x0000,0x190F,0x0010,0x0000,0x0000

@}}BLOCK(print098)
