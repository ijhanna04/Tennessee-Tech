/*
    Title:      ijhanna42_prog4.cpp
    Author:     Ian Hanna
    Date        April 19, 2023
    Purpose:    Monster Zoo
*/

#include "ijhanna42_prog4.h"

int main(){

    //array of 75 elements of Monster data type
    Monsters monster[75];

    //int of current number of monsters in the zoo initialized to 0
    int currNumMonsters = 0;

    //choice variable declarations
    int menuChoice = 0;
    

    //welcome message with loadMonstersFromFile call
    cout << "WELCOME TO THE MONSTER ZOO PROGRAM!!\n";
    currNumMonsters = loadMonstersFromFile(currNumMonsters, monster);

    //menu options loop
    do{
        //menu options display
        cout << "\n\nWhat would you like to do?\n";
        cout << "   1. Register a New Monster\n";
        cout << "   2. Remove a Monster From Zoo\n";
        cout << "   3. Print Monsters to Screen\n";
        cout << "   4. Print Monster Care Cost Data\n";
        cout << "   5. End Program\n";
        cout << "   Enter 1, 2, 3, 4, or 5.\n";
        cout << "CHOICE: ";
        cin >> menuChoice;

        //menu options choices
        switch (menuChoice){
            case 1:
                currNumMonsters = registerMonster(currNumMonsters, monster);
                break;
            case 2:
                currNumMonsters = removeMonster(currNumMonsters, monster);
                break;
            case 3:
                printMonsters(currNumMonsters, monster);
                break;
            case 4:
                printCostInfo(currNumMonsters, monster);
                break;
            case 5:
                char saveChoice = ' ';
                //ask user if they wish to save monster data to a file
                cout << endl << "Would you like to save your monster list to a file? (y or n) ";
                cin >> saveChoice;

                //save options choices
                if ((saveChoice == 'y') || (saveChoice == 'Y')){
                    saveMonstersToFile(currNumMonsters, monster);
                    
                    break;
                }

                break;
        }
    }while (menuChoice != 5);

    return 0;
}