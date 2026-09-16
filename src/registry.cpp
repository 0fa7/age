#include "registry.hpp"
#include "actor.hpp"
#include <iostream>

using namespace age;

registry::registry() :
    m_actors(std::vector<std::unique_ptr<actor>>(0)),
    m_next_actor_id(1)
{
}

registry::~registry()
{
}

std::uint64_t registry::create_actor()
{   
    std::uint64_t current_id = m_next_actor_id;
    m_actors.emplace_back(std::move(std::make_unique<actor>(current_id)));
    std::cout << "Created actor: " << current_id << std::endl;
    m_next_actor_id++;
    return current_id;
}
