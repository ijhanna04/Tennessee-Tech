/************************************************************************
 *	Title:             leftRight.cpp	
 *  Module:            2
 *	Author:            April R. Crockett
 *	Date of Creation:  September 9, 2019
 *	Purpose:           To demonstrate text stream manipulators
                       setw, left, and right
 ************************************************************************/

#include <iostream>
#include <iomanip>      // Required for setw, left, and right
using namespace std;

int main()
{   
   cout << endl;
   
   cout << "The default alignment for output is right aligned.\n\n";
   
   cout << setw(6) << 2897 << setw(6) << 5 << setw(6) << 837 << endl;
   cout << setw(6) << 34 << setw(6) << 7 << setw(6) << 1623 << endl;
   cout << setw(6) << 390 << setw(6) << 3456 << setw(6) << 12 << endl;
   
   cout << "\n\nUse left stream manipulator.\n\n";
   
   cout << left;
   
   cout << setw(6) << 2897 << setw(6) << 5 << setw(6) << 837 << endl;
   cout << setw(6) << 34 << setw(6) << 7 << setw(6) << 1623 << endl;
   cout << setw(6) << 390 << setw(6) << 3456 << setw(6) << 12 << endl;
   
   cout << "\n\nUse right stream manipulator.\n\n";
   
   cout << right;
   
   cout << setw(6) << 2897 << setw(6) << 5 << setw(6) << 837 << endl;
   cout << setw(6) << 34 << setw(6) << 7 << setw(6) << 1623 << endl;
   cout << setw(6) << 390 << setw(6) << 3456 << setw(6) << 12 << endl;
   
   return 0;
   
}