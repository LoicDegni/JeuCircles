#include "time.h"

struct time *time_initialize(file *Obstacles) {
   struct time* time = malloc(sizeof(struct time));
   time->state = TIME_ON;
   time->Obstacles = Obstacles;
   return time;
}

float time_variation() {
   static Uint32 last_tick;
   Uint32 current_tick = SDL_GetTicks();
   float delta_time = (current_tick - last_tick)/10.0f;
   last_tick = current_tick;
   return delta_time;
}
