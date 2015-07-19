
@{{BLOCK(print290)

@=======================================================================
@
@	print290, 16x16@1, 
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
	.global print290Tiles		@ 32 unsigned chars
	.hidden print290Tiles
print290Tiles:
	.hword 0x0000,0x0000,0x0000,0x8000,0x0000,0x0000,0x0000,0x0300
	.hword 0xC0C0,0x0080,0x0000,0x0000,0x0707,0x0003,0x0000,0x0000

@}}BLOCK(print290)
