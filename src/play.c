#include "play.h"

struct play *play_initialize(SDL_Renderer *renderer){
   srand(time(NULL));
   struct play *play = malloc(sizeof(struct play));
   play->state = PLAY_ALIVE;
   play->player = player_initialization();
   play->Obstacles= file_obstacle_initialize();
   play->renderer = renderer;
   return play;
}

void play_run(struct play *play){
    SDL_Event event;
    while (SDL_PollEvent(&event) != 0) {
        if (event.type == SDL_QUIT) {
            play->state = PLAY_QUIT;
        }else if (event.type == SDL_KEYDOWN) {
           player_animation(play->player, event);
        }else {
           obstacle_animation(play->Obstacles);
        }

    }  
    //    tick();
    background_display(play->renderer);
    file_display(play->renderer, play->Obstacles);
    player_display(play->renderer, play->player);
    SDL_RenderPresent(play->renderer);
}



