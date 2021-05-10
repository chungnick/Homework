// Nick Chung
// 104926143
// v2

#include "StudentUndo.h"

Undo* createUndo()
{
	return new StudentUndo;
}

void StudentUndo::submit(const Action action, int row, int col, char ch) {
	if (m_stack.size() > 0 && action == m_stack.top().m_action) {
		if (action == Action::INSERT && m_stack.top().m_col == col && m_stack.top().m_row == row) {
			m_stack.top().m_str.push_back(ch);
			m_stack.top().m_count++;
			return;
		} else if (action == Action::INSERT && (m_stack.top().m_col - 1) == col && m_stack.top().m_row == row) {
			m_stack.top().m_str.insert(0, 1, ch); 
			m_stack.top().m_count++;
			m_stack.top().m_col--;
			return;
		} else if ((int(ch) >= 65 && int(ch) <= 90) || (int(ch) >= 97 && int(ch) <= 122) || (ch) == 39) {
			char ch2 = m_stack.top().m_str.at(0);
			if ((int(ch2) >= 65 && int(ch2) <= 90) || (int(ch2) >= 97 && int(ch2) <= 122) || (ch2) == 39) {
				if (action == Action::DELETE && m_stack.top().m_col + m_stack.top().m_count == col && m_stack.top().m_row == row) {
					m_stack.top().m_count++;
					return;
				}
			}
		}
	}
	std::string str = "";
	str.append(1, ch);
	struct undoStruct undo = {row, col, 1, action, str};
	m_stack.push(undo);
}

StudentUndo::Action StudentUndo::get(int& row, int& col, int& count, std::string& text) {
	if (m_stack.size() == 0) 
		return Action::ERROR;
	Action act = m_stack.top().m_action;
	row = m_stack.top().m_row;
	col = m_stack.top().m_col;
	switch (act) {
	case Action::INSERT:
		count = 1;
		text = m_stack.top().m_str;
		break;
	case Action::DELETE:
		count = m_stack.top().m_count;
		text = "";
		break;
	case Action::JOIN:
	case Action::SPLIT:
		count = 1;
		text = "";
		break;
	}
	m_stack.pop();
	return (act);
}

void StudentUndo::clear() {
	while (!m_stack.empty()) {
		m_stack.pop();
	}
}