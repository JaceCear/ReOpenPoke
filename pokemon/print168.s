
@{{BLOCK(print168)

@=======================================================================
@
@	print168, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:34
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print168Tiles		@ 32 unsigned chars
	.hidden print168Tiles
print168Tiles:
	.hword 0x0000,0x0000,0x0000,0xE040,0x0000,0x0000,0x0000,0x0F0D
	.hword 0xB0F0,0x0000,0x0000,0x0000,0x0207,0x0000,0x0000,0x0000

@}}BLOCK(print168)
