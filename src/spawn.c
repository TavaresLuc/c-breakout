#include "../srch/structs.h"
#include "../srch/spawn.h"
#include "../srch/defs.h"
#include "../srch/draw.h"
#include "../srch/hero.h"
#include "../srch/sound.h"
#include <stdio.h>
#include <stdlib.h>

Entity *filaE = NULL;
Entity *filaM = NULL;
Entity *filaF = NULL;

Entity *r = NULL;
Entity baseEntityE;
Entity baseEntityM;
Entity baseEntityF;

Entity entities[3];
int increase[3];
int increaseY[3];

int collisionBox[] = {40,30};

void addEntity(Entity **spawn, int spn){
    Entity *aux, *entity = malloc(sizeof(Entity));
    if(entity){
        if(increase[spn] != 0){
            printf("\n The increase is: %i So the X will increase in: %i", increase[spn], entities[spn].increaseAmt);
            entity->x = entities[spn].x + (entities[spn].increaseAmt*increase[spn]);
            increase[spn] += 1;
            if(increase[spn] >= entities[spn].increaseMax){
                printf("\n Resetting the increase: %i", increase[spn]);
                increaseY[spn]++;
                increase[spn] = 0;
            }
        }else{
            increase[spn] += 1;
            entity->x = entities[spn].x;
        }


        entity->y = entities[spn].y + (entities[spn].increaseYAmt*increaseY[spn]);
        entity->moveSpeed = entities[spn].moveSpeed;
        entity->health = entities[spn].health;
        entity->texture = entities[spn].texture;
        entity->next = NULL;

        printf("\nAdding a new entity for x: %i the entity X is: %i and the Y is: %i", spn, entity->x, entity->y);
        
        // Caso a fila esteja NULL a gente vai iniciar ela com a entity criada como objeto
        if(*spawn == NULL){
          *spawn = entity;  
        }else{
            // Caso contrario a gente vai utilizar como auxiliar o objeto que estava armazenado no next;
            aux = *spawn;
            while(aux->next){
                aux = aux->next;
                // A gente vai entao pegar o next do auxiliar e assignar com a entity que criamos
            }
            aux->next = entity;
        }
        
    
    }else{
        // Caso nao seja possivel criar o entity a gente printa um erro de alolcacao de memoria
        printf("Erro de alocacao de memoria");
    }
}

Entity* removeEntity(Entity **spawn){
    Entity *remover = NULL;
    if(*spawn){
        //Se nao estiver null a gente vai remover o next
        remover = *spawn;
        //*spawn = remover->next;
    }else{
        //increase = 48;
        printf("Fila vazia!");
    }
    return remover;
}

void spawnRemove(int spn){
    playSound(SND_FILA_REMOVE, 1); 
    switch(spn){
        case 0:
                r = removeEntity(&filaE);
                if(r){
                    printf("\n Entity in the position: X%i Y%i will be dropped now!", r->x, r->y);
                    r->moveSpeed = 1;
                    /*increase -= 18;
                    printf("\n Removed memory for the first entity, the x is now at: %i", increase);
                    free(r);*/
                }
            break;
        case 1:
                r = removeEntity(&filaM);
                if(r){
                    printf("\n Entity in the position: X%i Y%i will be dropped now!", r->x, r->y);
                    r->moveSpeed = 4;
                    /*increase -= 18;
                    printf("\n Removed memory for the first entity, the x is now at: %i", increase);
                    free(r);*/
                }
            break;
        case 2:
                r = removeEntity(&filaF);
                if(r){
                    printf("\n Entity in the position: X%i Y%i will be dropped now!", r->x, r->y);
                    r->moveSpeed = 2;
                    /*increase -= 18;
                    printf("\n Removed memory for the first entity, the x is now at: %i", increase);
                    free(r);*/
                }
            break;
    }
}
void removeSpawn(Entity **spawn, int spn){
    Entity *remo = NULL;
    if(*spawn){
        remo = *spawn;
        *spawn = remo->next;
        spawnRemove(spn);
    }
}

void instaRemove(){
    Entity *remo = NULL;
    int r = rand() % 3;
    switch(r){
        case 0:
            removeSpawn(&filaE, r);
            break;
        case 1:
            removeSpawn(&filaM, r);
            break;
        case 2:
            removeSpawn(&filaF, r);
            break;
    }
    /*if(*spawn){
        remo = *spawn;
        *spawn = remo->next;
        spawnRemove();
    }*/
}

void readEntities(Entity **spawn, int spn){
    Entity *aux, *entity = NULL;
    if(*spawn){
        aux = *spawn;
        //printf("\n Entity na posicao X: %d e posicao Y: %d", aux->x, aux->y);
        //this is used to draw with an atlas:
        if(aux->moveSpeed != 0){
            if(aux->x + collisionBox[0] >= Hero.x && aux->x <= (Hero.x + 20) &&
               aux->y + collisionBox[1] >= Hero.y && aux->y <= (Hero.y + 20)){
                //instaRemove();
                switch(spn){
                    case 0:
                            removeSpawn(&filaE, 0);
                        break;
                    case 1:
                            removeSpawn(&filaM, 1);
                        break;
                    case 2:
                            removeSpawn(&filaF, 2);
                        break;
                }
                playSound(SND_PLAYER_COLLECT, 0);
                //removeSpawn(&spawn, spn);
                printf("\n Collided!");
            }
            aux->y += aux->moveSpeed;
        }
        if(aux->y >= (app.w_Y - 5)){
                switch(spn){
                    case 0:
                            removeSpawn(&filaE, 0);
                        break;
                    case 1:
                            removeSpawn(&filaM, 1);
                        break;
                    case 2:
                            removeSpawn(&filaF, 2);
                        break;
                }     
                playSound(SND_PLAYER_FAIL, 0);       
            //removeSpawn(**spawn, spn);
            //instaRemove();
        }
        blit(aux->texture, 3, aux->x, aux->y, 0, 0);
        //normal blit
        //blit(aux->texture, 1, aux->x, aux->y, 0);
        entity = aux->next;
        readEntities(&entity, spn);
    }
}

void add(){
    addEntity(&filaE, 0);
    addEntity(&filaM, 1);
    addEntity(&filaF, 2);
    /*increase += 30;
    if(increase >= (app.w_X)){
        increase = 30;
        yIncrease += 30;
    }*/
}

void initSpawn(){
    baseEntityF.x = app.w_X - 290;
    baseEntityF.y = 0;
    baseEntityF.moveSpeed = 0;
    baseEntityF.increase = 0;
    baseEntityF.increaseAmt = 52;
    baseEntityF.increaseYAmt = 52;
    baseEntityF.increaseMax = 5;
    baseEntityF.health = 10;
    baseEntityF.texture = loadTexture("resources/sprites/alexandre.png");

    baseEntityE = baseEntityF;
    baseEntityE.x = 32;

    baseEntityM = baseEntityF;
    baseEntityM.x= (app.w_X/2) - 100;

    entities[0] = baseEntityE;
    entities[1] = baseEntityM;
    entities[2] = baseEntityF;

    increase[0] = 0;
    increase[1] = 0;
    increase[2] = 0;

    increaseY[0] = 0;
    increaseY[1] = 0;
    increaseY[2] = 0;

    for (size_t i = 0; i < 40; i++)
    {
        /* code */  
        add();
    }
    
}

void readSpawn(){
    readEntities(&filaE, 0);
    readEntities(&filaM, 1);
    readEntities(&filaF, 2);
}
