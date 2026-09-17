#include "actor.hpp"
#include "logger.hpp"
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
    //g_logger.info(m_id + " update");
}