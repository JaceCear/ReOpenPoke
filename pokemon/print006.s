
@{{BLOCK(print006)

@=======================================================================
@
@	print006, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:16
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print006Tiles		@ 32 unsigned chars
	.hidden print006Tiles
print006Tiles:
	.hword 0x0000,0x9000,0xF8B0,0xF8F8,0x0100,0x1301,0x3F1B,0x3F3F
	.hword 0xF8F8,0xF0F8,0xE0F0,0x0080,0x3F3F,0x1F3F,0x0F1F,0x0003

@}}BLOCK(print006)
