#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

#include "TestGrpcClientPart.h"
#include "TestGrpcServerPart.h"

using namespace std;

void StartConverterServer(const string& listenAddress)
{
    TestGrpcService::TestGrpsServer service;

    grpc::ServerBuilder builder;
    builder.SetMaxReceiveMessageSize(TestGrpcService::MaxMessageLength);
    builder.AddListeningPort(listenAddress, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    unique_ptr<grpc::Server> grpcServer(builder.BuildAndStart());

    printf("Server has been started\n");

    auto serverThread = std::thread([&]() { grpcServer->Wait(); });

    service.WaitForExit();

	grpcServer->Shutdown();
	serverThread.join();

    printf("Server has been stopped\n");
}

int main(int argc, char* argv[])
{
    printf("TestGrpcServer v1.0\n");
    
    StartConverterServer("localhost:50000");

    return 0;
}
