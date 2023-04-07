#include <iostream>
using namespace std;

int main()
{
	int counter = 10;
	
	do{
		cout << counter << endl;
		counter--;
	} while(counter >= 5)
		
	cout << endl;
	cout << "out of loop";
	return 0;
}

