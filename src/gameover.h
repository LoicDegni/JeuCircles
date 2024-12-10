#ifndef GAMEOVER_H
#define GAMEOVER_H

#include "time.h"
#include "sdl2.h"
#include "spritesheet.h"
#include "play.h"

// -------------- //
// Data structure //
// -------------- //

enum game_over_state {
    GAME_OVER_ON,
    GAME_OVER_OFF
};

struct game_over {
    struct time *time;
    struct play *play;
    enum game_over_state state;
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
struct game_over *game_over_initialize(struct play *play);


/**
 * Affiche l'ecran de fin de jeu
 *
 * @param struct game_over
 */
void game_over_display(struct game_over *g);


/**
 * Lance l'etat de fin de jeu
 *
 * @param struct game_over
 */
void game_over_run(struct game_over *g);

/**
 * Supprime l'objet game over
 *
 * @param struct game_over
 */
void game_over_delete(struct game_over *g);

/**
 * Verifie un pointeur game_over
 *
 * @param struct game_over
 */
void abort_game_over(struct game_over *g);




#endif
