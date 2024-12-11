#ifndef MENU_H
#define MENU_H

#include "sdl2.h"
#include "constants.h"
#include "spritesheet.h"
#include "difficulty.h"
#include <stdbool.h>


// --------------- //
// Data structures //
// --------------- //

enum menu_state {
    MENU_PLAY_FOCUS,       // Play choice has focus
    MENU_DIFFICULTY_FOCUS, // Difficulty choice has focus   
    MENU_QUIT_FOCUS,       // Quit choice has focus
    MENU_PLAY,             // Play has been chosen
    MENU_DIFFICULTY,       // Difficulty has been chosen
    MENU_QUIT              // Quit has been chosen
};

struct menu {
    enum menu_state state;          // The choice of the user
    enum difficulty diff_select;    // Difficulty selected
    struct spritesheet *background; // The menu background
    struct spritesheet *title;      // The title sprite
    struct spritesheet *play;       // The play sprite
    struct spritesheet *difficulty; // The difficulty sprite
    struct spritesheet *easy;       //
    struct spritesheet *medium;     //
    struct spritesheet *hard;       //
    struct spritesheet *quit;       // The quit sprite
    SDL_Renderer *renderer;         // The renderer
};

// --------- //
// Functions //
// --------- //

/**
 * Creates a new menu.
 *
 * @param renderer  The renderer
 * @return          A pointer to the menu, NULL if there was an error
 */
struct menu *menu_initialize(SDL_Renderer *renderer);

/**
 * Gère l'alpha du menu principal
 */
int menu_alpha(bool);

/**
 * Gère l'alpha du menu de difficulté
 */
int difficulty_alpha(bool);

int menu_display(struct menu *);
/**
 * Start running the menu.
 *
 * @param menu  The menu to show
 */
void menu_run(struct menu *menu);

/**
 * Delete the menu.
 *
 * @param menu  The menu to delete
 */
void menu_delete(struct menu *menu);


#endif
