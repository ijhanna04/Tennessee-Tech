#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    float jGame1, jGame2, jGame3, fGame1, jGameTotal, fGame2, fGame3, fGameTotal, mGame1, mGame2, mGame3, mGameTotal, finalGameTotal, averageGamePrice;
    string monthOne, monthTwo, monthThree;

    cout << "Enter the month: ";
    cin >> monthOne;

    cout << "Price of Game 1: $";
    cin >> jGame1;

    cout << "Price of Game 2: $";
    cin >> jGame2;

    cout << "Price of Game 3: $";
    cin >> jGame3;
    
    jGameTotal = jGame1 + jGame2 + jGame3;
    cout << fixed << setprecision(2) << "Total cost of all three games for " << monthOne << ": $" << jGameTotal << endl << endl;

    cout << "Enter the month: ";
    cin >> monthOne;

    cout << "Price of Game 1: $";
    cin >> fGame1;

    cout << "Price of Game 2: $";
    cin >> fGame2;

    cout << "Price of Game 3: $";
    cin >> fGame3;
    
    fGameTotal = fGame1 + fGame2 + fGame3;
    cout << fixed << setprecision(2) << "Total cost of all three games for " << monthOne << ": $" << fGameTotal << endl << endl;

    cout << "Enter the month: ";
    cin >> monthOne;

    cout << "Price of Game 1: $";
    cin >> mGame1;

    cout << "Price of Game 2: $";
    cin >> mGame2;

    cout << "Price of Game 3: $";
    cin >> mGame3;
    
    mGameTotal = mGame1 + mGame2 + mGame3;
    cout << fixed << setprecision(2) << "Total cost of all three games for " << monthOne << ": $" << mGameTotal << endl << endl;

    finalGameTotal = jGameTotal + fGameTotal + mGameTotal;
    averageGamePrice = finalGameTotal / 9;
    cout << fixed << setprecision(2) << "Total amount spent over the three months: $" << finalGameTotal << endl;
    cout << fixed << setprecision(2) << "Average price per game: $" << averageGamePrice;

    return 0;
}