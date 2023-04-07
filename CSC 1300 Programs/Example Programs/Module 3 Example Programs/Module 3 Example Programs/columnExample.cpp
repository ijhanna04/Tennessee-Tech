/*
	Title:  columnExample.cpp
	Author: April R Crockett
	Date:  9/3/2021
	Purpose: to demonstrate how to set up columns using stream manipulators
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << setprecision(2) << fixed;
	double petPrice1=50.75, petPrice2=73.12, petPrice3=128.54;
	int age1=14, age2=12, age3=5;
	string name1("Bartlet"), name2("Scout"), name3("Jack");
	char vac1='y', vac2='y', vac3='n';
	
	//print the column headers
	cout << setw(20) << "Dog Name" << setw(5) << "Age" << setw(12) << "Price" << endl;
	
	//print the data
	cout << setw(20) << name1 << setw(5) << age1 << setw(4) << "$" << setw(8) << petPrice1 << endl;
	cout << setw(20) << name2 << setw(5) << age2 << setw(4) << "$" << setw(8) << petPrice2 << endl;
	cout << setw(20) << name3 << setw(5) << age3 << setw(4) << "$" << setw(8) << petPrice3 << endl;
	
	return 0;
}