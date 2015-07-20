#
# Making graphics.
#

PNGFILES	:= $(wildcard *.png)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../ow_sprites.a

include ../gfx_baserules

%.s : %.png
	$(GRIT) $< -fts -fh! -gu16 -p!
