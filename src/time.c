#include "time.h"

struct time *time_initialize() {
   struct time* time = malloc(sizeof(struct time));
   time->app_start_time = SDL_GetTicks();
   time->play_time = 0;
   return time;
}

void time_variation(struct time *t) {
    t->play_time = (t->app_start_time - SDL_GetTicks() )/1000;
}
