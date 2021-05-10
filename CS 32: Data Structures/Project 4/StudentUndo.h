// Nick Chung
// 104926143
// v2

#ifndef STUDENTUNDO_H_
#define STUDENTUNDO_H_

#include "Undo.h"
#include <stack>

class StudentUndo : public Undo {
public:
	void submit(Action action, int row, int col, char ch = 0);
	Action get(int& row, int& col, int& count, std::string& text);
	void clear();
private:
	struct undoStruct {
		int m_row;
		int m_col;
		int m_count;
		Action m_action;
		std::string m_str;
	};
	std::stack<undoStruct> m_stack;
};

#endif // STUDENTUNDO_H_
