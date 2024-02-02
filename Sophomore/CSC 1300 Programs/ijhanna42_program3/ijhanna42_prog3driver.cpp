/*
    Title:      ijhanna42_prog3driver.cpp
    Author:     Ian Hanna
    Date        April 5, 2023
    Purpose:    Candylife Game
*/

#include "ijhanna42_prog3.h"

int main(){
    char menuChoice;    //holds Y or N input for if user wants to play again
    
do{
    //variable definitions
    int numPlayers = 0;
    int diceNumber = 0;
    bool finishedGame = false;
    
    //prints out name of game
    cout << "YOU ARE PLAYING " << gameName << "!\n";
    
    //get number of players from the user
    cout << "How many players? ";
    cin >> numPlayers;
    while ((numPlayers > maxPlayers) || (numPlayers < 1)){
        cout << "INVALID NUMBER OF PLAYERS. ENTER A NUMBER OF PLAYERS BETWEEN 1 and  " << maxPlayers << ": ";
        cin >> numPlayers;
    }

    //array definitions
    string names[numPlayers];
    int boardSpace[numPlayers];
    double money[numPlayers];

    //set each element of names array to empty string
    for (int i = 0; i < numPlayers; i++){
        names[i] = "";
    }

    //set each element of boardSpace array to zero
    for (int i = 0; i < numPlayers; i++){
        boardSpace[i] = 0;
    }

    //set each element of money array to 0.0
    for (int i = 0; i < numPlayers; i++){
        money[i] = 0.0;
    }
    
    //calls getPlayerNames() function
    getPlayerNames(names, numPlayers);

    //loop that iterates until one of the players has reached the last space on the board
    for (int i = 0; i < numSpaces; i++){

        //loop that iterates through each of the players for each turn
        for (int i = 0; i < numPlayers; i++){
            string playerName = names[i];

            //calls rollDice() function
            diceNumber = rollDice(playerName);

            //add the dice number to the position in the boardSpace array that corresponds to the current player
            boardSpace[i] = boardSpace[i] + diceNumber;

            //if a player has reached the end of the board, call the playerFinishedBoard() function
            if (boardSpace[i] >= numSpaces){
                playerFinishedBoard(names, boardSpace, money, numPlayers);
                finishedGame = true;
                break;  
                
            //if a player has not reached the end of the board, call the activateActionOnSpace() function
            } else {
                activateActionOnSpace(names, boardSpace, money, numPlayers, i);
            }
        }
        if (finishedGame){
            break;
        }
    }
    
    //ask the user if they want to play again
    cout << "DO YOU WANT TO PLAY AGAIN?\n";
    cout << "Y or N: ";
    cin >> menuChoice;
        while ((menuChoice != 'y') && (menuChoice != 'Y') && (menuChoice != 'n') && (menuChoice != 'N')){
            cout << "Invalid Input. Enter Y or N: ";
            cin >> menuChoice;
        }
        if ((menuChoice == 'n') || (menuChoice == 'N')){
            return 0;
        } else if ((menuChoice == 'y') || (menuChoice == 'Y')){
            cout << "\n\n";
            cin.ignore();
        }

}while (menuChoice == 'y' || menuChoice == 'Y');

    return 0;
}
