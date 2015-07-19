
@{{BLOCK(print017)

@=======================================================================
@
@	print017, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:17
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print017Tiles		@ 32 unsigned chars
	.hidden print017Tiles
print017Tiles:
	.hword 0x0000,0x2020,0x7070,0xE0E0,0x0000,0x0808,0x1C1C,0x0F0F
	.hword 0xC0E0,0x8080,0x0080,0x0000,0x070F,0x0303,0x0103,0x0001

@}}BLOCK(print017)
