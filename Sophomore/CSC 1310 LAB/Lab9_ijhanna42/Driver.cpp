#include <iostream>
#include <fstream>
#include <string>
#include "GraphList.h"
using namespace std;

int main() {

    // open graph.txt
    ifstream file("graph.txt");

    int numVertices, vertex1, vertex2;

    // read the number of vertices
    file >> numVertices;
    cout << "There are " << numVertices << " vertices in the graph." << endl << endl;

    // create adjacency list object based on the number of vertices
    GraphList graph(numVertices);

    // use a loop to read from the file the edges
    while (file >> vertex1 >> vertex2) {

        // add the edges to the adjacency list
        graph.addEdge(vertex1, vertex2);

        // print what edge is being added
        cout << "Adding an edge from " << vertex1 << " to " << vertex2 << "." << endl;
    }

    // print the adjacency list
    graph.printGraph();

    return 0;
}