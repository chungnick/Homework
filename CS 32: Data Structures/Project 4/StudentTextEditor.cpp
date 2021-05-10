// Nick Chung
// 104926143
// v2

#include "StudentTextEditor.h"
#include "Undo.h"
#include <string>
#include <vector>

TextEditor* createTextEditor(Undo* un)
{
	return new StudentTextEditor(un);
}

StudentTextEditor::StudentTextEditor(Undo* undo)
	: TextEditor(undo), m_row(0), m_col(0) {
	m_list.push_back("");
	curr = m_list.begin();
	start = m_list.begin();
	// o(1)
}

StudentTextEditor::~StudentTextEditor() {
	std::list<std::string>::iterator it = m_list.begin();
	// o(N): while loop only runs for the length of m_list
	while (it != m_list.end()) {
		std::string temp = *it;
		it = m_list.erase(it);
		delete& temp;
	}
}

bool StudentTextEditor::load(std::string file) {
	m_col = 0;
	m_row = 0;
	std::ifstream infile(file);
	if (!infile)
		return false;
	// o(N + U)
	reset();
	std::string str;
	// o(N)
	while (getline(infile, str)) {
		m_list.push_back(str);
	}
	return true;
}

bool StudentTextEditor::save(std::string file) {
	std::ofstream outfile(file);
	if (!outfile)
		return false;
	std::list<std::string>::iterator it = m_list.begin();
	// o(M): number of characters being edited 
	while (it != m_list.end()) {
		outfile << *it << '\n';
		it++;
	}
	return true;
}

void StudentTextEditor::reset() {
	m_col = 0;
	m_row = 0;
	curr = start;
	std::list<std::string>::iterator it = m_list.begin();
	// o(N): number of rows being edited
	while (it != m_list.end()) {
		std::string temp = *it;
		it = m_list.erase(it);
		delete& temp;
	}
	// o(U): number of items in undo stack
	getUndo()->clear();
}

void StudentTextEditor::insert(char ch) {
	if (ch == '\t') {
		for (int i = 0; i < 4; i++) {
			(*curr).insert(m_col, 1, ' ');
		}
		m_col += 4;
	} else {
		(*curr).insert(m_col, 1, ch);
		m_col++;
	}
	// o(L)
	getUndo()->submit(Undo::Action::DELETE, m_row, m_col, ch);
}

void StudentTextEditor::enter() {
	if (m_row == m_list.size() - 1 && m_col == curr->size()) {
		getUndo()->submit(Undo::Action::JOIN, m_row, m_col);
		m_list.push_back("");
		m_row++;
		m_col = 0;
		curr++;
	} else {
		getUndo()->submit(Undo::Action::JOIN, m_row, m_col);
		std::string newstring = curr->substr(m_col, curr->size());
		curr->erase(m_col, curr->size());
		m_row++;
		m_col = 0;
		curr++;
		// o(L)
		m_list.insert(curr, newstring);
		curr--;
	}
}

void StudentTextEditor::del() {
	char ch;
	if (m_col >= 0 && m_col < curr->size()) {
		ch = (*curr).at(m_col);
		curr->erase(curr->begin() + m_col);
		getUndo()->submit(Undo::Action::INSERT, m_row, m_col, ch);
	} else if (m_col == curr->size()) {
		if (m_row + 1 < m_list.size()) {
			curr++;
			std::string ins = *curr;
			curr--;
			// o(L)
			(*curr).insert(m_col, ins);
			std::list<std::string>::iterator it = curr;
			it++;
			it = m_list.erase(it);
			ch = '\n';
			getUndo()->submit(Undo::Action::SPLIT, m_row, m_col);
		}
	}
}

