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
    int numInvestigators;
    int total;
    double average;
    int highestIndex;
    char nameLocation[100];
    //pointer to int
    int* numRecordingsPtr = nullptr;
    //pointer to string
    string* arrayNameInvestigator = nullptr;
    //pointer to string
    string* arrayDate = nullptr;

    //ask user for location they are investigating
    cout << "Hello! What haunted location are you investigating?";
    cin >> nameLocation;

    //ask user for the number of investigators at the location
    cout << "How many investigators will be working at this location?";
    cin >> numInvestigators;
    //validate the number entered is at least 1 but not greater than 25
    while ((numInvestigators < 1)||(numInvestigators > 25)){
        cout << "Oops! You must enter 1 through 25.";
        cin >> numInvestigators;
    }

    getParanormalData(numInvestigators, numRecordingsPtr, arrayNameInvestigator, arrayDate);
    getStats(numInvestigators, /*number of recordings each investigator had*/, &total, &average, &highestIndex);

    cout << "\nThe total amount of EVPs recorded by all " << numInvestigators << " investigators at " << nameLocation << " is " << total << " recordings.";
    cout << "\nThe average amount of EVPs recorded at " << nameLocation << " is " << average << " recordings.";
    cout << "\nThe investigator who recorded the most (" << /*most recordings*/ << " recordings) is " << highestIndex << " on " << /*date of most recordings*/;
//remember to delete arrays
}

void getParanormalData(int numInvestigators, int* numRecordings, string* arrayNames, string* arrayDates){
    cout << "Enter the investigator's name, the day of their investigation, and the number of EVPs they recorded on their voice recorder.";
    for (int i = 0; i < numInvestigators; i++){
        cout << "INVESTIGATOR " << i + 1 << ":\n";
        cout << right << "NAME - ";
        cin >> arrayNames[i];
        cout << "DAY (ex: 04-03-2023) - ";
        cin >> arrayDates[i];
        cout << "NUMBER OF EVPs - ";
        cin >> numRecordings[i];
    }
}

void getStats(int numInvestigators, int* numEVPs, int* totalPtr, double* averagePtr, int* highestIndexPtr){

}