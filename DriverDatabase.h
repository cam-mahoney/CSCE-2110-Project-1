#ifndef DRIVERDATABASE_H
#define DRIVERDATABASE_H

#include "HashTable.h"
#include "LinkedList.h"

class Driver;

class DriverDatabase {
    private:
        HashTable drivers;

        LinkedList countyList;
        LinkedList dateList;
        LinkedList inactiveDrivers;

        void moveToInactive(Driver* d);
        Driver* createDriver();

    public: 
        DriverDatabase(int size);
        void mainFlow();
        ~DriverDatabase();

        void loadFromFile();

        void insertDriver(Driver* d);

        void retrieveNewest(int N);
        void retrieveOldest(int N);

        void removeDriver(int id, bool isMigrating); // move to inactive list

        Driver* searchDriver(int id);
};

#endif