// FileRetrievalEngine.cpp : Defines the entry point for the application.
//

#include "FileRetrievalEngine.h"
#include <mutex>

using namespace std;

int main()
{
	Dry::Server server{};
	Dry::Client client0(server);
	
	client0.index("C:/Users/whend/source/repos/FileRetrievalEngine/data/Dataset1/folder1");
	
	std::vector<string> words = { "the", "help" };
	server.respondToQuery(words);

	return 0;
}
