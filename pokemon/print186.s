
@{{BLOCK(print186)

@=======================================================================
@
@	print186, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:36
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print186Tiles		@ 32 unsigned chars
	.hidden print186Tiles
print186Tiles:
	.hword 0xC080,0x8CC0,0xFE1E,0xE0EC,0x0301,0x3103,0x7F78,0x0737
	.hword 0xC0C0,0xC0C0,0xC0C0,0x0080,0x0303,0x0303,0x0303,0x0001

@}}BLOCK(print186)
