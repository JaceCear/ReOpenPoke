
@{{BLOCK(print142)

@=======================================================================
@
@	print142, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:31
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print142Tiles		@ 32 unsigned chars
	.hidden print142Tiles
print142Tiles:
	.hword 0x2000,0x6020,0xC060,0xC0C0,0x0800,0x0C08,0x070C,0x0707
	.hword 0xC0C0,0x80C0,0x8080,0x0080,0x0307,0x0303,0x0101,0x0000

@}}BLOCK(print142)
