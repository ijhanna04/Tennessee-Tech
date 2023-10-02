/*
    Title:      VideoGameLibrary.cpp
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Video Game Library Functions
*/

#include <iostream>
#include <fstream>

using namespace std;

// include necessary header files
#include "VideoGameLibrary.h"
#include "VideoGame.h"
#include "Text.h"

// resizeVideoGameArray function
void videoGameLibrary::resizeVideoGameArray(){

    cout << "\nResizing VideoGameArray from " << maxGames << " to " << maxGames*2 << endl;

    // make the array twice as big as it currently is
    videoGame**tempArray = new videoGame*[maxGames*2];

    // move all the videoGame pointers to the new array
    for(int i = 0; i < maxGames; i++){
        tempArray[i] = videoGamesArray[i];
    }

    delete[] videoGamesArray;
    videoGamesArray = tempArray;
    cout << "Array has been resized from " << maxGames << " to " << maxGames*2 << endl;
    maxGames = maxGames*2;
}

// videoGameLibrary constructor
videoGameLibrary::videoGameLibrary(int gamesInput){

    // dynamically allocate an array of pointers to VideoGame objects based on the maximum size
    this->maxGames = gamesInput;
    videoGamesArray = new videoGame*[maxGames];

    // set current number of games to 0
    this->numGames = 0;
}

// videoGameLibrary destructor
videoGameLibrary::~videoGameLibrary(){

    // release the dynamically created individual video games, then delete the array
    for(int i = 0; i < numGames; i++){
        delete videoGamesArray[i];
    }
    delete [] videoGamesArray;

    // print a message that the memory has been released
    cout << "VideoGameLibrary destructor: Released memory for each game in the video game array and the array itself.";
}

// addVideoGameToArray function
void videoGameLibrary::addVideoGameToArray(){

    char temp[10000];
    Text *newTitle, *newDeveloper, *newPublisher;
    int newYear;

    cin.ignore();

    // ask the user for the video game title
    cout << "\nVideo Game TITLE: ";
    //read input as a c-string
    cin.getline(temp, 10000);
    //dynamically create a Text object
    newTitle = new Text(temp);

    // ask the user for the video game developer
    cout << "\nVideo Game DEVELOPER: ";
    //read input as a c-string
    cin.getline(temp, 10000);
    //dynamically create a Text object
    newDeveloper = new Text(temp);

    // ask the user for the video game publisher
    cout << "\nVideo Game PUBLISHER: ";
    //read input as a c-string
    cin.getline(temp, 10000);
    //dynamically create a Text object
    newPublisher = new Text(temp);

    //fixme
    // ask user for video game release year
    cout << "\nVideo Game YEAR: ";
    // read input as an integer
    cin >> newYear;
    cin.ignore();

    // send the given data as arguments to the VideoGame constructor
    videoGame* newGame = new videoGame(newTitle, newDeveloper, newPublisher, newYear);

    // check if numGames is equal to maxGames
    if (numGames == maxGames){
        // if equal, call the resizeVideoGameArray function
        resizeVideoGameArray();
    }

    // assign the new video game to the correct pointer in the videoGamesArray
    videoGamesArray[numGames] = newGame;

    // increment numGames
    numGames++;
}

// displayVideoGames function
void videoGameLibrary::displayVideoGames(){

    // loop through the videoGamesArray
    for(int i = 0; i < numGames; i++){
        // call each video game's printVideoGameDetails function
        cout << "               ---------- Video Game " << i+1 << " ----------\n";
        videoGamesArray[i]->videoGame::printVideoGameDetails();
    }
}

// displayVideoGameTitles function
void videoGameLibrary::displayVideoGameTitles(){

    // loop through the videoGamesArray
    for(int i = 0; i < numGames; i++){

        cout << i+1 << ": ";
        // retrieve the video game's title by calling the video game's getVideoGameTitle function
        videoGamesArray[i]->getVideoGameTitle();

        // print out the title
        cout << endl;
    }
}

