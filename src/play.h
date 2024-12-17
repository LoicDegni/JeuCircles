#ifndef PLAY_H
#define PLAY_H

#include <time.h>
#include "sdl2.h"
#include "constants.h"
#include "background.h"
#include "animation.h"
#include "time.h"
#include "gameover.h"

// --------------- //
// Data structures //
// --------------- //

enum play_state {
    PLAY_ALIVE,
    PLAY_LOST,
    PLAY_QUIT
};

struct play {
    enum play_state state;
    enum difficulty difficulty;
    struct player *player;
    file *Obstacles;
    struct time *time;
    int counter;
    struct game_over *game_over;
    SDL_Renderer *renderer;
};

// ---------- //
// Functions  //
// ---------- //

/**
 * Renvoie un boolean de si le joueur touche à un obstacle
 *
 * @param1: la structure du joueur
 * @param2: la file d'obstacles de la partie
 */
bool collision(struct player *, file *);

/**
 * Ajuste le compteur pour la vitesse d'apparition des obstacles dans la partie
 * selon la difficulté choisie.
 *
 * @param1: la difficulté choisie
 * @return: le nombre auquel le compteur doit se rendre avant qu'un nouvel
 *          obstacle apparaisse
 */
int counter_setting(enum difficulty);

/**
 * La vitesse à laquelle les obstacles vont bouger lors de la partie.
 *
 * @param1: la difficulté choisie
 */
int obstacle_movement(enum difficulty);

/**
 * Initialise la structure play.
 *
 * @param1: le renderer utilisé
 * @param2: la difficulté choisie
 */
struct play *play_initialize(SDL_Renderer *, enum difficulty);

/**
 * Gère le jeu lorsqu'il roule
 *
 * @param1: la structure play à utiliser
 */
void play_run(struct play *);

/**
 * Verifie si il y a une colision
 *
 * Compare la position de l'obstacle et du joueur
 *
 * @param struct play 
 */
void verif_colision(struct play *play);

/** 
 * Verifie que le pointeur n'est pas NUL
 * @param  struct play
 */
void abort_play(struct play*);

/**
 * Libère la mémoire de la structure play.
 */
void play_delete(struct play *);
#endif

