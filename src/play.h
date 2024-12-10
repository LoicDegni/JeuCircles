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

bool collision(struct player *, file *);
int counter_setting(enum difficulty);
int obstacle_movement(enum difficulty);
struct play *play_initialize(SDL_Renderer *, enum difficulty);
void play_run(struct play *);

/** 
 * Verifie que le pointeur n'est pas NUL
 * @param  struct play
 */
void abort_play(struct play*);


#endif
