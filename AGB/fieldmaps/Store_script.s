	.include "scriptdefs.s"
	.section .rodata
	.align 0
	.global Store_Shopkeep_Script

@ -------------------------------------
@ Shopkeep
@ -------------------------------------
Store_Shopkeep_Script:
	.byte FACEPLAYER
	.byte DOSHOP
	 .word Store_Shopkeep_MyShop @ inventory
	.byte END
	.align 4
Store_Shopkeep_MyShop:

	.short 0x0004, 0x000D, 0x0045, 0x0000

