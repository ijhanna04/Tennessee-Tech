/*
    Title:      VideoGame.cpp
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Video Game Functions
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// include necessary header files
#include "VideoGame.h"

// videoGame constructor
videoGame::videoGame(Text* titleVG, Text* developerVG, Text* publisherVG, int yearVG){

    // initialize all attributes to the arguments sent to the function
    this->title = titleVG;
    this->developer = developerVG;
    this->publisher = publisherVG;
    this->year = yearVG;
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
    cout << "       Game Title: "; 
    title->displayText();
    cout << endl;
    cout << "       Developer: "; 
    developer->displayText();
    cout << endl;
    cout << "       Publisher: ";
    publisher->displayText();
    cout << endl;
    cout << "       Year Released: " << year << endl;

}

// printVideoGameDetailsToFile function
void videoGame::printVideoGameDetailsToFile(ofstream& filename){

    char temp[10000];
    // print the title, developer, publisher, and year to the filestream object sent to the function
    strncpy(temp, title->getText(), 10000);
    filename << temp << endl;
    strncpy(temp, developer->getText(), 10000);
    filename << temp << endl;
    strncpy(temp, publisher->getText(), 10000);
    filename << temp << endl;
    filename << year << endl;
}

// getVideoGameTitle accessor function
void videoGame::getVideoGameTitle() const{

    // return a pointer to the Text object containing the video game title
    title->displayText();
}