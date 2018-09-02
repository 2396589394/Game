#include "log.h"
#include <stdarg.h>

boost::log::sources::severity_logger<boost::log::trivial::severity_level > Log::lg_;

void Log::init(LogConfig& config)
{
    boost::log::add_file_log
    (
        boost::log::keywords::file_name = config.fileName,                                        /*< file name pattern >*/
        boost::log::keywords::rotation_size = 10 * 1024 * 1024,                                   /*< rotate files every 10 MiB... >*/
        boost::log::keywords::time_based_rotation = boost::log::sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
        boost::log::keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
    );

    boost::log::core::get()->set_filter
    (
        boost::log::trivial::severity >= boost::log::trivial::info
    );

    boost::log::add_common_attributes();
}

void Log::printf_info(const char* format, ...)
{
    va_list marker;
    va_start(marker, format);
    
    char message[200];
    sprintf(message, format, marker);
    
    va_end(marker);

    BOOST_LOG_SEV(Log::lg_, boost::log::trivial::info) << message;
}

void Log::printf_debug(const char* format, ...)
{
    va_list marker;
    va_start(marker, format);
    
    char message[200];
    sprintf(message, format, marker);
    
    va_end(marker);

    BOOST_LOG_SEV(Log::lg_, boost::log::trivial::debug) << message;
}

void Log::printf_warn(const char* format, ...)
{
    va_list marker;
    va_start(marker, format);
    
    char message[200];
    sprintf(message, format, marker);
    
    va_end(marker);

    BOOST_LOG_SEV(Log::lg_, boost::log::trivial::warning) << message;
}

void Log::printf_error(const char* format, ...)
{
    va_list marker;
    va_start(marker, format);
    
    char message[200];
    sprintf(message, format, marker);
    
    va_end(marker);

    BOOST_LOG_SEV(Log::lg_, boost::log::trivial::error) << message;
}