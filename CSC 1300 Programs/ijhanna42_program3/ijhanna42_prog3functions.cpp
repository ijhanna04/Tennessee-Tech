/*
    Title:      ijhanna42_prog3functions.cpp
    Author:     Ian Hanna
    Date        April 5, 2023
    Purpose:    Candylife Game
*/

#include "ijhanna42_prog3.h"

//function to get player names
void getPlayerNames(string namesgPN[], int numPlayersgPN){
    //get each player's name
    cin.ignore();
    for (int j = 0; j < numPlayersgPN; j++){
        cout << "\nPLAYER " << j + 1 << ", WHAT IS YOUR NAME?";
        cout << "\nNAME: ";
        
        //place player names in each element of the names array
        string name;
        getline(cin, name);
        namesgPN[j] = name;
    }
}

//function for a player's dice roll during their turn
int rollDice(string playerNamerD){
    int diceNumberrD;

    //print out the player's name and tell them to roll the dice
    cout << "----------\n";
    cout << playerNamerD << ", PRESS ENTER TO ROLL DIE." << endl;
    cin.get();

    //randomly generate a number between 1 and 6
    srand(time(0));
    diceNumberrD = rand() % 6 + 1;

    //tell user what number they rolled
    cout << "YOU ROLLED A " << diceNumberrD << ".\n";

    //print out picture of the dice that was rolled
    switch(diceNumberrD)
    {
	case 1:
		cout << " _________\n";
		cout << "|         |\n";
		cout << "|    o    |\n";
		cout << "|         |\n";
		cout << "|_________|\n\n";
		break;
	case 2:
		cout << " _________\n";
		cout << "|         |\n";
		cout << "|  o      |\n";
		cout << "|      o  |\n";
		cout << "|_________|\n\n";
		break;
	case 3:
		cout << " _________\n";
		cout << "| o       |\n";
		cout << "|    o    |\n";
		cout << "|       o |\n";
		cout << "|_________|\n\n";
		break;
	case 4:
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "|         |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		break;
	case 5:
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "|    o    |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		break;
	case 6:
		cout << " _________\n";
		cout << "| o     o |\n";
		cout << "| o     o |\n";
		cout << "| o     o |\n";
		cout << "|_________|\n\n";
		break;
    }

    return diceNumberrD;
}  

//end of game stats for when a player reaches the end of the board
void playerFinishedBoard(string namespFB[], int boardSpacepFB[], double moneypFB[], int numPlayerspFB){

    //variables for highest board space reached
    int maxBoard = -100;
    string boardSpaceHighest;

    //variables for most money gained
    double maxMoney = -1000000;
    string moneyHighest;

    cout << "YOU FINISHED THE BURGERLAND BOARD!!\n";
    cout << "----------\n\n";

    //iterate through the boardSpace array and find the player who reached the highest board space
    for (int k = 0; k < boardSpacepFB[numPlayerspFB]; k++){

        //save the name of the player with the highest board space
        
        for (int i = 0; i < numPlayerspFB; i++){
            if(boardSpacepFB[i] > maxBoard){
                maxBoard = boardSpacepFB[i];
                boardSpaceHighest = namespFB[i];
            }
        }
    }

    //print out the name of the player  with the highest board space
    cout << "PLAYER WHO SURVIVED ENTIRE " << gameName << " BOARD: " << boardSpaceHighest << endl;

    //iterate through the money array to fund the player who had the most money at the end of the game
    for (int l = 0; l < moneypFB[numPlayerspFB]; l++){

        //save the name of the player with the most money
        
        for (int i = 0; i < numPlayerspFB; i++){
            if(moneypFB[i] > maxMoney){
                maxMoney = moneypFB[i];
                moneyHighest = namespFB[i];
            }
        }
    }

    //print out the name of the player with the most money
    cout << "PLAYER WHO HAS THE MOST " << gameName << " MONEY: " << moneyHighest << " has $" << fixed << setprecision(2) << maxMoney << endl << endl;
}

void activateActionOnSpace(string namesaAOS[], int boardSpaceaAOS[], double moneyaAOS[], int numPlayersaAOS, int index){

    //variable for line read from txt file chosen
    string lineOfData;

    //print out current board space
    cout << namesaAOS[index] << " IS NOW ON SPACE " << boardSpaceaAOS[index] << endl;
    //finish

    //generate a random number either 1 or 2
    srand(time(0));
    int goodbad = rand() % 2 + 1;

    //file input variable
    ifstream infile;

    switch(goodbad){

        //if 1, good action occurs
        case 1:
            //open goodactions.txt file
            infile.open("goodactions.txt");
            //print out smiley face
            cout << "   *           *   \n";
            cout << "         |         \n";
            cout << "\\                /\n";
            cout << " \\______________/ \n";
            //print out "GREAT!"
            cout << "GREAT! ";
            break;

        //if 2, bad action occurs
        case 2:
            //open badactions.txt file
            infile.open("badactions.txt");
            //print out sad face
            cout << "   -           -   \n";
            cout << "   '     |         \n";
            cout << "   _____________   \n";
            cout << "  /             \\ \n";
            //print out word "OH NO!"
            cout << "OH NO! ";
            break;
    }
    
    //randomly generate a number between 1 & 20
    int lineChoice = rand() % 20 + 1;

    //for loop that iterates the number of times that was randomly generated
    for (int i = 0; i < lineChoice; ++i){
        //read a line from the file using getline
        if(infile.is_open()){
            getline(infile, lineOfData);
            
        }
    }

    //print out the line from the file and close the file
    cout << lineOfData;
    infile.close();
    
    //randomly generate a number between 1 & 100000
    double moneyChange = rand() % 100000 + 1; 
    switch(goodbad){
        //if a good action occured, add generated amount of money to player money
        case 1:
            moneyaAOS[index] = moneyaAOS[index] + moneyChange;
            cout << "\nADDED $" << fixed << setprecision(2) << moneyChange << " TO YOUR ACCOUNT";
            break;
        //if a bad action occured, subtract generated amount of money from player money
        case 2:
            moneyaAOS[index] = moneyaAOS[index] - moneyChange;
            cout << "\nSUBTRACTED $" << fixed << setprecision(2) << moneyChange << " FROM YOUR ACCOUNT";
            break;
    }

    //print out how much money the player now has
    cout << "\nYOU NOW HAVE $" << fixed << setprecision(2) << moneyaAOS[index] << " IN YOUR ACCOUNT.\n";
    cout << "----------\n\n";
}
