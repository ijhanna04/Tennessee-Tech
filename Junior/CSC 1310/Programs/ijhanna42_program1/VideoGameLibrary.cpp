#include <iostream>
#include "VideoGameLibrary.h"
#include "VideoGame.h"

using namespace std;

void resizeVideoGameArray(){
    VideoGame** new_array = new VideoGame*[this->maxGames * 2];
    for (int i = 0; i < this->numGames; i++){
        new_array[i] = this->videoGamesArray[i];
    }
    delete[] this->videoGamesArray;
    this->videoGamesArray = new_array;
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