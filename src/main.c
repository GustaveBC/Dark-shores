#include "../include/main.h"

int main(int argc, char* args[]) {

  initialize();
  readMapData();
  SDL_Delay(6000);
  SDL_Quit();
  return 1;
}