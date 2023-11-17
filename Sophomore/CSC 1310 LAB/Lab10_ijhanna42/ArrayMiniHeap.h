#include <iostream>
#include "Creature.h"

using namespace std;

class ArrayMinHeap {
    private:
        Creature *heapArray;
        int capacity;
        int heap_size;

        void swap(int i, int j);
        int parent(int i);
        int left(int i);
        int right(int i);

    public:
        ArrayMinHeap(int capacity);
        ~ArrayMinHeap();
        void minHeapify(int i);
        bool remove(Creature& c);
        bool insert(Creature& c);
        void resizeArray();
        bool isEmpty();
        int getNumberOfNodes();
        int getHeight();
        void display();
        void saveToFile();
};