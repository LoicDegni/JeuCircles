#ifndef PLAY_H
#define PLAY_H

#include <time.h>
#include "sdl2.h"
#include "constants.h"
#include "background.h"
#include "animation.h"
#include "time.h"

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
    SDL_Renderer *renderer;
};

// ---------- //
// Functions  //
// ---------- //

int counter_setting(enum difficulty);
int obstacle_movement(enum difficulty);
struct play *play_initialize(SDL_Renderer *, enum difficulty);
void play_run(struct play *);


#endif
