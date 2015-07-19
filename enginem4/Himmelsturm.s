	.include "enginem4/MPlayDef.s"

	.equ	Himmelsturm_grp, voicegroup000
	.equ	Himmelsturm_pri, 0
	.equ	Himmelsturm_rev, 0
	.equ	Himmelsturm_mvl, 127
	.equ	Himmelsturm_key, 0
	.equ	Himmelsturm_tbs, 1
	.equ	Himmelsturm_exg, 0
	.equ	Himmelsturm_cmp, 1

	.section .rodata
	.global	Himmelsturm
	.align	2

@**************** Track 1 (Midi-Chn.1) ****************@

Himmelsturm_1:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	TEMPO , 116*Himmelsturm_tbs/2
	.byte		VOICE , 76
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 70
	.byte	W92
	.byte	W03
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W23
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N40   , Bn3 , v120
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W11
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		N05   , An3 , v108
	.byte	W03
	.byte		        Bn3 , v120
	.byte	W04
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		N42   , Fs4 , v072
	.byte	W24
	.byte	W01
@ 007   ----------------------------------------
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N36   , En4 , v120
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W32
	.byte	W01
	.byte		N05   , En4 , v108
	.byte	W03
	.byte		        Fs4 , v100
	.byte	W04
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N23   , En4 , v120
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W17
@ 008   ----------------------------------------
	.byte		N23   , Cs4 
	.byte	W24
	.byte		N84   , An3 
	.byte	W42
	.byte		VOL   , 63*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        59*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		VOL   , 58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		VOL   , 55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte	W01
@ 009   ----------------------------------------
Himmelsturm_1_009:
	.byte		VOL   , 46*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 42*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 37*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        27*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W84
	.byte	W01
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte	PEND
@ 010   ----------------------------------------
	.byte		N24   , Bn3 , v112
	.byte	W23
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N72   , Fs4 , v060
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W64
	.byte	W01
@ 011   ----------------------------------------
	.byte		N24   , En4 , v092
	.byte	W06
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N48   , An4 , v080
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W40
	.byte		        c_v-4
	.byte	W01
	.byte		N36   , Gs4 , v060
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W17
@ 012   ----------------------------------------
	.byte	W12
	.byte		N04   , Gs4 , v072
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		TIE   , Fs4 , v056
	.byte	W06
	.byte		VOL   , 41*Himmelsturm_mvl/mxv
	.byte	W32
	.byte		        43*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        63*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W04
@ 013   ----------------------------------------
Himmelsturm_1_013:
	.byte		VOL   , 58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 55*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 51*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 42*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 37*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		VOL   , 32*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 27*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 20*Himmelsturm_mvl/mxv
	.byte	W02
	.byte	PEND
	.byte		EOT   , Fs4 
	.byte	W72
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W36
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOICE , 46
	.byte		VOL   , 76*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 100
	.byte	W54
	.byte	W01
@ 024   ----------------------------------------
Himmelsturm_1_024:
	.byte	W36
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v020
	.byte	W03
	.byte		        Bn3 , v040
	.byte	W03
	.byte		        Bn3 , v020
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Fs4 , v040
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        En4 , v056
	.byte	W03
	.byte		        En4 , v020
	.byte	W03
	.byte		        En4 , v012
	.byte	W03
	.byte		        En4 , v020
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Fs4 , v040
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Bn4 , v112
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W03
	.byte		        Bn4 , v040
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W03
	.byte	PEND
@ 025   ----------------------------------------
Himmelsturm_1_025:
	.byte	W12
	.byte		N03   , An4 , v112
	.byte	W03
	.byte		        An4 , v020
	.byte	W03
	.byte		        An4 , v040
	.byte	W03
	.byte		        An4 , v020
	.byte	W15
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v020
	.byte	W03
	.byte		        Gs4 , v040
	.byte	W03
	.byte		        Gs4 , v020
	.byte	W15
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Fs4 , v040
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W15
	.byte		        En4 , v112
	.byte	W03
	.byte		        En4 , v020
	.byte	W03
	.byte		        En4 , v040
	.byte	W03
	.byte		        En4 , v020
	.byte	W03
	.byte	PEND
@ 026   ----------------------------------------
Himmelsturm_1_026:
	.byte	W12
	.byte		N03   , Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Fs4 , v040
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W72
	.byte	W03
	.byte	PEND
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_024
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_025
@ 030   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_026
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W40
	.byte		VOICE , 5
	.byte		VOL   , 76*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		MOD   , 100
	.byte	W54
	.byte	W01
@ 040   ----------------------------------------
	.byte	W24
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W18
	.byte		N12   , Bn3 , v100
	.byte	W24
	.byte		N04   , Fs3 
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W06
@ 041   ----------------------------------------
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn3 , v080
	.byte	W24
	.byte		N04   , Fs3 , v100
	.byte	W12
	.byte		        Fs3 , v016
	.byte	W12
	.byte		N12   , Fs4 , v080
	.byte	W24
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
@ 042   ----------------------------------------
	.byte		        An3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , An3 , v100
	.byte	W12
	.byte		N04   , Bn3 
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W18
	.byte		N12   , Bn3 , v100
	.byte	W24
	.byte		N04   , Fs3 
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W06
@ 043   ----------------------------------------
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn3 , v080
	.byte	W84
@ 044   ----------------------------------------
	.byte	W15
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOICE , 46
	.byte		VOL   , 76*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 100
	.byte	W19
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v020
	.byte	W03
	.byte		        Bn3 , v040
	.byte	W03
	.byte		        Bn3 , v020
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Fs4 , v040
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        En4 , v056
	.byte	W03
	.byte		        En4 , v020
	.byte	W03
	.byte		        En4 , v012
	.byte	W03
	.byte		        En4 , v020
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Fs4 , v040
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		        Bn4 , v112
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W03
	.byte		        Bn4 , v040
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W03
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_025
@ 046   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_026
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_024
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_025
@ 050   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_026
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W24
	.byte		VOICE , 76
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		MOD   , 80
	.byte	W08
	.byte		BEND  , c_v+0
	.byte	W60
	.byte	W03
@ 059   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
@ 060   ----------------------------------------
	.byte		N16   , Cs4 , v112
	.byte	W04
	.byte		VOL   , 61*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        29*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        16*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N76   , Fs4 , v080
	.byte	W03
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W08
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W14
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        65*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        70*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        83*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        77*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        35*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        28*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W02
@ 061   ----------------------------------------
	.byte	W11
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N05   , En4 , v096
	.byte	W06
	.byte		        Fs4 , v072
	.byte	W05
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N68   , Cs5 , v084
	.byte	W03
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W08
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        77*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        81*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        73*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        37*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        28*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        16*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        12*Himmelsturm_mvl/mxv
	.byte	W10
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W01
@ 062   ----------------------------------------
Himmelsturm_1_062:
	.byte		N23   , En5 , v060
	.byte	W24
	.byte		N64   , Ds5 , v084
	.byte	W03
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte	W12
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        65*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        69*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        70*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        35*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        31*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        27*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        22*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        18*Himmelsturm_mvl/mxv
	.byte	W10
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte	PEND
@ 063   ----------------------------------------
Himmelsturm_1_063:
	.byte		N23   , Bn4 , v088
	.byte	W23
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 33*Himmelsturm_mvl/mxv
	.byte		N36   , Fs5 , v112
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		VOL   , 35*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 38*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        49*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        37*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N05   , En5 , v096
	.byte	W04
	.byte		        Fs5 , v056
	.byte	W03
	.byte		        En5 , v072
	.byte	W04
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N32   , Ds5 , v112
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W15
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W01
	.byte	PEND
@ 064   ----------------------------------------
Himmelsturm_1_064:
	.byte		VOL   , 56*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        49*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        26*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        16*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        10*Himmelsturm_mvl/mxv
	.byte	W10
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N80   , Cs5 , v112
	.byte	W03
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W08
	.byte		VOL   , 46*Himmelsturm_mvl/mxv
	.byte	W14
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        65*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        63*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        60*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 59*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        51*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		VOL   , 46*Himmelsturm_mvl/mxv
	.byte	W02
	.byte	PEND
@ 065   ----------------------------------------
	.byte		        42*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 38*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		VOL   , 29*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-4
	.byte	W15
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N36   , Cs5 , v084
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W28
	.byte	W01
	.byte		N36   , Fs5 , v052
	.byte	W32
	.byte	W03
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
@ 066   ----------------------------------------
	.byte		N24   , An5 , v084
	.byte	W23
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N68   , Gs5 , v092
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		VOL   , 43*Himmelsturm_mvl/mxv
	.byte	W12
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        35*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        28*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        21*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        14*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        10*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        7*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W01
@ 067   ----------------------------------------
	.byte		N23   , En5 , v080
	.byte	W23
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N36   , Bn5 , v112
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W28
	.byte	W01
	.byte		N05   , An5 , v096
	.byte	W04
	.byte		        Bn5 
	.byte	W03
	.byte		        An5 , v092
	.byte	W04
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N44   , Gs5 
	.byte	W02
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		VOL   , 38*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W04
@ 068   ----------------------------------------
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 44*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		VOL   , 32*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 28*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 24*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        15*Himmelsturm_mvl/mxv
	.byte	W72
	.byte	W01
@ 069   ----------------------------------------
	.byte	W88
	.byte	W01
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W01
@ 070   ----------------------------------------
Himmelsturm_1_070:
	.byte		N23   , Cs4 , v072
	.byte	W23
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N32   , Fs4 
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W11
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		N06   , En4 , v108
	.byte	W06
	.byte		        Fs4 , v080
	.byte	W05
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N42   , Cs5 , v072
	.byte	W24
	.byte	PEND
@ 071   ----------------------------------------
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N36   , Bn4 , v056
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W28
	.byte	W01
	.byte		N06   , Bn4 , v068
	.byte	W06
	.byte		        Cs5 , v060
	.byte	W05
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N23   , Bn4 , v072
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W17
@ 072   ----------------------------------------
Himmelsturm_1_072:
	.byte		N23   , Gs4 , v072
	.byte	W24
	.byte		N84   , Fs4 
	.byte	W42
	.byte		VOL   , 63*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        59*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		VOL   , 58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		VOL   , 55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte	PEND
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_009
@ 074   ----------------------------------------
Himmelsturm_1_074:
	.byte		N24   , Fs4 , v072
	.byte	W23
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N72   , Cs5 , v060
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W64
	.byte	W01
	.byte	PEND
@ 075   ----------------------------------------
Himmelsturm_1_075:
	.byte		N24   , Bn4 , v092
	.byte	W06
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N48   , Fs5 , v080
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W40
	.byte		        c_v-4
	.byte	W01
	.byte		N36   , En5 , v060
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W17
	.byte	PEND
@ 076   ----------------------------------------
Himmelsturm_1_076:
	.byte	W12
	.byte		N04   , En5 , v072
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		TIE   , Cs5 , v056
	.byte	W06
	.byte		VOL   , 41*Himmelsturm_mvl/mxv
	.byte	W32
	.byte		        43*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        63*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W04
	.byte	PEND
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_013
	.byte		EOT   , Cs5 
	.byte	W68
	.byte	W03
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_070
@ 079   ----------------------------------------
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N36   , Bn4 , v072
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W28
	.byte	W01
	.byte		N06   , Bn4 , v068
	.byte	W06
	.byte		        Cs5 , v060
	.byte	W05
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N23   , Bn4 , v072
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W17
@ 080   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_072
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_009
@ 082   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_074
@ 083   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_075
@ 084   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_076
@ 085   ----------------------------------------
	.byte		VOL   , 58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 55*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 51*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 42*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 37*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		VOL   , 32*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 27*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 20*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		VOICE , 45
	.byte		MOD   , 50
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		EOT   , Cs5 
	.byte	W68
	.byte	W03
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
@ 086   ----------------------------------------
	.byte		N17   , Cs3 , v100
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 49*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        39*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        34*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        29*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N32   , Fs3 
	.byte	W06
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        65*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        74*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W05
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N42   , Cs4 
	.byte	W24
