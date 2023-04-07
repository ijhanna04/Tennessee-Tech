// This file demonstrates the getline function with a user-
// specified delimiter.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   const int SIZE = 81;  // Size of input array
   char input[SIZE];     // To hold file input
   
   // Open the file for input.
   fstream dataFile("names2.txt", ios::in);

   // Read items from the file using $ as a delimiter.
   dataFile.getline(input, SIZE, '$');
   while (!dataFile.eof())
   {
      cout << input << endl;
      dataFile.getline(input, SIZE, '$');
   }
   
   // Close the file.
   dataFile.close();
   return 0;
}
