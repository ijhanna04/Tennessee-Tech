/*
    Title:      Text.cpp
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Text Functions
*/

#include <iostream>

#include <cstring>
using namespace std;

// include necessary files
#include "Text.h"

// Text constructor
Text::Text(const char* const arr){

    // dynamically allocate a new character string the size of the string passed to the function
    textLength = strlen(arr);

    // set the textArray attribute to the newly created c-string
    textArray = new char[textLength];

    // copy the text sent as an argument to the constructor to the new dynamically allocated string using strcpy
    strcpy(textArray, arr);

}

// Text destructor
Text::~Text(){

    // release the memory from the c-string pointed to by the Text array
    delete [] textArray;

    // print a message that memory has been released
    cout << "Text destructor: Released memory for textArray\n";
}

// displayText function
void Text::displayText(){

    // print the c-string(textArray) to the screen
    cout << textArray << endl;
}

// getText accessor function
const char* Text::getText() const{

    // return a pointer to a constant character array
    return textArray;
}

// getLength accessor function
int Text:: getLength() const{

    // return the length of the string
    return textLength;
}