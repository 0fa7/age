#ifndef AGE_ACTOR_HPP
#define AGE_ACTOR_HPP

#include <cstdint>
#include <unordered_map>
#include <vector>

class actor_component;

namespace age
{
    class actor
    {
    public:
        actor() = default;
        actor(std::uint64_t id);
        actor(actor &other) = default;
        ~actor();
        void update();
    private:
        std::uint64_t m_id;
    };
};

#endif