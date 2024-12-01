#ifndef PLAY_H
#define PLAY_H

#include "sdl2.h"
#include "constants.h"
#include "background.h"
#include "animation.h"

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
    SDL_Renderer *renderer;
};

// ---------- //
// Functions  //
// ---------- //

struct play *play_initialize(SDL_Renderer *);
void play_run(struct play *);

#endif
