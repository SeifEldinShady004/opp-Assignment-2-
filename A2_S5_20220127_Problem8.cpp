// File:  A2_S5_20220127_Problem8.cpp
// Purpose:  the program generate a pattern
// Author: Rahma Maged Mohamed Mohamed
// Section: S5
// ID: 20220127
// TA: Maya Ahmed
// Date: 5 Nov 2023
#include <iostream>
using namespace std;
void Pattern(int n, int i){
    if (n == 0)
        return;

    Pattern(n / 2, i);

    for (int j = 0; j < i; j++)
        cout << "  ";
    for (int j = 0; j < n; j++)
        cout << "* ";
    cout << endl;

    Pattern(n / 2, i + n / 2);

}
int main() {
    Pattern(8,0);
}
