/*
    Title:      lab8.cpp
    Author:     Ian Hanna
    Date        March 2023
    Purpose:    Arrays and Functions
*/

//include the "Spells.h" file
#include "Spells.h"

//main function
int main(){

    //array definitions
    string spellNames[SIZE];
    int effectAmount[SIZE];

    //variable definitions
    double effectAverage;
    string lineOfDashes(60, '-');

    //introduction text block
    cout << "Welcome to the Hogwarts School of Witchcraft and Wizardry.\n";
    cout << "\nThis is the Hogwarts Spell Evaluation program.\n";
    cout << "\nPlease enter the spell(s) that you have learned.\n";

    //function call statements with pass by values
    getInfoFromUser(spellNames, effectAmount);
    effectAverage = calculateAverage(effectAmount);
    int lowest = findLowest(effectAmount);
    int highest = findHighest(effectAmount);
    string lowestName = findLowestName(effectAmount, spellNames);
    string highestName = findHighestName(effectAmount, spellNames);


    //results text block
    cout << lineOfDashes;
    cout << "\nThe average amount of effect of spells: " << effectAverage;
    cout << "\n\nThe spell with the lowest amount of effect is " << lowestName << " with value of " << lowest << ".\n"; //find name of lowest spell
    cout << "\nThe spell with the highest amount of effect is " << highestName << " with value of " << highest << ".\n"; //find name of highest spell

    return 0;
}