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

VideoGame(Text*, Text*, Text*, int);
~VideoGame();
void printVideoGameDetails();
void printVideoGmeDetailsToFile(ofstream&);
Text* getVideoGameTitle();

#endif