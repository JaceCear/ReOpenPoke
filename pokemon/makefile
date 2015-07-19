POKEFB	:= $(wildcard mon*_frnt.png) $(wildcard mon*_back.png)
POKEPT	:= $(wildcard party-*.png)
POKEPR	:= $(wildcard print*.png)

PNGFILES	:= $(POKEPR) $(POKEFB) $(POKEPT)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../pokepics.a

$(TARGET) : $(OFILES)
	$(AR) -crs $@ $^

GRITBASE	:= -fts -fh! -gu16

include ../gfx_baserules

# ---------------------------------------------------------------------
# Rules
# ---------------------------------------------------------------------

$(POKEFB:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p -gzl

$(POKEPT:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p

$(POKEPR:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p! -gB1

