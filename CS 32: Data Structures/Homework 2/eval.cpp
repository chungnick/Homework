//
//  eval.cpp
//  Homework 2
//
//  Created by Nick Chung on 2/2/21.
//  *

#include <iostream>
#include <string>
#include <stack>
#include <cassert>

using namespace std;

int evaluate(string infix, const bool values[], string& postfix, bool& result) {
    stack<char> charStack;
    stack<bool> operandStack;
    postfix = "";
    string temp;
    for (int i = 0; i < infix.size(); i++) {            // ignore spaces from infix
        char ch = infix[i];
        if (ch != ' ')
            temp += ch;
    }
    infix = temp;
    int j = 0;
    for (int i = 0; i < infix.size(); i++) {
        char ch = infix[i];
        switch (ch) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                postfix += ch;
                break;
            case '!':
                if (i == infix.size() - 1)
                    return 1;
                while (charStack.empty() == false && charStack.top() != '(' && charStack.top() != '|' && charStack.top() != '&') {
                    postfix += charStack.top();
                    charStack.pop();
                }
                charStack.push(ch);
                break;
            case '&':
                if (i == 0 || i == infix.size() - 1)
                    return 1;
                while (charStack.empty() == false && charStack.top() != '(' && charStack.top() != '|') {
                    postfix += charStack.top();
                    charStack.pop();
                }
                charStack.push(ch);
                break;
            case '|':
                if (i == 0 || i == infix.size() - 1)
                    return 1;
                while (charStack.empty() == false && charStack.top() != '(') {
                    postfix += charStack.top();
                    charStack.pop();
                }
                charStack.push(ch);
                break;
            case '(':
                if (i == infix.size() - 1 || infix[i + 1] == '&' || infix[i + 1] == '|')
                    return 1;
                charStack.push(ch);
                break;
            case ')':
                if (i == 0 || infix[i - 1] == '&' || infix[i - 1] == '|')
                    return 1;
                while (charStack.top() != '(') {
                    postfix += charStack.top();
                    charStack.pop();
                    j++;
                }
                if (j == 0 && infix[i - 1] == '(')
                    return 1;
                charStack.pop();
                break;
            default:                            // reject infix string containing any other letter
                return 1;
        }
    }
    while (charStack.empty() == false) {        // create postfix string
        postfix += charStack.top();
        charStack.pop();
    }
    for (int i = 0; i < postfix.size(); i++) {
        char ch = postfix.at(i);
        if (ch >= '0' && ch <= '9') {
            int x = ch - '0';
            operandStack.push(values[x]);
        }
        else if (ch == '!') {
            bool temp = false;
            bool op1 = operandStack.top();
            operandStack.pop();
            temp = !op1;                        // apply unary operator
            operandStack.push(temp);
        }
        else if (ch == '&' || ch == '|') {
            bool temp = false;
            bool op1 = operandStack.top();
            operandStack.pop();
            bool op2 = operandStack.top();
            operandStack.pop();
            if (ch == '&')                      // apply & operator
                temp = op2 & op1;
            else if (ch == '|')
                temp = op2 | op1;               // apply | operator
            operandStack.push(temp);
        }
        else if (ch == '(')                     // for any mismatched (
            return 1;
    }
    if (operandStack.size() != 1)
        return 1;
    result = operandStack.top();
    return 0;
}

//int main() {
//    bool ba[10] = {
//      //  0      1      2      3      4      5      6      7      8      9
//        true,  true,  true,  false, false, false, true,  false, true,  false
//    };
//    string pf;
//    bool answer;
//    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  answer);
//    assert(evaluate("8|", ba, pf, answer) == 1);
//    assert(evaluate(" &6", ba, pf, answer) == 1);
//    assert(evaluate("4 5", ba, pf, answer) == 1);
//    assert(evaluate("01", ba, pf, answer) == 1);
//    assert(evaluate("()", ba, pf, answer) == 1);
//    assert(evaluate("()4", ba, pf, answer) == 1);
//    assert(evaluate("2(9|8)", ba, pf, answer) == 1);
//    assert(evaluate("2(&8)", ba, pf, answer) == 1);
//    assert(evaluate("(6&(7|7)", ba, pf, answer) == 1);
////    evaluate("(6&(7|7)", ba, pf, answer);
//    assert(evaluate("x+5", ba, pf, answer) == 1);
//    assert(evaluate("", ba, pf, answer) == 1);
//    assert(evaluate("2|3|4", ba, pf, answer) == 0
//                           &&  pf == "23|4|"  &&  answer);
//    assert(evaluate("2|(3|4)", ba, pf, answer) == 0
//                           &&  pf == "234||"  &&  answer);
//    assert(evaluate("4  |  !3 & (0&3) ", ba, pf, answer) == 0
//                           &&  pf == "43!03&&|"  &&  !answer);
//    assert(evaluate(" 9  ", ba, pf, answer) == 0  &&  pf == "9"  &&  !answer);
//    ba[2] = false;
//    ba[9] = true;
//    assert(evaluate("((9))", ba, pf, answer) == 0  &&  pf == "9"  &&  answer);
//    assert(evaluate("2| 3", ba, pf, answer) == 0  &&  pf == "23|" &&  !answer);
//
//    assert(evaluate("1", ba, pf, answer) == 0 && answer);
//
//    cout << "Passed all tests" << endl;
//}
