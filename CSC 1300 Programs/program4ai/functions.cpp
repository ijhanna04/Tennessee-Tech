#include "prog4.h"

int loadMonstersFromFile(Monster monsters[], int numMonsters) {
    string filename;
    cout << "What is the name of the file with your monster data? (ex: filename.txt)" << endl;
    cin >> filename;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error opening file." << endl;
        return numMonsters;
    }

    string line;
    while (getline(infile, line)) {
        if (numMonsters >= 75) {
            cout << "Zoo is at maximum capacity." << endl;
            break;
        }
        for (int i = 0; i < numMonsters; i++){
        stringstream ss(line);
        string temp;

        getline(ss, temp, '#');
        monsters[i].name = temp;

        getline(ss, temp, '#');
        monsters[i].description = temp;

        getline(ss, temp, '#');
        monsters[i].weightInPounds = stod(temp);

        getline(ss, temp, '#');
        monsters[i].heightInFeet = stod(temp);

        getline(ss, temp, '#');
        monsters[i].location = temp;

        getline(ss, temp, '#');
        monsters[i].dangerLevel = stoi(temp);

        getline(ss, temp, '#');
        monsters[i].cost.hoursPerWeek = stoi(temp);

        getline(ss, temp, '#');
        monsters[i].cost.costPerWeek = stod(temp);

        getline(ss, temp, '#');
        monsters[i].cost.foodCostPerWeek = stod(temp);

        getline(ss, temp, '#');
        monsters[i].cost.materialsCostPerWeek = stod(temp);


        cout << monsters[i].name << " has been added." << endl;
        numMonsters++;
        break;
    }
    }

    infile.close();
    cout << "All creatures from " << filename << " have been added to the program." << endl;

    return numMonsters;
}

int registerMonster(Monster monsters[], int numMonsters) {
    if (numMonsters >= 75) {
        cout << "Zoo is at maximum capacity." << endl;
        return numMonsters;
    }

    Monster newMonster;
    cout << "NAME: ";
    cin.ignore();
    getline(cin, newMonster.name);

    cout << "DESCRIPTION: ";
    getline(cin, newMonster.description);

    cout << "WEIGHT (in pounds): ";
    cin >> newMonster.weightInPounds;
    while (newMonster.weightInPounds <= 0) {
        cout << "Invalid weight. Please enter a weight greater than 0." << endl;
        cin >> newMonster.weightInPounds;
    }


    cout << "HEIGHT (in feet): ";
    cin >> newMonster.heightInFeet;
    while (newMonster.heightInFeet <= 0) {
        cout << "Invalid height. Please enter a height greater than 0." << endl;
        cin >> newMonster.heightInFeet;
    }

    cout << "LAST KNOWN LOCATION: ";
    cin.ignore();
    getline(cin, newMonster.location);

    cout << "DANGER LEVEL (1-5): ";
    cin >> newMonster.dangerLevel;
    while (newMonster.dangerLevel < 1 || newMonster.dangerLevel > 5) {
        cout << "Invalid danger level. Please enter a number between 1 and 5." << endl;
        cin >> newMonster.dangerLevel;
    }

    cout << endl << "CARE INFORMATION (per week):" << endl;

    cout << "\tRequired direct care for monster (in hours): ";
    cin >> newMonster.cost.hoursPerWeek;

    cout << "\tCost of care $: ";
    cin >> newMonster.cost.costPerWeek;

    cout << "\tFood cost $: ";
    cin >> newMonster.cost.foodCostPerWeek;

    cout << "\tMedical & grooming cost $: ";
    cin >> newMonster.cost.materialsCostPerWeek;

    if (newMonster.cost.hoursPerWeek < 0 || newMonster.cost.costPerWeek < 0 || 
        newMonster.cost.foodCostPerWeek < 0 || newMonster.cost.materialsCostPerWeek < 0) {
        cout << "Invalid care information. Please enter non-negative values for all four fields." << endl;
        return numMonsters;
    }

    monsters[numMonsters] = newMonster;
    numMonsters++;

    cout << endl << "The " << newMonster.name << " has been added." << endl;

    return numMonsters;
}

