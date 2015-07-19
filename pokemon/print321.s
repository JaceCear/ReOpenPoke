
@{{BLOCK(print321)

@=======================================================================
@
@	print321, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:50
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print321Tiles		@ 32 unsigned chars
	.hidden print321Tiles
print321Tiles:
	.hword 0x0000,0x8000,0xD8C8,0xF8D8,0x0000,0x0000,0x0D09,0x0F0D
	.hword 0xFCFC,0x1C3C,0xE8CC,0x00E0,0x1F1F,0x1C1E,0x0B19,0x0003

@}}BLOCK(print321)
