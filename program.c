//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>


//int argc is the number of arguments passed into the program
//int argv is 
int main(int argc, const char *argv[]) {
    int num_agents;

    if(argc == 0) num_agents = 5;

    if(argc == 1) num_agents = atoi(argv[1]);

    else printf("Usage: %s <num-of-agents>\n", argv[0]);
}
