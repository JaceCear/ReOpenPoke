
@{{BLOCK(dexlist)

@=======================================================================
@
@	dexlist, 256x160@4, 
@	+ palette 16 entries, not compressed
@	+ 80 tiles (t|f reduced) not compressed
@	+ regular map (flat), not compressed, 32x20 
@	Total size: 32 + 2560 + 1280 = 3872
@
@	Time-stamp: 2014-09-26, 14:52:17
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.12
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global dexlistTiles		@ 2560 unsigned chars
	.hidden dexlistTiles
dexlistTiles:
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x5555,0x5555
	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x8865,0x4444,0x8888,0x8555,0x3988
	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x8888,0x8888,0x8888,0x8888,0x3333,0x3333

	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x6555,0x4444,0x8885,0x8865,0x8888
	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x8888,0x8888,0x8888,0x8888,0x8888,0x8888
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x4444,0x4444,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x8555,0x3398,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8444,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338

	.hword 0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333
	.hword 0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333,0x3333
	.hword 0x8933,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x4418,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x4444,0x4444,0x5555,0x5555,0x5555,0x6555,0x5555,0x8655
	.hword 0x5555,0x6555,0x5555,0x8655,0x5555,0x8886,0x6555,0x8888
	.hword 0x8854,0x8888,0x8886,0x8888,0x8888,0x7888,0x8888,0x6678

	.hword 0x8888,0x8888,0x8888,0x8888,0x8888,0x7888,0x8888,0x6667
	.hword 0x6788,0x6666,0x6667,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x8888,0x8888,0x6788,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8444,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x4418
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518

	.hword 0x5555,0x8865,0x5555,0x8886,0x6555,0x8888,0x8544,0x8888
	.hword 0x8855,0x8888,0x8865,0x7888,0x8886,0x6788,0x8888,0x6678
	.hword 0x8888,0x6667,0x7888,0x6666,0x6788,0x6666,0x6678,0x6666
	.hword 0x6667,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x5688,0x5555,0x6888,0x5555,0x8888,0x5556,0x8888,0x4448
	.hword 0x8888,0x5588,0x8887,0x5188,0x8876,0x6888,0x8766,0x8888

	.hword 0x5555,0x6555,0x5555,0x8555,0x5555,0x8655,0x4444,0x8844
	.hword 0x5555,0x8855,0x5555,0x8855,0x5555,0x8865,0x5555,0x8885
	.hword 0x8888,0x6668,0x8888,0x6667,0x8888,0x6666,0x7888,0x6666
	.hword 0x6888,0x6666,0x6888,0x6666,0x6788,0x6666,0x6688,0x6666
	.hword 0x5551,0x5555,0x5564,0x5555,0x5518,0x5555,0x4448,0x4444
	.hword 0x5188,0x5555,0x5188,0x5555,0x5188,0x5555,0x6488,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555

	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8444,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x4418,0x8333,0x5518,0x8333,0x5518
	.hword 0x5555,0x8885,0x5555,0x8885,0x5555,0x8886,0x5555,0x8888
	.hword 0x5555,0x8888,0x4444,0x8888,0x5555,0x8888,0x5555,0x8888
	.hword 0x6688,0x6666,0x6678,0x6666,0x6668,0x6666,0x6668,0x6666
	.hword 0x6668,0x6666,0x6668,0x6666,0x6668,0x6666,0x6668,0x6666

	.hword 0x1888,0x5555,0x1888,0x5555,0x1888,0x5555,0x4888,0x5555
	.hword 0x8888,0x5551,0x8888,0x4441,0x8888,0x5551,0x8888,0x5551
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518

	.hword 0x5555,0x8888,0x5555,0x8888,0x5555,0x8888,0x5555,0x8888
	.hword 0x5555,0x8888,0x5555,0x8886,0x5555,0x8885,0x5555,0x8885
	.hword 0x8888,0x5551,0x8888,0x5551,0x8888,0x5551,0x8888,0x5551
	.hword 0x8888,0x5551,0x4888,0x5555,0x1888,0x5555,0x1888,0x5555
	.hword 0x5555,0x8885,0x5555,0x8865,0x4444,0x8844,0x5555,0x8855
	.hword 0x5555,0x8855,0x5555,0x8655,0x5555,0x8555,0x5555,0x6555
	.hword 0x1888,0x5555,0x5488,0x5555,0x4188,0x4444,0x5188,0x5555
	.hword 0x5188,0x5555,0x5148,0x5555,0x5518,0x5555,0x5514,0x5555

	.hword 0x8555,0x3338,0x8444,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8444,0x3338,0x8555,0x3338
	.hword 0x8333,0x5518,0x8333,0x4418,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x4418,0x8333,0x5518
	.hword 0x8888,0x6678,0x8885,0x6788,0x8865,0x7888,0x8855,0x8888
	.hword 0x8655,0x8888,0x6555,0x8888,0x4444,0x8885,0x5555,0x8865
	.hword 0x8766,0x8888,0x8876,0x1888,0x8887,0x1188,0x8888,0x5188
	.hword 0x8888,0x5118,0x8888,0x5511,0x1888,0x4441,0x1188,0x5555

	.hword 0x5551,0x5555,0x4441,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x4444,0x4444
	.hword 0x8555,0x3338,0x8555,0x3338,0x8444,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8444,0x3338,0x8444,0x3338
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x4418,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x4418,0x8333,0x4418

	.hword 0x5555,0x8655,0x5555,0x6555,0x4444,0x4444,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x4444,0x4444
	.hword 0x8888,0x6678,0x8888,0x6788,0x8885,0x8888,0x8865,0x8888
	.hword 0x6555,0x8888,0x5555,0x8885,0x4444,0x8544,0x4444,0x4444
	.hword 0x6666,0x6666,0x6666,0x6666,0x6667,0x6666,0x6788,0x6666
	.hword 0x8888,0x6667,0x8888,0x7888,0x8888,0x8888,0x8885,0x8888
	.hword 0x8766,0x8888,0x8876,0x8888,0x8888,0x1888,0x8888,0x1188
	.hword 0x8888,0x5111,0x1888,0x5551,0x1118,0x4444,0x4411,0x4444

	.hword 0x5118,0x5555,0x5511,0x5555,0x4441,0x4444,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x4444,0x4444
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x4444,0x4444,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8444,0x3338,0x8444,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x4418,0x8333,0x4418,0x8333,0x5518,0x8333,0x5518

	.hword 0x6415,0x8888,0x1555,0x8641,0x5555,0x1155,0x5555,0x5555
	.hword 0x4444,0x4444,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x8888,0x8888,0x8888,0x8888,0x8864,0x8888,0x1115,0x1111
	.hword 0x4444,0x4444,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x8888,0x8888,0x8888,0x8888,0x8888,0x6888,0x1111,0x1111
	.hword 0x4444,0x4444,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x8888,0x1468,0x4688,0x5111,0x1114,0x5555,0x5551,0x5555
	.hword 0x4444,0x4444,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555

	.hword 0x5554,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x4444,0x4444,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x4444,0x4444
	.hword 0x8555,0x3338,0x8444,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8444,0x3338,0x8444,0x3338
	.hword 0x8333,0x5518,0x8333,0x4418,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x4418,0x8333,0x4418

	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x8865,0x4444,0x8885,0x5444,0x3988
	.hword 0x5555,0x5555,0x4444,0x4444,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5688,0x5555,0x8888,0x4445,0x8893,0x4458
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x4444,0x4444,0x4444,0x4444
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8444,0x3338,0x8444,0x3338

	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x4418,0x8333,0x4418
	.hword 0x8555,0x3398,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8444,0x3338,0x8444,0x3338
	.hword 0x8933,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x4418,0x8333,0x4418
	.hword 0x4444,0x4444,0x4444,0x4444,0x4444,0x4444,0x5555,0x5555
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555

	.hword 0x8444,0x3338,0x8444,0x3338,0x8444,0x3338,0x8555,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8333,0x4418,0x8333,0x4418,0x8333,0x4418,0x8333,0x5518
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x5555,0x5555,0x4444,0x4444,0x4444,0x4444,0x4444,0x4444
	.hword 0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555,0x5555
	.hword 0x8555,0x3338,0x8444,0x3338,0x8444,0x3338,0x8444,0x3338
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338

	.hword 0x8333,0x5518,0x8333,0x4418,0x8333,0x4418,0x8333,0x4418
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8555,0x3338,0x8555,0x3338,0x8555,0x3338,0x8555,0x3338
	.hword 0x8444,0x3338,0x8444,0x3338,0x8444,0x3338,0x8555,0x3398
	.hword 0x8333,0x5518,0x8333,0x5518,0x8333,0x5518,0x8333,0x5518
	.hword 0x8333,0x4418,0x8333,0x4418,0x8333,0x4418,0x8933,0x5518
	.hword 0x6555,0x3988,0x5555,0x8886,0x5555,0x8615,0x5555,0x1555
	.hword 0x4444,0x4444,0x4444,0x4444,0x4444,0x4444,0x5555,0x5555

	.hword 0x3333,0x3333,0x8888,0x8888,0x8888,0x8888,0x1111,0x1111
	.hword 0x4444,0x4444,0x4444,0x4444,0x4444,0x4444,0x5555,0x5555
	.hword 0x8893,0x5518,0x8888,0x5516,0x1688,0x5551,0x5111,0x5555
	.hword 0x4444,0x4444,0x4444,0x4444,0x4444,0x4444,0x5555,0x5555
	.hword 0x8888,0x8888,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666,0x6666
	.hword 0x6666,0x6666,0x6666,0x6666,0x5555,0x5555,0x4444,0x4444

	.section .rodata
	.align	2
	.global dexlistMap		@ 1280 unsigned chars
	.hidden dexlistMap
dexlistMap:
	.hword 0x0000,0x0001,0x0002,0x0003,0x0003,0x0003,0x0003,0x0003
	.hword 0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003,0x0003
	.hword 0x0003,0x0003,0x0003,0x0402,0x0001,0x0001,0x0001,0x0004
	.hword 0x0005,0x0005,0x0404,0x0001,0x0001,0x0001,0x0001,0x0000
	.hword 0x0000,0x0006,0x0007,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0009,0x0006,0x000A,0x000B,0x000C
	.hword 0x000D,0x040D,0x040C,0x040B,0x040A,0x0006,0x0006,0x0000

	.hword 0x0000,0x0C06,0x000E,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x000F,0x0C06,0x0010,0x0011,0x0012
	.hword 0x0012,0x0012,0x0012,0x0411,0x0013,0x0C06,0x0C06,0x0000
	.hword 0x0000,0x0C06,0x000E,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x000F,0x0014,0x0015,0x0012,0x0012
	.hword 0x0012,0x0012,0x0012,0x0012,0x0415,0x0016,0x0C06,0x0000

	.hword 0x0000,0x0017,0x0018,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0019,0x001A,0x001B,0x0012,0x0012
	.hword 0x0012,0x0012,0x0012,0x0012,0x041B,0x001C,0x0017,0x0000
	.hword 0x0000,0x001D,0x001E,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x001F,0x0020,0x081B,0x0012,0x0012
	.hword 0x0012,0x0012,0x0012,0x0012,0x0C1B,0x0021,0x001D,0x0000

	.hword 0x0000,0x0C17,0x0818,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0819,0x0022,0x0815,0x0012,0x0012
	.hword 0x0012,0x0012,0x0012,0x0012,0x0C15,0x0023,0x0C17,0x0000
	.hword 0x0000,0x0001,0x0024,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0025,0x0001,0x0026,0x0811,0x0012
	.hword 0x0012,0x0012,0x0012,0x0C11,0x0027,0x0028,0x0001,0x0000

	.hword 0x0000,0x0029,0x002A,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x002B,0x0029,0x002C,0x002D,0x002E
	.hword 0x080D,0x0C0D,0x0C0C,0x002F,0x0030,0x0029,0x0029,0x0000
	.hword 0x0000,0x0031,0x0032,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0033,0x0031,0x0031,0x0031,0x0034
	.hword 0x0035,0x0036,0x0037,0x0038,0x0031,0x0031,0x0031,0x0000

	.hword 0x0000,0x0031,0x0032,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0033,0x0031,0x0031,0x0031,0x0031
	.hword 0x0031,0x0031,0x0031,0x0031,0x0031,0x0031,0x0031,0x0000
	.hword 0x0000,0x0039,0x003A,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x003B,0x003C,0x0003,0x0003,0x0003
	.hword 0x0003,0x0003,0x0003,0x0003,0x0003,0x003D,0x0039,0x0000

	.hword 0x0000,0x003E,0x003F,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0040,0x0041,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0042,0x003E,0x0000
	.hword 0x0000,0x001D,0x001E,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x001F,0x001E,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x001F,0x001D,0x0000

	.hword 0x0000,0x0043,0x0044,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0045,0x0044,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0045,0x0043,0x0000
	.hword 0x0000,0x0046,0x0047,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0048,0x0047,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0048,0x0046,0x0000

	.hword 0x0000,0x0C46,0x0049,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x004A,0x0049,0x0008,0x0008,0x0008
	.hword 0x0008,0x0008,0x0008,0x0008,0x0008,0x004A,0x0C46,0x0000
	.hword 0x0000,0x0C46,0x004B,0x004C,0x004C,0x004C,0x004C,0x004C
	.hword 0x004C,0x004C,0x004C,0x004C,0x004C,0x004C,0x004C,0x004C
	.hword 0x004C,0x004C,0x004C,0x004D,0x004B,0x004C,0x004C,0x004C
	.hword 0x004C,0x004C,0x004C,0x004C,0x004C,0x004D,0x0C46,0x0000

	.hword 0x0000,0x004E,0x004E,0x004E,0x004E,0x004E,0x004E,0x004E
	.hword 0x004E,0x004E,0x004E,0x004E,0x004E,0x004E,0x004E,0x004E
	.hword 0x004E,0x004E,0x004E,0x004E,0x004E,0x004E,0x004E,0x004E
	.hword 0x004E,0x004E,0x004E,0x004E,0x004E,0x004E,0x004E,0x0000
	.hword 0x0000,0x004F,0x004F,0x004F,0x004F,0x004F,0x004F,0x004F
	.hword 0x004F,0x004F,0x004F,0x004F,0x004F,0x004F,0x004F,0x004F
	.hword 0x004F,0x004F,0x004F,0x004F,0x004F,0x004F,0x004F,0x004F
	.hword 0x004F,0x004F,0x004F,0x004F,0x004F,0x004F,0x004F,0x0000

	.section .rodata
	.align	2
	.global dexlistPal		@ 32 unsigned chars
	.hidden dexlistPal
dexlistPal:
	.hword 0x0000,0x318C,0x675A,0x7FFF,0x7D6B,0x7DAE,0x7E10,0x7E52
	.hword 0x7E94,0x7F5A,0x043C,0x0000,0x0000,0x0000,0x0000,0x0000

@}}BLOCK(dexlist)