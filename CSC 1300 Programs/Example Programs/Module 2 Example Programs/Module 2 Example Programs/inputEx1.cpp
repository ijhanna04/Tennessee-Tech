/************************************************************************
 *	Title:             inputEx1.cpp	
 *  Module:            2
 *	Author:            April R. Crockett
 *	Date of Creation:  June 27, 2022
 *	Purpose:           This program asks the user to enter the length and 
 *                     width of a rectangle. It calculates the 
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
   cout << "This program calculates the area of a ";
   cout << "rectangle.\n";
   cout << "What is the length of the rectangle? ";
   cin >> length;
   cout << "What is the width of the rectangle? ";
   cin >> width;
   
   //CALCULATE the area
   area = length * width;
   
   //OUTPUT the result
   cout << "The area of the rectangle is " << area << ".\n";
   
   return 0;
}







