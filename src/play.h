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
    PLAY_BEGIN,
    PLAY_ALIVE,
    PLAY_LOST,
    PLAY_QUIT
};

struct play {
    enum play_state state;
    struct player *player;
    file *Obstacles;
    struct time *time;
    struct spritesheet *chrono;
    int compteur;
    SDL_Renderer *renderer;
};

// ---------- //
// Functions  //
// ---------- //

struct play *play_initialize(SDL_Renderer *);
void play_run(struct play *);

#endif
