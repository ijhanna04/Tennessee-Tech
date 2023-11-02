#include <iostream>
#include <fstream>
#include "sha256.h"
//include your hash table---------------------------------------------------------------------------------------------------
#include "hashTable.h"
using namespace std;

int main()
{
	
	ifstream file("testlist.txt");
	int menuChoice;
	int numUsers;
	string user, pwd, salt;
	string username, password;

	hashTable* newTable = nullptr;
	
	if(file.is_open()) {
	file >> numUsers;
	file.ignore(1, '\n');

	//dynamically allocate your hash table-------------------------------------------------------------------------------
	newTable = new hashTable(numUsers);

	while(getline(file, user))
	{
		getline(file, pwd);

		//generate a salt and add the new user to your table--------------------------------------------------------
		string newSalt = newTable->generateSalt();
		newTable->addEntry(user, sha256(pwd), newSalt);
	}}
	
	do
	{
		cout << "\nWhat would you like to do?\n";
		cout << "1.  Login.\n";
		cout << "2.  Create account.\n";
		cout << "3.  Delete account.\n";
		cout << "4.  Exit.\n";
		cout << "CHOOSE 1-4:  ";
		cin >> menuChoice;
		while(menuChoice < 1 || menuChoice > 4)
		{
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-4:  ";
			cin >> menuChoice;
		}
		
		switch(menuChoice)
		{
			case 1:	cout << "enter your username:  ";
					cin >> username;
					cout << "enter your password:  ";
					cin >> password;
					
					if(newTable->validateLogin(username, sha256(password)))//check if the user's credentials are correct-----------------------------------
						cout << "login successful\n";
					else
						cout << "invalid credentials\n";
					
					break;
					
			case 2: cout << "enter your new username:  ";
					cin >> username;
					cout << "enter your new password:  ";
					cin >> password;
					
					//generate a salt for the new user and add the user to the table--------------------
					newTable->addEntry(user, sha256(pwd), newTable->generateSalt());

					break;
					
			case 3:	cout << "enter your username:  ";
					cin >> username;
					cout << "enter your password:  ";
					cin >> password;
					
					if(newTable->removeUser(username, sha256(password)))//remove the user from the table and check if they were removed successfully----
						cout << "user removed successfully.\n";
					else
						cout << "invalid credentials, cannot remove user.\n";
					break;
					
			case 4:	cout << "goodbye" << endl;
					//delete the hash table-------------------------------------------------------------
					delete newTable;

					break;
					
		}
		
	} while(menuChoice != 4);

	return 0;
}