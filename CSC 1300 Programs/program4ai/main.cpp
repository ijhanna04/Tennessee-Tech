#include "prog4.h"

int main() {
    Monster monsters[75];
    int numMonsters = 0;
    cout << "Welcome to the Monster Zoo program!" << endl;
    loadMonstersFromFile(monsters, numMonsters);
    int choice = 0;
    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Register a New Monster" << endl;
        cout << "2. Remove a Monster From Zoo" << endl;
        cout << "3. Print Monsters to Screen" << endl;
        cout << "4. Print Monster Care Cost Data" << endl;
        cout << "5. End Program" << endl;
        cout << "Enter 1, 2, 3, 4, or 5." << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                registerMonster(monsters, numMonsters);
                break;
            case 2:
                removeMonster(monsters, numMonsters);
                break;
            case 3:
                printMonsters(monsters, numMonsters);
                break;
            case 4:
                printCostInfo(monsters, numMonsters);
                break;
            case 5:
                char saveChoice = ' ';
                cout << "Do you want to save the current zoo monster data to a file? (y/n)" << endl;
                cin >> saveChoice;

                if (saveChoice == 'y') {
                    saveMonstersToFile(monsters, numMonsters);
                }

                break;
        }
    } while (choice != 5);

    return 0;
}