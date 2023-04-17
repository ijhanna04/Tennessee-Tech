#include "ijhanna42_prog4.h"

int loadMonstersFromFile(int numCurrentMonsters, Monsters monster[]){
    string monsterData;
    ifstream infile;

    //ask user what the name of the file is that they would like to load the monsters from
    cout << "What is the name of the file with your monster data? (ex: filename.txt)\n";
    cout << "FILENAME: ";
    cin >> monsterData;

    //open user selected file
    infile.open(monsterData);

    //check if file could open before reading from it
    if(infile.is_open()){
        if (numCurrentMonsters >= maxCapacity){
            cout << "No more monsters can be registered at this time. Zoo is at full capacity.";
        }else {           
            for(int i; i < maxCapacity; i++){
                i = numCurrentMonsters + 1;

                //check to make sure the number of monsters is not already 75
                if (numCurrentMonsters >= maxCapacity){

                    //tell user that zoo is at full capacity
                    cout << "No more monsters can be registered at this time. Zoo is at full capacity.";

                    //end function
                    return 0;
                }

                //read each monster from the file and place the data in the correct element in the Monster array

                //print the name of the monster added
                cout << monster[i].name << " has been added.";

                //increment the number of monsters
                numCurrentMonsters++;
            
            }
            cout << "All creatures from " << monsterData << "have been added to the program.\n";

            //return the updated number of monsters loaded into the array
            
        }
    }
    return numCurrentMonsters;

}

int registerMonster(int numCurrentMonsters, Monsters monster[]){

//check to make sure the number of monsters is not already 75
if (numCurrentMonsters >= maxCapacity){

    //tell user that zoo is at full capacity
    cout << "No more monsters can be registered at this time. Zoo is at full capacity.";

    //end function
    return 0;

} else {
    int i = numCurrentMonsters + 1;
    //check to make sure the number of monsters is not already 75
    if (numCurrentMonsters >= maxCapacity){

        //tell user that zoo is at full capacity
        cout << "No more monsters can be registered at this time. Zoo is at full capacity.";

        //end function
        return 0;
    }

    //ask user for Monster variables
    cout << "NAME: ";
    cin >> monster[i].name;
    cout << "DESCRIPTION: ";
    cin >> monster[i].description;
    cout << "WEIGHT (in pounds): ";
    cin >> monster[i].weight;
        //validate that weight is over zero pounds
        while(monster[i].weight <= 0){
            cout << "Invalid Weight. Enter a Weight greater than 0: ";
            cin >> monster[i].weight;
        }
    cout << "HEIGHT (in feet): ";
    cin >> monster[i].height;
        //validate that height is taller than zero feet
        while(monster[i].height <= 0){
            cout << "Invalid Height. Enter a Height greater than 0: ";
            cin >> monster[i].height;
        }
    cout << "LAST KNOWN LOCATION: ";
    cin >> monster[i].location;
    cout << "DANGER LEVEL (1-5): ";
    cin >> monster[i].dangerLevel;
        //validate that level is 1 through 5
        while((monster[i].dangerLevel < 1) || (monster[i].dangerLevel > 5)){
            cout << "Invalid Danger Level. Enter a Danger Level between 1 and 5: ";
            cin >> monster[i].dangerLevel;
        }
    cout << "CARE INFORMATION (per week):\n";
    cout << "        Required direct care for monster (in hours) ";
    cin >> monster[i].cData.numCareHours;
        //validate that input is not negative
        while(monster[i].cData.numCareHours < 0){
            cout << "Invalid Number of Care Hours. Enter a positive number of Care Hours: ";
            cin >> monster[i].cData.numCareHours;
        }
    cout << "        Cost of care $";
    cin >> monster[i].cData.costPerHour;
        //validate that input is not negative
        while(monster[i].cData.costPerHour < 0){
            cout << "Invalid Cost per Hour. Enter a positive Cost per Hour: ";
            cin >> monster[i].cData.costPerHour;
        }
    cout << "        Food cost $";
    cin >> monster[i].cData.foodCost;
        //validate that input is not negative
        while(monster[i].cData.foodCost < 0){
            cout << "Invalid Food Cost. Enter a positive Food Cost: ";
            cin >> monster[i].cData.foodCost;
        }
    cout << "        Medical & grooming cost $";
    cin >> monster[i].cData.materialCost;
        //validate that input is not negative
        while(monster[i].cData.materialCost < 0){
            cout << "Invalid Medical & Grooming Cost. Enter a positive Medical & Grooming Cost: ";
            cin >> monster[i].cData.materialCost;
        }

    //increment the number of current monsters in the zoo by one
    numCurrentMonsters++;

    //return the number of monsters
    return numCurrentMonsters;
}
}

