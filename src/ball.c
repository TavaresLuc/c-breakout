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
int defaultSpeed = 4;

void start_ball(){
    shoot = 0;
    ball.x = Hero.x + 29;
    ball.y = Hero.y -16;
}

void create_ball(){
    start_ball();
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

int ball_getX(){
    return ball.x;
}
int ball_getY(){
    return ball.y;
}

void move_ball(){
    if(shoot == 0){
        ball.x = Hero.x + 29;
        ball.y = Hero.y -16;
    }else{
        ball.y += (ySpeed*defaultSpeed);
        ball.x += xSpeed;
    }
}

void ball_getBounce(int x, int y){
    printf("Object Y: %i Ball Y: %i \n", y, ball.y);
    int dif = ball.x-x;

    if(dif <= 10)xSpeed = -3;
    if(dif > 10 && dif < 20)xSpeed = 0;
    if(dif >= 20)xSpeed = 3;

    if(ball.y > y)ySpeed = 3;
    if(ball.y <= y)ySpeed = -3;
}

void ball_bounce(){
    if(ball.x + 18 >= (Hero.x+12) && ball.x <= (Hero.x + 60) &&
       ball.y + 20 >= Hero.y && ball.y <= (Hero.y + 34)){

        int dif = ball.x-Hero.x;
        if(dif <= 20)xSpeed = -3;
        if(dif > 20 && dif < 30)xSpeed = 0;
        if(dif >= 30)xSpeed = 3;
        ySpeed = -2;
    }

    
    if(ball.y <= 0)ySpeed = 2;
    if(ball.y >= app.w_Y){
        reset();
    }
    if(ball.x >= app.w_X-18)xSpeed = -2;
    if(ball.x <= 0)xSpeed = 2;
}