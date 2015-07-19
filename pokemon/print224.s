
@{{BLOCK(print224)

@=======================================================================
@
@	print224, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:41
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print224Tiles		@ 32 unsigned chars
	.hidden print224Tiles
print224Tiles:
	.hword 0x0000,0x0000,0x6030,0xC2C0,0x0000,0x3000,0x4830,0x3F4F
	.hword 0xFCE6,0xC0F0,0x0000,0x0000,0x1C3C,0x030F,0x0000,0x0000

@}}BLOCK(print224)
