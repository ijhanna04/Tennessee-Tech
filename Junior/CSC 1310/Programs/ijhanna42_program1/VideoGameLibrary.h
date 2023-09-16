#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include <iostream>
#include "VideoGame.h"

using namespace std;

class videoGameLibrary{
    int **videoGamesArray;
    int maxGames;
    int numGames;   
public:
    videoGameLibrary(int maxGames){
        this->maxGames = maxGames;
        this->numGames = 0;
        this->videoGamesArray = new int*[maxGames];
        
    }
    ~videoGameLibrary(){
        for(int i = 0; i < this->maxGames; i++){
            delete[] this->videoGamesArray[i];
        }
        delete[] this->videoGamesArray;
        cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.\n";
    }
    void resizeVideoGameArray();
        VideoGame** new_array = new VideoGame*[this->maxGames * 2];
        for (int i = 0; i < this->numGames; i++){
            new_array[i] = this->videoGamesArray[i];
        }
        delete[] this->videoGamesArray;
        this->videoGamesArray = new_array;  
    void addVideoGameToArray();
    void displayVideoGames();
    void displayVideoGameTitles();
    void loadVideoGamesFromFile(/*pointer to a character (c-string or literal argument) containing the filename*/);
    void removeVideoGameFromArray();
    void saveToFile();
};



#endif