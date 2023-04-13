/*
    Title:      lab8.cpp
    Author:     Ian Hanna
    Date        April 2023
    Purpose:    Pointers, Array & Pointer Notation, Dynamic Memory Allocation
*/

#include <iostream>
using namespace std;

void getParanormalData(int, int*, string*, string*);
void getStats(int, int*, int*, double*, int*);

int main(){
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
    getline(cin, nameLocation);

    //ask user for the number of investigators at the location
    cout << "\nHow many investigators will be working at this location?\n";
    cin >> numInvestigators;
    //validate the number entered is at least 1 but not greater than 25
    while ((numInvestigators < 1)||(numInvestigators > 25)){
        cout << "Oops! You must enter 1 through 25.\n";
        cout << "\nHow many investigators will be working at this location?\n";
        cin >> numInvestigators;
    }

    numRecordingsPtr = new int[numInvestigators];

    arrayNamePtr = new string[numInvestigators];

    arrayDatePtr = new string[numInvestigators];

    getParanormalData(numInvestigators, numRecordingsPtr, arrayNamePtr, arrayDatePtr);
    getStats(numInvestigators, numRecordingsPtr, &total, &average, &highestIndex);

    cout << endl << lineOfDashes;
    cout << "\nThe total amount of EVPs recorded by all " << numInvestigators << " investigators at " << nameLocation << " is " << total << " recordings.\n";
    cout << "\nThe average amount of EVPs recorded at " << nameLocation << " is " << average << " recordings.\n";
    cout << "\nThe investigator who recorded the most (" << numRecordingsPtr[highestIndex] << " recordings) is " << arrayNamePtr[highestIndex] << " on " << arrayDatePtr[highestIndex] << "!!\n";
    cout << lineOfDashes;

    delete [] numRecordingsPtr;
    delete [] arrayNamePtr;
    delete [] arrayDatePtr;

}

void getParanormalData(int numInvestigators, int *numRecordings, string *arrayNames, string *arrayDates){
    cout << "\nEnter the investigator's name, the day of their investigation, and the number of EVPs they recorded on their voice recorder.\n";
    for (int i = 0; i < numInvestigators; i++){
        cout << "INVESTIGATOR " << i + 1 << ":\n";
        cout << "       NAME - ";
        cin >> arrayNames[i];
        cout << "       DAY (ex: 04-03-2023) - ";
        cin >> arrayDates[i];
        cout << "       NUMBER OF EVPs - ";
        cin >> numRecordings[i];
    }
}

void getStats(int numInvestigators, int *numEVPs, int *totalPtr, double *averagePtr, int *indexPtr){
    int max = 0;
    *totalPtr = 0;
    *averagePtr = 0.0;
    for (int i = 0; i < numInvestigators; i++){
        *totalPtr += numEVPs[i];
        *averagePtr = *totalPtr / numInvestigators;
        if (numEVPs[i] > max){
            max = numEVPs[i];
            *indexPtr = i;
        }
    }

    
}