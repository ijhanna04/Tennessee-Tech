/*
    Title:      lab3.cpp
    Author:     Ian Hanna
    Date        February 2023
    Purpose:    Job Forecast Program
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Variables
    string lineOfStars(79, '*');
    string companyLike1, companyLike2, companyHate, vehicleLike1, vehicleLike2, vehicleHate;
    int numBetween, numYears, salary, salMultiple, caseNum;

    //Seed random number generator to time
    srand(time(0));

    //set output with a precision of 2
    cout << setprecision(2) << fixed;

    // Print line of stars and paragraph of text
    cout << lineOfStars << endl;
    cout << "JOB FORECAST" << endl;
    cout << lineOfStars << endl;
    cout << "Enter in the information requested below and I will determine the job you will" << endl;
    cout << "get, how many years you will work there, your salary, and the company car you" << endl;
    cout << "will drive." << endl << endl;

    // Get input for company and car interests
    cout << "Company you like: ";
    cin >> companyLike1;

    cout << "Another company you like: ";
    cin >> companyLike2;

    cout << "Company you hate: ";
    cin >> companyHate;

    cout << endl << "Vehicle you like: ";
    cin >> vehicleLike1;

    cout << "Another vehicle you like: ";
    cin >> vehicleLike2;

    cout << "Vehicle you hate: ";
    cin >> vehicleHate;

    // Get input for number between 1 and 25
    cout << endl << "Pick an integer between 1 to 25 (inclusively): ";
    cin >> numBetween;

    // Calculations for number of years at job and salary
    numYears = rand() % (100 - 1 + 1) + 1;
    salMultiple = rand() % (10 - 1 + 1) + 1;
    salary = numBetween * 10000 * salMultiple;

    //Determine the user's future with branch statement
    if(numBetween >= 20){
        caseNum = 1;
    } else if (numBetween > 7 && numBetween < 20){
        caseNum = 2;
    } else {
        caseNum = 3;
    }

    cout << endl << lineOfStars << endl << endl;

    // Switch statement that outputs results
    switch(caseNum)
    {
        case 1: 
            cout << "You will work at " << companyLike1 << " for " << numYears << " years making $" << salary << " per year" << endl << "and driving a red " << vehicleLike2 << " on business trips." << endl;
            break;
        case 2: 
            cout << "You will work at " << companyLike2 << " for " << numYears << " years making $" << salary << " per year" << endl << "and driving a royal blue " << vehicleLike2 << " on business trips." << endl;
            break;
        case 3:
            cout << "You will work at " << companyHate << " for " << numYears << " years making $" << salary << " per year" << endl << "and driving a neon orange " << vehicleHate << " on business trips." << endl;
            break;
    }

    cout << endl << lineOfStars << endl;

    return 0;
}
