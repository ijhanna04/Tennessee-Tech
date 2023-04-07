#include <iostream>
using namespace std;

int main(){
    int nematodesTamed;
    int nematodesAssigned;

    cout << "Enter the number of nematodes tamed: ";
    cin >> nematodesTamed;

    nematodesAssigned = nematodesTamed / 5;
    cout << endl;

    cout << "Number of nematodes that will be assigned to each of the 5 houses: " << nematodesAssigned;

    return 0;
} 