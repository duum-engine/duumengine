#CSRC specifies which files we need to compile
#engine components, just for clarity sake

RENDER = engine/source/renderer/init.c

RUNTIME = engine/source/runtime/main.c \
engine/source/runtime/clean.c

EVENT = engine/source/event/event.c

LOG = engine/source/log/log.c \
engine/source/log/init.c

CSRC = $(RENDER) $(RUNTIME) $(EVENT) $(LOG)


#LCC is our linux compiler
LCC = gcc

#WCC is our windows compiler
WCC = x86_64-w64-mingw32-gcc-win32

#LCFLAGS are our compile time flags for linux
LCFLAGS = -lm -lSDL2 -lSDL2_image -lSDL2_ttf -Werror


#WCFLAGS are our compile time flags for windows
WCFLAGS = -lmingw32 -lm -mwindows -Ilibs/ -Llibs/SDL2/ -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -static-libgcc -static-libstdc++ -Werror 

#i dont know what these do, they appear to "support" the compilation
WSFLAGS = -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid 



a.out :
	$(LCC) $(CSRC) $(LCFLAGS)

a.exe :
	$(WCC) $(CSRC) $(WCFLAGS) $(WSFLAGS)