@ 087   ----------------------------------------
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N36   , Bn3 
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W28
	.byte	W01
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W05
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N23   , Bn3 
	.byte	W24
@ 088   ----------------------------------------
	.byte		        Gs3 , v076
	.byte	W24
	.byte		N96   , Fs3 , v100
	.byte	W42
	.byte		VOL   , 63*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 089   ----------------------------------------
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        37*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        27*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W84
	.byte	W01
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W01
@ 090   ----------------------------------------
	.byte		N24   
	.byte	W24
	.byte		N72   , Cs4 
	.byte	W72
@ 091   ----------------------------------------
	.byte		N24   , Bn3 
	.byte	W06
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N48   , Fs4 
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W40
	.byte	W01
	.byte		N36   , En4 
	.byte	W24
@ 092   ----------------------------------------
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W05
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		TIE   , Cs4 
	.byte	W03
	.byte		VOL   , 41*Himmelsturm_mvl/mxv
	.byte	W32
	.byte		        43*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W14
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W09
@ 093   ----------------------------------------
	.byte		        65*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        71*Himmelsturm_mvl/mxv
	.byte	W10
	.byte		        69*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        63*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 59*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 42*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        37*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        27*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W13
	.byte		EOT   
	.byte	W06
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
@ 094   ----------------------------------------
	.byte	W96
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	W92
	.byte	W03
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
@ 097   ----------------------------------------
	.byte		N04   , Fs4 , v060
	.byte	W06
	.byte		        Gs4 , v048
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 , v080
	.byte	W06
	.byte		N68   , Cs5 , v100
	.byte	W03
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte	W12
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        77*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        81*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        73*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        37*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        28*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        16*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        12*Himmelsturm_mvl/mxv
	.byte	W10
	.byte		        66*Himmelsturm_mvl/mxv
	.byte	W01
@ 098   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_062
@ 099   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_063
@ 100   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_1_064
@ 101   ----------------------------------------
	.byte		VOL   , 42*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 38*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		VOL   , 29*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-4
	.byte	W88
@ 102   ----------------------------------------
	.byte	W96
@ 103   ----------------------------------------
	.byte	W96
@ 104   ----------------------------------------
	.byte	W96
@ 105   ----------------------------------------
	.byte	W96
@ 106   ----------------------------------------
	.byte	W96
@ 107   ----------------------------------------
	.byte	W96
@ 108   ----------------------------------------
	.byte	W96
@ 109   ----------------------------------------
	.byte	W96
@ 110   ----------------------------------------
	.byte	W96
@ 111   ----------------------------------------
	.byte	W96
@ 112   ----------------------------------------
	.byte	W24
	.byte	FINE

@**************** Track 2 (Midi-Chn.2) ****************@

Himmelsturm_2:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W02
	.byte		VOICE , 14
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		MOD   , 120
	.byte		PAN   , c_v+0
	.byte	W92
	.byte	W01
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W96
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W96
@ 017   ----------------------------------------
	.byte	W96
@ 018   ----------------------------------------
	.byte	W96
@ 019   ----------------------------------------
	.byte	W96
@ 020   ----------------------------------------
	.byte	W96
@ 021   ----------------------------------------
	.byte	W96
@ 022   ----------------------------------------
	.byte	W96
@ 023   ----------------------------------------
	.byte	W96
@ 024   ----------------------------------------
	.byte	W96
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
Himmelsturm_2_027:
	.byte	W12
	.byte		N04   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v068
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v068
	.byte	W06
	.byte		        Fs3 , v032
	.byte	W12
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v068
	.byte	W06
	.byte		        An3 , v032
	.byte	W12
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v068
	.byte	W06
	.byte	PEND
@ 028   ----------------------------------------
	.byte		        En3 , v032
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
Himmelsturm_2_031:
	.byte	W12
	.byte		N04   , En4 , v088
	.byte	W06
	.byte		        En4 , v040
	.byte	W06
	.byte		        En4 , v032
	.byte	W12
	.byte		        Cs4 , v088
	.byte	W06
	.byte		        Cs4 , v040
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W12
	.byte		        Dn4 , v088
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W12
	.byte		        An3 , v088
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte	PEND
@ 032   ----------------------------------------
	.byte		        An3 , v032
	.byte	W96
@ 033   ----------------------------------------
	.byte	W96
@ 034   ----------------------------------------
	.byte	W96
@ 035   ----------------------------------------
	.byte	W96
@ 036   ----------------------------------------
	.byte	W96
@ 037   ----------------------------------------
	.byte	W96
@ 038   ----------------------------------------
	.byte	W96
@ 039   ----------------------------------------
	.byte	W96
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W12
	.byte		        Bn3 , v092
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W06
	.byte		        Bn3 , v012
	.byte	W12
	.byte		        Fs3 , v092
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W06
	.byte		        Fs3 , v012
	.byte	W12
	.byte		        An3 , v092
	.byte	W06
	.byte		        An3 , v028
	.byte	W06
	.byte		        An3 , v012
	.byte	W12
	.byte		        En3 , v092
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
@ 044   ----------------------------------------
	.byte		        En3 , v012
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_2_027
@ 048   ----------------------------------------
	.byte		N04   , En3 , v032
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_2_031
@ 052   ----------------------------------------
	.byte		N04   , An3 , v032
	.byte	W96
@ 053   ----------------------------------------
	.byte	W96
@ 054   ----------------------------------------
	.byte	W96
@ 055   ----------------------------------------
	.byte	W96
@ 056   ----------------------------------------
	.byte	W96
@ 057   ----------------------------------------
	.byte	W96
@ 058   ----------------------------------------
	.byte	W96
@ 059   ----------------------------------------
	.byte	W96
@ 060   ----------------------------------------
	.byte	W96
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W96
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W96
@ 091   ----------------------------------------
	.byte	W24
	.byte		VOICE , 76
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		MOD   , 80
	.byte	W08
	.byte		BEND  , c_v+0
	.byte	W60
	.byte	W03
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W88
	.byte	W01
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W01
@ 094   ----------------------------------------
	.byte		N23   , Cs4 , v072
	.byte	W23
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N32   , Fs4 
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W11
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		N06   , En4 , v108
	.byte	W06
	.byte		        Fs4 , v080
	.byte	W05
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N42   , Cs5 , v072
	.byte	W24
@ 095   ----------------------------------------
	.byte		VOL   , 64*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N36   , Bn4 , v056
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W28
	.byte	W01
	.byte		N06   , Bn4 , v068
	.byte	W06
	.byte		        Cs5 , v060
	.byte	W05
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		N23   , Bn4 , v072
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W17
@ 096   ----------------------------------------
	.byte		N23   , Gs4 
	.byte	W24
	.byte		N84   , Fs4 
	.byte	W42
	.byte		VOL   , 63*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        59*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		VOL   , 58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		VOL   , 55*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		VOL   , 48*Himmelsturm_mvl/mxv
	.byte	W01
@ 097   ----------------------------------------
	.byte		        46*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 42*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 37*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        27*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W84
	.byte	W02
@ 098   ----------------------------------------
	.byte	W96
@ 099   ----------------------------------------
	.byte	W24
	.byte	W03
	.byte		VOICE , 14
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 120
	.byte		BEND  , c_v+0
	.byte	W68
@ 100   ----------------------------------------
	.byte	W96
@ 101   ----------------------------------------
	.byte	W96
@ 102   ----------------------------------------
	.byte	W96
@ 103   ----------------------------------------
	.byte	W12
	.byte		N04   , Bn3 , v088
	.byte	W06
	.byte		        Bn3 , v040
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Gs3 , v088
	.byte	W06
	.byte		        Gs3 , v040
	.byte	W06
	.byte		        Gs3 , v032
	.byte	W12
	.byte		        An3 , v088
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        An3 , v032
	.byte	W12
	.byte		        En3 , v088
	.byte	W06
	.byte		        En3 , v040
	.byte	W06
@ 104   ----------------------------------------
	.byte		        En3 , v032
	.byte	W96
@ 105   ----------------------------------------
	.byte	W96
@ 106   ----------------------------------------
	.byte	W96
@ 107   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_2_031
@ 108   ----------------------------------------
	.byte		N04   , An3 , v032
	.byte	W96
@ 109   ----------------------------------------
	.byte	W96
@ 110   ----------------------------------------
	.byte	W96
@ 111   ----------------------------------------
	.byte	W96
@ 112   ----------------------------------------
	.byte	W24
	.byte	FINE

@**************** Track 3 (Midi-Chn.3) ****************@

Himmelsturm_3:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W04
	.byte		VOICE , 24
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 60
	.byte	W01
	.byte	W90
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W24
	.byte		N48   , En4 , v052
	.byte	W48
	.byte		        An4 
	.byte	W24
@ 005   ----------------------------------------
Himmelsturm_3_005:
	.byte	W24
	.byte		N48   , Gs4 , v052
	.byte	W48
	.byte		        An4 
	.byte	W24
	.byte	PEND
@ 006   ----------------------------------------
Himmelsturm_3_006:
	.byte	W24
	.byte		TIE   , Fs4 , v052
	.byte	W72
	.byte	PEND
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , En4 
	.byte	W48
	.byte		        An4 
	.byte	W24
@ 009   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_005
@ 010   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_006
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W24
	.byte		EOT   , Fs4 
	.byte	W72
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W96
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
Himmelsturm_3_016:
	.byte	W23
	.byte		VOICE , 95
	.byte		MOD   , 50
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		N36   , Fs2 , v120
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W22
	.byte		VOL   , 82*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        79*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        69*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        29*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W11
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N24   , Bn2 , v088
	.byte	W19
	.byte		VOL   , 83*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W01
	.byte	PEND
@ 017   ----------------------------------------
Himmelsturm_3_017:
	.byte		VOL   , 59*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        34*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        24*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        85*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		N90   , Fs3 , v060
	.byte	W01
	.byte		BEND  , c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v+0
	.byte	W56
	.byte	W01
	.byte		VOL   , 82*Himmelsturm_mvl/mxv
	.byte	W10
	.byte		        80*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        73*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        65*Himmelsturm_mvl/mxv
	.byte	W02
	.byte	PEND
@ 018   ----------------------------------------
Himmelsturm_3_018:
	.byte		VOL   , 62*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        32*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        25*Himmelsturm_mvl/mxv
	.byte	W11
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 35*Himmelsturm_mvl/mxv
	.byte		N36   , Bn2 , v112
	.byte	W02
	.byte		VOL   , 44*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        70*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        80*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        81*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        82*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W09
	.byte		        82*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        79*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        69*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N24   , Fs3 , v088
	.byte	W19
	.byte		VOL   , 83*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W01
	.byte	PEND
@ 019   ----------------------------------------
Himmelsturm_3_019:
	.byte		VOL   , 59*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        34*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        24*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N36   , Bn3 , v060
	.byte	W24
	.byte	W01
	.byte		VOL   , 79*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        75*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        63*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        59*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        39*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        31*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        23*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        15*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        40*Himmelsturm_mvl/mxv
	.byte		N48   , Cs4 , v080
	.byte	W01
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        74*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W21
	.byte		        82*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        79*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        75*Himmelsturm_mvl/mxv
	.byte	W01
	.byte	PEND
