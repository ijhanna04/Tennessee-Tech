#include <iostream>
#include "VideoGameLibrary.h"
#include "VideoGame.h"

using namespace std;

void resizeVideoGameArray(){
    VideoGame** new_array = new VideoGame*[this->maxGames * 2];
    for (int i = 0; i < this->numGames; i++){
        new_array[i] = this->videoGamesArray[i];
    }
}

//VideoGameLibrary constructor

//~VideoGameLibrary destructor
videoGameLibrary(maxGames){
        this->videoGamesArray = new VideoGame*[maxGames];
        this->maxGames = maxGames;
        this->numGames = 0;
    }

~videoGameLibrary(){
    for (int i = 0; i < this->numGames; i++){
        delete this->videoGamesArray[i];
    }
    delete[] this->videoGamesArray;
    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.\n";
}

void addVideoGamesToArray(){
    char title[100];
    cout << "Video Game TITLE: ";
    cin.getline(title, 100);
    char developer[100];
    cout << "Video Game DEVELOPER: ";
    cin.getline(developer, 100);
    char publisher[100];
    cout << "Video Game PUBLISHER: ";
    cin.getline(publisher, 100);
    cout << "Video Game YEAR: ";
    cin >> ;
}

void displayVideoGames(){
    
}

void displayVideoGameTitles(){

}

//loadVideoGamesFromFile()

void removeVideoGameFromArray(){
    cout << "Choose from the following ideo games to remove\n\n";

}

//saveToFile()