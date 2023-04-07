/*
    Title:      lab4.cpp
    Author:     Ian Hanna
    Date        February 2023
    Purpose:    While Loops
*/

#include <iostream>
using namespace std;

int main()
{
    // integers for screen time and study time
    int hoursPhone, hoursHomework;

    // get user input for screen time
    cout << "Rounding to the nearest hour, how many hours is your daily average PHONE screen time?" << endl;
    cout << "AVG DAILY SCREEN-TIME HOURS: ";
    cin >> hoursPhone;

    // validate user input for screen time to make sure they entered a number between 0 and 24
    // asks user to re-enter a number if invalid
    while ((hoursPhone > 24) || (hoursPhone < 0))
    {
        cout << "Invalid number. Please enter a number between 0 and 24: ";
        cin >> hoursPhone;
    }

    // get user input for study time
    cout << endl << "Rounding to the nearest hour, how many hours is your daily average study or homework time?" << endl;
    cout << "AVG DAILY STUDY or HOMEWORK HOURS: ";
    cin >> hoursHomework;

    // validate user input for screen time to make sure they entered a number between 0 and 24
    // asks user to re-enter a number if invalid
    while ((hoursHomework > 24) || (hoursHomework < 0))
    {
        cout << "Invalid number. Please enter a number between 0 and 24: ";
        cin >> hoursHomework;
    }

    // logic operations for advice based on screen time and homework time
    if ((hoursPhone <= 2) && (hoursHomework < 2)){
        cout << endl << "You may want to study more if you wish to learn anything." << endl;
    } else if ((hoursPhone <= 2) && (hoursHomework >= 6)){
        cout << endl << "You need to socialize with people more often" << endl;
    } else if ((hoursPhone > 2) && (hoursHomework >= 6)){
        cout << endl << "You need to socialize with people more often and get off that phone." << endl;
    } else if ((hoursPhone <= 2) && (hoursHomework >= 2) && (hoursHomework < 6)){
        cout << endl <<"You manage your time well." << endl;
    } else if ((hoursPhone > 2) && (hoursHomework < 6)){
        cout << endl << "What are you going to do if you lose that phone?" << endl << "It is interfering with your ability to have a real life." << endl;
    }

    return 0;
}