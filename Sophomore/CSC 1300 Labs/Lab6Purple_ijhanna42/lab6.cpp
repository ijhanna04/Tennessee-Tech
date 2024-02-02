/*
    Title:      lab6.cpp
    Author:     Ian Hanna
    Date        February 2023
    Purpose:    Input/Output Files, Functions
*/

#include <iostream>
#include <fstream>
using namespace std;

//prototypes for functions
int displayMenuChoice();
void printToFile();

//main function
int main()
{
    //variable declarations
    int monsterAge;
    double monsterHeight;
    double monsterWeight;
    string monsterName, monsterFood, monsterFact;
    string value1;
    int value2;
    double value3;
    double value4;
    string value5;
    string value6;
    ifstream inFile;

    //menu choices
    int menuChoice = displayMenuChoice();
    do{
        switch(menuChoice){
            case 1:
                cout << "Monster Name: ";
                cin >> monsterName;
                cout << monsterName << "'s age (years): ";
                cin >> monsterAge;
                cout << monsterName << "'s height (feet): ";
                cin >> monsterHeight;
                cout << monsterName << "'s weight (pounds): ";
                cin >> monsterWeight;
                cout << "Food that " << monsterName << " prefers: ";
                cin >> monsterFood;
                cout << "Fun fact about " << monsterName << ": ";
                cin >> monsterFact;
                break;
            case 2:
                inFile.open("monsterData.txt");

                if(inFile.is_open())
                {
                    inFile >> value1;
                    inFile >> value2;
                    inFile >> value3;
                    inFile >> value4;
                    inFile >> value5;
                    inFile >> value6;
                    inFile.close();
                    cout << monsterName << " has been read from the file" << endl;;
                    break;
                }
                else{
                    cout << "The monsterData.txt file does not exist." << endl;
                    break;
                }   
            case 3:
                cout << "MONSTER NAME: " << right << monsterName << endl;
                cout << "AGE (YEARS): " << right << monsterAge << endl;
                cout << "HEIGHT (FEET): " << right << monsterHeight << endl;
                cout << "WEIGHT (POUNDS): " << right << monsterWeight << endl;
                cout << "FOOD IT EATS: " << right << monsterFood << endl;
                cout << "FUN FACT: " << monsterFact << endl;
                break;
            case 4:
                break;
        }
    } while (menuChoice != 4);


    cout << "GOODBYE!";

    return 0;
}

/*
displayMenuChoice function:
1. Print a menu of choices, 
2. Read in the user's choice, 
3. Validate the user's choice, 
4. Return the user's choice
*/
int displayMenuChoice()
{
    int menuChoice;
    cout << "1. Enter a Monster's Data from Screen" << endl;
    cout << "2. Read a Monster's Data from File" << endl;
    cout << "3. Print the Monster's Data to screen" << endl;
    cout << "4. Save & Quit Program" << endl;
    cout << "CHOOSE 1-4: ";
    cin >> menuChoice;
        while ((menuChoice < 1) || (menuChoice > 4)){
            cout << "Invalid Input. Enter a Number between 1 and 4: ";
            cin >> menuChoice;
        }
    return menuChoice;
}

/*
printToFile function:
1. Accept size arguments containing monster data
2. Open an output file
3. Print the monster data to the file
4. Close the file
5. Print confirmation that the arguments were saved to the document
*/
void printToFile(string monsterName, int monsterAge, double monsterHeight, double monsterWeight, string monsterFood, string monsterFact)
{
    ofstream outputFile;
    outputFile.open("monsterData.txt");
    outputFile << monsterName << endl;
    outputFile << monsterAge << endl;
    outputFile << monsterHeight << endl;
    outputFile << monsterWeight << endl;
    outputFile << monsterFood << endl;
    outputFile << monsterFact << endl;
    outputFile.close();
    cout << monsterName << " has been saved to monsterData.txt" << endl;
}