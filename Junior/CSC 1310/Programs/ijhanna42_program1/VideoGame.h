#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include "Text.h"

using namespace std;

class VideoGame {
    Text* title;
    Text* developer;
    Text* publisher;
    int year;
};

VideoGame* createVideoGame(Text*, Text*, Text*, int);
void destroyVideoGame(VideoGame* videogame);
void printVideoGameDetails();
void printVideoGameDetailsToFile(ofstream&);
Text* getVideoGameTitle();

#endif