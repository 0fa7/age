#ifndef AGE_ENGINE_HPP
#define AGE_ENGINE_HPP

#include <cstdint>

class SDL_Renderer;
class SDL_Window;

#define AGE_FIXED_FPS 60

namespace age
{
    class engine
    {
    public:
        engine();
        ~engine();
        void run();

    private:
        void initialize();
        void process_input();
        void update_world();
        void render();

        bool m_is_running;
        SDL_Renderer *m_renderer;
        SDL_Window *m_window;
        std::uint64_t m_delta_time;
    };
};

#endif