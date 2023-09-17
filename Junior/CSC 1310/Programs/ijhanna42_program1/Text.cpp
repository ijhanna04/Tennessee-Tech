#include <iostream>
#include <string.h>
using namespace std;

#include "Text.h"

Text::Text(const char* arr){
    textLength = strlen(arr);
    textArray = new char[textLength];
}

Text::~Text(){
    delete [] textArray;
    cout << "Text destructor: Released memory for textArray\n";
}

void Text::displayText(){
    cout << textArray << endl;
}

const char* Text::getText() const{
    return textArray;
}

int Text:: getLength() const{
    return textLength;
}