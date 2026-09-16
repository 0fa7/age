#ifndef AGE_ENGINE_HPP
#define AGE_ENGINE_HPP

#include "registry.hpp"
#include <cstdint>
#include <memory>

class SDL_Renderer;
class SDL_Window;

#define AGE_FPS 60.0
#define AGE_MS_PER_FRAME 16.67

namespace age
{
    class engine
    {
    public:
        engine();
        ~engine();
        void run();
        void setup_world();

    private:
        void initialize();
        void process_input();
        void update_world();
        void render();
        void update_time();
        void wait_to_next_frame();
        bool m_is_running;
        SDL_Renderer *m_renderer;
        SDL_Window *m_window;
        std::uint64_t m_current_time;
        std::uint64_t m_delta_time;
        registry m_registry;
    };
};

#endif