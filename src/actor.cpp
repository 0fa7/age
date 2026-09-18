#include "actor.hpp"
#include "logger.hpp"
#include <iostream>

using namespace age;

actor::actor(std::uint64_t id) :
    m_id(id)
{
}

void actor::add_component(std::unique_ptr<component> component)
{
}