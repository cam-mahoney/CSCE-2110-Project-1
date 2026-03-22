#ifndef DRIVERDATABASE_H
#define DRIVERDATABASE_H

#include "HashTable.h"
#include "LinkedList.H"

class DriverDatabase {
    private:
        HashTable drivers;
        LinkedList inactiveDrivers;
    public: 
        DriverDatabase(int size);
        void loadFromFile();
        void insertDriver(Driver* d);
        void retrieveNewest(int N);
        void retrieveOldest(int N);
        void removeDriver(int id, bool isMigrating); // move to inactive list

        void moveToInactive(Driver* d);
        Driver* searchDriver(int id);




};

#endif