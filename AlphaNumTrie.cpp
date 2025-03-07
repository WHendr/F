#include "AlphaNumTrie.hpp"

namespace Dry
{
	AlphaNumTrie::TrieNode::TrieNode()
		: children{},
		word{},
		map{}
	{

	}

	AlphaNumTrie::TrieNode::~TrieNode()
	{
		for (size_t i = 0; i < numNodes; i++)
		{
			delete this->children[i];
		}
	}

	AlphaNumTrie::AlphaNumTrie()
		:po_Head{ new TrieNode{} }
	{
	}
	
	AlphaNumTrie::~AlphaNumTrie()
	{
		delete this->po_Head;
	}

	void AlphaNumTrie::Insert(std::string& word, std::string fileName)
	{
		TrieNode* p_Curr = po_Head;
		for (const auto& letter : word)
		{
			if (!isalnum(letter))
			{
				break;
			}

			
			int ascii = tolower(letter);
			if (ascii < 123 && ascii > 96)
			{
				ascii = ascii - 'a' + 9;
			}
			else
			{
				ascii -= '0';
			}

			
			TrieNode* child = p_Curr->children[ascii];
			if (child)
			{
				p_Curr = child;
			}
			else
			{
				child = new TrieNode();
				p_Curr = child;
			}
		}

		if (p_Curr && p_Curr != this->po_Head)
		{
			p_Curr->word = word;
			++p_Curr->map[fileName];
		}
	}

}