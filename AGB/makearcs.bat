
@REM Creates the neccessary GFX-archives
cd miscgfx

@REM Only change, if changed in main Makefile
@REM Else there might be confusion
set LANGUAGE=de-de

del *_.s
del *_.o
del *_.png

copy *_%LANGUAGE%.png *_bfr.png
rename *_bfr.png *_.png


@REM Clear the variable
set LANGUAGE=

cd ..\

make -f gfxmake
