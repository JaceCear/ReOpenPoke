
@{{BLOCK(cardbg)

@=======================================================================
@
@	cardbg, 8x8@4, 
@	+ 1 tiles not compressed
@	Total size: 32 = 32
@
@	Time-stamp: 2014-09-26, 14:52:13
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global cardbgTiles		@ 32 unsigned chars
	.hidden cardbgTiles
cardbgTiles:
	.hword 0xFFFF,0xFFFF,0xEEEE,0xEEEE,0xEEEE,0xEEEE,0xEEEE,0xEEEE
	.hword 0xFFFF,0xFFFF,0xEEEE,0xEEEE,0xEEEE,0xEEEE,0xEEEE,0xEEEE

@}}BLOCK(cardbg)
