#ifndef COURSE_3
#define COURSE_3

#include <iostream>

using namespace std;

//structure containing Course information
struct Course {
    string Name;
    string Location;
    //Sections (pointer to an array of strings)
    int numSections;
    int numCreditHours;
};

//function prototypes
Course* createCourse(string, string, int, int);
void destroyCourse(Course* myCourse);
void printCourse(Course* myCourse);

#endif