#ifndef AGE_SYSTEM_HPP
#define AGE_SYSTEM_HPP

#include <memory>

namespace age
{

    class registry;

    enum SystemType : std::uint64_t
    {
        RENDER = 0,
        MOVEMENT,
        INPUT
    };

    class system
    {
    public:
        system();
        system(system &other) = default;
        virtual ~system();
        virtual void update(std::unique_ptr<registry> &reg);
    };
};

#endif
