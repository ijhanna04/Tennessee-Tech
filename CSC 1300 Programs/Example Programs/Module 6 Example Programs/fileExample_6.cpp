/*
	Title:  fileExample_6.cpp
	Author:  April R Crockett
	Date:  7/27/2017
	Purpose:  input file example that reads numbers from a file.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   ifstream inFile;
   int value1, value2, value3, sum;

   // Open the file.
   inFile.open("Numbers.txt");
   
   if(inFile.is_open())
   {

	   // Read the three numbers from the file.
	   inFile >> value1;
	   inFile >> value2;
	   inFile >> value3;

	   // Close the file.
	   inFile.close(); 

	   // Calculate the sum of the numbers.
	   sum = value1 + value2 + value3;

	   // Display the three numbers.
	   cout << "Here are the numbers:\n"
			<< value1 << " " << value2
			<< " " << value3 << endl;

	   // Display the sum of the numbers.
	   cout << "Their sum is: " << sum << endl;
   }
   else
   {
	   cout << "\nOops!  I wasn\'t able to open the file!\n";
   }
   return 0;
} 