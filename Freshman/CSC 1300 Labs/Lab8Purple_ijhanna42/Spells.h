#ifndef SPELLS_H
#define SPELLS_H

#include <iostream>
using namespace std;

//global constant for SIZE
const int SIZE = 10;

//function prototypes
void getInfoFromUser(string [], int []);
double calculateAverage(int []);
int findLowest(int []);
int findHighest(int []);
string findLowestName(int [], string[]);
string findHighestName(int [], string[]);

#endif