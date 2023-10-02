/*****************************************************************
	Title:  		List.h
	Date:           10-03-2023
	Author: 		Ian Hanna
	Purpose:		CSC 1310 Lab 4 List File
******************************************************************/

#include <iostream>
#include <string>

using namespace std;

// linked list node implemented as a struct named ListNode
struct ListNode {
    string value;
    ListNode* next;
};

// List class
class List {
    public:

        // Constructor with head and tail initialized to NULL
        List() : head(NULL), tail(NULL) {}

        // Destructor
        ~List() {

            // delete all remaining nodes in the linked list
            while (head) {
                ListNode* temp = head;
                head = head->next;
                delete temp;
            }
        }

        // appendNode function
        void appendNode(string value) {

            // dynamically allocate a new ListNode with value sent to the function
            ListNode* newNode = new ListNode{ value, nullptr };

            // place the new node at the end of the list
            if (!head) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        // insertNode function
        void insertNode(string value) {

            // dynamically allocate a new ListNode with value sent to the function
            ListNode* newNode = new ListNode{ value, nullptr };

            // place the new node in the linked list alphabetically based on the string values
            if (!head) {
                head = newNode;
                tail = newNode;
            }
            else if (value < head->value) {
                newNode->next = head;
                head = newNode;
            }
            else {
                ListNode* current = head;
                while (current->next && current->next->value < value){
                    current = current->next;
                    newNode->next = current->next;
                    current->next = newNode;
                }
                if (!newNode->next){
                    tail = newNode;
                }
            }
        }

        // deleteNode function
        void deleteNode(string value) {

            // delete the node with the same value as *current when found
            ListNode** current = &head;
            while (*current && (*current)->value != value){
                current = &(*current)->next;
            }
            if (*current) {
                ListNode* temp = *current;
                *current = (*current)->next;
                delete temp;
                if (!*current) {
                    tail = nullptr;
                }
            }
        }

        // displayList function
        void displayList() const {

            // display each node value in order from head to tail
            for (ListNode* current = head; current; current = current->next)
                cout << current->value << endl;
        }

    private:
        // two pointers to ListNode creates as attributes called head and tail
        ListNode* head, * tail;
};
