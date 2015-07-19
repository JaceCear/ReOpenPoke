
@{{BLOCK(print030)

@=======================================================================
@
@	print030, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:19
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print030Tiles		@ 32 unsigned chars
	.hidden print030Tiles
print030Tiles:
	.hword 0x0000,0x8000,0xB090,0xF8F8,0x0000,0x0000,0x0D09,0x1F1F
	.hword 0xF8F8,0xF0F0,0x80E0,0x0000,0x1F1F,0x0F0F,0x0107,0x0000

@}}BLOCK(print030)
