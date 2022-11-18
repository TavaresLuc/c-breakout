#ifdef __linux__
#include <SDL2/SDL.h>
#endif

#ifdef _WIN32
#include "../srch/include/SDL2/SDL.h"
#endif
#include "../srch/draw.h"
#include "../srch/defs.h"
#include <stdio.h>
#include <inttypes.h>
#include "../srch/spawn.h"
#include "../srch/structs.h"
#include "../srch/hero.h"

SDL_Texture *ball_hud, *hud;
int currentHealth = 5;

int y = 0, ball_y = 0,rotated = 0,ball_rotated = 0, frame = 0;

void hud_init(){
    ball_hud = loadTexture("resources/sprites/hud_ball.png");
    hud = loadTexture("resources/sprites/hud.png");

    y = 0;
    ball_y = 0;
}

void hud_anim(){
    frame++;

    if(frame >= currentHealth+3){
        if(rotated == 0){
            y += 1;
        }else{
            y -= 1;
        }

        if(ball_rotated == 0){
            ball_y += 1;
        }else{
            ball_y -= 1;
        }

        if(y >= 2 && rotated == 0){
            rotated = 1;
        }
        if(y<= -2 && rotated == 1){
            rotated = 0;
        }

        if(ball_y >= 1 && ball_rotated == 0){
            ball_rotated = 1;
        }
        if(ball_y <= -1 && ball_rotated == 1){
            ball_rotated = 0;
        }

        frame = 0;
    }
}

void hud_draw(){
    blit(hud, 4, 0, y, 0, 0);
    for (size_t i = currentHealth; i > 0; i--)
    {
        /* code */
        blit(ball_hud, 4, (10+(35*i))-32, ((30-(4*i))+6)-ball_y, 0, 0);
    }
    hud_anim();
}

void hud_change(int health){
    currentHealth = health;
}