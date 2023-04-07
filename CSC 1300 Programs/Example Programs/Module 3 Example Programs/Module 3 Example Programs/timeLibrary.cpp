#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	/*
		The value returned from the time() function represents
		the number of seconds since 00:00 hours, Jan 1, 1970 UTC
		This is the current unix timestamp and you can read more
		about that here:  https://www.unixtimestamp.com/.
	*/

	/*
		The time function must be sent an argument.  One option is
		to send NULL or 0....these do the same thing.
	*/
	cout << time(NULL) << " is the number of seconds since 00:00 hours, Jan 1, 1970 UTC\n";
	cout << time(0) << " is the number of seconds since 00:00 hours, Jan 1, 1970 UTC\n";
	
	
	
	/*
		If you did actually want to print out the current date/time, you can use time and then ctime
		The ctime function converts the time_t value to a c-string containing a human-readable
		version of the corresponding time and date in terms of local time.
	*/
	time_t now; //time_t is actually a data type for time
	char* date_time;
	now = time(0);
	date_time = ctime(&now); 
	cout << date_time <<" is the current date and time.";

	return 0;
}