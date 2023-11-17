#include "Creature.h"

using namespace std;

class ArrayMiniHeap{
    private:
        Creature *heapArray;
        int capacity;
        int heap_size;

        void swap(Creature &a, Creature &b){
            Creature temp = a;
            a = b;
            b = temp;
        }

        int parent(int i){
            return (i - 1) / 2;
        }

        int left(int i){
            return 2 * i + 1;
        }

        int right(int i){
            return 2 * i + 2;
        }

    public:
        ArrayMiniHeap::ArrayMiniHeap(int capacity){
            this->capacity = capacity;
            heapArray = new Creature[capacity];
            heap_size = 0;
        }

        ArrayMiniHeap::~ArrayMiniHeap(){
            delete[] heapArray;
        }

        void ArrayMiniHeap::miniHeapify(int i){
            int l = left(i);
            int r = right(i);
            int smallest = i;

            if (l < heap_size && heapArray[l].getName() < heapArray[i].getName()){
                smallest = l;
            }

            if (r < heap_size && heapArray[r].getName() < heapArray[smallest].getName()){
                smallest = r;
            }

            if (smallest != i){
                swap(heapArray[i], heapArray[smallest]);
                miniHeapify(smallest);
            }
        }

        bool ArrayMiniHeap::remove(Creature &creature){
            if (heap_size == 0){
                return false;
            }

            creature = heapArray[0];
            heapArray[0] = heapArray[heap_size - 1];
            heap_size--;
            miniHeapify(0);

            return true;
        }

        void ArrayMiniHeap::insert(Creature creature){
            if (heap_size == capacity){
                Creature *temp = new Creature[capacity * 2];
                for (int i = 0; i < capacity; i++){
                    temp[i] = heapArray[i];
                }
                delete [] heapArray;
                heapArray = temp;
                capacity *= 2;
            }

            heap_size++;
            int i = heap_size - 1;
            heapArray[i] = creature;

            while (i != 0 && heapArray[parent(i)].getName() > heapArray[i].getName()) {
                swap(heapArray[i], heapArray[parent(i)]);
                i = parent(i);
            }
        }

        void ArrayMiniHeap::resizeArray(){
            Creature *temp = new Creature[capacity * 2];
            for (int i = 0; i < capacity; i++){
                temp[i] = heapArray[i];
            }

            delete [] heapArray;
            heapArray = temp;
            capacity *= 2;
        }

        bool ArrayMiniHeap::isEmpty(){
            return heap_size == 0;
        }

        int ArrayMiniHeap::getNumberOfNodes(){
            return heap_size;
        }

        int ArrayMiniHeap::getHeight(){
            return ceil(log2(heap_size + 1));
        }

        void ArrayMiniHeap::display(){
            for (int i = 0; i < heap_size; i++){
                cout << heapArray[i].getName() << endl;
            }
        }

        void ArrayMiniHeap::saveToFile(){
            for (int i = 0; i < heap_size; i++){
                heapArray[i].printCreatureToFile("savedCreatures.txt");
            }
        }
};