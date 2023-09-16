#include <iostream>
#include "VideoGame.h"
#include "Text.h"

using namespace std;

//VideoGame constructor
VideoGame* createVideoGame(Text* vgTitle, Text* vgDeveloper, Text* vgPublisher, int vgYear){
    VideoGame* videogame = new VideoGame;
    videogame->title = vgTitle;
    videogame->developer = vgDeveloper;
    videogame->publisher = vgPublisher;
    videogame->year = vgYear;
}

//~VideoGame destructor
void destroyVideoGame(VideoGame* videogame){
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