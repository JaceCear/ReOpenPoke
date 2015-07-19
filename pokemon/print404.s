
@{{BLOCK(print404)

@=======================================================================
@
@	print404, 16x16@1, 
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
	.global print404Tiles		@ 32 unsigned chars
	.hidden print404Tiles
print404Tiles:
	.hword 0x3E0C,0xF8FC,0x78F8,0x7878,0x0000,0x0F01,0x1F1F,0x3E3F
	.hword 0x7C78,0x6C7C,0x606C,0x0000,0x3E3E,0x3E3E,0x3636,0x3036

@}}BLOCK(print404)
