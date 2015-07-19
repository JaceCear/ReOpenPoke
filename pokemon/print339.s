
@{{BLOCK(print339)

@=======================================================================
@
@	print339, 16x16@1, 
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
	.global print339Tiles		@ 32 unsigned chars
	.hidden print339Tiles
print339Tiles:
	.hword 0x0000,0xE000,0xF8F8,0xFCFC,0x0000,0x0700,0x1F1F,0x3F3F
	.hword 0xFCFC,0xF8F8,0x00E0,0x0000,0x3F3F,0x1F1F,0x0007,0x0000

@}}BLOCK(print339)
