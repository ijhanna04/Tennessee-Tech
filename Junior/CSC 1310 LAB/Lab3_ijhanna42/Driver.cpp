#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

struct wordCount{
	string word;
	int count;
};

void insertionSort(wordCount *wordArray, int numWords);
void bubbleSortReverse(wordCount *wordArray, int numWords);
void quicksort(wordCount *wordArray, int low, int high);
int partition(wordCount *wordArray, int left, int right);

int main()
{
	wordCount* wordArray = new wordCount[150000];
	int numWords = 0;
	string temp;
	int num;
	
	ofstream outfile;
	ifstream infile;

	time_t start, end;
	char filename[50];
	cout << "\nWhich file are you opening?\n";
	cin >> filename;
	infile.open(filename);
	
	if(!infile)
	{
		cout << "\nSorry, I couldn't find that file.\n";
		return 1;
	}

	while(getline(infile, temp) && numWords != 150000)
	{
		wordArray[numWords].word = temp;
		infile >> num;
		infile.ignore();
		wordArray[numWords].count = num;
		numWords++;
	}
	cout << "you've read in " << numWords << " words.\n";

	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   

	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	insertionSort(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 

	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	bubbleSortReverse(wordArray, numWords);

	end = getTime(); //Ends timer.
	outfile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();

	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	int low = 0;
	int high = numWords - 1;
	quickSort(wordArray, low, high);

	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outfile.open("sortFileQuick.txt");
	for(int x=0; x<numWords; x++)
	{
		outfile << wordArray[x].word << " : " << wordArray[x].count << endl;
	}
	outfile.close();
	
	delete [] wordArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(wordCount *arrWord, int wordNum){
	int i, key, j;
	for (i = 1; i < wordNum; i++){
		key = arrWord[i].count;
		j = i-1;

		while (j >= 0 && arrWord[j].count > key){
			arrWord[j+1] = arrWord[j];
			j = j-1;
		}

		arrWord[j+1].count = key;
	}
}

//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void bubbleSortReverse(wordCount *arrWord, int wordNum){
    for(int i = 0; i < wordNum-1; i++) {
        for(int j = 0; j < wordNum-i-1; j++) {
            if(arrWord[j].count < arrWord[j+1].count) {
                int temp = arrWord[j].count;
                arrWord[j] = arrWord[j+1];
                arrWord[j+1].count = temp;
            }
        }
    }
}

//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(wordCount *arrWord, int lowNum, int highNum){
    if (lowNum < highNum){
        int pi = partition(arrWord, lowNum, highNum);
        quickSort(arrWord, lowNum, pi - 1);
        quickSort(arrWord, pi + 1, highNum);
    }
}

void swap(wordCount* a, wordCount* b) {
    wordCount t = *a;
    *a = *b;
    *b = t;
}

//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(wordCount *arrWord, int leftNum, int rightNum){
	int pivot = arrWord[rightNum].count;
    int i = (leftNum - 1);

    for (int j = leftNum; j <= rightNum - 1; j++){
        if (arrWord[j].count <= pivot){
            i++;
            swap(&arrWord[i], &arrWord[j]);
        }
    }
    swap(&arrWord[i + 1], &arrWord[rightNum]);
    return (i + 1);
}
