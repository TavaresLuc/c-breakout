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

void initSpawn(){
    list.start = NULL;
    list.tam = 0;

    for (size_t i = 0; i < STUDENTS_AMOUNT; i++)
    {
        /* code */
        addEntity();
    }
    
}

void addEntity(){
    Entity *new = malloc(sizeof(Entity));

    if(new){
        int t = rand() % 6;
        int x = rand() % 335;
        int y = rand() % 135;

        int negativeX = rand() % 2;
        int negativeY = rand() % 2;

        if(negativeX == 0)
            x = -x;
        if(negativeY == 0)
            y = -y;

        new->next = list.start;
        new->type = t;
        new->x = Hero.x + x;
        new->y = Hero.y + y;
        new->id = list.tam;
        new->texture = NULL;
        switch(t){
            case 0:
            break;
            case 1:
            break;
            case 2:
                new->texture = loadTexture("resources/sprites/venancio.png");
            break;
            case 3:
            break;
            case 4:
            break;
        }
        list.start = new;
        list.tam++;
        printf("Created a %i type character on position %i", t, list.tam);
    }else{
        printf("Erro ao alocar memoria! \n");
    }
}

Entity* getEntity(int num){
    Entity *aux = NULL;

    aux = list.start;
    if(aux->id == num){
        return aux;
    }else{
        while(aux->next && aux->next->id != num){
            aux = aux->next;
        }
        if(aux->next->id == num){
            printf("Returning entity for.. %i", aux->id);
            return aux;
        }
    }
    return NULL;
}

