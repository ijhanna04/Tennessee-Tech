/*
	Title:  integerDivision.cpp
	Author:  April Crockett
	Date:  5-30-2017
	Purpose:  This program asks the user to enter the numerator 
			  and denominator of a fraction and it displays the
              value.  Unfortunately, it uses integer division.
*/

#include <iostream>
using namespace std;

int main()
{
   int numerator, denominator;

   cout << "Enter the numerator: ";
   cin >> numerator;
   cout << "Enter the denominator: ";
   cin >> denominator;
   cout << "The decimal value is ";

   cout << (numerator / denominator) << endl; //oh no!  Integer division!
   
   return 0;
}







