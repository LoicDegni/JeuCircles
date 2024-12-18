#ifndef MUSIC_H
#define MUSIC_H

#include <stdio.h>
#include "sdl2.h"

int music_initialisation();

int music_play(Mix_Music *music);

Mix_Music *music_load();

int music_delete(Mix_Music *);

#endif
