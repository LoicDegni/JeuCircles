#ifndef TIME_F
#define TIME_F

#include "animation.h"
#include "sdl2.h"
#include <time.h>


// --------------- //
// Data structures //
// --------------- //
struct time {
    int play_time;
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

#endif
