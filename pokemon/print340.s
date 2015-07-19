
@{{BLOCK(print340)

@=======================================================================
@
@	print340, 16x16@1, 
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
	.global print340Tiles		@ 32 unsigned chars
	.hidden print340Tiles
print340Tiles:
	.hword 0x6000,0xD6D1,0x8C8E,0x0607,0x0300,0x3545,0x1838,0x3070
	.hword 0x0607,0x1E0C,0xD9FE,0x0084,0x3070,0x3C18,0x4D3F,0x0010

@}}BLOCK(print340)
