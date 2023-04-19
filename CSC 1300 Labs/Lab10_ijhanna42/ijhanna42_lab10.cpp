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
    int winCategories = 0;
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

    cout << "\nPlease enter in information about each chef.\n\n";
    int i;
    int j;

    for (i = 0; i < numChefs; i++){

        //allow user to enter in information about each chef
        cout << "****CHEF " << i + 1 << "****\n";
        cout << "        NAME: ";
        cin >> chefArray[i].name;
        cout << "        HOMETOWN: ";
        cin >> chefArray[i].hometown;
        cout << "\n        How many categories has " << chefArray[i].name << " won awards in? ";
        cin >> chefArray[i].numCategories;

        //dynamically allocate array of PastryCategory based on number of categories entered
        awardsArray[i] = new PastryCategory[chefArray[i].numCategories];

        //enter category name and number of awards for each category
        for (j = 0; j < chefArray[i].numCategories; j++){
            cout << "      FOR CATEGORY " << j + 1 << ":\n";
            cout << "            Name of category - ";
            cin >> awardsArray[i][j].name;
            cout << "            Number of awards in " << awardsArray[i][j].name << " - ";
            int addAwards = 0;
            cin >> awardsArray[i][j].numAwards;
            awardsArray[i][j].numAwards += awardsArray[i][j-1].numAwards;
            
            //Calculate the most awards earned by a chef
            if (awardsArray[i][j].numAwards > mostAwards){
                mostAwards = awardsArray[i][j].numAwards;
                winChef = chefArray[i].name;
                winCategories = chefArray[i].numCategories;
                for (int m = 0; m < winCategories; m++){

                }
            }
        }
    }

    //print out the winner
    cout << "\n\nThe pastry chef who has won the most awards (" << mostAwards << " awards) is " << winChef << ", with awards in the following categories:\n";
    for(int l = 0; l < winCategories; l++){
        cout << awardsArray[i][j].name << endl;
    }
    
    for(int k = 0; k < numChefs ; k++){
        delete [] awardsArray[i];
    }
    delete [] awardsArray;
    delete [] chefArray;

    
}