@ 020   ----------------------------------------
Himmelsturm_3_020:
	.byte	W01
	.byte		VOL   , 74*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        35*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        24*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        19*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        85*Himmelsturm_mvl/mxv
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		N36   , Fs2 , v120
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W22
	.byte		VOL   , 82*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        79*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        69*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        57*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        29*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        20*Himmelsturm_mvl/mxv
	.byte	W11
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N24   , Bn2 , v088
	.byte	W19
	.byte		VOL   , 83*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W01
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_019
@ 024   ----------------------------------------
Himmelsturm_3_024:
	.byte	W01
	.byte		VOL   , 74*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        35*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        24*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        19*Himmelsturm_mvl/mxv
	.byte	W78
	.byte	PEND
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_016
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_017
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_018
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_019
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_020
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_017
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_018
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_019
@ 040   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_024
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_016
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_017
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_018
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_019
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_020
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_017
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_018
@ 059   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_019
@ 060   ----------------------------------------
	.byte	W01
	.byte		VOL   , 74*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        35*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        24*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        19*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		VOICE , 24
	.byte		VOL   , 80*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W01
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W96
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W96
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W96
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W96
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W96
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W96
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W96
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W96
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W96
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W96
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W96
@ 091   ----------------------------------------
	.byte	W96
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W96
@ 094   ----------------------------------------
	.byte	W96
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	W96
@ 097   ----------------------------------------
	.byte	W96
@ 098   ----------------------------------------
	.byte	W96
@ 099   ----------------------------------------
	.byte	W23
	.byte		VOICE , 7
	.byte	W72
	.byte	W01
@ 100   ----------------------------------------
	.byte	W24
	.byte		N48   , Fs3 , v092
	.byte	W60
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
@ 101   ----------------------------------------
	.byte	W12
	.byte		N84   , Gs3 , v092
	.byte	W84
@ 102   ----------------------------------------
	.byte	W24
	.byte		N48   , An3 
	.byte	W60
	.byte		N06   
	.byte	W06
	.byte		        An3 , v052
	.byte	W06
@ 103   ----------------------------------------
	.byte	W12
	.byte		N84   , Bn3 , v092
	.byte	W84
@ 104   ----------------------------------------
	.byte	W24
	.byte		N48   , Fs3 , v076
	.byte	W60
	.byte		N06   
	.byte	W06
	.byte		        Fs3 , v036
	.byte	W06
@ 105   ----------------------------------------
	.byte	W12
	.byte		N84   , Gs3 , v076
	.byte	W84
@ 106   ----------------------------------------
	.byte	W24
	.byte		N48   , An3 
	.byte	W60
	.byte		N06   
	.byte	W06
	.byte		        An3 , v036
	.byte	W06
@ 107   ----------------------------------------
	.byte	W12
	.byte		N84   , Bn3 , v076
	.byte	W84
@ 108   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_016
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_017
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_3_019
@ 112   ----------------------------------------
	.byte	W01
	.byte		VOL   , 74*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        60*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        35*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        24*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		        19*Himmelsturm_mvl/mxv
	.byte	W06
	.byte	FINE

@**************** Track 4 (Midi-Chn.4) ****************@

Himmelsturm_4:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W06
	.byte		VOICE , 95
	.byte	W01
	.byte		MOD   , 45
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v-63
	.byte	W01
	.byte	W15
	.byte		VOL   , 0*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		TIE   , Fs2 , v052
	.byte	W05
	.byte		VOL   , 2*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        2*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        6*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        8*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        11*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        14*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        16*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        19*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        22*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        25*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        28*Himmelsturm_mvl/mxv
	.byte	W04
@ 001   ----------------------------------------
	.byte	W02
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        33*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        39*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        70*Himmelsturm_mvl/mxv
	.byte	W06
@ 002   ----------------------------------------
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        81*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W68
	.byte	W02
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W23
	.byte		VOICE , 24
	.byte	W01
	.byte		EOT   
	.byte		N48   , Cs4 , v040
	.byte	W48
	.byte		TIE   , En4 
	.byte	W24
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn4 
	.byte	W72
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , Cs4 
	.byte	W48
	.byte		TIE   , En4 
	.byte	W24
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn4 
	.byte	W72
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Fs4 
	.byte	W72
@ 013   ----------------------------------------
	.byte	W60
	.byte	W01
	.byte		VOL   , 63*Himmelsturm_mvl/mxv
	.byte	W32
	.byte	W03
@ 014   ----------------------------------------
	.byte	W92
	.byte	W01
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W03
@ 015   ----------------------------------------
	.byte	W05
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        49*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        39*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        34*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        26*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        22*Himmelsturm_mvl/mxv
	.byte	W06
@ 016   ----------------------------------------
	.byte	W01
	.byte		        18*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        14*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        9*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		VOICE , 95
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v-30
	.byte	W01
	.byte		EOT   
	.byte		N48   , Bn1 , v060
	.byte	W48
	.byte		N36   
	.byte	W24
@ 017   ----------------------------------------
Himmelsturm_4_017:
	.byte	W12
	.byte		N36   , An1 , v060
	.byte	W32
	.byte	W03
	.byte		VOICE , 7
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N01   , Dn2 , v012
	.byte	W12
	.byte		N06   , An2 , v060
	.byte	W12
	.byte	PEND
@ 018   ----------------------------------------
Himmelsturm_4_018:
	.byte	W12
	.byte		N42   , Gs2 , v060
	.byte	W56
	.byte	W03
	.byte		VOICE , 95
	.byte		PAN   , c_v-30
	.byte	W01
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
Himmelsturm_4_019:
	.byte		N01   , En2 , v012
	.byte	W12
	.byte		N36   , Dn2 , v060
	.byte	W48
	.byte		N42   , Cs2 
	.byte	W36
	.byte	PEND
@ 020   ----------------------------------------
Himmelsturm_4_020:
	.byte	W23
	.byte		VOICE , 95
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v-30
	.byte	W01
	.byte		N48   , Bn1 , v060
	.byte	W48
	.byte		N36   
	.byte	W24
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_019
@ 024   ----------------------------------------
Himmelsturm_4_024:
	.byte	W23
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		N72   , Fs2 , v076
	.byte	W72
	.byte	PEND
@ 025   ----------------------------------------
Himmelsturm_4_025:
	.byte	W12
	.byte		TIE   , Gs2 , v076
	.byte	W84
	.byte	PEND
@ 026   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N72   , An2 
	.byte	W72
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_025
@ 028   ----------------------------------------
	.byte	W24
	.byte		EOT   , Gs2 
	.byte		N72   , Fs2 , v076
	.byte	W72
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_025
@ 030   ----------------------------------------
	.byte	W24
	.byte		EOT   , Gs2 
	.byte		N72   , An2 , v076
	.byte	W72
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_025
@ 032   ----------------------------------------
Himmelsturm_4_032:
	.byte	W23
	.byte		VOICE , 95
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v-30
	.byte	W01
	.byte	PEND
	.byte		EOT   , Gs2 
	.byte		N48   , Bn1 , v060
	.byte	W48
	.byte		N36   
	.byte	W24
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_017
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_018
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_019
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_020
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_017
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_018
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_019
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_024
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_025
@ 046   ----------------------------------------
	.byte	W24
	.byte		EOT   , Gs2 
	.byte		N72   , An2 , v076
	.byte	W72
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_025
@ 048   ----------------------------------------
	.byte	W24
	.byte		EOT   , Gs2 
	.byte		N72   , Fs2 , v076
	.byte	W72
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_025
@ 050   ----------------------------------------
	.byte	W24
	.byte		EOT   , Gs2 
	.byte		N72   , An2 , v076
	.byte	W72
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_025
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_032
	.byte		EOT   , Gs2 
	.byte		N48   , Bn1 , v060
	.byte	W48
	.byte		N36   
	.byte	W24
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_017
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_018
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_019
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_020
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_017
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_018
@ 059   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_019
@ 060   ----------------------------------------
	.byte	W23
	.byte		VOICE , 24
	.byte	W01
	.byte		N96   , Fs4 , v040
	.byte	W72
@ 061   ----------------------------------------
	.byte	W24
	.byte		        An4 
	.byte	W72
@ 062   ----------------------------------------
Himmelsturm_4_062:
	.byte	W24
	.byte		TIE   , Gs4 , v040
	.byte	W72
	.byte	PEND
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N96   , Fs4 
	.byte	W72
@ 065   ----------------------------------------
	.byte	W24
	.byte		        An4 
	.byte	W72
@ 066   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_062
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W23
	.byte		VOICE , 95
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		EOT   , Gs4 
	.byte		N48   , Fs2 , v080
	.byte	W48
	.byte		        An2 
	.byte	W24
@ 069   ----------------------------------------
Himmelsturm_4_069:
	.byte	W24
	.byte		N48   , Gs2 , v080
	.byte	W48
	.byte		        An2 
	.byte	W24
	.byte	PEND
@ 070   ----------------------------------------
Himmelsturm_4_070:
	.byte	W24
	.byte		TIE   , En2 , v080
	.byte	W72
	.byte	PEND
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , Fs2 
	.byte	W48
	.byte		        An2 
	.byte	W24
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_069
@ 074   ----------------------------------------
	.byte	W24
	.byte		N96   , Gs2 , v080
	.byte	W72
@ 075   ----------------------------------------
	.byte	W24
	.byte		        En2 
	.byte	W72
@ 076   ----------------------------------------
Himmelsturm_4_076:
	.byte	W24
	.byte		N48   , Fs2 , v080
	.byte	W48
	.byte		        An2 
	.byte	W24
	.byte	PEND
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_069
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_070
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W24
	.byte		EOT   , En2 
	.byte		N48   , Fs2 , v080
	.byte	W48
	.byte		        An2 
	.byte	W24
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_069
@ 082   ----------------------------------------
	.byte	W24
	.byte		N96   , Bn2 , v080
	.byte	W72
@ 083   ----------------------------------------
	.byte	W24
	.byte		        Gs2 
	.byte	W72
@ 084   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_076
@ 085   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_069
@ 086   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_070
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W24
	.byte		EOT   , En2 
	.byte		N48   , Fs2 , v080
	.byte	W48
	.byte		        An2 
	.byte	W24
@ 089   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_069
@ 090   ----------------------------------------
	.byte	W24
	.byte		N96   , Bn2 , v080
	.byte	W72
@ 091   ----------------------------------------
	.byte	W24
	.byte		        Gs2 
	.byte	W72
@ 092   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_076
@ 093   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_069
@ 094   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_070
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	W24
	.byte		EOT   , En2 
	.byte		N48   , Fs2 , v080
	.byte	W48
	.byte		        An2 
	.byte	W24
@ 097   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_069
@ 098   ----------------------------------------
	.byte	W24
	.byte		N96   , Bn2 , v080
	.byte	W72
@ 099   ----------------------------------------
	.byte	W24
	.byte		        Gs2 
	.byte	W72
@ 100   ----------------------------------------
	.byte	W24
	.byte		N48   , Dn2 , v092
	.byte	W60
	.byte		N09   
	.byte	W12
@ 101   ----------------------------------------
Himmelsturm_4_101:
	.byte	W12
	.byte		TIE   , En2 , v092
	.byte	W84
	.byte	PEND
