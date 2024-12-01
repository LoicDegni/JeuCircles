#include "obstacle.h"

file *file_obstacle_initialize() {
   file *Obstacles = malloc(sizeof(file));
   Obstacles->first = NULL;
   Obstacles->last = NULL;

   for(int i =0; i<6; ++i)
      file_push(Obstacles, 500 );

   return Obstacles;
}

bool file_is_empty(const file *f) {
   if(f == NULL) {
      fprintf(stderr,"Pointeur invalide\n");
      exit(1);
   }
   return f->first == NULL;
}


void file_push(file *f, unsigned int rayon) {
   if(f == NULL) {
      fprintf(stderr,"Pointeur invalide\n");
      exit(1);
   }
   if(rayon < /*SCREEN_HEIGHT */ 0) {
      fprintf(stderr,"L'obstacle ne commence pas a l'exterieur de l'ecran\n");
      exit(1);
   }
   obstacle *new = obstacle_initialize(rayon);

   if(f->first == NULL){
      f->first = f->last = new;
   }
   else {
      new->next = f->last;
      f->last->prev = new;
      f->last = new;
   }
}

unsigned int file_pop(file *f) {
   if(f == NULL) {
      fprintf(stderr, "Pointeur invalide\n");
      exit(1);
   }
   if(f->first == NULL) {
      return 0;
   }
   obstacle *temp = f->first;
   int cadran = temp->cadran;
   if(f->first == f->last) {
      f->first = f->last = NULL;
      free(temp);
   }
   else{
   f->first = temp->prev;
   f->first->next = NULL;
   free(temp);
   }
   return cadran;
}


obstacle* obstacle_initialize(int rayon) {
   obstacle *new = malloc(sizeof(obstacle));
   new->rayon = rayon;
   new->cadran = obstacle_cadran();
   new->prev = NULL;
   new->next = NULL;
   return new;
}

void file_delete(file *f) {
   if(f == NULL) {
      fprintf(stderr, "Pointeur invalide\n");
      exit(1);
   }
   while(file_pop(f) != 0);
}



int obstacle_display(SDL_Renderer *renderer, const file *f) {
   if(renderer == NULL){
      fprintf(stderr, "Pointeur invalide");
      exit(1);
   }
   if(f == NULL) {
      fprintf(stderr, "Pointeur invalide");
      exit(1);
   }
   int nb = 0;
   //for(obstacle *obstacle = f->first; obstacle != NULL; obstacle = obstacle->prev){
      //nb ++;

      printf("%d %d\n" ,f->first->cadran, f->first->rayon);
      int couleur = 255;
      int fin_cadran = (f->first->cadran*60) - 1;
      printf("%d\n", fin_cadran);

   if(fin_cadran<60 || (fin_cadran >119 && fin_cadran <180) || (fin_cadran > 239 && fin_cadran <300)) 
      couleur = 230;
   int debut_cadran = fin_cadran - 59;

   filledPieRGBA(renderer, CENTER_X, CENTER_Y, f->first->rayon, debut_cadran, fin_cadran,0,0,255,255);
   filledPieRGBA(renderer, CENTER_X, CENTER_Y, f->first->rayon - 20, debut_cadran,fin_cadran,couleur,couleur,couleur,255);
   filledCircleRGBA(renderer, CENTER_X, CENTER_Y, RAYON_CENTRE,128,128,128,255);
  // }
   return 0;
}

int obstacle_cadran() {
   srand(time(NULL));
   return ((rand() % 6) + 1);
}


