#include <iostream>
using namespace std;

#include "VideoGame.h";

videoGame::videoGame(Text* titleVG, Text* developerVG, Text* publisherVG, int yearVG){
    title = titleVG;
    developer = developerVG;
    publisher = publisherVG;
    year = yearVG;
}

videoGame::~videoGame(){
    delete title;
    delete developer;
    delete publisher;
    cout << "VideoGame destructor: Released memory for VideoGame object";
}

void videoGame::printVideoGameDetails(){
    cout << "Game Title: "; 
    title->Text::displayText();
    cout << "Developer: "; 
    developer->Text::displayText();
    cout << "Publisher: ";
    publisher->Text::displayText();
    cout << "Year Released: " << year << endl;

}

void videoGame::printVideoGameDetailsToFile(ofstream& file) const{
    string filename;
    cout << "What do you want to name the file? (example.txt): ";
    cin >> filename;
    ofstream file(filename);
    if(file.is_open()){
        file << title->getText() << endl << developer->getText() << endl << publisher->getText() << endl << year << endl;
    }

    file.close();
    cout << endl << "All video games in your library have been printed to " << filename << endl << endl;
}

Text* videoGame:: getVideoGameTitle() const{
    return title;
}