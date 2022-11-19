#ifdef __linux__
#include <SDL2/SDL.h>
#endif

#ifdef _WIN32
#include "../srch/include/SDL2/SDL.h"
#endif

#include "../srch/structs.h"
#include "../srch/spawn.h"
#include "../srch/defs.h"
#include "../srch/draw.h"
#include "../srch/hero.h"
#include "../srch/sound.h"
#include <stdio.h>
#include <stdlib.h>

List list;
List wallList;
SDL_Texture *textures[7];

int x, y;
int wallListX, wallListY;

void initSpawn(){
    list.start = NULL;
    list.tam = 0;

    wallList.start = NULL;
    wallList.tam = 0;

    textures[0] = loadTexture("resources/sprites/block.png");
    textures[1] = loadTexture("resources/sprites/block_damaged1.png");
    textures[2] = loadTexture("resources/sprites/block_damaged2.png");
    textures[3] = loadTexture("resources/sprites/block_damaged3.png");
    textures[4] = loadTexture("resources/sprites/block_destroyed.png");
    textures[5] = loadTexture("resources/sprites/wall.png");
    textures[6] = loadTexture("resources/sprites/block_egg.png");

    x = 32;
    y = 50;

    wallListX = 0;
    wallListY = app.w_Y - 180;


    /* spawning the blocks */
    for (size_t i = 0; i < BLOCKS_AMOUNT_1; i++)
    {
        /* code */
        addEntity(32, 0);
    }
    for (size_t i = 0; i < BLOCKS_AMOUNT_2; i++)
    {
        /* code */
        addEntity(0, 16);
    }
    for (size_t i = 0; i < BLOCKS_AMOUNT_1; i++)
    {
        /* code */
        addEntity(-32, 0);
    }
    x = 32;
    y = 50;
    for (size_t i = 0; i < BLOCKS_AMOUNT_2+1; i++)
    {
        /* code */
        addEntity(0, 16);
    }
    x = 96;
    y = 114;
    for (size_t i = 0; i < BLOCKS_AMOUNT_1-3; i++)
    {
        /* code */
        addEntity(32, 0);
    }
    x = 96;
    y = 228;
    for (size_t i = 0; i < BLOCKS_AMOUNT_1-3; i++)
    {
        /* code */
        addEntity(32, 0);
    }
    x = 96;
    y = 312;
    for (size_t i = 0; i < 2; i++)
    {
        /* code */
        addEntity(32, 0);
    }
    x = 898;
    y = 312;
    for (size_t i = 0; i < 2; i++)
    {
        /* code */
        addEntity(-32, 0);
    }
    for (size_t i = 0; i < WALLS_AMOUNT; i++)
    {
        /* code */
        addWall();
    }
    
    
}

void addEntity(int xx, int yy){
    Entity *new = malloc(sizeof(Entity));

    if(new){     

        new->next = list.start;
        new->x = x;
        new->y = y;
        new->health = 0;
        new->id = list.tam;
        new->texture = textures[new->health];
        int i = rand() % 350;
        if(i <= 25)
            new->texture = textures[6];
        list.start = new;
        list.tam++;
        x+=xx;
        y+=yy;

    }else{
        printf("Erro ao alocar memoria! \n");
    }
}
void addWall(){
    Entity *new = malloc(sizeof(Entity));

    if(new){     

        new->next = wallList.start;
        new->x = wallListX;
        new->y = wallListY;
        new->health = 0;
        new->id = wallList.tam;
        new->texture = textures[5];
        wallList.start = new;
        wallList.tam++;
        wallListX += 180;
    }else{
        printf("Erro ao alocar memoria! \n");
    }
}


Entity* getEntity(int num, List list){
    Entity *aux = NULL;

    aux = list.start;
    if(aux->id == num){
        return aux;
    }else{
        while(aux->next && aux->next->id != num){
            aux = aux->next;
        }
        if(aux->next->id == num){
            return aux;
        }
    }
    return NULL;
}

