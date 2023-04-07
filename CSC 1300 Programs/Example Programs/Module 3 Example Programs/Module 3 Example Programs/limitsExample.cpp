#include <limits>
#include <iostream>
using namespace std;

int main()
{
	cout << "Minimum value for int: " << numeric_limits<int>::min() << endl;
	cout << "Also the minimum for int: " << numeric_limits<int>::lowest() << endl;
	cout << "Maximum value for int: " << numeric_limits<int>::max() << endl;
	cout << "Minimum value for double: " << numeric_limits<double>::min() << endl;
	cout << "Maximum value for double: " << numeric_limits<double>::max() << endl;	
	cout << "int is signed: " << numeric_limits<int>::is_signed << endl;

	return 0;
}