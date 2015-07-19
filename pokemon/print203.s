
@{{BLOCK(print203)

@=======================================================================
@
@	print203, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:38
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print203Tiles		@ 32 unsigned chars
	.hidden print203Tiles
print203Tiles:
	.hword 0x0000,0x0000,0x4000,0xE0E0,0x0000,0x0000,0x0100,0x0303
	.hword 0xE0E0,0x00C0,0x0000,0x0000,0x0303,0x0001,0x0000,0x0000

@}}BLOCK(print203)
