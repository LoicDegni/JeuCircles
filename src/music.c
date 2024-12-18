#include "music.h"

int music_initialisation() {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        printf("Erreur SDL : %s\n", SDL_GetError());
        return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        printf("Erreur SDL_mixer : %s\n", Mix_GetError());
        return 1;
    }
    return 0;
}

Mix_Music *music_load() {
    Mix_Music *music = Mix_LoadMUS("music_loop.mp3");
    if (!music) {
        printf("Erreur chargement musique : %s\n", Mix_GetError());
        exit(1);
    }
    return music;
}

int music_play(Mix_Music *music) {
    Mix_PlayMusic(music, -1);
    return 0;
}

int music_delete(Mix_Music *music){
    Mix_FreeMusic(music);
    Mix_CloseAudio();

    return 0;
}

