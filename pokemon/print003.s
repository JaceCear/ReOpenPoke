
@{{BLOCK(print003)

@=======================================================================
@
@	print003, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:16
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print003Tiles		@ 32 unsigned chars
	.hidden print003Tiles
print003Tiles:
	.hword 0x0000,0x9000,0xF8B0,0xFCF8,0x0000,0x1301,0x3F1B,0x7F3F
	.hword 0xFCFC,0xF8FC,0xC0F0,0x0000,0x7F7F,0x3F7F,0x071F,0x0000

@}}BLOCK(print003)
