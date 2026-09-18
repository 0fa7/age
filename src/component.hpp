#ifndef AGE_COMPONENT_HPP
#define AGE_COMPONENT_HPP

namespace age
{
    class component
    {
    public:
        component() = default;
        virtual ~component() = default;
        virtual void begin();
        virtual void update();
    };
};

#endif