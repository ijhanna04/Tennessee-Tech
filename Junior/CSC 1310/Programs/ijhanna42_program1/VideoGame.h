#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <fstream>
using namespace std;

#include "Text.h"

class videoGame{
    public:
        videoGame(Text* titleVG, Text* developerVG, Text* publisherVG, int yearVG);
        ~videoGame();
        void printVideoGameDetails();
        void printVideoGameDetailsToFile(ofstream& file) const;
        Text* getVideoGameTitle() const;
    private:
        Text* title;
        Text* developer;
        Text* publisher;
        int year;
};

#endif