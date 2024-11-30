#include "background.h"

int background_display(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 0, 60, 230, 230, 230, 255);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 120, 180, 230, 230, 230, 255);
    filledPieRGBA(renderer, CENTER_X, CENTER_Y, SCREEN_HEIGHT, 240, 300, 230, 230, 230, 255);
    filledCircleRGBA(renderer, CENTER_X, CENTER_Y, RAYON_CENTRE, 128, 128, 128, 255);

    return 0;
}

