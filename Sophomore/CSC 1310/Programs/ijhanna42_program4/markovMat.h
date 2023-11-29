#ifndef MARKOVMAT_H
#define MARKOVMAT_H

#include<map>
#include<fstream>
#include<sstream>
#include<iostream>
#include<stdlib.h>
using namespace std;

class markovMat
{
	private:
		struct matrix{
			map<string, int> buckets;
		};
		matrix corpus;
		int corpusSize;
	public:
		markovMat(const char*);
		~markovMat();
		
		string generate(int);
};

markovMat::markovMat(const char* filename)
{
	ifstream file(filename);
	stringstream* parser;
	stringstream splitter;
	string line, word;
	float weight;
	int i = 0;
	srand (time(0));
	
	if(file.good()) {
	file >> corpusSize;
	file.ignore(1, '\n');
	//allocate memory for the matrix and set every value to 0---

	parser = new stringstream[corpusSize];
	
	while(getline(file, line, '\n')) //map every word to a position in the matrix, keep the line in an array of buffers for later
	{
		parser[i] << line;
		getline(parser[i], word,',');
		//assign an index number to the map for the current word
		corpus.buckets[word] = 0;
		i++;
	}
	for(i = 0; i < corpusSize; i++) //populate matrix using buffer array
	{
		while(getline(parser[i], word, ','))
		{
			splitter.clear();
			splitter.str(word);
			splitter >> word >> weight;
			//add weight into the matrix, with the first index as the starting node and the second index at the destination node
			corpus.buckets[parser[i].str()] = weight;
		}
	}}
}

markovMat::~markovMat()
{
//write this

}

string markovMat::generate(int length)
{
	//pick random starting node
	map<string, int>::iterator it = corpus.buckets.begin();		//initialize an iterator to find a random node in the next line
	advance(it,rand() % corpusSize);	//this grabs a random node from your corpus as a starting point
//you'll need to write the rest of this
    string current_word = it->first;
    string output = current_word;

    for (int i = 0; i < length; i++) {
        float rand_num = (float)rand() / RAND_MAX;
        float sum = 0;
        map<string, int>::iterator it2 = corpus.buckets.begin();
        while (it2 != corpus.buckets.end()) {
            sum += it2->second;
            if (rand_num < sum) {
                current_word = it2->first;
                output += " " + current_word;
                break;
            }
            it2++;
        }
    }

    return output;
}

#endif
