#include "play.h"

struct play *play_initialize(SDL_Renderer *renderer){
   srand(time(NULL));
   struct play *play = malloc(sizeof(struct play));
   play->renderer = renderer;
   play->state = PLAY_ALIVE;
   play->player = player_initialization();
   play->Obstacles = file_obstacle_initialize();
   play->time = time_initialize(renderer);
   play->compteur = 0;
   return play;
}

void play_run(struct play *play){
    while(play->time->state == TIME_ON) {
      SDL_Event event;
      while (SDL_PollEvent(&event) != 0) {
         if (event.type == SDL_QUIT) {
             play->time->state = TIME_OFF;
             play->state = PLAY_QUIT;
         }
      if (event.type == SDL_KEYDOWN) {
         player_animation(play->player, event);
        }
      }
      if (play->compteur == 120) {
          file_push(play->Obstacles, SCREEN_HEIGHT);
          play->compteur = 0;
      }
      obstacle_animation(play->Obstacles);
      background_display(play->renderer);
      file_display(play->renderer, play->Obstacles);
      player_display(play->renderer, play->player);
      centre_display(play->renderer);
      time_variation(play->time);
      time_display(play->time);
      SDL_RenderPresent(play->renderer);
      play->compteur++;
      SDL_Delay(16);
    }
}



