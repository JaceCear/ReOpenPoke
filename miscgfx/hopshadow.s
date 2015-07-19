
@{{BLOCK(hopshadow)

@=======================================================================
@
@	hopshadow, 16x8@4, 
@	+ 2 tiles not compressed
@	Total size: 64 = 64
@
@	Time-stamp: 2014-09-26, 14:52:13
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global hopshadowTiles		@ 64 unsigned chars
	.hidden hopshadowTiles
hopshadowTiles:
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xF000,0xFFFF
	.hword 0xFFF0,0xFFFF,0xFFFF,0xFFFF,0xFFF0,0xFFFF,0xF000,0xFFFF
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0xFFFF,0x000F
	.hword 0xFFFF,0x0FFF,0xFFFF,0xFFFF,0xFFFF,0x0FFF,0xFFFF,0x000F

@}}BLOCK(hopshadow)
