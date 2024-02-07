#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// compute the prime factors of a given number
vector<int> primeFactors(int n) {
    vector<int> factors;
    for (int i = 2; i <= n / i; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

// compute the greatest common divisor using the middle-school procedure
int gcdMiddleSchool(int m, int n) {
    vector<int> mFactors = primeFactors(m);
    vector<int> nFactors = primeFactors(n);

    int gcd = 1;
    
    for (int factor : mFactors) {
        auto it = find(nFactors.begin(), nFactors.end(), factor);
        if (it != nFactors.end()) {
            gcd *= factor;
            nFactors.erase(it); // delete the common factor from 'n' factors to avoid counting it again
        }
    }

    return gcd;
}

int main() {
   int m, n, mx, nx;

   // Get integers from user
   cout << "Enter two integers: ";
   cin >> m >> n;

   mx = abs(m);
   nx = abs(n);

   // Computing and printing their GCD using middle-school procedure
   if (m == 0 && n == 0){
        cout << "gcd(" << m << ", " << n << ") = undefined" << endl; 
   } else if (m == 0) {
        cout << "gcd(" << m << ", " << n << ") = " << nx << endl; 
   } else if (n == 0) {
        cout << "gcd(" << m << ", " << n << ") = " << mx << endl; 
   } else {
        cout << "gcd(" << m << ", " << n << ") = " << gcdMiddleSchool(mx, nx) << '\n';
   }
   return 0;
}