PNGFILES	:= $(wildcard *.png)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../itemicons.a

include ../gfx_baserules

%.s : %.png
	$(GRIT) $< -fts -fh! -gu16 -gzl
