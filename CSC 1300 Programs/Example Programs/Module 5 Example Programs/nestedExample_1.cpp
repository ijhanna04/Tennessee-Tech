/*
	Title: nestedExample_1.cpp
	Author: Gaddis & Krupnow, modified by April Crockett
	Date:  February 15, 2009
	Purpose:  This program finds the average time spent programming 
			  by a student each day over a three day period.
*/

#include <iostream>
using namespace std;

int main()
{
	int numStudents;
	float numHours, total, average;
	int student;     // these are the counters for the loops

	cout << "\n This program will find the average number of hours a day\n" 
	<< " that a student spent programming over a long weekend\n\n";
	
	cout << " How many students are there ?  ";
	cin >> numStudents; 
	
	int counter = 0;

	for(student = 1; student <= numStudents; student++)
	{
		total = 0;

		for(int day = 1; day <= 3; day++)
		{
			cout << "\n Enter the number of hours worked by student " << student <<" on day " << day << ":  ";
			cin >> numHours;

			total += numHours; //running total of hours spent
			counter++;
		}

		average = total / 3; //average number of hours for this student

		cout << endl;

		cout << " The average number of hours per day spent programming by "
		<< "student " << student << " is " << average
		<< endl << endl << endl;
	} 
	
	cout << "\n\ncounter is: " << counter << endl << endl;

	return 0;	
}




