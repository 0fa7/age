#ifndef AGE_REGISTRY_HPP
#define AGE_REGISTRY_HPP

#include "actor.hpp"
#include "system.hpp"
#include <memory>
#include <vector>

namespace age
{    
    class registry
    {
    public:
        registry();
        ~registry() = default;
        std::uint64_t create_actor();
        void create_system();
        std::vector<std::unique_ptr<actor>> m_actors;
        std::vector<std::unique_ptr<system>> m_systems;
    
    private:    
        std::uint64_t m_next_actor_id;
    };
};

#endif