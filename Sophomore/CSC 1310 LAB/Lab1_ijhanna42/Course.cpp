#include <iostream>
#include "course.h"
using namespace std;

Course* createCourse(string courseName, string courseLocation, int numSections, int numCredits){
    Course* course = new Course;
    course->name = courseName;
    course->location = courseLocation;
    course->numSections = numSections;
    course->sections = new string[numSections];
    course->numCreditHours = numCredits;
    return course;
}

void destroyCourse(Course* course){
    delete[] course->sections;
    delete course;
}

void printCourse(Course* myCourse){
    cout << "COURSE NAME: \t\t" << myCourse->name << endl;
    cout << "LOCATION: \t\t" << myCourse->location << endl;
    cout << "COURSE HOURS: \t\t" << myCourse->numCreditHours<< endl;
    cout << "COURSE SECTIONS: \t\t" << endl;
    for (int i = 0; i < myCourse->numSections; i++) {
        cout << "\t\t\t" << myCourse->sections[i] << endl;
    }
    
}


