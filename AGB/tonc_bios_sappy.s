
	.file	"tonc_bios_sappy.s"
	.text
	.align 2
	.thumb


	.align 2
	.thumb_func
	.global SoundBiasSet
SoundBiasSet:
	mov		r0, #1
	swi		25
	bx		lr

	.align 2
	.thumb_func
	.global SoundBiasReset
SoundBiasReset:
	mov		r0, #0
	swi		25
	bx		lr

	.align 2
	.thumb_func
	.global SoundBiasChange
SoundBiasChange:
	swi		25
	bx		lr
	
	.align 2
	.thumb_func
	.global SoundDriverInit
SoundDriverInit:
	swi		26
	bx		lr
	
	.align 2
	.thumb_func
	.global SoundDriverMode
SoundDriverMode:
	swi		27
	bx		lr

	.align 2
	.thumb_func
	.global SoundDriverMain
SoundDriverMain:
	swi		28
	bx		lr
	
	.align 2
	.thumb_func
	.global SoundDriverVSync
SoundDriverVSync:
	swi		29
	bx		lr

	.align 2
	.thumb_func
	.global SoundChannelClear
SoundChannelClear:
	swi		30
	bx		lr

	.align 2
	.thumb_func
	.global MusicPlayerOpen
MusicPlayerOpen:
	swi		32
	bx		lr
	
	.align 2
	.thumb_func
	.global MusicPlayerStart
MusicPlayerStart:
	swi		33
	bx		lr

	.align 2
	.thumb_func
	.global MusicPlayerStop
MusicPlayerStop:
	swi		34
	bx		lr
	
	.align 2
	.thumb_func
	.global MusicPlayerContinue
MusicPlayerContinue:
	swi		35
	bx		lr
	
	.align 2
	.thumb_func
	.global MusicPlayerFadeOut
MusicPlayerFadeOut:
	swi		36
	bx		lr
	
	.align 2
	.thumb_func
	.global SoundDriverVSyncOff
SoundDriverVSyncOff:
	swi		40
	bx		lr
	
	.align 2
	.thumb_func
	.global SoundDriverVSyncOn
SoundDriverVSyncOn:
	swi		41
	bx		lr





@	.align 2
@	.thumb_func
@	.global SoundDriverVSyncOn
@SoundDriverVSyncOn:
@	swi		41
@	bx		lr

@ EOF
