#ifndef SERVER_HPP
#define SERVER_HPP

#include <unordered_map>
#include <string>
#include "BatchData.hpp"

namespace Dry
{
	class Server
	{
	public:
		void quit();

		void receiveData(std::vector<BatchData> batch);
		void respondToQuery(std::vector<std::string> query);
	private:
		std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>> map;
	};
}

#endif // !SERVER_HPP
