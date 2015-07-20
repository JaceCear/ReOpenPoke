#
# Change older libs/objects to EABI format
#

PATH	:= C:/devkitpro/devkitARM:$(PATH)

FILES	:= $(wildcard *.o)

#$(DEVKITARM)\arm-none-eabi\bin\ar -r enginem4.a M4_Init.o M4_Intr.o M4_Main.o M4_Mixer.o M4_Data.o M4_Player.o M4_SFX.o M4_Track.o
$(PATH)\arm-none-eabi\bin\ar -r enginem4_data.a $(FILES)
