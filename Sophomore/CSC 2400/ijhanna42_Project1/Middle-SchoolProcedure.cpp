#include <iostream>
using namespace std;

int main() {
    int a, b, i, gcd;

    // get integers from user
    cout << "Enter two integers: ";
    cin >> a >> b;

    // Find the smaller of the two numbers
    if (a < b) {
        gcd = a;
    } else {
        gcd = b;
    }

    // Find the gcd
    for (i = 1; i <= gcd; i++) {
        // check if both numbers are divisible by i
        if (a % i == 0 && b % i == 0) {
            // if they are divisible by i, set gcd to i
            gcd = i;
        }
    }

    // print the gcd
    cout << "The greatest common divisor of " << a << " and " << b << " is " << gcd << endl;

    return 0;
}