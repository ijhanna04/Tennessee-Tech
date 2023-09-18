/*
    Title:      Program1.cpp
    Author:     Ian Hanna
    Class:      CSC 1310-001
    Date        September 18, 2023
    Purpose:    Video Game Library
*/

#include <iostream>
#include <fstream>

using namespace std;

// include necessary header files
#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

int main(){
    int numGamesHeld;
    int menuChoice;
    string file;
    ifstream infile;


    // ask the user for the number of games the video game library can hold
    cout << "How many video games can your library hold?\n";
    cin >> numGamesHeld;
    while(numGamesHeld < 0){
        cout << "\nInvalid menu choice. Enter a number greater than 0\n";
        cin >> numGamesHeld;
    }

    // dynamically allocate a VideoGameLibrary object, sending the number as an argument
    videoGameLibrary* myLibrary = new videoGameLibrary(numGamesHeld);

    do{
        // display a menu of six choices
        cout << "\n\nWhat would you like to do?\n";
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
                cin >> file;

                // call loadVideoGamesFromFile, sending the filename as a string
                myLibrary->loadVideoGamesFromFile(file);
                break;
            case 2:
                // ask the name of the file
                cout << "\nWhat do you want to name the file? (example.txt): ";
                cin >> file;

                // call the saveToFile function, sending the filename as a string
                myLibrary->saveToFile(file);
                cout << "\nAll video games in your library have been printed to " << file << endl;
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
                delete myLibrary;
        }
    }while (menuChoice != 6);

    cout << "\nGoodbye!\n";

    infile.close();

    return 0;
}