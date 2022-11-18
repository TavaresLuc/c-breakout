#ifdef __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_audio.h>
#endif

#ifdef _WIN32
#include "../srch/include/SDL2/SDL.h"
#include "../srch/include/SDL2/SDL_mixer.h"
#endif
#include "../srch/defs.h"
#include "../srch/sound.h"
#include <stdio.h>
#include <string.h>

Mix_Chunk* sounds[5];

Mix_Music* music;

void loadSounds(void){
    sounds[SND_SPLASH] = Mix_LoadWAV("resources/sounds/enter.ogg");
    sounds[SND_WALL_BOUNCE] = Mix_LoadWAV("resources/sounds/wall_bounce.wav");
    sounds[SND_BLOCK_BOUNCE] = Mix_LoadWAV("resources/sounds/block_bounce.wav");
    sounds[SND_PLATFORM_BOUNCE] = Mix_LoadWAV("resources/sounds/platform_bounce.wav");
    sounds[SND_BORDER_BOUNCE] = Mix_LoadWAV("resources/sounds/border_bounce.wav");
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
