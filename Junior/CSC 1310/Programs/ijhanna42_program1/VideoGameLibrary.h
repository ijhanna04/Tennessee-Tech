/*
    Title:      VideoGameLibrary.h
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Video Game Library Header File
*/

#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
using namespace std;

// include necessary header files
#include "VideoGame.h"
#include "Text.h"

// videoGameLibrary class definition
class videoGameLibrary{
    public:
        void resizeVideoGameArray();
        videoGameLibrary(int);  // videoGame constructor
        ~videoGameLibrary();    // videoGame destructor
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(string);
        void removeVideoGameFromArray();
        void saveToFile(string);
    private:
        videoGame** videoGamesArray;
        int maxGames;
        int numGames;
};

#endif