#include "grpc.h"

Grpc::Grpc(GrpcConfig& config, grpc::Service* service)
{
    this->builder_.AddListeningPort(config.address, grpc::InsecureServerCredentials());

    for(int i = 0; i < config.serverNumber; i++)
    {
        this->builder_.RegisterService(service);
    }
}