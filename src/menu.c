#include "menu.h"

struct menu *menu_initialize(SDL_Renderer *renderer) {
    struct menu *menu;
    menu = malloc(sizeof(struct menu));
    menu->renderer = renderer;
    menu->state = MENU_PLAY_FOCUS;
    menu->diff_select = MEDIUM;
    menu->background = spritesheet_create(BACKGROUND_FILENAME, 1, 1, 1, renderer);
    menu->title = spritesheet_create(TITLE_FILENAME, 1, 1, 1, renderer);
    menu->play = spritesheet_create(PLAY_FILENAME, 1, 1, 1, renderer);
    menu->difficulty = spritesheet_create(DIFFICULTY_FILENAME, 1, 1, 1, renderer);
    menu->easy = spritesheet_create(EASY_FILENAME, 1, 1, 1, renderer);
    menu->medium = spritesheet_create(MEDIUM_FILENAME, 1, 1, 1, renderer);
    menu->hard = spritesheet_create(HARD_FILENAME, 1, 1, 1, renderer);
    menu->quit = spritesheet_create(QUIT_FILENAME, 1, 1, 1, renderer);
    return menu;
}

int menu_alpha(bool chosen) {
    return chosen ? 255 : 64;
}

int difficulty_alpha(bool chosen) {
    return chosen ? 200 : 64;
}

int menu_display(struct menu *menu) {
        if (menu->state != MENU_DIFFICULTY){
            spritesheet_render(menu->background, BACKGROUND_X, BACKGROUND_Y,
                               255, 0);
            spritesheet_render(menu->title,      TITLE_X,      TITLE_Y,
                              255, 0);
            spritesheet_render(menu->play,       PLAY_X,       PLAY_Y,
                              menu_alpha(menu->state == MENU_PLAY_FOCUS), 0);
            spritesheet_render(menu->difficulty, DIFFICULTY_X, DIFFICULTY_Y,
                              menu_alpha(menu->state == MENU_DIFFICULTY_FOCUS), 0);
            spritesheet_render(menu->easy,       EASY_X,       EASY_Y,
                              difficulty_alpha(menu->diff_select == EASY), 0);
            spritesheet_render(menu->medium,       MEDIUM_X,       MEDIUM_Y,
                               difficulty_alpha(menu->diff_select == MEDIUM), 0);
            spritesheet_render(menu->hard,       HARD_X,       HARD_Y,
                               difficulty_alpha(menu->diff_select == HARD), 0);
            spritesheet_render(menu->quit,       QUIT_X,       QUIT_Y,
                              menu_alpha(menu->state == MENU_QUIT_FOCUS), 0);
        }else{
            spritesheet_render(menu->background, BACKGROUND_X, BACKGROUND_Y,
                               255, 0);
            spritesheet_render(menu->title,      TITLE_X,      TITLE_Y,
                              255, 0);
            spritesheet_render(menu->play,       PLAY_X,       PLAY_Y,
                              menu_alpha(menu->state == MENU_PLAY_FOCUS), 0);
            spritesheet_render(menu->difficulty, DIFFICULTY_X, DIFFICULTY_Y,
                              menu_alpha(menu->state == MENU_DIFFICULTY_FOCUS), 0);
            spritesheet_render(menu->easy,       EASY_X,       EASY_Y,
                              menu_alpha(menu->diff_select == EASY), 0);
            spritesheet_render(menu->medium,       MEDIUM_X,       MEDIUM_Y,
                               menu_alpha(menu->diff_select == MEDIUM), 0);
            spritesheet_render(menu->hard,       HARD_X,       HARD_Y,
                               menu_alpha(menu->diff_select == HARD), 0);
            spritesheet_render(menu->quit,       QUIT_X,       QUIT_Y,
                              difficulty_alpha(menu->state == MENU_QUIT_FOCUS), 0);

        }

    return 0;
}

void menu_run(struct menu *menu) {
    SDL_Event e;
    while (menu->state != MENU_PLAY && menu->state != MENU_QUIT) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                menu->state = MENU_QUIT;
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT:
                        if (menu->state != MENU_DIFFICULTY) {
                            menu->state = menu->state == MENU_PLAY_FOCUS ?
                                          MENU_QUIT_FOCUS : MENU_PLAY_FOCUS;
                            break;
                        }else{
                            if (menu->diff_select == HARD) {
                                menu->diff_select = MEDIUM;
                            }else if (menu->diff_select == MEDIUM) {
                                menu->diff_select = EASY;
                            }
                            break;
                        }                        
                    case SDLK_RIGHT:
                        if (menu->state != MENU_DIFFICULTY) {
                            if (menu->state == MENU_DIFFICULTY_FOCUS){
                                menu->state = MENU_QUIT_FOCUS;
                            }else{
                            menu->state = menu->state == MENU_PLAY_FOCUS ?
                                          MENU_QUIT_FOCUS : MENU_PLAY_FOCUS;
                            }
                            break;
                        }else{
                            if (menu->diff_select == EASY) {
                                menu->diff_select = MEDIUM;
                            }else if (menu->diff_select == MEDIUM) {
                                menu->diff_select = HARD;
                            }
                            break;
                        }
                    case SDLK_DOWN:
                        if (menu->state != MENU_DIFFICULTY) {
                            menu->state = MENU_DIFFICULTY_FOCUS;
                        }
                        break;
                    case SDLK_UP:
                        if (menu->state == MENU_DIFFICULTY_FOCUS) {
                            menu->state = MENU_PLAY_FOCUS;
                        }
                        break;
                    case SDLK_RETURN:
                        if (menu->state == MENU_PLAY_FOCUS) {
                            menu->state = MENU_PLAY;
                        } else if (menu->state == MENU_QUIT_FOCUS) {
                            menu->state = MENU_QUIT;
                        } else if (menu->state == MENU_DIFFICULTY_FOCUS) {
                            menu->state = MENU_DIFFICULTY;
                        } else if (menu->state == MENU_DIFFICULTY) {
                            menu->state = MENU_PLAY_FOCUS;
                        }
                        break;
                }
            }
        }
        SDL_SetRenderDrawColor(menu->renderer, 0x00, 0x00, 0x00, 0x00 );
        SDL_RenderClear(menu->renderer);
        menu_display(menu);
        SDL_RenderPresent(menu->renderer);
    }
}

void menu_delete(struct menu *menu) {
    if (menu != NULL) {
        spritesheet_delete(menu->background);
        spritesheet_delete(menu->title);
        spritesheet_delete(menu->play);
        spritesheet_delete(menu->quit);
        spritesheet_delete(menu->difficulty);
        spritesheet_delete(menu->easy);
        spritesheet_delete(menu->medium);
        spritesheet_delete(menu->hard);
        free(menu);
    }
}
