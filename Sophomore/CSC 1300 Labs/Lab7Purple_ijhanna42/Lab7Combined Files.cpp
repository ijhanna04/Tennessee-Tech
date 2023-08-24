#include <iostream>
using namespace std;

string name1, name2, pet1, pet2;
    int age1, age2;
    bool check1, check2, check3;

    int tally = 0;
    int name1A = 0;
    int name2A = 0;

    void getData(string&, int&, string&, string&, int&, string&);
    bool calculateResults(int, int, string, int, int, string);


int main(){
    
    cout << "Super Hero Roomate Compatibility Check\n\n";

    getData(name1, age1, pet1, name2, age2, pet2);
    calculateResults(name1A, age1, pet1, name2A, age2, pet2);
    cout << "\n\n***** RESULTS *****";
    if (calculateResults(name1A, age1, pet1, name2A, age2, pet2)){
        cout << endl << name1 << " and " << name2 << " are compatible to be roomates!";
    } else {
        cout << endl << name1 << " and " << name2 << " are not compatible to be roomates.";
    }
    return 0;
}

void getData(string &n1, int &a1, string &p1, string &n2, int &a2, string &p2){
    cout << "Enter the data for the first super hero:\n";
    cout << "NAME: ";
    cin >> name1;
    cout << "AGE: ";
    cin >> age1;
    cout << "PET (dog/cat/rabbit/gunea pig): ";
    cin >> pet1;
    cout << "\n\nEnter the data for the second super hero:\n";
    cout << "NAME: ";
    cin >> name2;
    cout << "AGE: ";
    cin >> age2;
    cout << "PET (dog/cat/rabbit/gunea pig): ";
    cin >> pet2;

    
    for(int i = 0; i < name1.length(); i++)
    {
        name1A += static_cast<int>(name1.at(i));
    }

    
    for(int j = 0; j < name2.length(); j++)
    {
        name2A += static_cast<int>(name2.at(j));
    }

    cout << endl << "The ASCII value of " << name1 << " is: " << name1A;
    cout << endl << "The ASCII value of " << name2 << " is: " << name2A;
}

bool calculateResults(int name1A, int age1, string pet1, int name2A, int age2ref, string pet2){
    if((name1A > name2A - 25) && (name1A < name2A +25)){
        check1 = true;
        cout << "\nCHECK 1 is true";
        tally++;
    }else {
        check1 = false;
        cout << "\nCHECK 1 is false.";
    }

    if((age1 > age2 - 5) && (age1 < age2 + 5)){
        check2 = true;
        cout << "\nCHECK 2 is true";
        tally++;
    }else {
        check2 = false;
        cout << "\nCHECK 2 is false.";
    }

    if(pet1 == pet2){
        check3 = true;
        cout << "\nCHECK 3 is true.";
        tally++;
    }else {
        check3 = false;
        cout << "\nCHECK 3 is false.";
    }
    if (tally >= 2){
        return true;
    }else {
        return false;
    }
}