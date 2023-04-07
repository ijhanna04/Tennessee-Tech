// This program uses the write and read functions.
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   const int SIZE = 10;
   fstream file;
   int number = 7;

   // Open the file for output in binary mode.
   file.open("numbers.dat", ios::out | ios::binary);

   // Write the contents of the array to the file.
   cout << "Writing the data to the file.\n";
   file.write(reinterpret_cast<char *>(number), sizeof(number));

   // Close the file.
   file.close();

   // Open the file for input in binary mode.
   file.open("numbers.dat", ios::in | ios::binary);

   // Read the contents of the file into the array.
   cout << "Now reading the data back into memory.\n";
   file.read(reinterpret_cast<char *>(number), sizeof(number));

   // Display
   cout << number << endl;

   // Close the file.
   file.close();
   return 0;
}
