#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>

#include "TestGrpcClientPart.h"

using namespace std;

unique_ptr<TestGrpcService::TestGrpcClient> InitConnection(const string& address);

void    Converter(TestGrpcService::TestGrpcClient* client);
void    CalculateAvgValue(TestGrpcService::TestGrpcClient* client);

int main(int argc, char* argv[])
{
    printf("TestGrpcClient v1.0\n");
    
    auto client = InitConnection("localhost:50000");

    if (client == nullptr)
        return 1;

    //Test methods call   
    Converter(client.get());
    CalculateAvgValue(client.get());

    //Stopping the server
    client.get()->StopServer();

#ifdef WIN32
    printf("Press Enter to exit\n");
    int value = getchar();
#endif // WIN32

    return 0; 
}

unique_ptr<TestGrpcService::TestGrpcClient> InitConnection(const string& address)
{
    unique_ptr<TestGrpcService::TestGrpcClient>	client;   

    try
    {
        client = make_unique<TestGrpcService::TestGrpcClient>(address);
    }
    catch(const std::exception& e)
    {
        printf("Connection can't be created\n");
        printf("%s\n", e.what());
    }

    return client;
}

void    Converter(TestGrpcService::TestGrpcClient* client)
{
    try
    {
    	int testValue = 12345;

	    std::string stringValue = client->ConvertIntToString(testValue);

	    printf("Source number %d\n", testValue);
	    printf("Result string %s\n", stringValue.c_str());
    }
    catch (std::exception& e)
    {
	    printf("Error message: %s\n", e.what());
    }    
}

void    CalculateAvgValue(TestGrpcService::TestGrpcClient* client)
{
    try
    {
    	std::vector<int> testArray({1, 2, 3, 5, 7, 9, 11});

	    double avgValue = client->CalculateAvgValue(testArray);

        printf("A test array for average calculation\n");
        for_each(testArray.begin(), testArray.end(), [](int value){ printf("%d ", value);});

        printf("\n");
	    printf("Average value %1.2lf\n", avgValue);
    }
    catch (std::exception& e)
    {
	    printf("Error message: %s\n", e.what());
    }    
}

