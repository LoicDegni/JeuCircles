#include "play.h"

struct play *play_initialize(SDL_Renderer *renderer, enum difficulty diff_setting){
   srand(time(NULL));
   struct play *play = malloc(sizeof(struct play));
   play->renderer = renderer;
   play->state = PLAY_ALIVE;
   play->difficulty = diff_setting;
   play->player = player_initialization();
   play->Obstacles = file_obstacle_initialize();
   play->time = time_initialize(renderer);
   play->counter = 0;
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
      if (play->counter == counter_setting(play->difficulty)) {
          file_push(play->Obstacles, SCREEN_HEIGHT);
          play->counter = 0;
      }
      obstacle_animation(play->Obstacles, obstacle_movement(play->difficulty));
      background_display(play->renderer);
      file_display(play->renderer, play->Obstacles);
      player_display(play->renderer, play->player);
      centre_display(play->renderer);
      time_variation(play->time);
      time_display(play->time);
      SDL_RenderPresent(play->renderer);
      play->counter++;
      SDL_Delay(TIME_FRAME);
   }
}

int obstacle_movement(enum difficulty difficulty){
    int speed;
    switch (difficulty){
    case EASY:
        speed = OBSTACLES_SPEED_EASY;
        break;
    case MEDIUM:
        speed = OBSTACLES_SPEED_MEDIUM;
        break;
    case HARD:
        speed = OBSTACLES_SPEED_HARD;
        break;
    }
    return speed;
}

int counter_setting(enum difficulty difficulty) {
    int counter_treshold;
    switch (difficulty) {
        case EASY:
            counter_treshold = COUNTER_EASY;
            break;
        case MEDIUM:
            counter_treshold = COUNTER_MEDIUM;
            break;
        case HARD:
            counter_treshold = COUNTER_HARD;
            break;
    }
    return counter_treshold;
}


