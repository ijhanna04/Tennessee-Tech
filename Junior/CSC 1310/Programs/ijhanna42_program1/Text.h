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

class Text{
    public:
        Text(const char* const arr);
        ~Text();
        void displayText();
        const char* getText() const;
        int getLength() const;
    private:
        char* textArray;  
        int textLength;
};

#endif