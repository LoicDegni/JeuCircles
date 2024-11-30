#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "sdl2.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct obstacle {
   int rayon;
   int cadran;
};


/**
 * Creer un obstacle
 */
struct obstacle *obstacle_initialize(int);

/**
 * Affiche un obstacle
 */
int obstacle_display(SDL_Renderer *, struct obstacle*);

//Fonctions Auxiliaire
//--------------------

/**
 * Fourni une position aleatoire entre 1 et 6 de 
 * cadran pour l'obstacle
 */
int obstacle_cadran();

void obstacle_delete(struct obstacle*);
#endif
