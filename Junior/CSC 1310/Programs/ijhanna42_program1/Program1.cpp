/*
    Title:      Program1.cpp
    Author:     Ian Hanna
    Class:      CSC 1310-001
    Date        September 18, 2023
    Purpose:    Video Game Library
*/

#include <iostream>

using namespace std;

// include necessary header files
#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

int main(){
    int numGamesHeld = 0;
    int menuChoice = 0;
    string fileToLoad;
    string fileToSave;

    // ask the user for the number of games the video game library can hold
    cout << "How many video games can your library hold?\n";
    cin >> numGamesHeld;

    // dynamically allocate a VideoGameLibrary object, sending the number as an argument
    videoGameLibrary* myLibrary = new videoGameLibrary(numGamesHeld);

    do{
        // display a menu of six choices
        cout << "What would you like to do?\n";
        cout << "1. Load video games from file.\n";
        cout << "2. Save video games to a file.\n";
        cout << "3. Add a video game.\n";
        cout << "4. Remove a video game.\n";
        cout << "5. Display all video games.\n";
        cout << "6. Remove ALL video games from list library and end program.\n";
        cout << "CHOOSE 1-6: ";
        cin >> menuChoice;

        // input check
        if(menuChoice < 1 || menuChoice > 6){
            cout << "Invalid menu choice. Choose a number between 1 and 6: ";
            cin >> menuChoice;
        }

        switch (menuChoice){
            case 1:
                // ask the name of the file
                cout << "\nWhat is the name of the file? (example.txt): ";
                cin >> fileToLoad;

                // call loadVideoGamesFromFile, sending the filename as a string
                myLibrary->loadVideoGamesFromFile(&fileToLoad);
                break;
            case 2:
                // ask the name of the file and call the saveToFile function, sending the filename as a string
                myLibrary->saveToFile(&fileToSave);
                break;
            case 3:
                // call the addVideoGameToArray function
                myLibrary->addVideoGameToArray();
                break;
            case 4:
                // call the removeVideoGameFromArray function
                myLibrary->removeVideoGameFromArray();
                break;
            case 5:
                // call the displayVideoGames function
                myLibrary->displayVideoGames();
                break;
            case 6:
                // release the VideoGameLibrary object and end the program
                myLibrary->~videoGameLibrary();
                return 0;
        }
    }while (menuChoice != 6);

    return 0;
}