@ 102   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , Fs2 
	.byte	W60
	.byte		N09   
	.byte	W12
@ 103   ----------------------------------------
Himmelsturm_4_103:
	.byte	W12
	.byte		TIE   , Gs2 , v092
	.byte	W84
	.byte	PEND
@ 104   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , Dn2 
	.byte	W60
	.byte		N09   
	.byte	W12
@ 105   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_101
@ 106   ----------------------------------------
	.byte	W24
	.byte		EOT   , En2 
	.byte		N48   , Fs2 , v092
	.byte	W60
	.byte		N09   
	.byte	W12
@ 107   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_103
@ 108   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_032
	.byte		EOT   , Gs2 
	.byte		N48   , Bn1 , v060
	.byte	W48
	.byte		N36   
	.byte	W24
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_017
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_4_019
@ 112   ----------------------------------------
	.byte	W24
	.byte	FINE

@**************** Track 5 (Midi-Chn.5) ****************@

Himmelsturm_5:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W09
	.byte		VOICE , 95
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		MOD   , 45
	.byte		PAN   , c_v+63
	.byte	W01
	.byte	W12
	.byte		VOL   , 0*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		TIE   , Bn1 , v052
	.byte	W05
	.byte		VOL   , 2*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        2*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        6*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        8*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        11*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        14*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        16*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        19*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        22*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        25*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        28*Himmelsturm_mvl/mxv
	.byte	W04
@ 001   ----------------------------------------
	.byte	W02
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        33*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        36*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        39*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        42*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        45*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        53*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        64*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        67*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        70*Himmelsturm_mvl/mxv
	.byte	W06
@ 002   ----------------------------------------
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        81*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        85*Himmelsturm_mvl/mxv
	.byte	W68
	.byte	W02
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W23
	.byte		VOICE , 24
	.byte	W01
	.byte		EOT   
	.byte		N48   , An3 , v040
	.byte	W48
	.byte		TIE   , Cs4 
	.byte	W24
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn3 
	.byte	W72
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , An3 
	.byte	W48
	.byte		TIE   , Cs4 
	.byte	W24
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn3 
	.byte	W72
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 013   ----------------------------------------
	.byte	W60
	.byte	W01
	.byte		VOL   , 63*Himmelsturm_mvl/mxv
	.byte	W32
	.byte	W03
@ 014   ----------------------------------------
	.byte	W92
	.byte	W01
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W03
@ 015   ----------------------------------------
	.byte	W05
	.byte		        56*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        52*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        50*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        49*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        46*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        39*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        34*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        30*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        26*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        22*Himmelsturm_mvl/mxv
	.byte	W06
@ 016   ----------------------------------------
	.byte	W01
	.byte		        18*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        14*Himmelsturm_mvl/mxv
	.byte	W07
	.byte		        9*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		VOICE , 95
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+30
	.byte	W01
	.byte		EOT   
	.byte		TIE   , Dn2 , v060
	.byte	W72
@ 017   ----------------------------------------
Himmelsturm_5_017:
	.byte	W24
	.byte		VOL   , 76*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        79*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        79*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        78*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        77*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        77*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        76*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        75*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        75*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        75*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        74*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        74*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        74*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        74*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        74*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        73*Himmelsturm_mvl/mxv
	.byte	W08
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W10
	.byte		        70*Himmelsturm_mvl/mxv
	.byte	W05
	.byte		        68*Himmelsturm_mvl/mxv
	.byte	W03
	.byte	PEND
@ 018   ----------------------------------------
Himmelsturm_5_018:
	.byte	W01
	.byte		VOL   , 65*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        63*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W02
	.byte	PEND
	.byte		EOT   , Dn2 
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        35*Himmelsturm_mvl/mxv
	.byte		N72   , Gs1 , v060
	.byte	W02
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 019   ----------------------------------------
Himmelsturm_5_019:
	.byte	W02
	.byte		VOL   , 44*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        43*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		VOICE , 7
	.byte		VOL   , 72*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N48   , An2 , v060
	.byte	W48
	.byte		N12   , Cs3 
	.byte	W24
	.byte		N30   , An2 
	.byte	W12
	.byte	PEND
@ 020   ----------------------------------------
Himmelsturm_5_020:
	.byte	W23
	.byte		VOICE , 95
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+30
	.byte	W01
	.byte		TIE   , Dn2 , v060
	.byte	W72
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_018
	.byte		EOT   , Dn2 
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        35*Himmelsturm_mvl/mxv
	.byte		N72   , Gs1 , v060
	.byte	W02
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_019
@ 024   ----------------------------------------
Himmelsturm_5_024:
	.byte	W23
	.byte		VOICE , 95
	.byte		VOL   , 60*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+10
	.byte	W01
	.byte		N72   , Dn2 , v080
	.byte	W72
	.byte	PEND
@ 025   ----------------------------------------
Himmelsturm_5_025:
	.byte	W12
	.byte		TIE   , Bn1 , v080
	.byte	W84
	.byte	PEND
@ 026   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N72   , Dn2 
	.byte	W72
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_025
@ 028   ----------------------------------------
	.byte	W24
	.byte		EOT   , Bn1 
	.byte		N72   , Dn2 , v080
	.byte	W72
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_025
@ 030   ----------------------------------------
	.byte	W24
	.byte		EOT   , Bn1 
	.byte		N72   , Dn2 , v080
	.byte	W72
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_025
@ 032   ----------------------------------------
Himmelsturm_5_032:
	.byte	W23
	.byte		VOICE , 95
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+30
	.byte	W01
	.byte	PEND
	.byte		EOT   , Bn1 
	.byte		TIE   , Dn2 , v060
	.byte	W72
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_017
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_018
	.byte		EOT   , Dn2 
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        35*Himmelsturm_mvl/mxv
	.byte		N72   , Gs1 , v060
	.byte	W02
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_019
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_020
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_017
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_018
	.byte		EOT   , Dn2 
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        35*Himmelsturm_mvl/mxv
	.byte		N72   , Gs1 , v060
	.byte	W02
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_019
@ 040   ----------------------------------------
	.byte	W96
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_024
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_025
@ 046   ----------------------------------------
	.byte	W24
	.byte		EOT   , Bn1 
	.byte		N72   , Dn2 , v080
	.byte	W72
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_025
@ 048   ----------------------------------------
	.byte	W24
	.byte		EOT   , Bn1 
	.byte		N72   , Dn2 , v080
	.byte	W72
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_025
@ 050   ----------------------------------------
	.byte	W24
	.byte		EOT   , Bn1 
	.byte		N72   , Dn2 , v080
	.byte	W72
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_025
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_032
	.byte		EOT   , Bn1 
	.byte		TIE   , Dn2 , v060
	.byte	W72
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_017
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_018
	.byte		EOT   , Dn2 
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        35*Himmelsturm_mvl/mxv
	.byte		N72   , Gs1 , v060
	.byte	W02
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_019
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_020
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_017
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_018
	.byte		EOT   , Dn2 
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        35*Himmelsturm_mvl/mxv
	.byte		N72   , Gs1 , v060
	.byte	W02
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 059   ----------------------------------------
	.byte	W02
	.byte		        44*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        43*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        38*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		VOICE , 7
	.byte		VOL   , 72*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N36   , An2 
	.byte	W48
	.byte		N36   
	.byte	W36
@ 060   ----------------------------------------
	.byte	W23
	.byte		VOICE , 24
	.byte	W01
	.byte		N96   , Cs4 , v052
	.byte	W72
@ 061   ----------------------------------------
	.byte	W24
	.byte		        Fs4 
	.byte	W72
@ 062   ----------------------------------------
Himmelsturm_5_062:
	.byte	W24
	.byte		TIE   , Bn3 , v052
	.byte	W72
	.byte	PEND
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N96   , Cs4 
	.byte	W72
@ 065   ----------------------------------------
	.byte	W24
	.byte		        Fs4 
	.byte	W72
@ 066   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_062
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W23
	.byte		VOICE , 95
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		EOT   , Bn3 
	.byte		N48   , Cs2 , v080
	.byte	W48
	.byte		        Fs2 
	.byte	W24
@ 069   ----------------------------------------
Himmelsturm_5_069:
	.byte	W24
	.byte		N48   , En2 , v080
	.byte	W48
	.byte		        Fs2 
	.byte	W24
	.byte	PEND
@ 070   ----------------------------------------
Himmelsturm_5_070:
	.byte	W24
	.byte		TIE   , Cs2 , v080
	.byte	W72
	.byte	PEND
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   
	.byte	W48
	.byte		        Fs2 
	.byte	W24
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_069
@ 074   ----------------------------------------
	.byte	W24
	.byte		N96   , En2 , v080
	.byte	W72
@ 075   ----------------------------------------
	.byte	W24
	.byte		        Cs2 
	.byte	W72
@ 076   ----------------------------------------
Himmelsturm_5_076:
	.byte	W24
	.byte		N48   , Cs2 , v080
	.byte	W48
	.byte		        Fs2 
	.byte	W24
	.byte	PEND
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_069
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_070
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W24
	.byte		EOT   , Cs2 
	.byte		N48   , Cs2 , v080
	.byte	W48
	.byte		        Fs2 
	.byte	W24
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_069
@ 082   ----------------------------------------
	.byte	W24
	.byte		N96   , Gs2 , v080
	.byte	W72
@ 083   ----------------------------------------
	.byte	W24
	.byte		        En2 
	.byte	W72
@ 084   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_076
@ 085   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_069
@ 086   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_070
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W24
	.byte		EOT   , Cs2 
	.byte		N48   , Cs2 , v080
	.byte	W48
	.byte		        Fs2 
	.byte	W24
@ 089   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_069
@ 090   ----------------------------------------
	.byte	W24
	.byte		N96   , Gs2 , v080
	.byte	W72
@ 091   ----------------------------------------
	.byte	W24
	.byte		        En2 
	.byte	W72
@ 092   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_076
@ 093   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_069
@ 094   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_070
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	W24
	.byte		EOT   , Cs2 
	.byte		N48   , Cs2 , v080
	.byte	W48
	.byte		        Fs2 
	.byte	W24
@ 097   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_069
@ 098   ----------------------------------------
	.byte	W24
	.byte		N96   , Gs2 , v080
	.byte	W72
@ 099   ----------------------------------------
	.byte	W24
	.byte		        En2 
	.byte	W72
@ 100   ----------------------------------------
	.byte	W24
	.byte		N48   , An1 , v092
	.byte	W60
	.byte		N09   
	.byte	W12
@ 101   ----------------------------------------
	.byte		N06   , An1 , v060
	.byte	W12
	.byte		TIE   , Bn1 , v092
	.byte	W84
@ 102   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , Dn2 
	.byte	W60
	.byte		N09   
	.byte	W12
@ 103   ----------------------------------------
Himmelsturm_5_103:
	.byte	W12
	.byte		TIE   , En2 , v092
	.byte	W84
	.byte	PEND
@ 104   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , An1 
	.byte	W60
	.byte		N09   
	.byte	W12
@ 105   ----------------------------------------
	.byte	W12
	.byte		TIE   , Bn1 
	.byte	W84
@ 106   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N48   , Dn2 
	.byte	W60
	.byte		N09   
	.byte	W12
