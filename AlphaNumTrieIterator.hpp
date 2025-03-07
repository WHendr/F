#ifndef ALPHA_NUM_TRIE_ITERATOR_HPP
#define ALPHA_NUM_TRIE_ITERATOR_HPP

#include "AlphaNumTrie.hpp"

namespace Dry
{

class AlphaNumTrieIterator
{
	using ValueType = AlphaNumTrie::TrieNode;
    using iterator_category = std::forward_iterator_tag;
    using value_type = ValueType;
    using difference_type = std::ptrdiff_t;
    using pointer = ValueType*;
    using reference = ValueType&;

public:

	AlphaNumTrieIterator(AlphaNumTrie);

    std::vector<ValueType*>::iterator begin() { return _data.begin(); }
    std::vector<ValueType*>::iterator end() { return _data.end(); }

private:
    reference operator*() const { return *current; }
    pointer operator->() { return current; }

    // Prefix increment
    AlphaNumTrieIterator& operator++() {
        ++current;
        return *this;
    }

    bool operator!=(const AlphaNumTrieIterator& other) const { return current != other.current; }
    bool operator==(const AlphaNumTrieIterator& other) const { return current == other.current; }


    std::vector<ValueType*> _data;
private:
    pointer current;
};

}
#endif // !ALPHA_NUM_TRIE_ITERATOR_HPP
