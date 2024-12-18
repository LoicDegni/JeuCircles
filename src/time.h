#ifndef TIME_F
#define TIME_F

#include "animation.h"
#include "sdl2.h"
#include "spritesheet.h"
#include <time.h>


// --------------- //
// Data structures //
// --------------- //

enum time_state {
    TIME_ON,
    TIME_OFF
};

struct time {
    enum time_state state;
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
struct time *time_initialize(SDL_Renderer *renderer);

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
void time_display(struct time* t);

/**
 * Affiche les dixiemes de seconde du chronometre
 *
 * @param d  dixieme
 */
void dixieme_display(const int d, struct time *t);

/**
 * Affiche les secondes du chronometre
 *
 * @param s  seconde
 */
void seconde_display(const int s, struct time *t);

/**
 * Affiche les minutes du chronometre
 *
 * @param m  minutes
 */
void minute_display(const int m, struct time *t);

/**
 * verifie si un pointeur struct time est valide
 *
 * @param t  pointeur
 */
void abort_time(struct time *t);

/**
 * Supprime un objet struct time
 *
 * @param t  objet struct time
 */
void time_delete(struct time *t);

#endif
