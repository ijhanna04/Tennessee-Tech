/*
	Title:  ifStatementA.cpp
	Author:  Gaddis, modified by Crockett
	Date:  6-1-2017
	Purpose:  This program averages three test scores
*/
#include <iostream>
using namespace std;

int main()
{
   const double HIGH_SCORE = 95.0;   // A high score is 95 or greater
   int score1, score2, score3;  // To hold three test scores
   double average;              // To hold the average score

   // Get the three test scores.
   cout << "Enter 3 test scores and I will average them: ";
   cin >> score1 >> score2 >> score3;
   
   // Calculate and display the average score.
   average = (score1 + score2 + score3) / 3.0;
   
   cout << "Your average is " << average << endl;
   
   // If the average is a high score, congratulate the user.
   if (average > HIGH_SCORE)
      cout << "Congratulations! That's a high score!\n";
  
   return 0;
} 




