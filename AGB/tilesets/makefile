#
# Making graphics.
#

PNGFILES	:= $(wildcard *.png)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../tileset.a

include ../gfx_baserules

%.s : %.png
	$(GRIT) $< -fts -fh! -gu16 -gzl -gB4
