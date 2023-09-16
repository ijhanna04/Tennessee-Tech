#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
#include <fstream>
#include "VideoGame.h"

using namespace std;

class videoGameLibrary{
    public:
        videoGameLibrary(int);
        ~videoGameLibrary();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char*);
        void removeVideoGameFromArray();
        void saveToFile();   
    private:
        int **videoGamesArray;
        int maxGames;
        int numGames;
};


#endif