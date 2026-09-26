#ifndef AGE_SPRITE_HPP
#define AGE_SPRITE_HPP

#include "component.hpp"
#include <cstdint>

namespace age
{
    class sprite : public component
    {
    public:
        sprite();
        ~sprite() = default;
        float m_x_offset;
        float m_y_offset;
        std::uint64_t m_width;
        std::uint64_t m_height;
        std::uint64_t m_r;
        std::uint64_t m_g;
        std::uint64_t m_b;
        std::uint64_t m_a;
        std::uint64_t m_layer;
    };
};

#endif