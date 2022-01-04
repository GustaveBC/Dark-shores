// this file contains all of the methods related to map-drawing .


#include "../include/map.h"

void readMapData(){

    int mapDataStorage[SCREEN_HEIGHT/UNIT_SIZE][SCREEN_WIDTH/UNIT_SIZE] = {0};// this map will contain the data of map.map file
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
           printf("%c", mapDataStorage[i][u]);
        }
    }
    
}