
@{{BLOCK(print408)

@=======================================================================
@
@	print408, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:14:00
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print408Tiles		@ 32 unsigned chars
	.hidden print408Tiles
print408Tiles:
	.hword 0xC000,0x7078,0xE0E0,0xC0C0,0x0000,0x0000,0x0307,0x0701
	.hword 0xC0C0,0xE0C0,0x70E0,0xC0F8,0x071F,0x0301,0x0007,0x0000

@}}BLOCK(print408)
