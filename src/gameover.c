#include "gameover.h"

struct game_over *game_over_initialize(struct play *play){
    abort_play(play);
    struct game_over *gameover = malloc(sizeof(struct game_over));
    gameover->play = play;
    gameover->state = GAME_OVER_ON;
    gameover->time = play->time;
    time_variation(gameover->time);
    gameover->background = spritesheet_create(BACKGROUND_END_FILENAME,1,1,1, play->renderer);
    gameover->renderer = play->renderer;
    return gameover;
}

void game_over_run(struct game_over *g){
    SDL_Event event;
    while(g->state == GAME_OVER_ON){

        while(SDL_PollEvent(&event) !=0) {
            if(event.type == SDL_QUIT){
                g->play->state = PLAY_QUIT;
                g->state = GAME_OVER_OFF;
            }
            else if(event.type == SDL_KEYDOWN){
                g->play->state = PLAY_LOST;
                g->state = GAME_OVER_OFF;
            }
        }
        game_over_display(g);
        SDL_RenderPresent(g->renderer);
    }
}

void game_over_display(struct game_over *g){
    abort_game_over(g);
    SDL_SetRenderDrawColor(g->renderer, 255, 255, 255, 255);
    SDL_RenderClear(g->renderer);
    spritesheet_render(g->background, BACKGROUND_X, BACKGROUND_Y, 255,0);
    time_display(g->time);
}

void game_over_delete(struct game_over *g){
    abort_game_over(g);
    free(g);
}

void abort_game_over(struct game_over *g){
    if(g == NULL){
        fprintf(stderr, "Le pointeur game_over est invalide");
        exit(1);
    }
}



