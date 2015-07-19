
@{{BLOCK(print081)

@=======================================================================
@
@	print081, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:25
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print081Tiles		@ 32 unsigned chars
	.hidden print081Tiles
print081Tiles:
	.hword 0x0000,0x0000,0x0000,0xC080,0x0000,0x0000,0x0000,0x0602
	.hword 0xC000,0x0080,0x0000,0x0000,0x0600,0x0002,0x0000,0x0000

@}}BLOCK(print081)
