/************************************************************************
 *	Title:             inputEx3.cpp	
 *  Module:            2
 *	Author:            April R. Crockett
 *	Date of Creation:  June 27, 2022
 *	Purpose:           This program demonstrates how cin can read 
                       multiple values of different data types.
 ************************************************************************/

#include <iostream>
using namespace std;

int main()
{
	//variable definitions
	int whole;
	double fractional;
	char letter;

	//get INPUT from the user
	cout << "\n\nEnter an integer, a double, and a character: ";
	cin >> whole >> fractional >> letter;

	//Display OUTPUT
	cout << "Whole: " << whole  << endl;
	cout << "Fractional: " << fractional << endl;
	cout << "Letter: " << letter << endl;

	return 0;
}