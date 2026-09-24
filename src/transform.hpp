#ifndef AGE_TRANSFORM_HPP
#define AGE_TRANSFORM_HPP

#include "component.hpp"

namespace age
{
    class transform : public component
    {
    public:
        transform();
        ~transform() = default;

        float m_x;
        float m_y;
    };
};

#endif