// loadVideoGamesFromFile function
void videoGameLibrary::loadVideoGamesFromFile(string filename){

    Text *gameTitle, *gameDeveloper, *gamePublisher;
    int yearReleased;
    char temp[10000];
    int numGamesAdded;
    ifstream infile;

    infile.open(filename.c_str());

    if(infile.good()) {

        // use a loop to read the contents of the file until reaching the end of file
        while(!infile.eof()){

            // read in the title with a c-string
            infile.getline(temp, 10000);
            // dynamically allocate a Text to hold the title
            gameTitle = new Text(temp);

            // read in the developer with a c-string
            infile.getline(temp, 10000);
            // dynamically allocate a Text to hold the developer
            gameDeveloper = new Text(temp);

            // read in the publisher with a c-string
            infile.getline(temp, 10000);
            // dynamically allocate a Text to hold the publisher
            gamePublisher = new Text(temp);

            //read in the year released
            infile >> yearReleased;
            infile.ignore();

            // dynamically allocate a new videoGame object, sending the data from the file as arguments to the videoGame constructor
            videoGame* gameLoad = new videoGame(gameTitle, gameDeveloper, gamePublisher, yearReleased);

            // check to see if numGames is equal to maxGames
            if(numGames == maxGames){
                // if qual, call the resizeVideoGameArray function
                videoGameLibrary::resizeVideoGameArray();
            }

            // assign the new video game to te correct pointer in the videoGamesArray
            videoGamesArray[numGames] = gameLoad;

            // increment numGames
            numGames++;
            numGamesAdded++;

            // print that the new video game has been added successfully
            gameTitle->displayText();
            cout << " was added successfully\n";
        }
    }else {
        cout << "\nSorry, I was unable to open the file.\n\n";
    }

        infile.close();

        // print out how many video games were read from the file and added th the library
        cout << numGamesAdded << " were read from the file and added to your VideoGame library.";
}   

// removeVideoGameFromArray function
void videoGameLibrary::removeVideoGameFromArray(){

    int choice;
    Text* removeTitle, *removeDeveloper, *removePublisher;
    int removeYear;

    // if numGames is not at least one, print that there should always be one game in the library and end the function
    if(numGames < 1){
        cout << "There must always be one video game in the library.";
        return;
    }

    // call the displayVideoGameTitles function to print all the video game titles
    cout << "Choose from the following video games to remove:\n\n";
    videoGameLibrary::displayVideoGameTitles();

    // ask the user to choose a video game to remove between 1 and numGames
    cout << "Choose a video game to remove between 1 & " << numGames << ":";
    cin >> choice;
    // input check
    if(choice < 1 || choice > numGames){
        cout << "Invalid choice. Enter a number between 1 and " << numGames << ":";
        cin >> choice;
    }

    // print that the video game title has been successfully deleted
    videoGamesArray[choice - 1]->getVideoGameTitle();
    cout << " has been successfully deleted.\n";

    // release the dynamically allocated space for the video game and move all array elements in the videoGamesArray back 1, starting with the deleted video game's element
    for(int i = choice - 1; i < numGames-1; ++i){
        videoGamesArray[i] = videoGamesArray[i + 1];
    }

    // decrement numGames
    numGames--;
}

// saveToFile function
void videoGameLibrary::saveToFile(string filename){

    ofstream file;

    file.open(filename.c_str());

    if (!file.is_open()){
        cout << "\nError opening file " << filename << endl;
    }

    // loop through the videoGamesArray
    for(int i = 0; i < numGames; i++){
        // call the printVideoGameDetailsToFile, sending the file stream object to be printed to
        videoGamesArray[i]->printVideoGameDetailsToFile(file);
    }

    // close the file
    file.close();

    // print a confirmation that all video games have been printed to the filename
    cout << "All video games in your library have been printed to " << filename << endl << endl;  
}