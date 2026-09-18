#include "registry.hpp"
#include "logger.hpp"
#include "render_system.hpp"
#include <iostream>
#include <string>

using namespace age;

registry::registry() :
    m_actors(std::vector<std::unique_ptr<actor>>(0)),
    m_next_actor_id(0)
{
    create_actor();
}

std::uint64_t registry::create_actor()
{   
    std::uint64_t current_id = m_next_actor_id;
    m_actors.emplace_back(std::move(std::make_unique<actor>(current_id)));
    g_logger.info("Created actor: " + std::to_string(current_id));
    m_next_actor_id++;
    return current_id;
}