int removeMonster(int numCurrentMonsters, Monsters monster[]){

    cout << "The following is a list of all the monsters in the zoo:\n";

    //print name of each monster
    for (int i; i < numCurrentMonsters; i++){
        cout << monster[i].name << endl;
    }

    //ask user which monster is leaving the zoo
    cout << "What monster is leaving the zoo?;\n";
    cout << "MONSTER NAME: ";

    //read the name and place it in a temporary string variable
    string nameDelete;
    cin >> nameDelete;

    //find index of the monster that needs to be removed with a name match
    for (int i; i < numCurrentMonsters; i++){
        if (nameDelete == monster[i].name){

            //overwrite element with the next element in the array


            //decrement the number of monsters in the zoo and print out name of monster deleted
            numCurrentMonsters--;
            cout << "You have removed " << nameDelete;
            
        } else {

            //if the monster with the given name was not found, inform user
            cout << "Sorry, a monster by the name " << nameDelete << " could not be found.";
        }
    }

    //return the new number of monsters
    return numCurrentMonsters;

}

void printMonsters(int numCurrentMonsters, Monsters monster[]){

    string lineOfDashes(50, '-');

    //if there are no monsters in the zoo, inform user
    if (numCurrentMonsters < 1){
        cout << "THERE ARE NO MONSTERS AT YOUR ZOO!";

    } else {
        //print out monster info
        for (int i; i < numCurrentMonsters; i++){
            cout << lineOfDashes << endl;
            cout << "**MONSTER " << i+1 << "**\n";
            cout << "Name: " << monster[i].name;
            cout << "Description: " << monster[i].description;
            cout << "Weight: " << monster[i].weight;
            cout << "Height: " << monster[i].height;
            cout << "Last known location: " << monster[i].location;
            cout << "Danger level: " << monster[i].dangerLevel;
            cout << "Weekly Care Information:\n";
            cout << "        -Hours of care required: " << right << monster[i].cData.numCareHours;
            cout << "        -Cost of care: " << right << monster[i].cData.costPerHour;
            cout << "        -Food cost: " << right << monster[i].cData.foodCost;
            cout << "        -Grooming & Supplies Cost: " << right << monster[i].cData.materialCost;
            
        }
    }

}

void printCostInfo(int numCurrentMonsters, Monsters monster[]){
    double careCost[numCurrentMonsters];
    double totalCost = 0.0;

    //if there are no monsters in the zoo, inform user
    if (numCurrentMonsters == 0){
        cout << "There are no monsters in the zoo so the total cost is $0.00";

    } else {

        cout << "MONSTER" << right << "CARE COST";
        for (int i; i < numCurrentMonsters; i++){

            //calculation for care cost
            careCost[i] = monster[i].cData.numCareHours * monster[i].cData.costPerHour + monster[i].cData.foodCost + monster[i].cData.materialCost;
            
            //print total cost for each monster
            cout << monster[i].name << right << "$" << careCost[i] << endl;

            //running total for total cost of all the monsters
            totalCost = totalCost + careCost[i];
        }

        //print total cost to care for all the monsters
        cout << "TOTAL COST" << right << "$" << totalCost;
    }

}

void saveMonstersToFile(int numCurrentMonsters, Monsters monster[]){
    string filename;
    ofstream outfile;

    //if there are no monsters in the zoo, inform user that there is nothing to be saved
    if (numCurrentMonsters == 0){
        cout << "There are no monsters in the zoo so none can be saved to a file.";
    } else {

        //ask user what the name of the file is that they should save their monsters to
        cout << "What is the name of the file you want to save your creatures to?\n";
        cout << "FILENAME: ";
        cin >> filename;

        //open file of the given name
        outfile.open(filename);

        //write monster data to file
        for (int i; i < numCurrentMonsters; i++){
            outfile << monster[i].name << "#";
            outfile << monster[i].description << "#";
            outfile << monster[i].weight << "#";
            outfile << monster[i].height << "#";
            outfile << monster[i].location << "#";
            outfile << monster[i].cData.numCareHours << "#";
            outfile << monster[i].cData.costPerHour << "#";
            outfile << monster[i].cData.foodCost << "#";
            outfile << monster[i].cData.materialCost << "#";
        }

        outfile.close();

        //print confirmation of file save
        cout << "All monsters currently housed in the zoo were successfully saved to the " << filename << " file.";
    }
}