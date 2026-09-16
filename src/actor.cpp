#include "actor.hpp"
#include <iostream>

using namespace age;

actor::actor(std::uint64_t id) :
    m_id(id)
{
}

actor::~actor()
{
}

void actor::update()
{
    std::cout << m_id << " update" << std::endl;
}