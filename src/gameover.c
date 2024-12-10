#include "gameover.h"

struct game_stat *game_over_initialize(SDL_Renderer *renderer, struct time *t){
    abort_time(t);
    struct game_stat *gameover = malloc(sizeof(struct game_stat));

    gameover->time = t;
    time_variation(gameover->time);
    //gameover->background=
    //gameover->gameover_display=
    gameover->renderer = renderer;
}

void game_over_display(struct game_stat *g){
}

