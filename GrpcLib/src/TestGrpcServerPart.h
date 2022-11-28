
#pragma once
#include <grpcpp/grpcpp.h>

#include "test_grpc_service.grpc.pb.h"

namespace TestGrpcService
{
	class TestGrpsServerPart : public TestGrpcService::TestGrpc::Service
	{
	public:
		TestGrpsServerPart()
		{
		}
		virtual ~TestGrpsServerPart() {};

		//RPC method
		grpc::Status  ConvertIntTostring(grpc::ServerContext* context,
			const TestGrpcService::ConversionRequest* request,
			TestGrpcService::ConversionResponse* response) override
		{
			int	intValue = request->int_value();
			
			response->set_string_value(std::to_string(intValue));

			return grpc::Status::OK;
		}
	private:

	};
}

