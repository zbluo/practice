#include "TrieNode.h"

TrieNode::TrieNode() {

}

TrieNode::~TrieNode() {
	for (int i = 0; i < 26; i++)
		if (children[i] != nullptr)
			delete children[i];
	//		delete[] children;
}