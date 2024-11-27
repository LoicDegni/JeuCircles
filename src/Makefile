
PREFIX = /opt/homebrew/Cellar
SDL2_INCLUDE = $(PREFIX)/sdl2/2.30.9/include
SDL2_LIB = $(PREFIX)/sdl2/2.30.9/lib
SDL2_IMAGE_INCLUDE = $(PREFIX)/sdl2_image/2.8.2_2/include
SDL2_IMAGE_LIB = $(PREFIX)/sdl2_image/2.8.2_2/lib
SDL2_GFX_INCLUDE = $(PREFIX)/sdl2_gfx/1.0.4/include
SDL2_GFX_LIB = $(PREFIX)/sdl2_gfx/1.0.4/lib


CC = gcc
OBJS = $(patsubst %.c,%.o,$(wildcard *.c))
CFLAGS = -Wall -Wextra `sdl2-config --cflags` -I$(SDL2_GFX_INCLUDE) -I$(SDL2_INCLUDE) -I$(SDL2_IMAGE_INCLUDE)
#CFLAGS = -Wall -Wextra `sdl2-config --cflags`
#LDFLAGS = -lSDL2_image -lSDL2_gfx `sdl2-config --libs`
LDFLAGS = -lSDL2_image -lSDL2_gfx `sdl2-config --libs` -L$(SDL2_GFX_LIB) -L$(SDL2_LIB) -L$(SDL2_IMAGE_LIB)
EXEC = circles

$(EXEC): $(OBJS)
	$(CC) $^ $(LDFLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

.PHONY: clean

clean:
	rm -f $(OBJS) $(EXEC)
