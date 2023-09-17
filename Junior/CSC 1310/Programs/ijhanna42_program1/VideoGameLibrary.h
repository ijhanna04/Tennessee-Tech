#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
using namespace std;

#include "VideoGame.h"
#include "Text.h"

class videoGameLibrary{
    public:
        void resizeVideoGameArray();
        videoGameLibrary();
        ~videoGameLibrary();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char* filename);
        void removeVideoGameFromArray();
        void saveToFile(char* filename);
    private:
        videoGame** videoGamesArray;
        int maxGames;
        int numGames;
};

#endif