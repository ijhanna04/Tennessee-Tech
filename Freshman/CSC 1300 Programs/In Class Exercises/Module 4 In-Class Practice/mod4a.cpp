/*
	Title:  mod4a_solution.cpp
	Purpose: In class practice for if-else statements
	Date:  7/25/2022
	Author: April Crockett
*/

#include <iostream>
using namespace std;

int main()
{
	int numPeople;
	cout << "\nHow many are in your party?  ";
	cin >> numPeople;
	
	if(numPeople <= 2)
		cout << "You may be seated at a small table.\n";
	else
		cout << "You may be seated at a large table.\n";
	
	return 0;
}