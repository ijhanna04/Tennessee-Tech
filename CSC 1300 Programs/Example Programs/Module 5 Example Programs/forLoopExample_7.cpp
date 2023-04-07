/*
	Title: 		forLoopExample_7.cpp
	Author: 	April R. Crockett
	Date:  		February 12, 2009
	Purpose:  	C++ program to help teachers grade exams 
				and to demonstrate a for loop).
*/
#include <iostream>
using namespace std;

int main()
{	
	
	
	for (int x=0, y=3; y <= 10; x++, y++)
	{
		cout << "\nThe area of a rectangle with width of " << x 
			<< " and height of " << y << " is "<< (x*y) <<".";
	}
		
	cout << endl;
	
    return 0;	
}
		