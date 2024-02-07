#include <iostream>

using namespace std;

int main() {

    // get integers from the user
    int m = 0, n = 0, mx, nx;
    cout << "Enter two integers: ";
    cin >> m >> n;

    // if m or n is negative, make them positive
    mx = abs(m);

    nx = abs(n);

    // return m if n is 0
    if(n == 0 && m != 0) {
        cout << "gcd(" << m << ", " << n << ") = " << mx;
        return 0;
    }

    // return n if m is 0
    if(m == 0 && n != 0) {
        cout << "gcd(" << m << ", " << n << ") = " << nx;
        return 0;
    }

    // return undefinded if both m and n are 0
    if (m == 0 && n == 0){
        cout << "gcd(" << m << ", " << n << ") undefined" << endl;
        return 0;
    }


    // if m is less than n, swap m and n
    if (mx < nx){
        int temp = mx;
        mx = nx;
        nx = temp;
    }

    // Check if the numbers are consecutive integers
    int t = min(mx, nx);
    while (t > 0) {




        // if the numbers are consecutive integers, print and exit
        if (mx % t == 0){
            if (nx % t == 0) {
                cout << "gcd(" << m << ", " << n << ") = " << t << endl;
                return 0;
            }

            
        }

        // decrement t and repeat the loop if the numbers are not consecutive integers
        t--;
    }

    // print 1 if there is no common divisor found
    cout << "gcd(" << m << ", " << n << ") = 1" << endl;
    return 0;
}