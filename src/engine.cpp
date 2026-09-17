#include "engine.hpp"
#include "logger.hpp"
#include <iostream>
#include <stdexcept>
#include <SDL3/SDL.h>

using namespace age;

engine::engine() : m_is_running(true),
                   m_renderer(nullptr),
                   m_window(nullptr),
                   m_current_time(0),
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
    g_logger.info("Initializing age engine...");

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

    update_time();

    g_logger.info("Initialization complete.");
}

void engine::run()
{
    setup_world();

    while (m_is_running)
    {

        process_input();
        update_world();
        render();

        update_time();
    }
}

void engine::setup_world()
{
    m_registry.create_actor();
}

void engine::process_input()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_KEY_DOWN:
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
    for(const auto &current_actor : m_registry.m_actors)
    {
        current_actor->update();
    }
}

void engine::render()
{
    // set bg color & draw
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    // layer game objects on to fresh canvas

    SDL_RenderPresent(m_renderer);
}

void engine::update_time()
{
    std::uint64_t new_time = SDL_GetTicks();
    m_delta_time = new_time - m_current_time;
    m_current_time = new_time;
}

void engine::wait_to_next_frame()
{
    if(m_delta_time > AGE_MS_PER_FRAME)
    {
        return;
    }

    uint64_t time_to_wait = AGE_MS_PER_FRAME - m_delta_time;
    SDL_Delay(time_to_wait);
}