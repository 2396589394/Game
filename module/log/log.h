#ifndef __LOG_H__
#define __LOG_H__

#include "logConfig.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

class Log
{
private:
    static boost::log::sources::severity_logger<boost::log::trivial::severity_level > lg_;

public:
    Log() = delete;
    ˜Log() = delete;

    static void init(LogConfig& config);
    static void printf_info(const char* fromat, ...);
    static void printf_debug(const char* fromat, ...);
    static void printf_warn(const char* fromat, ...);
    static void printf_error(const char* fromat, ...);
};

#endif
