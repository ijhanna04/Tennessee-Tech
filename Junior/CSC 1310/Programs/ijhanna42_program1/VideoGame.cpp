/*
    Title:      VideoGame.cpp
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Video Game Functions
*/

#include <iostream>
using namespace std;

// include necessary header files
#include "VideoGame.h"

// videoGame constructor
videoGame::videoGame(Text* titleVG, Text* developerVG, Text* publisherVG, int yearVG){

    // initialize all attributes to the arguments sent to the function
    title = titleVG;
    developer = developerVG;
    publisher = publisherVG;
    year = yearVG;
}

// videoGame destructor
videoGame::~videoGame(){

    // release the dynamically allocated space for the video game title, developer, and publisher
    delete title;
    delete developer;
    delete publisher;

    // print a message that memory has been deleted for the VideoGame object
    cout << "VideoGame destructor: Released memory for VideoGame object";
}

// printVideoGameDetails function
void videoGame::printVideoGameDetails(){

    // print the title, developer, publisher, and year
    cout << "Game Title: "; 
    title->Text::displayText();
    cout << "Developer: "; 
    developer->Text::displayText();
    cout << "Publisher: ";
    publisher->Text::displayText();
    cout << "Year Released: " << year << endl;

}

// printVideoGameDetailsToFile function
void videoGame::printVideoGameDetailsToFile(ofstream& filename) const{

    // print the title, developer, publisher, and year to the filestream object sent to the function
    filename << title->getText() << endl << developer->getText() << endl << publisher->getText() << endl << year << endl;

    cout << endl << "All video games in your library have been printed to " << &filename << endl << endl;
}

// getVideoGameTitle accessor function
Text* videoGame:: getVideoGameTitle() const{

    // return a pointer to the Text object containing the video game title
    return title;
}