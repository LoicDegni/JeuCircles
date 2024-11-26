#include "background.h"

int background_initialize(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    filledPieRGBA(renderer, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT, 0, 60, 230, 230, 230, 255);
    filledPieRGBA(renderer, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT, 120, 180, 230, 230, 230, 255);
    filledPieRGBA(renderer, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, SCREEN_HEIGHT, 240, 300, 230, 230, 230, 255);
    filledCircleRGBA(renderer, SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, RAYON_CENTRE, 128, 128, 128, 255);



    SDL_RenderPresent(renderer);

    return 0;
}

