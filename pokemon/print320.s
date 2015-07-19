
@{{BLOCK(print320)

@=======================================================================
@
@	print320, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:50
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print320Tiles		@ 32 unsigned chars
	.hidden print320Tiles
print320Tiles:
	.hword 0x0000,0xF0E0,0x78F8,0x3838,0x0000,0x0703,0x0F07,0x0E0E
	.hword 0x3838,0xF078,0xE0F0,0x0000,0x0E0E,0x0F0F,0x0307,0x0000

@}}BLOCK(print320)
