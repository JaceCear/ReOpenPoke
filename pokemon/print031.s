
@{{BLOCK(print031)

@=======================================================================
@
@	print031, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:19
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print031Tiles		@ 32 unsigned chars
	.hidden print031Tiles
print031Tiles:
	.hword 0x0800,0x7818,0xFCFC,0xFCFC,0x1000,0x1E18,0x3F3F,0x3F3F
	.hword 0xF8FC,0xF0F8,0xE0F0,0x0080,0x1F3F,0x0F1F,0x070F,0x0001

@}}BLOCK(print031)
