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

        new->next = list.start;
        new->type = t;
        list.start = new;
        list.tam++;
        printf("Created a %i type character on position %i", t, list.tam);
    }else{
        printf("Erro ao alocar memoria! \n");
    }
}

