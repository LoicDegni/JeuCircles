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
    triangle_player(player);
    return player;
}

void player_delete(struct player *player) {
    free(player);
}

int triangle_player(struct player *player){
    if(player == NULL){
        fprintf(stderr, "Pointeur invalide");
        exit(1);
    }

    int center_x = CENTER_X;
    int center_y = CENTER_Y;
    int rayon = RAYON_CENTRE + 10;
    int arrete_inf = 10;
    int hauteur_triangle = 15;

    double milieu_x = center_x + (rayon * cos(DEG_TO_RAD(player->position)));
    double milieu_y = center_y + (rayon * sin(DEG_TO_RAD(player->position)));
    double theta_t = player->position + 90.0;
    double x1 = milieu_x + (arrete_inf / 2) * cos(DEG_TO_RAD(theta_t));
    double y1 = milieu_y + (arrete_inf / 2) * sin(DEG_TO_RAD(theta_t));
    double x2 = milieu_x - (arrete_inf / 2) * cos(DEG_TO_RAD(theta_t));
    double y2 = milieu_y - (arrete_inf / 2) * sin(DEG_TO_RAD(theta_t));

    double vx = x2 - x1;
    double vy = y2 - y1;
    double longueur = sqrt(vx * vx + vy * vy);
    double ux = -vy / longueur;
    double uy = vx / longueur;

    double x3 = milieu_x + hauteur_triangle * ux;
    double y3 = milieu_y + hauteur_triangle * uy;
    
    player->p1_x = x1;
    player->p1_y = y1;
    player->p2_x = x2;
    player->p2_y = y2;
    player->p3_x = x3;
    player->p3_y = y3;

    return 0;
}
int player_display(SDL_Renderer *renderer,struct player *p) {
    filledTrigonRGBA(renderer, p->p1_x, p->p1_y, p->p2_x, p->p2_y, p->p3_x, p->p3_y, 255, 0, 0, 255);
    return 0;
}

