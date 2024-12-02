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
// ON DOIT FAIRE EN SORTE QUE UN SEUL RAYON 
void obstacle_animation(file *Obstacles, float delta_time) {
   if (Obstacles == NULL || Obstacles->first == NULL) {
      return;     
   }
   int distance = (int)(delta_time*OBSTACLES_SPEED_EASY);

   for(obstacle *current = Obstacles->first; current !=NULL; current = current->prev){
      if(current->rayon < distance){
         current->rayon = 0;
      }else{
         current->rayon -=distance;
         printf("%d %d\n", current->rayon, current->cadran);
      }
      // Ajouter la verif de la position cadran du joueur 
   }

   while(Obstacles->first->rayon == 0)
      file_update(Obstacles);
   //printf("%d\n", distance);
}
