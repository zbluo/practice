#pragma once
#include "TrieNode.h"
// #include <string>
// #include "Solution.h"

class Trie
{
public:
	Trie() {
		root = new TrieNode();
	}

	// Find the longest substr of 2 strings
	string findLongestSubstr(string str1, string str2) {
		string ans = "";
		if (str1.empty() || str2.empty())
			return ans;
		int n = (int)str1.size(), m = (int)str2.size();
		for (int i = 0; i < n; i++)
			longestSubStr(str1.substr(i, n - i), true, ans);
		for (int i = 0; i < m; i++)
			longestSubStr(str2.substr(i, n - i), false, ans);

		return ans;
	}

	// Inserts a word into the trie.
	void insert(string word) {
		getNode(word, true);
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode* tmpPtr = getNode(word, false);
		return (tmpPtr != nullptr) && (tmpPtr->count > 0);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		return getNode(prefix, false) != nullptr;
	}

	~Trie() {
		delete root;
	}

private:
	TrieNode* root;
	void longestSubStr(string word, bool creat, string &ans) {
		TrieNode *cur = root;

		for (int i = 0; i < (int)word.size(); i++) {
			int id = word[i] - 'a';
			if (cur->children[id] == nullptr) {
				if (creat) {
					cur->children[id] = new TrieNode();
					cur->children[id]->word = word.substr(0, i + 1);
				}
				else {
					if (cur->word.size() > ans.size())
						ans = cur->word;
					return;
				}
			}
			cur = cur->children[id];
		}
		if (!creat)
			if (cur->word.size() > ans.size())
				ans = cur->word;
	}

	TrieNode* getNode(string word, bool creat) {
		TrieNode* cur = root;

		for (int i = 0; i < (int)word.size(); i++) {
			int id = word[i] - 'a';
			if (cur->children[id] == nullptr) {
				if (creat)
					cur->children[id] = new TrieNode();
				else
					return nullptr;
			}
			cur = cur->children[id];
		}

		if (creat)
			cur->count++;

		return cur;
	}

};

