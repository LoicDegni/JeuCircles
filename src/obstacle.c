#include "obstacle.h"


struct obstacle  obstacle_initialize(int rayon) 
{
   struct obstacle nouvelle_obstacle;
   nouvelle_obstacle.rayon = RAYON_MAX;
}

// A completer
int obstacle_display(SDL_Renderer *renderer, struct obstacle nouvelle_obstacle) {
   thickArcRGBA(renderer, 320, 240, 75, 0, 45, 5, 0, 255, 0, 255);
}


