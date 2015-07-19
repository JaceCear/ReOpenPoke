
@{{BLOCK(print225)

@=======================================================================
@
@	print225, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:41
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print225Tiles		@ 32 unsigned chars
	.hidden print225Tiles
print225Tiles:
	.hword 0x0000,0x4040,0xE060,0xE0E0,0x0000,0x0101,0x0303,0x0303
	.hword 0xF0F0,0xF0F0,0xC0E0,0x0000,0x0707,0x0707,0x0103,0x0000

@}}BLOCK(print225)
