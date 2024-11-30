#include "obstacle.h"

struct obstacle*  obstacle_initialize(int rayon)
{
   struct obstacle *nouvelle_obstacle = malloc(sizeof(struct obstacle));
   nouvelle_obstacle->rayon = rayon;
   nouvelle_obstacle->cadran = obstacle_cadran();
   return nouvelle_obstacle;
}

// A completer
int obstacle_display(SDL_Renderer *renderer, struct obstacle *obstacle) {
   if(renderer == NULL){
      fprintf(stderr, "Pointeur invalide");
      exit(1);
   }
   if(obstacle == NULL) {
      fprintf(stderr, "Pointeur invalide");
      exit(1);
   }

   int couleur = 255;
   int fin_cadran = (obstacle->cadran*60) - 1;
   if(fin_cadran<60 || (fin_cadran >119 && fin_cadran <180) || (fin_cadran > 239 && fin_cadran <300)) couleur = 230;
   int debut_cadran = fin_cadran - 59;

   filledPieRGBA(renderer, CENTER_X, CENTER_Y, obstacle->rayon, debut_cadran, fin_cadran,0,0,255,255);
   filledPieRGBA(renderer, CENTER_X, CENTER_Y, obstacle->rayon - 5, debut_cadran,fin_cadran,couleur,couleur,couleur,255);
//thickArcRGBA(renderer, CENTER_X, CENTER_Y, obstacle->rayon, debut_cadran, fin_cadran, 5, 0, 0, 255, 255);
   return 0;
}

int obstacle_cadran() {
   srand(time(NULL));
   return ((rand() % 6) + 1);
}

void obstacle_delete(struct obstacle *o) {
   free(o);
}
