
@{{BLOCK(print220)

@=======================================================================
@
@	print220, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:40
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print220Tiles		@ 32 unsigned chars
	.hidden print220Tiles
print220Tiles:
	.hword 0x0000,0x0000,0x0000,0xC040,0x0000,0x0000,0x0000,0x0705
	.hword 0xC0C0,0x0080,0x0000,0x0000,0x0707,0x0003,0x0000,0x0000

@}}BLOCK(print220)
