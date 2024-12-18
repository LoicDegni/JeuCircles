#include "obstacle.h"

file *file_obstacle_initialize() {
   file *Obstacles = malloc(sizeof(file));
   Obstacles->first = NULL;
   Obstacles->last = NULL;

   return Obstacles;
}

bool file_is_empty(const file *f) {
    abort_file(f);
    return f->first == NULL;
}

void file_push(file *f, unsigned int rayon) {
    abort_file(f);
    if(rayon < SCREEN_HEIGHT/2) {
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
    abort_file(f);

    if(f->first == NULL) {
      return 0; 
    }
    obstacle *temp = f->first;
    int cadran = temp->cadran;
    if(f->first == f->last) {
        f->first = f->last = NULL;
        temp->next = NULL;
        temp->prev = NULL;
        free(temp);
    }
    else{
        f->first = temp->prev;
        f->first->next = NULL;
        temp->next = NULL;
        temp->prev = NULL;
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
    abort_file(f);
    while(file_pop(f) != 0);
    free(f);
}

void file_display(SDL_Renderer *renderer, const file *f) {
    abort_file(f);
    obstacle *noeud_courant = f->last;
    while (noeud_courant != NULL){
    obstacle_display(renderer, noeud_courant);
    noeud_courant = noeud_courant->next;
   }
}

int obstacle_display(SDL_Renderer *renderer,const obstacle *o) {
   if(renderer == NULL){
      fprintf(stderr, "Pointeur invalide");
      exit(1);
   }
   abort_obstacle(o);

   int couleur = 255;
   int fin_cadran = (o->cadran*60) - 1;

   if (o->cadran == 1 || o->cadran == 3 || o->cadran == 5)
       couleur = 230;
   
   int debut_cadran = fin_cadran - 59;

   filledPieRGBA(renderer, CENTER_X, CENTER_Y, o->rayon + 20, debut_cadran, fin_cadran,0,0,255,255);
   filledPieRGBA(renderer, CENTER_X, CENTER_Y, o->rayon, debut_cadran,fin_cadran,couleur,couleur,couleur,255);

   return 0;
}

int obstacle_cadran() {
   static unsigned int validation = 0;
   unsigned int num_cadran = ((rand() % 6) + 1);
   while(num_cadran == validation)
      num_cadran = ( (rand() % 6) + 1);
   validation = num_cadran;
   return num_cadran;
}

void abort_file(const file *f) {
    if(f == NULL) {
        fprintf(stderr,"pointeur de file invalide");
        exit(1);
    }
}

void abort_obstacle(const obstacle *o) {
    if(o == NULL) {
        fprintf(stderr,"pointeur d'obstacle invalide");
        exit(1);
    }
}
