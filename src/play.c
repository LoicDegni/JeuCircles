#include "play.h"

struct play *play_initialize(SDL_Renderer *renderer){
   srand(time(NULL));
   struct play *play = malloc(sizeof(struct play));
   play->state = PLAY_ALIVE;
   play->player = player_initialization();
   play->Obstacles = file_obstacle_initialize();
   play->time = time_initialize(play->Obstacles);
   play->compteur = 0;
   play->renderer = renderer;
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
      if (play->compteur == 180) {
          file_push(play->Obstacles, SCREEN_HEIGHT);    
      }
      obstacle_animation(play->Obstacles, time_variation());
      background_display(play->renderer);
      file_display(play->renderer, play->Obstacles);
      player_display(play->renderer, play->player);
      SDL_RenderPresent(play->renderer);
      play->compteur++;
      SDL_Delay(16);
   }
}



