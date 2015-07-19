
@{{BLOCK(print303)

@=======================================================================
@
@	print303, 16x16@1, 
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
	.global print303Tiles		@ 32 unsigned chars
	.hidden print303Tiles
print303Tiles:
	.hword 0x0000,0xC0C0,0xE0E0,0xE0E0,0x0000,0x0100,0x0303,0x0303
	.hword 0xC0C0,0x80C0,0xC040,0x0060,0x0303,0x0103,0x0001,0x0000

@}}BLOCK(print303)
