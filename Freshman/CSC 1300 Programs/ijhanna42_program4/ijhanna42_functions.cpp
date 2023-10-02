#include "ijhanna42_prog4.h"

int loadMonstersFromFile(int numCurrentMonsters, Monsters monster[]){
    string monsterData;

    //ask user what the name of the file is that they would like to load the monsters from
    cout << "What is the name of the file with your monster data? (ex: filename.txt)" << endl;
    cout << "FILENAME: ";
    cin >> monsterData;
    cout << endl ;

    //open user selected file
    ifstream infile(monsterData);

    //check if file could open before reading from it
    if(!infile.is_open()){
        cout << "Could not open file." << endl;
        return numCurrentMonsters;
    }

    //make sure there are no more monsters than the maxCapacity
    string line;
    while (getline(infile, line, '#')){
        if (numCurrentMonsters >= maxCapacity){
            cout << "No more monsters can be registered at this time. Zoo is at full capacity." << endl;
            break;

        }       

        //read each monster from the file and place the data in the correct element in the Monster array
        string temp;

        monster[numCurrentMonsters].name = line;

        getline(infile, temp, '#');
        monster[numCurrentMonsters].description = temp;

        getline(infile, temp, '#');
        monster[numCurrentMonsters].weight = stod(temp);

        getline(infile, temp, '#');
        monster[numCurrentMonsters].height = stod(temp);

        getline(infile, temp, '#');
        monster[numCurrentMonsters].location = temp;

        getline(infile, temp, '#');
        monster[numCurrentMonsters].dangerLevel = stoi(temp);

        getline(infile, temp, '#');
        monster[numCurrentMonsters].cData.numCareHours = stod(temp);

        getline(infile, temp, '#');
        monster[numCurrentMonsters].cData.costPerHour = stod(temp);

        getline(infile, temp, '#');
        monster[numCurrentMonsters].cData.foodCost = stod(temp);

        getline(infile, temp, '#');
        monster[numCurrentMonsters].cData.materialCost = stod(temp);

        //print the name of the monster added
        cout << monster[numCurrentMonsters].name << " has been added." << endl;

        //increment the number of monsters
        numCurrentMonsters++;
        
        
    }
    
    infile.close();
    cout << endl << "All creatures from " << monsterData << " have been added to the program." << endl;

    //return the updated number of monsters loaded into the array
    return numCurrentMonsters;

}

int registerMonster(int numCurrentMonsters, Monsters monster[]){

    //check to make sure the number of monsters is not already 75
    if (numCurrentMonsters >= maxCapacity){

        //tell user that zoo is at full capacity
        cout << "No more monsters can be registered at this time. Zoo is at full capacity.";

        //end function
        return numCurrentMonsters;

    } else {

        //check to make sure the number of monsters is not already 75
        if (numCurrentMonsters >= maxCapacity){

            //tell user that zoo is at full capacity
            cout << "No more monsters can be registered at this time. Zoo is at full capacity.";

            //end function
            return numCurrentMonsters;
        }

        //ask user for Monster variables
        Monsters newMonster;
        cout << endl << "NAME: ";
        cin.ignore();
        getline(cin, newMonster.name);

        cout << "DESCRIPTION: ";
        getline(cin, newMonster.description);

        newMonster.weight = 0;
        cout << "WEIGHT (in pounds): ";
        cin >> newMonster.weight;
            //validate that weight is over zero pounds
            while(newMonster.weight <= 0){
                cout << "Invalid Weight. Enter a Weight greater than 0: ";
                cin >> newMonster.weight;
            }

        cout << "HEIGHT (in feet): ";
        cin >> newMonster.height;
            //validate that height is taller than zero feet
            while(newMonster.height <= 0){
                cout << "Invalid Height. Enter a Height greater than 0: ";
                cin >> newMonster.height;
            }

        cout << "LAST KNOWN LOCATION: ";
        cin.ignore();
        getline(cin, newMonster.location);

        cout << "DANGER LEVEL (1-5): ";
        cin >> newMonster.dangerLevel;
            //validate that level is 1 through 5
            while((newMonster.dangerLevel < 1) || (newMonster.dangerLevel > 5)){
                cout << "Invalid Danger Level. Enter a Danger Level between 1 and 5: ";
                cin >> newMonster.dangerLevel;
            }

        cout << endl << "CARE INFORMATION (per week):" << endl;

        cout << "        Required direct care for monster (in hours) ";
        cin >> newMonster.cData.numCareHours;
            //validate that input is not negative
            while(newMonster.cData.numCareHours < 0){
                cout << "Invalid Number of Care Hours. Enter a positive number of Care Hours: ";
                cin >> newMonster.cData.numCareHours;
            }

        cout << "        Cost of care $ ";
        cin >> newMonster.cData.costPerHour;
            //validate that input is not negative
            while(newMonster.cData.costPerHour < 0){
                cout << "Invalid Cost per Hour. Enter a positive Cost per Hour: $ ";
                cin >> newMonster.cData.costPerHour;
            }

        cout << "        Food cost $ ";
        cin >> newMonster.cData.foodCost;
            //validate that input is not negative
            while(newMonster.cData.foodCost < 0){
                cout << "Invalid Food Cost. Enter a positive Food Cost: $ ";
                cin >> newMonster.cData.foodCost;
            }

        cout << "        Medical & grooming cost $ ";
        cin >> newMonster.cData.materialCost;
            //validate that input is not negative
            while(newMonster.cData.materialCost < 0){
                cout << "Invalid Medical & Grooming Cost. Enter a positive Medical & Grooming Cost: $ ";
                cin >> newMonster.cData.materialCost;
            }

        monster[numCurrentMonsters] = newMonster;

        //increment the number of current monsters in the zoo by one
        numCurrentMonsters++;

        cout << endl << newMonster.name << " has been added." << endl;

        //return the number of monsters
        return numCurrentMonsters;
    }
}

