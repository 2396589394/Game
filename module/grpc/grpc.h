#ifndef __GRPC_H__
#define __GRPC_H__

#include "grpcConfig.h"
#include <grpcpp/grpcpp.h>

class Grpc
{
private:
    grpc::ServerBuilder builder_;

public:
    Grpc(GrpcConfig& config, grpc::Service* service);
    ˜Grpc();

    void run();
};

#endif