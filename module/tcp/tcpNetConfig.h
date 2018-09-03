#ifndef __TCP_NET_CONFIG_H__
#define __TCP_NET_CONFIG_H__

struct TcpNetConfig{
    unsigned char threadNumber;
    unsigned short port;

    TcpNetConfig(const char* configFile)
    {

    }
};

#endif