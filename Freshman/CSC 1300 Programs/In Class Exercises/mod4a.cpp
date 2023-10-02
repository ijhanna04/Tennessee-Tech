#include <iostream>
using namespace std;

int main()
{
    int numParty;

    cout << "How many are in your party? ";
    cin >> numParty;

    if (numParty <= 2 && numParty > 0){
        cout << "You may be seated at a small table";
    } else if (numParty <= 0){
        cout << "INVALID NUMBER IN PARTY";
    } else {
        cout << "You may be seated at a large table";
    }
    return 0;
}