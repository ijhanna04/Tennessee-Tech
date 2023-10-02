/*
    Title:      VideoGame.h
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Video Game Header File
*/

#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <fstream>

using namespace std;

// include necessary header files
#include "Text.h"

// videoGame class definition
class videoGame{
    public:
        videoGame(){    // default constructor for videoGame

        };
        videoGame(Text* titleVG, Text* developerVG, Text* publisherVG, int yearVG); // videoGame constructor
        ~videoGame();   // videoGame destructor
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream &filename);
        void getVideoGameTitle() const; // accessor function
    private:
        Text* title;
        Text* developer;
        Text* publisher;
        int year;
};

#endif