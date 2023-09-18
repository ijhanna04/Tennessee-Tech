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

// resizeVideoGameArray function
void videoGameLibrary::resizeVideoGameArray(){

    cout << "\nResizing VideoGameArray from " << maxGames << " to " << maxGames*2 << endl;

    // make the array twice as big as it currently is
    maxGames *=2;
    videoGame**tempArray = new videoGame*[maxGames];

    // move all the videoGame pointers to the new array
    for(int i = 0; i < numGames; i++){
        tempArray[i] = videoGamesArray[i];
    }
}

// videoGameLibrary constructor
videoGameLibrary::videoGameLibrary(int gamesInput){

    // dynamically allocate an array of pointers to VideoGame objects based on the maximum size
    maxGames = gamesInput;
    videoGamesArray = new videoGame*[maxGames];

    // set current number of games to 0
    numGames = 0;
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

    char title[10000];
    char developer[10000];
    char publisher[10000];
    int releaseYear;

    // ask the user for the video game title
    cout << "\n\nVideo Game TITLE: ";
    //read input as a c-string
    cin.getline(title, 10000);
    //dynamically create a Text object
    Text* titleText = new Text(title);

    // ask the user for the video game developer
    cout << "\n\nVideo Game DEVELOPER: ";
    //read input as a c-string
    cin.getline(developer, 10000);
    //dynamically create a Text object
    Text* developerText = new Text(developer);

    // ask the user for the video game publisher
    cout << "\n\nVideo Game PUBLISHER: ";
    //read input as a c-string
    cin.getline(publisher, 10000);
    //dynamically create a Text object
    Text* publisherText = new Text(publisher);

    // ask user for video game release year
    cout << "\n\nVideo Game YEAR: ";
    // read input as an integer
    cin >> releaseYear;

    // --send the given data as arguments to the VideoGame constructor
    videoGame* game = new videoGame(titleText, developerText, publisherText, releaseYear);

    // check if numGames is equal to maxGames
    if (numGames == maxGames){
        // if equal, call the resizeVideoGameArray function
        resizeVideoGameArray();
    }

    // assign the new video game to the correct pointer in the videoGamesArray
    videoGamesArray[numGames] = game;

    // increment numGames
    numGames++;
}

// displayVideoGames function
void videoGameLibrary::displayVideoGames(){

    // loop through the videoGamesArray
    for(int i = 0; i < numGames; i++){
        // call each video game's printVideoGameDetails function
        videoGamesArray[i]->videoGame::printVideoGameDetails();
    }
}

// displayVideoGameTitles function
void videoGameLibrary::displayVideoGameTitles(){

    // loop through the videoGamesArray
    for(int i = 0; i < numGames; i++){
        // retrieve the video game's title by calling the video game's getVideoGameTitle function
        Text* newTitle = videoGamesArray[i]->getVideoGameTitle();

        // --print out the title by calling the Text's displayText function
        newTitle.displayText();
    }
}

// loadVideoGamesFromFile function
void videoGameLibrary::loadVideoGamesFromFile(string* filename){
    
    ifstream file(*filename);

    if(file.is_open()){

        // use a loop to read the contents of the file until reaching the end of file
        while(!file.eof()){

            // read in the title with a c-string
            char* title = new char[10000];
            file.getline(title, 10000);
            // dynamically allocate a Text to hold the title
            Text* gameTitle = new Text(title);

            // read in the developer with a c-string
            char* developer = new char[10000];
            file.getline(developer, 10000);
            // dynamically allocate a Text to hold the developer
            Text* gameDeveloper = new Text(developer);

            // read in the publisher with a c-string
            char* publisher = new char[10000];
            file.getline(publisher, 10000);
            // dynamically allocate a Text to hold the publisher
            Text* gamePublisher = new Text(publisher);

            //read in the year released
            int yearReleased;
            file >> yearReleased;

            // dynamically allocate a new videoGame object, sending the data from the file as arguments to the videoGame constructor
            videoGame* gameLoad = new videoGame(gameTitle, gameDeveloper, gamePublisher, yearReleased);

            // check to see if numGames is equal to maxGames
            if(numGames == maxGames){
                // if qual, call the resizeVideoGameArray function
                videoGameLibrary::resizeVideoGameArray();
            }

            // --assign the new video game to te correct pointer in the videoGamesArray
            videoGamesArray[numGames] = gameLoad;

            // increment numGames
            numGames++;

            // print that the new video game has been added successfully
            cout << gameTitle << " was added successfully\n";
        }

        // print out how many video games were read from the file and added th the library
        cout << numGames << " were read from the file and added to your VideoGame library.";
        file.close();

    } else {
        cout << "Sorry, I was unable to open the file.\n\n";
    }
    
}   

// removeVideoGameFromArray function
void videoGameLibrary::removeVideoGameFromArray(){

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
    int choice;
    cin >> choice;

    // input check
    if(choice < 1 || choice > numGames){
        cout << "Invalid choice. Enter a number between 1 and " << numGames << ":";
        cin >> choice;
    }

    // print that the video game title has been successfully deleted
    cout << videoGamesArray[choice - 1]->videoGame::getVideoGameTitle() << " has been successfully deleted.\n\n";

    // release the dynamically allocated space for the video game
    delete videoGamesArray[choice - 1];
    cout << "VideoGame destructor: Released memory for VideoGame object";

    // move all array elements in the videoGamesArray back 1, starting with the deleted video game's element
    for(int i = choice - 1; i < numGames; ++i){
        videoGamesArray[i] = videoGamesArray[i + 1];
    }

    // decrement numGames
    numGames--;
}

// saveToFile function
void videoGameLibrary::saveToFile(string* filename){
    ofstream file(*filename);
    if (file.is_open()){
        // loop through the videoGamesArray
        for(int i = 0; i < numGames; i++){
            // call the printVideoGameDetailsToFile, sending the file stream object to be printed to
            videoGamesArray[i]->videoGame::printVideoGameDetailsToFile(file);
        }

        // close the file
        file.close();

        // print a confirmation that all video games have been printed to the filename
        cout << "All video games in your library have been printed to " << filename << endl << endl;
    }
}