
@{{BLOCK(print333)

@=======================================================================
@
@	print333, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:51
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print333Tiles		@ 32 unsigned chars
	.hidden print333Tiles
print333Tiles:
	.hword 0x0000,0x0000,0x0000,0x0E0C,0x0000,0x0000,0x0000,0x1F01
	.hword 0x1C1E,0x0000,0x0000,0x0000,0x3EFE,0x0000,0x0000,0x0000

@}}BLOCK(print333)
