#ifndef PLAYER_H
#define PLAYER_H

#include "sdl2.h"
#include "constants.h"
#include <stdio.h>

struct player {
    int position;
    int cadran;
};


int cadran_position(int);

struct player *player_initialization();

#endif

