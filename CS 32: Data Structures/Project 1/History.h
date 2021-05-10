//
//  History.h
//  Project 1
//
//  Created by Nick Chung on 1/6/21.
//

#ifndef History_h
#define History_h

#include <stdio.h>
#include "globals.h"

class History {
public:
    History(int nRows, int nCols);
    bool record(int r, int c);
    void display() const;
    
private:
    int m_rows, m_cols;
    char m_grid[MAXROWS][MAXCOLS];
};

#endif /* History_h */
