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

#include "VideoGame.h"
#include "Text.h"

class videoGameLibrary{
    public:

        void resizeVideoGameArray();
        videoGameLibrary(int gamesInput);
        ~videoGameLibrary();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(string* filename);
        void removeVideoGameFromArray();
        void saveToFile(string* filename);
    private:
        videoGame** videoGamesArray;
        int maxGames;
        int numGames;
};

#endif