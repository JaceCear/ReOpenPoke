
@{{BLOCK(print350)

@=======================================================================
@
@	print350, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:53
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print350Tiles		@ 32 unsigned chars
	.hidden print350Tiles
print350Tiles:
	.hword 0x0000,0x0000,0xC0C0,0xE0E0,0x0000,0x0000,0x0303,0x0707
	.hword 0xE0E0,0xC0C0,0x0080,0x0000,0x0707,0x0303,0x0001,0x0000

@}}BLOCK(print350)
