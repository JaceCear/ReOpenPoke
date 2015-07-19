
@{{BLOCK(print212)

@=======================================================================
@
@	print212, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:39
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print212Tiles		@ 32 unsigned chars
	.hidden print212Tiles
print212Tiles:
	.hword 0x8000,0xC080,0xC0C0,0xE0E0,0x0000,0x0100,0x0101,0x0303
	.hword 0xC0E0,0x0080,0xC0C0,0x0080,0x0103,0x0000,0x0101,0x0000

@}}BLOCK(print212)
