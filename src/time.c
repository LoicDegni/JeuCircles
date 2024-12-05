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
    abort_time(t);
    t->play_time = (SDL_GetTicks() - t->app_start_time )/100;
}

void time_display(struct time* t) {
    abort_time(t);
    int dixieme = t->play_time % 10;
    int minute = t->play_time / 600;
    int seconde = (t->play_time % 600) /10;

    if(minute == 0){
        dixieme_display(dixieme, t);
        seconde_display(seconde, t);
    }else{
        dixieme_display(dixieme, t);
        seconde_display(seconde, t);
        minute_display(minute, t);
    }
}

void dixieme_display(const int d, struct time *t) {
    spritesheet_render(t->chrono, CHRONO_X, CHRONO_Y, 255, d);
}

void seconde_display(const int s, struct time *t) {
    spritesheet_render(t->chrono, CHRONO_X - t->chrono->sprite_width, CHRONO_Y, 225, 10);
    spritesheet_render(t->chrono, CHRONO_X - 2*(t->chrono->sprite_width), CHRONO_Y, 255, s%10);
    spritesheet_render(t->chrono, CHRONO_X - 3*(t->chrono->sprite_width), CHRONO_Y, 255, s/10);
    spritesheet_render(t->chrono, CHRONO_X - 4* (t->chrono->sprite_width), CHRONO_Y, 255, 12);
}

void minute_display(const int m, struct time *t) {
    spritesheet_render(t->chrono, CHRONO_X - 5* (t->chrono->sprite_width), CHRONO_Y, 255,m%10);
    spritesheet_render(t->chrono, CHRONO_X - 6* (t->chrono->sprite_width) , CHRONO_Y, 255, m/10);
}

void abort_time(struct time *t) {
    if(t ==NULL){
        fprintf(stderr, "Pointeur invalide");
        exit(1);
    }
}
