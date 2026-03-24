#ifndef HashTable_H
#define HashTable_H

#include <iostream>
#include <iomanip>
#include <cstring>
#include "LinkedList.h"
#include "Driver.h"

using namespace std;

class HashTable {
private:
    int tableSize;
    LinkedList* table;

    int hashFunction(int id);

public:
    HashTable(int size);
    ~HashTable();

    void insert(Driver* driver);
    Driver* search(int id);
    void remove(int id);
};

#endif
