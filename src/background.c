#include "background.h"

int background_display(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 60, 119, 255, 255, 255, 255);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 180, 239, 255, 255, 255, 255);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 300, 359, 255, 255, 255, 255);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 0, 59, 230, 230, 230, 255);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 120, 179, 230, 230, 230, 255);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 240, 299, 230, 230, 230, 255);

    return 0;
}

int centre_display(SDL_Renderer *renderer) { 
    filledCircleRGBA(renderer, CENTER_X, CENTER_Y, RAYON_CENTRE, 128, 128, 128, 255);

    return 0;
}
