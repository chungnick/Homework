//
//  maze.cpp
//  Homework 3
//
//  Created by Nick Chung on 2/7/21.
//  ***

#include <iostream>
#include <stack>

using namespace std;

class Coord {
public:
    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
    int r() const { return m_row; }
    int c() const { return m_col; }
private:
    int m_row;
    int m_col;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
    if (sr == er && sc == ec)
        return true;
    maze[sr][sc] = 'o';
    if (maze[sr - 1][sc] == '.' && pathExists(maze, nRows, nCols, sr - 1, sc, er, ec))
        return true;
    if (maze[sr][sc + 1] == '.' && pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
        return true;
    if (maze[sr + 1][sc] == '.' && pathExists(maze, nRows, nCols, sr + 1, sc, er, ec))
        return true;
    if (maze[sr][sc - 1] == '.' && pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
        return true;
    return false;
}

//int main() {
//    string maze[10] = {
//    //   0123456789
//        "XXXXXXXXXX",   //0
//        "X........X",   //1
//        "XX.X.XXXXX",   //2
//        "X..X.X...X",   //3
//        "X..X...X.X",   //4
//        "XXXX.XXX.X",   //5
//        "X.X....XXX",   //6
//        "X..XX.XX.X",   //7
//        "X...X....X",   //8
//        "XXXXXXXXXX"    //9
//    };
//
//    cout << (pathExists(maze, 10,10, 6,4, 1,1) ? "Solvable" : "Out of Luck!") << endl;;
//
//    cout << "----------" << endl;
//    for (int j = 0; j < 10; j++)
//        cout << maze[j] << endl;
//    cout << "----------" << endl;
//
//    return 0;
//}