void StudentTextEditor::backspace() {
	char ch;
	if (m_col > 0) {
		ch = (*curr).at(m_col - 1);
		// o(L)
		curr->erase((*curr).begin() + m_col - 1);
		m_col--;
		getUndo()->submit(Undo::Action::INSERT, m_row, m_col, ch);
	} else if (m_col == 0) {
		if (m_row > 0) {
			m_row--;
			std::string ins = *curr; 
			curr--;
			m_col = curr->size();
			// o(L1)
			(*curr).insert((*curr).size(), ins);
			std::list<std::string>::iterator it = curr;
			it++;
			// o(L2)
			it = m_list.erase(it);
			getUndo()->submit(Undo::Action::SPLIT, m_row, m_col);
		}
	}
}

void StudentTextEditor::move(Dir dir) {
	// o(1) for entire switch statement
	switch (dir) {
	case TextEditor::UP:
		if (m_row > 0) {
			m_row--;
			curr--;
			if (m_col > (*curr).size())
				m_col = (*curr).size();
		}
		break;
	case TextEditor::DOWN:
		if (m_row < m_list.size() - 1) {
			m_row++;
			curr++;
			if (m_col > (*curr).size())
				m_col = (*curr).size();
		}
		break;
	case TextEditor::LEFT:
		if (m_col > 0)
			m_col--;
		break;
	case TextEditor::RIGHT:
		if (m_col < curr->size())
			m_col++;
		break;
	case TextEditor::HOME:
		m_col = 0;
		break;
	case TextEditor::END:
		m_col = curr->size();
		break;
	default:
		break;
	}
}

void StudentTextEditor::getPos(int& row, int& col) const {
	// o(1)
	row = m_row;
	col = m_col;
}

int StudentTextEditor::getLines(int startRow, int numRows, std::vector<std::string>& lines) const {
	if (startRow < 0 || numRows < 0 || startRow > m_list.size() - 1)
		return -1;
	std::vector<std::string>::iterator it = lines.begin();
	// o(oldR)
	while (it != lines.end()) {
		std::string temp = *it;
		it = lines.erase(it);
		delete& temp;
	}
	std::list<std::string>::iterator it2 = start;
	// if current row number = 0, o(abs(currRow - start Row)
	for (int i = 0; i < startRow; i++) {
		it2++; 
	}
	// o(numRows * L)
	for (int i = startRow; i < numRows; i++) {
		if (i >= m_list.size())
			break;
		lines.push_back(*it2);
		it2++;
	}
	int numlines = lines.size();
	return numlines;
}

void StudentTextEditor::undo() {
	int col = 0, row = 0, x = 0;
	std::string str = "", str2 = "";
	switch (getUndo()->get(row, col, x, str)) {
	case Undo::Action::ERROR:
		return;
		break;
	case Undo::Action::INSERT: 
		m_row = row;
		curr = start;
		for (int i = 0; i < m_row; i++) {
			curr++;
		}
		(*curr).insert(m_col, str);
		m_col += str.size();
		break;
	case Undo::Action::DELETE:
		m_row = row;
		m_col = col;
		curr = start;
		for (int i = 0; i < m_row; i++) {
			curr++;
		}
		curr->erase(m_col - 1, x);
		m_col--;
		break;
	case Undo::Action::SPLIT:
		m_row = row; 
		m_col = col;
		curr = start;
		for (int i = 0; i < m_row; i++) {
			curr++;
		}
		str2 = *curr;
		str2 = str2.substr(m_col, str2.size());
		curr->erase(m_col, curr->size());
		m_row++;
		m_col = 0;
		curr++;
		m_list.insert(curr, str2);
		curr--;
		break;
	case Undo::Action::JOIN:
		m_row = row + 1;
		m_col = 0;
		curr = start;
		for (int i = 0; i < m_row; i++) {
			curr++;
		}
		str2 = *curr;
		curr--;
		m_row--;
		m_col = curr->size();
		(*curr).insert((*curr).size(), str2);
		std::list<std::string>::iterator it = curr;
		it++;
		it = m_list.erase(it);
		break;
	}

}