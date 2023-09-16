#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>

using namespace std;

class Text {
    public:
        Text(const char*);
        ~Text();
        void displayText();
        const char* getText();
        int getLength();
    private:
        char *textArray;   
        int textLength;
        string str;
};

#endif