POKEFB	:= $(wildcard front/mon*_frnt.png) $(wildcard back/mon*_back.png)
POKEPT	:= $(wildcard party/party-*.png)
POKEPR	:= $(wildcard footprints/print*.png)

PNGFILES	:= $(POKEPR) $(POKEFB) $(POKEPT)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../pokepics.a

$(TARGET) : $(OFILES)
	$(AR) -crs $@ $^

# GRIT parameters:
	# -fts:		Output as GNU ASM file
	# -fh!:		Don't create a file header
	# gu16:		Use u16 GFX data type
GRITBASE	:= -fts -fh! -gu16

include ../gfx_baserules

# ---------------------------------------------------------------------
# Rules
# ---------------------------------------------------------------------

# GRIT parameters:
	# -gB1:		Use 1-bit data format
	# -gzl:		Use LZ77 compression
	# -p:		Include Palette
	# -p!:		Don't include Palette
	# -o "$@":	Output files at respective folder

$(POKEFB:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p -gzl -o "$@"

$(POKEPT:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p -o "$@"

$(POKEPR:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p! -gB1 -o "$@"