@ 107   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_103
@ 108   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_032
	.byte		EOT   , En2 
	.byte		TIE   , Dn2 , v060
	.byte	W72
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_017
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_018
	.byte		EOT   , Dn2 
	.byte		VOL   , 34*Himmelsturm_mvl/mxv
	.byte	W06
	.byte		        35*Himmelsturm_mvl/mxv
	.byte		N72   , Gs1 , v060
	.byte	W02
	.byte		VOL   , 40*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        47*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        54*Himmelsturm_mvl/mxv
	.byte	W02
	.byte		        61*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        72*Himmelsturm_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		        62*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        58*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        55*Himmelsturm_mvl/mxv
	.byte	W04
	.byte		        51*Himmelsturm_mvl/mxv
	.byte	W03
	.byte		        48*Himmelsturm_mvl/mxv
	.byte	W01
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_5_019
@ 112   ----------------------------------------
	.byte	W24
	.byte	FINE

@**************** Track 6 (Midi-Chn.6) ****************@

Himmelsturm_6:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 4
	.byte	W80
	.byte	W03
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W24
	.byte		TIE   , Fs3 , v060
	.byte	W72
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
Himmelsturm_6_012:
	.byte	W23
	.byte		VOICE , 70
	.byte		MOD   , 0
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+40
	.byte	W01
	.byte	PEND
	.byte		EOT   , Fs3 
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
@ 013   ----------------------------------------
Himmelsturm_6_013:
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		        Bn2 , v040
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte	PEND
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 016   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 017   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 018   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 019   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 020   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 024   ----------------------------------------
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		        Bn2 , v040
	.byte	W72
	.byte	W03
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
	.byte	W23
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 040   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 041   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 042   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 043   ----------------------------------------
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W01
@ 044   ----------------------------------------
Himmelsturm_6_044:
	.byte	W05
	.byte		PAN   , c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte	PEND
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 046   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 048   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 050   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 059   ----------------------------------------
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		        Bn2 , v040
	.byte	W02
	.byte		VOICE , 81
	.byte		MOD   , 3
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W01
@ 060   ----------------------------------------
	.byte	W05
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W07
	.byte		TIE   , An2 , v060
	.byte	W72
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn2 
	.byte	W72
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , An2 
	.byte	W72
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn2 
	.byte	W72
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_012
	.byte		EOT   , Bn2 
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
@ 069   ----------------------------------------
Himmelsturm_6_069:
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Cs4 , v060
	.byte	W03
	.byte		        Cs4 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Cs4 , v120
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte	PEND
@ 070   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 071   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 072   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 074   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 075   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 076   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 079   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 080   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 082   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 083   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_069
@ 084   ----------------------------------------
	.byte		N03   , Fs4 , v120
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Cs4 , v060
	.byte	W03
	.byte		        Cs4 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		VOICE , 81
	.byte		MOD   , 3
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		TIE   , An2 , v060
	.byte	W72
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn2 
	.byte	W72
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , An2 
	.byte	W72
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn2 
	.byte	W72
@ 091   ----------------------------------------
	.byte	W96
@ 092   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , An2 
	.byte	W72
@ 093   ----------------------------------------
	.byte	W96
@ 094   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn2 
	.byte	W72
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , An2 
	.byte	W72
@ 097   ----------------------------------------
	.byte	W96
@ 098   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Bn2 
	.byte	W72
@ 099   ----------------------------------------
	.byte	W96
@ 100   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_012
	.byte		EOT   , Bn2 
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Fs3 , v120
	.byte	W03
	.byte		        Fs3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
@ 101   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 102   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 103   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 104   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 105   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 106   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 107   ----------------------------------------
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		        Bn2 , v040
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v-40
	.byte	W06
	.byte		        c_v+40
	.byte	W01
@ 108   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_044
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_6_013
@ 112   ----------------------------------------
	.byte		N03   , Bn3 , v120
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , En3 , v072
	.byte	W03
	.byte		        En3 , v032
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		N02   , Fs3 , v060
	.byte	W03
	.byte		        Fs3 , v040
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		N02   , Bn2 , v060
	.byte	W03
	.byte		        Bn2 , v040
	.byte	W03
	.byte	FINE

@**************** Track 7 (Midi-Chn.7) ****************@

Himmelsturm_7:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W14
	.byte		VOICE , 53
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		MOD   , 0
	.byte	W80
	.byte	W01
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W23
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
@ 005   ----------------------------------------
Himmelsturm_7_005:
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Fs4 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		        c_v-63
	.byte	W01
	.byte		N04   , Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W13
	.byte		N12   , Bn3 , v100
	.byte	W23
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs3 
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 006   ----------------------------------------
Himmelsturm_7_006:
	.byte	W12
	.byte		N12   , Fs3 , v100
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		        c_v+0
	.byte	W01
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		        c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 007   ----------------------------------------
Himmelsturm_7_007:
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Fs4 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W13
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W17
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Fs4 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 008   ----------------------------------------
Himmelsturm_7_008:
	.byte	W12
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 009   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_005
@ 010   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_006
@ 011   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_007
@ 012   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_008
@ 013   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_005
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_006
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_007
@ 016   ----------------------------------------
	.byte	W12
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W12
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
@ 017   ----------------------------------------
Himmelsturm_7_017:
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Fs4 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn4 , v068
	.byte	W12
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 018   ----------------------------------------
Himmelsturm_7_018:
	.byte		N04   , Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W06
	.byte		N12   , Fs3 , v100
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W12
	.byte		N04   , Fs3 
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 019   ----------------------------------------
Himmelsturm_7_019:
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Fs4 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn4 , v068
	.byte	W12
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte	PEND
@ 020   ----------------------------------------
Himmelsturm_7_020:
	.byte		N04   , Fs4 , v080
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Fs3 , v100
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W12
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 026   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 030   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 031   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 040   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 041   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 042   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 043   ----------------------------------------
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn3 , v060
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        An3 , v068
	.byte	W24
	.byte		        En3 , v100
	.byte	W12
@ 044   ----------------------------------------
	.byte	W23
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W12
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 046   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 048   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 050   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 059   ----------------------------------------
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Fs4 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N12   , Fs4 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Fs4 , v060
	.byte	W23
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		        c_v+63
	.byte	W01
@ 060   ----------------------------------------
	.byte	W11
	.byte		        c_v+0
	.byte	W12
	.byte		VOL   , 66*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , An3 , v080
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , En3 , v100
	.byte	W06
	.byte		        En3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , An3 , v100
	.byte	W06
	.byte		        An3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
@ 061   ----------------------------------------
Himmelsturm_7_061:
	.byte		N04   , En3 , v100
	.byte	W06
	.byte		        En3 , v016
	.byte	W06
	.byte		N12   , An3 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , An3 , v072
	.byte	W06
	.byte		        An3 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , An3 , v072
	.byte	W06
	.byte		        An3 , v016
	.byte	W06
	.byte		N12   , An4 , v052
	.byte	W12
	.byte		N04   , An3 , v072
	.byte	W06
	.byte		        An3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 062   ----------------------------------------
Himmelsturm_7_062:
	.byte		N04   , En3 , v072
	.byte	W06
	.byte		        En3 , v016
	.byte	W06
	.byte		N12   , An3 , v080
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v080
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 063   ----------------------------------------
Himmelsturm_7_063:
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn3 , v060
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Bn3 , v072
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Bn3 , v072
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W06
	.byte		N12   , Bn4 , v052
	.byte	W12
	.byte		N04   , Bn3 , v072
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 064   ----------------------------------------
Himmelsturm_7_064:
	.byte		N04   , Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn3 , v080
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , An3 , v080
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , En3 , v100
	.byte	W06
	.byte		        En3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , An3 , v100
	.byte	W06
	.byte		        An3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 065   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_061
@ 066   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_062
@ 067   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_063
@ 068   ----------------------------------------
Himmelsturm_7_068:
	.byte		N04   , Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn3 , v080
	.byte	W11
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , An3 , v080
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , En3 , v100
	.byte	W06
	.byte		        En3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , An3 , v100
	.byte	W06
	.byte		        An3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , En4 , v100
	.byte	W06
	.byte		        En4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 069   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_061
@ 070   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_062
@ 071   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_063
@ 072   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_068
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_061
@ 074   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_062
@ 075   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_063
@ 076   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_068
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_061
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_062
@ 079   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_063
@ 080   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_064
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_061
@ 082   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_062
@ 083   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_063
@ 084   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_064
@ 085   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_061
@ 086   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_062
@ 087   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_063
@ 088   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_064
@ 089   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_061
@ 090   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_062
@ 091   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_063
@ 092   ----------------------------------------
	.byte		N04   , Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W06
	.byte		N12   , Bn3 , v080
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		        c_v-63
	.byte	W01
	.byte		N10   , Fs4 
	.byte	W23
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N10   
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N10   
	.byte	W12
@ 093   ----------------------------------------
Himmelsturm_7_093:
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N10   , Fs4 , v080
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N10   
	.byte	W23
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N10   
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N10   
	.byte	W12
	.byte	PEND
@ 094   ----------------------------------------
Himmelsturm_7_094:
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N10   , Cs4 , v080
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		        c_v-63
	.byte	W01
	.byte		N10   , Fs4 
	.byte	W23
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N10   
	.byte	W23
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N10   
	.byte	W12
	.byte	PEND
@ 095   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_093
@ 096   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_094
@ 097   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_093
@ 098   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_094
@ 099   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_093
@ 100   ----------------------------------------
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N10   , Cs4 , v080
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Fs4 , v100
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Bn3 , v100
	.byte	W12
	.byte		N04   , Bn2 
	.byte	W06
	.byte		        Bn2 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N04   , Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N04   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
@ 101   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 102   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 103   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 104   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 105   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 106   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 107   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 108   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_020
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_017
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_7_019
@ 112   ----------------------------------------
	.byte		N04   , Fs4 , v080
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , Fs3 , v100
	.byte	W12
	.byte	FINE

@**************** Track 8 (Midi-Chn.8) ****************@

Himmelsturm_8:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W15
	.byte		VOICE , 10
	.byte	W01
	.byte		MOD   , 100
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W08
	.byte		N05   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
@ 001   ----------------------------------------
Himmelsturm_8_001:
	.byte		N05   , Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v048
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte	PEND
@ 002   ----------------------------------------
Himmelsturm_8_002:
	.byte		N05   , En3 , v100
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte	PEND
@ 003   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_001
@ 004   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_002
@ 005   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_001
@ 006   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_002
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_001
@ 008   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_002
@ 009   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_001
@ 010   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_002
@ 011   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_001
@ 012   ----------------------------------------
	.byte		N05   , En3 , v100
	.byte	W06
	.byte		        En3 , v048
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W06
@ 013   ----------------------------------------
Himmelsturm_8_013:
	.byte		N05   , Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v028
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W06
	.byte		        Bn2 , v100
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte	PEND
@ 014   ----------------------------------------
Himmelsturm_8_014:
	.byte		N05   , En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W06
	.byte	PEND
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 016   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 017   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 018   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 019   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 020   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 024   ----------------------------------------
Himmelsturm_8_024:
	.byte		N05   , En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		        An2 , v048
	.byte	W78
	.byte	PEND
@ 025   ----------------------------------------
	.byte	W96
@ 026   ----------------------------------------
	.byte	W96
@ 027   ----------------------------------------
	.byte	W96
@ 028   ----------------------------------------
	.byte	W96
@ 029   ----------------------------------------
	.byte	W96
@ 030   ----------------------------------------
	.byte	W96
@ 031   ----------------------------------------
	.byte	W96
@ 032   ----------------------------------------
Himmelsturm_8_032:
	.byte	W24
	.byte		N05   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W06
	.byte	PEND
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 040   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_024
@ 041   ----------------------------------------
	.byte	W96
@ 042   ----------------------------------------
	.byte	W96
