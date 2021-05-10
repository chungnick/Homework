//
//  main.cpp
//  HW7 Q1
//
//  Created by Nick Chung on 3/21/21.
//

#include <iostream>
#include "functions.h"
#include <vector>
#include <cmath>

struct e_pair {
    int pos;
    double e1;
    double e2;
};

double epsilon( int h, double e) {
    return h * e + (1 - h) * (1 - e);
}

    
   

double emission(int g, double e1, double e2) {
    if (g == 0)
        return epsilon(0 , e1) * epsilon(0, e2);
    else if (g == 1)
        return epsilon(0, e1) * epsilon(1, e2) + epsilon(0, e2) * epsilon(1, e1);
    else if (g == 2)
        return epsilon(1, e1) * epsilon(1, e2);
    else {
        std::cout << "g value out of bounds" << std::endl;
        return -1;
    }
}

int main() {
    double a = emission(1, 0.3, 0.2) / (4 * pow(2, 2));
    double b = emission(1, 0.7, 0.8) / (4 * pow(2, 2));
    
    std::cout << "s = 1, emit 1: " << a << std::endl;
    std::cout << "s = 1, emit 0: " << b << std::endl;
    return 0;
}
