#ifndef MAP_h
#define MAP_h

#include <stdio.h>
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/init.h"
#define UNIT_SIZE 50
#define HBU 12// a simplified version of SCREEN_HEIGHT/UNIT_SIZE. TO CHANGE in case of a modification of SCREEEN_HEIGHT or UNIT_SIZE
#define WBU 16


typedef struct Tile Tile;
struct Tile{//Tile structure
    SDL_Surface *tileImage;
    SDL_Texture *tileTexture;
    int collision;//1 if the tile can provoke a collision with the entities, 0 if not.     
};

Tile* composeTileArray(SDL_Renderer *renderer, Tile tileArray[3]);
void readMapData(int mapDataStorage[HBU][WBU]);
void drawMap(int mapDataStorage[HBU][WBU], Tile tileArray[], SDL_Renderer *renderer);
void mapAndTileInit(SDL_Renderer *renderer);

#endif