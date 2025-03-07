#include "Server.hpp"
#include <string>


namespace Dry
{

void Server::quit()
{
}

void Server::receiveData(std::vector<BatchData> batch)
{
	for (const auto& data : batch)
	{
		(map[data.word][data.file]) = data.count;
	}
}

void Server::respondToQuery(std::vector<std::string> query)
{
	unsigned int total = 0;
	for (const auto& word : query)
	{
		total = 0;
		auto& item = map[word];
		for (const auto& instance : item)
		{
			total += instance.second;
		}

		printf("Word: %s -- Total: %d\n", word.c_str(), total);
	}
}

}