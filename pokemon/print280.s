
@{{BLOCK(print280)

@=======================================================================
@
@	print280, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:45
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print280Tiles		@ 32 unsigned chars
	.hidden print280Tiles
print280Tiles:
	.hword 0x0000,0x8800,0x8018,0xF0B0,0x0000,0x2301,0x0330,0x1F1B
	.hword 0xC0E0,0x8080,0x8000,0x0000,0x070F,0x0303,0x0300,0x0001

@}}BLOCK(print280)
