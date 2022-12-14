
#pragma once

#include "test_grpc_service.grpc.pb.h" //Autogenerated
#include "test_grpc_service.pb.h" //Autogenerated

#include <grpc++/grpc++.h>
#include <string>

namespace TestGrpcService
{
    const int MaxMessageLength = 4096;

    class TestGrpcClient
    {
	std::shared_ptr<grpc::Channel> channel;
	std::unique_ptr<TestGrpc::Stub> service;

	grpc::ChannelArguments CreateChannelArguments()
	{
	    grpc::ChannelArguments args;
	    args.SetMaxReceiveMessageSize(MaxMessageLength);
	    return args;
	}

	public:
	TestGrpcClient(const std::string& serverAddress) :
	    channel{ grpc::CreateCustomChannel(serverAddress,
	    grpc::InsecureChannelCredentials(),
	    CreateChannelArguments()) },
	service{ std::make_unique<TestGrpc::Stub>(channel) }
	{
	}

	//RPC method is called inside
	std::string ConvertIntToString(int intValue)
	{
	    TestGrpcService::ConversionRequest request;
	    TestGrpcService::ConversionResponse response;
	    grpc::ClientContext context;

	    response.Clear();

	    request.set_int_value(intValue);

	    grpc::Status status = service->ConvertIntToString(&context, request, &response);
	    if (!status.ok())
	    {
			throw std::runtime_error{ status.error_message() };
	    }

	    return response.string_value();
	}

	//RPC method is called inside
	double CalculateAvgValue(std::vector<int> intArray)
	{
		double avgValue = 0.0;
	    TestGrpcService::ArrayAvgRequest request;
	    TestGrpcService::ArrayAvgResponse response;
	    grpc::ClientContext context;

	    response.Clear();

		for (auto item : intArray)
		{
			request.add_int_value(item);
		}

		grpc::Status status = service->CalculateAvgValueByArray(&context, request, &response);
	    if (!status.ok())
	    {
			throw std::runtime_error{ status.error_message() };
	    }

		avgValue = response.avg_value();

		return avgValue;
	}

	//RPC method is called inside
	void StopServer()
	{
		grpc::ClientContext context;
		google::protobuf::Empty	request, response;
		
		grpc::Status status = service->StopServer(&context, request, &response);

		if (!status.ok())
	    {
			throw std::runtime_error{ status.error_message() };
	    }		
	}

	virtual ~TestGrpcClient() {};

	private:

	};
}
