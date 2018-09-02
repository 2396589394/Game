#ifndef __NET_CONFIG_H__
#define __NET_CONFIG_H__

struct NetConfig{
    unsigned char threadNumber;
    unsigned short port;

    NetConfig(const char* configFile)
    {

    }
};

#endif