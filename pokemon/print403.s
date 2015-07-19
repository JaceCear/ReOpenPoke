
@{{BLOCK(print403)

@=======================================================================
@
@	print403, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print403Tiles		@ 32 unsigned chars
	.hidden print403Tiles
print403Tiles:
	.hword 0xC000,0x38F0,0x8C0C,0x2646,0x0300,0x1C0F,0x3130,0x6462
	.hword 0x4626,0x0C8C,0xF038,0x00C0,0x6264,0x3031,0x0F1C,0x0003

@}}BLOCK(print403)
