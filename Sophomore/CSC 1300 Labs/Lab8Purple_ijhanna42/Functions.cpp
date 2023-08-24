#include "Spells.h"

//function definition to get user input for spell names and effects
void getInfoFromUser(string spellNamesINFO[], int effectAmountINFO[]){
    for(int i = 0; i < SIZE; i++){
        cout << "SPELL " << i+1 << ":";
        cout << "\n     NAME - ";
        cin >> spellNamesINFO[i];
        cout << "     EFFECT - ";
        cin >> effectAmountINFO[i];
    }
}

//function definition to calculate the average of the effects of all spells
double calculateAverage(int effectAmountAVE[]){
    double total = 0;
    for (int i = 0; i < SIZE; i++){
        total += effectAmountAVE[i];
    }
    double average = total / SIZE;
    return average;
}

//function definition to find the spell with the lowest effect amount
int findLowest(int effectAmountLOW[]){
    int minValue = effectAmountLOW[0];
    for (int i = 0; i < SIZE; i++){
        if(effectAmountLOW[i] < minValue){
            minValue = effectAmountLOW[i];
        }
    }
    return minValue;
}

//function definition to find the name of the spell with the lowest effect amount
string findLowestName(int effectAmountLOW[], string spellNameLOW[]){
    int minValue = effectAmountLOW[0];
    string lowestName;
    for (int i = 0; i < SIZE; i++){
        if(effectAmountLOW[i] < minValue){
            minValue = effectAmountLOW[i];
            lowestName = spellNameLOW[i];
        }
    }
    return lowestName;
}

//function definition to find the spell with the highest effect amount
int findHighest(int effectAmountHIGH[]){
    int maxValue = effectAmountHIGH[0];
    for (int i = 0; i < SIZE; i++){
        if(effectAmountHIGH[i] > maxValue){
            maxValue = effectAmountHIGH[i];
        }
    }
    return maxValue;
}

//function definition to find the name of the spell with the highest effect amount
string findHighestName(int effectAmountHIGH[], string spellNameHIGH[]){
    int maxValue = effectAmountHIGH[0];
    string highestName;
    for (int i = 0; i < SIZE; i++){
        if(effectAmountHIGH[i] > maxValue){
            maxValue = effectAmountHIGH[i];
            highestName = spellNameHIGH[i];
        }
    }
    return highestName;
}