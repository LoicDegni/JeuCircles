#ifndef ANIMATION_H
#define ANIMATION_H

#include "player.h"
#include "obstacle.h"
#include "spritesheet.h"

void player_animation(struct player *, SDL_Event);

/**
 * Gere  l'evolution des obstacles
 */
void obstacle_animation(file *Obstacles);

#endif
