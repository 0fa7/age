#include "engine.hpp"
#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>

using namespace age;

engine::engine() : m_is_running(true),
                    m_renderer(nullptr),
                    m_window(nullptr),
                    m_delta_time(0)
{
    initialize();
}

engine::~engine()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;
    SDL_DestroyWindow(m_window);
    m_window = nullptr;
    SDL_Quit();
}

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
        std::string err_msg = "SHIT HAPPENS: ";
        err_msg += SDL_GetError(); 
        throw std::runtime_error(err_msg);
    }
    
    m_renderer = SDL_CreateRenderer(m_window, "direct3d12");

    if (m_renderer == nullptr)
    {
        std::string err_msg = "SHIT HAPPENS: ";
        err_msg += SDL_GetError(); 
        throw std::runtime_error(err_msg);
    }
    
    SDL_GetWindowSurface(m_window);
    SDL_UpdateWindowSurface(m_window);

    m_delta_time = SDL_GetTicks();

    std::cout << "Initialization complete.";
}

void engine::run()
{
    while (m_is_running)
    {
        process_input();
        update_world();
        render();
        m_delta_time = SDL_GetTicks();
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
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(m_renderer);
}