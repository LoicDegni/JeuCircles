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

struct time *time_initialize();
void time_variation(struct time* t);
#endif
