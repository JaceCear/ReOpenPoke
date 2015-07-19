
@{{BLOCK(print289)

@=======================================================================
@
@	print289, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:46
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print289Tiles		@ 32 unsigned chars
	.hidden print289Tiles
print289Tiles:
	.hword 0x4040,0x6060,0x2060,0xE0C0,0x0101,0x0303,0x0203,0x0300
	.hword 0xE0E0,0xC0E0,0xC0C0,0xC0C0,0x0303,0x0103,0x0101,0x0000

@}}BLOCK(print289)
