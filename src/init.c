#include "../include/init.h"


void initialize(){
    
    FILE *logs = fopen("logs.txt","a");

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
        fprintf(logs,"[init.c]ERR on window creation:%s\n",SDL_GetError());
    }

    SDL_Window *window = SDL_CreateWindow("game v0",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    testComponent(window,"window creation",logs);
    
    Uint32 render_flags = SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, render_flags);
    testComponent(renderer,"renderer creation",logs);

    SDL_Surface *pickaxeImage = IMG_Load("res/r.png");
    testComponent(pickaxeImage,"image creation",logs);

    SDL_Texture *pickaxeTexture = SDL_CreateTextureFromSurface(renderer,pickaxeImage);
    testComponent(pickaxeTexture,"texture creation",logs);

    SDL_RenderClear(renderer);
    
    // draw the image to the window
    SDL_RenderCopy(renderer, pickaxeTexture, NULL, NULL);
    SDL_RenderPresent(renderer);

}

void testComponent(void *component, char *operation, FILE *logs){

    if(!component){
        fprintf(logs,"[init.c]ERR on %s: %s\n",operation,SDL_GetError());
        SDL_Quit();
        exit(EXIT_FAILURE);
    }else{
        fprintf(logs,"[init.c] %s successful\n", operation);
    }
}
