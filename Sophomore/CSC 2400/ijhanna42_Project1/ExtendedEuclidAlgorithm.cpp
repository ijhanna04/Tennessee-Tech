#include <iostream>
using namespace std;

// Extended Euclid Algorithm function
int xGCD(int a, int b, int &x, int &y) {

    // return m if n is 0
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    // find the gcd of the given inputs n, remainder of a / b
    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    
    return gcd;
}

int main()
{

    int m = 0, n = 0, x, y, gcd;

    // get integers from user
    cout << "Enter two integers: ";
    cin >> m >> n;

    if(m < n) std::swap(m, n);

    // run the xGCD function
    gcd = xGCD(m, n, x, y);

    // print the gcd, x, and y
    cout << "GCD: " << gcd << ", x = " << x << ", y = " << y << endl;

    return 0;
}