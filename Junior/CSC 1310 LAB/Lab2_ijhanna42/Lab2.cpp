/*
	Title:  Lab2.cpp
	Author: Ian Hanna
	Date:  September 19, 2023
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << "\nThe result is: " << sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if (isMember(myArray, num, ARRAY_SIZE)) {
					cout << "\n\nYes! " << num << " IS in the array!";
				} else {
					cout << "\n\nNo! " << num << " is NOT in the array.";
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString, userString.length());
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				cout << isPalindrome(userStrModified);
				if (isPalindrome(userStrModified)) {
					cout << "\nYes! " << userString << " IS a palindrome!";
				} else {
					cout << "\nNo! " << userString << " is NOT a palindrome.";
				}
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << "\nThe value of " << num1 << " x " << num2 << " is " << multiply(num1, num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!

// Sum Of Numbers Recursive Function
int sumOfNumbers(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + sumOfNumbers(n - 1);
    }
}

// IsMember Array Recursive Function
bool isMember(int arr[], int value, int size) {
    if (size == 0) {
        return false;
    }

    if (arr[0] == value) {
        return true;
    }

    return isMember(arr + 1, size - 1, value);
}

// String Reverser Recursive Function
void stringReverser(string str, int length) {
    if (length == 0) {
        return;
    }

    cout << str[length - 1];

    stringReverser(str, length - 1);
}

// Palindrome Detector Recursive Function
bool isPalindrome(string str) {
    if (str.length() <= 1) {
        return true;
    }
    if (str[0] != str[str.length() - 1]) {
        return false;
    }
    return isPalindrome(str.substr(1, str.length() - 2));
}

// Recursive Multiplication Recursive Function
int multiply(int x, int y) {
    if (y == 0) {
        return 0;
    } else if (y > 0) {
        return x + multiply(x, y - 1);
    } else {
        return -multiply(x, -y);
    }
}