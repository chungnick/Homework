////
////  mazequeue.cpp
////  Homework 2
////
////  Created by Nick Chung on 2/2/21.
////  *
//
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//class Coord {
//public:
//    Coord(int rr, int cc) : m_row(rr), m_col(cc) {}
//    int r() const { return m_row; }
//    int c() const { return m_col; }
//private:
//    int m_row;
//    int m_col;
//};
//
//bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
//    maze[sr][sc] = '@';
//    queue<Coord> coordQ;
//    Coord start(sr, sc);
//    coordQ.push(start);
//    while (!coordQ.empty()) {
//        Coord current = coordQ.front();
//        coordQ.pop();
//        
//        cout << "(" <<current.r() << ", " << current.c() << ")" << endl;
//        
//        if (current.r() == er && current.c() == ec)
//            return true;
//        else {
//            if (maze[current.r() - 1][current.c()] == '.') {
//                maze[current.r() - 1][current.c()] = 'o';
//                Coord next(current.r() - 1, current.c());
//                coordQ.push(next);
//            } if (maze[current.r()][current.c() + 1] == '.') {
//                maze[current.r()][current.c() + 1] = 'o';
//                Coord next(current.r(), current.c() + 1);
//                coordQ.push(next);
//            } if (maze[current.r() + 1][current.c()] == '.') {
//                maze[current.r() + 1][current.c()] = 'o';
//                Coord next(current.r() + 1, current.c());
//                coordQ.push(next);
//            } if (maze[current.r()][current.c() - 1] == '.') {
//                maze[current.r()][current.c() - 1] = 'o';
//                Coord next(current.r(), current.c() - 1);
//                coordQ.push(next);
//            }
//        }
//    }
//    return false;
//}
//
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
