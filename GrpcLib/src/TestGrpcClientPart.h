
#pragma once

#include "test_grpc_service.grpc.pb.h"
#include "test_grpc_service.pb.h"

#include <grpc++/grpc++.h>
#include <string>

namespace TestGrpcService
{
	const int	MaxMessageLength = 4096;

	class TestGrpcConverter
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
		TestGrpcConverter(const std::string& serverAddress) :
			channel{ grpc::CreateCustomChannel(serverAddress,
										  grpc::InsecureChannelCredentials(),
										  CreateChannelArguments()) },
			service{ std::make_unique<TestGrpc::Stub>(channel) }
		{
		}

		//RPC method
		std::string	ConvertIntToString(int intValue)
		{
			TestGrpcService::ConversionRequest request;
			TestGrpcService::ConversionResponse response;
			grpc::ClientContext context;

			response.Clear();

			request.set_int_value(intValue);

			grpc::Status status = service->ConvertIntTostring(&context, request, &response);
			if (!status.ok())
			{
				throw std::runtime_error{ status.error_message() };
			}

			return response.string_value();
		}

		virtual ~TestGrpcConverter() {};

	private:

	};
}