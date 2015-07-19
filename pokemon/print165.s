
@{{BLOCK(print165)

@=======================================================================
@
@	print165, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:34
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print165Tiles		@ 32 unsigned chars
	.hidden print165Tiles
print165Tiles:
	.hword 0x0000,0x6000,0xF0F0,0x1060,0x0000,0x0000,0x0E06,0x0F0E
	.hword 0xF0F0,0xC0E0,0x0000,0x0000,0x0F0F,0x0307,0x0000,0x0000

@}}BLOCK(print165)
