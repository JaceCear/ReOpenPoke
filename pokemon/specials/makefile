UNOWNFB	:= $(wildcard unknown_*_frnt.png) $(wildcard unknown_*_back.png)
UNOWNPT	:= $(wildcard unknown_*_party.png)
EGGFB	:= egg.png
EGGPT	:= egg_party.png

PNGFILES	:= $(EGGFB) $(EGGPT) $(UNOWNFB) $(UNOWNPT)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../../specialmon.a

$(TARGET) : $(OFILES)
	$(AR) -crs $@ $^

GRITBASE	:= -fts -fh! -gu16

include ../../gfx_baserules

# ---------------------------------------------------------------------
# Rules
# ---------------------------------------------------------------------

$(UNOWNFB:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -gzl -p!

$(EGGFB:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -gzl -pe16

$(UNOWNPT:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p!

$(EGGPT:.png=.s): %.s : %.png
	$(GRIT) $< $(GRITBASE) -p!

