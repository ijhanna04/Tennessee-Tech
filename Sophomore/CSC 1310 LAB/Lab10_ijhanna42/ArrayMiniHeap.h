#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ArrayMiniHeap {
    private:
        Creature *heapArray;
        int capacity;
        int heap_size;

        void swap(int i, int j) {
            Creature temp = heapArray[i];
            heapArray[i] = heapArray[j];
            heapArray[j] = temp;
        }

        int parent(int i) {
            return (i - 1) / 2;
        }

        int left(int i) {
            return 2 * i + 1;
        }

        int right(int i) {
            return 2 * i + 2;
        }

    public:
        ArrayMiniHeap(int capacity) : capacity(capacity), heap_size(0) {
            heapArray = new Creature[capacity];
        }

        ~ArrayMiniHeap() {
            delete[] heapArray;
        }

        void minHeapify(int i) {
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if (l < heap_size && heapArray[l].getName() < heapArray[i].getName()) {
                smallest = l;
            }

            if (r < heap_size && heapArray[r].getName() < heapArray[smallest].getName()) {
                smallest = r;
            }

            if (smallest != i) {
                swap(i, smallest);
                minHeapify(smallest);
            }
        }

        Creature peek() {
            return heapArray[0];
        }

        bool remove(Creature &creature) {
            if (heap_size == 0) {
                return false;
            }

            creature = heapArray[0];
            heapArray[0] = heapArray[heap_size - 1];
            heap_size--;
            minHeapify(0);

            return true;
        }

        void insert(Creature creature) {
            if (heap_size == capacity) {
                resizeArray();
            }

            heap_size++;
            int i = heap_size - 1;
            heapArray[i] = creature;

            while (i != 0 && heapArray[parent(i)].getName() > heapArray[i].getName()) {
                swap(i, parent(i));
                i = parent(i);
            }
        }

        void resizeArray(){
            Creature *newHeapArray = new Creature[capacity * 2];
            for (int i = 1; i <= heap_size; i++){
                newHeapArray[i] = heapArray[i];
            }
            delete[] heapArray;
            heapArray = newHeapArray;
            capacity *= 2;
        }

        bool isEmpty() {
            return heap_size == 0;
        }

        int getNumberOfNodes() {
            return heap_size;
        }

        int getHeight() {
            return ceil(log2(heap_size + 1));
        }

        void display() {
            for (int i = 0; i < heap_size; i++) {
                cout << heapArray[i].getName() << endl;
            }
        }

        void saveToFile() {
            ofstream file("savedCreatures.txt");
            for (int i = 0; i < heap_size; i++) {
                file << heapArray[i].getName() << endl;
            }
            file.close();
        }
};
