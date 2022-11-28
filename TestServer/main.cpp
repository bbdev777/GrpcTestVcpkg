#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

#include "TestGrpcClientPart.h"
#include "TestGrpcServerPart.h"

using namespace std;

void StartConvertorServer(const string& listenAddress)
{
    TestGrpcService::TestGrpsServerPart service;

    grpc::ServerBuilder builder;
    builder.SetMaxReceiveMessageSize(TestGrpcService::MaxMessageLength);
    builder.AddListeningPort(listenAddress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    unique_ptr<grpc::Server> grpcServer(builder.BuildAndStart());
    grpcServer->Wait();
}

int main(int argc, char* argv[])
{
    printf("TestGrpcServer v1.0\n");
    
    StartConvertorServer("localhost:50000");

    return 0;
}
