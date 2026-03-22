#include "DriverDatabase.h"
#include <iostream>
using namespace std;

DriverDatabase::DriverDatabase(int size): drivers(size) {}

//load
void DriverDatabase::loadFromFile(){
    cout << "Loading driver..." << endl;

    for (int i = 0; i < 100; i++) {
        Driver* d = new Driver(/* data */);
        drivers.insert(d);
    }
}

//insert
void DriverDatabase::insertDriver(Driver* d) {
    drivers.insert(d);
}

//search
Driver* DriverDatabase::searchDriver(int id){
    return drivers.search(id);
}

//remove
void DriverDatabase::removeDriver(int id, bool isMigrating) {
    Driver* target = drivers.search(id);

    if (target != nullptr) {
        if (isMigrating) {
            moveToInactive(target);
        }
        drivers.remove(id);
    }
}

//movetoinactive
void DriverDatabase::moveToInactive(Driver* d) {
    inactiveDrivers.insertEnd(d);
}

//retrieveNewest
void DriverDatabase::retrieveNewest(int N){
    cout << "Retrieving newest " << N << " drivers..." << endl;
}

//retrieveOldest
void DriverDatabase::retrieveOldest(int N){
    cout << "Retrieving oldest " << N << " drivers..." << endl;
}