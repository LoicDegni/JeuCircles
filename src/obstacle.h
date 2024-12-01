#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "sdl2.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Structure de donnees representant une file d'obstacles
//------------------------------------------------------

typedef struct queue_node {
   unsigned int rayon;
   unsigned int cadran;
   struct queue_node *prev;
   struct queue_node *next;
} obstacle;

typedef struct {
   obstacle *first;
   obstacle *last;
} file;

// Interface
// ---------

/**
 * Creer une file d'obstacles vide
 *
 * return la liste
 */
file *file_obstacle_initialize();

/**
 * Creer un obstacle
 *
 * Retun  l'obstacle
 */
obstacle *obstacle_initialize(int rayon);

/**
 * Retourne true si la liste est vide
 *
 * @param f  la liste d'obstacle a verifier
 * @return   true si la liste est vide
 */
bool file_is_empty(const file *f);

/**
 * Place un element a la fin de la file
 *
 * @param f      la file
 * @param rayon  le rayon de l'obstacle a ajouter
 * @param cadran le numero du cadran ou l'obstacle sera ajoute
 */
void file_push(file *f, unsigned int rayon) ;

/**
 * Retire le premier element de la la file
 *
 * @param f        La file
 * @return cadran  le numero du cadran ou l'obastacle retirer etait
 */
unsigned int file_pop(file *f);

/**
 * Affiche les obstacle dans la file
 *
 * @param f  la file
 * @param r  Le renderer de l'affichage du jeu
 */
void file_display(SDL_Renderer *r, const file *f);

/**
 * Affiche un obstacle dans la file
 *
 * @param f  la file
 * @param r  le renderer de l'affichage du jeu
 * return    la valeur de succes de la fonction d'affichage
 */
int obstacle_display(SDL_Renderer * r, const obstacle *o);

/**
 * Supprime la file d'obstacle
 *
 * @param f la file
 */
void file_delete(file *f);


//Fonctions
//--------------------

/**
 * Fourni une position aleatoire entre 1 et 6 de 
 * cadran pour l'obstacle
 */
int obstacle_cadran();

#endif
