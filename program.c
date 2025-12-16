#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Variables
#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900
#define AGENT_SIZE 2
#define SCALE 10

//Structure to hold the direction the agent will move
typedef struct Velocity {
    int vx;
    int vy;
} Velocity;

//Agent structure to hold its location and color
typedef struct Agent {
    int x, y;
    Uint32 color;
} Agent;


//Function to get a random velocity pair
Velocity get_rand_v() {
    // modular arithmetic will always give you a remainder between 0 and n-1
    int choice = rand() % 4;
    switch (choice) {
        //up
        case 0:
            return (Velocity) {0, -1};
        //down
        case 1:
            return (Velocity) {0, 1};
        //left
        case 2:
            return (Velocity) {-1, 0};
        //right
        case 3:
            return (Velocity) {1, 0};
    }
    exit(-1);
}

void move_agent(SDL_Surface *surface, Agent *agent) {
    SDL_Rect rect = (SDL_Rect) {agent->x, agent->y, AGENT_SIZE, AGENT_SIZE};
    Velocity vel = get_rand_v();
    for(int i = 0; i < SCALE; i++) {
        agent->x += vel.vx;
        agent->y += vel.vy;
        SDL_Rect rect = {agent->x, agent->y, AGENT_SIZE, AGENT_SIZE};
        SDL_FillSurfaceRect(surface, &rect, agent->color);
    }
}

//int argc is the number of arguments passed into the program
//int argv stores the all the arguments
int main(int argc, const char *argv[]) {
    int num_agents;

    if(argc == 1) num_agents = 5;
    
    //atoi converts string to int
    else if(argc == 2) num_agents = atoi(argv[1]);

    else {
        printf("Usage: %s <num-of-agents>\n", argv[0]);
        exit(-1);
    }

    srand(time(NULL));
    

    SDL_Window* window = SDL_CreateWindow("Random Walk", WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    

    SDL_Surface* surface = SDL_GetWindowSurface(window);

    
    //Creates array of agents
    Agent *pagent = malloc(sizeof(Agent) * num_agents);

    for(int i = 0; i < num_agents; i++) {
        Uint32 rand_color = (rand() % 256) << 16 | (rand() % 256) << 8 | (rand() % 256);
        pagent[i] = (Agent) {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, rand_color};
    }


    int app_running = 1;
    while(app_running) {

        SDL_Event event;

        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                app_running = 0;
            }
        }

        for(int i = 0; i < num_agents; i++) {
            move_agent(surface, &pagent[i]);
        }

        //Updates window from surface buffer
        SDL_UpdateWindowSurface(window);
        SDL_Delay(30);
    }
}
