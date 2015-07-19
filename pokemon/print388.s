
@{{BLOCK(print388)

@=======================================================================
@
@	print388, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:58
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print388Tiles		@ 32 unsigned chars
	.hidden print388Tiles
print388Tiles:
	.hword 0x0000,0xBC0C,0xF8F8,0xF0F0,0x0000,0x3D30,0x1F1F,0x0F0F
	.hword 0xF8F8,0x8CDC,0x0080,0x0000,0x1F1F,0x313B,0x0001,0x0000

@}}BLOCK(print388)