int removeMonster(Monster monsters[], int numMonsters) {
    cout << "The following is a list of all the monsters in the zoo:" << endl;
    for (int i = 0; i < numMonsters; i++) {
        cout << monsters[i].name << endl;
    }

    string monsterName;
    cout << endl << "What monster is leaving the zoo?" << endl;
    cout << "MONSTER NAME: ";
    cin >> monsterName;

    int indexToDelete = -1;
    for (int i = 0; i < numMonsters; i++) {
        if (monsters[i].name == monsterName) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        cout << endl << "Sorry, a monster by the name " << monsterName << " could not be found." << endl;
        return numMonsters;
    }

    for (int i = indexToDelete; i < numMonsters - 1; i++) {
        monsters[i] = monsters[i + 1];
    }

    numMonsters--;
    cout << endl << "You have removed " << monsterName << "." << endl;

    return numMonsters;
}

void printMonsters(Monster monsters[], int numMonsters) {
    if (numMonsters == 0) {
        cout << "THERE ARE NO MONSTERS AT YOUR ZOO!" << endl;
        return;
    }

    for (int i = 0; i < numMonsters; i++) {
        cout << "------------------------------------------------------------------------" << endl;
        cout << "**MONSTER " << i + 1 << "**" << endl;
        cout << "Name:    " << monsters[i].name << endl;
        cout << "Description:" << endl;
        cout << "         " << monsters[i].description << endl;
        cout << "Weight:  " << fixed << setprecision(2) << monsters[i].weightInPounds << " pound(s)" << endl;
        cout << "Height:  " << fixed << setprecision(2) << monsters[i].heightInFeet << " feet" << endl;
        cout << "Last known location:  " << monsters[i].location << endl;
        cout << "Danger level:  " << monsters[i].dangerLevel << endl;
        cout << "Weekly Care Information:" << endl;
        cout << "        -Hours of care required:        " << fixed << setprecision(2) << monsters[i].cost.hoursPerWeek << endl;
        cout << "        -Cost of care:                  $ " << fixed << setprecision(2) << monsters[i].cost.costPerWeek << endl;
        cout << "        -Food cost:                     $ " << fixed << setprecision(2) << monsters[i].cost.foodCostPerWeek << endl;
        cout << "        -Grooming & Supplies Cost:      $ " << fixed << setprecision(2) << monsters[i].cost.materialsCostPerWeek << endl;
    }
}

void printCostInfo(Monster Monsters[], int numMonsters) {
    if (numMonsters == 0) {
        cout << "There are no monsters in the zoo so the total cost is $0.00." << endl;
        return;
    }

    double totalCost = 0;
    cout << "Monster\t\tCare Cost" << endl;
    for (int i = 0; i < numMonsters; i++) {
        double careCost = Monsters[i].cost.hoursPerWeek * Monsters[i].cost.costPerWeek + Monsters[i].cost.foodCostPerWeek + Monsters[i].cost.materialsCostPerWeek;
        totalCost += careCost;
        cout << Monsters[i].name << "\t\t$" << fixed << setprecision(2) << careCost << endl;
    }
    cout << "\nTotal Cost:\t$" << fixed << setprecision(2) << totalCost << endl;
}

void saveMonstersToFile(Monster monsters[], int numMonsters) {
    if (numMonsters == 0) {
        cout << "There are no monsters in the zoo so none can be saved to a file." << endl;
        return;
    }

    string filename;
    cout << "Enter the name of the file you wish to save your monsters to: ";
    cin >> filename;

    ofstream outfile(filename);
    if (!outfile) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    for (int i = 0; i < numMonsters; i++) {
        outfile << monsters[i].name << "#" << monsters[i].description << "#" << monsters[i].weightInPounds << "#" << monsters[i].heightInFeet << "#" << monsters[i].location << "#" << monsters[i].dangerLevel << "#" << monsters[i].cost.hoursPerWeek << "#" << monsters[i].cost.costPerWeek << "#" << monsters[i].cost.foodCostPerWeek << "#" << monsters[i].cost.materialsCostPerWeek << '#';
    }

    outfile.close();
    cout << "All monsters currently housed in the zoo were successfully saved to the " << filename << " file." << endl;
}