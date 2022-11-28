#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

#include "TestGrpcClientPart.h"

using namespace std;

int main(int argc, char* argv[])
{
	printf("TestGrpcClient v1.0\n");
	
	TestGrpcService::TestGrpcConverter	converter("localhost:50000");

	try
	{
		int		testValue = 12345;

		std::string stringValue = converter.ConvertIntToString(testValue);

		printf("Source number %d\n", testValue);
		printf("Result string %s\n", stringValue.c_str());
	}
	catch (std::exception& e)
	{
		printf("Error message: %s\n", e.what());
	}

#ifdef WIN32
	printf("Press Enter to exit\n");
	int value = getchar();
#endif // WIN32

	return 0; 
}
