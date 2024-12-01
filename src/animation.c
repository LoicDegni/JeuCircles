#include "animation.h"

void player_animation(struct player *player, SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_LEFT:
                player->position -= 5;
                triangle_player(player);
                cadran_position(player);
                break;
            case SDLK_RIGHT:
                player->position += 5;
                triangle_player(player);
                cadran_position(player);
                break;
        }
    }
}

void obstacle_animation(file *Obstacle) {
   static Uint32 last_tick;
   Uint32 current_tick = SDL_GetTicks();
   float delta_time = (current_tick - last_tick)/1000.0f;
   last_tick = current_tick;
   int distance = (int)(delta_time*OBSTACLES_SPEED_EASY);
   printf("%d\n", distance);
}
