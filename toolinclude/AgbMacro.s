@********************************************************************
@*          AgbMacro.s                                              *
@*            AGB Standard Macro Functions (GAS)                    *
@*                                                                  *
@*          Copyright (C) 1999-2001 NINTENDO Co.,Ltd.               *
@********************************************************************


@--------------------------------------------------------------------
@-                      System Call                                 -
@--------------------------------------------------------------------

    .MACRO    SystemCall16 No
        swi \No
    .ENDM
    .MACRO    SystemCall32 No
        swi \No << 16
    .ENDM

    .MACRO    Halt                Bits    @ HALT
        SystemCall\Bits 2
    .ENDM
    .MACRO    Stop                Bits    @ STOP
        SystemCall\Bits 3
    .ENDM


