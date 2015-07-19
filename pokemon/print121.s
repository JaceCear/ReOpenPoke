
@{{BLOCK(print121)

@=======================================================================
@
@	print121, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:29
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print121Tiles		@ 32 unsigned chars
	.hidden print121Tiles
print121Tiles:
	.hword 0x0000,0x0000,0x0000,0xC080,0x0000,0x0000,0x0000,0x0301
	.hword 0x80C0,0x0000,0x0000,0x0000,0x0103,0x0000,0x0000,0x0000

@}}BLOCK(print121)
