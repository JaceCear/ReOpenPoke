
@{{BLOCK(print180)

@=======================================================================
@
@	print180, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:35
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print180Tiles		@ 32 unsigned chars
	.hidden print180Tiles
print180Tiles:
	.hword 0x0000,0x0000,0x0000,0x8080,0x0000,0x0000,0x0000,0x0101
	.hword 0xC0C0,0xC0C0,0x0080,0x0000,0x0303,0x0303,0x0001,0x0000

@}}BLOCK(print180)
