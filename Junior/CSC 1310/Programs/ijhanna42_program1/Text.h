#ifndef TEXT_H
#define TEXT_H

#include <iostream>

using namespace std;

class Text {
    char *textArray;   
    int textLength;     
};

Text(const char*);
~Text();
void displayText();
const char* getText();
int getLength();


#endif