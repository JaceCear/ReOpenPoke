
@{{BLOCK(print365)

@=======================================================================
@
@	print365, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:55
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print365Tiles		@ 32 unsigned chars
	.hidden print365Tiles
print365Tiles:
	.hword 0x0000,0x8080,0x80C0,0xE0C0,0x0100,0x0909,0x1C1D,0x171B
	.hword 0x70E0,0x3030,0xF070,0xC0E0,0x0E0F,0x0C0C,0x0706,0x0103

@}}BLOCK(print365)
