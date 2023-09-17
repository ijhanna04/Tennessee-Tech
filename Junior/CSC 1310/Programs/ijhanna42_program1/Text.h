#ifndef TEXT_H
#define TEXT_H

#include <iostream>
using namespace std;

class Text{
    public:
        Text(const char* arr);
        ~Text();
        void displayText();
        const char* getText() const;
        int getLength() const;
    private:
        const char* textArray;  
        int textLength;
};

#endif