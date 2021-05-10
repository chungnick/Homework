//
//  main.cpp
//  Homework 3 Problem 6
//
//  Created by Nick Chung on 2/3/21.
//  *

#include <iostream>

using namespace std;

long double fun(long double x, long double y) {
    return 9 - (6 * x) + pow(x, 2) + (100 * pow(y, 2)) + (200 * pow(x, 2) * y) + (100 * pow(x, 4));
}

long double dx(long double x, long double y) {
    return (400 * pow(x, 3)) + (400 * x * y) + (2 * x) - 6;
}

long double dy(long double x, long double y) {
    return (200 * pow(x, 2)) + (200 * y);
}

int gradDescent(double startingX, double startingY, double stepSize) {
    long double x1 = startingX, y1 = startingY, x2 = 0, y2 = 0, i = 1;
    
    x2 = x1 - stepSize * dx(x1, y1);
    y2 = y1 - stepSize * dy(x1, y1);
    
    for (;;) {
        if (fun(x1, y1) - fun(x2, y2) <= pow(10, -8))
            break;
        
        long double tempx = 0, tempy = 0;
        
        tempx = x2 - stepSize * dx(x2, y2);
        tempy = y2 - stepSize * dy(x2, y2);
        
        x1 = x2;
        y1 = y2;

        x2 = tempx;
        y2 = tempy;
        i++;
    }
    cout << "step size of: " << stepSize << ": " << endl;
    cout << "(x, y) = " << "(" << x2 << ", " << y2 << ")" << endl;
    cout << "f(x,y) = " << fun(x2, y2) << endl;
    return i;
}

int main() {
    cout << gradDescent(2, 2, pow(10, -3)) << " iteration(s)" << endl << "--------------------" << endl;
    cout << gradDescent(2, 2, pow(10, -4)) << " iteration(s)" << endl << "--------------------" << endl;
    cout << gradDescent(2, 2, pow(10, -5)) << " iteration(s)" << endl << "--------------------" << endl;
    return 0;
}
