
@{{BLOCK(print222)

@=======================================================================
@
@	print222, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:40
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print222Tiles		@ 32 unsigned chars
	.hidden print222Tiles
print222Tiles:
	.hword 0x0000,0x0000,0x0000,0xC080,0x0000,0x0000,0x0000,0x0703
	.hword 0x80C0,0x0000,0x0000,0x0000,0x0307,0x0000,0x0000,0x0000

@}}BLOCK(print222)
