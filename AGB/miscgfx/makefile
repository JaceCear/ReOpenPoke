LANGUAGE=de-de

FOURBPP		:=	hopshadow.png morearrow.png cardbg.png selectmove.png 		\
			outro_danny.png outro_dani.png

FOURWPAL	:=	frame.png uiframe.png helpbar.png badges.png newbtlwins.png	\
			\
			ball1.png ball2.png ball4.png ball5.png ball6.png ball7.png 	\
			ball8.png ball9.png ball10.png ball11.png ball12.png 		\
			\
			boxbg01.png boxbg02.png boxbg03.png boxbg04.png boxbg05.png 	\
			boxbg06.png boxbg07.png boxbg08.png boxbg09.png boxbg10.png 	\
			boxbg15.png boxhand.png boxselwin.png				\
			\
			dannyback.png daniback.png					\
			maleBag.png femaleBag.png					\
			demoback.png							\
			\
			emoticons.png fog.png sandstorm.png grasswalk.png healscrn.png	\
			reflectedclouds.png surf.png					\
			\
			intro_cearn.png intro_dani.png intro_danny.png intro_dark.png 	\
			intro_kawa.png intro_suka.png intro_van.png			\
			\
			hpbar.png types.png markings.png btlstatus.png	\
			partyboxes.png partyballs.png helditem.png \
			\
			welc_dani.png welc_danny.png welc_kawa.png welc_rival.png	\
			shirtcolors.png	pkball.png					\
			\
			titlecardcorner.png titleflavor.png titleparticles.png		\
			titletexts.png							\
			\
			gearbuttons.png mapicons.png spinner.png

FOURWPALMAP	:=	genericback.png							\
			blackcreds.png titleback.png titlelogo.png			\
			battleinterface.png battlegrass.png battlegym.png		\
			battlewater.png							\
			boxbg.png boxui.png						\
			card.png card2.png						\
			cavewarp.png							\
			dexlist.png dexinfo1.png dexfilter.png			\
			gear.png gearphone.png						\
			intro_bg1.png intro_bg2.png 					\
			inventory.png							\
			letterback.png letterbox.png					\
			openingletter.png						\
			shop.png							\
			signbox.png speechbox.png					\
			pokestatus_.png useitem.png						\
			welc_back.png

FOURWMAPONLY	:=	titlemon.png intro_m7sky.png intro_m7clouds.png evo_bg1.png evo_bg2.png

FOURWPAL_C := mapedges.png 

EIGHTWPALMAP_C	:= worldmap.png clock.png titlecard.png

SPECIALS	:= intro_m7ground.png

PNGFILES	:= $(FOURBPP) $(FOURWPAL) $(FOURWMAP) $(FOURWPALMAP) $(FOURWMAPONLY) $(FOURWPAL_C) $(EIGHTWPALMAP_C) $(SPECIALS)
OFILES		:= $(PNGFILES:.png=.o)
TARGET		:= ../miscgfx.a

GRITBASE	:= -fts -fh! -gu16

include ../gfx_baserules

# ---------------------------------------------------------------------
# Rules
# ---------------------------------------------------------------------

$(FOURBPP:.png=.s) : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB4 -p!

$(FOURWPAL:.png=.s) : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB4 -p

$(FOURWMAP:.png=.s) : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB4 -p! -mRtf

$(FOURWPALMAP:.png=.s) : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB4 -p -mRtf

$(FOURWMAPONLY:.png=.s) : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB4 -p! -mRtf

$(FOURWPAL_C:.png=.s) : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB4 -gzl -p

# No 'p' here - no per-tile palette, causes glitch tiles.
$(EIGHTWPALMAP_C:.png=.s) : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB8 -gzl -p -mRtf -mzl

# ---------------------------------------------------------------------
# Special cases
# ---------------------------------------------------------------------

intro_m7ground.s : %.s : %.png
	$(GRIT) $< $(GRITBASE) -gB8 -pe32 -mRa -mLa
