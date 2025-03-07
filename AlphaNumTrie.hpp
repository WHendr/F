#ifndef ALPHA_NUM_TRIE_HPP
#define ALPHA_NUM_TRIE_HPP

#include <string>
#include <vector>
#include <unordered_map>
namespace Dry
{
	const unsigned int numNodes = 36;

	class AlphaNumTrie
	{
		friend class AlphaNumTrieIterator;
		class TrieNode
		{
		public:
			TrieNode();
			~TrieNode();
			TrieNode* children[numNodes];
			std::string word;
			std::unordered_map<std::string, unsigned int> map;
		};
	public:
		AlphaNumTrie();
		~AlphaNumTrie();

		void Insert(std::string& word, std::string fileName);

	private:
		TrieNode* po_Head;
	};

}

#endif // !ALPHA_NUM_TRIE_HPP
