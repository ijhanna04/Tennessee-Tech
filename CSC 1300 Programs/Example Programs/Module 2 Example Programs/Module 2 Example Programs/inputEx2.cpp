/************************************************************************
 *	Title:             inputEx2.cpp	
 *  Module:            2
 *	Author:            April R. Crockett
 *	Date of Creation:  June 27, 2022
 *	Purpose:           This program asks the user to enter the length and 
 *                     width of a rectangle on one line. It calculates the 
 *					   rectangle's area and displays the value on the 
 *   				   screen.
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
	//variable definitions
	int length, width, area;

	//get INPUT from the user
	cout << "\n\nThis program calculates the area of a ";
	cout << "rectangle.\n";
	cout << "Enter the length and width of the rectangle ";
	cout << "separated by a space.\n";
	cin >> length >> width;

	//CALCULATE the area
	area = length * width;

	//OUTPUT the result
	cout << "The area of the rectangle is " << area << endl;

	return 0;
} 

