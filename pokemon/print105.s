
@{{BLOCK(print105)

@=======================================================================
@
@	print105, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:27
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print105Tiles		@ 32 unsigned chars
	.hidden print105Tiles
print105Tiles:
	.hword 0x0000,0x0000,0xC080,0xE0C0,0x0000,0x0000,0x0703,0x0F07
	.hword 0xE0E0,0xC0E0,0x0080,0x0000,0x0F0F,0x070F,0x0003,0x0000

@}}BLOCK(print105)
