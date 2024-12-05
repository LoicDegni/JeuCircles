#include "time.h"

struct time *time_initialize(SDL_Renderer *renderer) {
   struct time* time = malloc(sizeof(struct time));
   time->state = TIME_ON;
   time->app_start_time = SDL_GetTicks();
   time->chrono = spritesheet_create(CHRONO_FILENAME, 1, 11, 11, renderer);
   time->play_time = 0;
   return time;
}

void time_variation(struct time *t) {
    t->play_time = (t->app_start_time - SDL_GetTicks() )/1000;
}

void time_display(SDL_Renderer *renderer, struct time* t) {
    spritesheet_render(t->chrono, CHRONO_X, CHRONO_Y, 255, 11);
}
