#include <iostream>
#include "course.h"
using namespace std;

Course* createCourse(string courseName, string courseLocation, int numSections, int numCredits){
    Course* course = new Course;
    course->name = courseName;
    course->location = courseLocation;
    course->numSections = numSections;
    course->numCreditHours = numCredits;
    return course;
}

void destroyCourse(Course* course){
    delete[] course->sections;
    delete course;
}

void printCourse(Course* myCourse){
    cout << "COURSE NAME: " << myCourse->name << endl;
    cout << "LOCATION: " << myCourse->location << endl;
    cout << "COURSE HOURS: " << myCourse->numCreditHours<< endl;
    cout << "COURSE SECTIONS: " << myCourse->sections << endl;
    
}


