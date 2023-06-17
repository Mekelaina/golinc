#include <stdio.h>

#include "SDL2/SDL.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480 

int main(int argc, char **argv){
    

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Failed to initialize the SDL2 library\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if(!window){
        printf("Failed to create window\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface){
        printf("Failed to get the surface from the window\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
        return -1;
    }

    SDL_Surface *image = SDL_LoadBMP("album.bmp");

    if(!image){
        printf("Failed to load image\n");
        printf("SDL2 Error: %s\n", SDL_GetError());
        return -1;
    }

    size_t running = 1;
    while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e) > 0){
            switch(e.type){
                case SDL_QUIT:
                    running = 0;
                    break;
                
                default:
                    break;
            }

            SDL_BlitSurface(image, NULL, window_surface, NULL);
            SDL_UpdateWindowSurface(window);
        }
    }
    

    return 0;
}