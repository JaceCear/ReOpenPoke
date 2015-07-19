
@{{BLOCK(print137)

@=======================================================================
@
@	print137, 16x16@1, 
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
	.global print137Tiles		@ 32 unsigned chars
	.hidden print137Tiles
print137Tiles:
	.hword 0xC000,0xC0C0,0xC0C0,0xE0C0,0x0100,0x0F0F,0x0F0F,0x0F0F
	.hword 0xE0E0,0xE0E0,0x80E0,0x0000,0x070F,0x0707,0x0707,0x0000

@}}BLOCK(print137)
