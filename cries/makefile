.SUFFIXES:

PATH	:= $(DEVKITARM)/bin:$(PATH)

CC		:= arm-none-eabi-gcc
AR		:= arm-none-eabi-ar

SFILES		:= $(wildcard *.s)
OFILES		:= $(SFILES:.s=.o)
TARGET		:= ../cries.a

# ---------------------------------------------------------------------
# Rules
# ---------------------------------------------------------------------

.PHONY : build clean

# build: $(TARGET)

$(TARGET) : $(OFILES)
	@echo Build $@
	@$(AR) -crs $@ $^

$(OFILES) : $(CFILES)

%.o : %.s
	@echo $< -\> $@
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	-rm $(CFILES) $(OFILES)
