#include "actor.hpp"
#include "logger.hpp"
#include <iostream>

using namespace age;

actor::actor(std::uint64_t id) :
    m_id(id)
{
}

void actor::update()
{
    for(auto &component : m_components)
    {
        component->update();
    }
}

void actor::add_component(std::unique_ptr<component> component)
{
    m_components.push_back(std::move(component));
}