#include "AlphaNumTrieIterator.hpp"
#include <queue>

namespace Dry
{

AlphaNumTrieIterator::AlphaNumTrieIterator(AlphaNumTrie in_Trie)
	: _data{},
	current{}
{
	ValueType* p_Curr = in_Trie.po_Head;

	// Need an queue of some form for traversal
	std::queue<ValueType*> queue;
	queue.push(p_Curr);
	while (p_Curr)
	{
		p_Curr = queue.front();
		queue.pop();

		for (unsigned int i = 0; i < numNodes; ++i)
		{
			ValueType* temp = p_Curr->children[i];
			if (temp)
			{
				queue.push(temp);
				_data.push_back(temp);
			}
		}
	}
}

}