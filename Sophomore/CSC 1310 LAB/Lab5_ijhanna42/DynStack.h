/*****************************************************************
	Title:  		DynStack.h
	Date:  			10-17-2019
	Author: 		Ian Hanna
	Purpose:		CSC 1310 Lab 5
******************************************************************/

#ifndef DYNSTACK_H
#define DYNSTACK_H

#include <iostream>
using namespace std;

// template class that can accept any data type
template <typename T>
class dynamicStack{
    private:
        struct Node {
            T data;
            Node* next;
        };
        Node* top;
    
    public:

        // Stack Constructor
        Stack(){
            top = nullptr
        }

        // push function
        void push(T element){
            Node* newNode = new Node;
            newNode->data = element;
            newNode->next = top;
            top = newNode;
        }

        // pop function
        void pop(T element){
            if(isEmpty()){
                cout << "Stack is empty";
            }
            Node* temp = top;
            top = top->next;
            delete temp;
        }

        // isEmpty function
        bool isEmpty(){
            return top == nullptr;
        }
    
};

#endif