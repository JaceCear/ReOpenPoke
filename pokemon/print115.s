
@{{BLOCK(print115)

@=======================================================================
@
@	print115, 16x16@1, 
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
	.global print115Tiles		@ 32 unsigned chars
	.hidden print115Tiles
print115Tiles:
	.hword 0x8000,0xC0C0,0xFCF8,0xF8FC,0x0100,0x0303,0x3F1F,0x1F3F
	.hword 0xF0F0,0xF0F0,0xC0E0,0x0000,0x0F0F,0x0F0F,0x0307,0x0000

@}}BLOCK(print115)
