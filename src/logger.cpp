#include "logger.hpp"
#include <iostream>

using namespace age;

logger::logger()
{
}

logger::~logger()
{
}

void logger::error(const std::string_view msg)
{
    std::cout << "[ERROR]: " << msg << std:: endl;
}

void logger::warn(const std::string_view msg)
{
    std::cout << "[WARN]: " << msg << std:: endl;
}

void logger::info(const std::string_view msg)
{
    std::cout << "[INFO]: " << msg << std:: endl;
}

void logger::debug(const std::string_view msg)
{
    std::cout << "[DEBUG]: " << msg << std:: endl;
}