
@{{BLOCK(print135)

@=======================================================================
@
@	print135, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:31
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print135Tiles		@ 32 unsigned chars
	.hidden print135Tiles
print135Tiles:
	.hword 0x0000,0x0000,0xB080,0xF8F0,0x0000,0x0000,0x0D01,0x1F0F
	.hword 0xF8F8,0xF0F0,0x00C0,0x0000,0x1F1F,0x0F0F,0x0003,0x0000

@}}BLOCK(print135)
