#include "engine.hpp"
#include <SDL3/SDL_main.h>

int main(int argc, char **argv)
{
    auto engine = age::engine();
    engine.run();
    return 0;
}
