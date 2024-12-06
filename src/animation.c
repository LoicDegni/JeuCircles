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

void obstacle_animation(file *Obstacles) {
    obstacle *noeud_courant = Obstacles->first;
    while (noeud_courant != NULL){
        noeud_courant->rayon--;
        int rayon = noeud_courant->rayon;
        noeud_courant = noeud_courant->prev;
        if (rayon == 0) {
            file_pop(Obstacles);
        }
    }
}

