#ifndef PLAYER_H
#define PLAYER_H

#include "sdl2.h"
#include "constants.h"
#include <stdio.h>
#include <math.h>

#define DEG_TO_RAD(angle_in_degrees) ((angle_in_degrees) * M_PI / 180.0)

struct player {
    int position;
    int cadran;
    int p1_x;
    int p1_y;
    int p2_x;
    int p2_y;
    int p3_x;
    int p3_y;
};

int triangle_player(struct player *);
int cadran_position(struct player *);
struct player *player_initialization();
void player_delete(struct player *);
int player_display(SDL_Renderer *, struct player *);

#endif

