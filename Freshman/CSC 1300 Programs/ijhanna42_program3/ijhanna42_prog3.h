/*
    Title:      ijhanna42_prog3.h
    Author:     Ian Hanna
    Date        April 5, 2023
    Purpose:    Candylife Game
*/

#ifndef IJHANNA42_PROG3_H
#define IJHANNA42_PROG3_H

//include libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

//constant variable definitions
const int maxPlayers = 20;
const int numSpaces = 25;
const string gameName = "BURGERLAND";

//function prototypes
void getPlayerNames(string[], int);
int rollDice(string);
void playerFinishedBoard(string[], int[], double[], int);
void activateActionOnSpace(string[], int[], double[], int, int);


#endif