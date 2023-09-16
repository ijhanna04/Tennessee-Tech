/*
    Title:      Program1.cpp
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Video Game Library
*/

#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"
#include <iostream>

using namespace std;

int main(){
    int numGamesHeld = 0;
    int menuChoice = 0;

    cout << "How many video games can your library hold?\n";
    cin >> numGamesHeld;

    do{
        cout << "What would you like to do?\n";
        cout << "1. Load video games from file.\n";
        cout << "2. Save video games to a file.\n";
        cout << "3. Add a video game.\n";
        cout << "4. Remove a video game.\n";
        cout << "5. Display all video games.\n";
        cout << "6. Remove ALL video games from list library and end program.\n";
        cout << "CHOOSE 1-6: ";
        cin >> menuChoice;

        switch (menuChoice){
            case 1:
                loadVideoGamesFromFile();
                break;
            case 2:
                saveToFile();
                break;
            case 3:
                addVideoGameToArray();
                break;
            case 4:
                removeVideoGameFromArray();
                break;
            case 5:
                displayVideoGames();
                break;
            case 6:

                break;
        }
    }while (menuChoice != 6);

    return 0;
}