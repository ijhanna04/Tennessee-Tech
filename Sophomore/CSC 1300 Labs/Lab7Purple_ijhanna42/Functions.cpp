// include the Lab7.h header file
#include "Lab7.h"


// getData function
void getData(string &n1, int &a1, string &p1, string &n2, int &a2, string &p2){

    // variable definitions
    int name1Aget = 0, name2Aget = 0;

    // get user input for first super hero
    cout << "Enter the data for the first super hero:\n";
    cout << "NAME: ";
    cin >> n1;
    cout << "AGE: ";
    cin >> a1;
    cout << "PET (dog/cat/rabbit/gunea pig): ";
    cin >> p1;

    // get user input for second super hero
    cout << "\n\nEnter the data for the second super hero:\n";
    cout << "NAME: ";
    cin >> n2;
    cout << "AGE: ";
    cin >> a2;
    cout << "PET (dog/cat/rabbit/gunea pig): ";
    cin >> p2;

    // ASCII value calculations
    for(int i = 0; i < n1.length(); i++)
    {
        name1Aget += static_cast<int>(n1.at(i));
    }

    
    for(int j = 0; j < n2.length(); j++)
    {
        name2Aget += static_cast<int>(n2.at(j));
    }

    // ASCII value output
    cout << endl << "The ASCII value of " << n1 << " is: " << name1Aget;
    cout << endl << "The ASCII value of " << n2 << " is: " << name2Aget;
}

//calculateResults function
bool calculateResults(int name1Ares, int age1res, string pet1res, int name2Ares, int age2res, string pet2res){

    // variable definitions
    int tally = 0;

    // check 1 calculations
    if((name1Ares > name2Ares - 50) && (name1Ares < name2Ares + 50)){
        cout << "\nCHECK 1 is true";
        tally++;
    }else {
        cout << "\nCHECK 1 is false.";
    }

    // check 2 calculations
    if((age1res > age2res - 10) && (age1res < age2res + 10)){
        cout << "\nCHECK 2 is true";
        tally++;
    }else {
        cout << "\nCHECK 2 is false.";
    }

    // check 3 calculations
    if(pet1res == pet2res){
        cout << "\nCHECK 3 is true.";
        tally++;
    }else {
        cout << "\nCHECK 3 is false.";
    }

    // compatibility check
    if (tally >= 2){
        return true;
    }else {
        return false;
    }
}