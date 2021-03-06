/*
*This file contains all of the methods related to the initialization of the game. 
*It also containsthe testComponent method, which is used throughout the program.
*/




#include "../include/init.h"


void initialize(){
    
    FILE *logs = fopen("logs.txt","a");

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(logs,"[init.c]ERR on SDL_Init:%s\n",SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("game v0",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    testComponent(window,"window creation", "[init.c]");
    
    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;//PROBLEM WITH THE RENDERER, TO CHECK TOMMOROW
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, render_flags);
    testComponent(renderer,"renderer creation", "[init.c]");
    

}

void testComponent(void *component, char *operation, char *fileName){// basic method to test if the component is NULL.

    FILE *logs = fopen("logs.txt","a");
    if(!component||!logs){
        fprintf(logs,"%SERR on %s: %s\n",fileName, operation,SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }else{
        fprintf(logs,"%sSUCCESS on %s \n",fileName, operation);
    }
    fclose(logs);
}
