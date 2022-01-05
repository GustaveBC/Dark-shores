// this file contains all of the methods related to map-drawing .


#include "../include/mapAndTiles.h"

void readMapData(){

    int mapDataStorage[24][32] = {0};// this map will contain the data of map.map file. 24 and 32 represent the number of tiles in x and y
    char tempChar = 0;

    FILE *mapData = fopen("map.map","r");
    testComponent(mapData,"mapData opening","[map.c]");

    for(int i = 0; i<24; i++){// stores the value from map.map in mapData
        for(int u = 0; u<32; u++){
            mapDataStorage[i][u] = fgetc(mapData);
        }
    }
    for(int i = 0; i<24; i++){// stores the value from map.map in mapData
        for(int u = 0; u<32; u++){
           printf("%c", mapDataStorage[i][u]);// FIXME: prints a square of 32 by 24, but the 24th row only has 
        }
    }
    
}

void composeTileArray(SDL_Renderer *renderer){

    Tile tileArray[3];

    tileArray[0].tileImage = IMG_Load("res/ds_water.png");
    tileArray[0].tileTexture = SDL_CreateTextureFromSurface(renderer,tileArray[0].tileImage);
    tileArray[0].collision = 1;

    tileArray[1].tileImage = IMG_Load("res/ds_grass.png");
    tileArray[1].tileTexture = SDL_CreateTextureFromSurface(renderer,tileArray[1].tileImage);
    tileArray[1].collision = 1;

    tileArray[2].tileImage = IMG_Load("res/ds_sand.png");
    tileArray[2].tileTexture = SDL_CreateTextureFromSurface(renderer,tileArray[2].tileImage);
    tileArray[2].collision = 1;
}

void drawMap(int mapDataStorage[24][32], Tile tileArray[], SDL_Renderer *renderer){
    SDL_RenderClear(renderer);
     for(int i = 0; i<SCREEN_HEIGHT; i += UNIT_SIZE){// stores the value from map.map in mapData
        for(int u = 0; u<SCREEN_WIDTH; u += UNIT_SIZE){

        }
    }
}