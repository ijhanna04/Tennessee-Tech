/*
   Title:  mixingGetline.cpp
   Author:  April R Crockett
   Date: 9/3/2021
   Purpose:  demonstrate mixing extraction operator and getline
*/

#include <iostream>
using namespace std;

int main()
{
   string lineOfStars(50,'*');
   string name, city, candy, word, nickname;
   int age, year;


   cout << lineOfStars << endl;
   cout << "\nEnter your name: ";
   getline(cin, name);

   cout << "\nEnter your age: ";
   cin >> age;
   cin.ignore();
   
   cout << "\nEnter your city: ";
   getline(cin, city);

   cout << "\nEnter your favorite candy: ";
   getline(cin, candy);

   cout << "\nWhat year did you enter in college: ";
   cin >> year;
   cin.ignore();

   cout << "\nGive a single word that describes you (without spaces): ";
   getline(cin, word);
   
   cout << "\nWhat is your nickname:  ";
   getline(cin, nickname);
   
   cout << "\n\nThank You!\n\n";
   return 0;
}


