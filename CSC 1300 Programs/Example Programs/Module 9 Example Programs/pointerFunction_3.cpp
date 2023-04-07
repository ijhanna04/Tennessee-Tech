/**********************************************************
	Title: 		pointerFunction_3.cpp
	Author:  	April Crockett
	Date:  		4/1/2022
	Purpose:   	This program demonstrates a logic error
				of trying to return a local variable address
				from a function.
**********************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
string* getAnimals();
void printAnimals(string*);
void sortStrings(string*);
const int SIZE = 5;

int main()
{
	string* animalsArrPtr;
	// Get the user's favorite animals
	animalsArrPtr = getAnimals();

	//Display animals
	printAnimals(animalsArrPtr);
	
	return 0;
}

/*
	getAnimals - creates an array, gets user's data and 
	then returns the memory address of the array
*/
string* getAnimals()
{
	string animalsArray[SIZE];
	cout << "\n\nPlease enter your favorite animals:\n";
	for(int i = 0; i<SIZE; i++)
	{
		cout << "ANIMAL " << i+1 << ": ";
		getline(cin, *(animalsArray+i));
	}
	cout << endl;
	return animalsArray; //you can't do this because the address of the array will be removed when this function ends since this is a local variable.  
}

/*
	printAnimals - first calls the sort function to sort the array
	and then prints the string array.
*/
void printAnimals(string* arr)
{
	//call the function to sort the animals in alphabetical ascending order
	sortStrings(arr);
	
	cout << "\nHere are your favorite animals printed back out:\n";
	for(int i=0; i<SIZE; i++)
		cout << "ANIMAL " << i+1 << arr[i] << endl;
}

/*
	sortStrings - sorts an array of strings in alphabetical
	ascending order
*/
void sortStrings(string* arr)
{
	int i, j;
	string key;
    for (i = 1; i < SIZE; i++)
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are greater than 
			the key, to one position ahead of their current position
			to move them out of the way for the insert
		*/
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }	
}










