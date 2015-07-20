
PATH	:= $(DEVKITARM)/bin:$(PATH)

CROSS	:= arm-none-eabi-

# To make things go
CC		:= $(CROSS)gcc	#agbcc
AS		:= $(CROSS)gcc	#agbas
LD		:= $(CROSS)gcc	#agbld
OBJCOPY	:= $(CROSS)objcopy

# --------------------------------------------------------------------
# FILES
# --------------------------------------------------------------------

TARGET	:= openpoke
TITLE	:= $(TARGET)

# some extra settings...
# set bDISABLEAGBPRINT to 1 if playing on hardware, no$ or vba17
bDISABLEAGBPRINT := 0

# Change as well in:
#	miscgfx/makefile
#	makearcs.bat
LANGUAGE = de-de

# Regular makefile continues here
SFILES	:=	irq_single.s tonc_bios.s tonc_bios_sappy.s pal_blend.s		\
		testachu.s							\
		$(wildcard fieldmaps/*.s)

CFILES	:=	main.c pokedex/pokedex.c rtc.c text.c map16.c vwf.c multiplechoice.c	\
		startmenu.c trainercard.c townmap.c breeding.c			\
		judassystem.c judascommands.c judasdata.c judasspecials.c	\
		gear.c \
		printf.c timekeeper.c 						\
		\
		spritemanager.c	pokemanager.c itemmanager.c miscevents.c shop.c \
		help.c options.c partyscreen.c boxsystem.c  spinda.c		\
		\
		data/itemicons.c	\
		data/partyicons.c	\
		data/pokedata_evos.c	\
		data/pokedata_moves.c	\
		lang_$(LANGUAGE).c						\
		$(wildcard cutscenes/*.c)					\
		$(wildcard battleEngine/*.c)					\
		$(wildcard data/$(LANGUAGE)/*.c)			\
		$(wildcard data/*.s)						\
		$(wildcard fieldmaps/*.c)					\
		$(wildcard tilesets/*.c)					\
		$(wildcard tileanims/*.c)					\

SFILES	+=	stdscripts.s vwf_asm.s fontWestern.s fontSmall.s fontWide.s	\
		fontScream.s fontOam.s fontBraille.s fontJapanese.s

#ifeq ($(wildcard enginem4.a),)
#	CFILES	+=	snd_dummy.c
#else
	CFILES	+=	snd_enginem4.c				\
				$(wildcard enginem4/*.c)	\
				enginem4/Waves/SncBtl_MainGuitar.c
	SFILES	+=	$(wildcard enginem4/*.s)
#endif

ICFILES   :=	vwf.iwram.c

export AFILES	:= pokepics.a specialmon.a trainerpics.a itemicons.a ow_sprites.a miscgfx.a tileset.a tileanims.a
export ROFILES	:= $(SFILES:.s=.o) $(CFILES:.c=.o)
export IOFILES	:= $(ICFILES:.c=.o) $(MAPPACK)
export OFILES	:= $(ROFILES) $(IOFILES)

#ifeq ($(wildcard enginem4.a),)
#else
	OFILES	+=	enginem4.a enginem4_data.a cries.a
#endif

# --------------------------------------------------------------------
# OPTIONS
# --------------------------------------------------------------------

MAPFILE		:= $(TARGET).map


AGBINC	   =	$(AGBDIR)/include
AGBLIB	   =	$(AGBDIR)/lib

ARCH    := -mthumb-interwork -mthumb
RARCH   := -mthumb-interwork -mthumb
IARCH   := -mthumb-interwork -marm
SPECS   := -specs=gba.specs

INCLUDE		:= -I toolinclude
LIBPATHS	:=

CBASE   := $(INCLUDE) -O2 -Wall -fno-strict-aliasing
RCFLAGS := $(CBASE) $(RARCH)
ICFLAGS := $(CBASE) $(IARCH) -mlong-calls
CFLAGS  := $(RCFLAGS)

ASFLAGS := -x assembler-with-cpp -c -mthumb-interwork -Wall
LDFLAGS := $(ARCH) $(SPECS) $(LIBPATHS) $(LIBS)


LDFLAGS += -Wl,-Map $(MAPFILE)

# disable AGBPrint routines and associates if bDISABLEAGBPRINT is set
ifeq ($(bDISABLEAGBPRINT),1)
	RCFLAGS	+= -g -DNDEBUG
	ICFLAGS	+= -g -DNDEBUG
else
	OFILES += toolinclude/isagbprn.a
endif

# ---------------------------------------------------------------------
# RULES
# ---------------------------------------------------------------------

$(TARGET).gba : $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	@gbafix $@ -tOPENPOKE -cKOPN -mXX
#	arm-eabi-nm	-n -S $< > $(TARGET).nm


$(TARGET).elf : $(OFILES) $(AFILES) Makefile $(DEPENDFILE)
	@echo > $(MAPFILE)
	$(LD) -g -o $@ $(OFILES) $(AFILES) $(LDFLAGS)

.PHONY: all clean depend

all:    clean $(TARGET).elf

# clean:
# 	rm $(OFILES) $(DEPENDFILE) $(MAPFILE) $(TARGET).elf

depend:
	$(CC) $(RCFLAGS) -M $(RCFILES) > $(DEPENDFILE)
	$(CC) $(ICFLAGS) -M $(ICFILES) > $(DEPENDFILE)

$(DEPENDFILE): 
	$(CC) -S $(RCFLAGS) -M $(CFILES) $(ICFLAGS) $(ICFILES) > $(DEPENDFILE)


# --- IWRAM compilation ----
%.iwram.o : %.iwram.c
	$(CC) $(ICFLAGS) -c $< -o $@

# --- ROM compilation ---
%.o : %.c
	$(CC) $(RCFLAGS) -c $< -o $@

# --- Assembling ---
%.o : %.s
	$(AS) $(ASFLAGS) -c $< -o $@

#$(.IOFILES) : %.o : %.c
#	$(CC) $(ICFLAGS) -c $< -o $@
