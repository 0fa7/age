#ifndef AGE_ACTOR_HPP
#define AGE_ACTOR_HPP

#include "component.hpp"
#include <cstdint>
#include <memory>
#include <unordered_map>

namespace age
{
    class actor
    {
    public:
        actor() = default;
        actor(std::uint64_t id);
        actor(actor &other) = default;
        ~actor() = default;
        void add_component(std::unique_ptr<component> component);
    private:
        std::uint64_t m_id;
        std::unordered_map<std::uint64_t, std::unique_ptr<component>> m_components;
    };
};

#endif