#ifndef AGE_RECTANGLE_HPP
#define AGE_RECTANGLE_HPP

#include <cstdint>

namespace age
{
    class rectangle
    {
    public:
        rectangle();
        ~rectangle() = default;
        float m_x_offset;
        float m_y_offset;
        std::uint64_t m_width;
        std::uint64_t m_height;
    };
};

#endif