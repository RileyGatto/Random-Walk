//Libraries
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 600

//int argc is the number of arguments passed into the program
//int argv stores the all the arguments
int main(int argc, const char *argv[]) {
    int num_agents;

    if(argc == 1) num_agents = 5;
    
    //atoi converts string to int
    else if(argc == 2) num_agents = atoi(argv[1]);

    else printf("Usage: %s <num-of-agents>\n", argv[0]);
    
    SDL_Window* window = SDL_CreateWindow("Random Walk", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    
    int app_running = 1;
    while(app_running) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                app_running = 0;
            }
        }
    }
}
