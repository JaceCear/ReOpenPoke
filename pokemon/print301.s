
@{{BLOCK(print301)

@=======================================================================
@
@	print301, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:47
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print301Tiles		@ 32 unsigned chars
	.hidden print301Tiles
print301Tiles:
	.hword 0x0000,0xF800,0x00C0,0x0000,0x0000,0x0100,0x3E0F,0x7878
	.hword 0x8000,0x0000,0x0000,0x0000,0x073E,0x0000,0x0000,0x0000

@}}BLOCK(print301)
