#ifndef AGE_COMPONENT_HPP
#define AGE_COMPONENT_HPP

#include <cstdint>

namespace age
{
    enum ComponentType : std::uint64_t
    {
        TRANSFORM = 0,
        SPRITE
    };

    class component
    {
    public:
        component() = delete;
        component(ComponentType type);
        virtual ~component();
        virtual void begin();
        virtual void update();
        ComponentType m_type;
    };
};

#endif