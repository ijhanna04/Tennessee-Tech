/*
    Title:      lab7.cpp
    Author:     Ian Hanna
    Date        March 2023
    Purpose:    Super Hero Compatibility Test
*/

// include the Lab7.h header file
#include "Lab7.h"

// main function
int main(){

    // variable definitions
    string name1, name2, pet1, pet2;
    int age1, age2;
    int name1A = 0;
    int name2A = 0;
    
    // print out "Super Hero Roomate Compatibility Check"
    cout << "Super Hero Roomate Compatibility Check\n\n";

    // call getData and calculateResults functions
    getData(name1, age1, pet1, name2, age2, pet2);
    calculateResults(name1A, age1, pet1, name2A, age2, pet2);

    // print out ***** RESULTS *****
    cout << "\n\n***** RESULTS *****";
    
    // results calculations
    if (calculateResults(name1A, age1, pet1, name2A, age2, pet2)){
        cout << endl << name1 << " and " << name2 << " are compatible to be roomates!";
    } else {
        cout << endl << name1 << " and " << name2 << " are not compatible to be roomates.";
    }

    return 0;
}


