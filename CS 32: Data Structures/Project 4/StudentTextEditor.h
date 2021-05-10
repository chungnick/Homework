// Nick Chung
// 104926143
// v2

#ifndef STUDENTTEXTEDITOR_H_
#define STUDENTTEXTEDITOR_H_

#include "TextEditor.h"

#include <iostream>
#include <fstream>
#include <list>

class Undo;

class StudentTextEditor : public TextEditor {
public:
	StudentTextEditor(Undo* undo);
	~StudentTextEditor();
	bool load(std::string file);
	bool save(std::string file);
	void reset();
	void move(Dir dir);
	void del();
	void backspace();
	void insert(char ch);
	void enter();
	void getPos(int& row, int& col) const;
	int getLines(int startRow, int numRows, std::vector<std::string>& lines) const;
	void undo();
private:
	std::list<std::string> m_list;
	std::list<std::string>::iterator curr;
	std::list<std::string>::iterator start;
	int m_row = 0, m_col = 0;
};

#endif // STUDENTTEXTEDITOR_H_