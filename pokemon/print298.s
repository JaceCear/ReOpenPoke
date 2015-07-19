
@{{BLOCK(print298)

@=======================================================================
@
@	print298, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print298Tiles		@ 32 unsigned chars
	.hidden print298Tiles
print298Tiles:
	.hword 0x0000,0x0000,0xF0C0,0xF8F0,0x0000,0x0000,0x0F03,0x1F0F
	.hword 0xF8F8,0xE000,0xC0E0,0x0000,0x1F1F,0x0700,0x0307,0x0000

@}}BLOCK(print298)
