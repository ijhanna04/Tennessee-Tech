#include <iostream>
#include <tuple>

using namespace std;

tuple<int, int, int> extendedEuclid(int a, int b) {
    if (a == 0)
        return make_tuple(b, 0, 1);

    int gcd, x, y;
    tie(gcd, x, y) = extendedEuclid(b % a, a);

    return make_tuple(gcd, (y - (b/a) * x), x);
}

int main(int argc, char* argv[]) {
    int a = stoi(argv[1]);
    int b = stoi(argv[2]);

    int gcd, x, y;
    tie(gcd, x, y) = extendedEuclid(a, b);

    cout << a << "*(" << x << ") + " << b << "*(" << y << ") = " << gcd << endl;

    return 0;
}