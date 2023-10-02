/*
    Title:      ijhanna42_prog2.cpp
    Author:     Ian Hanna
    Date        March 8, 2023
    Purpose:    Predict the Future
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function prototypes
int displayMenuChoice(int);
int randomNum(int, int);

int main(){
    //integer variables
    int menuChoice;
    int choice;
    int randNum1, randNum2, randNum3;
    int randNum4, randNum5, randNum6;
    int jobTitleChoice;
    int companyChoice;
    int childrenChoice;
    int children;
    int salaryChoice;
    int salary;

    //string variables
    string awesomeJob1, awesomeJob2, badJob;
    string companyLike1, companyLike2, companyHate;
    string jobTitle;
    string company;

    //do-while loop for main menu
    do{
        menuChoice = displayMenuChoice(choice);
       
        switch (menuChoice){
            case 1:
                cout << "\nYou chose to predict your future!\n";
                cout << "First, I need just a little information.\n\n";

                // get user input for three integers between 1 and 100
                cout << "Enter three numbers between 1 and 100, separated by a space.\n";
                cin >> randNum1 >> randNum2 >> randNum3;
                cin.ignore();
                //input validation for individual numbers
                while ((randNum1 < 1) || (randNum1 > 100)){
                    cout << "Invalid choice for the first number you entered.\nEnter a number between 1 and 100.\n";
                    cin >> randNum1;
                    cin.ignore();
                }
                while ((randNum2 < 1) || (randNum2 > 100)){
                    cout << "Invalid choice for the second number you entered.\nEnter a number between 1 and 100.\n";
                    cin >> randNum2;
                    cin.ignore();
                }
                while ((randNum3 < 1) || (randNum3 > 100)){
                    cout << "Invalid choice for the third number you entered.\nEnter a number between 1 and 100.\n";
                    cin >> randNum3;
                    cin.ignore();
                }
                
                // get user input for three job titles
                cout << "\nEnter an awesome job title: ";
                getline(cin, awesomeJob1);
                cout << "Enter in another awesome job title: ";
                getline(cin, awesomeJob2);
                cout << "Enter in the worst job title ever: ";
                getline(cin, badJob);

                //get user input for three companies, organizations, or restaurants
                cout << "\nEnter a company, organization, or restaurant you like: ";
                getline(cin, companyLike1);
                cout << "Enter another company, organization, or restaurant you like: ";
                getline(cin, companyLike2);
                cout << "Enter a company, organization, or restaurant you hate: ";
                getline(cin, companyHate);

                // get user input for three integers between 10000 and 500000
                cout << "\nEnter three numbers between 10,000 and 500,000, separated by a space.\n";
                cin >> randNum4 >> randNum5 >> randNum6;
                //input validation for individual numbers
                while ((randNum4 < 10000) || (randNum4 > 500000)){
                    cout << "Invalid choice for the first number you entered.\nEnter a number between 1 and 100.\n";
                    cin >> randNum4;
                }
                while ((randNum5 < 10000) || (randNum5 > 500000)){
                    cout << "Invalid choice for the second number you entered.\nEnter a number between 1 and 100.\n";
                    cin >> randNum5;
                }
                while ((randNum6 < 10000) || (randNum6 > 500000)){
                    cout << "Invalid choice for the third number you entered.\nEnter a number between 1 and 100.\n";
                    cin >> randNum6;
                }

                //calculations
                
                //spouse calculation
                    ifstream inputPeople;
                    inputPeople.open("PEOPLE_PC.txt");
                    string spouse;
                    int randomLine = randomNum(1, 15);
                    for (int i = 0; i < randomLine; ++i)
                        if (inputPeople.is_open()){
                            getline(inputPeople, spouse);
                        } else {
                            cout << "Error opening PEOPLE_PC.txt";
                        }
                    inputPeople.close();


                //dwelling calculaton
                    ifstream inputDwellings;
                    inputDwellings.open("DWELLINGS_PC.txt");
                    string dwelling;
                    for (int j =0; j < randomNum(1, 15); ++j)
                        if (inputDwellings.is_open()){
                            getline(inputDwellings, dwelling);
                        }
                    inputDwellings.close();

                //location calculation
                    ifstream inputLocation;
                    inputLocation.open("LOCATIONS_PC.txt");
                    string location;
                    for (int k = 0; k < randomNum(1, 15); ++k)
                        if (inputLocation.is_open()){
                            getline(inputLocation, location);
                        }
                    inputLocation.close();

                //car calculation
                    ifstream inputCar;
                    inputCar.open("CARS_PC.txt");
                    string car;
                    for (int k = 0; k < randomNum(1, 15); ++k)
                        if (inputCar.is_open()){
                            getline(inputCar, car);
                        }
                    inputCar.close();
                        
                //children number calculation
                childrenChoice = randomNum(1, 3);
                switch(childrenChoice){
                    case 1:
                        children = randNum1;
                        break;
                    case 2:
                        children = randNum2;
                        break;
                    case 3:
                        children = randNum3;
                        break;
                }

                //job title random number choice
                jobTitleChoice = randomNum(1, 3);
                switch(jobTitleChoice){
                    case 1:
                        jobTitle = awesomeJob1;
                        break;
                    case 2:
                        jobTitle = awesomeJob2;
                        break;
                    case 3:
                        jobTitle = badJob;
                        break;
                }

                //company random number choice
                companyChoice = randomNum(1, 3);
                switch(companyChoice){
                    case 1:
                        company = companyLike1;
                        break;
                    case 2:
                        company = companyLike2;
                        break;
                    case 3:
                        company = companyHate;
                        break;
                }

                //salary calculation
                salaryChoice = randomNum(1, 3);
                switch(salaryChoice){
                    case 1:
                        salary = randNum4;
                        break;
                    case 2:
                        salary = randNum5;
                        break;
                    case 3:
                        salary = randNum6;
                        break;
                }

                // future predictions
                cout << "\n\n******  YOUR FUTURE  ******\n";
                cout << "You and your spouse, " << spouse << " will live in a " << dwelling << " in " << location << ",";
                cout << "\nand drive a " << car << ".";
                cout << "\nYou and your spouse will have " << children << " children.";
                cout << "\nYou will work at " << company << " as a " << jobTitle << " making " << salary << " a year.\n\n";
                break;               
        }
    } while (menuChoice != 2);

    // end of program
    cout << "You chose to end the program.\n";
    cout << "Bye!";
    return 0;
}


// random number function
int randomNum(int a, int b){
    int result;
    srand(time(0));
    result = rand() % (b - a + 1) + a;
    return result;
}

// menu function
int displayMenuChoice(int mChoice){
    cout << "Pick from the following menu: \n";
    cout << "1. Predict my future!\n";
    cout << "2. End the program.\n";
    cout << "CHOOSE 1 or 2: ";
    cin >> mChoice;
    while ((mChoice < 1) || (mChoice > 2)){
        cout << "Invalid choice. CHOOSE 1 or 2: ";
        cin >> mChoice;
    }
    return mChoice;
}
