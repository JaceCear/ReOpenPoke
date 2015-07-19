
@{{BLOCK(print112)

@=======================================================================
@
@	print112, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:28
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print112Tiles		@ 32 unsigned chars
	.hidden print112Tiles
print112Tiles:
	.hword 0x1000,0x7838,0xFCFC,0xFCFC,0x0E04,0x1F0E,0x1F1F,0x1F1F
	.hword 0xFCFC,0xF8F8,0xE0F0,0x0080,0x1F1F,0x0F1F,0x070F,0x0001

@}}BLOCK(print112)
