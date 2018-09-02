#ifndef __GRPC_CONFIG_H__
#define __GRPC_CONFIG_H__

struct GrpcConfig{
    unsigned char serverNumber;
    char address[30];

    GrpcConfig(const char* configFile)
    {

    }
};

#endif