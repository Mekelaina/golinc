#include <stdio.h>

#include "SDL2/SDL.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480 

int main(int argc, char **argv){
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Failed to initialize the SDL2 library\n");
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if(!window){
        printf("Failed to create window\n");
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface){
        printf("Failed to get the surface from the window\n");
        return -1;
    }

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    return 0;
}