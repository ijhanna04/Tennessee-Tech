/*
	Filename: 	charFuncsB.cpp
	Author: 	April Crockett
	Date: 		1/20/2021
	Purpose: 	Demonstrates the tolower function 
*/
#include <iostream>
#include <cctype> //required to use tolower
#include <iomanip>
using namespace std;

int main()
{
   const double PI = 3.14159;  // Constant for Pi
   double radius;              // The circle's radius
   char goAgain;               // To hold Y or N

   cout << "This program calculates the area of a circle.\n";
   cout << fixed << setprecision(2);

   do //beginning of do-while loop that allows program to repeat
   {
      // Get the radius and display the area.
      cout << "Enter the circle's radius: ";
      cin >> radius;
      cout << "The area is " << (PI * radius * radius);
      cout << endl;

      // Does the user want to do this again?
      cout << "Calculate another? (Y or N) ";
      cin >> goAgain;
	  goAgain = tolower(goAgain);
	 
      // Validate the input with a while loop
      while (goAgain != 'y' && goAgain != 'n')
      {
         cout << "Please enter Y or N: ";
         cin >> goAgain;
		 goAgain = tolower(goAgain);
      }

   }while (goAgain == 'y');  
   
   return 0;
}