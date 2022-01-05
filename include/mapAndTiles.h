#ifndef MAP_h
#define MAP_h

#include <stdio.h>
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/init.h"
#define UNIT_SIZE 25

void readMapData();
void drawMap(int mapDataStorage[24][32], Tile tileArray[], SDL_Renderer *renderer);

typedef struct Tile Tile;
struct Tile{//Tile structure
    SDL_Surface *tileImage;
    SDL_Texture *tileTexture;
    int collision;//1 if the tile can provoke a collision with the entities, 0 if not.     
};

#endif