#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <string>
#include <unordered_map>
#include "Server.hpp"
#include "BatchData.hpp"
#include "AlphaNumTrie.hpp"

namespace Dry
{
	// TODO - fix dependency on server and move it to gRPC
	class Client
	{
	public:
		Client(Server&);


		void quit();
		void index(std::string dataset_path);
		void search(std::string query);
	private:

		std::vector<BatchData> batchData();
		
		Server& server;

		//AlphaNumTrie m_trie;
		std::unordered_map<std::string, std::unordered_map<std::string, unsigned int>> map;
	};
}


#endif // !CLIENT_HPP
