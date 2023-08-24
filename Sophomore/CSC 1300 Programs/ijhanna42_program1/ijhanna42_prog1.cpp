/*
    Title:      ijhanna42_prog1.cpp
    Author:     Ian Hanna
    Date        February 15, 2023
    Purpose:    Life Expectancy Calculator
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // list of variables for user input
    string firstName;
    int currentAge, weightStatus, exerciseStatus, maritalStatus, jobFeeling, hangoutFriends, educationLevel;
    char gender, smokeStatus, drinkStatus, petStatus, caretakerStatus, eatBreakfast, dieYoung, eatFruits, eatVegetables;

    // prompts for user input
    cout << "Enter your name: ";
    getline(cin, firstName);

    cout << endl << "Enter your current age: ";
    cin >> currentAge;

    cout << endl << "Are you male or female? (Enter m or f): ";
    cin >> gender;

    cout << endl << "What is your weight status?" << endl;
    cout << "(1)Underweight, (2)Just right, (3)Overweight, (4)Obese" << endl;
    cout << "(Enter 1, 2, 3 or 4): ";
    cin >> weightStatus;

    cout << endl << "Do you smoke cigarettes? (Enter y or n): ";
    cin >> smokeStatus;

    cout << endl << "Do you drink more than one alcoholic beverage every day?" << endl;
    cout << "(Enter y or n): ";
    cin >> drinkStatus;

    cout << endl << "Do you exercise?" << endl;
    cout << "(1)None, (2)Very Little, (3)Periodically, (4)Active, (5)Athlete" << endl;
    cout << "(Enter 1, 2, 3, 4 or 5): ";
    cin >> exerciseStatus;

    cout << endl << "Do you have a pet? (Enter y or n): ";
    cin >> petStatus;

    cout << endl << "Are you married?" << endl;
    cout << "(1) Divorced, (2)Single, (3)Married, (4)Happily Married" << endl;
    cout << "(Enter 1, 2, 3 or 4): ";
    cin >> maritalStatus;

    cout << endl << "Are you a caretaker? (Enter y or n): ";
    cin >> caretakerStatus;

    cout << endl << "How do you feel about your job?" << endl;
    cout << "(1)Hate it!, (2)Dislike it, (3)It's ok, (4)Enjoyable, (5) Love it!" << endl;
    cout << "(Enter 1, 2, 3, 4 or 5): ";
    cin >> jobFeeling;

    cout << endl << "Do you eat breakfast every day? (Enter y or n): ";
    cin >> eatBreakfast;

    cout << endl << "Did either of your biological parents or any of your biological" << endl;
    cout << "grandparents die before the age of 50? (Enter y or n): ";
    cin >> dieYoung;

    cout << endl << "Do you eat fruits every day? (Enter y or n): ";
    cin >> eatFruits;

    cout << endl << "Do you eat vegetables every day? (Enter y or n): ";
    cin >> eatVegetables;

    cout << endl << "Do you hang out with your friends?" << endl;
    cout << "(1)Never, (2)Periodically, (3)Often" << endl;
    cout << "(Enter 1, 2 or 3): ";
    cin >> hangoutFriends;

    cout << endl << "What is your education level?" <<endl;
    cout << "(1)No degrees, (2)Highschool degree, (3)Associates degree," << endl;
    cout << "(4)Bachelors degree, (5)Masters/PHD degree" << endl;
    cout << "(Enter 1, 2, 3, 4 or 5): ";
    cin >> educationLevel;

    // variables for life expectancy equations
    bool isMale, doesSmoke, doesDrink, ownsPet, isCaretaker, eatsBreakfast, diedYoung, eatsFruits, eatsVegetables;
    int lifeExpectancy;

    // life expectancy equations
        if(currentAge <= 60){
            lifeExpectancy = 60;
        } else {
            lifeExpectancy = currentAge;
        }
    cout << endl << "Starting Life Epectancy: " << lifeExpectancy << endl;

    cout << "Life Expectancy after gender: ";
        if(gender == 'm'){
            isMale = true;
        }else {
            isMale = false;
        }
        if (isMale){
            lifeExpectancy = lifeExpectancy;
        }else if (gender == 'f'){
            lifeExpectancy += 4;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after weight: ";
        switch(weightStatus)
        {
            case 1: 
                lifeExpectancy -= 1;
                break;
            case 2: 
                lifeExpectancy += 5;
                break;
            case 3:
                lifeExpectancy -= 2;
                break;
            case 4:
                lifeExpectancy -= 5;
                break;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after smoke: ";
        if(smokeStatus == 'y'){
            doesSmoke = true;
        }else {
            doesSmoke = false;
        }
        if (doesSmoke){
            lifeExpectancy = lifeExpectancy -= 5;
        }else if (smokeStatus == 'n'){
            lifeExpectancy = lifeExpectancy += 5;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after alcohol: ";
        if(drinkStatus == 'y'){
            doesDrink = true;
        }else {
            doesDrink = false;
        }
        if (doesDrink){
            lifeExpectancy = lifeExpectancy -= 5;
        }else if (drinkStatus == 'n'){
            lifeExpectancy = lifeExpectancy += 2;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after exercise: ";
        switch(exerciseStatus)
        {
            case 1: 
                lifeExpectancy -= 5;
                break;
            case 2: 
                lifeExpectancy -= 2;
                break;
            case 3:
                lifeExpectancy = lifeExpectancy;
                break;
            case 4:
                lifeExpectancy += 5;
                break;
            case 5:
                lifeExpectancy += 7;
                break;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after pet: ";
        if(petStatus == 'y'){
            ownsPet = true;
        }else {
            ownsPet = false;
        }
        if (ownsPet){
            lifeExpectancy = lifeExpectancy += 3;
        }else if (petStatus == 'n'){
            lifeExpectancy = lifeExpectancy -= 1;
        } 
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after married: ";
        switch(maritalStatus)
        {
            case 1: 
                lifeExpectancy -= 5;
                break;
            case 2: 
                lifeExpectancy -= 2;
                break;
            case 3:
                lifeExpectancy += 2;
                break;
            case 4:
                lifeExpectancy += 5;
                break;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after caretaker: ";
        if(caretakerStatus == 'y'){
            isCaretaker = true;
        }else {
            isCaretaker = false;
        }
        if (isCaretaker){
            lifeExpectancy = lifeExpectancy -= 2;
        }else if (caretakerStatus == 'n'){
            lifeExpectancy = lifeExpectancy;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after job stress: ";
        switch(jobFeeling)
        {
            case 1: 
                lifeExpectancy -= 5;
                break;
            case 2: 
                lifeExpectancy -= 2;
                break;
            case 3:
                lifeExpectancy = lifeExpectancy;
                break;
            case 4:
                lifeExpectancy += 2;
                break;
            case 5:
                lifeExpectancy += 5;
                break;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after breakfast: ";
        if(eatBreakfast == 'y'){
            eatsBreakfast = true;
        }else {
            eatsBreakfast = false;
        }
        if (eatsBreakfast){
            lifeExpectancy = lifeExpectancy += 5;
        }else if (eatBreakfast == 'n'){
            lifeExpectancy = lifeExpectancy -= 2;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after died: ";
        if(dieYoung == 'y'){
            diedYoung = true;
        }else {
            diedYoung = false;
        }
        if (diedYoung){
            lifeExpectancy = lifeExpectancy -= 2;
        }else if (dieYoung == 'n'){
            lifeExpectancy = lifeExpectancy += 5;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after fruits: ";
        if(eatFruits == 'y'){
            eatsFruits = true;
        }else {
            eatsFruits = false;
        }
        if (eatsFruits){
            lifeExpectancy = lifeExpectancy += 5;
        }else if (eatFruits == 'n'){
            lifeExpectancy = lifeExpectancy -= 5;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after vegetables: ";
        if(eatVegetables == 'y'){
            eatsVegetables = true;
        }else {
            eatsVegetables = false;
        }
        if (eatsVegetables){
            lifeExpectancy = lifeExpectancy += 5;
        }else if (eatVegetables == 'n'){
            lifeExpectancy = lifeExpectancy -= 5;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after friends: ";
        switch(hangoutFriends)
        {
            case 1: 
                lifeExpectancy -= 2;
                break;
            case 2: 
                lifeExpectancy = lifeExpectancy;
                break;
            case 3:
                lifeExpectancy += 2;
                break;
        }
        cout << lifeExpectancy << endl;

    cout << "Life Expectancy after education level: ";
        switch(educationLevel)
        {
            case 1: 
                lifeExpectancy -= 5;
                break;
            case 2: 
                lifeExpectancy -= 2;
                break;
            case 3:
                lifeExpectancy += 2;
                break;
            case 4:
                lifeExpectancy += 5;
                break;
            case 5:
                lifeExpectancy += 7;
                break;
        }
        cout << lifeExpectancy << endl << endl;

    if(lifeExpectancy <= currentAge){
            lifeExpectancy = currentAge;
        } else {
            lifeExpectancy = lifeExpectancy;
        }

    // program output
    cout << string (49, '*') << endl << endl;

    cout << setw(22) << right << "Name:     " << firstName << endl;
    cout << setw(22) << right << "Current Age:     " << currentAge << endl;
    cout << setw(22) << right << "Life Expectancy:     " << lifeExpectancy << endl << endl;

    cout << string (49, '*') << endl << endl;
    
    return 0;
}