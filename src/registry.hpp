#ifndef AGE_REGISTRY_HPP
#define AGE_REGISTRY_HPP

#include "actor.hpp"
#include <cstdint>
#include <memory>
#include <vector>

namespace age
{    
    class registry
    {
    public:
        registry();
        ~registry();
        std::uint64_t create_actor();
        std::vector<std::unique_ptr<actor>> m_actors;
    
    private:    
        std::uint64_t m_next_actor_id;
    };
};

#endif