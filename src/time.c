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
    t->play_time = (SDL_GetTicks() - t->app_start_time )/100;
}

void time_display(SDL_Renderer *renderer, struct time* t) {
    int dixieme = t->play_time % 10;
    spritesheet_render(t->chrono, CHRONO_X, CHRONO_Y, 255, dixieme);
    int minute = t->play_time / 600;
    int seconde = (t->play_time % 600) /10;

    if(minute == 0){
        spritesheet_render(t->chrono, CHRONO_X, CHRONO_Y, 255, dixieme);
        spritesheet_render(t->chrono, CHRONO_X - t->chrono->sprite_width, CHRONO_Y, 225, 10);
        spritesheet_render(t->chrono, CHRONO_X - 2*(t->chrono->sprite_width), CHRONO_Y, 255, seconde%10);
        spritesheet_render(t->chrono, CHRONO_X - 3*(t->chrono->sprite_width), CHRONO_Y, 255, seconde/10);
    }else{
        spritesheet_render(t->chrono, CHRONO_X, CHRONO_Y, 255, dixieme);
        spritesheet_render(t->chrono, CHRONO_X - t->chrono->sprite_width, CHRONO_Y, 225, 10);
        spritesheet_render(t->chrono, CHRONO_X - 2*(t->chrono->sprite_width), CHRONO_Y, 255, seconde%10);
        spritesheet_render(t->chrono, CHRONO_X - 3* (t->chrono->sprite_width), CHRONO_Y, 255, seconde/10);
        spritesheet_render(t->chrono, CHRONO_X - 4* (t->chrono->sprite_width), CHRONO_Y, 255, 12);
        
        spritesheet_render(t->chrono, CHRONO_X - 5* (t->chrono->sprite_width), CHRONO_Y, 255,minute%10);
        spritesheet_render(t->chrono, CHRONO_X - 6* (t->chrono->sprite_width) , CHRONO_Y, 255, minute/10);
    }
}
