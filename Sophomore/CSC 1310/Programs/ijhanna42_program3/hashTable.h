#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using std::string;

class hashTable
{
	private:
		class entry;

		//add the attributes you need for the class---------------------------------------------------------

		int hash(string);
	public:
		//add all the functions you need--------------------------------------------------------------------
		string generateSalt();
};

class hashTable::entry
{
	private:
		string uname;
		string salt;
		string passHash;
	public:
		entry* next;

		//add the constructor and getter functions-----------------------------------------------------------

};

#endif