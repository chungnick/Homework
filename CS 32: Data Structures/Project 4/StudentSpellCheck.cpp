// Nick Chung
// 104926143
// v2

#include "StudentSpellCheck.h"
#include <string>
#include <vector>
#include <fstream>

SpellCheck* createSpellCheck()
{
	return new StudentSpellCheck;
}

StudentSpellCheck::~StudentSpellCheck() {
	delete root;
}

bool StudentSpellCheck::load(std::string dictionaryFile) {
	// load file
	std::ifstream infile(dictionaryFile);	
	if (infile) {
		std::string s;
		root = new trieNode;
		while (getline(infile, s)) {
			// insert line into trie
			insert(root, s);				
		}
		return true;
	}
	return false;
}

bool StudentSpellCheck::spellCheck(std::string word, int max_suggestions, std::vector<std::string>& suggestions) {
	if (dictionaryCheck(word)) 
		return true;
	std::unordered_map<char, trieNode*>::iterator it;
	trieNode* curr_node = root;
	for (int i = 0; i < word.length(); i++) {
		for (it = curr_node->m_map.begin(); it != curr_node->m_map.end(); ++it) {
			if (max_suggestions == 0)
				// return if max_suggestions reached
				return false;
			if (it->first != word[i]) {
				std::string curr_word = word;
				curr_word[i] = it->first;
				// check for valid word suggestion
				if (dictionaryCheck(curr_word)) {
					suggestions.push_back(curr_word);
					max_suggestions--;
				}
			}
		}
	}
	return false;
}

void StudentSpellCheck::spellCheckLine(const std::string& line, std::vector<SpellCheck::Position>& problems) {
	bool first = false; 
	for (int i = 0; i < line.size(); i++) {
		int ch = tolower(line.at(i));
		if ((ch >= 97 && ch <= 122) || ch == 39) {
			// for first word
			if (!first) {
				Position pos;
				first = true;
				pos.start = i;
				while (first && i < line.size() - 1) {
					i++;
					int ch2 = tolower(line.at(i));
					if (!((ch2 >= 97 && ch2 <= 122) || ch2 == 39))
						first = false;
				}
				if (!first)
					pos.end = i - 1;
				// last character
				else
					pos.end = i;
				problems.push_back(pos);
			}
		} else
			first = false;
	}
	std::vector<Position>::iterator it = problems.begin();
	while (it != problems.end()) {
		bool valid = false;
		std::string str;
		str = line.substr((*it).start, (*it).end - (*it).start + 1);
		if (dictionaryCheck(str))
			it = problems.erase(it);
		else
			it++;
	}
}
