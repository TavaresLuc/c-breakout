#ifdef __linux__
#include <SDL2/SDL.h>
#endif

#ifdef _WIN32
#include "../srch/include/SDL2/SDL.h"
#endif
#include "../srch/draw.h"
#include <stdio.h>
#include <inttypes.h>
#include "../srch/spawn.h"
#include "../srch/structs.h"
#include "../srch/hero.h"

Entity ball;

int shoot = 0;

int xSpeed = 0, ySpeed = 0;

void create_ball(int x, int y){
    ball.x = y;
    ball.y = x;
    ball.texture = loadTexture("resources/sprites/ball.png");
}

void draw_ball(){
    blit(ball.texture, 2, ball.x, ball.y, 0, 0);
}

void shoot_ball(int x, int y){
    shoot = 1;
    xSpeed = x;
    ySpeed = y;
}

void move_ball(){
    if(shoot == 0){
        ball.x = Hero.x + 29;
        ball.y = Hero.y -16;
    }else{
        ball.y += ySpeed;
        ball.x += xSpeed;
    }
}

void ball_bounce(){
    if(ball.y <= 0)ySpeed = 2;
    if(ball.y >= app.w_Y)ySpeed = -2;
    if(ball.x >= app.w_X)xSpeed = -2;
    if(ball.x <= 0)xSpeed = 2;
}