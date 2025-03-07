#ifndef TRIE_HPP
#define TRIE_HPP

namespace Dry
{

class Trie
{
	class TrieNode
	{
		TrieNode();
		TrieNode* children[26];
		int count;
	};
public:
	Trie();
	~Trie();

private:
	TrieNode* po_Head;
};

}

#endif // !TRIE_HPP
