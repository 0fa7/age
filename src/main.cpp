#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>


int main(int argc, char** argv)
{
    std::cout << "Hello, world";
    
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
        "Hello, world",
        2560,
        1440,
        0
    );

    if(window == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    SDL_GetWindowSurface(window);
    SDL_UpdateWindowSurface(window);

    bool is_running = true;
    SDL_Event event;

    while(is_running)
    {
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_EVENT_QUIT) 
            {
                is_running = false;

            }
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}