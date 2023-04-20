#ifndef PROG4_H
#define PROG4_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

struct Cost {
    int hoursPerWeek;
    double costPerWeek;
    double foodCostPerWeek;
    double materialsCostPerWeek;
};

struct Monster {
    string name;
    string description;
    double weightInPounds;
    double heightInFeet;
    string location;
    int dangerLevel;
    Cost cost;
};

int loadMonstersFromFile(Monster[], int);
int registerMonster(Monster[], int );
int removeMonster(Monster[], int);
void printMonsters(Monster[], int);
void printCostInfo(Monster[], int);
void saveMonstersToFile(Monster[], int);



#endif
