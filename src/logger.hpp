#ifndef AGE_LOGGER_HPP
#define AGE_LOGGER_HPP

#include <string_view>

namespace age
{
    class logger
    {
    public:
        logger();
        ~logger();
        void error(const std::string_view msg);
        void warn(const std::string_view msg);
        void info(const std::string_view msg);
        void debug(const std::string_view msg);
    };

    inline logger g_logger; 
};

#endif