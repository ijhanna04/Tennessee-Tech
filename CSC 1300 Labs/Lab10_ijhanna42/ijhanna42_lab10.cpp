/*
    Title:      ijhanna42_lab10.cpp
    Author:     Ian Hanna
    Date        April 2023
    Purpose:    Structures, Array of Pointers, Dynamic Memory Allocation
*/

#include <iostream>
using namespace std;

//PastryCategory structure
struct PastryCategory{
    string name;
    int numAwards;
};

//Chef structure
struct Chef{
    string name;
    string hometown;
    int numCategories;
};

int main(){
    //variable declarations
    int numChefs = 0;
    string winChef;
    int mostAwards = 0;

    //ask how many chefs are competing and read into an int variable
    cout << "How many chefs are competing? ";
    cin >> numChefs;

    //dynamically allocate an array of Chef elements based on number of chefs read in
    Chef *chefArray;
    chefArray = new Chef[numChefs];

    //dynamically allocate array of pointers-to-PastryCategory based on number of chefs read in
    PastryCategory ** awardsArray;
    awardsArray = new PastryCategory*[numChefs];

    PastryCategory * catArray;

    cout << "\nPlease enter in information about each chef.\n\n";

    for (int i = 0; i < numChefs; i++){

        //allow user to enter in information about each chef
        cout << "****CHEF " << i + 1 << "****\n";
        cout << "        NAME: ";
        cin >> chefArray[i].name;
        cout << "        HOMETOWN: ";
        cin >> chefArray[i].hometown;
        cout << "\n        How many categories has " << chefArray[i].name << " won awards in? ";
        cin >> chefArray[i].numCategories;

        //dynamically allocate array of PastryCategory based on number of categories entered
        catArray = new PastryCategory[chefArray[i].numCategories];

        //enter category name and number of awards for each category
        for (int j = 0; j < chefArray[i].numCategories; j++){
            cout << "     FOR CATEGORY " << j + 1 << ":\n";
            cout << "             Name of category - ";
            cin >> catArray[j].name;
            cout << "             Number of awards in " << catArray[j].name << " - ";
            cin >> catArray[j].numAwards;
            awardsArray[i].numAwards +=catArray[j].numAwards;
            
            //Calculate and print out the most awards earned by a chef
            if (catArray[j].numAwards > mostAwards){
                mostAwards = catArray[j].numAwards;
                winChef = chefArray[i].name;
            }
        }
    }


    for (int i = 0; i < numChefs; i++){
        for (int j; j < chefArray[i].numCategories; j++){
            
        }
    }

    cout << "The pastry chef who has won the most awards (" << mostAwards << " awards) is " << winChef << ", with awards in the following categories:\n";

    

    delete [] chefArray;
    delete [] awardsArray;
    delete [] catArray;
}