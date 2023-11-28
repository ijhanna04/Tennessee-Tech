#include "Creature.h"
#include "ArrayMiniHeap.h"
#include <cctype>
#include <iostream>
#include <fstream>
using namespace std;

void enterMagicalCreature(ArrayMiniHeap*);
void enterMagicalCreatureFromFile(ArrayMiniHeap*);
void deleteCreature(ArrayMiniHeap*);
void printCreatures(ArrayMiniHeap*);
void saveCreaturesToFile(ArrayMiniHeap*);

int main()
{
	int choice;
	char response;

	ArrayMiniHeap creatureHeap(100);
	Creature creatureRemoved;
		
	do{
	
		cout << "\n\nWhat would you like to do?\n";
		cout << "\t1.  Enter Magical Creature\n";
		cout << "\t2.  List/Print Creatures.\n";
		cout << "\t3.  Remove Next Creature.\n";	// add option to remove next creature
		cout << "\t4.  End Program.\n";
		cout << "\tEnter 1, 2, 3, or 4.\n";
		cout << "CHOICE:  ";
		cin >> choice;
		
		while(choice < 1 || choice > 3)
		{
			cout << "\nYour choice was invalid.  Choose a number 1 through 3.\n";
			cout << "CHOICE: ";
			cin >> choice;
		}
		
		cout << endl;
		
		switch(choice)
		{
			case 1: //enter creatures
					int enterChoice;
					cout << "\n\nDo you want to enter the creature(s)\n";
					cout << "\t1.  Manually?\n";
					cout << "\t2.  From a file?\n";
					cout << "ENTER 1 or 2:  ";
					cin >> enterChoice;
					while(enterChoice < 1 || enterChoice > 2)
					{
						cout << "\nInvalid choice.  Please enter 1 or 2.\n";
						cout << "ENTER 1 or 2:  ";
						cin >> enterChoice;
					}
					if(enterChoice == 1)
						enterMagicalCreature(&creatureHeap);	
					else
						enterMagicalCreatureFromFile(&creatureHeap);
					break;
					
			case 2: printCreatures(&creatureHeap);
					break;

			case 3: 
					bool isRemoved = creatureHeap.remove(creatureRemoved);
					if (isRemoved){
						cout << "\nYou have removed " << creatureRemoved.getName() << "\n";
					} else {
						cout << "\nNo creature was removed." << endl;
					}
					break;
					
			case 4: cout << "\nWould you like to save your creature list to a file? (y or n)  ";
					cin >> response;
					if(tolower(response) == 'y')
						saveCreaturesToFile(&creatureHeap);
					cout << "\n\nGOODBYE!\n";
					
		} //end of switch
		
	}while(choice != 3);
	
	return 0;
} //end of main

void enterMagicalCreature(ArrayMiniHeap *creatureHeap)
{
	string name, desc;
	float cost;
	bool dangerous;
	char response;
	int creaturePosition;
	
	do{
		cout << "\nNAME: ";
		cin.ignore();
		getline(cin, name);
		
		cout << "\nDESCRIPTION:  ";
		getline(cin, desc);
		
		cout << "\nIS IT A DANGEROUS CREATURE? (y or n):  ";
		cin >> response;
		if(tolower(response) == 'y')
			dangerous = true;
		else
			dangerous = false;
		
		cout << "\nCOST PER MONTH TO CARE FOR CREATURE:  ";
		cin >> cost;
	
		//create a creature
		Creature newCreature(name, desc, dangerous, cost); 
		
		//insert creature in the tree
		creatureHeap->insert(newCreature);

		cout << "\n\nWant to add more creatures? (y or n)  ";
		cin >> response;
		
	}while(tolower(response) == 'y');	
}

void enterMagicalCreatureFromFile(ArrayMiniHeap *creatureHeap)
{
	ifstream inputFile;
	char filename[100];
	cout << "\n\nWhat is the name of the file you want to read from?\n";
	cout << "FILENAME:  ";
	cin.ignore();
	cin.getline(filename, 100);
	
	inputFile.open(filename);
	if(inputFile.fail())
	{
		cout << filename << " does not exist or is corrupt.  Sorry.  Can't load creatures.\n";
	}
	else
	{
		string temp, name, desc;
		float cost;
		bool dangerous;
		char response;
		int numCreatures = 0;
		//load creatures from file
					
		//read first creature name to see if one exists
		getline(inputFile, temp);

		while(!inputFile.eof())  //if we are not at the end of the file, proceed
		{
			name = temp;
			getline(inputFile, desc);
			
			inputFile >> dangerous;
			inputFile >> cost;
			inputFile.ignore();
			
			//create a creature
			Creature newCreature(name, desc, dangerous, cost); 

			//insert creature in the tree
			creatureHeap->insert(newCreature);
			
			numCreatures++;
			//start reading next line with new creature.						
			getline(inputFile, temp);
			
		}
		
		inputFile.close();
		inputFile.clear();
		
		cout << "\n" << numCreatures << " creatures from " << filename << " have been read from the file.\n";
		
	}
}

void printCreatures(ArrayMiniHeap *creatureHeap)
{
	creatureHeap->display();
}

void saveCreaturesToFile(ArrayMiniHeap *creatureHeap)
{
	string filename;
	Creature tempCreature;
	
	if(creatureHeap->getNumberOfNodes() == 0)
	{
		cout << "------------------------------------------------------------------------" << endl;
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!\n";
		cout << endl;
	}
	else
	{
		creatureHeap->saveToFile();
	}
}
