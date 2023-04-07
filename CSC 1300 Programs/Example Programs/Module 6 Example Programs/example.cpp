#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream outFile;
	
	outFile.open("something.txt");
	
	outFile << "\n\nWhatever I want.\n";
	outFile << "This is 1300.\n";
	
	outFile.close();
	
	outFile.open("something.txt", ios::app);
	outFile << "Writing something else now.\n";
	outFile << "making this up right now.\n";
	
	outFile.close();
	
	cout << "\n\nDone writing to file.\n\n";
	return 0;
}





