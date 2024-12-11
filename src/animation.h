#ifndef ANIMATION_H
#define ANIMATION_H

#include "player.h"
#include "obstacle.h"
#include "difficulty.h"

/**
 * Gere l'animation du joueur selon la touche appuyée.
 * 
 * @param1: la structure du joueur
 * @param2: le event dans la file d'event
 */
void player_animation(struct player *, SDL_Event);

/**
 * Gere  l'evolution des obstacles
 *
 * @param1: la file d'obstacle du jeu
 * @param2: la vitesse de déplacement selon la difficulté de la partie
 */
void obstacle_animation(file *Obstacles, int);

#endif
