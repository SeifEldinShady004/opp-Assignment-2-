// File: A2_S6_20220160_Problem 4 .cpp
// Purpose: The program finds prime numbers 
// Author:seif eldin shady abdelsalam
// Section:S6
// ID:20220160
// TA:maya ahmed 
// Date: 5 Nov 2023
#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieve(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}

int

main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<bool> primes = sieve(n);

    cout << "The prime numbers between 2 and " << n << " are: " << endl;
    for (int i = 2; i <= n; i++) {
        if (primes[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
