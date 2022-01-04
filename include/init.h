#ifndef INIT_h
#define INIT_h

#include <stdio.h>
#include"../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#define SCREEN_HEIGHT 600
#define SCREEN_WIDTH 800

void initialize();
void testComponent(void *component,char *operation, FILE *logs);

#endif