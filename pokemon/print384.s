
@{{BLOCK(print384)

@=======================================================================
@
@	print384, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:57
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print384Tiles		@ 32 unsigned chars
	.hidden print384Tiles
print384Tiles:
	.hword 0xC080,0x1CCC,0xE8DC,0xF8F0,0x7301,0x707B,0x1F2F,0x3F3F
	.hword 0xF8F8,0xF8F8,0xE070,0x0080,0x3F3F,0x3F3F,0x0B1C,0x0307

@}}BLOCK(print384)
