#ifndef TIME_F
#define TIME_F

#include "animation.h"
#include "sdl2.h"
#include <time.h>


// --------------- //
// Data structures //
// --------------- //
struct time {
    Uint32 app_start_time;
    int play_time;
    struct spritesheet *chrono;
};

// --------- //
// Fonctions //
// --------- //

/**
 * Initialise le temps en seconde a zero
 *
 * @return  la nouvelle structure time
 */
struct time *time_initialize();

/**
 * Met a jour le temp ecouler depuis le lancement du jeu
 *
 * @param  la structure time
 */
void time_variation(struct time* t);

/**
 * Met a jour l'affichage du temps de jeu dans le renderer
 *
 * @param  renderer de l'application
 * @param  la struct time
 */
void time_display(SDL_Renderer *renderer, struct time* t);

#endif
