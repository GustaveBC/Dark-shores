#define SDL_MAIN_HANDLED
#include "include/SDL2/SDL.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int main(int argc, char* args[]) {
  SDL_version nb;
  SDL_VERSION(&nb);

  printf("%d.%d.%d",nb.major,nb.minor,nb.patch);
}