#include <iostream>
#include "Text.h"

using namespace std;

Text::Text(const char* text){
    textLength = strlen(text);
    textArray = new char[textLength + 1];
    strcpy(textArray, text);
}

Text::~Text(){
    delete[] textArray;
    cout << "Text destructor: Released memory for textArray.\n";
} 

void displayText(){
    cout << textArray << endl;
}

const char* getText(){
    return textArray;
}

int getLength(){
    return textLength;
}