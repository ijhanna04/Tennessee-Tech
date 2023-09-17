#include <iostream>
#include <fstream>
using namespace std;

#include "VideoGameLibrary.h"

void videoGameLibrary::resizeVideoGameArray(){
    cout << "\nResizing VideoGameArray from " << maxGames << " to " << maxGames*2 << endl;
    maxGames *=2;

    videoGame**tempArray = new videoGame*[maxGames];

    for(int i = 0; i < numGames; i++){
        tempArray[i] = videoGamesArray[i];
    }
}

videoGameLibrary::videoGameLibrary(){
    videoGamesArray = new videoGame*[maxGames];
    numGames = 0;
}

videoGameLibrary::~videoGameLibrary(){
    for(int i = 0; i < numGames; i++){
        delete videoGamesArray[i];
    }
    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.";
}

void videoGameLibrary::addVideoGameToArray(){
    char title[10000];
    char developer[10000];
    char publisher[10000];
    int releaseYear;

    cout << "\n\nVideo Game TITLE: ";
    cin.getline(title, 10000);
    Text* titleText = new Text(title);

    cout << "\n\nVideo Game DEVELOPER: ";
    cin.getline(developer, 10000);
    Text* developerText = new Text(developer);

    cout << "\n\nVideo Game PUBLISHER: ";
    cin.getline(publisher, 10000);
    Text* publisherText = new Text(publisher);

    cout << "\n\nVideo Game YEAR: ";
    cin >> releaseYear;

    videoGame* game = new videoGame(titleText, developerText, publisherText, releaseYear);

    if (numGames == maxGames){
        resizeVideoGameArray();
    }

    videoGamesArray[numGames] = game;

    numGames++;
}

void videoGameLibrary::displayVideoGames(){
    for(int i = 0; i < numGames; i++){
        videoGamesArray[i]->videoGame::printVideoGameDetails();
    }
}

void videoGameLibrary::displayVideoGameTitles(){
    for(int i = 0; i < numGames; i++){
        cout << videoGamesArray[i]->getVideoGameTitle();
    }
}

void videoGameLibrary::loadVideoGamesFromFile(char* filename){
    string filename;
    cout << "\nWhat is the name of the file? (example.txt): ";
    cin >> filename;

    ifstream file(filename);
    if(file.is_open()){
        while(!file.eof()){
            char* title = new char[10000];
            file.getline(title, 10000);
            Text* gameTitle = new Text(title);

            char* developer = new char[10000];
            file.getline(developer, 10000);
            Text* gameDeveloper = new Text(developer);

            char* publisher = new char[10000];
            file.getline(publisher, 10000);
            Text* gamePublisher = new Text(publisher);

            int yearReleased;
            file >> yearReleased;

            videoGame* gameLoad = new videoGame(gameTitle, gameDeveloper, gamePublisher, yearReleased);

            if(numGames == maxGames){
                videoGameLibrary::resizeVideoGameArray();
            }

            videoGamesArray[numGames] = gameLoad;

            numGames++;

            cout << gameTitle << " was added successfully\n";
        }
        cout << numGames << " were read from the file and added to your VideoGame library.";
        file.close();
    } else {
        cout << "Sorry, I was unable to open the file.\n\n";
    }
    
}   

void videoGameLibrary::removeVideoGameFromArray(){
    if(numGames < 1){
        cout << "There must always be one video game in the library.";
        return;
    }

    cout << "Choose from the following video games to remove:\n\n";
    videoGameLibrary::displayVideoGameTitles();
    cout << "Choose a video game to remove between 1 & " << numGames << ":";

    int choice;
    cin >> choice;
    if(choice < 1 || choice > numGames){
        cout << "Invalid choice. Enter a number between 1 and " << numGames << ":";
        cin >> choice;
    }

    cout << videoGamesArray[choice - 1]->videoGame::getVideoGameTitle() << " has been successfully deleted.\n\n";

    //text destruction
    //fixme below
    cout << "Text destructor: Released memory for textArray\n";
    delete videoGamesArray[choice - 1];
    cout << "VideoGame destructor: Released memory for VideoGame object";

    for(int i = choice - 1; i < numGames; i++){
        videoGamesArray[i] = videoGamesArray[i - 1];
    }

    numGames--;
}

void videoGameLibrary::saveToFile(char* filename){
    ofstream file(filename);
    if (file.is_open()){
        for(int i = 0; i < numGames; i++){
            videoGamesArray[i]->videoGame::printVideoGameDetailsToFile(file);
        }
        file.close();
        cout << "All video games in your library have been printed to " << filename << endl << endl;
    }
}