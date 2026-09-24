#ifndef AGE_COMPONENT_HPP
#define AGE_COMPONENT_HPP

#include <cstdint>

namespace age
{
    enum class ComponentType : std::uint64_t
    {
        TRANSFORM = 0,
        SPRITE
    };

    class component
    {
    public:
        component() = default;
        virtual ~component();
        virtual void begin();
        virtual void update();
    };
};

#endif