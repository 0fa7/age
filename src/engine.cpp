#include "engine.hpp"
#include <iostream>
#include <SDL3/SDL.h>

using namespace age;

engine::engine() : m_is_running(true),
                   m_window(nullptr)
{
    initialize();
}

engine::~engine()
{
    if(m_window != nullptr)
    {
        SDL_DestroyWindow(m_window);
    }
    SDL_Quit();
}

struct SDLWindowDeleter
{
    void operator()(SDL_Window *window) const
    {
        if (window != nullptr)
        {
            
        }
    }
};

void engine::initialize()
{
    std::cout << "Initializing age engine..." << std::endl;

    SDL_Init(SDL_INIT_VIDEO);

    m_window = SDL_CreateWindow(
        "age",
        2560,
        1440,
        0);

    if (m_window == nullptr)
    {
        std::cout << SDL_GetError() << std::endl;
    }

    SDL_GetWindowSurface(m_window);
    SDL_UpdateWindowSurface(m_window);

    std::cout << "Initialization complete.";
}

void engine::run()
{
    while (m_is_running)
    {
        process_input();
        update_world();
        render();
    }
}

void engine::process_input()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_KEY_DOWN:
            // Check if the pressed key is Escape
            if (event.key.key == SDLK_ESCAPE)
            {
                m_is_running = false;
            }
            break;

        case SDL_EVENT_QUIT:
            m_is_running = false;
            break;
        default:
            break;
        }
    }
}

void engine::update_world()
{
}

void engine::render()
{
}