#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>

using namespace std;

class videoGameLibrary{
    int **videoGamesArray;
    int maxGames;
    int numGames;
    public:
        videoGameLibrary(int);
        ~videoGameLibrary();
        void resizeVideoGameArray();  
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(/*pointer to a character (c-string or literal argument) containing the filename*/);
        void removeVideoGameFromArray();
        void saveToFile();
};



#endif