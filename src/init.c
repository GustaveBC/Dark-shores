/*
*This file contains all of the methods related to the initialization of the game. 
*It also containsthe testComponent method, which is used throughout the program.
*/




#include "../include/init.h"


void initialize(){
    
    FILE *logs = fopen("logs.txt","a");

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(logs,"[init.c]ERR on window creation:%s\n",SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("game v0",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    testComponent(window,"window creation", "[init.c]");
    
    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, render_flags);
    testComponent(renderer,"renderer creation", "[init.c]");

    SDL_Surface *tempImage = IMG_Load("res/temporary.png");
    testComponent(tempImage,"image creation", "[init.c]");

    SDL_Texture *tempTexture = SDL_CreateTextureFromSurface(renderer,tempImage);
    testComponent(tempTexture,"texture creation", "[init.c]");

    SDL_RenderClear(renderer);
    
    // draw the image to the window
    SDL_RenderCopy(renderer, tempTexture, NULL, NULL);
    SDL_RenderPresent(renderer);

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
