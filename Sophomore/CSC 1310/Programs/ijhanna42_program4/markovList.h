#ifndef MARKOVLIST_H
#define MARKOVLIST_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct edge{
	string word;
	float weight;
	edge* next;
};

class markovList
{
	private:
		map<string, edge*> corpus;
		int corpusSize;
	public:
		markovList(const char*);
		~markovList();
		
		string generate(int);
};

markovList::markovList(const char* filename)
{
	ifstream file(filename);
	stringstream parser, splitter;
	string line, index, word;
	float weight;
	edge* newEdge;
	int i = 0;
	srand (time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');
	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		parser.clear();
		parser << line;
		getline(parser, index,',');	//pulls the first word of the line, which is the node for which we're making a list of neighbors
		//initialize an empty list at the index---
		newEdge = new edge;
		corpus[index] = newEdge;

		while(getline(parser, word, ','))
		{
			//allocate a new node in the edge list---
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//stick word and weight on the node you've just allocated---
			newEdge->word = word;
			newEdge->weight = weight;
			
			//make sure your new node is attached to the list---
			newEdge->next = corpus[index];
			corpus[index] = newEdge;
		}
	}
	}
}

markovList::~markovList()
{
//write this
	map<string, edge*>::iterator it;
	for(it = corpus.begin(); it != corpus.end(); it++){
		delete it->second;
	}
}
		
string markovList::generate(int length)
{
	map<string, edge*>::iterator it = corpus.begin();	//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
//write the rest of this
    string output = it->first;
    for (int i = 1; i < length; i++) {
		
		// make a random roll to determine which node it traverses to
        float roll = (float)rand()/RAND_MAX;
        float sum = 0;
        edge* current = it->second;
        while (current != NULL) {
            sum += current->weight;

			// check the roll value against the weight of every edge
			// if the random value is less than the weight of the edge, do a traversal to the node
            if (sum > roll) {
                output += " " + current->word;
                it = corpus.find(current->word);
                break;
            }
            current = current->next;
        }
    }
    return output;
}

#endif