//
//  main.cpp
//  Project 2
//
//  Created by Nick Chung on 1/23/21.
//  v3

#include "Sequence.h"
#include <cassert>

int main() {
    Sequence alpha;
    // check that empty sequence behaves as expected
    assert(alpha.size() == 0);
    assert(alpha.empty() == true);
    // check that insert functions behave as expected
    assert(alpha.insert("") == 0);
    assert(alpha.insert(0, "a") == 0);
    assert(alpha.insert(0, "b") == 0);
    assert(alpha.insert(2, "c") == 2);
    // check that other member functions behave as expected
    // checking remove function implies that erase also works as expected
    assert(alpha.remove("e") == 0);
    assert(alpha.remove("b") == 1);
    assert(alpha.set(2, "d") == true);
    std::string x;
    assert(alpha.get(2, x) == true);
    assert(alpha.find("d") == 2);
    // check that swap functions behave as expected
    // also implies that copy constructor and assignment operator are functional
    Sequence beta;
    beta.insert(0, "a");
    beta.insert(1, "b");
    beta.insert(2, "c");
    beta.insert(3, "d");

    Sequence gamma;
    gamma.insert(0, "1");
    gamma.insert(1, "2");
    gamma.insert(2, "3");
    gamma.insert(3, "4");
    gamma.insert(4, "5");

    beta.swap(gamma);
    // check that non-member functions behave as expected
    Sequence delta;
    delta.insert("2");
    delta.insert("3");
    delta.insert("4");

    Sequence epsilon;
    epsilon.insert("a");
    epsilon.insert("2");
    epsilon.insert("3");
    epsilon.insert("4");
    
    Sequence omega;
    assert(subsequence(epsilon, omega) == -1);
    assert(subsequence(omega, epsilon) == -1);

    assert(subsequence(delta, epsilon) == -1);
    assert(subsequence(epsilon, delta) == 0);

    Sequence phi;
    phi.insert("a");
    phi.insert("b");
    phi.insert("c");
    phi.insert("d");
    phi.insert("e");
    
    Sequence psi;
    psi.insert("1");
    psi.insert("2");
    psi.insert("3");
    
    interleave(psi, phi, omega);

    std::cerr << "all tests passed!" << std::endl;
    return 0;
}

