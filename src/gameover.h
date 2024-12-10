#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "time.h"
#include "sdl2.h"
#include "spritesheet.h"

// -------------- //
// Data structure //
// -------------- //

struct game_stat {
    struct time *time;
    struct spritesheet *background;
    struct spritesheet *gameover_display;
    SDL_Renderer *renderer;
};


/**
 * Initialise les donnees de fin de jeu
 *
 * @param renderer affichage du jeu
 * @param time     temps de jeu
 *
 * @return struct game_stat
 */
struct game_stat *game_over_initialize(SDL_Renderer *renderer, struct time *t);


/**
 * Affiche l'ecran de fin de jeu
 *
 * @param struct game_stat
 */
void game_over_display(struct game_stat *g);




#endif
