#include <iostream>
#include <fstream>
#include "VideoGameLibrary.h"
#include "VideoGame.h"

using namespace std;

videoGameLibrary::videoGameLibrary(int maxSize) : maxGames(10){
    maxGames = maxSize;
    numGames = 0;
        
    videoGamesArray = new VideoGame*[maxGames];
        
    for (int i = 0; i < maxGames; i++) {
            videoGamesArray[i] = nullptr;
    }
}
    
videoGameLibrary::~videoGameLibrary() {
    for (int i = 0; i < numGames; i++) {
        delete videoGamesArray[i];
    }
        
    delete[] videoGamesArray;
        
    std::cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself." << std::endl;
}
    
void resizeVideoGameArray() {
    maxGames *= 2;
        
    VideoGame** newArray = new VideoGame*[maxGames];
        
    for (int i = 0; i < numGames; i++) {
        newArray[i] = videoGamesArray[i];
    }
        
    delete[] videoGamesArray;
        
    videoGamesArray = newArray;
}
    
void addVideoGameToArray(const char* gameTitle, const char* gameDeveloper, const char* gamePublisher, int year) {
    if (numGames == maxGames) {
        resizeVideoGameArray();
    }
    
    videoGamesArray[numGames] = new VideoGame(gameTitle, gameDeveloper, gamePublisher, year);
        
    numGames++;
        
    std::cout << gameTitle << " was added successfully." << std::endl;
}
    
void displayVideoGames() {
    for (int i = 0; i < numGames; i++) {
        videoGamesArray[i]->printVideoGameDetails();
        std::cout << std::endl;
    }
}
    
void displayVideoGameTitles() {
    for (int i = 0; i < numGames; i++) {
        videoGamesArray[i]->getVideoGameTitle();
        std::cout << std::endl;
    }
}

void loadVideoGamesFromFile(char* filename) {
    ifstream file(filename);
    if (file.is_open()) {
        while (!file.eof()) {
            char* title = new char[10000];
            file.getline(title, 10000, ',');
            Text* gameTitle = new Text(title);
            char* developer = new char[10000];
            file.getline(developer, 10000, ',');
            Text* gameDeveloper = new Text(developer);
            int year;
            file >> year;
            file.ignore(1, '\n');
            VideoGame* game = new VideoGame(gameTitle, gameDeveloper, year);
            if (numGames == maxGames) {
                resizeVideoGameArray();
            }
            videoGamesArray[numGames] = game;
            numGames++;
            cout << *gameTitle << " was added successfully." << endl;
        }
        cout << numGames << " video games were read from the file & added to the library." << endl;
        file.close();
    }
}

void removeVideoGameFromArray() {
    if (numGames < 1) {
        cout << "There must always be at least one video game in the library." << endl;
        return;
    }
    displayVideoGameTitles();
    cout << "Choose a video game to remove between 1 and " << numGames << ": ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > numGames) {
        cout << "Invalid choice. Please try again." << endl;
        return;
    }
    cout << videoGamesArray[choice - 1]->getTitle() << " has been successfully deleted." << endl;
    delete videoGamesArray[choice - 1];
    for (int i = choice - 1; i < numGames - 1; ++i) {
        videoGamesArray[i] = videoGamesArray[i + 1];
    }
    --numGames;
}

void saveToFile(char* filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < numGames; ++i) {
            videoGamesArray[i]->printVideoGameDetailsToFile(file);
        }
        file.close();
        cout << "All video games have been printed to " << filename << "." << endl;
    }
}
