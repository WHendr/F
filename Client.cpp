#include "Client.hpp"

#include <filesystem>
#include <fstream>
#include <iterator>

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

#include "AlphaNumTrieIterator.hpp"
#include "File.hpp"

namespace fs = std::filesystem;

namespace Dry
{
	Client::Client(Server& r_Server)
		: server(r_Server)
	{
	}

	void Client::quit()
	{
	}

	void Client::index(std::string dataset_path)
	{
		fs::path filePath = dataset_path;
		if (fs::exists(filePath))
		{
			for (const auto& entry : fs::directory_iterator(filePath))
			{
				std::string file = entry.path().string();
				std::vector<char> buffer = readFileToBuffer(file);

				std::string word;
				for (const auto& letter : buffer)
				{
					if (isalnum(letter))
					{
						word += tolower(letter);
					}
					else
					{
						auto& item = map[word][file];
						++item;
						word.clear();
					}
				}
			}

			std::vector<BatchData> batch = this->batchData();
			this->server.receiveData(batch);
		}
		else
		{
			printf_s("Error : File_Path does not exist");
		}
	}
	
	void Client::search(std::string query)
	{
		// TODO change this functionality to use gRPC
	}

	std::vector<BatchData> Client::batchData()
	{
		std::vector<BatchData> vec;
		for (const auto& word : map)
		{
			BatchData data;
			for (const auto& file : word.second)
			{
				data.word = word.first;
				data.file = file.first;
				data.count = file.second;
				vec.push_back(data);
			}
		}

		return vec;
	}

}