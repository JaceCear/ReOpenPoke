
@{{BLOCK(print150)

@=======================================================================
@
@	print150, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:32
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print150Tiles		@ 32 unsigned chars
	.hidden print150Tiles
print150Tiles:
	.hword 0xF060,0xF0F0,0xE0F0,0xE0E0,0x0C00,0x1E1E,0x0F0F,0x0707
	.hword 0xA0C0,0xB0B0,0xC0A0,0x00C0,0x0307,0x0303,0x0303,0x0001

@}}BLOCK(print150)
