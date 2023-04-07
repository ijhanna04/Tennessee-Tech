#include <iostream>
#include <fstream>

using namespace std;
int main(){
    ofstream outFS;
    outFS.open("mod6b.txt");

    if (!outFS.is_open()){
        cout << "Could not open file mod6b.txt" << endl;
        return 1;
    }

    outFS << "Grape Ape\n";
    outFS << "2026\n";
    outFS << "I like to drink pickle juice";

    outFS.close();

    return 0;
}