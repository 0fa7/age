#ifndef AGE_REGISTRY_HPP
#define AGE_REGISTRY_HPP

#include "actor.hpp"
#include "render_system.hpp"
#include <cstdint>
#include <memory>
#include <vector>

namespace age
{    
    class render_system;
    
    class registry
    {
    public:
        registry();
        ~registry() = default;
        std::uint64_t create_actor();
        std::vector<std::unique_ptr<actor>> m_actors;
        std::vector<std::unique_ptr<render_system>> m_systems;
    
    private:    
        std::uint64_t m_next_actor_id;
    };
};

#endif