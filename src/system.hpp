#ifndef AGE_SYSTEM_HPP
#define AGE_SYSTEM_HPP

#include <memory>

namespace age
{

    class registry;

    enum class SystemType : std::uint64_t
    {
        RENDER = 0
    };

    class system
    {
    public:
        system() = default;
        virtual ~system();
        virtual void update(std::unique_ptr<registry> &reg);
    };
};

#endif
