
@{{BLOCK(print305)

@=======================================================================
@
@	print305, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:48
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print305Tiles		@ 32 unsigned chars
	.hidden print305Tiles
print305Tiles:
	.hword 0x8080,0x9808,0xB088,0xF0B0,0x0100,0x1001,0x1519,0x0F0D
	.hword 0xC0E0,0x80C0,0x8000,0x0080,0x0707,0x0103,0x0001,0x0101

@}}BLOCK(print305)
