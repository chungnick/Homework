//
//  main.cpp
//  Homework 1
//
//  Created by Nick Chung on 1/17/21.
//bababooey

#include "Sequence.h"
#include <iostream>

using namespace std;

int main() {
    Sequence s;
    s.insert(3);
    s.insert(4);
    s.insert(2);
    s.insert(2, 99);
    s.insert(50);
    
    cout << "size is " << s.size() << endl;
}


//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//int main()
//{
//    Sequence s;
//    assert(s.empty());
//    assert(s.find(42) == -1);
//    assert(s.insert(42) == 0);
//    assert(s.size() == 1  &&  s.find(42) == 0);
//    cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//int main()
//{
//   Sequence s;
//   assert(s.empty());
//   assert(s.find("laobing") == -1);
//   assert(s.insert("laobing") == 0);
//   assert(s.size() == 1  &&  s.find("laobing") == 0);
//   cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    s.insert(0, "lavash");
//    s.insert(0, "tortilla");
//    assert(s.size() == 2);
//    ItemType x = "injera";
//    assert(s.get(0, x) && x == "tortilla");
//    assert(s.get(1, x) && x == "lavash");
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}

//#include "Sequence.h"
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//void test()
//{
//    Sequence s;
//    s.insert(0, 10);
//    s.insert(0, 20);
//    assert(s.size() == 2);
//    ItemType x = 999;
//    assert(s.get(0, x) && x == 20);
//    assert(s.get(1, x) && x == 10);
//}
//
//int main()
//{
//    test();
//    cout << "Passed all tests" << endl;
//}