@ 043   ----------------------------------------
	.byte	W96
@ 044   ----------------------------------------
	.byte	W96
@ 045   ----------------------------------------
	.byte	W96
@ 046   ----------------------------------------
	.byte	W96
@ 047   ----------------------------------------
	.byte	W96
@ 048   ----------------------------------------
	.byte	W96
@ 049   ----------------------------------------
	.byte	W96
@ 050   ----------------------------------------
	.byte	W96
@ 051   ----------------------------------------
	.byte	W96
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_032
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 059   ----------------------------------------
	.byte		N05   , Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v028
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W05
	.byte		VOL   , 76*Himmelsturm_mvl/mxv
	.byte	W72
	.byte	W01
@ 060   ----------------------------------------
	.byte	W23
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Cs3 , v088
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v092
	.byte	W12
	.byte		        Cs4 , v028
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Fs4 , v092
	.byte	W12
	.byte		        Fs4 , v028
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v092
	.byte	W12
@ 061   ----------------------------------------
Himmelsturm_8_061:
	.byte		N03   , Cs4 , v028
	.byte	W10
	.byte		PAN   , c_v-20
	.byte	W02
	.byte		N03   , An4 , v092
	.byte	W12
	.byte		        An4 , v028
	.byte	W10
	.byte		PAN   , c_v+20
	.byte	W02
	.byte		N03   , Fs4 , v092
	.byte	W12
	.byte		        Fs4 , v028
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs5 , v092
	.byte	W12
	.byte		        Cs5 , v028
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , An4 , v092
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 062   ----------------------------------------
	.byte		N03   , En4 
	.byte	W12
	.byte		        En4 , v028
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Ds3 , v088
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Ds4 , v092
	.byte	W12
	.byte		        Ds4 , v028
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Gs4 , v092
	.byte	W12
	.byte		        Gs4 , v028
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Ds4 , v092
	.byte	W12
@ 063   ----------------------------------------
Himmelsturm_8_063:
	.byte		N03   , Ds4 , v028
	.byte	W10
	.byte		PAN   , c_v-20
	.byte	W02
	.byte		N03   , Bn4 , v092
	.byte	W12
	.byte		        Bn4 , v028
	.byte	W10
	.byte		PAN   , c_v+20
	.byte	W02
	.byte		N03   , Gs4 , v092
	.byte	W12
	.byte		        Gs4 , v028
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Ds5 , v092
	.byte	W12
	.byte		        Ds5 , v028
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Bn4 , v092
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 064   ----------------------------------------
	.byte		N03   , Fs4 
	.byte	W12
	.byte		        Fs4 , v028
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Cs3 , v088
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v092
	.byte	W12
	.byte		        Cs4 , v028
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Fs4 , v092
	.byte	W12
	.byte		        Fs4 , v028
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v092
	.byte	W12
@ 065   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_061
@ 066   ----------------------------------------
	.byte		N03   , En5 , v092
	.byte	W12
	.byte		        En5 , v028
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Ds3 , v088
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Ds4 , v092
	.byte	W12
	.byte		        Ds4 , v028
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Gs4 , v092
	.byte	W12
	.byte		        Gs4 , v028
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Ds4 , v092
	.byte	W12
@ 067   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_063
@ 068   ----------------------------------------
	.byte		N03   , Gs4 , v092
	.byte	W23
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N05   , Fs4 , v080
	.byte	W06
	.byte		        Fs4 , v028
	.byte	W06
	.byte		        Bn3 , v052
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N05   , Cs4 , v080
	.byte	W06
	.byte		        Cs4 , v028
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N05   , Bn3 , v080
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N05   , Cs4 , v052
	.byte	W06
	.byte		        Cs4 , v028
	.byte	W05
	.byte		PAN   , c_v-10
	.byte	W01
@ 069   ----------------------------------------
Himmelsturm_8_069:
	.byte		N05   , Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N05   , Fs4 , v080
	.byte	W06
	.byte		        Fs4 , v028
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N05   , Bn3 , v080
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W05
	.byte		PAN   , c_v-10
	.byte	W01
	.byte		N05   , Cs4 , v052
	.byte	W06
	.byte		        Cs4 , v028
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N05   , Fs3 , v080
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N05   , Bn3 , v052
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N05   , Cs4 , v080
	.byte	W06
	.byte		        Cs4 , v028
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte	PEND
@ 070   ----------------------------------------
Himmelsturm_8_070:
	.byte		N05   , Bn3 , v080
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N05   , Fs4 , v080
	.byte	W06
	.byte		        Fs4 , v028
	.byte	W06
	.byte		        Bn3 , v052
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N05   , Cs4 , v080
	.byte	W06
	.byte		        Cs4 , v028
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N05   , Bn3 , v080
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N05   , Cs4 , v052
	.byte	W06
	.byte		        Cs4 , v028
	.byte	W05
	.byte		PAN   , c_v-10
	.byte	W01
	.byte	PEND
@ 071   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_069
@ 072   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_070
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_069
@ 074   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_070
@ 075   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_069
@ 076   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_070
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_069
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_070
@ 079   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_069
@ 080   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_070
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_069
@ 082   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_070
@ 083   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_069
@ 084   ----------------------------------------
	.byte		N05   , Bn3 , v080
	.byte	W06
	.byte		        Bn3 , v028
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W05
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Cs3 , v108
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
@ 085   ----------------------------------------
Himmelsturm_8_085:
	.byte		N03   , Cs4 , v048
	.byte	W10
	.byte		PAN   , c_v-20
	.byte	W02
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W10
	.byte		PAN   , c_v+20
	.byte	W02
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte	PEND
@ 086   ----------------------------------------
Himmelsturm_8_086:
	.byte		N03   , Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Fs3 , v108
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte	PEND
@ 087   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_085
@ 088   ----------------------------------------
Himmelsturm_8_088:
	.byte		N03   , Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Cs3 , v108
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte	PEND
@ 089   ----------------------------------------
Himmelsturm_8_089:
	.byte		N03   , Cs4 , v048
	.byte	W10
	.byte		PAN   , c_v-20
	.byte	W02
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W10
	.byte		PAN   , c_v+20
	.byte	W02
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte	PEND
@ 090   ----------------------------------------
Himmelsturm_8_090:
	.byte		N03   , Cs4 , v048
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W11
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Fs3 , v108
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte	PEND
@ 091   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_089
@ 092   ----------------------------------------
	.byte		N03   , Cs4 , v048
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W11
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N03   , Cs3 , v108
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v048
	.byte	W11
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		N03   , Cs4 , v112
	.byte	W12
@ 093   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_085
@ 094   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_086
@ 095   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_085
@ 096   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_088
@ 097   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_089
@ 098   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_090
@ 099   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_089
@ 100   ----------------------------------------
	.byte		N03   , Cs4 , v048
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W84
@ 101   ----------------------------------------
	.byte	W96
@ 102   ----------------------------------------
	.byte	W96
@ 103   ----------------------------------------
	.byte	W96
@ 104   ----------------------------------------
	.byte	W96
@ 105   ----------------------------------------
	.byte	W96
@ 106   ----------------------------------------
	.byte	W96
@ 107   ----------------------------------------
	.byte	W96
@ 108   ----------------------------------------
	.byte	W23
	.byte		VOICE , 10
	.byte		MOD   , 100
	.byte		VOL   , 53*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N05   , Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v048
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Fs3 , v048
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		        Bn2 , v048
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        Fs3 , v028
	.byte	W06
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_014
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_8_013
@ 112   ----------------------------------------
	.byte		N05   , En3 , v100
	.byte	W06
	.byte		        En3 , v028
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		        An2 , v048
	.byte	W06
	.byte	FINE

@**************** Track 9 (Midi-Chn.9) ****************@

Himmelsturm_9:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W17
	.byte		VOICE , 127
	.byte		VOL   , 73*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W05
	.byte		        c_v+0
	.byte	W01
	.byte		N05   , Fs1 , v052
	.byte	W06
	.byte		N02   , Fs1 , v016
	.byte	W06
	.byte		N12   , En2 , v052
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W11
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
@ 001   ----------------------------------------
	.byte		N02   , Fs1 , v112
	.byte	W11
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W11
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
@ 002   ----------------------------------------
	.byte		N02   , Fs1 , v112
	.byte	W11
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N05   , Fs1 , v080
	.byte	W06
	.byte		N02   , Fs1 , v016
	.byte	W06
	.byte		N12   , En2 , v052
	.byte	W11
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W11
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
@ 003   ----------------------------------------
	.byte		N02   , Fs1 , v112
	.byte	W11
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W11
	.byte		PAN   , c_v-63
	.byte	W01
	.byte		N02   , Fs1 , v060
	.byte	W06
	.byte		        Fs1 , v016
	.byte	W05
	.byte		VOL   , 63*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N02   , Fs1 , v112
	.byte	W03
	.byte		        Fs1 , v016
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W06
	.byte		N12   , En2 , v060
	.byte	W12
@ 004   ----------------------------------------
	.byte		N02   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v012
	.byte	W06
	.byte		N12   , En2 , v060
	.byte	W11
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
@ 005   ----------------------------------------
Himmelsturm_9_005:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte	PEND
@ 006   ----------------------------------------
Himmelsturm_9_006:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W11
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte	PEND
@ 007   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 008   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 009   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 010   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 011   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 012   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 013   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 014   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 015   ----------------------------------------
Himmelsturm_9_015:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte	PEND
@ 016   ----------------------------------------
Himmelsturm_9_016:
	.byte		N12   , Ds2 , v072
	.byte	W12
	.byte		N12   
	.byte	W11
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte	PEND
@ 017   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 018   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 019   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 020   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 026   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 030   ----------------------------------------
Himmelsturm_9_030:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W11
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , Ds2 , v072
	.byte	W12
	.byte	PEND
@ 031   ----------------------------------------
Himmelsturm_9_031:
	.byte		N12   , Ds2 , v072
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte	PEND
@ 032   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_016
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 040   ----------------------------------------
Himmelsturm_9_040:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W11
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N08   , Gs1 , v092
	.byte	W09
	.byte		N02   , Fs1 , v032
	.byte	W03
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte	PEND
@ 041   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_015
@ 042   ----------------------------------------
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W05
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N08   , Gs1 , v092
	.byte	W09
	.byte		N02   , Fs1 , v032
	.byte	W03
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
@ 043   ----------------------------------------
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W12
	.byte		N12   , En2 , v072
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
@ 044   ----------------------------------------
	.byte		N24   , Ds2 , v080
	.byte	W23
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 046   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 048   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 050   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_030
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_031
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_016
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_040
@ 059   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_015
@ 060   ----------------------------------------
Himmelsturm_9_060:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W30
	.byte		PAN   , c_v+0
	.byte	W36
	.byte		N02   , En2 , v012
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v016
	.byte	W03
	.byte	PEND
@ 061   ----------------------------------------
Himmelsturm_9_061:
	.byte		N02   , En2 , v016
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v020
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v024
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v028
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v032
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v036
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v040
	.byte	W03
	.byte		        En2 , v044
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v048
	.byte	W03
	.byte		        En2 , v052
	.byte	W03
	.byte		        En2 , v056
	.byte	W03
	.byte		        En2 , v060
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v064
	.byte	W03
	.byte		        En2 , v076
	.byte	W03
	.byte		        En2 , v084
	.byte	W03
	.byte		        En2 , v088
	.byte	W03
	.byte		        En2 , v096
	.byte	W03
	.byte		        En2 , v100
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v096
	.byte	W03
	.byte		        En2 , v092
	.byte	W03
	.byte		        En2 , v088
	.byte	W03
	.byte	PEND
