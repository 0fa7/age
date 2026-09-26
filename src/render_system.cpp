#include "render_system.hpp"
#include "logger.hpp"
#include "registry.hpp"

using namespace age;

render_system::render_system() :
    system::system()
{
}

void render_system::update(std::unique_ptr<registry> &reg)
{
    for(auto &actor : reg->m_actors)
    {
        for(auto &component : actor->m_components)
        {
            if(component->m_type == ComponentType::SPRITE)
            {
            
            }
        }
    }
}