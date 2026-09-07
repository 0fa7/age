#ifndef AGE_ENGINE_HPP
#define AGE_ENGINE_HPP

#include <memory>

class SDL_Window;

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
        SDL_Window *m_window;
    };
};

#endif