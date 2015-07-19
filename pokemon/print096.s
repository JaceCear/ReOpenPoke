
@{{BLOCK(print096)

@=======================================================================
@
@	print096, 16x16@1, 
@	+ 4 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2015-06-27, 23:13:26
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global print096Tiles		@ 32 unsigned chars
	.hidden print096Tiles
print096Tiles:
	.hword 0x0000,0xC000,0xE0E0,0xF0F0,0x0000,0x0600,0x0F0F,0x1F1F
	.hword 0xF0F0,0xF0F0,0xE0E0,0x00C0,0x1F1F,0x1F1F,0x0F0F,0x0007

@}}BLOCK(print096)
