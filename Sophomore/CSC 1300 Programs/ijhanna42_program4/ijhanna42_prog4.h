#ifndef IJHANNA42_PROG3_H
#define IJHANNA42_PROG3_H

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int maxCapacity = 75;

//Cost structure
struct Cost {
    double numCareHours;
    double costPerHour;
    double foodCost;
    double materialCost;    
};


//Monsters structure
struct Monsters {
    string name;
    string description;
    double weight;
    double height;
    string location;
    int dangerLevel;
    Cost cData;
};

//function prototypes
int loadMonstersFromFile(int, Monsters[]);
int registerMonster(int, Monsters[]);
int removeMonster(int, Monsters[]);
void printMonsters(int, Monsters[]);
void printCostInfo(int, Monsters[]);
void saveMonstersToFile(int, Monsters[]);

#endif