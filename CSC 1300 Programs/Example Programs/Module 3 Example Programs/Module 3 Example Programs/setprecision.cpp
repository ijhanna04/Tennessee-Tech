/*
	Title:  setprecision.cpp
	Author:  April Crockett
	Date: 2018
	Purpose: This program demonstrates how setprecision 
	         rounds a floating point value. 
			
*/

#include <iostream>
#include <iomanip> //required to use setprecision
using namespace std;

int main()
{
   double quotient = 132.36485967;

   cout << "WITHOUT SETPRECISION: " << quotient << endl;
   cout << endl << "NOW WITH SETPRECISION STARTING WITH 5 and down to 1:\n";
   cout << setprecision(5) << quotient << endl;
   cout << setprecision(4) << quotient << endl;
   cout << setprecision(3) << quotient << endl;
   cout << setprecision(2) << quotient << endl;
   cout << setprecision(1) << quotient << endl;
   
   cout << endl << "NOW WITH FIXED\n\n";
   cout << fixed;
   cout << setprecision(5) << quotient << endl;
   cout << setprecision(4) << quotient << endl;
   cout << setprecision(3) << quotient << endl;
   cout << setprecision(2) << quotient << endl;
   cout << setprecision(1) << quotient << endl;
   
   return 0;
} 