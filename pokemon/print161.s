
@{{BLOCK(print161)

@=======================================================================
@
@	print161, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:33
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print161Tiles		@ 32 unsigned chars
	.hidden print161Tiles
print161Tiles:
	.hword 0x0000,0x0000,0x8000,0xC0C0,0x0000,0x0000,0x0100,0x0303
	.hword 0x4040,0x0080,0x0000,0x0000,0x0202,0x0001,0x0000,0x0000

@}}BLOCK(print161)