int removeMonster(int numCurrentMonsters, Monsters monster[]){

    cout << endl << "The following is a list of all the monsters in the zoo:" << endl;

    //print name of each monster
    for (int i = 0; i < numCurrentMonsters; i++){
        cout << monster[i].name << endl;
    }

    //ask user which monster is leaving the zoo
    string nameDelete;
    cout << "\nWhat monster is leaving the zoo?" << endl;
    cout << "\nMONSTER NAME: ";

    //read the name and place it in a temporary string variable
    cin.ignore();
    getline(cin, nameDelete);

    //find index of the monster that needs to be removed with a name match
    int indexToDelete = -1;
    for (int i = 0; i < numCurrentMonsters; i++){
        if (monster[i].name == nameDelete){
            indexToDelete = i;
            break;
        }
    }

    //if the monster with the given name was not found, inform user
    if (indexToDelete == -1) {
        cout << endl << "Sorry, a monster by the name " << nameDelete << " could not be found." << endl;
        return numCurrentMonsters;
    }

    //overwrite element with the next element in the array
    for (int i = indexToDelete; i < numCurrentMonsters - 1; i++) {
        monster[i] = monster[i + 1];
    }

    //decrement the number of monsters in the zoo and print out name of monster deleted
    numCurrentMonsters--;
    cout << endl << "You have removed " << nameDelete << "." << endl;

    //return the new number of monsters
    return numCurrentMonsters;

}

void printMonsters(int numCurrentMonsters, Monsters monster[]){

    string lineOfDashes(50, '-');

    //if there are no monsters in the zoo, inform user
    if (numCurrentMonsters == 0){
        cout << "THERE ARE NO MONSTERS AT YOUR ZOO!" << endl;

    } else {
        //print out monster info
        for (int i = 0; i < numCurrentMonsters; i++){
            cout << endl << lineOfDashes << endl;
            cout << "**MONSTER " << i + 1 << "**" << endl;
            cout << "Name: " << monster[i].name << endl;
            cout << "Description: " << monster[i].description << endl;
            cout << "Weight: " << fixed << setprecision(2) << monster[i].weight << endl;
            cout << "Height: " << fixed << setprecision(2) << monster[i].height << endl;
            cout << "Last known location: " << monster[i].location << endl;
            cout << "Danger level: " << monster[i].dangerLevel << endl;
            cout << "Weekly Care Information:" << endl;
            cout << "        -Hours of care required:      " << fixed << setprecision(2) << monster[i].cData.numCareHours << endl;
            cout << "        -Cost of care:                $ " << fixed << setprecision(2) << monster[i].cData.costPerHour << endl;
            cout << "        -Food cost:                   $ " << fixed << setprecision(2) << monster[i].cData.foodCost << endl;
            cout << "        -Grooming & Supplies Cost:    $ " << fixed << setprecision(2) << monster[i].cData.materialCost << endl;    
        }
    }
}

void printCostInfo(int numCurrentMonsters, Monsters monster[]){

    //if there are no monsters in the zoo, inform user
    if (numCurrentMonsters == 0){
        cout << endl << "There are no monsters in the zoo so the total cost is $0.00\n";
        return;

    } else {

        double totalCost = 0.0;

        cout << endl << "COST OF EACH MONSTER FOR ONE WEEK: " << endl << endl;

        cout << setw(30) << left << "MONSTER" << setw(21) << right << "CARE COST" << endl;
        for (int i = 0; i < numCurrentMonsters; i++){

            //calculation for careCost and totalCost
            double careCost = monster[i].cData.numCareHours * monster[i].cData.costPerHour + monster[i].cData.foodCost + monster[i].cData.materialCost;
            totalCost += careCost;

            //print total cost for each monster
            cout << setw(30) << left << monster[i].name  << "$" << setw(20) << right << fixed << setprecision(2) <<  careCost << endl;
        }

        //print total cost to care for all the monsters
        cout << endl << setw(30) << left << "TOTAL COST"  << "$" << setw(20) << right << fixed << setprecision(2) << totalCost;
    }

}

void saveMonstersToFile(int numCurrentMonsters, Monsters monster[]){

    //if there are no monsters in the zoo, inform user that there is nothing to be saved
    if (numCurrentMonsters == 0){
        cout << endl << "There are no monsters in the zoo so none can be saved to a file." << endl;
        return;
    } 

    string filename;

    //ask user what the name of the file is that they should save their monsters to
    cout << "What is the name of the file you want to save your creatures to?" << endl;
    cout << "FILENAME: ";
    cin >> filename;

    //open file of the given name
    ofstream outfile(filename);
    if (!outfile){
        cout << endl << "Error opening file " << filename << endl;
        return;
    }

    //write monster data to file
    for (int i = 0; i < numCurrentMonsters; i++){
        outfile << monster[i].name << "#"
        << monster[i].description << "#"
        << monster[i].weight << "#"
        << monster[i].height << "#"
        << monster[i].location << "#"
        << monster[i].dangerLevel << "#"
        << monster[i].cData.numCareHours << "#"
        << monster[i].cData.costPerHour << "#"
        << monster[i].cData.foodCost << "#"
        << monster[i].cData.materialCost << "#";

    }

    outfile.close();

    //print confirmation of file save
    cout << endl << "All monsters currently housed in the zoo were successfully saved to the " << filename << " file." << endl;
    cout << endl << endl << "GOODBYE!";
}