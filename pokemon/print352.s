
@{{BLOCK(print352)

@=======================================================================
@
@	print352, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:54
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print352Tiles		@ 32 unsigned chars
	.hidden print352Tiles
print352Tiles:
	.hword 0x6000,0x7060,0x30F0,0xF0D0,0x0300,0x0703,0x0607,0x0705
	.hword 0xF0F0,0xE0E0,0xE0E0,0x00C0,0x0707,0x0303,0x0303,0x0001

@}}BLOCK(print352)
