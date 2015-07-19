
@{{BLOCK(print190)

@=======================================================================
@
@	print190, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:36
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print190Tiles		@ 32 unsigned chars
	.hidden print190Tiles
print190Tiles:
	.hword 0x0000,0x0000,0x8000,0xC080,0x0000,0x0000,0x0F03,0x0F0F
	.hword 0xC0C0,0xC0C0,0x0080,0x0000,0x070F,0x0307,0x0001,0x0000

@}}BLOCK(print190)
