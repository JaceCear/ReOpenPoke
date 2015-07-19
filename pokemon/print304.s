
@{{BLOCK(print304)

@=======================================================================
@
@	print304, 16x16@1, 
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
	.global print304Tiles		@ 32 unsigned chars
	.hidden print304Tiles
print304Tiles:
	.hword 0x0000,0x0000,0x1080,0x80B0,0x0000,0x0100,0x0801,0x010D
	.hword 0xE0B0,0x80C0,0x0080,0x0080,0x070D,0x0103,0x0101,0x0100

@}}BLOCK(print304)
