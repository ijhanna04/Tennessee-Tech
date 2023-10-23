#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue{
    private:

        // Structure declaration of a QueueNode
        struct QueueNode{
            string riderName;
            QueueNode* next;
        };

        int numNodes;

        // pointers to first and last nodes
        QueueNode* head;
        QueueNode* tail;

    public:

        // Queue Constructor
        Queue(){
            numNodes = 0;
            head = nullptr;
            tail = nullptr;
        }

        // enqueue member function
        void enqueue(string riderName){
            QueueNode* newNode = new QueueNode;
            newNode->riderName = riderName;
            newNode->next = nullptr;

            if (head == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            numNodes++;
        }

        // dequeue member function
        void dequeue(){
            if (head == nullptr){
                return;
            }

            QueueNode* temp = head;

            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }

            // statement for deleted nodes
            cout << "Oh shoot, I am sorry, our park is closed so " << temp->riderName << " will not get to ride today." << endl;

            delete temp;

            numNodes--;
        }

        // isEmpty member function
        bool isEmpty(){
            return numNodes == 0;
        }

        // Queue Destructor
        ~Queue(){
            while (head != nullptr) {
                dequeue();
            }
        }
};

#endif