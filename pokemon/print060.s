
@{{BLOCK(print060)

@=======================================================================
@
@	print060, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:22
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print060Tiles		@ 32 unsigned chars
	.hidden print060Tiles
print060Tiles:
	.hword 0x0000,0x0000,0x0000,0x8000,0x0000,0x0000,0x0000,0x0F07
	.hword 0xC080,0xC0C0,0x0000,0x0000,0x070F,0x0001,0x0000,0x0000

@}}BLOCK(print060)
