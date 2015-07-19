
@{{BLOCK(print018)

@=======================================================================
@
@	print018, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:18
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print018Tiles		@ 32 unsigned chars
	.hidden print018Tiles
print018Tiles:
	.hword 0x0000,0x9010,0xB8B8,0xF0F0,0x0100,0x1311,0x3B3B,0x1F1F
	.hword 0xE0F0,0x80C0,0x8080,0x0000,0x0F1F,0x0307,0x0303,0x0001

@}}BLOCK(print018)
