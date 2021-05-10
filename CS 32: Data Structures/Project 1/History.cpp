//
//  History.cpp
//  Project 1
//
//  Created by Nick Chung on 1/6/21.
//

#include "History.h"
//#include "globals.h"
#include <iostream>

using namespace std;

History::History(int nRows, int nCols)
 : m_rows(nRows), m_cols(nCols) {
    for (int r = 0; r < m_rows; r++) {
        for (int c = 0; c < m_cols; c++) {
            m_grid[r][c] = '.';
        }
    }
}

bool History::record(int r, int c) {
    if (r > m_rows || c > m_cols || r < 1 || c < 1) {
        return false;
    }
    if (m_grid[r - 1][c - 1] == '.')
        m_grid[r - 1][c - 1] = 'A';
    else if (m_grid[r - 1][c - 1] == 'Z')
        return true;
    else
        m_grid[r - 1][c - 1]++;
    return true;
}

void History::display() const {
    clearScreen();
    for (int r = 0; r < m_rows; r++) {
        for (int c = 0; c < m_cols; c++) {
            cout << m_grid[r][c];
        }
        cout << endl;
    }
    cout << endl;
}
