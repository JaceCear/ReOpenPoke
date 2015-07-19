
@{{BLOCK(print405)

@=======================================================================
@
@	print405, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:14:00
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print405Tiles		@ 32 unsigned chars
	.hidden print405Tiles
print405Tiles:
	.hword 0x1000,0xB890,0x40B8,0xE8E8,0x1101,0x3B13,0x043B,0x2F2F
	.hword 0xE8E8,0x38D8,0xF0F8,0x20B0,0x2F2F,0x3837,0x1F3F,0x091B

@}}BLOCK(print405)
