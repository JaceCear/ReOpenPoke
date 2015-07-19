
@{{BLOCK(print400)

@=======================================================================
@
@	print400, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print400Tiles		@ 32 unsigned chars
	.hidden print400Tiles
print400Tiles:
	.hword 0xC080,0xE0C0,0x80C0,0x0000,0x0100,0x0301,0x0001,0x0000
	.hword 0x0000,0x0E00,0x0F0E,0x0003,0x0000,0x3800,0x7838,0x0060

@}}BLOCK(print400)
