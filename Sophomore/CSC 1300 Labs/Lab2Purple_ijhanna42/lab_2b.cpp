#include <iostream>
using namespace std;

int main(){
    int numPuppies, foodDay, costFoodWeek;




    cout << "Puppy Food Cost Calculator" << endl << endl;

    cout << "Please enter th number of puppies: ";
    cin >> numPuppies;
    
    foodDay = numPuppies * 2;

    cout << "The amount of pet food needed per day: " << foodDay << " cups" << endl;

    costFoodWeek = foodDay * 7 * 3;
    cout << "The total cost of pet food per week: $" << costFoodWeek;
    return 0;
}