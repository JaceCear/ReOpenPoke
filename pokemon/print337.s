
@{{BLOCK(print337)

@=======================================================================
@
@	print337, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:52
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print337Tiles		@ 32 unsigned chars
	.hidden print337Tiles
print337Tiles:
	.hword 0xB000,0x5050,0x60F0,0xA020,0x0100,0x0507,0x0705,0x0202
	.hword 0xC0C0,0x80C0,0x0000,0x0000,0x0101,0x0001,0x0000,0x0000

@}}BLOCK(print337)
