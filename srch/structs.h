#ifndef STRUCT_H
#define STRUCT_H

#ifdef __linux__
#include <SDL2/SDL.h>
#endif

#ifdef _WIN32
#include "../srch/include/SDL2/SDL.h"
#endif
#include <stdbool.h>

typedef struct{
    SDL_Renderer *renderer;
    SDL_Window *window;
    int w_X;
    int w_Y;
    int up;
    int down;
    int left;
    int right;
    int interacted;
    int jump;
} App;

typedef struct entity{
    int x;
    int y;
    int moveSpeed;
    int health;
    int framesCount;
    int increase;
    int increaseAmt;
    int increaseYAmt;
    int increaseMax;
    int currentFrame;
    int type;
    int id;
    char name;
    bool slowed;
    bool work;
    struct entity *next;
    SDL_Texture *texture;
    SDL_Texture *frames[];
} Entity;

typedef struct {
    Entity *start;
    int tam;
} List;

typedef struct {
    SDL_Texture *texture;
} UI_Entity;

extern App app;

#endif
