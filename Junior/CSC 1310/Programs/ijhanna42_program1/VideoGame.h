#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string>
#include "Text.h"

using namespace std;
class Text;

class VideoGame {
public:
    VideoGame* VideoGame(Text* t, Text* d, Text* p, int y) : title(t), developer(d), publisher(p), year(y) {}
    ~VideoGame() {
        delete title;
        delete developer;
        delete publisher;
        cout << "VideoGame destructor: Released memory for VideoGame object." << endl;
    }
    void printVideoGameDetails();
    void printVideoGameDetailsToFile(ofstream&);
    Text* getVideoGameTitle();

private:
    Text* title;
    Text* developer;
    Text* publisher;
    int year;
};

#endif