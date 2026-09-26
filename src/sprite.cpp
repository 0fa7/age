#include "sprite.hpp"

using namespace age;

sprite::sprite() :
    m_x_offset(0.0f),
    m_y_offset(0.0f),
    m_width(0),
    m_height(0),
    m_r(0),
    m_g(0),
    m_b(0),
    m_a(0),
    m_layer(0),
    component(ComponentType::SPRITE)
{
}