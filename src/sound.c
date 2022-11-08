#include "../srch/include/SDL2/SDL.h"
#include "../srch/include/SDL2/SDL_mixer.h"
#include "../srch/defs.h"
#include "../srch/sound.h"
#include <stdio.h>
#include <string.h>

Mix_Chunk* sounds[4];

Mix_Music* music;

void loadSounds(void){
    sounds[SND_SPLASH] = Mix_LoadWAV("resources/sounds/enter.ogg");
    sounds[SND_PLAYER_COLLECT] = Mix_LoadWAV("resources/sounds/collect.ogg");
    sounds[SND_FILA_REMOVE] = Mix_LoadWAV("resources/sounds/remove.ogg");
    sounds[SND_PLAYER_FAIL] = Mix_LoadWAV("resources/sounds/fail.ogg");
}

void loadMusic(char *filename){
    if(music != NULL){
        Mix_HaltMusic();
        Mix_FreeMusic(music);
        music = NULL;
    }

    music = Mix_LoadMUS(filename);
}

void playMusic(int loop)
{
	Mix_PlayMusic(music, (loop) ? -1 : 0);
}

void initSound(){
    memset(sounds, 0, sizeof(Mix_Chunk*) * 4);

    music = NULL;

    loadSounds();
}

void playSound(int id, int channel){
    Mix_PlayChannel(channel, sounds[id], 0);
}
