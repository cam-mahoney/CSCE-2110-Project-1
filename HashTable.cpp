#include "HashTable.h"

HashTable::HashTable(int size) {
    tableSize = size;
    table = new LinkedList[tableSize];
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hashFunction(int id) {
    return id % tableSize;
}

void HashTable::insert(Driver* driver) {
    int index = hashFunction(driver->getID());
    table[index].insertByCounty(driver);
}

Driver* HashTable::search(int id) {
    int index = hashFunction(id);
    return table[index].searchByID(id);
}

void HashTable::remove(int id) {
    int index = hashFunction(id);

    Driver* d = table[index].searchByID(id);
    if (d != nullptr)
        table[index].removeNode(d);
}
