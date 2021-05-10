//
//  testScoreList.cpp
//  Homework 1
//
//  Created by Nick Chung on 1/19/21.
//bababooey

#include <iostream>
#include "ScoreList.h"
#include "Sequence.h"

using namespace std;

void testScoreList () {
    ScoreList s;
//    s.add(-1);
//    s.add(134);
    s.add(70);
    s.add(12);
    s.add(100);
    s.add(1);
    s.add(14);
    s.add(5);
    s.add(10);

    cout << "size is: " << s.size() << endl;
    cout << "max is: " << s.maximum() << endl;
    cout << "min is: " << s.minimum() << endl;
}

int main () {
    testScoreList();
    return 0;
}
