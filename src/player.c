#include "player.h"

int cadran_position(int position){
    int cadran;
    if (position >= 0 && position < 60){
        cadran = 1;
    }else if (position >= 60 && position < 120) {
        cadran = 2;
    }else if (position >= 120 && position < 180) {
        cadran = 3;
    }else if (position >= 180 && position < 240) {
        cadran = 4;
    }else if (position >= 240 && position < 300) {
        cadran = 5;
    }else{
        cadran = 6;
    }
    return cadran;
}

struct player *player_initialization() {
    struct player *player = malloc(sizeof(struct player));
    player->position = STARTING_POSITION;
    player->cadran = cadran_position(player->position);    
    return player;
}
