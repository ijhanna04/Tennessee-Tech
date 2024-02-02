/*
    Title:      Text.h
    Author:     Ian Hanna
    Date        September 18, 2023
    Purpose:    Text Header File
*/

#ifndef TEXT_H
#define TEXT_H

#include <iostream>
using namespace std;

// Text class definition
class Text{
    public:
        Text(const char* arr);  // Text constructor
        ~Text();    // Text destructor
        void displayText();
        const char* getText() const;    // accessor function
        int getLength() const;  // accessor function
    private:
        const char* textArray;  
        int textLength;
};

#endif