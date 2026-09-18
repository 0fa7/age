#ifndef AGE_RENDER_SYSTEM_HPP
#define AGE_RENDER_SYSTEM_HPP

#include "actor.hpp"
#include <vector>

namespace age
{
    class render_system
    {
    public:
        render_system();
        ~render_system() = default;
        void update(std::vector<actor> actors);
    };
};

#endif