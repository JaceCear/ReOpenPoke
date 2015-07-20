#include "../openpoke.h"

void ZeldaHomage()
{
	int spinDirection = 1, spinTimer = 1, plonk = 128 + 64;
	u8* thisPic;

	ClearSpriteGFX();
	LoadSpriteColors();
	OamBak[0].Pltt = 0;
	OamBak[0].CharNo = 0;
	OamBak[0].Size = 2;
	OamBak[0].Shape = 2;
	OamBak[0].VPos = 60;
	OamBak[0].HPos = 120 - 8;
	pal_bg_mem[0] = CLR_MAROON;
	sndPlaySound(77,0);

	REG_DISPCNT = DCNT_MODE0 | DCNT_OBJ | DCNT_OBJ_1D;
	REG_BLDCNT = 0;

	while(1)
	{
		DoVBlank();

		plonk--;
		if(plonk > 0)
		{
			if(plonk > 64)
			{
				spinTimer--;
				if(spinTimer == 0)
				{
					spinTimer=8;
					thisPic = (u8*)Sprites[Actors[0].sprite].spriteStart;
					switch(spinDirection)
					{
						case 0:
							break;
						case 1:
							thisPic += 0x200;
							break;
						case 2:
							thisPic += 0x100;
							break;
						case 3:
							thisPic += 0x200;
							break;
					}
					OamBak[0].HFlip = (spinDirection==3);
					CpuFastCopy(thisPic, (u16*)MEM_VRAM_OBJ, 0x100);
					spinDirection++;
					if(spinDirection==4)
						spinDirection = 0;
				}
			}
			else if(plonk == 64)
			{
				thisPic = (u8*)Sprites[Actors[0].sprite].spriteStart + 0xD00;
				CpuFastCopy(thisPic, (u16*)MEM_VRAM_OBJ, 0x100);
			}
		}
		else
		{
			break;
		}
	}

	ResetBackgrounds();
	ClearOamBak();
}
