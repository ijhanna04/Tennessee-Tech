#include <iostream>
using namespace std;

int consecutiveIntegerChecking(int a, int b) {
    int min = std::min(a, b);

    while (min > 0) {
        if (a % min == 0 && b % min == 0)
            return min;
        min--;
    }

    return 1;
}

int main(int argc, char* argv[]) {
    int a = stoi(argv[1]);
    int b = stoi(argv[2]);

    int gcd = consecutiveIntegerChecking(a, b);

    cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;

    return 0;
}