#ifndef PLAY_H
#define PLAY_H

#include "sdl2.h"
#include "constants.h"
#include "background.h"
#include "player.h"

// --------------- //
// Data structures //
// --------------- //

enum play_state {
    PLAY_BEGIN,
    PLAY_ALIVE,
    PLAY_LOST
};

struct play {
    enum play_state state;
    SDL_Renderer *renderer;
};

// ---------- //
// Functions  //
// ---------- //

struct play *play_initialize(SDL_Renderer *renderer);

#endif
