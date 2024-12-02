#ifndef TIME_F
#define TIME_F

#include "animation.h"
#include "sdl2.h"
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
   file *Obstacles;
};

// --------- //
// Fonctions //
// --------- //

struct time *time_initialize(file *Obstacles);
float time_variation();


#endif
