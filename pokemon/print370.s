
@{{BLOCK(print370)

@=======================================================================
@
@	print370, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:56
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print370Tiles		@ 32 unsigned chars
	.hidden print370Tiles
print370Tiles:
	.hword 0xE000,0x78F0,0xE898,0xF0E0,0x0000,0x0001,0x0F07,0x1F1F
	.hword 0xF0F0,0xE0E0,0x80C0,0x0000,0x373F,0x2033,0x1D39,0x000F

@}}BLOCK(print370)
