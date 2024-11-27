#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "sdl2.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct obstacle {
   int rayon;
};

/**
 * Creer un obstacle
 */
struct obstacle obstacle_initialize(int);

int obstacle_display(SDL_Renderer *, struct obstacle*);

#endif
