/*
	Title:      HashTable.h
	Author:	    Ian Hanna
	Date:       October 31, 2023
	Purpose:    Hash Table Class Implementation	
*/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "HashEntry.h"
using namespace std;

const int sizeTable = 128;

class HashTable {
    private:
        HashEntry **table;
    public:
        HashTable(){
            table = new HashEntry*[sizeTable];
            for (int i = 0; i < sizeTable; i++){
                table[i] = NULL;
            }
        }

        ~HashTable(){
            for (int i = 0; i < sizeTable; i++){
                if (table[i] != NULL){
                    delete table[i];
                }
            }
            delete[] table;
        }

        int get(int key){
            int hash = (key % sizeTable);
            while (table[hash] != NULL && table[hash]->getKey() != key){
                hash = (hash + 1) % sizeTable;
            }
            if (table[hash] != NULL){
                return table[hash]->getValue();
            }
        }

    void put(int key, int value) {
        int hash = (key % sizeTable);
        while (table[hash] != NULL && table[hash]->getKey() != key){
            hash = (hash + 1) % sizeTable;
        }
        if (table[hash] != NULL){
            delete table[hash];
        }
        table[hash] = new HashEntry(key, value);
    }
};

#endif