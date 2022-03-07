#pragma once
#include <string>
using namespace std;

class TrieNode
{
public:
	// Initialize your data structure here.
	int count = 0;

	string word = "";

	TrieNode* children[26] = { nullptr };

	TrieNode();

	~TrieNode();

private:

};

