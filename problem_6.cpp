// File: A2_S6_20220018_Problem 6.cpp
// Purpose:The purpose of the provided C++ program is to convert three integer numbers (n1, n2, and n3) into their binary representations and print the binary representations for each of these numbers. It demonstrates the use of a recursive function binaryPrint to perform the conversion and print the binary output.
// Author:Ahmed hussien saad 
// Section:S6
// ID:20220018
// TA:maya ahmed 
// Date: 5 Nov 2023
#include <iostream>
using namespace std;
void binaryPrint(int n) {
    if (n > 0) {
        // Recursively print the binary representation of n/2
        binaryPrint(n / 2);
    }
    
    // Print the remainder (0 or 1) for the current step
    std::cout << n % 2;
}

int main() {
    int n1;
    int n2 ;
    int n3 ;
    cin>>n1;
    cin>>n2;
    cin>>n3;
   

    cout << "n = " << n1 << " Output: ";
    binaryPrint(n1);
    cout << endl;

    cout << "n = " << n2 << " Output: ";
    binaryPrint(n2);
    scout << endl;

    cout << "n = " << n3 << " Output: ";
    binaryPrint(n3);
    cout << endl;

    return 0;
}
