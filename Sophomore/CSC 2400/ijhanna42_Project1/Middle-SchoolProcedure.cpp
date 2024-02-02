#include <iostream>
#include <vector>

using namespace std;

vector<int> primeFactorization(int n) {
    vector<int> factors;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    if (n > 1)
        factors.push_back(n);

    return factors;
}

int middleSchoolProcedure(int a, int b) {
    vector<int> factorsA = primeFactorization(a);
    vector<int> factorsB = primeFactorization(b);

    int gcd = 1;
    for (int i = 0; i < factorsA.size(); i++) {
        for (int j = 0; j < factorsB.size(); j++) {
            if (factorsA[i] == factorsB[j]) {
                gcd *= factorsA[i];
                factorsB.erase(factorsB.begin() + j);
                break;
            }
        }
    }

    return gcd;
}

int main(int argc, char* argv[]) {
    int a = stoi(argv[1]);
    int b = stoi(argv[2]);

    int gcd = middleSchoolProcedure(a, b);

    cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;

    return 0;
}