@ 062   ----------------------------------------
Himmelsturm_9_062:
	.byte		N02   , En2 , v084
	.byte	W03
	.byte		        En2 , v080
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v072
	.byte	W03
	.byte		        En2 , v068
	.byte	W03
	.byte		        En2 , v064
	.byte	W03
	.byte		        En2 , v056
	.byte	W03
	.byte		        En2 , v052
	.byte	W03
	.byte		        En2 , v048
	.byte	W03
	.byte		        En2 , v044
	.byte	W03
	.byte		        En2 , v036
	.byte	W03
	.byte		        En2 , v032
	.byte	W03
	.byte		        En2 , v028
	.byte	W03
	.byte		        En2 , v024
	.byte	W03
	.byte		        En2 , v016
	.byte	W03
	.byte		        En2 , v012
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N02   , En2 , v008
	.byte	W36
	.byte		        En2 , v012
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v016
	.byte	W03
	.byte	PEND
@ 063   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_061
@ 064   ----------------------------------------
Himmelsturm_9_064:
	.byte		N02   , En2 , v084
	.byte	W03
	.byte		        En2 , v080
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v072
	.byte	W03
	.byte		        En2 , v068
	.byte	W03
	.byte		        En2 , v064
	.byte	W03
	.byte		        En2 , v056
	.byte	W03
	.byte		        En2 , v052
	.byte	W03
	.byte		        En2 , v048
	.byte	W03
	.byte		        En2 , v044
	.byte	W03
	.byte		        En2 , v036
	.byte	W03
	.byte		        En2 , v032
	.byte	W03
	.byte		        En2 , v028
	.byte	W03
	.byte		        En2 , v024
	.byte	W03
	.byte		        En2 , v016
	.byte	W03
	.byte		        En2 , v012
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		N02   , En2 , v008
	.byte	W36
	.byte		        En2 , v012
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v016
	.byte	W03
	.byte	PEND
@ 065   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_061
@ 066   ----------------------------------------
	.byte		N02   , En2 , v084
	.byte	W03
	.byte		        En2 , v080
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v072
	.byte	W03
	.byte		        En2 , v068
	.byte	W03
	.byte		        En2 , v064
	.byte	W03
	.byte		        En2 , v056
	.byte	W03
	.byte		        En2 , v052
	.byte	W03
	.byte		        En2 , v048
	.byte	W03
	.byte		        En2 , v044
	.byte	W03
	.byte		        En2 , v036
	.byte	W03
	.byte		        En2 , v032
	.byte	W03
	.byte		        En2 , v028
	.byte	W03
	.byte		        En2 , v024
	.byte	W03
	.byte		        En2 , v016
	.byte	W03
	.byte		        En2 , v012
	.byte	W03
	.byte		        En2 , v008
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W24
@ 067   ----------------------------------------
	.byte	W24
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
@ 068   ----------------------------------------
	.byte		        Ds2 
	.byte	W12
	.byte		N12   
	.byte	W11
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N08   , Gs1 , v092
	.byte	W09
	.byte		N02   , Fs1 , v032
	.byte	W03
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
@ 069   ----------------------------------------
Himmelsturm_9_069:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte	PEND
@ 070   ----------------------------------------
Himmelsturm_9_070:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N06   , En2 , v072
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W05
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N08   , Gs1 , v092
	.byte	W09
	.byte		N02   , Fs1 , v032
	.byte	W03
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte	PEND
@ 071   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_069
@ 072   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_070
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_069
@ 074   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_070
@ 075   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_069
@ 076   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_070
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_069
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_070
@ 079   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_069
@ 080   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_070
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_069
@ 082   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_070
@ 083   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_069
@ 084   ----------------------------------------
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N06   , En2 , v072
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W05
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N08   , Gs1 , v092
	.byte	W09
	.byte		N02   , Fs1 , v032
	.byte	W03
	.byte		        Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
@ 085   ----------------------------------------
Himmelsturm_9_085:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N08   , Gs1 , v092
	.byte	W09
	.byte		N02   , Fs1 , v032
	.byte	W03
	.byte		        Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte	PEND
@ 086   ----------------------------------------
Himmelsturm_9_086:
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W05
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N08   , Gs1 , v092
	.byte	W09
	.byte		N02   , Fs1 , v032
	.byte	W03
	.byte		        Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte	PEND
@ 087   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_085
@ 088   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_086
@ 089   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_085
@ 090   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_086
@ 091   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_085
@ 092   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_060
@ 093   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_061
@ 094   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_062
@ 095   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_061
@ 096   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_064
@ 097   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_061
@ 098   ----------------------------------------
	.byte		N02   , En2 , v084
	.byte	W03
	.byte		        En2 , v080
	.byte	W03
	.byte		N02   
	.byte	W03
	.byte		        En2 , v072
	.byte	W03
	.byte		        En2 , v068
	.byte	W03
	.byte		        En2 , v064
	.byte	W03
	.byte		        En2 , v056
	.byte	W03
	.byte		        En2 , v052
	.byte	W03
	.byte		        En2 , v048
	.byte	W03
	.byte		        En2 , v044
	.byte	W03
	.byte		        En2 , v036
	.byte	W03
	.byte		        En2 , v032
	.byte	W03
	.byte		        En2 , v028
	.byte	W03
	.byte		        En2 , v024
	.byte	W03
	.byte		        En2 , v016
	.byte	W03
	.byte		        En2 , v012
	.byte	W03
	.byte		        En2 , v008
	.byte	W23
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
@ 099   ----------------------------------------
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W12
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W12
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
@ 100   ----------------------------------------
	.byte		N24   , Ds2 , v080
	.byte	W23
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W06
	.byte		N03   , Ds2 , v032
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
@ 101   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 102   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 103   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 104   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 105   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 106   ----------------------------------------
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W11
	.byte		VOL   , 50*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W01
@ 107   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_031
@ 108   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_016
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_006
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_9_005
@ 112   ----------------------------------------
	.byte		N02   , Gs1 , v092
	.byte	W03
	.byte		        Fs1 , v032
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N12   , En2 , v072
	.byte	W12
	.byte	FINE

@**************** Track 10 (Midi-Chn.10) ****************@

Himmelsturm_10:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W18
	.byte		VOICE , 93
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		MOD   , 2
	.byte		PAN   , c_v+0
	.byte	W76
	.byte	W01
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W23
	.byte		VOICE , 32
	.byte	W72
	.byte	W01
@ 004   ----------------------------------------
	.byte	W24
	.byte		TIE   , Bn2 , v127
	.byte	W72
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 013   ----------------------------------------
	.byte	W96
@ 014   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   
	.byte	W72
@ 015   ----------------------------------------
	.byte	W96
@ 016   ----------------------------------------
	.byte	W23
	.byte		VOICE , 37
	.byte	W01
	.byte		EOT   
	.byte		N10   
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
@ 017   ----------------------------------------
Himmelsturm_10_017:
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		N12   , An2 , v127
	.byte	W12
	.byte		N06   , An2 , v072
	.byte	W12
	.byte		        An2 , v127
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		        An2 , v127
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		        An2 , v127
	.byte	W12
	.byte	PEND
@ 018   ----------------------------------------
Himmelsturm_10_018:
	.byte		N06   , An2 , v072
	.byte	W12
	.byte		N12   , Gs2 , v127
	.byte	W12
	.byte		N04   , Gs2 , v072
	.byte	W12
	.byte		N06   , Gs2 , v127
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W12
	.byte		        Gs2 , v127
	.byte	W12
	.byte		        Gs2 , v072
	.byte	W12
	.byte		        Gs2 , v127
	.byte	W12
	.byte	PEND
@ 019   ----------------------------------------
Himmelsturm_10_019:
	.byte		N06   , Gs2 , v072
	.byte	W12
	.byte		N12   , An2 , v127
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte		N04   , Cs2 , v127
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		N04   , En2 , v127
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Cs3 , v072
	.byte	W06
	.byte	PEND
@ 020   ----------------------------------------
Himmelsturm_10_020:
	.byte		N24   , An2 , v127
	.byte	W24
	.byte		N10   , Bn2 
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_019
@ 024   ----------------------------------------
Himmelsturm_10_024:
	.byte		N24   , An2 , v127
	.byte	W24
	.byte		N10   , Bn2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte	PEND
@ 025   ----------------------------------------
Himmelsturm_10_025:
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		N10   , En2 , v127
	.byte	W12
	.byte		N06   , En2 , v072
	.byte	W12
	.byte		        En3 , v127
	.byte	W12
	.byte		        En2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte		        Bn1 , v072
	.byte	W12
	.byte		        En2 , v127
	.byte	W12
	.byte	PEND
@ 026   ----------------------------------------
Himmelsturm_10_026:
	.byte		N04   , Bn1 , v127
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v072
	.byte	W06
	.byte		N04   , Dn2 , v127
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte		        Dn2 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte	PEND
@ 027   ----------------------------------------
Himmelsturm_10_027:
	.byte		N04   , Dn2 , v072
	.byte	W12
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte		N04   , En2 , v127
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cs2 , v072
	.byte	W06
	.byte		N04   , Cs2 , v127
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte		N04   , En2 , v127
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Cs3 , v072
	.byte	W06
	.byte	PEND
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_024
@ 029   ----------------------------------------
Himmelsturm_10_029:
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		        En2 , v127
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte		N04   , En2 , v127
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        En3 , v072
	.byte	W06
	.byte		N04   , En2 , v127
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		N04   , En2 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte	PEND
@ 030   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_026
@ 031   ----------------------------------------
Himmelsturm_10_031:
	.byte		N04   , Dn2 , v072
	.byte	W12
	.byte		N12   , En3 , v127
	.byte	W12
	.byte		N01   , Fs2 , v072
	.byte	W12
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		N01   , Fs2 , v072
	.byte	W12
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		N01   , Fs2 , v072
	.byte	W12
	.byte		N12   , An2 , v127
	.byte	W12
	.byte	PEND
@ 032   ----------------------------------------
Himmelsturm_10_032:
	.byte		N06   , Fs2 , v127
	.byte	W06
	.byte		        Fs2 , v092
	.byte	W06
	.byte		N12   , An2 , v127
	.byte	W12
	.byte		N10   , Bn2 
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte	PEND
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_017
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_018
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_019
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_020
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_017
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_018
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_019
@ 040   ----------------------------------------
	.byte		N24   , An2 , v127
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W11
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N01   , Bn2 , v032
	.byte	W09
	.byte		N03   , Fs2 , v127
	.byte	W03
	.byte		N01   , Fs2 , v032
	.byte	W09
	.byte		N12   , Bn2 , v127
	.byte	W12
@ 041   ----------------------------------------
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N01   , Fs2 , v032
	.byte	W08
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		N12   , Bn2 , v127
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N03   
	.byte	W03
	.byte		N01   , Bn2 , v032
	.byte	W09
	.byte		N12   , Fs2 , v127
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N01   , Fs2 , v032
	.byte	W09
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		N03   , En2 
	.byte	W03
	.byte		N01   , En2 , v032
	.byte	W09
	.byte		N12   , Fs2 , v127
	.byte	W12
