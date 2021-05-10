// Nick Chung
// 104926143
// v2

#ifndef STUDENTSPELLCHECK_H_
#define STUDENTSPELLCHECK_H_

#include "SpellCheck.h"

#include <string>
#include <vector>
#include <unordered_map>

class StudentSpellCheck : public SpellCheck {
public:
    StudentSpellCheck() { }
	virtual ~StudentSpellCheck();
	bool load(std::string dict_file);
	bool spellCheck(std::string word, int maxSuggestions, std::vector<std::string>& suggestions);
	void spellCheckLine(const std::string& line, std::vector<Position>& problems);
private:
	struct trieNode {
		std::unordered_map<char, trieNode*> m_map;
		char ch;
		bool endofWord = false;
	};

	trieNode* root = nullptr;

	void insert(trieNode*& root, std::string s) {
		trieNode* curr = root;
		int i = 0;
		while (i < s.size()) {
			// if no path exists in trie
			if (curr->m_map.find(s[i]) == curr->m_map.end())
				curr->m_map[tolower(s[i])] = new trieNode();
			curr = curr->m_map[s[i++]];
		}
		curr->endofWord = true;
	}

	bool dictionaryCheck(std::string word) {
		trieNode* p = root;
		std::unordered_map<char, trieNode*>::iterator it;
		for (char c : word) {
			it = p->m_map.find(c);
			if (it == p->m_map.end())
				return false;
			p = it->second;
		}
		if (!p->endofWord) 
			return false;
		return true;
	}
};

#endif  // STUDENTSPELLCHECK_H_