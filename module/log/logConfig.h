#ifndef __LOG_CONFIG_H__
#define __LOG_CONFIG_H__

struct LogConfig{
    char fileName[20];      // 日志输出文件名

    LogConfig(const char* configFile)
    {
        
    }
};

#endif