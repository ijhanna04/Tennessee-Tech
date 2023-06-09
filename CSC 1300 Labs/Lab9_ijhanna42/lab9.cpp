/*
    Title:      ijhanna42_lab9.cpp
    Author:     Ian Hanna
    Date        April 2023
    Purpose:    Pointers, Array & Pointer Notation, Dynamic Memory Allocation
*/

#include <iostream>
using namespace std;

//function prototypes
void getParanormalData(int, int*, string*, string*);
void getStats(int, int*, int*, double*, int*);

int main(){
    //variable definintions
    string lineOfDashes(50, '-');
    int numInvestigators;
    int total;
    double average;
    int highestIndex;
    char nameLocation[100];

    //pointer to int
    int *numRecordingsPtr = nullptr;

    //pointer to string
    string *arrayNamePtr = nullptr;

    //pointer to string
    string *arrayDatePtr = nullptr;

    //ask user for location they are investigating
    cout << "Hello! What haunted location are you investigating?\n";
    cin.ignore();
    cin.getline(nameLocation, 100);

    //ask user for the number of investigators at the location
    cout << "\nHow many investigators will be working at this location?\n";
    cin >> numInvestigators;

    //validate the number entered is at least 1 but not greater than 25
    while ((numInvestigators < 1)||(numInvestigators > 25)){
        cout << "Oops! You must enter 1 through 25.\n";
        cout << "\nHow many investigators will be working at this location?\n";
        cin >> numInvestigators;
    }

    //dynamically allocate pointer arrays
    numRecordingsPtr = new int[numInvestigators];
    arrayNamePtr = new string[numInvestigators];
    arrayDatePtr = new string[numInvestigators];

    //call functions
    getParanormalData(numInvestigators, numRecordingsPtr, arrayNamePtr, arrayDatePtr);
    getStats(numInvestigators, numRecordingsPtr, &total, &average, &highestIndex);

    //print out the results
    cout << endl << lineOfDashes;
    cout << "\nThe total amount of EVPs recorded by all " << numInvestigators << " investigators at " << nameLocation << " is " << total << " recordings.\n";
    cout << "\nThe average amount of EVPs recorded at " << nameLocation << " is " << average << " recordings.\n";
    cout << "\nThe investigator who recorded the most (" << numRecordingsPtr[highestIndex] << " recordings) is " << arrayNamePtr[highestIndex] << " on " << arrayDatePtr[highestIndex] << "!!\n";
    cout << lineOfDashes;

    //release the dynamically allocated arrays
    delete [] numRecordingsPtr;
    delete [] arrayNamePtr;
    delete [] arrayDatePtr;
}

//getParanormalData function
void getParanormalData(int numInvestigators, int *numRecordings, string *arrayNames, string *arrayDates){
    cout << "\nEnter the investigator's name, the day of their investigation, and the number of EVPs they recorded on their voice recorder.\n";
    
    //iterate through each element of the array and allow user to enter a name, date, and number of recordings
    for (int i = 0; i < numInvestigators; i++){
        cout << "INVESTIGATOR " << i + 1 << ":\n";
        cout << "       NAME - ";
        cin.ignore();
        string name;
        getline(cin, name);

        cout << "       DAY (ex: 04-03-2023) - ";
        arrayNames[i] = name;
        string date;
        getline(cin, date);
        arrayDates[i] = date;

        cout << "       NUMBER OF EVPs - ";
        cin >> numRecordings[i];
    }
}

//getStats function
void getStats(int numInvestigators, int *numEVPs, int *totalPtr, double *averagePtr, int *indexPtr){
    int max = 0;
    double totalEVPs;
    *totalPtr = 0;
    *averagePtr = 0.0;

    for (int i = 0; i < numInvestigators; i++){
        //find total number of EVPs
        totalEVPs += numEVPs[i];
        *totalPtr = totalEVPs;
        //find average number of EVPs
        *averagePtr = totalEVPs / numInvestigators;

        //find investigator with highest number of recordings
        if (numEVPs[i] > max){
            max = numEVPs[i];
            *indexPtr = i;
        }
    }

    
}