
@{{BLOCK(print127)

@=======================================================================
@
@	print127, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:30
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print127Tiles		@ 32 unsigned chars
	.hidden print127Tiles
print127Tiles:
	.hword 0x0000,0x7830,0x7078,0x0070,0x0000,0x3C18,0x3C3C,0x001C
	.hword 0x0000,0xC000,0xC0C0,0x0080,0x0000,0x0300,0x0303,0x0001

@}}BLOCK(print127)
