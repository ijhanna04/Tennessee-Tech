#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "hashTable.h"
using std::string;
using std::cout;

// hashTable constructor
hashTable::hashTable(int size)
{
	//you need to add everything else that belongs in the constructor--------------------------------------
	// dynamically allocate a new array of entry pointers
	hashArray = new entry*[size];

	// set every array element to null
	for (int i = 0; i < size; i++){
		hashArray[i] = nullptr;
	}

	srand (time(0));	//this needs to be in the constructor, otherwise every user gets the same salt
}

// hashTable destructor
hashTable::~hashTable(){

	// loop through the array
	for (int i = 0; i < tableSize; i++){

		// delete the linked list in every bucket
		entry* current = hashArray[i];
		while (current != nullptr){
			entry* temp = current;
			current = current->next;
			delete temp;
		}
	}
}

//don't touch this!
int hashTable::hash(string key)
{
	int sum = 0;
	for(int i = 0; i < key.size(); i++)
		sum += key[i];
	
	return sum % tableSize;
}

//don't touch this!
string hashTable::generateSalt()
{
	string s = "";
	
	for(int i = 0; i < tableSize; i++)
		s = s + char('!' + (rand() % 93));
	return s;
}

// getSalt function
string hashTable::getSalt(string user){

	// call the getEntry function to find the user associated with the parameter key
	entry* entry = getEntry(user);

	// call the getSalt function for the user
	entry->getSalt();

	// think about what needs to happen if that user isn't in the table
}

// addEntry function
void hashTable::addEntry(string username, string password, string salt){

	// call the hash function to determine which bucket the new user will be stored in
	int index = hash(username);
	if (hashArray[index] == nullptr){
		hashArray[index] = new entry(username, password, salt);
		return;
	}

	// dynamically allocate a new entry and add it to the list in the specified bucket
	entry* current = hashArray[index];

	// check that the usernmae doesn't already exist
	while (current != nullptr){
		if (current->getUsername() == username){
			return;
		}
		if (current->next == nullptr){
			current->next = new entry(username, password, salt);
			return;
		}
		current = current->next;
	}
}

// validateLogin function
bool hashTable::validateLogin(string username, string password){

	// call the getEntry function
	entry* entry = getEntry(username);
	if (entry == nullptr) {
		return false;
	}

	// check if the password hash sent matches the saved password hash
	return entry->getHashedpwd() == password;
}

// removeUser function
bool hashTable::removeUser(string username, string password){

	// find the user trying to remove themself
	entry* user = getEntry(username);
	if (user = nullptr){
		return false;
	}

	// verify the login credentials of the user
	if (user->getHashedpwd() != password){
		return false;
	}

	int index = hash(username);

	entry* current = hashArray[index];
	entry* prev = nullptr;

	// remove the specified user entry from the table
	while (current != nullptr){
		if (current == user){
			if (prev == nullptr){
				hashArray[index] = current->next;
			} else{
				prev->next = current->next;
			}
			delete current;
			return true;
		}
		prev = current;
		current = current->next;
	}

	return false;
}

// getEntry function
hashTable::entry* hashTable::getEntry(string key){

	// apply the hash function to the key
	int index = hash(key);
	if (hashArray[index] == nullptr){
		return nullptr;
	}

	// traverse the list in the bucket until the node with the matching key is found
	entry* current = hashArray[index];
	while (current != nullptr){
		if (current->getUsername() == key){

			// return the node once found
			return current;
		}
		current = current->next;
	}
	return nullptr;
}

// entry constructor
hashTable::entry::entry(string username, string salt, string hashedpwd){

	// assign each attribute to the given parameter
	this->uname = username;
	this->salt = salt;
	this->passHash = hashedpwd;

	//set the next pointer to null
	this->next = nullptr;
}

// entry getUsername function
string hashTable::entry::getUsername(){

	// return the username
	return uname;
}

// entry getSalt function
string hashTable::entry::getSalt(){

	// return the salt for hashing the password
	return salt;
}

// entry getHashedpwd function
string hashTable::entry::getHashedpwd(){

	// return the hashed password
	return passHash;
}