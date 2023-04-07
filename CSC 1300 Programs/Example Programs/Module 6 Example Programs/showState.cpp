// This program demonstrates the return value of the stream
// object error testing member functions.
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	int num = 10;

	// Open the file for output.
	fstream testFile("stuff.dat", ios::out);
	
	
	if (testFile.fail())
	{
		cout << "ERROR: cannot open the file.\n";
		return 0;
	}

	// Write a value to the file.
	cout << "Writing the value " << num << " to the file.\n";
	testFile << num;

	// Show the bit states.
	cout << "File Status:\n";
	cout << " eof bit: " << testFile.eof() << endl;
	cout << " fail bit: " << testFile.fail() << endl;
	cout << " bad bit: " << testFile.bad() << endl;
	cout << " good bit: " << testFile.good() << endl;
	testFile.clear();	// Clear any bad bits

	// Close the file.
	testFile.close();

	// Reopen the file for input.
	testFile.open("stuff.dat", ios::in);
	if (testFile.fail())
	{
		cout << "ERROR: cannot open the file.\n";
		return 0;
	}

	// Read the only value from the file.
	cout << "Reading from the file.\n";
	testFile >> num;
	cout << "The value " << num << " was read.\n";

	// Show the bit states.
	cout << "File Status:\n";
	cout << " eof bit: " << testFile.eof() << endl;
	cout << " fail bit: " << testFile.fail() << endl;
	cout << " bad bit: " << testFile.bad() << endl;
	cout << " good bit: " << testFile.good() << endl;
	testFile.clear();	// Clear any bad bits

	// No more data in the file, but force an invalid read operation.
	cout << "Forcing a bad read operation.\n";
	testFile >> num;

	// Show the bit states.
	cout << "File Status:\n";
	cout << " eof bit: " << testFile.eof() << endl;
	cout << " fail bit: " << testFile.fail() << endl;
	cout << " bad bit: " << testFile.bad() << endl;
	cout << " good bit: " << testFile.good() << endl;
	testFile.clear();	// Clear any bad bits

	// Close the file.
	testFile.close();
	testFile.clear();
	return 0;
}






