
@{{BLOCK(print401)

@=======================================================================
@
@	print401, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:59
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print401Tiles		@ 32 unsigned chars
	.hidden print401Tiles
print401Tiles:
	.hword 0xA000,0xD0C0,0xE810,0xE8E8,0x0500,0x0B03,0x1708,0x1717
	.hword 0xF0F0,0xE8E8,0xB058,0x00A0,0x0F0F,0x1717,0x0D1A,0x0005

@}}BLOCK(print401)
