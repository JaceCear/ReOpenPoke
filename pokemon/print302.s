
@{{BLOCK(print302)

@=======================================================================
@
@	print302, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print302Tiles		@ 32 unsigned chars
	.hidden print302Tiles
print302Tiles:
	.hword 0x0000,0x0000,0x0000,0x0080,0x0000,0x0000,0x0E00,0x1E1F
	.hword 0xC000,0xF0F8,0x0000,0x0000,0x0F1F,0x0003,0x0000,0x0000

@}}BLOCK(print302)
