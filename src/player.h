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

/**
 * Formule pour trouver les points du triangle représantant le joueur.
 *
 * @param1: la strucutre player
 */
int triangle_player(struct player *);

/**
 * Identifie le cadran dans lequel le joueur se trouve.  Les cadrans se sont
 * numéroté de 1 à 6, le degré 0 étant vers la droite.  Le premier cadran est
 * en bas à droite et les autres suivent dans le sens des aiguilles d'une
 * montre.
 */
int cadran_position(struct player *);

/**
 * Initialise la structure player.
 */
struct player *player_initialization();

/**
 * Efface et libère la mémoire d'une structure player.
 */
void player_delete(struct player *);

/**
 * Affichage du joueur.
 *
 * @param1: le renderer à utiliser
 * @param2: la strucutre player à afficher
 */
int player_display(SDL_Renderer *, struct player *);

#endif

