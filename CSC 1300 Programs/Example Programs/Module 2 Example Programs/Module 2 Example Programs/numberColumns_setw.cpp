/************************************************************************
 *	Title:             numberColumns_setw.cpp	
 *  Module:            2
 *	Author:            April R. Crockett
 *	Date of Creation:  September 9, 2019
 *	Purpose:           To demonstrate improved output formatting by
 *                     using a text stream manipulator setw
 ************************************************************************/

#include <iostream>
#include <iomanip>      // Required for setw
using namespace std;

int main()
{
   cout << setw(12) << 2897 << setw(6) << 5 << setw(6) << 837 << endl;
   cout << setw(12) << 34 << setw(6) << 7 << setw(6) << 1623 << endl;
   cout << setw(12) << 390 << setw(6) << 3456 << setw(6) << 12 << endl;
   
   return 0;
}