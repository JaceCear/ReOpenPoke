
@{{BLOCK(print021)

@=======================================================================
@
@	print021, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:18
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print021Tiles		@ 32 unsigned chars
	.hidden print021Tiles
print021Tiles:
	.hword 0x0000,0x2000,0x7020,0xE070,0x0000,0x0800,0x1C08,0x0F1C
	.hword 0xC0E0,0x8080,0x0000,0x0000,0x070F,0x0303,0x0101,0x0000

@}}BLOCK(print021)
