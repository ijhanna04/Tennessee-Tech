#include <iostream>
#include "VideoGame.h"
#include "Text.h"

//VideoGame constructor
VideoGame(Text* title, Text* developer, Text* publisher, int year){
    this->title = title;
    this->developer = developer;
    this->publisher = publisher;
    this->year = year;
}

//~VideoGame destructor
~VideoGame(){
    delete title;
    delete developer;
    delete publisher;
    cout << "VideoGame destructor: Released memory for VideoGame object.\n";
}

void printVideoGameDetails(){
    cout << "Game Title: ";
    title->displayText();
    cout << "Developer: ";
    developer->displayText();
    cout << "Publisher: ";
    publisher->displayText();
    cout << "Year Released: " << year << endl;
}

void printVideoGameDetailsToFile(ofstream& file){
    cout << "Game Title: ";
    title->displayText();
    cout << "Developer: ";
    developer->displayText();
    cout << "Publisher: ";
    publisher->displayText();
    cout << "Year Released: " << year << endl;
}

Text* getVideoGameTitle(){
    return title;
}