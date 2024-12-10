#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <stdio.h>
#include "sdl2.h"
#include "constants.h"
#include "player.h"
#include "obstacle.h"

/**
 * Affichage du background
 *
 * @param1: le renderer utilisé
 */
int background_display(SDL_Renderer *);

/**
 * Affichage du cercle au centre
 *
 * @param1: le renderer utilisé
 */
int centre_display(SDL_Renderer *);
#endif
