#include <iostream>

using namespace std;

int main() {

    // get integers from the user
    int m = 0, n = 0;
    cout << "Enter two integers: ";
    cin >> m >> n;

    // Check if the numbers are consecutive integers
    int t = min(m, n);
    while (t > 0) {

        // if the numbers are consecutive integers, print and exit
        if (m % t == 0 && n % t == 0) {
            cout << "The greatest common divisor of " << m << " and " << n << " is " << t << endl;
            return 0;
        }

    // decrement t and repeat the loop if the numbers are not consecutive integers
    t--;
    }

    // print 1 if there is no common divisor found
    cout << "The greatest common divisor of " << m << " and " << n << " is 1" << endl;
    return 0;
}