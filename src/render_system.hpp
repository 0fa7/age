#ifndef AGE_RENDER_SYSTEM_HPP
#define AGE_RENDER_SYSTEM_HPP

#include "actor.hpp"
#include "system.hpp"
#include <vector>
#include <memory>

namespace age
{
    class registry;

    class render_system : public system
    {
    public:
        render_system();
        ~render_system() = default;
        virtual void update(std::unique_ptr<registry> &reg) override;
    };
};

#endif