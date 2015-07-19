#
# Making graphics.
#

PNGFILES	:= $(wildcard *.png)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../trainerpics.a

include ../gfx_baserules

%.s : %.png
	$(GRIT) $< -fts -gu16 -gzl -fh! -strn$(basename $<)