@ 042   ----------------------------------------
	.byte		N24   , An2 
	.byte	W11
	.byte		BEND  , c_v-11
	.byte	W02
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W09
	.byte		N12   , Bn2 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N01   , Bn2 , v032
	.byte	W09
	.byte		N03   , Fs2 , v127
	.byte	W03
	.byte		N01   , Fs2 , v032
	.byte	W08
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		N12   , Bn2 , v127
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W09
@ 043   ----------------------------------------
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N01   , Fs2 , v032
	.byte	W08
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		N12   , Bn2 , v127
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W44
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W20
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-8
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v+0
	.byte	W09
@ 044   ----------------------------------------
	.byte	W24
	.byte		N10   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_025
@ 046   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_026
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_027
@ 048   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_024
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_029
@ 050   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_026
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_031
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_032
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_017
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_018
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_019
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_020
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_017
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_018
@ 059   ----------------------------------------
	.byte		N06   , Gs2 , v072
	.byte	W12
	.byte		N12   , An2 , v127
	.byte	W12
	.byte		N04   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		N04   , Cs2 , v127
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N04   , Cs2 
	.byte	W12
@ 060   ----------------------------------------
	.byte		N24   , An2 
	.byte	W23
	.byte		VOICE , 91
	.byte	W01
	.byte		TIE   , Dn2 
	.byte	W72
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , En2 
	.byte	W72
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , En2 
	.byte	W72
@ 067   ----------------------------------------
	.byte	W96
@ 068   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 069   ----------------------------------------
	.byte	W96
@ 070   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , En2 
	.byte	W72
@ 071   ----------------------------------------
	.byte	W96
@ 072   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 073   ----------------------------------------
	.byte	W96
@ 074   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , En2 
	.byte	W72
@ 075   ----------------------------------------
	.byte	W96
@ 076   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 077   ----------------------------------------
	.byte	W96
@ 078   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , En2 
	.byte	W72
@ 079   ----------------------------------------
	.byte	W96
@ 080   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 081   ----------------------------------------
	.byte	W96
@ 082   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , En2 
	.byte	W72
@ 083   ----------------------------------------
	.byte	W96
@ 084   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , En2 
	.byte	W72
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N96   , En2 
	.byte	W72
@ 091   ----------------------------------------
Himmelsturm_10_091:
	.byte	W24
	.byte		N48   , En2 , v127
	.byte	W48
	.byte		        Cs2 
	.byte	W24
	.byte	PEND
@ 092   ----------------------------------------
	.byte	W24
	.byte		TIE   , Bn1 
	.byte	W72
@ 093   ----------------------------------------
	.byte	W96
@ 094   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Cs2 
	.byte	W72
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		TIE   , Dn2 
	.byte	W72
@ 097   ----------------------------------------
	.byte	W96
@ 098   ----------------------------------------
	.byte	W24
	.byte		EOT   
	.byte		N96   , En2 
	.byte	W72
@ 099   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_091
@ 100   ----------------------------------------
	.byte	W23
	.byte		VOICE , 37
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte	W01
	.byte		N10   , Dn2 , v127
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
@ 101   ----------------------------------------
Himmelsturm_10_101:
	.byte		N06   , Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte	PEND
@ 102   ----------------------------------------
Himmelsturm_10_102:
	.byte		N06   , Dn3 , v072
	.byte	W12
	.byte		N10   , Dn3 , v127
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte		        Dn3 , v072
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte	PEND
@ 103   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_101
@ 104   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_102
@ 105   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_101
@ 106   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_102
@ 107   ----------------------------------------
	.byte		N06   , Dn3 , v072
	.byte	W12
	.byte		        En2 , v127
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte		N04   , En2 , v127
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cs2 , v072
	.byte	W06
	.byte		N04   , Cs2 , v127
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v072
	.byte	W06
	.byte		N04   , Dn2 , v127
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        An1 , v072
	.byte	W06
@ 108   ----------------------------------------
	.byte		        An2 , v127
	.byte	W06
	.byte		        An2 , v072
	.byte	W06
	.byte		N12   , An2 , v127
	.byte	W12
	.byte		N10   , Bn2 
	.byte	W12
	.byte		N10   
	.byte	W12
	.byte		N06   , Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
	.byte		        Bn2 , v072
	.byte	W12
	.byte		        Bn2 , v127
	.byte	W12
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_017
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_10_019
@ 112   ----------------------------------------
	.byte		N24   , An2 , v127
	.byte	W24
	.byte	FINE

@**************** Track 11 (Midi-Chn.11) ****************@

Himmelsturm_11:
	.byte	KEYSH , Himmelsturm_key+0
@ 000   ----------------------------------------
	.byte	W20
	.byte		VOL   , 85*Himmelsturm_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOICE , 127
	.byte	W72
	.byte	W03
@ 001   ----------------------------------------
	.byte	W96
@ 002   ----------------------------------------
	.byte	W96
@ 003   ----------------------------------------
	.byte	W96
@ 004   ----------------------------------------
	.byte	W96
@ 005   ----------------------------------------
	.byte	W96
@ 006   ----------------------------------------
	.byte	W96
@ 007   ----------------------------------------
	.byte	W96
@ 008   ----------------------------------------
	.byte	W96
@ 009   ----------------------------------------
	.byte	W96
@ 010   ----------------------------------------
	.byte	W96
@ 011   ----------------------------------------
	.byte	W96
@ 012   ----------------------------------------
	.byte	W24
	.byte		N03   , Cn1 , v120
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N03   
	.byte	W12
@ 013   ----------------------------------------
Himmelsturm_11_013:
	.byte		N03   , Dn1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte	PEND
@ 014   ----------------------------------------
	.byte		        Dn1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N03   
	.byte	W12
@ 015   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_013
@ 016   ----------------------------------------
	.byte		N03   , Dn1 , v120
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
@ 017   ----------------------------------------
Himmelsturm_11_017:
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 , v080
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte	PEND
@ 018   ----------------------------------------
Himmelsturm_11_018:
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		N06   , Gs4 , v080
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , An4 , v072
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte	PEND
@ 019   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 020   ----------------------------------------
Himmelsturm_11_020:
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		N06   , Fn3 , v120
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte	PEND
@ 021   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 022   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 023   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 024   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_020
@ 025   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 026   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 027   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 028   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_020
@ 029   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 030   ----------------------------------------
Himmelsturm_11_030:
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		N06   , Gs4 , v080
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , An4 , v072
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte	PEND
@ 031   ----------------------------------------
Himmelsturm_11_031:
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        An4 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Gs4 , v012
	.byte	W06
	.byte		        An4 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        An4 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W09
	.byte		        Dn1 , v016
	.byte	W03
	.byte		        Dn1 , v120
	.byte	W09
	.byte		        Dn1 , v016
	.byte	W03
	.byte	PEND
@ 032   ----------------------------------------
Himmelsturm_11_032:
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Dn1 , v052
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte	PEND
@ 033   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 034   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 035   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 036   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_020
@ 037   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 038   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 039   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 040   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_020
@ 041   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 042   ----------------------------------------
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		N06   , Gs4 , v080
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , An4 , v092
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N06   , Gs4 , v092
	.byte	W06
	.byte		N03   , Ds3 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
@ 043   ----------------------------------------
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W18
	.byte		        Dn1 
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        Gs4 , v080
	.byte	W12
	.byte		        An4 
	.byte	W12
@ 044   ----------------------------------------
	.byte		        Gs4 , v020
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
@ 045   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 046   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 047   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 048   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_020
@ 049   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 050   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_030
@ 051   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_031
@ 052   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_032
@ 053   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 054   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 055   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 056   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_020
@ 057   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 058   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 059   ----------------------------------------
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W21
	.byte		        Dn1 , v016
	.byte	W03
	.byte		        Dn1 , v120
	.byte	W24
	.byte		N03   
	.byte	W18
	.byte		        Gs4 , v012
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Gs4 , v012
	.byte	W06
@ 060   ----------------------------------------
	.byte		        An4 , v080
	.byte	W06
	.byte		        Fs2 , v008
	.byte	W03
	.byte		        Fs2 , v012
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fs2 , v028
	.byte	W03
	.byte		        Fs2 , v044
	.byte	W03
	.byte		        Fs2 , v072
	.byte	W03
	.byte		N06   , Fs2 , v088
	.byte	W72
@ 061   ----------------------------------------
	.byte	W96
@ 062   ----------------------------------------
	.byte	W96
@ 063   ----------------------------------------
	.byte	W96
@ 064   ----------------------------------------
	.byte	W96
@ 065   ----------------------------------------
	.byte	W96
@ 066   ----------------------------------------
	.byte	W96
@ 067   ----------------------------------------
	.byte	W24
	.byte		N03   , Cn1 , v120
	.byte	W06
	.byte		        Gs4 , v012
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		        Gs4 , v012
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        An4 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Dn1 , v032
	.byte	W06
@ 068   ----------------------------------------
	.byte		        Dn1 , v120
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , An4 , v092
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
@ 069   ----------------------------------------
Himmelsturm_11_069:
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , An4 , v092
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte	PEND
@ 070   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 071   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 072   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 073   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 074   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 075   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 076   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 077   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 078   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 079   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 080   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 081   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 082   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 083   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_069
@ 084   ----------------------------------------
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        Dn3 , v120
	.byte	W78
@ 085   ----------------------------------------
	.byte	W96
@ 086   ----------------------------------------
	.byte	W96
@ 087   ----------------------------------------
	.byte	W96
@ 088   ----------------------------------------
	.byte	W96
@ 089   ----------------------------------------
	.byte	W96
@ 090   ----------------------------------------
	.byte	W96
@ 091   ----------------------------------------
	.byte	W96
@ 092   ----------------------------------------
	.byte	W96
@ 093   ----------------------------------------
	.byte	W96
@ 094   ----------------------------------------
	.byte	W96
@ 095   ----------------------------------------
	.byte	W96
@ 096   ----------------------------------------
	.byte	W96
@ 097   ----------------------------------------
	.byte	W96
@ 098   ----------------------------------------
	.byte	W96
@ 099   ----------------------------------------
	.byte	W96
@ 100   ----------------------------------------
	.byte	W24
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v080
	.byte	W06
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte		N03   , En3 , v080
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W12
	.byte		        Dn3 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
@ 101   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 102   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 103   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 104   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_020
@ 105   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 106   ----------------------------------------
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		N06   , Gs4 , v080
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte	W18
	.byte		N06   , An4 , v072
	.byte	W60
@ 107   ----------------------------------------
	.byte	W12
	.byte		N03   , An4 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Gs4 , v012
	.byte	W06
	.byte		        An4 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        An4 , v080
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W09
	.byte		        Dn1 , v016
	.byte	W03
	.byte		        Dn1 , v120
	.byte	W09
	.byte		        Dn1 , v016
	.byte	W03
@ 108   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_032
@ 109   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 110   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_018
@ 111   ----------------------------------------
	.byte	PATT
	 .word	Himmelsturm_11_017
@ 112   ----------------------------------------
	.byte		N03   , Dn1 , v120
	.byte	W06
	.byte		        Ds3 , v072
	.byte	W06
	.byte		N06   , Fn3 , v120
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

Himmelsturm:
	.byte	11	@ NumTrks
	.byte	0	@ NumBlks
	.byte	Himmelsturm_pri	@ Priority
	.byte	Himmelsturm_rev	@ Reverb.

	.word	Himmelsturm_grp

	.word	Himmelsturm_1
	.word	Himmelsturm_2
	.word	Himmelsturm_3
	.word	Himmelsturm_4
	.word	Himmelsturm_5
	.word	Himmelsturm_6
	.word	Himmelsturm_7
	.word	Himmelsturm_8
	.word	Himmelsturm_9
	.word	Himmelsturm_10
	.word	Himmelsturm_11

	.end
