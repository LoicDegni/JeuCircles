#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "sdl2.h"
#include "constants.h"
#include <stdio.h>


struct obstacle {
   int rayon;
};

/**
 * Creer un obstacle
 */
struct obstacle obstacle_initialize(int);

int obstacle_display(SDL_Renderer *renderer, struct obstacle);

#endif
