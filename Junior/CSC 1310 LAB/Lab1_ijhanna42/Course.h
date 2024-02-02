#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

//structure containing Course information
struct Course {
    string name;
    string location;
    string* sections;
    int numSections;
    int numCreditHours;

};

//function prototypes
Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif