#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;


template<typename T>
class List{
    public:

        // List attributes
        struct listNode{
            T value;
            listNode* next;
            listNode* prev;

        };
        listNode* head;
        listNode* tail;

    // List constructor
    // set head and tail to null
    List() : head(nullptr), tail(nullptr) {}

    // List destructor
    ~List() {

        // traverse through each node
        while (head != nullptr) {

            // delete nodes
            listNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // print function
    void print() const {
        // call private print function and pass head as an argument
        print(head);
    }

    // append function
    void append(T value) {

        // dynamically allocate a new node
        listNode* node = new listNode{value, nullptr, tail};

        // if a list is empty, set the head and tail to a new node
        if (tail == nullptr) {
            head = node;
            tail = node;
        }

        // if a list is not empty, add the node after the tail node and move the tail pointer
        else {
            tail->next = node;
            tail = node;
        }
    }

    // mergeSort function
    void mergeSort() {

        // call the private mergesort function, passing head and tail as arguments
        head = mergesort(head, tail);

        // traverse list to find where the new tail is
        listNode* current = head;
        while (current->next != nullptr){
            current = current->next;
        }
        tail = current;
    }

    private:

        // private print function
        void print(listNode* n){

            // traverse through every node in the list, starting with the node sent through the parameter
            while (n != nullptr){

                // cout the current node at each step in the list traversal
                cout << n->data << " ";
                n = n->next;
            }
        }

        // private mergesort function
        typename List<T>::listNode* mergesort(listNode* first, listNode* last){

            // base case returns first parameter
            if (first == nullptr || first == last){
                return first;
            }

            // make node references for a placeholder, passing lower and upper bound of list partitions and sending the data to placeholder nodes
            listNode* mid = split(first, last);
            listNode* left = mergesort(first, mid);
            listNode* right = mergesort(mid, last);

            // merge and return the node that's passed from the merge function
            return merge(left, right);
        }
        
        // private merge function
        typename List<T>::listNode* merge(listNode* left, listNode* right){

            // if either parameter is null, return the remaining node reference
            if (left == nullptr){
                return right;
            }
            if (right == nullptr){
                return left;
            }

            // compare the two parameter nodes to see which should be merged next
            listNode* selected = nullptr;
            if (left->data < right->data){
                selected = left;

                // next pointer is the return value of a recursive call to merge, passing the next node of the list partition
                // previous pointer for the node is set to the selected node
                selected->next = merge(left->next, right);
            } else{
                selected = right;

                // next pointer is the return value of a recursive call to merge, passing the next node of the list partition
                // previous pointer for the node is set to the selected node
                selected->next = merge(left->next, right);
            }

            // selected node's previous pointer is set to null
            selected->prev = nullptr;

            // return the selected node
            return selected;
        }

        // private split function
        typename List<T>::listNode* split(listNode* first, listNode*last){
            listNode* slow = first;
            listNode* fast = first;

            // double traversal to meet at the middle node
            while (fast != last && fast->next != last){
                slow = slow->next;
                fast = fast->next->next;
            }

            listNode* middle = slow;

            // set middle's next pointer to null
            middle->next = nullptr;

            return middle;
        }
};

#endif