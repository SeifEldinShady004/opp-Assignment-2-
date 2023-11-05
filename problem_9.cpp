// File: A2_S6_20220018_Problem 9.cpp
// Purpose:The purpose of the provided C++ program is to determine whether it's possible to reach a goal of having exactly 42 bears starting with a given number of bears and following a set of rules. The program defines a recursive function bears that checks if it's possible to reach 42 bears, given a certain number of bears and following specific rules.
// Author:Ahmed hussien saad 
// Section:S6
// ID:20220018
// TA:maya ahmed 
// Date: 5 Nov 2023
#include <iostream>
using namespace std;
bool bears(int n) {
    if (n == 42) {
        // If we have exactly 42 bears, we've reached the goal.
        return true;
    } else if (n < 42) {
        // If we have fewer than 42 bears, it's impossible to reach the goal.
        return false;
    } else {
        // Try different moves and check if any of them lead to the goal.
        if (n % 2 == 0 && bears(n / 2)) {
            return true;
        }
        if (n % 3 == 0 && bears(n - n / 3)) {
            return true;
        }
        if (n % 4 == 0 && bears(n - (n % 10) * ((n % 100) / 10))) {
            return true;
        }
        if (n % 5 == 0 && bears(n - 42)) {
            return true;
        }
        // If none of the moves lead to the goal, it's impossible to reach the goal.
        return false;
    }
}

int main() {
    int n1,n2,n3,n4,n5;
    cin>>n1>>n2>>n3>>n4>>n5;
    

    cout << "bear(" << n1 << ") is " << (bears(n1) ? "true" : "false") << endl;
    cout << "bear(" << n2 << ") is " << (bears(n2) ? "true" : "false") << endl;
    cout << "bear(" << n3 << ") is " << (bears(n3) ? "true" : "false") << endl;
    cout << "bear(" << n4 << ") is " << (bears(n4) ? "true" : "false") << endl;
    cout << "bear(" << n5 << ") is " << (bears(n5) ? "true" : "false") << endl;

    return 0;
}
