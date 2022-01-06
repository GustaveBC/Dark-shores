// this file contains all of the methods related to map-drawing .


#include "../include/mapAndTiles.h"

void mapAndTileInit(SDL_Renderer *renderer){
    FILE *logs = fopen("logs.txt","a");
    fprintf(logs,"hey");
    int mapDataStorage[HBU][WBU];// this map will contain the data of map.map file. 24 and 32 represent the number of tiles in x and 
    readMapData(mapDataStorage);
    Tile tileArray[3];
    testComponent(tileArray,"tileArray init","[map.c]");
    composeTileArray(renderer, tileArray);
    drawMap(mapDataStorage, tileArray, renderer);
}


void readMapData(int mapDataStorage[HBU][WBU]){

    FILE *mapData = fopen("map.map","r");
    testComponent(mapData,"mapData opening","[map.c]");

    for(int i = 0; i<HBU; i++){// stores the value from map.map in mapData
        for(int u = 0; u<WBU; u++){
            mapDataStorage[i][u] = fgetc(mapData);
        }
    }
    for(int i = 0; i<HBU; i++){// stores the value from map.map in mapData
        for(int u = 0; u<WBU; u++){
           printf("%c", mapDataStorage[i][u]);// FIXME: prints a square of 32 by 24, but the 24th row only has 
        }
    }
}

Tile* composeTileArray(SDL_Renderer *renderer, Tile tileArray[3]){


    tileArray[0].tileImage = IMG_Load("res/ds_water.png");
    tileArray[0].tileTexture = SDL_CreateTextureFromSurface(renderer,tileArray[0].tileImage);
    tileArray[0].collision = 1;

    tileArray[1].tileImage = IMG_Load("res/ds_grass.png");
    tileArray[1].tileTexture = SDL_CreateTextureFromSurface(renderer,tileArray[1].tileImage);
    tileArray[1].collision = 1;

    tileArray[2].tileImage = IMG_Load("res/ds_sand.png");
    tileArray[2].tileTexture = SDL_CreateTextureFromSurface(renderer,tileArray[2].tileImage);
    tileArray[2].collision = 1;

    return tileArray;
}

void drawMap(int mapDataStorage[HBU][WBU], Tile tileArray[], SDL_Renderer *renderer){
    SDL_RenderClear(renderer);
    testComponent(renderer,"ezfzef","[map.c]");

    SDL_Rect dest;
    dest.h = 50;
    dest.w = 50;

     for(int i = 0; i<SCREEN_WIDTH; i += UNIT_SIZE){// stores the value from map.map in mapData
        for(int u = 0; u<SCREEN_WIDTH; u += UNIT_SIZE){
            testComponent(renderer,"zefzef","[map.c]");
            dest.x = u;
            dest.y = i;
            testComponent(tileArray[mapDataStorage[i/UNIT_SIZE][u/UNIT_SIZE]].tileTexture,"zef","[map.c]");
            if(SDL_RenderCopy(renderer,tileArray[mapDataStorage[i/UNIT_SIZE][u/UNIT_SIZE]].tileTexture,NULL,&dest)<0){
                SDL_Log(SDL_GetError());
            }
            SDL_RenderPresent(renderer);
            testComponent(renderer,"z2435235f","[map.c]");
        }
    }
    testComponent(renderer,"drawMAP","[map.c]");
}
